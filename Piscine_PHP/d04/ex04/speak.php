<?PHP

include("auth.php");

session_start();
if ($_SESSION["loggued_on_user"] && $_POST["submit"] && $_POST["submit"] == "OK")
{
	if (!(file_exists("../private/chat")))
		file_put_contents("../private/chat", null);
	$arr = unserialize(file_get_contents("../private/chat"));
	$fp = fopen("../private/chat", "r+");
	flock($fp, LOCK_EX);
	$temp["login"] = $_SESSION["loggued_on_user"];
	$temp["time"] = time();
	$temp["msg"] = $_POST["msg"];
	$arr[] = $temp;
	file_put_contents("../private/chat", serialize($arr));
	flock($fp, LOCK_UN);
	echo $temp["msg"]."\n";
}
else
	echo "ERROR\n";

?>
