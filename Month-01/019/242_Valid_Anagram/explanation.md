
# 242. Valid Anagram

# Intuition

Two strings are anagrams if

- They contain exactly the same characters.
- Every character appears the same number of times.
- The order of characters does not matter.

Example

```
anagram

nagaram
```

Both contain

```
a → 3

n → 1

g → 1

r → 1

m → 1
```

Therefore,

```
True
```

---

# Brute Force Approach

Sort both strings.

If both sorted strings become equal,

return

```
true
```

Otherwise,

```
false
```

Example

```
anagram

↓

aaagmnr
```

```
nagaram

↓

aaagmnr
```

Both are equal.

---

## Time Complexity

```
O(n log n)
```

---

## Space Complexity

```
O(1)
```

---

# Optimized Approach (Hash Array)

Instead of sorting,

count the frequency of every character.

Since the strings contain only lowercase English letters,

we need only

```
26
```

integers.

Increase the frequency while reading string **s**.

Decrease the frequency while reading string **t**.

Finally,

if every frequency becomes zero,

both strings have exactly the same characters.

---

# Algorithm

```
If lengths are different

    Return false

Create frequency array of size 26

Traverse both strings together

Increase frequency for s

Decrease frequency for t

Traverse frequency array

If any value is not zero

    Return false

Else

Return true
```

---

# Dry Run

Input

```
s = "anagram"

t = "nagaram"
```

Initially

```
hash

[a...z]

0 0 0 0 0 ...
```

---

Iteration 1

```
s[0] = 'a'

hash['a']++

↓

a = 1
```

```
t[0] = 'n'

hash['n']--

↓

n = -1
```

---

Iteration 2

```
s[1] = 'n'

hash['n']++

↓

n = 0
```

```
t[1] = 'a'

hash['a']--

↓

a = 0
```

---

Continue for every character.

Finally

```
a = 0

b = 0

c = 0

...

z = 0
```

Every frequency is zero.

Return

```
true
```

---

Another Example

```
s = rat

t = car
```

Frequency becomes

```
a = 0

r = 1

c = -1

t = 1
```

Not all values are zero.

Return

```
false
```

---

# Code Explanation

```cpp
if(s.length() != t.length())
```

If lengths are different,

they can never be anagrams.

Return

```
false
```

---

```cpp
int hash[26] = {0};
```

Create a frequency array for

```
a → z
```

Initially

```
0 0 0 ... 0
```

---

```cpp
hash[s[i]-'a']++;
```

Increase the count of the current character from string **s**.

Example

```
s = apple

'a'

hash[0]++

1
```

---

```cpp
hash[t[i]-'a']--;
```

Decrease the count of the current character from string **t**.

If both strings contain the same characters,

all counts will cancel each other.

---

```cpp
for(int i=0;i<26;i++)
```

Check every frequency.

---

```cpp
if(hash[i]!=0)
```

A non-zero frequency means one string contains extra or fewer characters.

Return

```
false
```

---

```cpp
return true;
```

Every frequency became zero.

Hence,

both strings are valid anagrams.

---

# Time Complexity

Traversing the strings

```
O(n)
```

Traversing frequency array

```
O(26)
```

Overall

```
O(n)
```

---

# Space Complexity

Frequency array contains only

```
26
```

integers.

```
O(1)
```

---

# Complexity Summary

| Operation | Complexity |
| --------- | ---------- |
| Time      | O(n)       |
| Space     | O(1)       |

---

# Key Learning

- Hashing is faster than sorting for frequency problems.
- A fixed-size frequency array is enough for lowercase English letters.
- Increase count for one string and decrease for the other.
- If every frequency becomes zero, the strings are anagrams.
- This is the optimal solution for lowercase English letters.
