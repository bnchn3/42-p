<?PHP
$arr1 = unserialize(file_get_contents("private/database"));
$arr2 = unserialize(file_get_contents("private/categories"));
sort($arr2);
foreach($arr2 as $i => $j)
{
	sort($arr2[$i]["items"]);
	if (count($arr2[$i]["items"]) == 0)
	{
		$arr2[$i]["name"] = "";
		$arr2[$i] = null;
		$arr2 = array_filter($arr2);
	}
}
?>

<html>
<head>
	<link rel="stylesheet" href="../css/style.css" />
	<title>Manage Items</title>
</head>
<body>
	<div name="login" class="admin">
		<div name="categories" class="list">
			<?PHP
				foreach($arr2 as $i)
				{
					?><div class="cat_row"><?PHP echo $i["name"];?></div><br />
						<?PHP
							foreach($i["items"] as $j)
							{
							?><div class="list_row"><?PHP
									echo $j;?>
									<a href="item_del.php?item=<?PHP echo $j;?>">
										<button type="button">Delete</button>
									</a>
									<a href="item_modif.php?item=<?PHP echo $j;?>">
										<button type="button">Modify</button>
									</a><br />
								</div><?PHP
							}
				}?>
		</div>
		<a href="item_create.html">
			<button type="button">Add Item</button>
		</a>
		<a href="admin_home.php">Back</a>
	</div>
</body>
</html>
