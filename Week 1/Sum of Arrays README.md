# Sum of Arrays

## Description

This program calculates the sum of all elements in an array using an iterative approach. It includes performance benchmarking to measure execution time across different array sizes.

## Algorithm

1. Initialize sum to 0
2. Iterate through each element in the array
3. Add each element to the sum
4. Return the total sum

## Functions

- `sumOfArray(int arr[], int n)`: Computes the sum of n elements in the array

## Input (Benchmark Mode)

The program automatically tests with 10 different array sizes:

- Array sizes: 1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000
- Each size is tested 10 times
- Arrays are populated with consecutive integers (1, 2, 3, ...)

## Output

- Average execution time for each array size in microseconds
- Complete timing data stored in a 2D vector (10x10)
- Performance analysis across different input sizes

## Time Complexity

O(n) where n is the number of elements in the array

## Space Complexity

O(1) - constant space (excluding input array)

## Performance Benchmarking

The program measures:

- Time taken for each iteration
- Average time across 10 iterations for each array size
- Uses high-resolution clock for precise microsecond measurements

## Example Output

```
Sum of Arrays - Time Analysis
Array Size:  1000 | Average Time: 2.50 microseconds
Array Size:  5000 | Average Time: 12.30 microseconds
Array Size: 10000 | Average Time: 24.80 microseconds
...
```
