#!/usr/bin/php
<?PHP

function str_grab($str, $sub, &$final)
{
	$temp = stristr($str, $sub, $before_needle = TRUE);
	if ($temp)
		$final = array_merge($final, array($temp));
	if ((stripos($str, $sub)))
	{
		$str = substr($str, stripos($str, $sub));
		$temp = substr($str, strlen($sub));
		$str = substr($str, 0, strlen($sub));
	}
	$final = array_merge($final, array($str));
	return ($temp);
}

function capital($str, $sub, $end, &$final)
{
	$str = str_grab($str, $sub, $final);
	$temp = stristr($str, $end, $before_needle = TRUE);
	$final = array_merge($final, array(strtoupper($temp)));
	$str = stristr($str, $end);
	return ($str);
}

if ($argc > 1)
{
	$str = file_get_contents($argv[1]);
	$final = array();
	while ((stripos($str, "<a ")))
	{
		$str = str_grab($str, "<a ", $final);
		if ((stripos($str, 'title="')) < (strpos($str, ">")))
			$str = capital($str, 'title="', '"', $final);
		$str = capital($str, ">", "<", $final);
		while (stripos($str, "</a>") != 0)
		{
			if ((stripos($str, 'title="')) < (strpos($str, ">")))
				$str = capital($str, 'title="', '"', $final);
			$str = capital($str, ">", "<", $final);
		}
	}
	$final = array_merge($final, array($str));
	$str = implode("", $final);
	print($str);
}

?>
