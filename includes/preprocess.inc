<?php

/**
 * @file
 * Preprocess include file.
 */

function ag_theme_preprocess_node(&$variables) {
  $variables['attributes']['class'][] = 'ag-node';
}

function ag_theme_preprocess_block(&$variables) {
  $variables['attributes']['class'][] = 'ag-block';
}
