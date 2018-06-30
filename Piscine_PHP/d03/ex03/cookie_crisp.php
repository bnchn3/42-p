<?PHP

if ($_GET["action"])
{
	if ($_GET["action"] == "set" && $_GET["name"] && $_GET["value"])
		setcookie($_GET["name"], $_GET["value"]);
	if ($_GET["action"] == "get" && $_GET["name"] && $_COOKIE[$_GET["name"]])
		echo $_COOKIE[$_GET["name"]]."\n";
	if ($_GET["action"] == "del" && $_GET["name"])
		setcookie($_GET["name"], "", time());
}

?>
