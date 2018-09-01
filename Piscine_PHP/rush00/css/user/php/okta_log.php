<?PHP
$state = "OK";
$query = http_build_query([
    'client_id' => '0oag4126ufR2fEOpV0h7',
    'response_type' => 'code',
    'response_mode' => 'query',
    'scope' => 'openid profile',
    'redirect_uri' => 'http://localhost:8000/user/php/login_callback.php',
    'state' => $state,
    'nonce' => uniqid($more_entropy = TRUE)
]);

header('Location: ' . 'https://dev-593612.oktapreview.com/oauth2/default/v1/authorize?'.$query);
?>
