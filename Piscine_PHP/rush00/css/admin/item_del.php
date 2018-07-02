<?PHP

$arr1 = unserialize(file_get_contents("private/database"));
$arr2 = unserialize(file_get_contents("private/categories"));
foreach ($arr1 as $i => $j)
{
	if ($j["item"] == $_GET["item"])
	{
		$arr1[$i]["item"] = "";
		$arr1[$i]["price"] = "";
		$arr1[$i]["img"] = "";
		$arr1[$i] = null;
		$arr1 = array_filter($arr1);
	}
}
foreach($arr2 as $i => $j)
{
	if (array_search($_GET["item"], $arr2[$i]["items"]) !== FALSE)
	{
		$a = array_search($_GET["item"], $arr2[$i]["items"]);
		$arr2[$i]["items"][$a] = "";
		$arr2[$i]["items"] = array_filter($arr2[$i]["items"]);
	}
}
file_put_contents("private/database", serialize($arr1));
file_put_contents("private/categories", serialize($arr2));
header('Location: articles.php');
echo "OK\n";

?>
