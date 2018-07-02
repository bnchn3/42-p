<?PHP

if (file_exists("private/orders"))
	$arr = unserialize(file_get_contents("private/orders"));

?>
<html>
<head>
	<link rel="stylesheet" href="../css/style.css" />
	<title>Manage Orders</title>
</head>
<body>
	<div name="spacer" class="spacer"></div>
	<div name="login" class="admin">
		<div name="users" class="list">
			<?PHP
				foreach($arr as $i => $j)
				{
					if ($j["user"] == $_GET["login"])
					{
						?><div class="list_row"><?PHP
						foreach($arr[$i]["items"] as $k)
						{
							$temp[] = $k["item"]." x ".$k["count"];
						}
						$items = implode(", ", $temp);
						echo $j["time"]."   ".$items."    $".$j["price"];?>
						</div>
					<?PHP
					}
				}?>
		</div>
		<a href="users.php">Back</a>
	</div>
</body>
</html>
