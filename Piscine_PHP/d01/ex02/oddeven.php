#!/usr/bin/php

<?PHP
while (1)
{
	print("Enter a number: ");
	$line = fgets(STDIN);

	if ($line == NULL)
	{
		print("^D\n");
		exit;
	}
	$line = trim($line);
	if (is_numeric($line))
	{
		$number = intval($line);
		if ($number % 2 == 0)
			printf("%s%d%s", "The number ", $number, " is even\n");
		else if ($number % 2 == 1)
			printf("%s%d%s", "The number ", $number, " is odd\n");
	}
	else
		printf("%s%s%s", "'", $line, "' is not a number\n");
}
?>
