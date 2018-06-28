#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$line = $argv[1];
	$line = trim($line);
	$arr = array_values(array_filter(explode(' ', $line)));
	for ($i = 0; $i < count($arr); $i++)
		printf("%s ", $arr[$i]);
	print("\n");
}

?>
