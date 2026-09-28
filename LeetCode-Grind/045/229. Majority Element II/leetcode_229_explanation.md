# LeetCode 229: Majority Element II

## Approach Used in Your Code

Your solution uses a **Hash Map / Frequency Counting** approach.

The idea is simple:

```text
Array
  ↓
Count frequency of every element
  ↓
Check which frequencies are > n/3
  ↓
Store qualifying elements
```

---

# Your Code

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> hash;

        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }

        vector<int> ans;

        for (auto x : hash)
        {
            if (x.second > n / 3)
            {
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};
```

---

# Step 1: Get Array Size

```cpp
int n = nums.size();
```

`n` stores the number of elements.

For:

```text
nums = [3,2,3]
```

we have:

```text
n = 3
```

---

# Step 2: Create a Hash Map

```cpp
unordered_map<int, int> hash;
```

The map stores:

```text
element → frequency
```

For example:

```text
nums = [3,2,3,1,3,2]
```

the hash map becomes approximately:

```text
3 → 3
2 → 2
1 → 1
```

The order inside an `unordered_map` is not guaranteed.

---

# Step 3: Count Frequencies

Your loop:

```cpp
for (int i = 0; i < n; i++)
{
    hash[nums[i]]++;
}
```

does the frequency counting.

For:

```text
nums = [3,2,3]
```

initially:

```text
hash = {}
```

Read `3`:

```text
3 → 1
```

Read `2`:

```text
3 → 1
2 → 1
```

Read `3` again:

```text
3 → 2
2 → 1
```

Final:

```text
3 → 2
2 → 1
```

---

# Step 4: Check the Majority Condition

The problem asks for elements appearing more than:

```text
n / 3
```

times.

Your code checks:

```cpp
if (x.second > n / 3)
```

Here:

```text
x.first  = element
x.second = frequency
```

For:

```text
nums = [3,2,3]
n = 3
```

we calculate:

```text
n / 3 = 1
```

For element `3`:

```text
frequency = 2

2 > 1 ✓
```

So `3` is added.

For element `2`:

```text
frequency = 1

1 > 1 ✗
```

So `2` is not added.

Result:

```text
[3]
```

---

# Why Is the Condition `>` and Not `>=`?

The problem says:

```text
more than n/3
```

So we need:

```text
frequency > n/3
```

not:

```text
frequency >= n/3
```

For example:

```text
n = 6
```

Then:

```text
n/3 = 2
```

An element appearing exactly `2` times does **not** qualify.

It must appear:

```text
3 or more times
```

because:

```text
3 > 2
```

---

# Why Can There Be At Most Two Answers?

This is an important mathematical observation.

Suppose three different elements each appeared more than:

```text
n/3
```

times.

Then together they would appear more than:

```text
n/3 + n/3 + n/3
```

which is:

```text
n
```

That is impossible because the array contains exactly `n` elements.

Therefore:

```text
Maximum number of majority elements = 2
```

This is why the answer contains at most two elements.

---

# Example: Two Answers

Consider:

```text
nums = [1,2,1,2,1,2]
```

Here:

```text
n = 6
n/3 = 2
```

Frequencies:

```text
1 → 3
2 → 3
```

Check:

```text
3 > 2 ✓
3 > 2 ✓
```

Therefore:

```text
answer = [1,2]
```

---

# Example: One Answer

```text
nums = [1,1,1,2,3,4]
```

Here:

```text
n = 6
n/3 = 2
```

Frequencies:

```text
1 → 3
2 → 1
3 → 1
4 → 1
```

Only:

```text
1 → 3
```

satisfies:

```text
3 > 2
```

Therefore:

```text
answer = [1]
```

---

# Example: No Answer

Consider:

```text
nums = [1,2,3,4,5,6]
```

Here:

```text
n = 6
n/3 = 2
```

Every element occurs once:

```text
1 → 1
2 → 1
3 → 1
4 → 1
5 → 1
6 → 1
```

None satisfies:

```text
frequency > 2
```

Therefore:

```text
answer = []
```

---

# What Does `auto x : hash` Mean?

Your code:

```cpp
for (auto x : hash)
```

iterates over every key-value pair in the hash map.

Each `x` is approximately:

```text
pair<int, int>
```

where:

```text
x.first  → key / element
x.second → frequency
```

For example:

```text
3 → 5
```

means:

```cpp
x.first  = 3
x.second = 5
```

Therefore:

```cpp
ans.push_back(x.first);
```

adds the element to the answer.

---

# Why `unordered_map`?

You need to count the frequency of every value.

An `unordered_map` provides average:

```text
O(1)
```

insertion and lookup.

So:

```cpp
hash[nums[i]]++;
```

is efficient.

---

# Complexity Analysis

There are two loops.

## First Loop

```cpp
for (int i = 0; i < n; i++)
```

Each element is processed once.

Average:

```text
O(n)
```

## Second Loop

It iterates through the distinct elements.

In the worst case there can be `n` distinct elements:

```text
O(n)
```

Therefore total average time:

```text
O(n) + O(n)
= O(n)
```

---

# Space Complexity

The hash map can contain up to `n` distinct elements.

Therefore:

```text
O(n)
```

space is required.

The answer itself can contain at most two elements, so its additional output size is:

```text
O(1)
```

But the main auxiliary data structure is the hash map:

```text
O(n)
```

---

# Complexity Summary

| Operation | Complexity |
|---|---:|
| Frequency counting | `O(n)` average |
| Checking frequencies | `O(n)` worst case |
| Total Time | `O(n)` average |
| Hash Map Space | `O(n)` |
| Answer Size | `O(1)` |

---

# Important Note: There Is an O(1) Space Approach

Your current solution is completely valid, but LeetCode 229 can also be solved using the **Boyer-Moore Voting Algorithm with two candidates**.

Because:

```text
There can be at most 2 elements appearing > n/3 times
```

we can maintain:

```text
candidate1
candidate2
count1
count2
```

and reduce auxiliary space to:

```text
O(1)
```

That is a more advanced version of this problem.

Your current solution is easier to understand because it directly follows the frequency definition.

---

# Hash Map Approach vs Boyer-Moore

| Approach | Time | Extra Space | Difficulty |
|---|---:|---:|---|
| Hash Map | `O(n)` average | `O(n)` | Easier |
| Boyer-Moore | `O(n)` | `O(1)` | More advanced |

Your current implementation uses:

```text
Hash Map
```

---

# Key Pattern to Remember

For frequency-based problems:

```text
1. Create frequency map
        ↓
2. Traverse array
        ↓
3. Increment frequency
        ↓
4. Traverse map
        ↓
5. Check required frequency condition
```

For this problem specifically:

```text
frequency > n/3
```

---

# Important Formula

For LeetCode 229:

```text
Majority condition:

count > n/3
```

And:

```text
Maximum possible answers = 2
```

because three elements each occurring more than `n/3` times would require more than `n` positions.

---

# Final Algorithm

```text
Input array
    ↓
Create unordered_map
    ↓
Count every element
    ↓
Calculate n/3
    ↓
Check every frequency
    ↓
If frequency > n/3
    ↓
Add element to answer
```

# Final Complexity

```text
Time Complexity:
O(n) average

Auxiliary Space:
O(n)
```

The key idea is simply:

```text
Count → Compare with n/3 → Store
```

Your implementation is a clean and straightforward frequency-counting solution for **LeetCode 229 - Majority Element II**.
