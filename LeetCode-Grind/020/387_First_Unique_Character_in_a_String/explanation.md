
# Approach

This problem asks us to find the **first character that appears exactly once** in the string.

There are two common approaches:

1. Brute Force
2. Hash Array (Optimal)

---

# Brute Force Approach

## Idea

For every character, count how many times it appears in the string.

If its frequency is 1, immediately return its index.

---

## Algorithm

For every character

- Compare it with every other character.
- Count its occurrences.
- If count becomes 1, return its index.

If no such character exists, return -1.

---

## Dry Run

Input

```
s = "leetcode"
```

### i = 0

Character = 'l'

Compare with every character

```
l == l ✔
l == e ✖
l == e ✖
l == t ✖
l == c ✖
l == o ✖
l == d ✖
l == e ✖
```

Count = 1

Return index = 0

---

Worst Case

```
s = "aabbccdd"
```

For every character we scan the entire string.

Time becomes

```
O(n²)
```

---

## Complexity

Time

```
O(n²)
```

Space

```
O(1)
```

---

# Optimal Approach (Hash Array)

Instead of counting every character repeatedly, we count frequencies only once.

Since the string contains only lowercase letters, we create an array of size 26.

```
index = character - 'a'
```

Example

```
'a' -> 0
'b' -> 1
...
'z' -> 25
```

---

## Step 1

Count frequency of every character.

```
for every character

hash[ch-'a']++
```

---

## Step 2

Traverse the string again.

The first character whose frequency is exactly 1 is the answer.

```
if(hash[ch-'a']==1)

return index
```

---

# Dry Run

Input

```
s = "loveleetcode"
```

---

### Frequency Table

```
l -> 2
o -> 2
v -> 1
e -> 4
t -> 1
c -> 1
d -> 1
```

Hash Array

```
a :0
b :0
c :1
d :1
e :4
...
l :2
o :2
t :1
v :1
```

---

Second Traversal

Index 0

```
l
frequency = 2
```

Skip

---

Index 1

```
o
frequency = 2
```

Skip

---

Index 2

```
v
frequency = 1
```

Return

```
2
```

---

# Why Two Loops?

First loop

Builds the frequency table.

Second loop

Finds the **first** unique character while preserving the original order.

If we only used the frequency table, we wouldn't know which unique character appeared first.

---

# Complexity

## Time

First loop

```
O(n)
```

Second loop

```
O(n)
```

Total

```
O(n)
```

---

## Space

Hash array size is fixed (26).

```
O(1)
```

---

# Comparison

| Approach    | Time   | Space |
| ----------- | ------ | ----- |
| Brute Force | O(n²) | O(1)  |
| Hash Array  | O(n)   | O(1)  |

---

# Key Learning

- Frequency counting is a common optimization technique.
- A fixed-size hash array is faster than nested loops.
- Use one pass to count frequencies and another pass to preserve the original order.
