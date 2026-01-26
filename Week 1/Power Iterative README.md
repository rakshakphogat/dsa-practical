# Power Iterative

## Description

This program calculates x raised to the power n (x^n) using an iterative approach. It handles both positive and negative exponents.

## Algorithm

1. Initialize result to 1.0
2. Multiply result by x for n times
3. If n is negative, return the reciprocal of the result

## Functions

- `powerIterative(double x, int n)`: Calculates x^n iteratively

## Input

- Base (x): double
- Exponent (n): integer

## Output

- Result of x^n

## Time Complexity

O(n) where n is the exponent

## Space Complexity

O(1) - constant space

## Example

```
Enter base (x): 2
Enter exponent (n): 5
2^5 = 32
```

```
Enter base (x): 2
Enter exponent (n): -3
2^-3 = 0.125
```
