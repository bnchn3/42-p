<?PHP

include("../user/php/auth.php");

session_start();

if (!($_POST["login"] && $_POST["passwd"] && auth($_POST["login"], $_POST["passwd"], "private/passwd")))
{
	$_SESSION["logged_on_admin"] = "";
	header('Location: admin.html');
	echo "ERROR\n";
}
else
{
	$_SESSION["logged_on_admin"] = $_POST["login"];
	header('Location: admin_home.php');
	echo "OK\n";
}

?>
