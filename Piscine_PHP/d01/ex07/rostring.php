#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$str = $argv[1];
	$arr = array_values(array_filter(explode(' ', trim($str))));
	for($i = 1; $i < count($arr); $i++)
		printf("%s ", $arr[$i]);
	printf("%s\n", $arr[0]);
}

?>
