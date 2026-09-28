# LeetCode 15: 3Sum

## Approach Used in Your Code

Your solution uses:

```text
Sorting + Two Pointers
```

The idea is:

1. Sort the array.
2. Fix one element with `i`.
3. Use `first` and `second` pointers to find the other two elements.
4. If the sum is too small, move `first` right.
5. If the sum is too large, move `second` left.
6. When the sum is zero, store the triplet.
7. Skip duplicates so the answer contains no duplicate triplets.

---

# Your Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int first = i + 1;
            int second = n - 1;

            while(first < second)
            {
                int sum = nums[i] + nums[first] + nums[second];

                if (sum == 0)
                {
                    ans.push_back({
                        nums[i],
                        nums[first],
                        nums[second]
                    });

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

                    first++;
                    second--;
                }
                else if (sum < 0)
                {
                    first++;
                }
                else
                {
                    second--;
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
[-1,0,1,2,-1,-4]
```

becomes:

```text
[-4,-1,-1,0,1,2]
```

Sorting is essential because it lets us control the sum using two pointers.

---

# Step 2: Fix One Element

```cpp
for (int i = 0; i < n; i++)
```

`i` represents the first element of the triplet.

For example:

```text
i = 0
nums[i] = -4
```

Now we need two other values whose sum is `4`:

```text
-4 + x + y = 0
x + y = 4
```

---

# Step 3: Create Two Pointers

```cpp
int first = i + 1;
int second = n - 1;
```

For:

```text
[-4,-1,-1,0,1,2]
```

with `i = 0`:

```text
[-4, -1, -1, 0, 1, 2]
  ↑    ↑              ↑
  i   first         second
```

---

# Step 4: Calculate the Sum

```cpp
int sum = nums[i] + nums[first] + nums[second];
```

There are three cases.

### `sum == 0`

A valid triplet was found:

```cpp
ans.push_back({nums[i], nums[first], nums[second]});
```

### `sum < 0`

The sum is too small.

Because the array is sorted, increase the sum:

```cpp
first++;
```

### `sum > 0`

The sum is too large.

Decrease the sum:

```cpp
second--;
```

---

# Why Does `first++` Increase the Sum?

Because the array is sorted.

When `first` moves right:

```text
value does not decrease
```

So if:

```text
sum < 0
```

we need a larger value, therefore:

```cpp
first++;
```

Similarly, when:

```text
sum > 0
```

we need a smaller value, therefore:

```cpp
second--;
```

---

# Complete Dry Run

Input:

```text
[-1,0,1,2,-1,-4]
```

After sorting:

```text
[-4,-1,-1,0,1,2]
```

## `i = 0`

```text
nums[i] = -4
first = 1
second = 5
```

First:

```text
-4 + (-1) + 2 = -3
```

Negative, so:

```text
first++
```

Next:

```text
-4 + (-1) + 2 = -3
```

Again:

```text
first++
```

Next:

```text
-4 + 0 + 2 = -2
```

Move `first`.

Next:

```text
-4 + 1 + 2 = -1
```

Move `first`.

Now:

```text
first == second
```

Stop.

No valid triplet starts with `-4`.

---

# `i = 1`

```text
nums[i] = -1
first = 2
second = 5
```

Calculate:

```text
-1 + (-1) + 2 = 0
```

Found:

```text
[-1,-1,2]
```

Store it:

```text
ans = [[-1,-1,2]]
```

---

# Skip Duplicate Values

After finding a triplet, your code does:

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

This prevents duplicate triplets.

Then:

```cpp
first++;
second--;
```

moves both pointers to search for another triplet.

---

# Continue `i = 1`

Eventually the pointers reach:

```text
first = 3
second = 4
```

Values:

```text
-1 + 0 + 1 = 0
```

So we find:

```text
[-1,0,1]
```

Final result:

```text
[[-1,-1,2],[-1,0,1]]
```

---

# Duplicate `i` Check

This code:

```cpp
if (i > 0 && nums[i] == nums[i-1])
{
    continue;
}
```

is very important.

After sorting:

```text
[-4,-1,-1,0,1,2]
```

both index `1` and index `2` contain `-1`.

If we processed both, we could generate the same triplets again.

Therefore, when the current `nums[i]` equals the previous value, skip it.

---

# Three Duplicate Checks

Your solution handles duplicates in three places.

## 1. Duplicate first element

```cpp
if (i > 0 && nums[i] == nums[i-1])
    continue;
```

## 2. Duplicate `first`

```cpp
while (first < second &&
       nums[first] == nums[first + 1])
    first++;
```

## 3. Duplicate `second`

```cpp
while (first < second &&
       nums[second] == nums[second - 1])
    second--;
```

Together they ensure that duplicate triplets are not added.

---

# Example: `[0,0,0]`

Input:

```text
[0,0,0]
```

Pointers:

```text
i = 0
first = 1
second = 2
```

Sum:

```text
0 + 0 + 0 = 0
```

Store:

```text
[0,0,0]
```

The duplicate loops skip the other equal values.

Final:

```text
[[0,0,0]]
```

Only one triplet is returned.

---

# Why `first < second`?

```cpp
while(first < second)
```

ensures that `first` and `second` refer to different positions.

Also:

```text
first = i + 1
```

already guarantees:

```text
i < first
```

Therefore all three indices are different.

---

# Why Sorting Is Required

Without sorting, these rules would not be valid:

```text
sum < 0 → first++
sum > 0 → second--
```

Sorting guarantees:

```text
first moves right → value gets larger or equal
second moves left → value gets smaller or equal
```

That is what makes the two-pointer technique work.

---

# Complexity Analysis

Let:

```text
n = nums.size()
```

## Sorting

```cpp
sort(nums.begin(), nums.end());
```

takes:

```text
O(n log n)
```

## Two-Pointer Search

For each fixed `i`, `first` only moves right and `second` only moves left.

So the inner search is:

```text
O(n)
```

for each `i`.

The outer loop runs `O(n)` times:

```text
O(n) × O(n) = O(n²)
```

Therefore:

```text
O(n log n) + O(n²)
= O(n²)
```

---

# Space Complexity

The algorithm uses only a few pointer variables besides the output:

```text
i
first
second
sum
```

Therefore the algorithm's auxiliary space is:

```text
O(1)
```

The returned `ans` itself can contain many triplets, so its output space is separate.

---

# Brute Force vs Your Approach

A brute-force solution uses three loops:

```text
i
j
k
```

and checks every combination.

Complexity:

```text
O(n³)
```

Your solution:

```text
Sort
  ↓
Fix i
  ↓
Two pointers
```

Complexity:

```text
O(n²)
```

So you improve:

```text
O(n³) → O(n²)
```

---

# Key Pattern to Remember

```text
Sort
  ↓
Fix one element
  ↓
first = i + 1
second = n - 1
  ↓
Calculate sum
  ↓
sum < 0  → first++
sum > 0  → second--
sum == 0 → store + skip duplicates + move both
```

For 3Sum:

```text
target = 0
```

so the condition is:

```cpp
nums[i] + nums[first] + nums[second] == 0
```

---

# Final Complexity

```text
Time Complexity:  O(n²)
Auxiliary Space: O(1)
```

The main idea you should remember is:

```text
Brute Force:
O(n³)

Sorting + Two Pointers:
O(n²)
```

The duplicate-handling logic is just as important as the two-pointer logic because the problem requires **unique triplets**.
