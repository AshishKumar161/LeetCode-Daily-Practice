
# 9. Palindrome Number

**Difficulty:** Easy

## Problem Statement

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

A palindrome number reads the same forward and backward.

---

## Example 1

Input

```
x = 121
```

Output

```
true
```

Explanation

```
121
↓
121
```

The number reads the same from both directions.

---

## Example 2

Input

```
x = -121
```

Output

```
false
```

Explanation

Reading from left to right

```
-121
```

Reading from right to left

```
121-
```

They are not the same.

---

## Example 3

Input

```
x = 10
```

Output

```
false
```

Explanation

```
10
```

Reverse becomes

```
01
```

which is

```
1
```

Hence it is not a palindrome.

---

## Constraints

```
-2^31 <= x <= 2^31 - 1
```

---

## Follow Up

Can you solve it without converting the integer to a string?

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        double reverse = 0 ;
        int orignal = x ;
        if(x < 0)
        {
            return false ;
        }
        while(x != 0)
        {
            reverse = (reverse * 10) + x % 10 ;
            x /= 10 ;
        }


        // if(reverse == orignal)
        // {
        //     return true ;
        // }
        // else
        // {
        //     return false ;
        // }

        return reverse == orignal ;
    }
};
```
