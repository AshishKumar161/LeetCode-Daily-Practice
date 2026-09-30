# LeetCode 88: Merge Sorted Array

## Approach Used

Your solution uses the **two-pointer approach from the end**.

Instead of merging from the beginning, we compare the largest elements and place the larger one at the last available position of `nums1`.

### Main idea

```text
Compare largest elements
        ↓
Put the larger element at the back
        ↓
Move that pointer backward
        ↓
Repeat
```

## Your Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;

        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            }
            else
            {
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }

        while (j >= 0)
        {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }
};
```

## Step 1: The Three Pointers

```cpp
int idx = m + n - 1;
int i = m - 1;
int j = n - 1;
```

- `i` points to the last useful element of `nums1`.
- `j` points to the last element of `nums2`.
- `idx` points to the last position where we can place an element.

For:

```text
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
```

we have:

```text
i = 2
j = 2
idx = 5
```

So we compare `3` and `6`.

## Step 2: Why Start From the End?

The end of `nums1` already contains empty positions.

For example:

```text
nums1 = [1,2,3,0,0,0]
                 ↑
              empty space
```

If we start from the beginning, inserting an element could require shifting existing values.

Starting from the end avoids shifting.

## Step 3: Compare the Largest Elements

```cpp
if (nums1[i] >= nums2[j])
{
    nums1[idx] = nums1[i];
    idx--;
    i--;
}
else
{
    nums1[idx] = nums2[j];
    idx--;
    j--;
}
```

We always place the larger value at `idx`.

### Example

```text
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
```

Compare:

```text
3 vs 6
```

Place `6`:

```text
[1,2,3,0,0,6]
```

Then:

```text
3 vs 5
```

Place `5`:

```text
[1,2,3,0,5,6]
```

Then:

```text
3 vs 2
```

Place `3`:

```text
[1,2,3,3,5,6]
```

Then:

```text
2 vs 2
```

Your `>=` condition selects the value from `nums1`:

```text
[1,2,2,3,5,6]
```

Continue until `nums2` is exhausted.

## Step 4: Why Do We Need the Second While Loop?

```cpp
while (j >= 0)
{
    nums1[idx] = nums2[j];
    idx--;
    j--;
}
```

Suppose:

```text
nums1 = [4,5,6,0,0,0]
nums2 = [1,2,3]
```

All elements of `nums1` are larger.

After the first loop, `nums2` still contains:

```text
[1,2,3]
```

Therefore, we copy those remaining values into `nums1`.

Result:

```text
[1,2,3,4,5,6]
```

## Why Don't We Copy Remaining `nums1` Elements?

There is no need for:

```cpp
while (i >= 0)
```

If `nums2` becomes empty first, the remaining elements of `nums1` are already in their correct positions.

That is an important property of this approach.

## Complete Dry Run

Input:

```text
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
```

Initial:

```text
i = 2
j = 2
idx = 5
```

### 1. Compare `3` and `6`

Place `6`:

```text
[1,2,3,0,0,6]
```

```text
i = 2
j = 1
idx = 4
```

### 2. Compare `3` and `5`

Place `5`:

```text
[1,2,3,0,5,6]
```

```text
i = 2
j = 0
idx = 3
```

### 3. Compare `3` and `2`

Place `3`:

```text
[1,2,3,3,5,6]
```

```text
i = 1
j = 0
idx = 2
```

### 4. Compare `2` and `2`

Place `2`:

```text
[1,2,2,3,5,6]
```

### 5. Compare `1` and `2`

Place `2`:

```text
[1,2,2,3,5,6]
```

Now `j = -1`, so the merge is complete.

## Important Edge Cases

### `nums2` is empty

```text
nums1 = [1]
m = 1
nums2 = []
n = 0
```

The result remains:

```text
[1]
```

### `nums1` has no valid elements

```text
nums1 = [0]
m = 0
nums2 = [1]
n = 1
```

The first loop does not run. The second loop copies `1`:

```text
[1]
```

### Duplicate values

```text
nums1 = [1,2,3,0,0,0]
nums2 = [2,2,4]
```

The result is:

```text
[1,2,2,2,3,4]
```

## Complexity Analysis

Every element is processed at most once.

Therefore:

```text
Time Complexity: O(m + n)
```

No extra array is created:

```text
Auxiliary Space: O(1)
```

## Complexity Summary

| Metric | Complexity |
|---|---:|
| Time | `O(m + n)` |
| Extra Space | `O(1)` |

## Key Pattern to Remember

This is an important DSA pattern:

```text
Two pointers + fill from the end
```

When two arrays are sorted and one array has enough empty space to hold the result:

```text
Start from the largest elements
        ↓
Compare from the right
        ↓
Place the larger element at the back
```

## Final Algorithm

```text
1. Set i to the last valid element of nums1.
2. Set j to the last element of nums2.
3. Set idx to the last position of nums1.
4. Compare nums1[i] and nums2[j].
5. Put the larger value at nums1[idx].
6. Move the corresponding pointer backward.
7. Continue until one array is exhausted.
8. Copy any remaining nums2 elements.
```

### Final Complexity

```text
Time:  O(m + n)
Space: O(1)
```

The key idea is:

> **Compare from the back → place from the back.**

This lets the merge happen in-place without shifting elements.
