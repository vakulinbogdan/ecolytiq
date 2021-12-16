<?php

/**
 * @file
 */

/**
 * Callback function for test page
 * of ecolytiq module.
 *
 * @param array $form
 * @param array $form_state
 *
 * @return mixed
 */
function ecolytiq_form_test($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form for test of requests'),
  );
  $form['request_type'] = array(
    '#title' => t("Choose request type"),
    '#type' => 'select',
    '#options' => array(
      'transaction' => 'Transaction',
      'transaction_range' => 'Transaction Range',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Submit handler for ecolytiq_form_test().
 *
 * @ingroup form_example
 * @throws \JsonException
 */
function ecolytiq_form_test_submit($form, &$form_state) {
  $request_type = $form_state['values']['request_type'];

  $result = get_request_data($request_type);

  // Set a response to the user.
  if ($result) {
    $output = json_decode($result, TRUE, 512, JSON_THROW_ON_ERROR);
    drupal_set_message(
      t('The form has been submitted with selected request type <i><b>@request_type</b></i> and response below: <pre>@response</pre>', array(
        '@request_type' => $request_type,
        '@response' => print_r($output, TRUE)),
      )
    );
  }
  else {
    drupal_set_message(t('Some error are present, See watchdog of the site'), 'error');
  }
}
