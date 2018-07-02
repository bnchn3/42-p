<?PHP

session_start();

if ($_SESSION["logged_on_user"])
{
	$exists = 0;
	if (!(file_exists("private")))
		mkdir ("private");
	if (!(file_exists("private/cart")))
		file_put_contents("private/cart", null);
	else
	{
		$arr1 = unserialize(file_get_contents("private/cart"));
		foreach ($arr1 as $i => $j)
		{
			if ($j["item"] == $_GET["item"])
			{
				$arr1[$i]["count"]++;
				$exists = 1;
			}
		}
	}
	$arr = unserialize(file_get_contents("../admin/private/database"));
	foreach ($arr as $i)
	{
		if ($i["item"] == $_GET["item"])
		{
			$price = $i["price"];
			$img = $i["img"];
		}
	}
	if (!($exists))
	{
		$temp = array("item" => $_GET["item"], "price" => $price, "img" => $img, "count" => 1);
		$arr1[] = $temp;
	}
	file_put_contents("private/cart", serialize($arr1));
	header('Location: cart.php');
	echo "OK\n";
}
else
{
	header('Location: ../user/html/newlogin.html');
	echo "ERROR\n";
}

?>
