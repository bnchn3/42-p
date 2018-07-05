<?PHP

class Lannister
{
	public function sleepWith($person)
	{
		if ($this->willSleep($person))
		{
			if ($this->withSister($person))
				print("With pleasure, but only in a tower in Winterfell, then.\n");
			else
				print("Let's do this.\n");
		}
		else
			print("Not even if I'm drunk !\n");
	}
}

?>
