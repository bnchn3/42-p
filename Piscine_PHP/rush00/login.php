<?PHP

include("auth.php");

session_start();

if (!($_POST["login"] && $_POST["passwd"] && auth($_POST["login"], $_POST["passwd"])))
{
	$_SESSION["loggued_on_user"] = "";
	header('Location: main.html');
}
else
{
	$_SESSION["loggued_on_user"] = $_POST["login"];
	header('Location: main.html');
}
?>
