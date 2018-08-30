# FdF
This project involved the creation of a 3D wireframe using a provided graphical library (minilibx), given a map in a text file. Instead of using projection matrices, I decided to code each step in order to fully understand the mathematics behind [graphical projection](https://www.scratchapixel.com/lessons/3d-basic-rendering/get-started). For the lines in between points, I used [Bresenham's line algorithm](https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/). Full instructions can be found [here](fdf.en.pdf).
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
To execute the program use:
```
./fdf file_name
```
File examples are given in the [test_maps folder](test_maps).
## Additional Commands
Within the program, these additional commands have been added:

| Command | Description |
| --- | --- |
| Arrow Keys | Move the map in X-Y space |
| + / - | Zoom in/out |
| C | Change colors |
| Esc | Close the window |
## Allowed functions
- open, read, write, close
- malloc, free
- perror, strerror
- exit
- All functions in the **math** library
- All functions in the **miniLibX** library
