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
    '#required' => TRUE,
    '#description' => t('Auth Client Id.'),
    '#default_value' => variable_get('ecolytiq_auth_client_id', ''),
  );

  $form['ecolytiq_auth_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Auth Client Secret'),
    '#required' => TRUE,
    '#description' => t('Auth Client Secret.'),
    '#default_value' => variable_get('ecolytiq_auth_client_secret', ''),
  );

  $form['ecolytiq_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Api URL'),
    '#required' => TRUE,
    '#description' => t('Api URL.'),
    '#default_value' => variable_get('ecolytiq_api_url', ''),
  );

  $form['ecolytiq_auth_token_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Auth Token URL'),
    '#required' => TRUE,
    '#description' => t('Auth Token URL.'),
    '#default_value' => variable_get('ecolytiq_auth_token_url', ''),
  );

  $form['#validate'][] = 'ecolytiq_settings_form_validate';

  return system_settings_form($form);
}

/**
 * Form validate handler for the currency settings form.
 */
function ecolytiq_settings_form_validate($form, &$form_state) {
  $ecolytiq_api_url = parse_url($form_state['values']['ecolytiq_api_url']);
  if ($ecolytiq_api_url['scheme'] !== 'https') {
    form_set_error('ecolytiq_api_url', t('Api URL should start from https://'));
  }

  $ecolytiq_auth_token_url = parse_url($form_state['values']['ecolytiq_auth_token_url']);
  if ($ecolytiq_auth_token_url['scheme'] !== 'https') {
    form_set_error('ecolytiq_auth_token_url', t('Api URL should start from https://'));
  }
}
