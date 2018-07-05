<?PHP

class UnholyFactory
{
	private $_absorbed = array();

	public function absorb($soldier)
	{
		if(is_subclass_of($soldier, "Fighter"))
		{
			if(in_array($soldier, $this->_absorbed))
				printf("(Factory already absorbed a fighter of type %s)\n", $soldier);
			else
			{
				$this->_absorbed[] = $soldier;
				printf("(Factory absorbed a fighter of type %s)\n", $soldier);
			}
		}
		else
			printf("(Factory can't absorb this, it's not a fighter)\n");
	}

	public function fabricate($soldier)
	{
		if(in_array($soldier, $this->_absorbed))
		{
			printf("(Factory fabricates a fighter of type %s)\n", $soldier);
			return($this->_absorbed[array_search($soldier, $this->_absorbed)]);
		}
		else
			printf("(Factory hasn't absorbed any fighter of type %s)\n", $soldier);
		return(NULL);
	}
}

?>
