#!/usr/bin/php

<?PHP

if ($argc != 2)
	print("Incorrect Parameters\n");
else
{
	$str = trim($argv[1]);
	$i = 0;
	while (ord($str[$i]) >= 48 && ord($str[$i]) <= 57)
		$i++;
	$first = $i;
	while (ord($str[$i]) == 32)
		$i++;
	$op = $i;
	if (ord($str[$i]) != 37 && ord($str[$i]) != 42 && ord($str[$i]) != 43 && ord($str[$i]) != 45 && ord($str[$i]) != 47)
		print("Syntax Error\n");
	else
	{
		$i++;
		while (ord($str[$i]) == 32)
			$i++;
		$second = $i;
		while ($i < strlen($str) && ord($str[$i]) >= 48 && ord($str[$i]) <= 57)
			$i++;
		if ($i != strlen($str))
			print("Syntax Error\n");
		else
		{
			$num1 = intval(substr($str, 0, $first));
			$num2 = intval(substr($str, $second));
			if (ord($str[$op]) == 43)
				printf("%d\n", $num1 + $num2);
			else if (ord($str[$op]) == 45)
				printf("%d\n", $num1 - $num2);
			else if (ord($str[$op]) == 42)
				printf("%d\n", $num1 * $num2);
			else if (ord($str[$op]) == 47)
				printf("%d\n", $num1 / $num2);
			else if (ord($str[$op]) == 37)
				printf("%d\n", $num1 % $num2);
		}
	}
}

?>
