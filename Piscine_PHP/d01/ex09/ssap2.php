#!/usr/bin/php
<?PHP

function to_upper($char)
{
	if ($char >= 97 && $char <= 122)
		return ($char - 32);
	return ($char);
}

function is_alpha($char)
{
	if ($char >= 65 && $char <= 90)
		return (true);
	return (false);
}

function is_num($char)
{
	if ($char >= 48 && $char <= 57)
		return (true);
	return (false);
}

function is_special($char)
{
	if (!(is_alpha($char)) && !(is_num($char)) && $char > 32 && $char != 127)
		return (true);
	return (false);
}

function swap($arr, $i)
{
	$temp = $arr[$i];
	$arr[$i] = $arr[$i + 1];
	$arr[$i + 1] = $temp;
	return ($arr);
}

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
	$i = 0;
	while($i < count($arr) - 1)
	{
		for($j = 0; $j < strlen($arr[$i]); $j++)
		{
			$c = to_upper(ord($arr[$i][$j]));
			$d = to_upper(ord($arr[$i + 1][$j]));
			if ((is_alpha($c) && is_alpha($d) && $c > $d) || 
				(is_num($c) && ((is_num($d) && $c > $d) || is_alpha($d))) || 
				(is_special($c) && ((is_special($d) && $c > $d) || !(is_special($d)))))
			{
				$arr = swap($arr, $i);
				$i = -1;
				break;
			}
			else if ($c != $d)
				break;
		}
		$i++;
	}
	for($i = 0; $i < count($arr); $i++)
		printf("%s\n", $arr[$i]);
}

?>
