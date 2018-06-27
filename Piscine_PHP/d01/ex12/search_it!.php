#!/usr/bin/php

<?PHP

if ($argc > 1)
{
	$str = $argv[1];
	$arr = array();
	$key = array();
	$count = 2;
	while ($count < $argc)
	{
		$temp = array(strstr($argv[$count], ':', $before_needle = TRUE));
		$key = array_merge($key, $temp);
		$temp = array(substr(strstr($argv[$count], ':'), 1));
		$arr = array_merge($arr, $temp);
		$count++;
	}
	$final = array_combine($key, $arr);
	if (array_key_exists($str, $final))
		printf("%s\n", $final[$str]);
}

?>
