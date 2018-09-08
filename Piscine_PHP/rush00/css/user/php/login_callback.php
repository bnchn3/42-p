<?PHP
$state = "OK";
if(array_key_exists('state', $_REQUEST) && $_REQUEST['state'] !== $state) {
    throw new \Exception('State does not match.');
}

if(array_key_exists('code', $_REQUEST)) {
    $exchange = exchangeCode($_REQUEST['code']);
		$jwks = get_jwks();
}

function exchangeCode($code) {
    $authHeaderSecret = base64_encode( '{CLIENT_ID}:{CLIENT_SECRET}' );
    $query = http_build_query([
        'grant_type' => 'authorization_code',
        'code' => $code,
        'redirect_uri' => 'http://localhost:8000/user/php/login_callback.php'
    ]);
    $headers = [
        'Authorization: Basic ' . $authHeaderSecret,
        'Accept: application/json',
        'Content-Type: application/x-www-form-urlencoded',
        'Connection: close',
        'Content-Length: 0'
    ];
    $url = 'https://dev-593612.oktapreview.com/oauth2/default/v1/token?' . $query;
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_HEADER, 0);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($ch, CURLOPT_POST, 1);
    $output = curl_exec($ch);
    $httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    if(curl_error($ch)) {
        $httpcode = 500;
    }
    curl_close($ch);
    return json_decode($output);
}

function get_jwks() {
	$url = 'https://dev-593612.oktapreview.com/oauth2/default/.well-known/openid-configuration';
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_HEADER, 0);
	$output = curl_exec($ch);
	$arr = json_decode($output);
	$url = $arr->jwks_uri;
	curl_setopt($ch, CURLOPT_URL, $url);
	$output = curl_exec($ch);
	return json_decode($output);
}

$jwks = get_jwks();

//$jwt = $exchange->access_token;
?>
