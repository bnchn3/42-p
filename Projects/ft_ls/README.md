#ft_ls
This project involved recoding some of the basic functionalities of the `ls` command. Full instructions can be found [here](ft_ls.en.pdf).
## Makefile
The program can be compiled with
```
make
```
Object files can be removed with
```
make clean
```
The binary and object files can be removed with
```
make fclean
```
The program can be recompiled with
```
make re
```
## Usage
Once compiled, the program can be used similarly to `ls`:
```
./ft_ls [flags] file/directory_names ...
```
## Included Flags
| Flag | Function |
| --- | --- |
| -l | Use a long listing format |
| -R | List subdirectories recursively |
| -a | Include entries starting with . |
| -r | Print entries in reverse order |
| -t | Sort entries by modification time |
| -A | List all entries except . and .. |
| -@ | Display extended attribute keys and sizes in long (-l) output |
| -c | Use time when file status was last changed for sorting (-t) or long printing (-l) |
| -e | Print Access Control Lists (ACL) in long (-l) output (bugged)|
| -o | List in long format, but omit group id |
| -u | Use time of last access for sorting (-t) or long printing (-l) |
| -1 | Force output to one entry per line |
## Known Issues
The `-e` flag will print the Access Control List, but the format does not match the output of the original `ls` command.
## Allowed Functions
- write
- opendir, readdir, closedir
- stat, lstat
- getpwuid, getgrgid
- listxattr, getxattr
- time, ctime
- readlink
- malloc, free
- perror, strerror
- exit
