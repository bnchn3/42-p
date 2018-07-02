<?PHP

if ($_POST["submit"] && $_POST["submit"] == "OK" && $_POST["login"] && $_POST["passwd"] && $_POST["passwd"] == $_POST["confirm"])
{
	if (!(file_exists("../user/private")))
		mkdir("../user/private");
	if (!(file_exists("../user/private/passwd")))
		file_put_contents("../user/private/passwd", null);
	$str = file_get_contents("../user/private/passwd");
	$arr = unserialize($str);
	$error = 0;
	foreach($arr as $i => $j)
	{
		if ($j["login"] == $_POST["login"])
			$error = 1;
	}
	if ($error == 1)
		echo "ERROR\n";
	else
	{
		$temp["login"] = $_POST["login"];
		$temp["passwd"] = hash("whirlpool", $_POST["passwd"]);
		$arr[] = $temp;
		file_put_contents("../user/private/passwd", serialize($arr));
		header('Location: users.php');
		echo "OK\n";
	}
}
else
	echo "ERROR\n";
?>
