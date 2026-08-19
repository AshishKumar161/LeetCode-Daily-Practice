
# 7. Reverse Integer

# Intuition

We need to reverse the digits of a 32-bit signed integer.

Instead of converting the integer into a string, we repeatedly extract the last digit using `% 10`, append it to the reversed number, and remove the last digit using `/ 10`.

Since the reversed number may exceed the 32-bit integer range, we must check for overflow before updating the result.

---

# Approach

1. Initialize `reverse = 0`.
2. Repeat until `x` becomes 0.
3. Extract the last digit using `% 10`.
4. Remove the last digit using `/= 10`.
5. Check whether adding the digit will cause overflow.
6. If overflow occurs, return `0`.
7. Otherwise, append the digit to `reverse`.
8. Return the reversed number.

---

# Dry Run

## Input

```
x = 123
```

Initial State

```
reverse = 0
```

---

### Iteration 1

```
digit = 123 % 10 = 3

x = 123 / 10

= 12

reverse = 0 × 10 + 3

= 3
```

Current State

```
reverse = 3

x = 12
```

---

### Iteration 2

```
digit = 12 % 10 = 2

x = 12 / 10

= 1

reverse = 3 × 10 + 2

= 32
```

Current State

```
reverse = 32

x = 1
```

---

### Iteration 3

```
digit = 1 % 10 = 1

x = 1 / 10

= 0

reverse = 32 × 10 + 1

= 321
```

Loop Ends.

Return

```
321
```

---

# Overflow Check

Suppose

```
reverse = 214748365

digit = 9
```

If we calculate

```
reverse = reverse × 10 + digit
```

The answer becomes larger than

```
2147483647
```

which is outside the range of a signed 32-bit integer.

Therefore, before multiplying by 10, we check

```cpp
if(reverse > INT_MAX / 10)
```

Similarly for negative numbers,

```cpp
if(reverse < INT_MIN / 10)
```

If overflow is possible, return

```
0
```

---

# Algorithm

```
Initialize reverse = 0

While x is not zero

    Extract last digit

    Remove last digit

    Check overflow

    Append digit to reverse

Return reverse
```

---

# Code Explanation

```cpp
int reverse = 0;
```

Stores the reversed number.

---

```cpp
while(x != 0)
```

Loop until every digit is processed.

---

```cpp
int digit = x % 10;
```

Extract the last digit.

Example

```
123

↓

3
```

---

```cpp
x /= 10;
```

Remove the last digit.

Example

```
123

↓

12
```

---

```cpp
if(reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && digit > 7))
```

Checks whether adding another digit would exceed

```
2147483647
```

Return

```
0
```

---

```cpp
if(reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && digit < -8))
```

Checks negative overflow.

Return

```
0
```

---

```cpp
reverse = reverse * 10 + digit;
```

Append the digit.

Example

```
reverse = 45

digit = 6

New reverse

456
```

---

```cpp
return reverse;
```

Return the final reversed integer.

---

# Time Complexity

Each digit is processed once.

```
Time Complexity

O(log₁₀ n)
```

---

# Space Complexity

Only constant extra memory is used.

```
Space Complexity

O(1)
```

---

# Complexity Summary

| Operation      | Complexity |
| -------------- | ---------- |
| Reverse Digits | O(log n)   |
| Extra Space    | O(1)       |

---

# Key Learning

- Extract digits using `% 10`.
- Remove digits using `/ 10`.
- Build the reversed number mathematically.
- Always check integer overflow before multiplying by 10.
- No string conversion is required.
