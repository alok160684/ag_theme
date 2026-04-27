<?php

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function ag_theme_form_system_theme_settings_alter(&$form, FormStateInterface $form_state) {

  $form['ag_theme_settings'] = [
    '#type' => 'details',
    '#title' => t('AG Theme Settings'),
    '#description' => t('Configure branding, colors, and layout defaults for AG Theme.'),
    '#open' => TRUE,
  ];

  $form['ag_theme_settings']['ag_show_logo'] = [
    '#type' => 'checkbox',
    '#title' => t('Show logo'),
    '#description' => t('Display the configured theme logo in supported templates.'),
    '#default_value' => theme_get_setting('ag_show_logo'),
  ];

  $form['ag_theme_settings']['ag_logo_upload'] = [
    '#type' => 'managed_file',
    '#title' => t('Custom logo upload'),
    '#description' => t('Upload a custom SVG, PNG, JPG, or WEBP logo.'),
    '#upload_location' => 'public://ag-theme/',
    '#upload_validators' => [
      'file_validate_extensions' => ['svg png jpg jpeg webp'],
    ],
    '#default_value' => theme_get_setting('ag_logo_upload'),
  ];

  $form['ag_theme_settings']['ag_primary_color'] = [
    '#type' => 'color',
    '#title' => t('Primary color'),
    '#description' => t('Used for buttons, links, and primary brand accents.'),
    '#default_value' => theme_get_setting('ag_primary_color') ?: '#1f4f82',
  ];

  $form['ag_theme_settings']['ag_secondary_color'] = [
    '#type' => 'color',
    '#title' => t('Secondary color'),
    '#description' => t('Used for secondary accents and highlights.'),
    '#default_value' => theme_get_setting('ag_secondary_color') ?: '#f5a623',
  ];

  $form['ag_theme_settings']['ag_layout_width'] = [
    '#type' => 'select',
    '#title' => t('Layout width'),
    '#description' => t('Controls the maximum container width.'),
    '#options' => [
      '1140px' => t('Narrow - 1140px'),
      '1200px' => t('Default - 1200px'),
      '1320px' => t('Wide - 1320px'),
      '1440px' => t('Extra wide - 1440px'),
      '100%' => t('Full width'),
    ],
    '#default_value' => theme_get_setting('ag_layout_width') ?: '1200px',
  ];
}
