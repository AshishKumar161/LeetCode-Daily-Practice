# 678. Valid Parenthesis String

**Difficulty:** Medium  
**Topics:** String, Dynamic Programming, Stack, Greedy  
**Companies:** Amazon, Facebook, Google, Bloomberg, Microsoft  

---

### Problem Statement

Given a string `s` containing only three types of characters: `'('`, `')'`, and `'*'`, return `true` if `s` is **valid**.

The following rules define a **valid** string:
1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

---

### Example 1:
```text
Input: s = "()"
Output: true
```

### Example 2:
```text
Input: s = "(*)"
Output: true
```

### Example 3:
```text
Input: s = "(*))"
Output: true
```

---

### Constraints:
- $1 \le \text{s.length} \le 100$
- `s[i]` is `'('`, `')'` or `'*'`.