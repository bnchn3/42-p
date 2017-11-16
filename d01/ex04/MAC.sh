ifconfig | egrep "ether[[:space:]]" | sed -E "s/ether[[:space:]]//g"
