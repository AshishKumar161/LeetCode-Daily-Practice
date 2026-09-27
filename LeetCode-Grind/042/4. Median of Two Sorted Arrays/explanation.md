# LeetCode 4: Median of Two Sorted Arrays

## Approach Used in Your Code

Your solution uses the **merge approach**, similar to the merge step of Merge Sort.

You maintain two pointers:

```cpp
int n1 = 0;
int m1 = 0;
```

Then repeatedly compare:

```cpp
nums1[n1]
nums2[m1]
```

and put the smaller element into:

```cpp
vector<int> nums3;
```

After both arrays are merged, you use the middle element(s) to calculate the median.

---

# Your Code

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int n1 = 0;
        int m1 = 0;
        vector<int> nums3;

        while(n1 < n && m1 < m)
        {
            if(nums1[n1] < nums2[m1])
            {
                nums3.push_back(nums1[n1]);
                n1++;
            }
            else
            {
                nums3.push_back(nums2[m1]);
                m1++;
            }
        }

        while(n > n1)
        {
            nums3.push_back(nums1[n1]);
            n1++;
        }

        while(m > m1)
        {
            nums3.push_back(nums2[m1]);
            m1++;
        }

        int n3 = nums3.size();
        int mid = n3 / 2;

        if(n3 % 2 == 1)
        {
            return nums3[mid];
        }

        return (nums3[mid - 1] + nums3[mid]) / 2.0;
    }
};
```

---

# Step 1: Get the Sizes

```cpp
int n = nums1.size();
int m = nums2.size();
```

For:

```text
nums1 = [1,2]
nums2 = [3,4]
```

we have:

```text
n = 2
m = 2
```

---

# Step 2: Create Two Pointers

```cpp
int n1 = 0;
int m1 = 0;
```

They point to the current elements of the two arrays.

```text
nums1 → n1
nums2 → m1
```

Initially both are at index `0`.

---

# Step 3: Create the Merged Array

```cpp
vector<int> nums3;
```

Initially:

```text
nums3 = []
```

It will contain all elements in sorted order.

---

# Step 4: Merge the Two Arrays

```cpp
while(n1 < n && m1 < m)
```

As long as both arrays still contain unprocessed elements, compare their current elements.

```cpp
if(nums1[n1] < nums2[m1])
```

If `nums1` has the smaller element:

```cpp
nums3.push_back(nums1[n1]);
n1++;
```

Otherwise:

```cpp
nums3.push_back(nums2[m1]);
m1++;
```

This is the same basic idea as the **merge step of Merge Sort**.

---

# Dry Run - Example 1

Input:

```text
nums1 = [1,3]
nums2 = [2]
```

Initially:

```text
n1 = 0
m1 = 0
nums3 = []
```

### Compare 1 and 2

```text
1 < 2
```

Take `1`:

```text
nums3 = [1]
n1 = 1
```

### Compare 3 and 2

```text
3 < 2 → false
```

Take `2`:

```text
nums3 = [1,2]
m1 = 1
```

Now `nums2` is finished.

---

# Step 5: Copy Remaining Elements

Your code handles the remaining elements separately:

```cpp
while(n > n1)
{
    nums3.push_back(nums1[n1]);
    n1++;
}
```

Here `nums1` still has:

```text
3
```

So:

```text
nums3 = [1,2,3]
```

The other loop:

```cpp
while(m > m1)
```

does the same thing when `nums2` has remaining elements.

---

# Step 6: Find the Median

```cpp
int n3 = nums3.size();
int mid = n3 / 2;
```

For:

```text
nums3 = [1,2,3]
```

we have:

```text
n3 = 3
mid = 1
```

Because `3` is odd:

```cpp
if(n3 % 2 == 1)
{
    return nums3[mid];
}
```

So:

```text
median = nums3[1] = 2
```

---

# Even Number of Elements

For:

```text
nums1 = [1,2]
nums2 = [3,4]
```

merged array:

```text
[1,2,3,4]
```

Now:

```text
n3 = 4
mid = 2
```

The two middle elements are:

```text
nums3[mid - 1] = 2
nums3[mid]     = 3
```

Therefore:

```cpp
return (nums3[mid - 1] + nums3[mid]) / 2.0;
```

gives:

```text
(2 + 3) / 2.0
= 2.5
```

Using `2.0` is important because it performs floating-point division.

---

# Complete Dry Run - Example 2

```text
nums1 = [1,2]
nums2 = [3,4]
```

### Compare 1 and 3

Take `1`:

```text
nums3 = [1]
```

### Compare 2 and 3

Take `2`:

```text
nums3 = [1,2]
```

`nums1` is finished.

Copy remaining `nums2`:

```text
3,4
```

Final merged array:

```text
[1,2,3,4]
```

Middle values:

```text
2 and 3
```

Median:

```text
2.5
```

---

# Why the Merge Works

Both input arrays are already sorted.

At any point, the smallest unprocessed element must be either:

```text
nums1[n1]
```

or:

```text
nums2[m1]
```

So comparing these two values lets us safely choose the next smallest element.

This guarantees:

```text
nums3
```

is sorted.

---

# Complexity of Your Solution

Let:

```text
n = nums1.size()
m = nums2.size()
```

Every element from both arrays is processed once.

Therefore:

```text
Time = O(n + m)
```

Your vector:

```cpp
vector<int> nums3;
```

stores all `n + m` elements.

Therefore:

```text
Space = O(n + m)
```

So your solution is:

```text
Time:  O(n + m)
Space: O(n + m)
```

---

# Important: Your Solution Does Not Meet the Required Time Complexity

The problem explicitly requires:

```text
O(log(m + n))
```

Your solution uses:

```text
O(m + n)
```

Therefore, your solution correctly calculates the median, but it does **not** satisfy the required complexity constraint.

This is the main issue with this approach.

---

# Why the Optimal Solution Is Different

The optimal solution does **not** fully merge the arrays.

Instead, it uses **binary search** to find a partition:

```text
Left half | Right half
```

across the two arrays.

The goal is to make:

```text
all left-side elements <= all right-side elements
```

while putting exactly half of the combined elements on the left.

Once the correct partition is found, the median can be obtained from the boundary elements.

This gives:

```text
O(log(min(m,n)))
```

time and:

```text
O(1)
```

auxiliary space.

---

# Three Useful Approaches

| Approach | Time | Space |
|---|---:|---:|
| Full merge — your solution | `O(m+n)` | `O(m+n)` |
| Merge without storing result | `O(m+n)` | `O(1)` |
| Binary-search partition | `O(log(min(m,n)))` | `O(1)` |

The binary-search partition approach is the intended optimal solution for this problem.

---

# Important C++ Detail

You wrote:

```cpp
return (nums3[mid - 1] + nums3[mid]) / 2.0;
```

The `2.0` is correct because it ensures floating-point division.

For example:

```text
5 / 2   = 2      // integer division
5 / 2.0 = 2.5    // floating-point division
```

---

# Key Learning

Your approach follows:

```text
Two sorted arrays
       ↓
Two pointers
       ↓
Compare current elements
       ↓
Take smaller element
       ↓
Move pointer
       ↓
Merge remaining elements
       ↓
Find median
```

This is an excellent first approach because it makes the sorted-array property easy to understand.

But LeetCode 4 specifically tests whether you can go beyond the merge solution and achieve logarithmic time.

---

# Pattern to Remember

Your approach:

```cpp
while(n1 < n && m1 < m)
{
    compare nums1[n1] and nums2[m1];

    take smaller element;

    move its pointer;
}

copy remaining elements;
find middle;
```

The optimization:

```text
Do not build the complete merged array.

Instead:

Binary search for the correct partition.
```

---

# Final Complexity

## Your submitted solution

```text
Time:  O(m+n)
Space: O(m+n)
```

## Optimal solution

```text
Time:  O(log(min(m,n)))
Auxiliary Space: O(1)
```

The key lesson is:

```text
Merge approach
    ↓
Simple and intuitive
    ↓
O(m+n)

Binary-search partition
    ↓
More difficult
    ↓
O(log(min(m,n)))
```
