#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$str = trim($argv[1]);
	$arr = array_values(array_filter(explode(' ', $str)));
	if (count($arr) != 5)
		print("Wrong Format\n");
	else
	{
		$temp = ucfirst($arr[0]);
		if ((strcmp("Lundi", $temp)) && (strcmp("Mardi", $temp)) &&
			(strcmp("Mercredi", $temp)) && (strcmp("Jeudi", $temp)) &&
			(strcmp("Vendredi", $temp)) && (strcmp("Samedi", $temp)) &&
			(strcmp("Dimanche", $temp)))
			print("Wrong Format\n");
		else
		{
			if (intval($arr[1]) < 1 || intval($arr[1]) > 31 || strlen($arr[1]) > 2)
				print("Wrong Format\n");
			else
			{
				$time = array($arr[1]);
				$month = array("Janvier" => "01", "Fevrier" => "02", "Mars" => "03",
					"Avril" => "04", "Mai" => "05", "Juin" => "06", "Juillet" => "07",
					"Aout" => "08", "Septembre" => "09", "Octobre" => "10", "Novembre" => "11",
					"Decembre" => "12");
				$temp = ucfirst($arr[2]);
				if (!(array_key_exists($temp, $month)))
					print("Wrong Format\n");
				else
				{
					$time = array_merge(array($month[$arr[2]]), $time);
					if (strlen($arr[3]) != 4)
						print("Wrong Format\n");
					else
					{
						$time = array_merge(array($arr[3]), $time);
						$temp = array_values(array_filter(explode(':', $arr[4])));
						if (count($temp) != 3 || strlen($temp[0]) != 2 || strlen($temp[1]) != 2 ||
							strlen($temp[2]) != 2)
							print("Wrong Format\n");
						else
						{
							$str = implode(":", $time);
							$final = implode(" ", array($str, $arr[4]));
							printf("%d\n", strtotime($final));
						}
					}
				}
			}
		}
	}
}

?>
