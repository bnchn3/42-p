var=$(ifconfig | grep 'inet ')
if test -z "$var"
then
	echo "I am lost!\n"
else
	ifconfig | grep 'inet ' | awk '{print $2}'
fi
