<?php

/**
 * @file
 * Make a copy of the role table. To use this you must create a table named
 * role_copy with the same structure as role.
 */

class NHPIDExcelFieldMappingMigration extends DrupalMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
	//print_r($arguments);
    $this->description = 'Copy the nhpid_excel_drupal_field_mapping table.';
    $destination_key = array(
      'node_type' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 100,
      ),
	  'drupal_field_name' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 150,
      ),
    );
    //$query = db_select('old_nhpid.nhpid_excel_drupal_field_mapping', 'm')->fields('m');
	
	
    $this->source = new MigrateSourceSQL($this->query());
    $this->destination = new MigrateDestinationTableCopy('nhpid_excel_drupal_field_mapping', $destination_key);

    $this->map = new MigrateSQLMap($this->machineName,
    array('node_type' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 100,
		'alias' => 'm',
      ),
	  'drupal_field_name' => array(
        'type' => 'varchar',
        'not null' => TRUE,
		'length' => 150,
		'alias' => 'm',
      ),
	  ),

    $destination_key
    );
  }
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)->select('nhpid_excel_drupal_field_mapping', 'm');
	
	$query->fields('m');
		
    return $query;
  }
}