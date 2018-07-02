<?PHP

	$arr = unserialize(file_get_contents("../user/private/passwd"));
	foreach($arr as $i => $j)
	{
		if ($j["login"] == $_GET["login"])
		{
			$arr[$i] = 0;
			break;
		}
	}
	$arr = array_filter($arr);
	file_put_contents("../user/private/passwd", serialize($arr));
	header("Location: users.php");
	echo "OK\n";

?>
