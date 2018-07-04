<?PHP

require_once("Vertex.class.php");

class Vector
{

	private $_x, $_y, $_z, $_w;
	static $verbose = FALSE;

	function __construct($arr)
	{
		if (isset($arr['dest']))
		{
			if (isset($arr['orig']))
				$orig = $arr['orig'];
			else
				$orig = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1));
			$this->_x = $arr['dest']->get_x() - $orig->get_x();
			$this->_y = $arr['dest']->get_y() - $orig->get_y();
			$this->_z = $arr['dest']->get_z() - $orig->get_z();
			$this->_w = 0;
		}
		if (SELF::$verbose)
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
		return;
	}

	function __destruct()
	{
		if (SELF::$verbose)
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
		return;
	}

	function __toString()
	{
		$str = sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
		return ($str);
	}

	public function get_x()
    {
        return($this->_x);
    }

    public function get_y()
    {
        return($this->_y);
    }

    public function get_z()
    {
        return($this->_z);
    }

    public function get_w()
    {
        return($this->_w);
	}

	public static function doc()
	{
		$str = file_get_contents("Vector.doc.txt");
		return($str);
	}

	public function magnitude(): float
	{
		return (sqrt($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z));
	}

	public function normalize(): Vector
	{
		$length = SELF::magnitude();
		if ($length > 0)
		{
			$x = $this->_x / $length;
			$y = $this->_y / $length;
			$z = $this->_z / $length;
			$norm = new Vertex(array('x' => $x, 'y' => $y, 'z' => $z));
			return(new Vector(array('dest' => $norm)));
		}
	}

	public function add($vec): Vector
	{
		$x = $this->_x + $vec->get_x();
		$y = $this->_y + $vec->get_y();
		$z = $this->_z + $vec->get_z();
		return(new Vector(array('dest' => new Vertex(array('x' => $x, 'y' => $y, 'z' => $z)))));
	}

	public function sub($vec): Vector
    {
        $x = $this->_x - $vec->get_x();
        $y = $this->_y - $vec->get_y();
        $z = $this->_z - $vec->get_z();
        return(new Vector(array('dest' => new Vertex(array('x' => $x, 'y' => $y, 'z' => $z)))));
	}

	public function opposite(): Vector
    {
        $x = $this->_x * -1;
        $y = $this->_y * -1;
        $z = $this->_z * -1;
        return(new Vector(array('dest' => new Vertex(array('x' => $x, 'y' => $y, 'z' => $z)))));
	}

	public function scalarProduct($i): Vector
    {
        $x = $this->_x * $i;
        $y = $this->_y * $i;
        $z = $this->_z * $i;
        return(new Vector(array('dest' => new Vertex(array('x' => $x, 'y' => $y, 'z' => $z)))));
	}

	public function dotProduct($vec): float
	{
		$x = $this->_x * $vec->get_x();
        $y = $this->_y * $vec->get_y();
		$z = $this->_z * $vec->get_z();
		return($x + $y + $z);
	}

	public function cos($vec): float
	{
		$unit = $vec->normalize();
		$dot = SELF::dotProduct($unit);
		return ($dot / SELF::magnitude());
	}

	public function crossProduct($vec): Vector
	{
		$x = $this->_y * $vec->get_z() - $this->_z * $vec->get_y();
		$y = $this->_z * $vec->get_x() - $this->_x * $vec->get_z();
		$z = $this->_x * $vec->get_y() - $this->_y * $vec->get_x();
		return(new Vector(array('dest' => new Vertex(array('x' => $x, 'y' => $y, 'z' => $z)))));
	}

}

?>
