<?PHP

require_once("Vertex.class.php");
require_once("Vector.class.php");

class Matrix
{

	const IDENTITY = 'IDENTITY';
	const SCALE = 'SCALE';
	const RX = 'Ox ROTATION';
	const RY = 'Oy ROTATION';
	const RZ = 'Oz ROTATION';
	const TRANSLATION = 'TRANSLATION';
	const PROJECTION = 'PROJECTION';

	private $_matrix;
	private $_preset, $_scale, $_angle, $_vtc, $_fov, $_ratio, $_near, $_far;
	static $verbose = FALSE;

	function __construct($arr)
	{
		if (isset($arr['preset']))
			$this->_preset = $arr['preset'];
		if (isset($arr['scale']))
			$this->_scale = $arr['scale'];
		if (isset($arr['angle']))
			$this->_angle = $arr['angle'];
		if (isset($arr['vtc']))
			$this->_vtc = $arr['vtc'];
		if (isset($arr['fov']))
			$this->_fov = $arr['fov'];
		if (isset($arr['ratio']))
			$this->_ratio = $arr['ratio'];
		if (isset($arr['near']))
			$this->_near = $arr['near'];
		if (isset($arr['far']))
			$this->_far = $arr['far'];
		if (isset($arr['matrix']))
			$this->_matrix = $arr['matrix'];
		else
			$this->create_matrix();
		if (SELF::$verbose)
		{
			if ($this->_preset == SELF::IDENTITY)
				printf("Matrix %s instance constructed\n", $this->_preset);
			else
				printf("Matrix %s preset instance constructed\n", $this->_preset);
		}
		return;
	}

	function __destruct()
	{
		if (SELF::$verbose)
			print("Matrix instance destructed\n");
		return;
	}

	function __toString()
	{
		$m = $this->_matrix;
		$str = sprintf("M | vtcX | vtcY | vtcZ | vtx0\n");
		$str = $str.sprintf("-----------------------------\n");
		$str = $str.sprintf("x | %.2f | %.2f | %.2f | %.2f\n", $m[0][0], $m[0][1], $m[0][2], $m[0][3]);
		$str = $str.sprintf("y | %.2f | %.2f | %.2f | %.2f\n", $m[1][0], $m[1][1], $m[1][2], $m[1][3]);
		$str = $str.sprintf("z | %.2f | %.2f | %.2f | %.2f\n", $m[2][0], $m[2][1], $m[2][2], $m[2][3]);
		$str = $str.sprintf("w | %.2f | %.2f | %.2f | %.2f", $m[3][0], $m[3][1], $m[3][2], $m[3][3]);
		return ($str);
	}

	private function create_matrix()
	{
		$this->_matrix = array_fill(0, 4, array(0, 0, 0, 0));
		if ($this->_preset == SELF::IDENTITY)
		{
			$this->_matrix[0][0] = 1;
			$this->_matrix[1][1] = 1;
			$this->_matrix[2][2] = 1;
			$this->_matrix[3][3] = 1;
		}
		if ($this->_preset == SELF::SCALE)
		{
			$this->_matrix[0][0] = $this->_scale;
            $this->_matrix[1][1] = $this->_scale;
            $this->_matrix[2][2] = $this->_scale;
            $this->_matrix[3][3] = 1;
		}
		if ($this->_preset == SELF::RX)
		{
			$this->_matrix[0][0] = 1;
			$this->_matrix[1][1] = cos($this->_angle);
			$this->_matrix[1][2] = sin($this->_angle) * -1;
			$this->_matrix[2][1] = sin($this->_angle);
			$this->_matrix[2][2] = cos($this->_angle);
			$this->_matrix[3][3] = 1;
		}
		if ($this->_preset == SELF::RY)
        {
            $this->_matrix[0][0] = cos($this->_angle);
            $this->_matrix[0][2] = sin($this->_angle);
            $this->_matrix[1][1] = 1;
            $this->_matrix[2][0] = sin($this->_angle) * -1;
            $this->_matrix[2][2] = cos($this->_angle);
            $this->_matrix[3][3] = 1;
		}
		if ($this->_preset == SELF::RZ)
        {
            $this->_matrix[0][0] = cos($this->_angle);
            $this->_matrix[0][1] = sin($this->_angle) * -1;
            $this->_matrix[1][0] = sin($this->_angle);
            $this->_matrix[1][1] = cos($this->_angle);
            $this->_matrix[2][2] = 1;
            $this->_matrix[3][3] = 1;
		}
		if ($this->_preset == SELF::TRANSLATION)
		{
			$this->_matrix[0][0] = 1;
			$this->_matrix[0][3] = $this->_vtc->get_x();
			$this->_matrix[1][1] = 1;
			$this->_matrix[1][3] = $this->_vtc->get_y();
			$this->_matrix[2][2] = 1;
			$this->_matrix[2][3] = $this->_vtc->get_z();
			$this->_matrix[3][3] = 1;
		}
		if ($this->_preset == SELF::PROJECTION)
		{
			$S = 1 / (tan($this->_fov / 2 * pi() / 180));
			$this->_matrix[0][0] = $S / $this->_ratio;
			$this->_matrix[1][1] = $S;
			$this->_matrix[2][2] = -1 * ($this->_far + $this->_near) / ($this->_far - $this->_near);
			$this->_matrix[2][3] = -2 * ($this->_near * $this->_far) / ($this->_far - $this->_near);
			$this->_matrix[3][2] = -1;
		}
	}

	public static function doc()
	{
		$str = file_get_contents("Matrix.doc.txt");
		return($str);
	}

	public function get_matrix()
	{
		return($this->_matrix);
	}

	public function mult($mat): Matrix
	{
		$mat = $mat->get_matrix();
		$m = array_fill(0, 4, array(0, 0, 0, 0));
		for ($i = 0; $i < 4; ++$i)
		{
			for ($j = 0; $j < 4; ++$j)
			{
				$m[$i][$j] = $this->_matrix[$i][0] * $mat[0][$j] +
							$this->_matrix[$i][1] * $mat[1][$j] +
							$this->_matrix[$i][2] * $mat[2][$j] +
							$this->_matrix[$i][3] * $mat[3][$j];
			}
		}
		return (new Matrix(array('matrix' => $m)));
	}

	public function transformVertex($vtx): Vertex
	{
		$x = $vtx->get_x();
		$y = $vtx->get_y();
		$z = $vtx->get_z();
		$m = $this->_matrix;
		$i = $x * $m[0][0] + $y * $m[0][1] + $z * $m[0][2] + $m[0][3];
		$j = $y * $m[1][0] + $y * $m[1][1] + $z * $m[1][2] + $m[1][3];
		$k = $x * $m[2][0] + $y * $m[2][1] + $z * $m[2][2] + $m[2][3];
		return (new Vertex(array('x' => $i, 'y' => $j, 'z' => $k, 'color' => $vtx->get_color())));
	}

	public function invert(): Matrix
	{
		$m = array_fill(0, 4, array(0, 0, 0, 0));
		for ($i = 0; $i < 4; ++$i)
		{
			for ($j = 0; $j < 4; ++$j)
			{
				$m[$i][$j] = $this->_matrix[$j][$i];
			}
		}
		return (new Matrix(array('matrix' => $m)));
	}

}

?>
