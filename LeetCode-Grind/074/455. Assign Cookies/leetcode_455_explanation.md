# 455. Assign Cookies — Code Explanation

**LeetCode:** [455. Assign Cookies](https://leetcode.com/problems/assign-cookies/)  
**Language:** C++

## Your Code

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // current child
        int j = 0; // current cookie

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // child is content
            }
            j++; // this cookie has been considered
        }

        return i;
    }
};
```

## 1. Greedy Strategy

Sort the children by greed factor and cookies by size. Always try the smallest cookie against the least-greedy child who has not yet received a cookie.

- If the cookie is large enough, assign it and move to the next child.
- If it is too small, discard it and try the next cookie. Because greed factors are sorted, that cookie cannot satisfy this child or any child after them.

This saves larger cookies for children who may need them.

## 2. Pointer Meaning

- `i`: next child who has not yet been satisfied.
- `j`: next cookie to consider.
- `s[j] >= g[i]`: the cookie can satisfy this child.
- `i` increases only after a successful assignment.
- `j` increases on every iteration because each cookie is considered at most once.

When the loop ends, `i` is the number of content children.

## 3. Dry Run — Example 1

Input: `g = [1,2,3]`, `s = [1,1]`  
Sorted arrays are unchanged.

| Step | i | j | Check | Action |
|---:|---:|---:|---|---|
| 1 | 0 | 0 | `1 >= 1` | Assign cookie; `i=1`, then `j=1` |
| 2 | 1 | 1 | `1 >= 2` is false | Cookie too small; `j=2` |
| Stop | 1 | 2 | No cookies left | Return `1` |

Output: `1`.

## 4. Dry Run — Example 2

Input: `g = [1,2]`, `s = [1,2,3]`.

| Step | i | j | Check | Action |
|---:|---:|---:|---|---|
| 1 | 0 | 0 | `1 >= 1` | Assign; `i=1`, `j=1` |
| 2 | 1 | 1 | `2 >= 2` | Assign; `i=2`, `j=2` |
| Stop | 2 | 2 | All children satisfied | Return `2` |

Output: `2`. The size-`3` cookie can remain unused.

## 5. Why Greedy Works

The least-greedy remaining child is the easiest to satisfy. If the smallest available cookie satisfies that child, using it is safe: a larger cookie is not needed for this child and may be needed for a more demanding child.

If a cookie is too small for the current child, it is also too small for every later child because the greed array is sorted. Skipping it cannot lose a possible match. Therefore, the algorithm maximizes the number of successful assignments.

## 6. Complexity

Let `n = g.size()` and `m = s.size()`.

- Sorting: `O(n log n + m log m)`
- Two-pointer scan: `O(n + m)`
- **Total time:** `O(n log n + m log m)`
- **Auxiliary space:** The scan itself uses `O(1)` extra variables; sorting may use implementation-dependent stack space.

## 7. Common Mistakes

- Correct syntax is `sort(g.begin(), g.end())`.
- Increment `j` on every iteration.
- Increment `i` only when the cookie fits the child's greed factor.
- Return `i`, not `j`, because `i` counts satisfied children.
- Keep both bounds in the loop: `i < g.size() && j < s.size()`.

## Summary

Sorting plus two pointers implements a greedy matching strategy. Match the smallest suitable cookie to the least-greedy child. The solution runs in `O(n log n + m log m)` time.
