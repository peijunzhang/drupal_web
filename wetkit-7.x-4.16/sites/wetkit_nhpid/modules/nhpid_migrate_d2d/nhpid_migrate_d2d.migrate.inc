<?php
/**
 * @file nhpid_migrate_d2d.migrate.inc
 */

/**
 * This is code for NHPID DMS migration from old D7 to new D7.
 */

/**
 * Implements hook_migrate_api().
 */
function nhpid_migrate_d2d_migrate_api() {
  /**
   * Declare the api version and migration group.
   */
  $code_node_group_1 = array(
  'code_application_type'=>'CodeApplicationType',
  'code_cat_iv_product'=>'CodeWithNameComment',
  'code_chemical_class'=>'CodeWithDescriptionComment',
  'code_common_term' => 'CodeCommentTerm',
  'code_dosage_unit'=>'CodeWithName',
  'code_dose_type'=>'CodeWithNameDescription',
  'code_evidence_type'=>'CodeWithNameDescription',
  'code_geo_distribution'=>'CodeWithDescriptionComment',
  'code_indication_type'=>'CodeWithNameDescription',
  /*'code_ingredient_category' => 'CodeIngredientCategory';
  'code_ingredient_class' => 'CodeWithDescription',
  'code_journal' => 'CodeJournal',*/
  
  );
  $code_node_group_2 = array(
  'code_chemical_subclass'=>'CodeChemicalSubclass',
  'code_dosage_form' => 'CodeDosageForm',
  'code_ich_classes'=>'CodeICHClasses',
  'code_ingredient_category'=>'CodeIngredientCategory',
  
  );
  $code_node_group_3 = array(
  'code_dosage_form_group'=>'CodeDosageFormGroup',
  );
  $api = array(
    'api' => 2,
    'groups' => array(
      'nhpid_group_1' => array(
        'title' => t('Basic Data'),
      ),
	  'nhpid_group_code_node_group1' => array(
        'title' => t('Code node group 1'),
      ),
	  'nhpid_group_code_node_group2' => array(
        'title' => t('Code node group 2'),
      ),
	  'nhpid_group_code_node_group2' => array(
        'title' => t('Code node group 3'),
      ),
	  
	  
      'migrations' => array(),
    ),
  );

  /**
   * Each migration being registered takes an array of arguments, some required
   * and some optional. Start with the common arguments required by all - the
   * source_connection (connection key, set up in settings.php, pointing to
   * the Drupal 6 database), source_version (major version of Drupal), and
   * group_name (a.k.a. import job).
   */
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 7,
	'source_database' => array(
    'driver' => 'mysql',
    'database' => 'old_nhpid',
    'username' => 'drupal',
    'password' => 'drupal_pwd',
    'host' => 'localhost',
    'prefix' => '',
	),
  );

  // Register the user migration.
   // Migrate roles
  
  $api['migrations']['Role'] = $common_arguments + array(
    'description' => t('Migration of Roles'),
    'class_name' => 'DrupalRole7Migration',
	'group_name' => 'nhpid_group_1',
	'role_mappings' => array(
      'manager' => 'manager',
      'data entry' => 'data entry',
      'observer' => 'observer',
    ),
  );

  // We just use the migrate_d2d D7 migration class as-is.
  $api['migrations']['User'] = $common_arguments + array(
    'description' => t('Migration of users'),
    'class_name' => 'DrupalUser7Migration',
	'group_name' => 'nhpid_group_1',
	'role_migration' => 'Role',
  );

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments. Note that in Drupal 6 vocabularies did not have machine
  // names, so we use the vocabulary ID to uniquely identify them.
  /*
  $vocabulary_arguments = array(
    'Countries' => array(
      'description' => t('Migration of Countries terms from Drupal 6'),
      'source_vocabulary' => '1',  // D6 Vocabulary ID
      'destination_vocabulary' => 'countries',
    ),
    'Topics' => array(
      'description' => t('Migration of Topics terms from Drupal 6'),
      'source_vocabulary' => '2',  // D6 Vocabulary ID
      'destination_vocabulary' => 'topics',
    ),
  );
	*/
  // Again, we're using the migrate_d2d class directly.
  // The soft dependency says that while we don't have to run the user migration
  // first, we want to make sure it's listed first so the vocabularies are
  // listed right ahead of the node migrations.
  /*
  $common_vocabulary_arguments = $common_arguments + array(
    'class_name' => 'DrupalTerm6Migration',
    'soft_dependencies' => array('User'),
  );
  foreach ($vocabulary_arguments as $migration_name => $arguments) {
    $arguments += $common_vocabulary_arguments;
    $api['migrations'][$migration_name] = $arguments;
  }
	*/
  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  
  // and destination_type are required arguments.
  
  // node data
  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
      'user_migration' => 'User'
    );
  $code_node_group1_arguments = array();
  foreach ($code_node_group_1 as $type => $class){
	 $code_node_group1_arguments[$type] = array(
      'class_name' => $class,
      'description' => t("Migration of code $type"),
      'source_type' => $type,
      'destination_type' => $type,
	  'group_name' => 'nhpid_group_code_node_group1',
    );
	  
  }
  foreach ($code_node_group1_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  

  

  
	/*
  // Menu migrations -- same requirements as users
  $menu_arguments = $common_arguments + array(
    'description' => t('Migration of menus from Drupal 6'),
    'class_name' => 'DrupalMenu6Migration',
  );

  // We just use the migrate_d2d D6 migration class as-is.
  $api['migrations']['Menu'] = $menu_arguments;

  // Menu links migrations -- basic requirements, plus must set up menu dependency
  $menu_links_arguments = $common_arguments + array(
    'description' => t('Migration of menu links from Drupal 6'),
    'class_name' => 'DrupalMenuLinks6Migration',
    'menu_migration' => 'Menu',
  );
  $api['migrations']['MenuLinks'] = $menu_links_arguments;
	*/
	// field collection
	/*
	$api['migrations_6']['FCNotes'] = $common_arguments + array(
    'description' => t('Migration of field collection field_notes'),
    'class_name' => 'ACNotesMigration',
	);
	$api['migrations_6']['FCPCI'] = $common_arguments + array(
    'description' => t('Migration of field collection field_pci'),
    'class_name' => 'ACPCIMigration',
	);
	*/

  return $api;
}
