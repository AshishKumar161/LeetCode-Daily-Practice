# Longest Consecutive Sequence — C++ Explanation

**LeetCode:** [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)  
**Approach:** `unordered_set`

## C++ Code

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            // Start only at the beginning of a sequence.
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int count = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
```

## 1. Build the Set

```cpp
unordered_set<int> st(nums.begin(), nums.end());
```

This stores each distinct value once. For example, `[1,0,1,2]` becomes `{0,1,2}`. Average membership lookup in an `unordered_set` is `O(1)`.

## 2. Iterate Through Unique Numbers

```cpp
for (int num : st)
```

This visits every distinct number. The set's iteration order is not sorted, but the algorithm does not rely on any particular order.

## 3. Check Whether a Number Starts a Sequence

```cpp
if (st.find(num - 1) == st.end())
```

`st.find(num - 1)` searches for the predecessor of `num`.

- If the predecessor is absent (`st.find(...) == st.end()`), `num` is the start of a sequence.
- If the predecessor exists, `num` is somewhere in the middle or at the end of a sequence, so skip starting a new count from it.

For `{1,2,3,4}`, only `1` starts a sequence because `0` is absent. This prevents repeatedly counting the same run.

## 4. Count Consecutive Values

```cpp
int curr = num;
int count = 1;

while (st.find(curr + 1) != st.end()) {
    curr++;
    count++;
}
```

The starting number itself contributes length `1`. While the next integer exists, move forward and increment the count.

## 5. Update the Answer

```cpp
longest = max(longest, count);
```

Keep the largest length found among all sequence starts.

## Dry Run

Input:

```text
nums = [100, 4, 200, 1, 3, 2]
```

Set: `{100, 4, 200, 1, 3, 2}` (iteration order can vary).

| Number | Is `num - 1` absent? | What happens? | Length |
|---:|---|---|---:|
| 100 | Yes (`99` absent) | Count `[100]` | 1 |
| 4 | No (`3` exists) | Skip | — |
| 200 | Yes (`199` absent) | Count `[200]` | 1 |
| 1 | Yes (`0` absent) | Count `[1,2,3,4]` | 4 |
| 3 | No (`2` exists) | Skip | — |
| 2 | No (`1` exists) | Skip | — |

The maximum length is `4`.

**Output:** `4`

## Complexity Analysis

Let `n` be the input length.

- **Average time complexity: `O(n)`.** Building the set is average `O(n)`, and each sequence is expanded only from its beginning. Across all sequences, the forward checks process each distinct element at most once as part of a sequence.
- **Auxiliary space complexity: `O(n)`.** The set may contain every input value if they are all distinct.

`unordered_set` operations can degrade in pathological worst cases, but average `O(n)` is the standard analysis for this solution.

## Common Mistakes

- Expanding a sequence from every number instead of checking whether `num - 1` exists.
- Using linear search in a vector for each lookup, which can make the solution `O(n^2)`.
- Counting duplicate values more than once.
- Assuming `unordered_set` iterates in sorted order.
- Initializing `longest` to a value other than `0`, which can mishandle an empty array.

## Key Takeaway

Start counting only when the predecessor is missing. This avoids duplicate work and achieves average `O(n)` time.
