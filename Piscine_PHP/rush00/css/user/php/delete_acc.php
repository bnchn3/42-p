<?PHP
session_start();

if ($_SESSION["logged_on_user"] && $_POST["passwd"] == $_POST["confirm"])
{
	$arr = unserialize(file_get_contents("../private/passwd"));
	foreach($arr as $i => $j)
	{
		if ($j["login"] == $_SESSION["logged_on_user"] && $j["passwd"] == hash("whirlpool", $_POST["passwd"]))
		{
			$arr[$i] = 0;
			break;
		}
	}
	$arr = array_filter($arr);
	file_put_contents("../private/passwd", serialize($arr));
	$_SESSION["logged_on_user"] = "";
	header("Location: ../html/newlogin.html");
	echo "OK\n";
}
?>
