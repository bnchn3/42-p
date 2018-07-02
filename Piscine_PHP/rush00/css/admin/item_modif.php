<?PHP

include("photos.php");

$arr1 = unserialize(file_get_contents("private/database"));
$arr2 = unserialize(file_get_contents("private/categories"));
$temp = array();
foreach($arr1 as $i)
{
	if ($i["item"] == $_GET["item"])
		$item = $i;
}
foreach($arr2 as $i)
{
	foreach($i["items"] as $j)
	{
		if ($j == $_GET["item"])
			$temp[] = $i["name"];
	}
}
$cat = implode(" ", $temp);
?>
<html>
<head>
	<title>Modify Item</title>
	<link rel="stylesheet" href="../css/style.css" />
</head>
<body>
	<div name="spacer" class="spacer"></div>
	<div name="login" class="login">
			<form name="login.php" action="item_modif_2.php" method="POST">
				ITEM: <br />
				<input type="text" name="item" value="<?PHP echo $_GET['item']; ?>" /><br />
				PRICE: <br />
				<input type="text" name="price" value="<?PHP echo $item['price']; ?>" /><br />
				IMAGE: <br />
				<input type="text" name="image" value="" /><br />
				CATEGORIES: <br />
				<input type="text" name="categories" value="<?PHP echo $cat; ?>" /> <br />
				<input type="submit" name="submit" value="OK" />
			</form>
			<a href="articles.php">Back</a>
	</div>

</body>
</html>
