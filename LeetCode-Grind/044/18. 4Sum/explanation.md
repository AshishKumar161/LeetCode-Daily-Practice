# LeetCode 18: 4Sum

## Approach Used in Your Code

Your solution uses:

```text
Sorting + Two Fixed Elements + Two Pointers
```

This is an extension of your 3Sum approach.

### 3Sum

```text
Fix 1 element
+
2 pointers
```

### 4Sum

```text
Fix 2 elements
+
2 pointers
```

The structure is:

```text
i → fixed
j → fixed

first  → search
second → search
```

---

# Your Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (j > i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }

                int first = j + 1;
                int second = n - 1;

                while (first < second)
                {
                    int sum = nums[i] + nums[j] +
                              nums[first] + nums[second];

                    if (sum == target)
                    {
                        ans.push_back({
                            nums[i], nums[j],
                            nums[first], nums[second]
                        });

                        first++;
                        second--;

                        while (first < second &&
                               nums[first] == nums[first + 1])
                        {
                            first++;
                        }

                        while (first < second &&
                               nums[second] == nums[second - 1])
                        {
                            second--;
                        }
                    }
                    else if (sum < target)
                    {
                        first++;
                    }
                    else
                    {
                        second--;
                    }
                }
            }
        }

        return ans;
    }
};
```

---

# Step 1: Sort the Array

```cpp
sort(nums.begin(), nums.end());
```

Example:

```text
[1,0,-1,0,-2,2]
```

becomes:

```text
[-2,-1,0,0,1,2]
```

Sorting is what makes the two-pointer movement valid.

Because the array is sorted:

```text
first++   → value increases or stays equal
second--  → value decreases or stays equal
```

Therefore:

```text
sum < target → first++
sum > target → second--
```

---

# Step 2: Fix `i`

```cpp
for(int i = 0; i < n; i++)
```

`i` selects the first number.

Example:

```text
[-2,-1,0,0,1,2]
  ↑
  i
```

---

# Step 3: Skip Duplicate `i`

```cpp
if (i > 0 && nums[i] == nums[i-1])
{
    continue;
}
```

If the current value is the same as the previous value, using it again would produce the same quadruplets.

So:

```text
same nums[i] as previous
        ↓
      skip
```

---

# Step 4: Fix `j`

```cpp
for (int j = i + 1; j < n; j++)
```

Now we select the second number.

```text
[-2,-1,0,0,1,2]
  ↑  ↑
  i  j
```

After fixing `i` and `j`, only two numbers remain to be found.

---

# Step 5: Skip Duplicate `j`

```cpp
if (j > i+1 && nums[j] == nums[j-1])
{
    continue;
}
```

The condition `j > i + 1` is important.

The first possible `j`:

```text
j = i + 1
```

must be allowed.

After that, repeated values can be skipped.

---

# Step 6: Create Two Pointers

```cpp
int first = j + 1;
int second = n - 1;
```

Now:

```text
i < j < first < second
```

So all four indices are distinct.

---

# Step 7: Calculate the Sum

```cpp
int sum = nums[i] + nums[j] +
          nums[first] + nums[second];
```

There are three cases.

### `sum == target`

A valid quadruplet is found.

```cpp
ans.push_back({
    nums[i], nums[j],
    nums[first], nums[second]
});
```

### `sum < target`

The sum is too small.

Because the array is sorted:

```cpp
first++;
```

### `sum > target`

The sum is too large:

```cpp
second--;
```

---

# Complete Dry Run

Input:

```text
nums = [1,0,-1,0,-2,2]
target = 0
```

After sorting:

```text
[-2,-1,0,0,1,2]
```

## `i = 0`

```text
nums[i] = -2
```

Take:

```text
j = 1
nums[j] = -1
first = 2
second = 5
```

Calculate:

```text
-2 + (-1) + 0 + 2 = -1
```

Since:

```text
-1 < 0
```

move:

```text
first++
```

Now:

```text
first = 3
```

Again:

```text
-2 + (-1) + 0 + 2 = -1
```

Move `first`.

Now:

```text
first = 4
```

Calculate:

```text
-2 + (-1) + 1 + 2 = 0
```

Found:

```text
[-2,-1,1,2]
```

---

# After Finding a Quadruplet

Your code does:

```cpp
first++;
second--;
```

Then removes duplicate values:

```cpp
while (first < second &&
       nums[first] == nums[first + 1])
{
    first++;
}
```

and:

```cpp
while (first < second &&
       nums[second] == nums[second - 1])
{
    second--;
}
```

This prevents the same quadruplet from being generated again.

---

# Continue `i = 0`

Now choose:

```text
j = 2
nums[j] = 0
```

Then:

```text
first = 3
second = 5
```

Sum:

```text
-2 + 0 + 0 + 2 = 0
```

Found:

```text
[-2,0,0,2]
```

When `j` reaches the next `0`, this condition:

```cpp
if (j > i+1 && nums[j] == nums[j-1])
```

skips it.

---

# `i = 1`

Now:

```text
nums[i] = -1
```

One valid combination is:

```text
-1 + 0 + 0 + 1 = 0
```

So:

```text
[-1,0,0,1]
```

is added.

Final result:

```text
[
 [-2,-1,1,2],
 [-2,0,0,2],
 [-1,0,0,1]
]
```

---

# Example 2: All Values Are Equal

Input:

```text
[2,2,2,2,2]
target = 8
```

The first valid combination is:

```text
2 + 2 + 2 + 2 = 8
```

So:

```text
[2,2,2,2]
```

is stored.

The duplicate checks prevent the same quadruplet from being inserted again.

Result:

```text
[[2,2,2,2]]
```

---

# Four Duplicate Checks

Your code handles duplicates at four levels.

### 1. Duplicate `i`

```cpp
if (i > 0 && nums[i] == nums[i-1])
    continue;
```

### 2. Duplicate `j`

```cpp
if (j > i+1 && nums[j] == nums[j-1])
    continue;
```

### 3. Duplicate `first`

```cpp
while (first < second &&
       nums[first] == nums[first + 1])
    first++;
```

### 4. Duplicate `second`

```cpp
while (first < second &&
       nums[second] == nums[second - 1])
    second--;
```

Together these ensure unique quadruplets.

---

# Why `first < second`?

```cpp
while (first < second)
```

ensures:

```text
first != second
```

And because:

```text
i < j < first
```

all four indices are distinct.

---

# Why Move the Pointers?

Because the array is sorted.

If:

```text
sum < target
```

we need a larger sum:

```cpp
first++;
```

If:

```text
sum > target
```

we need a smaller sum:

```cpp
second--;
```

This is exactly the two-pointer idea from 3Sum.

---

# 3Sum → 4Sum

Your 3Sum pattern:

```text
Fix one element
      ↓
Two pointers
```

Your 4Sum pattern:

```text
Fix two elements
      ↓
Two pointers
```

So:

```text
3Sum → O(n²)
4Sum → O(n³)
```

This is a very useful K-Sum pattern.

---

# Brute Force vs Your Approach

Brute-force 4Sum:

```text
four nested loops
```

Complexity:

```text
O(n⁴)
```

Your approach:

```text
sort
+
two fixed elements
+
two pointers
```

Complexity:

```text
O(n³)
```

So you reduce:

```text
O(n⁴) → O(n³)
```

---

# Complexity Analysis

Let:

```text
n = nums.size()
```

Sorting:

```text
O(n log n)
```

For every `i`, we run the `j` loop:

```text
O(n²)
```

For every `(i,j)` pair, `first` moves only right and `second` moves only left:

```text
O(n)
```

Therefore:

```text
O(n²) × O(n)
= O(n³)
```

The total is:

```text
O(n log n) + O(n³)
= O(n³)
```

So:

```text
Time Complexity = O(n³)
```

---

# Space Complexity

Ignoring the returned answer, your algorithm uses only:

```text
i
j
first
second
sum
```

Therefore:

```text
Auxiliary Space = O(1)
```

The `ans` vector is output space and is not counted as auxiliary algorithmic space.

---

# Integer Overflow Note

Your current code has:

```cpp
int sum = nums[i] + nums[j] +
          nums[first] + nums[second];
```

A safer general C++ version is:

```cpp
long long sum =
    (long long)nums[i] +
    nums[j] +
    nums[first] +
    nums[second];
```

This avoids overflow when adding several large `int` values.

---

# Complexity Summary

| Part | Complexity |
|---|---:|
| Sorting | `O(n log n)` |
| FourSum search | `O(n³)` |
| Total Time | `O(n³)` |
| Auxiliary Space | `O(1)` |
| Output Space | Depends on number of quadruplets |

---

# Key Pattern to Remember

```text
Sort
  ↓
Fix i
  ↓
Skip duplicate i
  ↓
Fix j
  ↓
Skip duplicate j
  ↓
first = j + 1
second = n - 1
  ↓
Calculate sum
  ↓
sum < target → first++
sum > target → second--
sum == target
      ↓
  store answer
      ↓
  skip duplicates
      ↓
  move both pointers
```

## Final Complexity

```text
Time Complexity:  O(n³)
Auxiliary Space: O(1)
```

The main connection with your previous 3Sum solution is:

```text
3Sum:
1 fixed element + 2 pointers

4Sum:
2 fixed elements + 2 pointers
```

So 4Sum is essentially your 3Sum two-pointer pattern with one additional fixed loop.
