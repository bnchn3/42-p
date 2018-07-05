<?PHP

class NightsWatch
{
	private $_crows;

	public function recruit($person)
	{
		$this->_crows[] = $person;
	}

	public function fight()
	{
		foreach($this->_crows as $fighter)
		{
			if (is_subclass_of($fighter, "IFighter"))
				$fighter->fight();
		}
	}
}

?>
