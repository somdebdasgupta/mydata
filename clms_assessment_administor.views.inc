<?php 

/**
 * Implementation of HOOK_views_data()
 *
 * Tells views about the filters we need to add.
 *
 * @return array An associative array of options.
 */
 
function clms_assessment_administor_views_data() {
    $data = array();
   // ----------------------------------------------------------------
  	// learning_outcome table -- basic table information.
	
 	$data['learning_outcome']['table']['group'] = t('Learning Outcome');
	
	$data['learning_outcome']['table']['base'] = array(
    'field' => 'lo_id',
    'title' => t('All Learning Outcome'),
    'help' => t('Holds Learning Outcome'),
 	 );
	 
    $data['learning_outcome']['clms_assessment_administor_learning_outcome'] = array(
        'title' => t('Learning Outcome'),
        'help' => t('Filter will be based on learning outcome table.'),
        'filter' => array(
            'handler' => 'clms_assessment_administor_learning_outcome_filter_view',
			'label' => t('Learning Outcome'),
     	    'use equal' => TRUE,
        ),
    );
 
    return $data;
}

/**
 *
 * Register the views handlers with the view.
 *
 * @return array An associative array of options.
 */
 
function clms_assessment_administor_views_handlers() {
    return array(
        'info' => array(
            'path' => drupal_get_path('module', 'clms_assessment_administor') . '/views',
        ),
        'handlers' => array(
            'clms_assessment_administor_learning_outcome_filter_view' => array(
                'parent' => 'views_handler_filter',
            ),
        ),
    );
}
