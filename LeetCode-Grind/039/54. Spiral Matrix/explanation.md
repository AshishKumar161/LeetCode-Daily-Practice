# LeetCode 54: Spiral Matrix

## Approach

Your solution uses **four boundaries**:

```cpp
top
bottom
left
right
```

These boundaries describe the part of the matrix that has not been processed yet.

Every round processes four directions:

```text
1. Top row       → left to right
2. Right column  → top to bottom
3. Bottom row    → right to left
4. Left column   → bottom to top
```

After each direction, its boundary moves inward.

## Your Code

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        vector<int> spiral;

        while(top <= bottom && left <= right)
        {
            for(int i = left; i <= right; i++)
            {
                spiral.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++)
            {
                spiral.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom)
            {
                for(int i = right; i >= left; i--)
                {
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right)
            {
                for(int i = bottom; i >= top; i--)
                {
                    spiral.push_back(matrix[i][left]);
                }
            }
            left++;

        }

        return spiral;
    }
};
```

---

# Step 1: Rows and Columns

```cpp
int m = matrix.size();
int n = matrix[0].size();
```

`m` is the number of rows and `n` is the number of columns.

For:

```text
[1 2 3]
[4 5 6]
[7 8 9]
```

we have:

```text
m = 3
n = 3
```

---

# Step 2: Four Boundaries

```cpp
int top = 0;
int bottom = m - 1;
int left = 0;
int right = n - 1;
```

Initially:

```text
top = 0
bottom = 2
left = 0
right = 2
```

They represent the current rectangle.

```text
top
 ↓
[1 2 3] ← right
[4 5 6]
[7 8 9]
 ↑
left

bottom = 2
```

Meaning:

```text
top    → first active row
bottom → last active row
left   → first active column
right  → last active column
```

---

# Step 3: Main Loop

```cpp
while(top <= bottom && left <= right)
```

Continue while there is at least one active row and one active column.

---

# Direction 1: Top Row

```cpp
for(int i = left; i <= right; i++)
{
    spiral.push_back(matrix[top][i]);
}
top++;
```

For the first round:

```text
1 2 3
```

is added.

Answer:

```text
[1,2,3]
```

Then:

```cpp
top++;
```

changes:

```text
top = 0 → 1
```

The first row is finished.

---

# Direction 2: Right Column

```cpp
for(int i = top; i <= bottom; i++)
{
    spiral.push_back(matrix[i][right]);
}
right--;
```

Now we move downward along the right column.

The top element `3` has already been processed, so the loop starts at `top`.

We add:

```text
6
9
```

Answer:

```text
[1,2,3,6,9]
```

Then:

```cpp
right--;
```

changes:

```text
right = 2 → 1
```

---

# Direction 3: Bottom Row

```cpp
if(top <= bottom)
{
    for(int i = right; i >= left; i--)
    {
        spiral.push_back(matrix[bottom][i]);
    }
    bottom--;
}
```

The bottom row is traversed from:

```text
right → left
```

We add:

```text
8
7
```

Answer:

```text
[1,2,3,6,9,8,7]
```

Then:

```cpp
bottom--;
```

changes:

```text
bottom = 2 → 1
```

---

# Direction 4: Left Column

```cpp
if(left <= right)
{
    for(int i = bottom; i >= top; i--)
    {
        spiral.push_back(matrix[i][left]);
    }
}
left++;
```

We move:

```text
bottom → top
```

and add:

```text
4
```

Answer:

```text
[1,2,3,6,9,8,7,4]
```

Then:

```cpp
left++;
```

changes:

```text
left = 0 → 1
```

The outer layer is complete.

---

# Second Layer

The remaining matrix is:

```text
[5]
```

Now:

```text
top = 1
bottom = 1
left = 1
right = 1
```

The loop still runs.

The top-row traversal adds:

```text
5
```

Final:

```text
[1,2,3,6,9,8,7,4,5]
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

### Initial

```text
top = 0
bottom = 2
left = 0
right = 2
```

### Round 1

Top:

```text
1,2,3
```

Right:

```text
6,9
```

Bottom:

```text
8,7
```

Left:

```text
4
```

Answer:

```text
[1,2,3,6,9,8,7,4]
```

Boundaries become:

```text
top = 1
bottom = 1
left = 1
right = 1
```

### Round 2

Top:

```text
5
```

Final:

```text
[1,2,3,6,9,8,7,4,5]
```

---

# Boundary Updates

Remember these four updates:

```cpp
top++;
right--;
bottom--;
left++;
```

They mean:

```text
top++    → remove top row
right--  → remove right column
bottom-- → remove bottom row
left++   → remove left column
```

So each round shrinks the active rectangle.

---

# Why Are `if` Conditions Needed?

These checks prevent duplicate processing when only one row or one column remains:

```cpp
if(top <= bottom)
```

and:

```cpp
if(left <= right)
```

For example, after processing a single remaining row, there should not be another attempt to process that same row as the bottom row.

---

# Important Issue in Your Exact Code

Your approach is correct, but the exact code shown has one boundary-safety issue.

The right-column traversal is unconditional:

```cpp
for(int i = top; i <= bottom; i++)
{
    spiral.push_back(matrix[i][right]);
}
```

For a **single-column matrix**, `right` can become invalid after the top-row traversal.

For example:

```text
[
 [1],
 [2],
 [3]
]
```

After processing `1`:

```text
top = 1
right = -1
```

The next loop can attempt:

```cpp
matrix[i][-1]
```

which is invalid.

## Safe Version

Keep your same approach, but protect the right-column traversal:

```cpp
if(left <= right)
{
    for(int i = top; i <= bottom; i++)
    {
        spiral.push_back(matrix[i][right]);
    }
    right--;
}
```

A fully safe version is:

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        vector<int> spiral;

        while(top <= bottom && left <= right)
        {
            for(int i = left; i <= right; i++)
            {
                spiral.push_back(matrix[top][i]);
            }
            top++;

            if(left <= right)
            {
                for(int i = top; i <= bottom; i++)
                {
                    spiral.push_back(matrix[i][right]);
                }
                right--;
            }

            if(top <= bottom)
            {
                for(int i = right; i >= left; i--)
                {
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right)
            {
                for(int i = bottom; i >= top; i--)
                {
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return spiral;
    }
};
```

This is the same boundary approach with the missing guard added.

---

# Example 2

```text
[
 [1,2,3,4],
 [5,6,7,8],
 [9,10,11,12]
]
```

Traversal:

```text
1 → 2 → 3 → 4
              ↓
5             8
↑             ↓
9 ← 10 ← 11 ← 12
```

Then the inner remaining part is:

```text
[6,7]
```

The final result is:

```text
[1,2,3,4,8,12,11,10,9,5,6,7]
```

---

# Complexity Analysis

If the matrix has `m` rows and `n` columns, it contains:

```text
m × n
```

elements.

Every element is visited once.

Therefore:

```text
Time = O(m × n)
```

The returned vector contains all elements:

```text
Output Space = O(m × n)
```

Apart from the output, only the four boundaries and loop variables are used:

```text
Auxiliary Space = O(1)
```

Therefore:

```text
Time: O(mn)
Auxiliary Space: O(1)
Output Space: O(mn)
```

---

# Key Learning

This problem teaches the **Boundary Simulation** pattern.

Instead of using a visited matrix, maintain:

```text
top
bottom
left
right
```

and repeatedly traverse:

```text
→ top
↓ right
← bottom
↑ left
```

Then shrink the boundaries.

Think:

```text
TOP    → right
RIGHT  → down
BOTTOM → left
LEFT   → up
```

---

# Pattern to Remember

```cpp
while(top <= bottom && left <= right)
{
    // top: left → right

    // right: top → bottom

    // bottom: right → left

    // left: bottom → top

    // shrink boundaries
}
```

The four boundary changes are:

```cpp
top++;
right--;
bottom--;
left++;
```

---

# Final Complexity

| Metric | Complexity |
|---|---:|
| Time | `O(m × n)` |
| Auxiliary Space | `O(1)` |
| Output Space | `O(m × n)` |

For your approach:

```text
Four boundaries
      ↓
Four directions
      ↓
Shrink boundaries
      ↓
Repeat
```
