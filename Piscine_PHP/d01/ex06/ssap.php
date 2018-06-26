#!/usr/bin/php

<?PHP

if ($argc > 1)
{
	$count = 1;
	$arr = array();
	while ($count < $argc)
	{
		$str = $argv[$count++];
		$temp = array_values(array_filter(explode(' ', trim($str))));
		$arr = array_merge($arr, $temp);
	}
	sort($arr);
	for($i = 0; $i < count($arr); $i++)
		printf("%s\n", $arr[$i]);
}

?>
