
# 387. First Unique Character in a String

## Problem Statement

Given a string `s`, find the first non-repeating character in it and return its index.

If it does not exist, return `-1`.

---

### Example 1

Input:

```
s = "leetcode"
```

Output:

```
0
```

Explanation:
The first character 'l' appears only once.

---

### Example 2

Input:

```
s = "loveleetcode"
```

Output:

```
2
```

Explanation:
'l' repeats later, 'o' repeats later.
'v' is the first character that appears exactly once.

---

### Example 3

Input:

```
s = "aabb"
```

Output:

```
-1
```

Explanation:
Every character repeats.

---

## Constraints

- 1 <= s.length <= 10^5
- s consists of only lowercase English letters.
