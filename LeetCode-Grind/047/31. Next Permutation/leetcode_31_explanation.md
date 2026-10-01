# LeetCode 31: Next Permutation

## Approach Used in Your Code

Your solution follows the standard four-step approach:

```text
1. Find the pivot
2. Find the next greater element
3. Swap
4. Reverse the suffix
```

## Your Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int pivot = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }

        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i >= pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        int i = pivot + 1;
        int j = n - 1;

        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
```

# 1. Find the Pivot

```cpp
int pivot = -1;

for (int i = n - 2; i >= 0; i--)
{
    if (nums[i] < nums[i + 1])
    {
        pivot = i;
        break;
    }
}
```

Scan from right to left and find the first index satisfying:

```text
nums[i] < nums[i + 1]
```

This index is the **pivot**.

### Example

```text
[1,2,3,6,5,4]
```

From the right:

```text
5 > 4
6 > 5
3 < 6  ✓
```

So:

```text
pivot = 2
```

and:

```text
nums[pivot] = 3
```

The suffix is:

```text
[6,5,4]
```

The suffix is descending, meaning it is already the largest arrangement of those elements.

# 2. What If `pivot == -1`?

```cpp
if (pivot == -1)
{
    reverse(nums.begin(), nums.end());
    return;
}
```

Example:

```text
[3,2,1]
```

There is no position where:

```text
nums[i] < nums[i+1]
```

Therefore the array is already the **largest permutation**.

The next permutation wraps around to the smallest permutation:

```text
[3,2,1]
    ↓ reverse
[1,2,3]
```

Because the array is already descending, `reverse()` is enough; there is no need for `sort()`.

# 3. Find the Next Greater Element

```cpp
for (int i = n - 1; i >= pivot; i--)
{
    if (nums[i] > nums[pivot])
    {
        swap(nums[i], nums[pivot]);
        break;
    }
}
```

Search from the right for the first value greater than the pivot.

Because the suffix is descending, the first suitable value found from the right is the smallest value that can increase the pivot while keeping the resulting permutation as close as possible to the current one.

### Example

```text
[1,2,3,6,5,4]
```

Pivot:

```text
3
```

Search from the right:

```text
4 > 3  ✓
```

Swap:

```text
[1,2,4,6,5,3]
```

# 4. Reverse the Suffix

```cpp
int i = pivot + 1;
int j = n - 1;

while (i < j)
{
    swap(nums[i], nums[j]);
    i++;
    j--;
}
```

After the swap, the suffix is still descending:

```text
[6,5,3]
```

We need the **smallest possible suffix**, so reverse it:

```text
[3,5,6]
```

Final result:

```text
[1,2,4,3,5,6]
```

# Complete Dry Run

Input:

```text
nums = [1,2,3]
```

### Step 1: Pivot

Check from right:

```text
2 < 3 ✓
```

So:

```text
pivot = 1
```

### Step 2: Successor

Pivot value:

```text
2
```

From the right:

```text
3 > 2 ✓
```

Swap:

```text
[1,3,2]
```

### Step 3: Reverse Suffix

The suffix contains only:

```text
[2]
```

So nothing changes.

Final:

```text
[1,3,2]
```

# Another Dry Run

```text
nums = [1,2,3,6,5,4]
```

Pivot search:

```text
5 > 4
6 > 5
3 < 6 ✓
```

Pivot:

```text
3
```

Find successor:

```text
4 > 3 ✓
```

Swap:

```text
[1,2,4,6,5,3]
```

Reverse suffix:

```text
[6,5,3] → [3,5,6]
```

Final:

```text
[1,2,4,3,5,6]
```

# Why the Algorithm Works

The goal is to find the **immediately next** permutation, not just any larger permutation.

So we:

1. Change the rightmost possible position.
2. Increase that position by the smallest possible amount.
3. Arrange everything after it in the smallest possible order.

That is exactly why we choose:

```text
Rightmost pivot
    ↓
Smallest valid increase
    ↓
Smallest possible suffix
```

# Why Reverse the Suffix?

Before the pivot is changed, the suffix is descending.

For example:

```text
[1,2,3,6,5,4]
```

Suffix:

```text
[6,5,4]
```

After swapping the pivot:

```text
[1,2,4,6,5,3]
```

We need the smallest arrangement of:

```text
[6,5,3]
```

which is:

```text
[3,5,6]
```

Since the suffix is descending, reversing it gives the ascending order directly.

# Edge Cases

## Already Largest

```text
[3,2,1]
```

No pivot → reverse entire array:

```text
[1,2,3]
```

## Duplicate Values

```text
[1,1,5]
```

Pivot is the second `1`.

Swap with `5`:

```text
[1,5,1]
```

## Two Elements

```text
[1,2] → [2,1]
```

and:

```text
[2,1] → [1,2]
```

# Complexity Analysis

Finding the pivot:

```text
O(n)
```

Finding the successor:

```text
O(n)
```

Reversing the suffix:

```text
O(n)
```

Total:

```text
Time Complexity = O(n)
```

Only a few variables are used:

```text
Space Complexity = O(1)
```

# Complexity Summary

| Operation | Complexity |
|---|---:|
| Find pivot | `O(n)` |
| Find successor | `O(n)` |
| Reverse suffix | `O(n)` |
| Total Time | `O(n)` |
| Extra Space | `O(1)` |

# Key Pattern to Remember

Memorize:

```text
P → S → R

P = Pivot
S = Successor
R = Reverse suffix
```

### Pivot

Find from right:

```cpp
nums[i] < nums[i + 1]
```

### Successor

Find from right:

```cpp
nums[i] > nums[pivot]
```

### Reverse

Reverse:

```text
pivot + 1 → end
```

# Final Algorithm

```text
1. Find the rightmost index i where nums[i] < nums[i+1].
2. If no such index exists, reverse the entire array.
3. Find the first element from the right greater than nums[i].
4. Swap it with nums[i].
5. Reverse the suffix after i.
```

## Final Complexity

```text
Time:  O(n)
Space: O(1)
```

The central idea is:

> **Find the rightmost place where the permutation can increase, make the smallest possible increase, then make the suffix as small as possible.**
