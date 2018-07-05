<?PHP

class Tyrion extends Lannister
{
	public function willSleep($person)
	{
		if (is_a($person, "Lannister"))
			return FALSE;
		else
			return TRUE;
	}
	
	public function withSister($person)
	{
		return FALSE;
	}
}

?>
