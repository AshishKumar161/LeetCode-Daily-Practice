# LeetCode 344 — Reverse String: Explanation

## Your Code

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int second = n - 1;

        for (int i = 0; i < n / 2; i++)
        {
            char temp = s[i];

            s[i] = s[second];

            s[second] = temp;

            second--;
        }

        return;
    }
};
```

Your solution is correct and uses the **two-pointer technique**.

---

# 1. What Does the Problem Ask?

We need to reverse the array **in-place**.

For example:

```text
["h","e","l","l","o"]
```

should become:

```text
["o","l","l","e","h"]
```

The important requirement is:

```text
O(1) extra memory
```

So we should not create another array containing the reversed string.

---

# 2. Main Idea — Two Pointers

You use two positions:

```text
i       → starts from the left
second  → starts from the right
```

For:

```text
h e l l o
```

the positions are:

```text
0 1 2 3 4
↑       ↑
i     second
```

Swap the two characters.

Then move both pointers toward the center.

---

# 3. Initialize the Right Pointer

You write:

```cpp
int second = n - 1;
```

Array indices start from `0`.

Therefore, if:

```text
n = 5
```

the last index is:

```text
5 - 1 = 4
```

So:

```text
second = 4
```

---

# 4. Why `i < n / 2`?

Your loop is:

```cpp
for (int i = 0; i < n / 2; i++)
```

You only need to perform swaps until reaching the middle.

For:

```text
h e l l o
```

there are 5 characters.

You need these swaps:

```text
h ↔ o
e ↔ l
```

The middle character:

```text
l
```

doesn't need to move.

Therefore, you only need approximately half the array.

---

# 5. Swapping the Characters

You use:

```cpp
char temp = s[i];

s[i] = s[second];

s[second] = temp;
```

This is the standard swap technique.

Suppose:

```text
s[i] = 'h'
s[second] = 'o'
```

First:

```cpp
char temp = s[i];
```

Now:

```text
temp = 'h'
```

Then:

```cpp
s[i] = s[second];
```

Now:

```text
s[i] = 'o'
```

Finally:

```cpp
s[second] = temp;
```

Now:

```text
s[second] = 'h'
```

So:

```text
h e l l o
```

becomes:

```text
o e l l h
```

---

# 6. Move the Right Pointer

After the swap:

```cpp
second--;
```

The right pointer moves one position toward the center.

So:

```text
Before:

i           second
↓              ↓
h e l l o

After:

  i       second
  ↓          ↓
o e l l h
```

Then the next iteration swaps:

```text
e ↔ l
```

---

# 7. Complete Dry Run

Input:

```text
["h","e","l","l","o"]
```

### Initial

```text
i = 0
second = 4
```

Array:

```text
h e l l o
↑       ↑
i     second
```

Swap:

```text
o e l l h
```

Then:

```text
second = 3
```

---

### Second iteration

```text
i = 1
second = 3
```

Array:

```text
o e l l h
  ↑   ↑
  i second
```

Swap:

```text
o l l e h
```

Then:

```text
second = 2
```

---

### Loop ends

For `n = 5`:

```text
n / 2 = 2
```

The loop has performed two swaps.

Final:

```text
["o","l","l","e","h"]
```

---

# 8. Why This Is In-Place

You don't create another vector.

You only create:

```cpp
int n;
int second;
char temp;
```

These are constant-size variables.

Therefore:

```text
Extra Space = O(1)
```

The original array itself is modified.

---

# 9. Complexity

Each element is involved in at most one swap.

Therefore:

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

This satisfies the problem's requirement.

---

# 10. Important Pattern

This problem teaches the **two-pointer reversal pattern**:

```cpp
int left = 0;
int right = n - 1;

while (left < right)
{
    swap(s[left], s[right]);

    left++;
    right--;
}
```

This pattern is extremely important in DSA.

You will see it in:

- Reverse String
- Reverse Array
- Palindrome problems
- Two Sum on sorted arrays
- Remove duplicates
- Partitioning problems
- Many sliding/two-pointer problems

---

# 11. One Small Observation About Your Code

You use:

```cpp
int second = n - 1;

for (int i = 0; i < n / 2; i++)
```

This is completely valid.

An alternative is to use two pointers explicitly:

```cpp
int left = 0;
int right = n - 1;

while (left < right)
{
    swap(s[left], s[right]);

    left++;
    right--;
}
```

Both approaches have:

```text
Time:  O(n)
Space: O(1)
```

Your current solution is accepted and correct.

---

# Final Algorithm

```text
1. Put one pointer at the first character.
2. Put another pointer at the last character.
3. Swap the two characters.
4. Move the left pointer right.
5. Move the right pointer left.
6. Stop when the pointers meet/cross.
```

## Core Pattern

```text
left →              ← right

swap(left, right)

left++              right--
```

Remember:

> When reversing an array/string in-place, think **two pointers moving toward the center**.
