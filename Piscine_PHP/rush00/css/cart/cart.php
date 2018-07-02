<?PHP

session_start();
if (!($_SESSION["logged_on_user"]))
{
	header('Location: ../user/html/newlogin.html');
	echo "ERROR\n";
}
else
{
	if (file_exists("private/cart"))
		$arr = unserialize(file_get_contents("private/cart"));
	else
		$arr = array();
	$total = 0;
?>
<html>
<head>
	<title>Cart</title>
	<link rel="stylesheet" href="../css/style.css" />
</head>
<body>
	<div name="login" class="admin">
		<div name="categories" class="list">
			<?PHP
				foreach($arr as $i)
				{
					?><div class="list_row"><?PHP
							echo $i["item"]."    ".$i["count"]." x $".$i["price"];
							$total += floatval($i["price"]) * $i["count"];
							?>
							<a href="add.php?item=<?PHP echo $i['item'];?>">
								<button type="button">Add</button>
							</a>
							<a href="delete.php?item=<?PHP echo $i['item'];?>">
								<button type="button">Remove</button>
							</a><br />
						</div><?PHP
				}?>
				<h3 style="justify-content: flex-end;">Total: <?PHP echo "$".$total; ?></h3>
		</div>
		<a href="validate.php">
			<button type="button">Validate</button>
		</a>
		<a href="../index.php">Back</a>
	</div>
</body>
</html>
<?PHP
}
?>
