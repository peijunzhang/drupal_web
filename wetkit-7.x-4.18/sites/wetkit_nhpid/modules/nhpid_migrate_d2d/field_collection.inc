<?php
/**
 * @file
 * Base class for migrating field collection into Drupal.
 */
 abstract class FCMigration extends DrupalMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
 
  public function get_new_code_entity_id($code, $code_type){
	$entity_row = Database::getConnection('default')
                 ->select('field_data_field_code', 'c')
                 ->fields('c', array('entity_id', 'field_code_value'))
				 ->condition('bundle', $code_type)
				 ->condition('field_code_value', $code)
                 ->execute()
                 ->fetchObject();
	if($entity_row){
		$entity_id = $entity_row -> entity_id;
		return $entity_id;
	}
	return null;	
  }
  
  public function get_new_nid($legacy_nid){
	$entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('field_legacy_nid_value', $legacy_nid)
                 ->execute()
                 ->fetchObject();
	if($entity_row){
		$entity_id = $entity_row -> entity_id;
		return $entity_id;
	}  
	return null;
  }
  public function map_field_reference(&$row, $field_name){
	if (property_exists($row, "$field_name")){
		$legacy_nids=$row->{"$field_name"};
		$target_ids= array();
		if (!empty($legacy_nids)){
			foreach($legacy_nids as $legacy_nid){
				$target_ids[] = $this->get_new_nid($legacy_nid);
			}
			$row->{$field_name}=$target_ids;
		}
	}
  }

}

/**
 
 */

class NHPIDFCMigration extends FCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
	//print_r($arguments);
    $this->description = t('field_notes migration from old D7.');
	$this->destination_type = $arguments['destination_type'];
    $this->source_type = $arguments['source_type'];
	$field_instances = field_info_instances('field_collection_item', $arguments['destination_type']);
	$this->dependencies = $arguments['dependencies'];
	$fields = array();
	foreach($field_instances as $field_name => $info){
		if ($field_name != 'field_legacy_nid'){
			$fields[$field_name] = $info['label'];
		}
	}
	
	$this -> destination_fields=$fields;
	//print_r($this -> destination_fields);
    $this->sourceFields += array(
      'item_id' => t('Item Id'),
      'revision_id' => t('Revision ID'),  
      'field_name' => t('Host field name'),
      'archived' => t('Archived'),
	  'host_entity_id' => 'Host entity ID',
    );

	foreach($this -> destination_fields as $field_name => $label){
		$this->sourceFields += array($field_name =>$label);
		$this->addFieldMapping($field_name, $field_name);
	}
	
	$this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
    $this->destination = new MigrateDestinationFieldCollection(
      $arguments['destination_type'],
      array('host_entity_type' => 'node')
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'item_id' => array(
        'type' => 'int',
        'not null' => true,
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    
	$this->addFieldMapping('host_entity_id', 'host_entity_id');
	//$this->addFieldMapping('field_legacy_nid', 'nid') ->description('We have a common field to save the D6 nid');
	    
  }
  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('legancy', $this->sourceConnection)
		->select('field_collection_item', 'c')
		->condition('field_name', $this->source_type);
	
	foreach($this -> destination_fields as $field_name => $label){
		$query->leftJoin('field_data_' . $field_name, $field_name, $field_name .'.entity_id = c.item_id');
	}
	
	$query->fields('c', array('item_id', 'revision_id', 'field_name', 'archived'));
	
	foreach($this -> destination_fields as $field_name => $label){
		$field=field_info_field($field_name);
		if($field['type'] == 'entityreference') {
			$storage_field=$field_name . '_entity_id';
		}
		else{
			$storage_field=$field['storage']['details']['sql']['FIELD_LOAD_CURRENT']['field_data_' . $field_name]['value'];
		}
		$query->addField($field_name, $storage_field, $field_name);
		
	}
	
	//print_r($query->execute()->rowCount());
	print_r($query->__toString());
    return $query;
  }
  
  public function prepareRow($row) {
    print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	
	// Mapping field collection item id
	$old_field_collection_field_table = 'field_data_' . $this->source_type;
	$legacy_host_entity_row = Database::getConnection('legancy', $this->sourceConnection)
                 ->select($old_field_collection_field_table, 'c')
                 ->fields('c', array('entity_id', $this->source_type .'_value'))
				 ->condition($this->source_type .'_value', $row->item_id)
                 ->execute()
                 ->fetchObject();
		print_r($legacy_host_entity_row);
		if($legacy_host_entity_row){
			$legacy_entity_id = $legacy_host_entity_row -> entity_id;
			print_r($legacy_entity_id );
			$new_host_entity_row = Database::getConnection('default')
                 ->select('field_data_field_legacy_nid', 'c')
                 ->fields('c', array('entity_id', 'field_legacy_nid_value'))
				 ->condition('field_legacy_nid_value', $legacy_entity_id)
                 ->execute()
                 ->fetchObject();
			print_r($new_host_entity_row );
			$row->host_entity_id = $new_host_entity_row->entity_id;
		}
		else{
			print_r ('No host entity id is found for'  . $row->item_id . "\n");
		}
	//mapping entity reference fields target id
	foreach($this -> destination_fields as $field_name => $label){
		$field=field_info_field($field_name);
		if ($field['type'] == 'entityreference'){
			$this->map_field_reference($row, $field_name);
		}
	}
	
	print_r($row);
	print_r($row->item_id . " is migrated \n");
	return True;
  }
}
