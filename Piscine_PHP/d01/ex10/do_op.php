#!/usr/bin/php

<?PHP

if ($argc != 4)
	print("Incorrect Parameters\n");
else
{
	$num1 = intval(trim($argv[1]));
	$num2 = intval(trim($argv[3]));
	if (strcmp(trim($argv[2]), "+") == 0)
		printf("%d\n", $num1 + $num2);
	else if (strcmp(trim($argv[2]), "-") == 0)
		printf("%d\n", $num1 - $num2);
	else if (strcmp(trim($argv[2]), "*") == 0)
		printf("%d\n", $num1 * $num2);
	else if (strcmp(trim($argv[2]), "/") == 0)
		printf("%d\n", $num1 / $num2);
	else if (strcmp(trim($argv[2]), "%") == 0)
		printf("%d\n", $num1 % $num2);
}

?>
