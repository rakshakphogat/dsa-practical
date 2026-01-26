# Tower of Hanoi

## Description

This program solves the classic Tower of Hanoi puzzle using recursion. The puzzle involves moving disks from a source rod to a destination rod using an auxiliary rod, with the constraint that a larger disk cannot be placed on a smaller disk.

## Algorithm

The recursive approach follows these steps:

1. Move n-1 disks from source to auxiliary rod using destination as temporary
2. Move the largest disk from source to destination
3. Move n-1 disks from auxiliary to destination using source as temporary

## Functions

- `towerOfHanoi(int n, char source, char destination, char auxiliary)`: Recursively solves the Tower of Hanoi problem and prints each move

## Input

- Number of disks (integer)

## Output

- Step-by-step moves required to solve the puzzle

## Time Complexity

O(2^n) where n is the number of disks

## Space Complexity

O(n) for the recursive call stack

## Example

```
Enter number of disks: 3
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```
