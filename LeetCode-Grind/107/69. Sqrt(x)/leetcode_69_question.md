# 69. Sqrt(x)

**Difficulty:** Easy  
**Topics:** Math, Binary Search  
**Companies:** Amazon, Microsoft, Google, Meta, Bloomberg, Apple, LinkedIn  

---

### Problem Statement

Given a non-negative integer `x`, return *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be **non-negative** as well.

You **must not use** any built-in exponent function or operator.

- For example, do not use `pow(x, 0.5)` in C++ or `x ** 0.5` in Python.

---

### Example 1:
```text
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

### Example 2:
```text
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

---

### Constraints:
- $0 \le x \le 2^{31} - 1$