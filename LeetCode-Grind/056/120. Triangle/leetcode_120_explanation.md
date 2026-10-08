# LeetCode 120 — Triangle

## Problem

Given a triangle array, return the **minimum path sum** from top to bottom.

From index `j` in the current row, you can move to either `j` or `j + 1` in the next row.

---

# Code

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                triangle[i][j] += min(
                    triangle[i + 1][j],
                    triangle[i + 1][j + 1]
                );
            }
        }

        return triangle[0][0];
    }
};
```

---

# Code Explanation — Line by Line

## 1. Function Declaration

```cpp
int minimumTotal(vector<vector<int>>& triangle)
```

This function receives the triangle by **reference**.

```cpp
vector<vector<int>>&
```

means we can directly modify the original triangle instead of creating another matrix.

The function returns an `int` because the answer is the minimum path sum.

---

## 2. Outer Loop

```cpp
for (int i = triangle.size() - 2; i >= 0; i--)
```

This loop moves from the **second-last row toward the first row**.

### Why `triangle.size() - 2`?

Suppose there are 4 rows:

```text
row 0 → 2
row 1 → 3 4
row 2 → 6 5 7
row 3 → 4 1 8 3
```

The last row is:

```text
row 3
```

It has no row below it, so we do not need to process it.

Therefore, start from:

```text
row 2
```

which is:

```cpp
triangle.size() - 2
```

Then:

```text
2 → 1 → 0
```

So we are moving **bottom → top**.

---

# 3. Inner Loop

```cpp
for (int j = 0; j < triangle[i].size(); j++)
```

This visits every element in the current row.

For example, if:

```text
triangle[i] = [6, 5, 7]
```

then:

```text
j = 0 → 6
j = 1 → 5
j = 2 → 7
```

---

# 4. Find the Two Possible Children

For:

```cpp
triangle[i][j]
```

there are exactly two possible positions in the next row:

```cpp
triangle[i + 1][j]
triangle[i + 1][j + 1]
```

For example:

```text
        2
       / \
      3   4
```

For `2`:

```text
left child  = 3
right child = 4
```

In array indices:

```text
triangle[i + 1][j]
triangle[i + 1][j + 1]
```

---

# 5. Choose the Smaller Child

```cpp
min(
    triangle[i + 1][j],
    triangle[i + 1][j + 1]
)
```

We choose the smaller child because we are looking for the **minimum path sum**.

Example:

```text
        3
       / \
      7   6
```

We choose:

```text
min(7, 6) = 6
```

So the best cost starting from `3` is:

```text
3 + 6 = 9
```

---

# 6. Update the Current Cell

```cpp
triangle[i][j] += min(
    triangle[i + 1][j],
    triangle[i + 1][j + 1]
);
```

This is the most important line.

It changes the current value into:

```text
current value
+
minimum cost from the two children
```

In mathematical form:

```text
dp[i][j] =
triangle[i][j]
+
min(dp[i+1][j], dp[i+1][j+1])
```

Instead of creating a separate `dp` matrix, we store the DP values directly inside `triangle`.

This is called **in-place Dynamic Programming**.

---

# Complete Dry Run

Initial triangle:

```text
        2
       3 4
      6 5 7
     4 1 8 3
```

We start at:

```text
i = 2
```

because:

```cpp
triangle.size() - 2 = 4 - 2 = 2
```

---

## Step 1 — `i = 2, j = 0`

Current:

```text
triangle[2][0] = 6
```

Children:

```text
triangle[3][0] = 4
triangle[3][1] = 1
```

Choose:

```text
min(4, 1) = 1
```

Update:

```text
6 + 1 = 7
```

Triangle becomes:

```text
        2
       3 4
      7 5 7
     4 1 8 3
```

---

## Step 2 — `i = 2, j = 1`

Current:

```text
5
```

Children:

```text
1 and 8
```

Choose:

```text
min(1, 8) = 1
```

Update:

```text
5 + 1 = 6
```

Triangle:

```text
        2
       3 4
      7 6 7
     4 1 8 3
```

---

## Step 3 — `i = 2, j = 2`

Current:

```text
7
```

Children:

```text
8 and 3
```

Choose:

```text
min(8, 3) = 3
```

Update:

```text
7 + 3 = 10
```

Triangle:

```text
        2
       3 4
      7 6 10
     4 1 8 3
```

---

# Now `i = 1`

Current row:

```text
3 4
```

## `j = 0`

Current:

```text
3
```

Children:

```text
7 and 6
```

Choose:

```text
min(7, 6) = 6
```

Update:

```text
3 + 6 = 9
```

Triangle:

```text
        2
       9 4
      7 6 10
     4 1 8 3
```

---

## `j = 1`

Current:

```text
4
```

Children:

```text
6 and 10
```

Choose:

```text
min(6, 10) = 6
```

Update:

```text
4 + 6 = 10
```

Triangle:

```text
        2
       9 10
      7 6 10
     4 1 8 3
```

---

# Now `i = 0`

Current:

```text
2
```

Children:

```text
9 and 10
```

Choose:

```text
min(9, 10) = 9
```

Update:

```text
2 + 9 = 11
```

Final triangle:

```text
        11
       9 10
      7 6 10
     4 1 8 3
```

Therefore:

```text
answer = triangle[0][0] = 11
```

---

# Why Does This Work?

At every position, we calculate the **minimum path sum from that position to the bottom**.

For example:

```text
        3
       / \
      7   6
```

The best path from `3` is:

```text
3 + min(7, 6)
= 3 + 6
= 9
```

So after updating, `3` becomes `9`.

Then the value `9` represents:

```text
minimum cost to travel from this position to the bottom
```

This information is passed upward.

That is the main idea of **Dynamic Programming**:

```text
solve smaller subproblems
        ↓
store their answers
        ↓
use them to solve bigger problems
```

---

# Why Bottom-Up Instead of Top-Down?

A top-down solution would have to keep track of many possible paths.

For example:

```text
2
↙ ↘
3   4
↙↘ ↙↘
...
```

The number of possible paths grows quickly.

Bottom-up avoids repeatedly calculating the same subproblems.

Each cell is processed exactly once.

---

# In-Place DP

Normally we could create:

```cpp
vector<vector<int>> dp = triangle;
```

and store answers in `dp`.

But that would require extra memory.

Instead, we modify:

```cpp
triangle[i][j]
```

directly.

Therefore:

```cpp
triangle[i][j] += ...
```

stores the DP result in the original matrix.

---

# Complexity

Let `N` be the total number of elements in the triangle.

Every element is processed exactly once.

```text
Time Complexity  : O(N)
Space Complexity : O(1) extra
```

There is no additional DP matrix.

---

# Key Pattern to Remember

For Triangle DP:

```text
Start from second-last row
          ↓
Look at two children
          ↓
Take the minimum
          ↓
Add it to current cell
          ↓
Move upward
          ↓
triangle[0][0] = answer
```

Core formula:

```cpp
triangle[i][j] += min(
    triangle[i + 1][j],
    triangle[i + 1][j + 1]
);
```

This is a classic **Bottom-Up Dynamic Programming** pattern.
