<?PHP

require_once("Vertex.class.php");
require_once("Vector.class.php");
require_once("Matrix.class.php");

class Camera
{
	private $_tT, $_tR, $_view, $_proj;
	private $_origin, $_orientation, $_width, $_height, $_ratio, $_fov, $_near, $_far;
	static $verbose = FALSE;

	function __construct($arr)
	{
		if (isset($arr['origin']))
			$this->_origin = $arr['origin'];
		if (isset($arr['orientation']))
			$this->_orientation = $arr['orientation'];
		if (isset($arr['width']))
			$this->_width = $arr['width'];
		if (isset($arr['height']))
			$this->_height = $arr['height'];
		if (isset($arr['ratio']))
			$this->_ratio = $arr['ratio'];
		if (isset($arr['fov']))
			$this->_fov = $arr['fov'];
		if (isset($arr['near']))
			$this->_near = $arr['near'];
		if (isset($arr['far']))
			$this->_far = $arr['far'];
		$this->create_camera();
		if (SELF::$verbose)
			printf("Camera instance constructed\n");
		return;
	}

	function __destruct()
	{
		if (SELF::$verbose)
			printf("Camera instance destructed\n");
		return;
	}

	function __toString()
	{
		$str = "Camera(\n";
		$str = $str."+ Origine: ".$this->_origin."\n";
		$str = $str."+ tT:\n".$this->_tT."\n";
		$str = $str."+ tR:\n".$this->_tR."\n";
		$str = $str."+ tR->mult( tT ):\n".$this->_view."\n";
		$str = $str."+ Proj:\n".$this->_proj."\n)";
		return ($str);
	}

	private function create_camera()
	{
		$temp = new Vector(array('dest' => $this->_origin));
		$temp = $temp->opposite();
		$this->_tT = new Matrix(array('preset' => Matrix::TRANSLATION, 'vtc' => $temp));
		$this->_tR = $this->_orientation->invert();
		$this->_view = $this->_tR->mult($this->_tT);
		if ($this->_width && $this->_height)
			$ratio = $this->_width / $this->_height;
		else
			$ratio = $this->_ratio;
		$this->_proj = new Matrix(array('preset' => Matrix::PROJECTION, 'ratio' => $ratio, 'fov' => $this->_fov,
			'near' => $this->_near, 'far' => $this->_far));
	}

	public static function doc()
	{
		$str = file_get_contents("Camera.doc.txt");
		return($str);
	}

	public function watchVertex($worldVertex): Vertex
	{
		return ($this->_proj->transformVertex($worldVertex));
	}

}

?>
