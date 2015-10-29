<?php
/**
 * @file
 * school_ratings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function school_ratings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Integrating import.io with Drupal';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = 'Bring import.io datasets into Drupal with Feeds';
  $export['site_slogan'] = $strongarm;

  return $export;
}
