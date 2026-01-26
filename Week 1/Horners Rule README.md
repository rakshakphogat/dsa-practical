# Horner's Rule

## Description

This program evaluates a polynomial at a given value of x using Horner's Rule. Horner's Rule is an efficient method for polynomial evaluation that minimizes the number of multiplications.

## Algorithm

For a polynomial P(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ:

1. Start with result = aₙ
2. For i from n-1 down to 0:
   - result = result \* x + aᵢ
3. Return result

This transforms the polynomial into: P(x) = a₀ + x(a₁ + x(a₂ + ... + x(aₙ₋₁ + xaₙ)...))

## Functions

- `hornersRule(double coefficients[], int n, double x)`: Evaluates polynomial using Horner's Rule

## Input

- Degree of polynomial (n): integer
- Coefficients from a₀ to aₙ: array of doubles
- Value of x: double

## Output

- Result of polynomial evaluation at x

## Time Complexity

O(n) where n is the degree of the polynomial

## Space Complexity

O(n) for storing coefficients

## Example

```
Enter degree of polynomial: 3
Enter coefficients from a0 to a3:
2
3
4
5
Enter value of x: 2
Result: 100
```

This evaluates 2 + 3(2) + 4(2²) + 5(2³) = 2 + 6 + 16 + 40 = 64 + 36 = 100
