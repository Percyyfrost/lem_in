# lem-in

## Project Overview

This project aims to create an algorithm that efficiently finds the fastest route through a network of interconnected rooms, represented as a graph. The goal is to determine the optimal path for a group of "ants" to travel from a starting room ("##start") to an ending room ("##end"), adhering to specific constraints.

## Map Format

The map format is as follows:

- Room lines: Each room is defined by a line containing its ID, coordinates (x, y), and the number of links to other rooms.
- Comment lines: Lines starting with `#` are considered comments and are ignored.
- Start and end lines: The start and end rooms are marked with `##start` and `##end`, respectively.
- Link lines: Links between rooms are defined by pairs of room IDs separated by a hyphen (`-`).

## Example Map

```
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```

## Usage

1. Compile the program using the provided Makefile:
    ```bash
    make
    ```
2. Run the program with the map file as input:
    ```bash
    ./lem-in < map.txt
    ```
3. Optional flags:
    - `-p`: Print the path taken by each ant.
    - `-c`: Color-code the output for visual clarity.
    - `-e`: Display a graphical representation of the map and path.

## Algorithm Design

The core challenge of this project lies in designing an efficient algorithm to find the shortest paths for multiple ants while considering the following constraints:

- Room capacity: Each room can only hold a limited number of ants at a time.
- Ant movement: Ants can only move from one room to another if a link exists between them.
- Path uniqueness: Each ant must take a unique path to the end room.

## Evaluation

Your solution will be evaluated based on:

- Correctness: The program must find valid paths for all ants to reach the end room.
- Efficiency: The algorithm should find the shortest possible paths in a reasonable amount of time.
- Clarity: The code should be well-structured, readable, and maintainable.
