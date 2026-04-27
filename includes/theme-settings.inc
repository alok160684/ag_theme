<?php

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function ag_theme_form_system_theme_settings_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state) {

  $form['ag_theme_settings'] = [
    '#type' => 'details',
    '#title' => t('AG Theme Settings'),
    '#open' => TRUE,
  ];

  $form['ag_theme_settings']['ag_show_logo'] = [
    '#type' => 'checkbox',
    '#title' => t('Show logo'),
    '#default_value' => theme_get_setting('ag_show_logo'),
  ];

  $form['ag_theme_settings']['ag_primary_color'] = [
    '#type' => 'textfield',
    '#title' => t('Primary color'),
    '#default_value' => theme_get_setting('ag_primary_color'),
  ];

  $form['ag_theme_settings']['ag_secondary_color'] = [
    '#type' => 'textfield',
    '#title' => t('Secondary color'),
    '#default_value' => theme_get_setting('ag_secondary_color'),
  ];

  $form['ag_theme_settings']['ag_layout_width'] = [
    '#type' => 'textfield',
    '#title' => t('Layout width'),
    '#default_value' => theme_get_setting('ag_layout_width'),
  ];
}
