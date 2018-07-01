<?PHP
session_start();
if (!($_SESSION["loggued_on_user"]))
	header("Location: create.html");
?>

<html>
<head>
	<title>Manage Account</title>
	<link rel="stylesheet" href="main.css" />
</head>
<body>
	<div name="spacer" class="spacer"></div>
	<div name="login" class="login">
		Username: <?PHP echo $_SESSION["loggued_on_user"]?> <br><br>
		<a href="modif.html">
			<button type="button">Change Password</button>
		</a><br><br>
		<a href="delete_acc.html">
			<button type="button">Delete Account</button>
		</a>
	</div>
</body>
</html>
