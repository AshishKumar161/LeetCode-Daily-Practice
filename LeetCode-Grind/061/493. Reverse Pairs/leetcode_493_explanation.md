# Reverse Pairs — C++ Solution and Explanation

**LeetCode:** [493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)  
**Approach:** Modified Merge Sort

## C++ Code

```cpp
class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int cnt = 0;
        int j = mid + 1;

        // Count reverse pairs crossing the two sorted halves.
        for (int i = low; i <= mid; i++) {
            while (j <= high &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }

        // Merge the sorted halves.
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int k = 0; k < temp.size(); k++) {
            nums[low + k] = temp[k];
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int cnt = mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, (int)nums.size() - 1);
    }
};
```

## 1. What Is a Reverse Pair?

A reverse pair requires `i < j` **and** `nums[i] > 2 * nums[j]`. It is not enough for `nums[i]` to be merely greater than `nums[j]`.

For `[1,3,2,3,1]`, the two reverse pairs are `(1,4)` and `(3,4)`, since both compare `3` with `1`.

## 2. Why Merge Sort?

Checking every pair takes `O(n^2)` time. Merge sort splits the array into halves and counts:
- pairs fully inside the left half,
- pairs fully inside the right half,
- pairs crossing from the left half to the right half.

Every pair belongs to exactly one of these groups.

## 3. Counting Cross-Half Pairs

```cpp
int j = mid + 1;
for (int i = low; i <= mid; i++) {
    while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
        j++;
    }
    cnt += j - (mid + 1);
}
```

Both halves are sorted. For a fixed `nums[i]`, all right-half values before `j` satisfy the reverse-pair condition. Thus, their count is `j - (mid + 1)`.

The pointer `j` does not need to reset for each `i`: as the left values increase, the number of qualifying right values cannot decrease. This makes the counting scan linear.

**Why `2LL`?** Input values can be large, so `2 * nums[j]` could overflow a 32-bit integer. `2LL * nums[j]` performs the multiplication using `long long`.

## 4. Merge the Halves

After counting, the code merges the two sorted halves into `temp`, always taking the smaller front element. It appends any remaining values and copies the merged result back into `nums[low ... high]`. This keeps each segment sorted for its parent recursive call.

## 5. Dry Run: Cross-Pair Count

Suppose a merge step receives these sorted halves:

```text
Left:  [1, 3, 3]
Right: [1, 2]
```

| Left value | Qualifying right values | Added count |
|---:|---|---:|
| 1 | None | 0 |
| 3 | 1, because `3 > 2 * 1` | 1 |
| 3 | 1, because `3 > 2 * 1` | 1 |

Cross-half count: `2`. The merge then combines the halves into `[1,1,2,3,3]`.

## 6. Recursion

```cpp
int cnt = mergeSort(nums, low, mid);
cnt += mergeSort(nums, mid + 1, high);
cnt += merge(nums, low, mid, high);
```

The recursive calls count pairs in each half. `merge` counts cross-half pairs and sorts the segment. A segment with zero or one element has no pair, so the base case returns `0`.

## Complexity Analysis

Let `n` be the array length.

- **Time:** `O(n log n)` — there are `O(log n)` recursion levels, and each level performs `O(n)` total counting and merging work.
- **Auxiliary space:** `O(n)` for temporary merge vectors, plus `O(log n)` recursion stack space.

## Common Mistakes

- Checking `nums[i] > nums[j]` instead of `nums[i] > 2 * nums[j]`.
- Forgetting `i < j`; the recursive split and cross-half counting enforce this.
- Using 32-bit multiplication instead of `2LL * nums[j]`.
- Resetting `j` for every left-side element, which can make the counting step quadratic.
- Merging before counting cross-half pairs.

## Key Takeaway

Modified merge sort counts reverse pairs in `O(n log n)` time by counting cross-half pairs with a monotonic pointer and then merging the sorted halves.
