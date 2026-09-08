# LeetCode 2486 - Append Characters to String to Make Subsequence

## Question

You are given two strings `s` and `t` consisting of only lowercase English letters.

Return the **minimum number of characters** that need to be appended to the end of `s` so that `t` becomes a **subsequence** of `s`.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

---

## Example 1

**Input:**

```text
s = "coaching"
t = "coding"
```

**Output:**

```text
4
```

**Explanation:**

Append the characters:

```text
"ding"
```

to `s`.

Then:

```text
s = "coachingding"
```

Now `t = "coding"` is a subsequence of `s`.

It can be shown that appending only `3` characters is not enough.

---

## Example 2

**Input:**

```text
s = "abcde"
t = "a"
```

**Output:**

```text
0
```

`t` is already a subsequence of `s`.

---

## Example 3

**Input:**

```text
s = "z"
t = "abcde"
```

**Output:**

```text
5
```

None of the characters of `t` can be matched in `s`, so all `5` characters must be appended.

---

## Constraints

* `1 <= s.length, t.length <= 10^5`
* `s` and `t` consist only of lowercase English letters.

---

## Topics

* Two Pointers
* String
* Greedy
