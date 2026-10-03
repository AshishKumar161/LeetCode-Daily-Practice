# Armstrong Number — Check if the Number is Armstrong

## Problem

Given an integer `n`, check whether it is an Armstrong number.

Return:

- `true` if `n` is an Armstrong number.
- `false` otherwise.

An Armstrong number is a number that is equal to the sum of its digits, where every digit is raised to the power of the total number of digits.

## Examples

### Example 1

```text
Input: n = 153
Output: true
```

Because:

```text
1³ + 5³ + 3³
= 1 + 125 + 27
= 153
```

### Example 2

```text
Input: n = 12
Output: false
```

Because:

```text
1² + 2²
= 1 + 4
= 5
```

and:

```text
5 != 12
```

### Example 3

```text
Input: n = 370
Output: true
```

Because:

```text
3³ + 7³ + 0³
= 27 + 343 + 0
= 370
```
