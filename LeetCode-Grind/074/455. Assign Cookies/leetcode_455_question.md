# 455. Assign Cookies

**LeetCode:** [455. Assign Cookies](https://leetcode.com/problems/assign-cookies/)  
**Difficulty:** Easy · **Topics:** Array, Two Pointers, Greedy, Sorting

## Problem Statement

Each child `i` has a greed factor `g[i]`, the minimum cookie size that makes the child content. Each cookie `j` has size `s[j]`. A child is content if assigned a cookie where `s[j] >= g[i]`. Each child receives at most one cookie, and each cookie can be assigned to at most one child.

Return the maximum number of content children.

## Example 1

**Input:** `g = [1,2,3], s = [1,1]`  
**Output:** `1`

**Explanation:** Both cookies have size `1`, so only the child with greed factor `1` can be content.

## Example 2

**Input:** `g = [1,2], s = [1,2,3]`  
**Output:** `2`

**Explanation:** Assign the size-`1` cookie to the child with greed `1` and the size-`2` cookie to the child with greed `2`.

## Constraints

- `1 <= g.length <= 3 * 10^4`
- `0 <= s.length <= 3 * 10^4`
- `1 <= g[i], s[j] <= 10^9`

## Visual Representation

```text
Children greed: [1, 2, 3]
Cookies:        [1, 1]

size 1 -> greed 1  ✓
size 1 -> greed 2  ✗ (too small)

Answer: 1 content child
```

## Function Signature

```cpp
int findContentChildren(vector<int>& g, vector<int>& s);
```

See `leetcode_455_explanation.md` for the greedy strategy, dry runs, correctness reasoning, and complexity.
