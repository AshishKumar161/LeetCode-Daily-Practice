# Count Subarrays with Given XOR K — Explanation

**Language:** C++  
**Approach:** Prefix XOR + ordered map

## C++ Solution

```cpp
class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        int xr = 0;
        map<int, int> hash;

        hash[0]++;  // Empty prefix with XOR 0.
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            xr = xr ^ nums[i];  // Current prefix XOR.

            int x = xr ^ k;     // Earlier prefix XOR we need.
            cnt += hash[x];     // Count matching earlier prefixes.

            hash[xr]++;         // Record current prefix XOR.
        }

        return cnt;
    }
};
```

**Note:** In the screenshot, the loop uses `a.size()`, but the input vector is named `nums`. Use `nums.size()` unless you have separately declared a variable named `a`.

## 1. XOR Properties

- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is associative and commutative.

Therefore, if `xr ^ x = k`, then `x = xr ^ k`.

## 2. Prefix XOR Logic

`xr` is the XOR of all elements from index `0` through the current index. To make a subarray XOR equal to `k`, we need an earlier prefix XOR equal to `xr ^ k`.

The map stores how many times each prefix XOR has appeared. Every matching earlier prefix represents one valid subarray.

## 3. Why `hash[0] = 1`?

The initial zero represents the empty prefix before the array. It lets us count valid subarrays that start at index `0`.

## 4. Dry Run

Input:
```text
nums = [5, 2, 9], k = 7
```

Initially: `xr = 0`, `cnt = 0`, and `hash = {0: 1}`.

| Index | Value | Prefix XOR `xr` | `x = xr ^ k` | Previous matches | Count |
|---:|---:|---:|---:|---:|---:|
| 0 | 5 | 5 | 2 | 0 | 0 |
| 1 | 2 | 7 | 0 | 1 | 1 |
| 2 | 9 | 14 | 9 | 0 | 1 |

At index `1`, prefix XOR is `7`, so `x = 7 ^ 7 = 0`. The initial `hash[0]` entry counts subarray `[5, 2]`, whose XOR is `7`.

**Output: `1`**

## 5. Complexity Analysis

Let `n` be the array length.

- **Time:** `O(n log n)` because `map` operations take `O(log n)` and are performed for each element.
- **Auxiliary space:** `O(n)` for the prefix XOR frequencies in the map.

Using `unordered_map` instead of `map` gives expected `O(n)` time, with `O(n)` auxiliary space.

## Common Mistakes

- Using `nums[i] ^ k` instead of the running prefix XOR `xr ^ k`.
- Forgetting `hash[0] = 1`.
- Updating the map before checking the number of matches.
- Confusing bitwise XOR (`^`) with addition.
- Using `a.size()` when the vector is named `nums`.

## Key Takeaway

For each prefix XOR `xr`, count previous prefixes equal to `xr ^ k`. This prefix-XOR and frequency-map technique counts all valid subarrays without checking every possible subarray.
