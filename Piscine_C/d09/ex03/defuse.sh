touch -A -000001 -a bomb.txt | stat -f %a bomb.txt | cat -e
