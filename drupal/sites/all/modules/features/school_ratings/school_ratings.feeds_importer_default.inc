<?php
/**
 * @file
 * school_ratings.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function school_ratings_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'california_school_ratings';
  $feeds_importer->config = array(
    'name' => 'California School Ratings',
    'description' => 'Ratings, ranking, test scores for schools',
    'fetcher' => array(
      'plugin_key' => 'FeedsImportIoFetcher',
      'config' => array(
        'connector_guid' => 'd90b8e3d-957c-4757-bec8-98b22f64b11b',
        'user_guid' => 'e2f1b330-b0f7-4ad9-86b4-b2c6bf21',
        'api_key' => 'e2f1b330b0f74ad986b4b2c6bf2182a59984b4ec5625c9d57accdba14daa75f8ada82ff26517e5c9dcbe79820bbfe4b145762c97213ee9f5c1c832465cdd649d8c2348cd0c50543774d49e1159be5532',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsImportIoParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'number_1',
            'target' => 'state_rank',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'number_2',
            'target' => 'api_score',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'value_1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'content',
            'target' => 'location',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'values',
            'target' => 'class_sizes',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'alttext_value_numbers',
            'target' => 'parent_education',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'school',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['california_school_ratings'] = $feeds_importer;

  return $export;
}
