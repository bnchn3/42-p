<?PHP

session_start();
date_default_timezone_set("America/Los_Angeles");
if (!(file_exists("../admin/private/orders")))
	file_put_contents("../admin/private/orders", null);
else
	$arr1 = unserialize(file_get_contents("../admin/private/orders"));
if (file_exists("private/cart"))
{
	$temp = array("time" => date("d/m/y H:i"), "user" => $_SESSION["logged_on_user"], "items" => array(), "price" => 0.0);
	$arr2 = unserialize(file_get_contents("private/cart"));
	foreach ($arr2 as $i => $j)
	{
		$temp["items"][] = $j;
		$temp["price"] += floatval($arr2[$i]["price"]);
	}
	$arr1[] = $temp;
	file_put_contents("../admin/private/orders", serialize($arr1));
	unlink("private/cart");
	header('Location: ../index.php');
	echo "OK\n";
}
?>
