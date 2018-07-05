<?PHP

class Jaime extends Lannister
{
	public function willSleep($person)
	{
		if (is_a($person, "Tyrion"))
			return FALSE;
		else
			return TRUE;
	}

	public function withSister($person)
	{
		if (is_a($person, "Cersei"))
			return TRUE;
		else
			return FALSE;
	}
}

?>
