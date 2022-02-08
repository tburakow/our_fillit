# our_fillit
Hive Helsinki project. A program to fit tetris-pieces into smallest possible square. (no rotation.)

This program was written together with @github/cony101. 

## Quick start

Compile with make file
```
make
```
Run with example file
```
./fillit exaple.txt
```

## What does it do?

This program accepts tetris-pieces in the following format. It fits them into the smallest possible square (without rotateing the pieces.)
It attempts to place the pieces in the order they are in the input file, i.e. the top piece will be placed as close to top/left as possible etc.
```
..##
..##
....
....

####
....
....
....
```
- Each piece is made of hashes(#) on a 4 x 4 field of dots (.). Each row therefore has four dots or hashes followed by a newline.

- Each piece is separated by a newline. The maximum amount of pieces (called tetrimino in the comments) is 26.

- Each piece consists of four hashes that are attached to each other (parallel and next to, or above/below.)

- There can be no empty line at the end of the input file.

The output is in the following format (for above example):
```
AAAA
BB..
BB..
....
```
Where the letter represents the position of the tetrimino in the file with A being first, B secondd and so forth.

Fixes/future additions:

- Some amounts of identical tetriminos slow the program a lot. For example 10 square tetriminos is incredibly slow.
