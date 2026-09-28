# LeetCode 4: Median of Two Sorted Arrays

## Approach Used in Your Code

Your solution uses **Binary Search + Partition**.

Instead of merging the arrays, you search for a partition:

``` text
LEFT PART | RIGHT PART
```

such that the left side contains half of the total elements and:

``` text
every LEFT value <= every RIGHT value
```

The main pattern is:

``` text
Binary search on the smaller array
        ↓
Choose partition in nums1
        ↓
Derive partition in nums2
        ↓
Find l1, l2, r1, r2
        ↓
Check whether the partition is valid
        ↓
Correct → calculate median
Wrong   → move binary search
```

## Your Code

``` cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = n1 + n2;

        int left = (n1+n2+1) / 2;
        int low = 0;
        int high = n1;

        while (low <= high)
        {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;

            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 < n1)
                r1 = nums1[mid1];

            if (mid2 < n2)
                r2 = nums2[mid2];

            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];

            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                if(n % 2 == 1)
                {
                    return max(l1,l2);
                }

                return (double)((max(l1,l2) + min(r1,r2)) / 2.0);
            }

            else if (l1 > r2)
            {
                high = mid1 - 1;
            }

            else
            {
                low = mid1 + 1;
            }
        }

        return 0;
    }
};
```

------------------------------------------------------------------------

## 1. Search on the Smaller Array

``` cpp
if (n1 > n2)
{
    return findMedianSortedArrays(nums2, nums1);
}
```

This guarantees:

``` text
n1 <= n2
```

So binary search is performed on the smaller array.

The search range is:

``` cpp
low = 0;
high = n1;
```

This gives:

``` text
O(log(min(n1,n2)))
```

time.

------------------------------------------------------------------------

## 2. Calculate the Left Partition Size

``` cpp
int left = (n1+n2+1) / 2;
```

`left` means the number of elements that must be in the left partition.

For `n = 5`:

``` text
left = 3
```

For `n = 4`:

``` text
left = 2
```

The `+1` makes the odd-sized case keep the median on the left.

------------------------------------------------------------------------

## 3. Choose `mid1`

``` cpp
int mid1 = (low + high) >> 1;
```

This is equivalent to:

``` cpp
int mid1 = (low + high) / 2;
```

`mid1` represents the number of elements taken from `nums1` into the
left partition.

------------------------------------------------------------------------

## 4. Calculate `mid2`

``` cpp
int mid2 = left - mid1;
```

Because:

``` text
mid1 + mid2 = left
```

So `mid2` automatically gives the required partition in `nums2`.

------------------------------------------------------------------------

## Partition Structure

Think of the arrays as:

``` text
nums1:

[ LEFT | RIGHT ]
       ↑
      mid1


nums2:

[ LEFT | RIGHT ]
       ↑
      mid2
```

The four important boundary values are:

``` text
nums1: l1 | r1

nums2: l2 | r2
```

------------------------------------------------------------------------

## 5. Find `l1`, `l2`, `r1`, `r2`

Your code starts with:

``` cpp
int l1 = INT_MIN;
int l2 = INT_MIN;

int r1 = INT_MAX;
int r2 = INT_MAX;
```

Then it fills the values when the corresponding element exists.

``` cpp
if (mid1 < n1)
    r1 = nums1[mid1];

if (mid2 < n2)
    r2 = nums2[mid2];

if (mid1 - 1 >= 0)
    l1 = nums1[mid1 - 1];

if (mid2 - 1 >= 0)
    l2 = nums2[mid2 - 1];
```

Therefore:

``` text
l1 = last LEFT value from nums1
r1 = first RIGHT value from nums1

l2 = last LEFT value from nums2
r2 = first RIGHT value from nums2
```

------------------------------------------------------------------------

## Why `INT_MIN` and `INT_MAX`?

If the partition is at the beginning:

``` text
mid1 = 0
```

there is no left value, so:

``` cpp
l1 = INT_MIN;
```

acts like negative infinity.

If the partition is at the end:

``` text
mid1 = n1
```

there is no right value, so:

``` cpp
r1 = INT_MAX;
```

acts like positive infinity.

This makes the same comparison logic work at array boundaries.

------------------------------------------------------------------------

## 6. Check the Correct Partition

The key condition is:

``` cpp
if (l1 <= r2 && l2 <= r1)
```

Because each array is already sorted, these two cross checks are enough.

We need:

``` text
l1 <= r2
l2 <= r1
```

Together:

``` text
every LEFT value <= every RIGHT value
```

So the partition is correct.

------------------------------------------------------------------------

## 7. Odd Total

If:

``` cpp
n % 2 == 1
```

there is one middle value.

Your code returns:

``` cpp
return max(l1,l2);
```

The left partition contains one extra element, so its largest value is
the median.

Thus:

``` text
median = max(l1,l2)
```

------------------------------------------------------------------------

## 8. Even Total

For an even number of elements, the two middle values are:

``` cpp
max(l1,l2)
```

and:

``` cpp
min(r1,r2)
```

Therefore:

``` text
median =
(max(l1,l2) + min(r1,r2)) / 2
```

------------------------------------------------------------------------

## Example 1 Dry Run

``` text
nums1 = [1,3]
nums2 = [2]
```

Total:

``` text
n = 3
left = 2
```

Correct partition:

``` text
nums1: [1 | 3]
nums2: [2 | ]
```

So:

``` text
l1 = 1
r1 = 3

l2 = 2
r2 = INT_MAX
```

Check:

``` text
1 <= INT_MAX ✓
2 <= 3 ✓
```

Correct.

Since the total is odd:

``` text
median = max(1,2)
       = 2
```

------------------------------------------------------------------------

## Example 2 Dry Run

``` text
nums1 = [1,2]
nums2 = [3,4]
```

Total:

``` text
n = 4
left = 2
```

Correct partition:

``` text
nums1: [1,2 | ]
nums2: [    | 3,4]
```

Therefore:

``` text
l1 = 2
r1 = INT_MAX

l2 = INT_MIN
r2 = 3
```

Two middle values:

``` text
2 and 3
```

Therefore:

``` text
median = (2 + 3) / 2
       = 2.5
```

------------------------------------------------------------------------

## What If the Partition Is Wrong?

### Case 1: `l1 > r2`

``` cpp
high = mid1 - 1;
```

Too many elements from `nums1` are on the left.

Move the partition left.

### Case 2: `l2 > r1`

``` cpp
low = mid1 + 1;
```

Too few elements from `nums1` are on the left.

Move the partition right.

The complete idea is:

``` text
l1 > r2 → move LEFT
l2 > r1 → move RIGHT
```

------------------------------------------------------------------------

## Complete Dry Run of Binary Search

Input:

``` text
nums1 = [1,2]
nums2 = [3,4]
```

Initial:

``` text
n1 = 2
n2 = 2
left = 2
low = 0
high = 2
```

### Iteration 1

``` text
mid1 = 1
mid2 = 1
```

Partition:

``` text
nums1: [1 | 2]
nums2: [3 | 4]
```

Values:

``` text
l1 = 1
r1 = 2
l2 = 3
r2 = 4
```

Check:

``` text
l1 <= r2  → 1 <= 4 ✓
l2 <= r1  → 3 <= 2 ✗
```

So:

``` text
l2 > r1
```

Move right:

``` text
low = mid1 + 1
    = 2
```

### Iteration 2

``` text
mid1 = 2
mid2 = 0
```

Partition:

``` text
nums1: [1,2 | ]
nums2: [    | 3,4]
```

Now:

``` text
l1 = 2
r1 = INT_MAX
l2 = INT_MIN
r2 = 3
```

Check:

``` text
2 <= 3 ✓
INT_MIN <= INT_MAX ✓
```

Correct partition.

Since total is even:

``` text
left middle  = 2
right middle = 3
```

Therefore:

``` text
median = 2.5
```

------------------------------------------------------------------------

## Why We Do Not Merge the Arrays

The simple approach is:

``` text
Merge nums1 and nums2
        ↓
Find the middle
```

That takes:

``` text
O(m+n)
```

But the problem requires logarithmic time.

Your solution instead searches for the correct partition directly.

------------------------------------------------------------------------

## Brute Force vs Optimal

### Merge Approach

``` text
Time: O(m+n)
```

### Your Binary Search Approach

``` text
Time: O(log(min(m,n)))
Space: O(1)
```

The second approach satisfies the required complexity.

------------------------------------------------------------------------

## Complexity Analysis

Because your code first guarantees:

``` text
n1 <= n2
```

binary search is performed only on `nums1`.

Therefore:

``` text
Time Complexity:
O(log(min(m,n)))
```

and:

``` text
Auxiliary Space:
O(1)
```

This is within the required:

``` text
O(log(m+n))
```

------------------------------------------------------------------------

## Important C++ Detail: Average

Your code uses:

``` cpp
return (double)((max(l1,l2) + min(r1,r2)) / 2.0);
```

A more robust form is:

``` cpp
return ((double)max(l1,l2) + min(r1,r2)) / 2.0;
```

This converts before the addition, avoiding an intermediate integer
overflow for very large values.

------------------------------------------------------------------------

## Important C++ Detail: Midpoint

You use:

``` cpp
int mid1 = (low + high) >> 1;
```

which is equivalent to:

``` cpp
int mid1 = (low + high) / 2;
```

A common alternative is:

``` cpp
int mid1 = low + (high - low) / 2;
```

------------------------------------------------------------------------

## Key Pattern to Remember

Memorize:

``` text
nums1:  ... l1 | r1 ...

nums2:  ... l2 | r2 ...
```

Correct partition:

``` text
l1 <= r2
l2 <= r1
```

Median:

``` text
Odd:
max(l1,l2)

Even:
(max(l1,l2) + min(r1,r2)) / 2
```

And:

``` text
mid1 + mid2 = left
```

so:

``` cpp
mid2 = left - mid1;
```

------------------------------------------------------------------------

# Final Algorithm

``` text
1. Make nums1 the smaller array.
2. Calculate total size.
3. Calculate left partition size.
4. Binary search mid1 in nums1.
5. Derive mid2.
6. Get l1, l2, r1, r2.
7. Check:
      l1 <= r2
      l2 <= r1
8. Correct partition:
      odd  → max(l1,l2)
      even → (max(l1,l2) + min(r1,r2)) / 2
9. Wrong partition:
      l1 > r2 → move left
      l2 > r1 → move right
```

# Final Complexity

``` text
Time Complexity:  O(log(min(m,n)))
Auxiliary Space: O(1)
```

The central idea is:

``` text
Do not merge the arrays.

Find the correct partition
        ↓
Left contains half the elements
        ↓
Left values <= right values
        ↓
Read the median from the boundaries
```

This is the key binary-search partition pattern for **LeetCode 4**.
