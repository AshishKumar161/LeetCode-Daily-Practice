# 1614. Maximum Nesting Depth of the Parentheses

**Difficulty:** Easy  
**Topics:** String, Stack  
**Companies:** Facebook, Amazon, Google, Bloomberg  

---

### Problem Statement

Given a **valid parentheses string (VPS)** `s`, return the *nesting depth* of `s`. The nesting depth is the maximum number of nested parentheses.

A string is a **valid parentheses string** (denoted **VPS**) if it meets one of the following:
- It is an empty string `""`, or a single character not equal to `'('` or `')'`,
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are **VPS**'s, or
- It can be written as `(A)`, where `A` is a **VPS**.

We can similarly define the **nesting depth** `depth(S)` of any VPS `S` as follows:
- `depth("") = 0`
- `depth(C) = 0`, where `C` is a string with a single character not equal to `'('` or `')'`.
- `depth(A + B) = max(depth(A), depth(B))`, where `A` and `B` are **VPS**'s.
- `depth("(" + A + ")") = 1 + depth(A)`, where `A` is a **VPS**.

---

### Example 1:
```text
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.
```

### Example 2:
```text
Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation: Digit 3 is inside of 3 nested parentheses in the string.
```

### Example 3:
```text
Input: s = "()(())((()))"
Output: 3
```

---

### Constraints:
- $1 \le \text{s.length} \le 100$
- `s` consists of digits `0-9` and characters `'+'`, `'-'`, `'*'`, `'/'`, `'('`, and `')'`.
- It is guaranteed that parentheses expression `s` is a **valid parentheses string**.