------------------------------
Computer Graphics Lab Programs
------------------------------

These programs are part of the curriculum of computer graphics lab for B.E. course at UVCE, Bangalore University.

To compile:
gcc program_name.c -o program_name -lglut -lGL -lGLU -lm

To run:
./program_name



If you haven't installed OpenGL (these commands work at the time of writing. might change in future.):

Ubuntu:	sudo apt-get install freeglut3-dev

Fedora: sudo yum install freeglut-devel

#include <GL/glut.h>
in the programs which use OpenGL.
