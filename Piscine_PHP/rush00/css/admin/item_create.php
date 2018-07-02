<?PHP

include("photos.php");

if ($_POST["submit"] && $_POST["submit"] == "OK" && $_POST["item"] && $_POST["price"] && $_POST["image"] && $_POST["categories"])
{
	$arr1 = unserialize(file_get_contents("private/database"));
	$arr2 = unserialize(file_get_contents("private/categories"));
	$error = 0;
	foreach ($arr1 as $i)
	{
			if ($i["item"] == $_POST["item"])
				$error = 1;
	}
	if ($error)
	{
		header('Location: item_create.html');
		echo "ERROR\n";
	}
	else
	{
		$temp = array();
		$arr1[] = array("item" => $_POST["item"], "price" => $_POST["price"], "img" => base64_encode(get_img($_POST["image"], $_POST["item"])));
		$temp2 = array_filter(explode(" ", $_POST["categories"]));
		foreach ($temp2 as $j)
		{
			$exists = 0;
			foreach($arr2 as $i => $k)
			{
				if ($k["name"] == $j)
				{
					$arr2[$i]["items"][] = $_POST["item"];
					$exists = 1;
				}
			}
			if (!($exists))
				$temp[] = array("name" => $j, "items" => array($_POST["item"]));
		}
		if (count($temp))
			$arr2 = array_merge($arr2, $temp);
		file_put_contents("private/database", serialize($arr1));
		file_put_contents("private/categories", serialize($arr2));
		header('Location: articles.php');
		echo "OK\n";
	}
}
else
{
	header('Location: item_create.html');
	echo "ERROR\n";
}
?>
