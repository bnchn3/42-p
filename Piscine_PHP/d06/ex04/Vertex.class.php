<?PHP

require_once("Color.class.php");

class Vertex
{

	private $_x, $_y, $_z, $_w = 1.0, $_color;
	static $verbose = FALSE;	

	function __construct($arr)
	{
		if (isset($arr['x']) && isset($arr['y']) && isset($arr['z']))
		{
			$this->_x = $arr['x'];
			$this->_y = $arr['y'];
			$this->_z = $arr['z'];
			if (isset($arr['w']))
				$this->_w = $arr['w'];
			if (isset($arr['color']))
				$this->_color = $arr['color'];
			else
				$this->_color = new Color(array('rgb' => 0xFFFFFF));
		}
		if (SELF::$verbose)
			printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
		return;
	}

	function __destruct()
	{
		if (SELF::$verbose)
			printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
		return;
	}

	function __toString()
	{
		if (SELF::$verbose)
			$str = sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
		else
			$str = sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
		return ($str);
	}

	public function get_x()
    {
        return ($this->_x);
    }

    public function set_x($value)
    {
        $this->_x = $value;
    }

    public function get_y()
    {
        return ($this->_y);
    }

    public function set_y($value)
    {
        $this->_y = $value;
    }

    public function get_z()
    {
        return ($this->_z);
    }

    public function set_z($value)
    {
        $this->_z = $value;
    }

    public function get_w()
    {
        return ($this->_x);
    }

    public function set_w($value)
    {
        $this->_w = $value;
	}

	 public function get_color()
    {
        return ($this->_color);
    }

    public function set_color($value)
    {
        $this->_color = $value;
    }
	
	public static function doc()
	{
		$str = file_get_contents("Vertex.doc.txt");
		return($str);
	}

}

?>
