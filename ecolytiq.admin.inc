<?php

/**
 * @file
 */

/**
 * Settings form for ecolytiq module.
 */
function ecolytiq_settings() {
  $form['ecolytiq_auth_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Auth Client Id'),
    '#description' => t('Auth Client Id.'),
    '#default_value' => variable_get('ecolytiq_auth_client_id', ''),
  );

  $form['ecolytiq_auth_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Auth Client Secret'),
    '#description' => t('Auth Client Secret.'),
    '#default_value' => variable_get('ecolytiq_auth_client_secret', ''),
  );

  $form['ecolytiq_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Api URL'),
    '#description' => t('Api URL.'),
    '#default_value' => variable_get('ecolytiq_api_url', ''),
  );

  $form['ecolytiq_auth_token_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Auth Token URL'),
    '#description' => t('Auth Token URL.'),
    '#default_value' => variable_get('ecolytiq_auth_token_url', ''),
  );

  return system_settings_form($form);
}
