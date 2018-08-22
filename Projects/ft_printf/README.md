# ft_printf
This project involved recoding the libc function [printf](http://www.cplusplus.com/reference/cstdio/printf/). Full instructions can be found [here](ft_printf.en.pdf).
## Makefile
The library can be compiled with
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
The library can be recompiled with
```
make re
```
## Format specifiers
All standard format specifiers and flags are included in my implementation of printf. Check out the [documentation](http://www.cplusplus.com/reference/cstdio/printf/) of the original function for more information.
## Allowed functions
- write
- malloc
- free
- exit
- va_start
- va_arg
- va_end
- va_copy
