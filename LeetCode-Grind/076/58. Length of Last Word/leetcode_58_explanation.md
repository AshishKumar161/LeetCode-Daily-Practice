# 58. Length of Last Word — Code Explanation

**LeetCode:** [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/)  
**Language:** C++

## Solution Code

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int count = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters in the last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};
```

## 1. Main Idea

We need the length of the last word, not the word itself. Scan from right to left in two phases:

1. Skip any spaces at the end of the string.
2. Count characters until a space or the beginning of the string is reached.

`i` is the current index, and `count` stores the length of the last word.

## 2. Line-by-Line Explanation

### Start from the final character
```cpp
int i = s.size() - 1;
int count = 0;
```
`i` points to the last character, and `count` starts at zero.

### Phase 1: Skip trailing spaces
```cpp
while (i >= 0 && s[i] == ' ') {
    i--;
}
```
Move left while the current character is a space. The `i >= 0` check prevents accessing an invalid index.

### Phase 2: Count the last word
```cpp
while (i >= 0 && s[i] != ' ') {
    count++;
    i--;
}
```
Every non-space character belongs to the last word, so increment `count` and move left. Stop at a space or the start of the string.

### Return the length
```cpp
return count;
```

## 3. Dry Run — Example 1

Input: `s = "Hello World"`

There are no trailing spaces, so the first loop does nothing.

| Character visited | Action | Count |
|---|---|---:|
| `d` | Count | 1 |
| `l` | Count | 2 |
| `r` | Count | 3 |
| `o` | Count | 4 |
| `W` | Count | 5 |
| Space | Stop | 5 |

**Output:** `5`

## 4. Dry Run — Example 2

Input: `s = " fly me to the moon "`

First skip the final space, then count the letters in `moon`.

| Character | Action | Count |
|---|---|---:|
| Final space | Skip | 0 |
| `n` | Count | 1 |
| `o` | Count | 2 |
| `o` | Count | 3 |
| `m` | Count | 4 |
| Space before `moon` | Stop | 4 |

**Output:** `4`

## 5. Dry Run — Example 3

Input: `s = "luffy is still joyboy"`

Starting from the right, count `y`, `o`, `b`, `y`, `o`, `j`. The space before `joyboy` stops the loop.

**Output:** `6`

## 6. Why the Algorithm Works

After skipping trailing spaces, `i` points to the last character of the final word. The second loop visits each character in that word exactly once and stops at its preceding space or the beginning of the string. Thus, `count` equals the last word's length.

## 7. Complexity Analysis

Let `n` be the string length.

- **Time complexity:** `O(n)` worst case — the algorithm may scan the entire string.
- **Auxiliary space:** `O(1)` — only two integer variables are used.

## 8. Common Mistakes

- Do not count trailing spaces.
- Check `i >= 0` before accessing `s[i]`.
- Stop counting when a space is reached.
- Return the count, not the last word itself.

## Summary

Skip trailing spaces, count non-space characters backward, and stop at the preceding space. The algorithm runs in `O(n)` time and `O(1)` auxiliary space.
