# LeetCode 268: Missing Number

## Approach

Your solution uses an **`unordered_map`** to remember every number present in the array.

The key observation is:

```text
nums has n elements
possible values are 0 through n
```

Therefore there are `n + 1` possible values but only `n` values in the array, so exactly one value is missing.

The approach is:

```text
Store every existing number
        ↓
Check 0, 1, 2, ..., n-1
        ↓
If a number is absent → return it
        ↓
If none is absent → n is missing
```

---

## Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> hash;

        for (int i = 0; i < n; i++)
        {
            hash[nums[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (hash.find(i) == hash.end())
            {
                return i;
            }
        }

        return n;
    }
};
```

---

## Code Explanation

### 1. Find `n`

```cpp
int n = nums.size();
```

For:

```text
nums = [3,0,1]
```

we get:

```text
n = 3
```

Therefore the complete range is:

```text
[0,3]
```

---

### 2. Create the Hash Map

```cpp
unordered_map<int,int> hash;
```

The map stores:

```text
number → index
```

For:

```text
nums = [3,0,1]
```

the map becomes conceptually:

```text
3 → 0
0 → 1
1 → 2
```

The index is not actually needed. We mainly use the map to check whether a number exists.

---

## First Loop

```cpp
for (int i = 0; i < n; i++)
{
    hash[nums[i]] = i;
}
```

This inserts every number from `nums`.

For:

```text
nums = [3,0,1]
```

we store:

```text
hash[3] = 0
hash[0] = 1
hash[1] = 2
```

So the values present are:

```text
0, 1, 3
```

and:

```text
2
```

is absent.

---

## Second Loop

```cpp
for (int i = 0; i < n; i++)
{
    if (hash.find(i) == hash.end())
    {
        return i;
    }
}
```

We check:

```text
0 → n-1
```

For `n = 3`:

```text
0,1,2
```

### Understanding `find()`

```cpp
hash.find(i)
```

searches for `i`.

If it exists:

```cpp
hash.find(i) != hash.end()
```

If it does not exist:

```cpp
hash.find(i) == hash.end()
```

Therefore:

```cpp
if (hash.find(i) == hash.end())
```

means:

> `i` is not present, so `i` is the missing number.

---

## Dry Run

Input:

```text
nums = [3,0,1]
```

### Step 1

```text
n = 3
```

Possible numbers:

```text
0,1,2,3
```

### Step 2: Build Hash Map

Present values:

```text
3
0
1
```

### Step 3: Check the Range

Check `0`:

```text
found
```

Check `1`:

```text
found
```

Check `2`:

```text
not found
```

Therefore:

```cpp
return 2;
```

Final answer:

```text
2
```

---

## Why Do We Return `n`?

This is an important part of the solution.

The second loop checks only:

```cpp
i < n
```

so it checks:

```text
0,1,...,n-1
```

But the valid range is:

```text
[0,n]
```

Therefore `n` itself is also a possible missing number.

Example:

```text
nums = [0,1]
```

Here:

```text
n = 2
```

Range:

```text
0,1,2
```

The loop finds:

```text
0 → found
1 → found
```

No missing value is found.

Therefore the only missing value must be:

```text
n = 2
```

So:

```cpp
return n;
```

---

## Missing Number = 0

Example:

```text
nums = [1,2,3]
```

Here:

```text
n = 3
```

Range:

```text
0,1,2,3
```

`0` is absent.

The second loop starts with:

```text
i = 0
```

and immediately returns:

```text
0
```

---

## Missing Number = `n`

Example:

```text
nums = [0,1,2]
```

Here:

```text
n = 3
```

Range:

```text
0,1,2,3
```

The loop checks:

```text
0 → found
1 → found
2 → found
```

Then it finishes.

Therefore:

```cpp
return n;
```

returns:

```text
3
```

---

## Why Use a Hash Map?

The main question we need to answer is:

```text
Does this number exist in nums?
```

An `unordered_map` provides average:

```text
O(1)
```

lookup.

So we can:

```text
Store all values → O(n)
Check all required values → O(n) average
```

---

## Important Note About Your Map

Your code uses:

```cpp
unordered_map<int,int> hash;
```

and:

```cpp
hash[nums[i]] = i;
```

The index is not actually required.

A simpler structure for only checking presence would be:

```cpp
unordered_set<int> hash;
```

with:

```cpp
hash.insert(nums[i]);
```

Then the same `find()` check can be used.

However, **your submitted `unordered_map` solution is correct**.

---

## Brute Force Approach

A straightforward method is to check every number in `[0,n]` against the whole array.

That can require:

```text
O(n²)
```

time.

For example:

```cpp
for(int i = 0; i <= n; i++)
{
    bool found = false;

    for(int j = 0; j < n; j++)
    {
        if(nums[j] == i)
        {
            found = true;
            break;
        }
    }

    if(!found)
        return i;
}
```

The hash-map solution avoids repeatedly scanning the array.

---

## Complexity Analysis

### Time Complexity

First loop:

```text
O(n)
```

Second loop:

```text
O(n) average
```

Therefore:

```text
O(n) average
```

overall.

### Space Complexity

The hash map can store up to `n` values:

```text
O(n)
```

So your solution uses:

```text
Time:  O(n) average
Space: O(n)
```

---

## Edge Cases

### Single Element

```text
nums = [0]
```

Range:

```text
[0,1]
```

Output:

```text
1
```

### Missing Zero

```text
nums = [1,2,3]
```

Output:

```text
0
```

### Missing `n`

```text
nums = [0,1,2]
```

Output:

```text
3
```

### Missing in the Middle

```text
nums = [0,1,3]
```

Output:

```text
2
```

---

## Key Learning

This problem teaches the **Hashing + Presence Check** pattern.

Whenever you have:

```text
Known range of values
+
One value is missing
```

a straightforward approach is:

```text
Store existing values
        ↓
Check expected values
        ↓
Return the absent value
```

---

## Pattern to Remember

```cpp
unordered_map<int,int> hash;

for(int i = 0; i < n; i++)
{
    hash[nums[i]] = i;
}

for(int i = 0; i < n; i++)
{
    if(hash.find(i) == hash.end())
    {
        return i;
    }
}

return n;
```

Think:

```text
First loop  → remember what exists
Second loop → find what is missing
Final return → n is missing
```

---

## Alternative Solutions

There are also `O(1)` extra-space solutions using:

* Mathematical sum
* XOR

But your current solution is useful for understanding hash-table membership checks.

---

## Final Complexity

| Approach | Time | Extra Space |
| -------- | ---- | ----------- |
| Brute Force | `O(n²)` | `O(1)` |
| Hash Map | `O(n)` average | `O(n)` |
| XOR | `O(n)` | `O(1)` |
| Math Sum | `O(n)` | `O(1)` |

For **your submitted solution**:

```text
Time:  O(n) average
Space: O(n)
```
