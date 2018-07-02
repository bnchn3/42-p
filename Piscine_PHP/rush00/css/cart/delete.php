<?PHP

$arr = unserialize(file_get_contents("private/cart"));
foreach ($arr as $i => $j)
{
	if ($j["item"] == $_GET["item"])
		$arr[$i]["count"]--;
	if ($j["count"] <= 0)
	{
		$arr[$i] = 0;
		$arr = array_filter($arr);
	}
}
file_put_contents("private/cart", serialize($arr));
header('Location: cart.php');
echo "OK\n";

?>
