<?PHP
session_start();

if ($_SESSION["loggued_on_user"] && $_POST["passwd"] == $_POST["confirm"])
{
	$arr = unserialize(file_get_contents("private/passwd"));
	foreach($arr as $i => $j)
	{
		if ($j["login"] == $_SESSION["loggued_on_user"] && $j["passwd"] == hash("whirlpool", $_POST["passwd"]))
		{
			$arr[$i] = 0;
			break;
		}
	}
	$arr = array_filter($arr);
	file_put_contents("private/passwd", serialize($arr));
	//header("Location: main.html"); trying to redirect with header crashes the server for some reason
	$_SESSION["loggued_on_user"] = "";
}
?>
