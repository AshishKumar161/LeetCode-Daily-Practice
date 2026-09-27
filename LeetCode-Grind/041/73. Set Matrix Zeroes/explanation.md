# LeetCode 73: Set Matrix Zeroes

## Approach

Your solution uses two `unordered_set`s:

```cpp
unordered_set<int> row_index;
unordered_set<int> col_index;
```

The idea is:

1. First scan the matrix and find all **original zeroes**.
2. Store their row indices in `row_index`.
3. Store their column indices in `col_index`.
4. Scan the matrix again.
5. If a cell belongs to a marked row or marked column, set it to `0`.

This is a **two-pass approach**.

---

# Your Code

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        unordered_set<int> row_index;
        unordered_set<int> col_index;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_index.insert(i);
                    col_index.insert(j);
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (row_index.count(i) || col_index.count(j))
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
```

---

# Step 1: Get Matrix Dimensions

```cpp
int row = matrix.size();
int col = matrix[0].size();
```

For:

```text
1 1 1
1 0 1
1 1 1
```

we have:

```text
row = 3
col = 3
```

---

# Step 2: Create Two Sets

```cpp
unordered_set<int> row_index;
unordered_set<int> col_index;
```

They store:

```text
row_index → rows containing an original 0
col_index → columns containing an original 0
```

Initially:

```text
row_index = {}
col_index = {}
```

---

# Step 3: Find Original Zeroes

```cpp
if (matrix[i][j] == 0)
{
    row_index.insert(i);
    col_index.insert(j);
}
```

For:

```text
1 1 1
1 0 1
1 1 1
```

the zero is at:

```text
row = 1
column = 1
```

So:

```text
row_index = {1}
col_index = {1}
```

You only store the **indices**. You do not need to store the zero value.

---

# Step 4: Apply the Zeroes

```cpp
if (row_index.count(i) || col_index.count(j))
{
    matrix[i][j] = 0;
}
```

This asks:

```text
Is this row marked?
OR
Is this column marked?
```

If either is true, the cell becomes zero.

---

# Complete Dry Run

Input:

```text
[
 [1,1,1],
 [1,0,1],
 [1,1,1]
]
```

## First Pass

The only zero is:

```text
matrix[1][1]
```

Therefore:

```text
row_index = {1}
col_index = {1}
```

The matrix is still unchanged:

```text
1 1 1
1 0 1
1 1 1
```

## Second Pass

For row `0`:

```text
column 0 → not marked → 1
column 1 → marked     → 0
column 2 → not marked → 1
```

Row `0` becomes:

```text
1 0 1
```

For row `1`:

```text
row 1 is marked
```

so the entire row becomes:

```text
0 0 0
```

For row `2`:

```text
column 1 is marked
```

so:

```text
1 0 1
```

Final:

```text
[
 [1,0,1],
 [0,0,0],
 [1,0,1]
]
```

---

# Why Two Passes?

You should **not immediately zero cells while finding zeroes**.

Suppose:

```text
1 1 1
1 0 1
1 1 1
```

If you immediately changed row `1` and column `1`, you would create new zeroes.

Those newly created zeroes must **not** be treated as original zeroes.

Therefore:

```text
Pass 1
Find original zeroes
      ↓
Store affected rows/columns
      ↓
Pass 2
Apply the zeroes
```

This is the main reason your solution works correctly.

---

# `unordered_set::count()`

For:

```cpp
row_index.count(i)
```

the result is:

```text
0 → i is not present
1 → i is present
```

For example:

```text
row_index = {1}
```

then:

```text
count(0) = 0
count(1) = 1
count(2) = 0
```

The same applies to `col_index`.

---

# Example 2 Dry Run

Input:

```text
[
 [0,1,2,0],
 [3,4,5,2],
 [1,3,1,5]
]
```

Original zeroes:

```text
(0,0)
(0,3)
```

Therefore:

```text
row_index = {0}
col_index = {0,3}
```

Now apply them:

```text
row 0 → all zero
column 0 → all zero
column 3 → all zero
```

Result:

```text
[
 [0,0,0,0],
 [0,4,5,0],
 [0,3,1,0]
]
```

---

# Complexity Analysis

Let:

```text
m = number of rows
n = number of columns
```

The first nested loop visits every cell:

```text
O(m × n)
```

The second nested loop also visits every cell:

```text
O(m × n)
```

Therefore:

```text
Time = O(m × n)
```

The sets can contain at most:

```text
m row indices
n column indices
```

so:

```text
Extra Space = O(m + n)
```

Final complexity:

```text
Time:  O(m × n)
Space: O(m + n)
```

---

# Is This Strictly O(1) Space?

No.

The problem asks for an in-place modification, and your matrix itself is modified directly.

However, your code also creates:

```cpp
row_index
col_index
```

so it uses additional memory.

Therefore your solution is:

```text
Matrix modified directly: Yes
Auxiliary space: O(m + n)
Strict O(1) auxiliary space: No
```

The standard optimized solution uses the **first row and first column of the matrix as markers**, giving `O(1)` auxiliary space.

---

# Key Learning

Your solution follows this pattern:

```text
Find zero
   ↓
Store row index
Store column index
   ↓
Finish first scan
   ↓
Check every cell
   ↓
If row OR column is marked
   ↓
Set cell to zero
```

The important condition is:

```cpp
if (row_index.count(i) || col_index.count(j))
```

It means:

```text
affected row
OR
affected column
```

therefore:

```cpp
matrix[i][j] = 0;
```

---

# Pattern to Remember

```cpp
// Pass 1
for each cell
{
    if(cell == 0)
    {
        store row;
        store column;
    }
}

// Pass 2
for each cell
{
    if(row is marked || column is marked)
    {
        cell = 0;
    }
}
```

Think:

```text
ZERO FOUND
    ↓
STORE ROW + COLUMN
    ↓
FINISH SCAN
    ↓
APPLY ZEROES
```

---

# Final Complexity

| Metric | Complexity |
|---|---:|
| Time | `O(m × n)` |
| Extra Space | `O(m + n)` |
| Matrix modified directly | Yes |
| Strict O(1) auxiliary space | No |

Your approach is a clean **two-pass row/column marking solution**. The next optimization for this problem is using the matrix's **first row and first column as the marker storage**.
