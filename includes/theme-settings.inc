<?php

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function ag_theme_form_system_theme_settings_alter(&$form, FormStateInterface $form_state) {

  $form['ag_theme_settings'] = [
    '#type' => 'details',
    '#title' => t('AG Theme Settings'),
    '#description' => t('Configure branding, colors, typography, layout, and dark mode settings.'),
    '#open' => TRUE,
  ];

  $form['ag_theme_settings']['ag_google_font'] = [
    '#type' => 'select',
    '#title' => t('Google Font'),
    '#description' => t('Optional Google Font loaded from fonts.googleapis.com.'),
    '#options' => [
      '' => t('None'),
      'Inter' => t('Inter'),
      'Roboto' => t('Roboto'),
      'Open Sans' => t('Open Sans'),
      'Lato' => t('Lato'),
      'Montserrat' => t('Montserrat'),
      'Poppins' => t('Poppins'),
    ],
    '#default_value' => theme_get_setting('ag_google_font') ?: '',
  ];

  $form['ag_theme_settings']['ag_google_font_apply_to_headings'] = [
    '#type' => 'checkbox',
    '#title' => t('Apply Google Font to headings'),
    '#default_value' => theme_get_setting('ag_google_font_apply_to_headings'),
  ];
}
