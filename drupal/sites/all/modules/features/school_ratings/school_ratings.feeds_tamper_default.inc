<?php
/**
 * @file
 * school_ratings.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function school_ratings_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'california_school_ratings-content-find_replace';
  $feeds_tamper->importer = 'california_school_ratings';
  $feeds_tamper->source = 'content';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ' map ',
    'replace' => ', ',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['california_school_ratings-content-find_replace'] = $feeds_tamper;

  return $export;
}
