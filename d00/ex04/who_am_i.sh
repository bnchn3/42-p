ldapsearch uid=bchan dn | grep '^dn:' | sed "s/dn: //"
