# fillit
The second project in the 42 curriculum, this program will take in a list of tetris pieces (Tetriminos) and assemble them into the smallest possible square. The algorithm I used takes an outside-in approach, generating the largest possible square first and running every permutation of pieces using the same placement algorithm, then saving the placement order of the smallest square. The final answer can then be generated using the saved order and the same placement algorithm. Full instructions for the project can be found [here](fillit.en.pdf).
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
## Using the program
The executable must take in the name of no more than one file as a parameter
```
./fillit filename
```
This file must contain a list of Tetriminos to assemble. Each Tetrimino must fit within a 4x4 char square and each square must be separated by a newline. Tetrimino blocks must be represented by '#' characters and empty spaces must be represented by '.' characters. Valid Tetriminos are any of the classic 4-block [Tetris pieces](https://tetris.wiki/Tetromino). The program will only accept files with up to 26 Tetriminos.

Example input:
```
...#
...#
...#
...#

....
....
..##
..##
```
The output will be the smallest possible square using the inputted pieces. Each piece will be represented by a capital letter, starting with 'A' and continuing based on the order of the Tetriminos in the input file. In the case of multiple final solutions with the same area, the solution with the pieces in the most upper left position will be given.

Example output:
```
ABB.
ABB.
A...
A...
```
## Allowed functions
- exit
- open
- close
- write
- read
- malloc
- free
