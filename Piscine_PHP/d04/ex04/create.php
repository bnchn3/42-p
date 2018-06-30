<?PHP

if ($_POST["submit"] && $_POST["submit"] == "OK" && $_POST["login"] && $_POST["passwd"])
{
	if (!(file_exists("../private")))
		mkdir("../private");
	if (!(file_exists("../private/passwd")))
		file_put_contents("../private/passwd", null);
	$str = file_get_contents("../private/passwd");
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
		file_put_contents("../private/passwd", serialize($arr));
		header('Location: index.html');
		echo "OK\n";
	}
}
else
	echo "ERROR\n";
?>
