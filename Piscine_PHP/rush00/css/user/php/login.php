<?PHP

include("auth.php");

session_start();

if (!($_POST["login"] && $_POST["passwd"] && auth($_POST["login"], $_POST["passwd"], "../private/passwd")))
{
	$_SESSION["logged_on_user"] = "";
	header('Location: ../html/newlogin.html');
	echo "ERROR\n";
}
else
{
	$_SESSION["logged_on_user"] = $_POST["login"];
	header('Location: account.php');
	echo "OK\n";
}
?>
