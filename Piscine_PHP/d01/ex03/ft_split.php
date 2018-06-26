#!/usr/bin/php

<?PHP

function ft_split($string)
{
	$string = trim($string);
	$arr = array_filter(explode(' ', $string));
	if (sort($arr))
		return ($arr);
	else
		return (-1);
}

?>
