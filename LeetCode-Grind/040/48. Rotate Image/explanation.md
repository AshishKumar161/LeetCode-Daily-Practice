# LeetCode 48: Rotate Image

## Approach Used in Your Code

Your solution creates a temporary **1D vector** and stores the rotated matrix in flattened form.

The key observation is:

```text
For every column:
    read from bottom → top
    store those values

Then:
    write the stored values row-by-row
```

For:

```text
1 2 3
4 5 6
7 8 9
```

the columns read bottom-to-top are:

```text
7 4 1
8 5 2
9 6 3
```

which is exactly the 90° clockwise rotation.

---

# Your Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int left = 0;

        vector<int> matrixx;

        while (left < n)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                matrixx.push_back(matrix[i][left]);
            }
            left++;
        }

        int k = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = matrixx[k];
                k++;
            }
        }
    }
};
```

---

# Step 1: Get Matrix Size

```cpp
int n = matrix.size();
```

For a `3 x 3` matrix:

```text
n = 3
```

---

# Step 2: Start With the First Column

```cpp
int left = 0;
```

Here `left` represents the column currently being processed.

Initially:

```text
left = 0
```

---

# Step 3: Temporary Vector

```cpp
vector<int> matrixx;
```

This stores the rotated matrix as one linear array.

Initially:

```text
matrixx = []
```

---

# Step 4: Read Each Column Bottom-to-Top

```cpp
while (left < n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        matrixx.push_back(matrix[i][left]);
    }

    left++;
}
```

For:

```text
1 2 3
4 5 6
7 8 9
```

## Column 0

```text
matrix[2][0] = 7
matrix[1][0] = 4
matrix[0][0] = 1
```

So:

```text
matrixx = [7,4,1]
```

## Column 1

```text
8,5,2
```

Now:

```text
matrixx = [7,4,1,8,5,2]
```

## Column 2

```text
9,6,3
```

Final:

```text
matrixx = [7,4,1,8,5,2,9,6,3]
```

---

# Why Does This Rotate the Matrix?

Original:

```text
1 2 3
4 5 6
7 8 9
```

Column 0, bottom → top:

```text
7
4
1
```

becomes row 0:

```text
7 4 1
```

Column 1, bottom → top:

```text
8
5
2
```

becomes row 1:

```text
8 5 2
```

Column 2, bottom → top:

```text
9
6
3
```

becomes row 2:

```text
9 6 3
```

Therefore:

```text
7 4 1
8 5 2
9 6 3
```

---

# Step 5: Write Back Into the Matrix

```cpp
int k = 0;
```

`k` points to the current element of `matrixx`.

Then:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        matrix[i][j] = matrixx[k];
        k++;
    }
}
```

The values are written row-by-row.

### Row 0

```text
matrixx[0] = 7
matrixx[1] = 4
matrixx[2] = 1
```

Result:

```text
7 4 1
```

### Row 1

```text
8 5 2
```

### Row 2

```text
9 6 3
```

Final:

```text
7 4 1
8 5 2
9 6 3
```

---

# Complete Dry Run

Input:

```text
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]
```

| `left` | Column read bottom → top | `matrixx` |
|---:|---|---|
| 0 | `7,4,1` | `[7,4,1]` |
| 1 | `8,5,2` | `[7,4,1,8,5,2]` |
| 2 | `9,6,3` | `[7,4,1,8,5,2,9,6,3]` |

Then write row-by-row:

```text
[7,4,1]
[8,5,2]
[9,6,3]
```

---

# Important Constraint Issue

The problem asks for an **in-place** rotation.

Your code uses:

```cpp
vector<int> matrixx;
```

This stores all `n²` elements.

Therefore, although you do not create another **2D** matrix, you still use:

```text
O(n²)
```

extra memory.

So your solution is correct in terms of the resulting matrix, but it does **not** satisfy the strict `O(1)` auxiliary-space interpretation of the in-place requirement.

---

# Complexity of Your Solution

The first traversal visits all `n²` elements:

```text
O(n²)
```

The second traversal also visits all `n²` elements:

```text
O(n²)
```

Therefore:

```text
Time Complexity = O(n²)
```

The temporary vector contains `n²` elements:

```text
Auxiliary Space = O(n²)
```

So your solution is:

```text
Time:  O(n²)
Space: O(n²)
```

---

# Standard O(1) In-Place Approach

The usual optimal solution is:

```text
Transpose the matrix
        ↓
Reverse every row
        ↓
90° clockwise rotation
```

For:

```text
1 2 3
4 5 6
7 8 9
```

## Step 1: Transpose

Swap elements across the main diagonal:

```text
1 4 7
2 5 8
3 6 9
```

## Step 2: Reverse Every Row

```text
1 4 7 → 7 4 1
2 5 8 → 8 5 2
3 6 9 → 9 6 3
```

Final:

```text
7 4 1
8 5 2
9 6 3
```

---

# Optimal Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every row
        for(int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

# Your Approach vs Optimal

| Approach | Time | Auxiliary Space | Strict In-Place |
|---|---:|---:|---|
| Your `matrixx` approach | `O(n²)` | `O(n²)` | No |
| Transpose + reverse | `O(n²)` | `O(1)` | Yes |

---

# Key Learning

Your approach gives a very clear understanding of the rotation:

```text
Original column
bottom → top
       ↓
New row
left → right
```

The important mapping is:

```text
new[i][j] = old[n - 1 - j][i]
```

The interview optimization is to perform the same transformation without storing all elements.

Remember:

```text
90° clockwise rotation
        ↓
Transpose
        ↓
Reverse every row
```

---

# Final Complexity

### Your submitted solution

```text
Time:  O(n²)
Space: O(n²)
```

### Optimal in-place solution

```text
Time:  O(n²)
Auxiliary Space: O(1)
```

The key lesson is:

> A solution can produce the correct output while still violating an in-place space constraint.
