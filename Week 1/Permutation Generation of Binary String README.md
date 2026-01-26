# Permutation Generation of Binary String

## Description

This program generates all possible binary strings of a given length using recursion. For a binary string of length n, it generates all 2^n possible combinations. The program includes performance benchmarking to measure execution time.

## Algorithm

The recursive algorithm works as follows:

1. Base case: If current index equals string length, one binary string is complete
2. Set current position to '0' and recursively generate remaining positions
3. Set current position to '1' and recursively generate remaining positions
4. This creates a binary tree of choices, generating all 2^n combinations

## Functions

- `permutationGenerationOfBinaryString(int n, int idx, string &current)`: Recursively generates all binary strings of length n

## Input (Benchmark Mode)

The program automatically tests with 10 different string lengths:

- String lengths: 5, 10, 12, 14, 16, 18, 20, 21, 22, 23
- Each length is tested 10 times
- Generates binary strings with '0' and '1' characters

## Output

- Average execution time for each string length in microseconds
- Complete timing data stored in a 2D vector (10x10)
- Performance analysis showing exponential growth

## Time Complexity

O(2^n) where n is the length of the binary string

- Generates 2^n total binary strings
- Each string generation involves O(n) operations

## Space Complexity

O(n) for the recursion call stack depth

## Performance Analysis

Number of binary strings generated for each length:

- Length 5: 32 strings
- Length 10: 1,024 strings
- Length 20: 1,048,576 strings
- Length 23: 8,388,608 strings (maximum safe value)

## Performance Considerations

- Length 23 generates over 8 million strings (takes significant time)
- Length 24+: may cause stack overflow or excessive execution time
- Exponential growth means doubling the length increases time ~4x

## Example Output

```
Permutation Generation of Binary String - Time Analysis
String Length:  5 | Average Time: 1.25 microseconds
String Length: 10 | Average Time: 35.40 microseconds
String Length: 20 | Average Time: 35000.00 microseconds
String Length: 23 | Average Time: 280000.00 microseconds
...
```
