# 58. Length of Last Word

**LeetCode:** [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/)  
**Difficulty:** Easy · **Topics:** String

## Problem Statement

Given a string `s` consisting of words and spaces, return the **length of the last word** in the string.

A **word** is a maximal substring consisting of non-space characters only.

## Examples

### Example 1
**Input:** `s = "Hello World"`  
**Output:** `5`  
**Explanation:** The last word is `"World"`, which has length `5`.

### Example 2
**Input:** `s = " fly me to the moon "`  
**Output:** `4`  
**Explanation:** The last word is `"moon"`, which has length `4`.

### Example 3
**Input:** `s = "luffy is still joyboy"`  
**Output:** `6`  
**Explanation:** The last word is `"joyboy"`, which has length `6`.

## Visual Representation

Example: `s = " fly me to the moon "`

```text
String: " fly me to the moon "
                       └───┘
                    Last word: moon
                    Length: 4
```

First ignore spaces at the end. Then count the non-space characters from right to left until reaching a space or the beginning of the string.

## Constraints
- `1 <= s.length <= 10^4`
- `s` consists of English letters and spaces.
- There is at least one word in `s`.

## Function Signature

```cpp
int lengthOfLastWord(string s);
```

See `leetcode_58_explanation.md` for the algorithm, dry runs, correctness reasoning, and complexity analysis.
