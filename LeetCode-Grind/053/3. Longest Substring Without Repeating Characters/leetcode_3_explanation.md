# LeetCode 3 — Longest Substring Without Repeating Characters

## Your Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int right = 0;
        int maxLength = 0;

        while (right < s.length()) {
            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            }

            mp[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
```

## Approach

This is a classic **Sliding Window + Hash Map** problem.

Maintain a window:

```text
[left ... right]
```

The window must contain no repeated characters.

The hash map stores:

```text
character -> latest index
```

For example:

```text
a -> 0
b -> 1
c -> 2
```

When `s[right]` already exists, move `left` after its previous occurrence:

```cpp
left = max(left, mp[s[right]] + 1);
```

### Why `+1`?

For:

```text
abcda
```

the second `a` is at index `4`, and the previous `a` is at index `0`.

So the new window must begin at:

```text
0 + 1 = 1
```

giving:

```text
bcda
```

### Why `max()`?

Consider:

```text
abba
```

After the second `b`, `left` is already `2`.

The final `a` was previously at index `0`. We must not move `left` backward to `1`.

Therefore:

```cpp
left = max(left, mp[s[right]] + 1);
```

guarantees that `left` only moves forward.

## Window Length

The current window contains:

```cpp
right - left + 1
```

characters.

Update the answer with:

```cpp
maxLength = max(maxLength, right - left + 1);
```

## Dry Run: `"abcabcbb"`

```text
a -> window "a"   -> 1
b -> window "ab"  -> 2
c -> window "abc" -> 3
```

Next `a` is a duplicate. Its previous index is `0`, so:

```text
left = 1
```

Window becomes:

```text
"bca"
```

Length remains `3`.

Next `b` causes:

```text
left = 2
```

Window:

```text
"cab"
```

Again length `3`.

The maximum answer is:

```text
3
```

## Complexity

Because both `left` and `right` only move forward:

```text
Time Complexity:  O(n)
Space Complexity: O(n)
```

## Pattern to Remember

```text
SLIDING WINDOW + HASH MAP
```

Important lines:

```cpp
left = max(left, mp[s[right]] + 1);
```

and:

```cpp
right - left + 1
```

### Final Algorithm

1. Create a hash map.
2. Set `left = 0`.
3. Move `right` through the string.
4. If the current character was seen, move `left` after its previous occurrence.
5. Store the character's latest index.
6. Calculate the current window length.
7. Update the maximum.
8. Return the maximum.
