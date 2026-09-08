# LeetCode 2486: Append Characters to String to Make Subsequence

## Approach

We solve this problem using the **Two Pointer** technique.

We use two pointers:

```cpp
int first = 0;
int second = 0;
```

Their purpose is:

```text
first  → current character in s
second → current character in t
```

We want to match as much of `t` as possible inside `s`.

While both pointers are inside their strings:

* If `s[first] == t[second]`, we successfully matched one character, so move both pointers.
* If they do not match, move only `first` because we can skip the current character of `s`.

When the loop finishes, `second` tells us how many characters of `t` have already been matched.

Therefore:

```cpp
t.size() - second
```

is the number of characters still missing from `t`.

Those remaining characters must be appended to the end of `s`.

---

## Intuition

Consider:

```text
s = "coaching"
t = "coding"
```

Write the strings as:

```text
s = c o a c h i n g
t = c o d i n g
```

We try to match `t` from left to right inside `s`.

### Match `c`

```text
s[0] = c
t[0] = c
```

Match:

```text
first++
second++
```

Now:

```text
first = 1
second = 1
```

### Match `o`

```text
s[1] = o
t[1] = o
```

Match again:

```text
first = 2
second = 2
```

Now we need:

```text
d
```

### Search for `d`

Current:

```text
s[2] = a
t[2] = d
```

No match.

Move only `first`.

```text
first = 3
second = 2
```

Continue:

```text
c → no
h → no
i → no
n → no
g → no
```

There is no `d` in the remaining part of `s`.

The loop ends with:

```text
second = 2
```

`t` has length:

```text
6
```

So remaining characters are:

```text
6 - 2 = 4
```

Those characters are:

```text
d i n g
```

Therefore the answer is:

```text
4
```

---

## Key Idea

We do **not** need to actually append the characters.

We only need to count how many characters of `t` are not matched.

If:

```text
matched = second
```

then:

```text
remaining = t.size() - second
```

So the answer is:

```cpp
return t.size() - second;
```

---

## Algorithm

1. Initialize:
   ```cpp
   int first = 0;
   int second = 0;
   ```

2. Traverse both strings while both pointers are valid:
   ```cpp
   while(first < s.size() && second < t.size())
   ```

3. If the characters match:
   ```cpp
   first++;
   second++;
   ```

4. If they do not match:
   ```cpp
   first++;
   ```

5. After the loop, `second` is the number of characters from `t` already matched.

6. Return:
   ```cpp
   t.size() - second;
   ```

---

## Dry Run

Consider:

```text
s = "coaching"
t = "coding"
```

Initially:

```text
first = 0
second = 0
```

---

### Step 1

```text
s[first] = s[0] = 'c'
t[second] = t[0] = 'c'
```

Match.

```text
first = 1
second = 1
```

Matched:

```text
"c"
```

---

### Step 2

```text
s[1] = 'o'
t[1] = 'o'
```

Match.

```text
first = 2
second = 2
```

Matched:

```text
"co"
```

---

### Step 3

```text
s[2] = 'a'
t[2] = 'd'
```

No match.

We still need `d`, so do not move `second`.

```text
first = 3
second = 2
```

---

### Step 4

```text
s[3] = 'c'
t[2] = 'd'
```

No match.

```text
first = 4
second = 2
```

---

### Step 5

```text
s[4] = 'h'
t[2] = 'd'
```

No match.

```text
first = 5
second = 2
```

---

### Step 6

```text
s[5] = 'i'
t[2] = 'd'
```

No match.

```text
first = 6
second = 2
```

---

### Step 7

```text
s[6] = 'n'
t[2] = 'd'
```

No match.

```text
first = 7
second = 2
```

---

### Step 8

```text
s[7] = 'g'
t[2] = 'd'
```

No match.

```text
first = 8
second = 2
```

Now:

```text
first == s.size()
```

The loop ends.

---

### Calculate Remaining Characters

`t` is:

```text
c o d i n g
```

Length:

```text
6
```

Matched:

```text
2
```

Remaining:

```text
6 - 2 = 4
```

The remaining suffix is:

```text
d i n g
```

Therefore:

```text
return 4
```

---

## Code

```cpp
class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0;
        int second = 0;

        while(first < s.size() && second < t.size())
        {
            if(s[first] == t[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        return t.size() - second;
    }
};
```

---

## Code Explanation

### Create Two Pointers

```cpp
int first = 0;
int second = 0;
```

`first` points to the current character in `s`.

```text
s → first
```

`second` points to the current character in `t`.

```text
t → second
```

---

### While Loop

```cpp
while(first < s.size() && second < t.size())
```

We continue while:

```text
first is inside s
AND
second is inside t
```

We need both conditions because we cannot compare characters after reaching the end of either string.

---

### Compare Characters

```cpp
if(s[first] == t[second])
```

We check whether the current character of `s` can match the current required character of `t`.

---

### When Characters Match

```cpp
first++;
second++;
```

A match means one character of `t` has successfully been found in `s`.

Therefore:

```text
second++
```

moves to the next required character of `t`.

And:

```text
first++
```

moves forward in `s`.

---

### When Characters Do Not Match

```cpp
else
{
    first++;
}
```

This is the important part.

Suppose:

```text
s[first] = 'a'
t[second] = 'd'
```

We cannot skip `d` because `d` is still required.

But we can skip `a` because `a` cannot be used to match `d`.

Therefore:

```text
first++ 
second stays
```

The rule is:

```text
Match    → move both
Mismatch → move only s
```

---

## Why Do We Move Only `first` on Mismatch?

Consider:

```text
s = "abc"
t = "ac"
```

Initially:

```text
a matches a
```

Now:

```text
first = 1
second = 1
```

We need:

```text
c
```

Current:

```text
s[first] = b
t[second] = c
```

They do not match.

If we moved `second`, we would skip `c`, which is required.

Instead:

```text
first++
```

Now:

```text
s[first] = c
t[second] = c
```

They match.

So:

```text
first++
second++
```

All characters of `t` are matched.

Answer:

```text
0
```

---

## Why Is `t.size() - second` the Answer?

Suppose:

```text
t = "coding"
```

and we successfully matched:

```text
"co"
```

Then:

```text
second = 2
```

`t` contains:

```text
6 characters
```

So the number of characters not matched is:

```text
6 - 2 = 4
```

Those remaining characters are:

```text
"ding"
```

Because they are appended to the **end** of `s`, they form the remaining suffix of `t`.

Therefore:

```cpp
return t.size() - second;
```

---

## Important Observation

The characters of `t` that are matched form a **prefix** of `t`.

For:

```text
t = "coding"
```

if we match:

```text
c → o
```

then we have matched:

```text
"co"
```

We cannot skip a required character in `t`.

So the unmatched portion is always:

```text
t[second ... end]
```

Its length is:

```text
t.size() - second
```

---

## Another Dry Run - Complete Match

Consider:

```text
s = "abcde"
t = "ace"
```

Initially:

```text
first = 0
second = 0
```

### `a`

```text
a == a
```

Move both:

```text
first = 1
second = 1
```

### `b`

```text
b != c
```

Move only `first`:

```text
first = 2
second = 1
```

### `c`

```text
c == c
```

Move both:

```text
first = 3
second = 2
```

### `d`

```text
d != e
```

Move only `first`:

```text
first = 4
second = 2
```

### `e`

```text
e == e
```

Move both:

```text
first = 5
second = 3
```

Now:

```text
second == t.size()
```

All characters are matched.

Therefore:

```text
t.size() - second
= 3 - 3
= 0
```

Answer:

```text
0
```

No characters need to be appended.

---

## Another Dry Run - No Match

Consider:

```text
s = "z"
t = "abcde"
```

Initially:

```text
first = 0
second = 0
```

Compare:

```text
z vs a → mismatch
```

Move:

```text
first = 1
second = 0
```

Now `s` is finished.

So:

```text
matched = second = 0
```

`t` has length:

```text
5
```

Therefore:

```text
5 - 0 = 5
```

Answer:

```text
5
```

All five characters must be appended.

---

## Greedy Idea

This solution is also **greedy**.

When the current character of `s` matches the current character of `t`, we immediately use that match.

Why?

Because using the earliest possible matching character leaves the maximum amount of `s` available for matching the remaining characters of `t`.

Therefore:

```text
Take the earliest possible match.
```

This is optimal.

---

## Why We Don't Actually Append Characters

The problem asks for:

```text
minimum number of characters
```

It does not ask us to construct the final string.

So there is no need to create:

```text
s + remaining characters
```

We only calculate how many characters remain unmatched.

This saves memory.

---

## Connection With LeetCode 392

This problem is closely related to **Is Subsequence**.

In both problems we use two pointers.

### LeetCode 392

Question:

```text
Is s a subsequence of t?
```

Pointer movement:

```text
Match     → move both
Mismatch  → move t
```

### LeetCode 2486

Question:

```text
How many characters of t are missing from s?
```

Pointer movement:

```text
Match     → move both
Mismatch  → move s
```

The difference comes from which string we are searching through.

Here:

```text
s = existing string
t = required subsequence
```

---

## Complexity Analysis

### Time Complexity

```text
O(s.length + t.length)
```

Each pointer only moves forward.

`first` moves at most `s.length` times.

`second` moves at most `t.length` times.

Therefore the total is:

```text
O(s.length + t.length)
```

---

### Space Complexity

```text
O(1)
```

Only two integer variables are used:

```text
first
second
```

No additional array, map, set, or string is created.

---

## Edge Cases

### 1. `t` Already a Subsequence

```text
s = "abcde"
t = "ace"
```

All characters match.

Output:

```text
0
```

---

### 2. No Character Matches

```text
s = "z"
t = "abcde"
```

Output:

```text
5
```

---

### 3. Only Some Characters Match

```text
s = "coaching"
t = "coding"
```

Matched:

```text
"co"
```

Remaining:

```text
"ding"
```

Output:

```text
4
```

---

### 4. `s` Is Longer

```text
s = "abcxyz"
t = "abc"
```

`t` is already a subsequence.

Output:

```text
0
```

---

### 5. Repeated Characters

```text
s = "aaaa"
t = "aaaab"
```

Four `a`s can be matched.

The final `b` is missing.

Output:

```text
1
```

---

## Key Learning

This problem teaches an important **Two Pointer + Greedy + Remaining Count** pattern.

When one string must become a subsequence of another by appending characters:

```text
Match as much as possible first.
Then count what remains.
```

The pattern is:

```text
Match → move both
Mismatch → move existing-string pointer
Answer → required length - matched length
```

---

## Pattern to Remember

```cpp
int first = 0;
int second = 0;

while(first < s.size() && second < t.size())
{
    if(s[first] == t[second])
    {
        first++;
        second++;
    }
    else
    {
        first++;
    }
}

return t.size() - second;
```

Think:

```text
s = what I already have
t = what I need
```

Then:

```text
Try to match t inside s
↓
Count matched characters
↓
Remaining t characters must be appended
```

---

## Core Logic

The entire problem can be reduced to:

```text
Find the longest prefix of t that is a subsequence of s.
```

If:

```text
t length = 6
matched prefix length = 2
```

then:

```text
characters needed = 6 - 2 = 4
```

Therefore:

```cpp
return t.size() - second;
```

---

## Final Complexity

| Metric | Complexity |
| ------ | ---------- |
| Time | `O(s.length + t.length)` |
| Extra Space | `O(1)` |

### Best Approach

```text
Two Pointers + Greedy Matching
```

This gives:

```text
O(s.length + t.length) time
O(1) extra space
```
