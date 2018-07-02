<?PHP

include("photos.php");

if ($_POST["submit"] && $_POST["submit"] == "OK" && $_POST["price"] && $_POST["item"] && $_POST["categories"])
{
	$arr1 = unserialize(file_get_contents("private/database"));
	$arr2 = unserialize(file_get_contents("private/categories"));
	$error = 1;
	foreach ($arr1 as $i => $j)
	{
			if ($j["item"] == $_POST["item"])
			{
				if ($_POST["image"])
					$arr1[$i]["img"] = base64_encode(get_img($_POST["image"], $_POST["item"]));
				$arr1[$i]["price"] = $_POST["price"];
				$error = 0;
			}
	}
	if ($error)
	{
		header('Location: articles.php');
		echo "ERROR\n";
	}
	else
	{
		$temp = array();
		$temp2 = array_filter(explode(" ", $_POST["categories"]));
		foreach($temp2 as $j)
		{
			$exists = 0;
			foreach($arr2 as $i => $k)
			{
				if ($k["name"] == $j)
				{
					$exists = 1;
					if (array_search($_POST["item"], $arr2[$i]["items"]) === FALSE)
						$arr2[$i]["items"][] = $_POST["item"];
				}
				else
				{
					if (array_search($_POST["item"], $arr2[$i]["items"]) !== FALSE && array_search($k["name"], $temp2) === FALSE)
					{
						$a = array_search($_POST["item"], $arr2[$i]["items"]);
						$arr2[$i]["items"][$a] = "";
						$arr2[$i]["items"] = array_filter($arr2[$i]["items"]);
					}
				}
			}
			if (!($exists))
				$temp[] = array("name" => $j, "items" => array($_POST["item"]));
		}
		$arr2 = array_filter($arr2);
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
	header('Location: item_modif.php?item='.$_POST["item"]);
	echo "ERROR\n";
}
?>
