<?PHP
$arr = unserialize(file_get_contents("admin/private/database"));
?>
<html>
<head>
	<title> </title>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<script src="js/jquery.min.js"></script>
	<script src="js/skel.min.js"></script>
	<script src="js/init.js"></script>
	<noscript>
		<link rel="stylesheet" href="css/skel.css" />
		<link rel="stylesheet" href="css/style.css" />
		<link rel="stylesheet" href="css/style-xlarge.css" />
	</noscript>
	</head>
	<body>
		<header id="header">
			<h1><a href="index.html">Welcome to the shop</span></a></h1>
			<nav id="nav">
				<ul class="adjust-right">
					<li><a href="index.html">Home</a></li>
					<li><a href="cart/cart.php">Cart</a></li>
					<li><a href="./user/html/newlogin.html">Login</a></li>
				</ul>
			</nav>
		</header>
		</div>
		<section id="banner">
			<div class="inner">
				<h2>BenPed</h2>
				<p>Welcome to our online shop</p>
				<ul class="actions">
					<li><a href="#" class="button big scrolly">Add To Cart</a></li>
				</ul>
			</div>
		</section>
		<section id="three" class="wrapper style1">
			<div class="container">
				<header class="major">
					<h2>Items currently on sale</h2>
				</header>
				<div class="row">
					<div class="4u 6u(2) 12u$(3)">
						<article class="box post">
							<a href="#" class="image fit"><img src="images/laptop.jpg" alt="" /></a>
							<ul class="actions">
								<li><a href="cart/add.php?item=LaptopSleeve" class="button">Add To Cart</a></li>
							</ul>
						</article>
					</div>
					<div class="4u 6u$(2) 12u$(3)">
						<article class="box post">
							<a href="#" class="image fit"><img src="images/macbook.jpg" alt="" /></a>

							<ul class="actions">
								<li><a href="cart/add.php?item=Macbook" class="button">Add To Cart</a></li>
							</ul>
						</article>
					</div>
						<div class="4u$ 6u(2) 12u$(3)">
							<article class="box post">
								<a href="#" class="image fit"><img src="images/drone.jpg" alt="" /></a>

								<ul class="actions">
									<li><a href="cart/add.php?item=Drone" class="button">Add To Cart</a></li>
								</ul>
							</article>
						</div>
						<div class="4u 6u$(2) 12u$(3)">
							<article class="box post">
								<a href="#" class="image fit"><img src="images/camera.jpg" alt="" /></a>
								<ul class="actions">
									<li><a href="cart/add.php?item=Camera" class="button">Add To Cart</a></li>
								</ul>
							</article>
						</div>
						<div class="4u 6u(2) 12u$(3)">
							<article class="box post">
								<a href="#" class="image fit"><img src="images/drones.jpg" alt="" /></a>

								<ul class="actions">
									<li><a href="cart/add.php?item=Drone2" class="button">Add To Cart</a></li>
								</ul>
							</article>
						</div>
						<div class="4u$ 6u$(2) 12u$(3)">
							<article class="box post">
								<a href="#" class="image fit"><img src="images/blue.jpg" alt="" /></a>
								<ul class="actions">
									<li><a href="cart/add.php?item=BluetoothSpeaker" class="button">Add To Cart</a></li>
								</ul>
							</article>
						</div>
					</div>
				</div>
			</section>
			<footer id="footer">
				<span class="copyright">
					&copy; PNUNEZ BENJAMIN</a>
				</span>
			</footer>

	</body>
</html>
