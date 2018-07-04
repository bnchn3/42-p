<?PHP

class Color
{

	public $red, $green, $blue;
	static $verbose = FALSE;
	
	function __construct($arr)
	{
		if (isset($arr['rgb']))
		{
			$rgb = intval($arr['rgb']);
			$this->red = $rgb / 65536 % 256;
			$this->green = $rgb / 256 % 256;
			$this->blue = $rgb % 256;
		}
		else if (isset($arr['red']) && isset($arr['green']) && isset($arr['blue']))
		{
			$this->red = intval($arr['red']);
			$this->green = intval($arr['green']);
			$this->blue = intval($arr['blue']);
		}
		if (SELF::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
		return;
	}
	
	function __destruct()
	{
		if (SELF::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
		return;
	}

	function __toString()
	{
		$str = sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue);
		return ($str);
	}

	public static function doc()
	{
		$str = file_get_contents("Color.doc.txt");
		return ($str);
	}

	public function add($Color)
	{
		$new_Color = new Color(array('red' => $this->red + $Color->red, 'green' => $this->green + $Color->green, 'blue' => $this->blue + $Color->blue));
		return ($new_Color);
	}

	public function sub($Color)
	{
		$new_Color = new Color(array('red' => $this->red - $Color->red, 'green' => $this->green - $Color->green, 'blue' => $this->blue - $Color->blue));
		return ($new_Color);
	}

	public function mult($f)
	{
		$new_Color = new Color(array('red' => $this->red * $f, 'green' => $this->green * $f, 'blue' => $this->blue * $f));
		return ($new_Color);
	}

}

?>
