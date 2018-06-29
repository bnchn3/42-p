#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$str = trim($argv[1]);
	$str = preg_replace("/[ \t]+/", " ", $str);
	printf("%s\n", $str);
}
?>
