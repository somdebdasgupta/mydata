<?php
$request_xml = file_get_contents("php://input");
function my_ip_address($method_name, $args, $app_data) {
    $username = $args[0];
    $password = $args[1];
/**
* Perform authentication and authorization here
* If failed return a fault code or exit
*/
    return $_SERVER['REMOTE_ADDR'];

}

$xmlrpc_server = xmlrpc_server_create();

xmlrpc_server_register_method($xmlrpc_server, "my_ip_address", "my_ip_address");
header('Content-Type: text/xml');
print xmlrpc_server_call_method($xmlrpc_server, $request_xml, array());

?>
