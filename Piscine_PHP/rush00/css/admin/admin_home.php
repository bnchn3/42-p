<?PHP
session_start();

if (!($_SESSION["logged_on_admin"]))
{
	header("Location: admin.html");
	echo "ERROR\n";
}
else
{
?>

<html>
<head>
	<link rel="stylesheet" href="../css/style.css" />
	<title>Admin Home</title>
</head>
<body>
	<div name="spacer" class="spacer"></div>
	<div name="login" class="login">
			<a href="articles.php">Manage Articles</a>
			<a href="users.php">Manage Users</a>
			<a href="admin_modif.html">Change Admin Password</a>
	</div>

</body>
</html>
<?PHP
}?>
