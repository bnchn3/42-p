<?PHP

class Fighter
{
	private $_type;

	function __construct($type)
	{
		$this->_type = $type;
	}

	function __toString()
	{
		return ($this->_type);
	}
}

?>
