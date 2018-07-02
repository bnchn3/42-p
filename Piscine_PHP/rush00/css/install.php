<?PHP

if (!(file_exists("admin/private")))
	mkdir("admin/private");
if (!(file_exists("admin/private/passwd")))
{
	$temp1 = array("login" => "bchan", "passwd" => hash("whirlpool", "password"));
	$temp2 = array("login" => "pnunez", "passwd" => hash("whirlpool", "password"));
	$arr = array($temp1, $temp2);
	file_put_contents("admin/private/passwd", serialize($arr));
}
if (!(file_exists("admin/private/database")))
{
	$temp1 = array("item" => "Macbook", "price" => 1299.99, "img" => base64_encode("images/macbook.jpg"));
	$temp2 = array("item" => "Drone", "price" => 399.99, "img" => base64_encode("images/drone.jpg"));
	$temp3 = array("item" => "Drone2", "price" => 599.99, "img" => base64_encode("images/drones.jpg"));
	$temp4 = array("item" => "LaptopSleeve", "price" => 29.99, "img" => base64_encode("images/laptop.jpg"));
	$temp5 = array("item" => "Camera", "price" => 99.99, "img" => base64_encode("images/camera.jpg"));
	$temp6 = array("item" => "BluetoothSpeaker", "price" => 49.99, "img" => base64_encode("images/blue.jpg"));
	$arr = array($temp1, $temp2, $temp3, $temp4, $temp5, $temp6);
	file_put_contents("admin/private/database", serialize($arr));
}
if (!(file_exists("admin/private/categories")))
{
	$temp1 = array("name" => "Apple", "items" => array("Macbook"));
	$temp2 = array("name" => "Laptop", "items" => array("Macbook"));
	$temp3 = array("name" => "Drone", "items" => array("Drone", "Drone2"));
	$temp4 = array("name" => "Electronics", "items" => array("Macbook", "Drone"));
	$temp5 = array("name" => "Camera", "items" => array("Camera"));
	$temp = array("name" => "Accessories", "items" => array("LaptopSleeve", "BluetoothSpeaker"));
	$arr = array($temp1, $temp2, $temp3, $temp4);
	file_put_contents("admin/private/categories", serialize($arr));
}

?>
