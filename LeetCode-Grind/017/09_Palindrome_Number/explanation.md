
# 9. Palindrome Number

# Intuition

A palindrome number looks exactly the same from both directions.

Instead of converting the number into a string, we can reverse the digits mathematically and compare the reversed number with the original number.

This uses constant extra space.

---

# Approach

1. Store the original number.
2. If the number is negative, return false.
3. Reverse the digits one by one.
4. Compare the reversed number with the original number.
5. Return the result.

---

# Dry Run

Input

```
121
```

Initial

```
original = 121

reverse = 0

x = 121
```

---

Iteration 1

Last Digit

```
121 % 10 = 1
```

Reverse

```
0 × 10 + 1

= 1
```

Remove last digit

```
121 / 10

= 12
```

Current

```
reverse = 1

x = 12
```

---

Iteration 2

Last Digit

```
12 % 10 = 2
```

Reverse

```
1 × 10 + 2

= 12
```

Remove digit

```
12 / 10

= 1
```

Current

```
reverse = 12

x = 1
```

---

Iteration 3

Last Digit

```
1 % 10 = 1
```

Reverse

```
12 × 10 + 1

= 121
```

Remove digit

```
1 / 10

= 0
```

Loop Ends

Compare

```
reverse = 121

original = 121
```

Return

```
true
```

---

# Algorithm

```
Store original number

If number is negative

    Return false

While number is not zero

    Extract last digit

    Add digit to reversed number

    Remove last digit

Compare reversed number with original number

Return result
```

---

# Code Explanation

```cpp
double reverse = 0;
```

Stores the reversed number.

---

```cpp
int original = x;
```

Stores the original value.

---

```cpp
if(x < 0)
{
    return false;
}
```

Negative numbers are never palindrome numbers.

---

```cpp
while(x != 0)
```

Loop until every digit is processed.

---

```cpp
reverse = (reverse * 10) + x % 10;
```

Extract the last digit.

Append it to the reversed number.

Example

```
reverse = 45

digit = 6

New Reverse

456
```

---

```cpp
x /= 10;
```

Remove the last digit.

Example

```
4567

↓

456
```

---

```cpp
return reverse == original;
```

If both numbers are equal, return true.

Otherwise return false.

---

# Complexity Analysis

## Time Complexity

Every digit is visited once.

```
O(log10 n)
```

---

## Space Complexity

Only a few variables are used.

```
O(1)
```

---

# Complexity Summary

| Operation      | Complexity |
| -------------- | ---------- |
| Reverse Number | O(log n)   |
| Extra Space    | O(1)       |

---

# Key Points

- No string conversion.
- Uses mathematical operations only.
- Constant extra memory.
- Faster than string comparison.
- Common interview solution.
