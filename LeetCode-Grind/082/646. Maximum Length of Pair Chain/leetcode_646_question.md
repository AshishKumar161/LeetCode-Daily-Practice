# LeetCode 646 — Maximum Length of Pair Chain

**Difficulty:** Medium  
**Topics:** Array, Dynamic Programming, Greedy, Sorting

## Problem Statement

You are given an array of `n` pairs, `pairs`, where `pairs[i] = [lefti, righti]` and `lefti < righti`.

A pair `p2 = [c, d]` can follow a pair `p1 = [a, b]` if `b < c`.

Return the length of the longest chain that can be formed. You do not need to use all the given pairs. You can select pairs in any order.

## Example 1

**Input**
```text
pairs = [[1,2], [2,3], [3,4]]
```
**Output**
```text
2
```
**Explanation:** The longest chain is `[1,2] -> [3,4]`. `[2,3]` cannot follow `[1,2]`, because `2 < 2` is false.

```text
Pair [1,2]:  1 ----- 2
Pair [2,3]:        2 ----- 3
Pair [3,4]:              3 ----- 4

Valid:   [1,2] ----------> [3,4]
Invalid: [1,2] --X-------> [2,3]
                 2 is not less than 2
```

## Example 2

**Input**
```text
pairs = [[1,2], [7,8], [4,5]]
```
**Output**
```text
3
```
**Explanation:** The longest chain is `[1,2] -> [4,5] -> [7,8]`, because `2 < 4` and `5 < 7`.

## Constraints

- `n == pairs.length`
- `1 <= n <= 1000`
- `-1000 <= lefti < righti <= 1000`

## Function Signature

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs);
};
```

## Important Rule

The comparison is **strict**: `previous_pair[1] < next_pair[0]`. Equality is not allowed.
