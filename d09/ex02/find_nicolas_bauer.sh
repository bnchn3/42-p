cat $1 | grep -i "Nicolas\tBauer" | awk '{print $(NF-1)}'
