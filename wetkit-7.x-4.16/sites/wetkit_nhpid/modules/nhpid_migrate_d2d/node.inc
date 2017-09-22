<?php

/**
 * Common mappings for the TPD node migrations.
 */
abstract class NHPIDNodeMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
	$this->addFieldMapping('field_its_ids', 'field_its_ids');
	//$this->addFieldMapping('uid', 'uid');
  }
   /**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
   
  public function prepareRow($row) {
    // If the  workflow states setting is different from old D7 to new D7, a mapping must be done.
	//print_r($row);
	if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
	$sid = $this->get_sid($row->nid);

	if ($sid){
		$row->workflow_node = array($sid);
	}

    else {
      $this->saveMessage(t('No workflow_node data for node !nid', array('!nid' => $nid)));
    }
	
	print_r($row->workflow_node);
	return True;
  }
  public function complete($entity, stdClass $row){
	  //print_r($entity);
	  //print_r($row);
	  // author uid
	if ($row->uid){
		//print_r ('legacy_uid: ' . $entity->uid . "\n");
		$entity->uid=$row->uid;
		//print_r ('new_uid: ' . $entity->uid . "\n");
	}
	print_r($row->title . " is migrated \n");
  }
  public function get_new_user_uid($legacy_uid){
	 $legacy_user_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('users', 'u')
                 ->fields('u', array('uid', 'name'))
				 ->condition('uid', $legacy_uid)
                 ->execute()
                 ->fetchObject();
	if ($legacy_user_row ) {
       $user_name = $user_row->name;
	   
	   $user_row = Database::getConnection('default')
                 ->select('users', 'u')
                 ->fields('u', array('uid', 'name'))
				 ->condition('name', $user_name)
                 ->execute()
                 ->fetchObject();
		if($user_row){
			$new_uid = $user_row -> uid;
			return $$new_uid;
		}
    }
	return 1;
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
  public function get_sid($legacy_nid){
	$workflow_row = Database::getConnection('legacy', $this->sourceConnection)
                 ->select('workflow_node', 'wd')
                 ->fields('wd', array('nid', 'sid', 'uid', 'stamp'))
				 ->condition('nid', $legacy_nid)
                 ->execute()
                 ->fetchObject();
	//print_r ($legency_nid);
	//print_r ($workflow_row);
	if ($workflow_row ){
		return $workflow_row->sid;
	}
	
	return null;
  }

}


/**
 *Code application type mappings and handling.
 */
class CodeApplicationType extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_app_type_e', 'field_app_type_e');
	$this->addFieldMapping('field_app_type_f', 'field_app_type_f');
	$this->addFieldMapping('field_workflow', 'workflow_node');
	
  } 
}

/**
 *CodeWithNameComment mappings and handling.
 */
class CodeWithNameComment extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_its_ids', 'field_its_ids');
	$this->addFieldMapping('field_workflow', 'workflow_node');
	
  } 
}

/**
 *CodeWithDescriptionComment mappings and handling.
 */
class CodeWithDescriptionComment extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_comment_e', 'field_comment_e');
	$this->addFieldMapping('field_comment_f', 'field_comment_f');
	$this->addFieldMapping('field_its_ids', 'field_its_ids');
	$this->addFieldMapping('field_workflow', 'workflow_node');
	
  } 
}

/**
 *CodeCommentTerm mappings and handling.
 */
class CodeCommentTerm extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_common_term_e', 'field_common_term_e');
	$this->addFieldMapping('field_common_term_f', 'field_common_term_f');
	$this->addFieldMapping('field_common_term_type', 'field_common_term_type');
	$this->addFieldMapping('field_common_term_type_f', 'field_common_term_type_f');
	$this->addFieldMapping('field_workflow', 'workflow_node');
	
  } 
}

/**
 *CodeWithName mappings and handling.
 */
class CodeWithName extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_workflow', 'workflow_node');
	
  } 
}

/**
 *CodeWithNameDescription mappings and handling.
 */
class CodeWithNameDescription extends NHPIDNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);

    $this->addFieldMapping('field_code', 'field_code');
    $this->addFieldMapping('field_name_e', 'field_name_e');
	$this->addFieldMapping('field_name_f', 'field_name_f');
	$this->addFieldMapping('field_description_e', 'field_description_e');
	$this->addFieldMapping('field_description_f', 'field_description_f');
	$this->addFieldMapping('field_workflow', 'workflow_node');
	
  } 
}

