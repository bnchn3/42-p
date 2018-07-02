<?PHP

if ($_POST["login"] && $_POST["oldpw"] && $_POST["newpw"] && $_POST["submit"] && $_POST["submit"] == "OK" && $_POST["newpw"] == $_POST["confirm"])
{
	$arr = unserialize(file_get_contents("private/passwd"));
	$error = 1;
	foreach($arr as $i => $j)
	{
		if ($j["login"] == $_POST["login"] && $j["passwd"] == hash("whirlpool", $_POST["oldpw"]))
		{
			$arr[$i]["passwd"] = hash("whirlpool", $_POST["newpw"]);
			$error = 0;
		}
	}
	if ($error == 1)
		echo "ERROR\n";
	else
	{
		file_put_contents("private/passwd", serialize($arr));
		header("Location: admin.html");
		echo "OK\n";

	}
}
else
	echo "ERROR\n";

?>
