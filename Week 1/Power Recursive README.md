# Power Recursive

## Description

This program calculates x raised to the power n (x^n) using a recursive divide-and-conquer approach. It is more efficient than the iterative version for large exponents.

## Algorithm

1. Base case: if n is 0, return 1
2. If n is negative, return 1 / powerRecursive(x, -n)
3. Calculate half = powerRecursive(x, n/2)
4. If n is even, return half \* half
5. If n is odd, return x _ half _ half

## Functions

- `powerRecursive(double x, int n)`: Calculates x^n recursively using divide and conquer

## Input

- Base (x): double
- Exponent (n): integer

## Output

- Result of x^n

## Time Complexity

O(log n) where n is the exponent

## Space Complexity

O(log n) for the recursive call stack

## Example

```
Enter base (x): 2
Enter exponent (n): 10
2^10 = 1024
```

```
Enter base (x): 3
Enter exponent (n): -2
3^-2 = 0.111111
```
