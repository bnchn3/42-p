#!/usr/bin/php

<?PHP

function to_upper($char)
{
	if ($char >= 'a' && $char <= 'z')
		return ($char - 32);
	return ($char);
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
	while($i < count($arr));
	{
		for($j = 0; $j < strlen($arr[$i]); $j++)
		{
			$c = to_upper($arr[$i][$j]);
			$d = to_upper($arr[$i + 1][$j]);
			if (($c >= 'A' && $c <= 'Z' && $c > $d) || ($c >= 'A' && $c <= 'Z' && ($d < 'A' || $d > 'Z')))
			{
				$arr = swap($arr, $i);
				$i = -1;
				break;
			}
			else if ($c > $d || ($c >= '0' && $c <= '9' && ($d < '0' || $d > '9')))
			{
				$arr = swap($arr, $i);
				$i = -1;
				break;
			}
		}
		$i++;
	}
	for($i = 0; $i < count($arr); $i++)
		printf("%s\n", $arr[$i]);
}

?>
