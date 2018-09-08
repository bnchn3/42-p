<?php
$jwt = 'eyJhbGciOiJSUzI1Nqd0FfRzh6X0ZsOGlJRnNoUlRuQUkweVUifQ.eyJ2ZXIiOjEsiOiJwaHBAb2t0YS5jb20ifQ.ZGrn4fvIoCq0QdSyA';

$jwtVerifier = (new \Okta\JwtVerifier\JwtVerifierBuilder())
    ->setDiscovery(new \Okta\JwtVerifier\Discovery\Oauth) // This is not needed if using oauth.  The other option is OIDC
    ->setAdaptor(new \Okta\JwtVerifier\Adaptors\SpomkyLabsJose)
    ->setAudience('api://default')
    ->setClientId('{clientId}')
    ->setIssuer('https://{yourOktaDomain}.com/oauth2/default')
    ->build();

$jwt = $jwtVerifier->verify($jwt);

dump($jwt); //Returns instance of \Okta\JwtVerifier\JWT

dump($jwt->toJson()); // Returns Claims as JSON Object

dump($jwt->getClaims()); // Returns Claims as they come from the JWT Package used

dump($jwt->getIssuedAt()); // returns Carbon instance of issued at time
dump($jwt->getIssuedAt(false)); // returns timestamp of issued at time

dump($jwt->getExpirationTime()); //returns Carbon instance of Expiration Time
dump($jwt->getExpirationTime(false)); //returns timestamp of Expiration Time
?>
