# Subarray Sum Equals K — C++ Explanation

**LeetCode:** [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)  
**Approach:** Prefix Sum + Hash Map

## C++ Code

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        int n = nums.size();
        int sum = 0;
        int count = 0;

        hash[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (hash.find(sum - k) != hash.end()) {
                count += hash[sum - k];
            }

            hash[sum]++;
        }

        return count;
    }
};
```

## 1. Prefix Sum Idea

A prefix sum is the sum of elements from index `0` through the current index.

If the current prefix sum is `sum` and an earlier prefix sum is `oldSum`, the subarray between those prefix positions has sum:

`sum - oldSum`

We need this to equal `k`, so:

`sum - oldSum = k`  
`oldSum = sum - k`

Therefore, the algorithm looks up `sum - k` in the hash map.

## 2. What Does the Map Store?

```cpp
unordered_map<int, int> hash;
hash[0] = 1;
```

`hash[p]` records how many times prefix sum `p` has occurred before the current position. The initial `hash[0] = 1` represents the empty prefix, allowing a matching subarray that begins at index `0` to be counted.

## 3. Update the Running Sum

```cpp
sum += nums[i];
```

Include the current element in the prefix sum.

## 4. Count Matching Prefix Sums

```cpp
if (hash.find(sum - k) != hash.end()) {
    count += hash[sum - k];
}
```

Each earlier occurrence of `sum - k` identifies one subarray ending at the current index with sum `k`. Add the stored frequency, not just `1`, because the same prefix sum can occur multiple times.

## 5. Record the Current Prefix

```cpp
hash[sum]++;
```

Store the current prefix sum for future elements. Do this after the lookup so the current prefix is not treated as an earlier prefix for itself.

## Dry Run 1

Input: `nums = [1,2,3]`, `k = 3`

Initial state: `sum = 0`, `count = 0`, `hash = {0:1}`.

| Index | Value | `sum` | `sum - k` | Found frequency | Count |
|---:|---:|---:|---:|---:|---:|
| 0 | 1 | 1 | -2 | 0 | 0 |
| 1 | 2 | 3 | 0 | 1 | 1 |
| 2 | 3 | 6 | 3 | 1 | 2 |

The matching subarrays are `[1,2]` and `[3]`. Output: `2`.

## Dry Run 2

Input: `nums = [1,1,1]`, `k = 2`

Initial state: `sum = 0`, `count = 0`, `hash = {0:1}`.

| Index | Value | `sum` | `sum - k` | Found frequency | Count |
|---:|---:|---:|---:|---:|---:|
| 0 | 1 | 1 | -1 | 0 | 0 |
| 1 | 1 | 2 | 0 | 1 | 1 |
| 2 | 1 | 3 | 1 | 1 | 2 |

Output: `2`, from the two subarrays `[1,1]`.

## Why Not Use a Sliding Window?

Negative numbers are allowed. Adding a negative value can reduce the running sum, so the sum is not monotonic as the window expands or shrinks. A standard sliding window therefore cannot solve all valid inputs reliably.

## Complexity Analysis

Let `n` be the array length.

- **Average time:** `O(n)` — each element performs a constant number of expected hash-map operations.
- **Auxiliary space:** `O(n)` — the map may store up to `n + 1` distinct prefix sums.

## Common Mistakes

- Forgetting `hash[0] = 1`.
- Adding `1` instead of the frequency `hash[sum - k]`.
- Updating `hash[sum]` before checking `sum - k`.
- Using a standard sliding window despite negative values.
- Confusing a prefix sum with a subarray sum.

## Key Takeaway

A subarray sums to `k` when the current prefix sum minus an earlier prefix sum equals `k`. Prefix-sum frequencies let us count these subarrays in average `O(n)` time.
