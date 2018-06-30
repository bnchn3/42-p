<?PHP

function auth($login, $passwd)
{
	$arr = unserialize(file_get_contents("../private/passwd"));
	foreach($arr as $i => $j)
	{
		if ($j["login"] == $login && $j["passwd"] == hash("whirlpool", $passwd))
			return (TRUE);
	}
	return (FALSE);
}

?>
