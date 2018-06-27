<?PHP

function ft_is_sort($arr)
{
	for($i = 1; $i < count($arr); $i++)
	{
		$j = $i - 1;
		if (strcmp($arr[$j], $arr[$i]) > 0)
			return (false);
	}
	return (true);
}

?>
