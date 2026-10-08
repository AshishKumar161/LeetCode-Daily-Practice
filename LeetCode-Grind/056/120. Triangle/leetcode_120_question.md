# LeetCode 120 — Triangle

Given a triangle array, return the **minimum path sum from top to bottom**.

For each step, you may move to an adjacent number of the row below.

From index `i` on the current row, you may move to index `i` or `i + 1` on the next row.

## Example 1

```text
Input:
triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]

Output:
11
```

The minimum path is:

```text
2 → 3 → 5 → 1
```

So:

```text
2 + 3 + 5 + 1 = 11
```

## Example 2

```text
Input:
triangle = [[-10]]

Output:
-10
```

## Constraints

```text
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4
```
