<?php

class clms_assessment_administor_learning_outcome_filter_view extends views_handler_filter{
  
   /**
   * Provide a select list for value selection.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
 
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Learning Outcome'),
      '#options' => array(
        0 => t('Positive'),
        1 => t('Negetive'),
        2 => t('Nutral'),
      ),
      '#default_value' => $this->value,
      '#required' => FALSE,
    );
	return $form;
  }

  //query() for joins
  /*function query() {
        // Ensure table alias has been set
        $table_alias = $this->ensure_my_table();
 
        // Get term value
        $term_value = check_plain($this->view->exposed_input['clms_assessment_administor_learning_outcome_filter_view']);
 
        // Make sure term value is set.
        if ($term_value != '') {
            /*
            Query parts to add:
             1. LEFT JOIN term_node term_node2 ON node.vid = term_node2.vid
             2. LEFT JOIN term_data term_data2 ON term_node2.tid = term_data2.tid
             3. AND (UPPER(term_data2.name) LIKE UPPER('%Term Name%'))
             */
 
            // Add the term_node table with an alias of term_node2 this ensures 
            $this->query->add_table('term_node', NULL, NULL, 'term_node2');
 
            // Add a join between the term_node and the node tables
            // This uses the alias term_node2 for the term_node table
            $join = new views_join();
            $join->construct('term_node', $this->table_alias, 'vid', 'vid', array(), 'LEFT');
            $this->query->ensure_table('term_node2', $this->relationship, $join);
 
            // Add a join between the term_data and term_node tables
            // This uses the alias term_data2 for the term_data table
            $join = new views_join();
            $join->construct('term_data', 'term_node2', 'tid', 'tid', array(), 'LEFT');
            $return = $this->query->ensure_table('term_data2', $this->relationship, $join);
 
            // Add a where clause to the query
            $this->query->add_where($this->options['group'], "(UPPER(term_data2.name) LIKE UPPER('%%%s%%')) ", $term_value);
        }
    }*/
}
