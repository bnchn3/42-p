<?PHP

function auth($login, $passwd, $file)
{
	if (file_exists($file))
	{
		$arr = unserialize(file_get_contents($file));
		foreach($arr as $i => $j)
		{
			if ($j["login"] == $login && $j["passwd"] == hash("whirlpool", $passwd))
				return (TRUE);
		}
	}
	return (FALSE);
}

?>
