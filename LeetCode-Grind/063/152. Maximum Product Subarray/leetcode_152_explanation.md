# Maximum Product Subarray — Explanation

**LeetCode:** [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)  
**Language:** C++ · **Approach:** Prefix and suffix products

## C++ Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int max_prod = INT_MIN;
        int pref = 1, suff = 1;

        for (int i = 0; i < n; i++) {
            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;

            pref = pref * nums[i];
            suff = suff * nums[n - i - 1];

            max_prod = max({max_prod, pref, suff});
        }

        return max_prod;
    }
};
```

## 1. Why Is It Tricky?

Multiplication behaves differently from addition:

- A positive value preserves the sign of the product.
- A negative value flips the sign.
- Zero makes the product zero.

A very negative product can become the maximum after multiplying by another negative number. Tracking products from both ends helps handle this.

## 2. Variables

- `max_prod`: largest product found so far. `INT_MIN` is important when all values are negative.
- `pref`: running product from the left.
- `suff`: running product from the right.
- `n`: length of the array.

Both running products start at `1`, the multiplicative identity.

## 3. Reset After Zero

```cpp
if (pref == 0) pref = 1;
if (suff == 0) suff = 1;
```

A zero breaks a product segment. Resetting to `1` lets the next nonzero element begin a new segment. The zero itself is still considered because the product is updated before `max_prod` is updated.

## 4. Multiply from Both Directions

```cpp
pref = pref * nums[i];
suff = suff * nums[n - i - 1];
```

`pref` extends the product from the left, while `suff` extends it from the right. The largest product may be easier to discover from either direction, especially when negative values are present.

## 5. Update the Answer

```cpp
max_prod = max({max_prod, pref, suff});
```

Keep the maximum among the best result so far and both current products. The initializer-list overload of `max` is provided by `<algorithm>`.

## Dry Run

Input: `nums = [2, 3, -2, 4]`

| `i` | Left value | Right value | `pref` | `suff` | `max_prod` |
|---:|---:|---:|---:|---:|---:|
| 0 | 2 | 4 | 2 | 4 | 4 |
| 1 | 3 | -2 | 6 | -8 | 6 |
| 2 | -2 | 3 | -12 | -24 | 6 |
| 3 | 4 | 2 | -48 | -48 | 6 |

The answer is `6`, from subarray `[2,3]`.

## Complexity Analysis

For `n = nums.size()`:

- **Time:** `O(n)` — one loop visits each index once.
- **Auxiliary space:** `O(1)` — only a constant number of variables are used.

## Common Mistakes

- Initializing the answer to `0`; this fails for arrays whose best product is negative.
- Tracking only a left-to-right product; negative numbers can flip the sign.
- Forgetting to reset after zero.
- Choosing non-contiguous elements; the answer must come from a contiguous subarray.

## Alternative DP Approach

A standard dynamic-programming solution tracks both:
- `curMax`: maximum product of a subarray ending at the current index.
- `curMin`: minimum product ending at the current index.

When the current value is negative, swap `curMax` and `curMin`, then update both. This is also `O(n)` time and `O(1)` auxiliary space.

## Key Takeaway

Negative values can turn a minimum product into a maximum product. The prefix/suffix method scans both directions to account for this while using constant extra space.
