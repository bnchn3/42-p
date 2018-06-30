<?PHP

date_default_timezone_set("America/Los_Angeles");
session_start();
if (!($_SESSION["loggued_on_user"]))
	echo "ERROR\n";
else if (file_exists("../private/chat"))
{
	$arr = unserialize(file_get_contents("../private/chat"));
	foreach($arr as $i)
		echo "[".date("H:i", $i["time"])."] <b>".$i["login"]."</b>: ".$i["msg"]."<br />\n";
}

?>
