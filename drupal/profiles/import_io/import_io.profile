<?php
/**
 * @file
 * Default form values.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function import_io_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = 'Import.IO';
  $form['site_information']['site_mail']['#default_value'] = 'support@import.io';
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'no-reply@mport.io';
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  // Disable automatic update checks.
  $form['update_notifications']['update_status_module']['#default_value'] = array();
}
