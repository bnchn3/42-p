<?PHP
$arr = unserialize(file_get_contents("../user/private/passwd"));
sort($arr);
?>

<html>
<head>
	<link rel="stylesheet" href="../css/style.css" />
	<title>Manage Users</title>
</head>
<body>
	<div name="spacer" class="spacer"></div>
	<div name="login" class="admin">
		<div name="users" class="list">
			<?PHP
				foreach($arr as $i)
				{
					?><div class="list_row"><?PHP
							echo $i["login"];?>
							<a href="user_del.php?login=<?PHP echo $i['login'];?>">
								<button type="button">Delete</button>
							</a>
							<a href="orders.php?login=<?PHP echo $i['login'];?>">
								<button type="button">Manage Orders</button>
							</a><br />
						</div><?PHP
				}?>
		</div>
		<a href="user_create.html">
			<button type="button">Add User</button>
		</a>
		<a href="admin_home.php">Back</a>
	</div>
</body>
</html>
