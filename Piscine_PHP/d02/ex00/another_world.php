#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$str = trim($argv[1]);
	$arr = array_values(array_filter(explode('\t', $str)));
	$str = implode(" ", $arr);
	$arr = array_values(array_filter(explode(' ', $str)));
	printf("%s\n", implode(" ", $arr));
}
?>
