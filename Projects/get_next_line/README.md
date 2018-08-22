# get_next_line
This project involved creating a function that could be called in a loop to read a file line by line and save the contents into a usable format. My function also implements the ability to read from multiple files without losing the file position. Full instructions can be found [here](get_next_line.en.pdf).
## Using the function
The function takes in two parameters: the file descriptor for the file to be read, and a pointer to a string that will save the line read from the file descriptor. The function will return 1, 0, or -1 when a line has been read, when the entire file has been read, or if an error has happened, respectively. A line is delimited by a '\n' character.

To change the number of bytes the function reads in each pass, edit the BUFF_SIZE macro in the header file:
```
#define BUFF_SIZE 32
```
## Allowed functions
- read
- malloc
- free
