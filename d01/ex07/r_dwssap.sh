cat /etc/passwd | awk '$1!="#"' | awk '$1!="##"' | awk 'NR%2==0' | awk 'BEGIN{FS=":"}{for (i=length($1);i>=1;i--) printf(substr($1,i,1)); print(",")}' | sort -r | awk -v var="$FT_LINE2" 'NR<=var' | awk -v var="$FT_LINE1" 'NR>=var' | tr '\n' ' ' | awk '{for (i=1;i<length-1;i++) printf(substr($0,i,1)); printf(".")}'
