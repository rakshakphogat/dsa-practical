# Permutation Generation of String

## Description

This program generates all permutations of a given string using a recursive backtracking algorithm. It includes performance benchmarking to measure execution time for different string lengths.

## Algorithm

The algorithm uses backtracking with the following approach:

1. Base case: If current index equals string length, one permutation is complete
2. For each position from current index to end:
   - Swap current character with the character at current index
   - Recursively generate permutations for remaining positions
   - Backtrack by swapping characters back to original positions

This generates all n! permutations where n is the string length.

## Functions

- `permutationGenerationOfString(int n, int idx, string &s)`: Recursively generates all permutations of string s

## Input (Benchmark Mode)

The program automatically tests with 10 different string lengths:

- String lengths: 2, 3, 4, 5, 6, 7, 8, 9, 10, 10
- Each length is tested 10 times
- Uses alphabetic strings: "ab", "abc", "abcd", etc.

## Output

- Average execution time for each string length in microseconds
- Complete timing data stored in a 2D vector (10x10)
- Performance analysis showing exponential growth with string length

## Time Complexity

O(n! × n) where n is the string length

- n! permutations are generated
- Each permutation requires O(n) operations

## Space Complexity

O(n) for the recursion call stack depth

## Performance Considerations

- String length 10: ~3.6 million permutations (slow but manageable)
- String length 11+: causes stack overflow due to excessive recursion
- Maximum safe length is capped at 10 characters

## Example Output

```
Permutation Generation of String - Time Analysis
String Length:  2 | Average Time: 0.15 microseconds
String Length:  3 | Average Time: 0.45 microseconds
String Length:  5 | Average Time: 12.30 microseconds
String Length: 10 | Average Time: 45000.00 microseconds
...
```
