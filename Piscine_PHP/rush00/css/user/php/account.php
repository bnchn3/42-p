<?PHP
session_start();
if (!($_SESSION["logged_on_user"]))
	header("Location: ../html/create.html");
?>

<html>
<head>
	<title>Manage Account</title>
	<link rel="stylesheet" href="../../css/style.css" />
</head>
<body>
	<div name="spacer" class="spacer"></div>
	<div name="login" class="login">
		Username: <?PHP echo $_SESSION["logged_on_user"]?> <br><br>
		<a href="../html/modif.html">
			<button type="button">Change Password</button>
		</a><br><br>
		<a href="../html/delete_acc.html">
			<button type="button">Delete Account</button>
		</a>
		<a href="../../index.php">
			Home
		</a>
	</div>
</body>
</html>
