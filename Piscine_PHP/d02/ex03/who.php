#!/usr/bin/php
<?PHP

date_default_timezone_set("America/Los_Angeles");
$utmp = fopen("/var/run/utmpx", 'r');
while ($ret = fread($utmp, 628))
{
	$arr = unpack("a256user/a4id/a32tty/ipid/itype/I2time/a256host/i16pad", $ret);
	$arr2[$arr["tty"]] = $arr;
}
ksort($arr2);
foreach($arr2 as $elem)
	if ($elem["type"] == 7)
		printf("%s\t%s\t%s\n", $elem["user"], $elem["tty"], date("M d H:i", $elem["time1"]))

?>
