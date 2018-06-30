<?PHP

include("auth.php");

session_start();

if (!($_POST["login"] && $_POST["passwd"] && auth($_POST["login"], $_POST["passwd"])))
{
	$_SESSION["loggued_on_user"] = "";
    echo "ERROR\n";
}
else
{
	$_SESSION["loggued_on_user"] = $_POST["login"];
    echo "OK\n";
?>

<html>
<body>
<iframe name="chat" src="chat.php" width=100% height=550px></iframe>
<iframe name="speak" src="speak.php" width=100% height=50px></iframe>
</body>
</html>
<?PHP
}
?>
