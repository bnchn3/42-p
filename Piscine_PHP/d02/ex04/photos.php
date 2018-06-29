#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$curl = curl_init();
	$count = 1;
	while ($count < $argc)
	{
		$str = $argv[$count];
		if ((curl_setopt($curl, CURLOPT_URL, $str)))
		{
			$sub = strstr($str, "www");
			eval("mkdir($sub)");
			$page = curl_exec($curl);
		}
		$count++;
	}
}

?>
