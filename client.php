<?php
$request = xmlrpc_encode_request("my_ip_address", array('username', 'password'));

$context = stream_context_create(array('http' => array(
    'method' => "POST",
    'header' => "Content-Type: text/xml\r\nUser-Agent: PHPRPC/1.0\r\n",
    'content' => $request
)));

/**
* This URL does not exist. Replace it with your server URL
*/
$server = 'http://localhost/xmlrpctest/service.php';

$file = file_get_contents($server, false, $context);

$response = xmlrpc_decode($file);

echo "My IP Address is " . $response;
?>
