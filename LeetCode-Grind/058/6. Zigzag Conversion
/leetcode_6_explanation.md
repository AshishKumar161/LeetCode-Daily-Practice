# Zigzag Conversion — Solution and Explanation

**LeetCode:** [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)  
**Language:** C++  
**Approach:** Simulation using row strings

## Code

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        // No zigzag movement is needed in these cases.
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        // Each element stores the characters for one row.
        vector<string> rows(numRows);

        int row = 0;
        bool down = true;

        for (char ch : s) {
            // Put the current character in the current row.
            rows[row] += ch;

            // Reverse direction at the bottom.
            if (row == numRows - 1) {
                down = false;
            }

            // Reverse direction at the top.
            if (row == 0) {
                down = true;
            }

            // Move to the next row.
            if (down) {
                row++;
            } else {
                row--;
            }
        }

        // Read all rows from top to bottom.
        string ans = "";
        for (string r : rows) {
            ans += r;
        }

        return ans;
    }
};
```

## Logic Explained

### 1. Handle the special cases

```cpp
if (numRows == 1 || numRows >= s.size()) {
    return s;
}
```

- With one row, every character stays in the same row.
- If `numRows` is at least the string length, there are not enough characters to form a downward-and-upward zigzag. The original string is already the answer.

### 2. Create the rows

```cpp
vector<string> rows(numRows);
```

This creates `numRows` empty strings. `rows[0]` is the first row, `rows[1]` the second row, and so on.

### 3. Track the current row and direction

```cpp
int row = 0;
bool down = true;
```

- `row` is the row where the next character will be placed.
- `down == true` means move toward the bottom.
- `down == false` means move toward the top.

### 4. Place each character and change direction at boundaries

```cpp
rows[row] += ch;

if (row == numRows - 1) {
    down = false;
}

if (row == 0) {
    down = true;
}
```

First, the character is added to the current row. At the bottom row, movement must reverse upward. At the top row, movement must reverse downward.

**Why `numRows - 1`?** Vector indices begin at `0`. For `numRows = 3`, the valid row indices are `0`, `1`, and `2`; therefore, the last row is `3 - 1 = 2`.

### 5. Move to the next row

```cpp
if (down) {
    row++;
} else {
    row--;
}
```

Move down by increasing the row index, or up by decreasing it. The direction checks happen after adding the character, so the character is placed before the next movement.

### 6. Read the rows

```cpp
string ans = "";
for (string r : rows) {
    ans += r;
}
return ans;
```

The problem asks for the rows to be read from top to bottom. Concatenating the row strings in vector order produces the required converted string.

## Dry Run

Use `s = "PAYPALISHIRING"` and `numRows = 3`.

The row indices are `0`, `1`, and `2`. The direction changes at rows `2` and `0`.

| Character | Row receiving it | Rows after placement (`row 0 / row 1 / row 2`) | Next direction |
|---|---:|---|---|
| `P` | 0 | `P / "" / ""` | Down |
| `A` | 1 | `P / A / ""` | Down |
| `Y` | 2 | `P / A / Y` | Up |
| `P` | 1 | `P / AP / Y` | Up |
| `A` | 0 | `PA / AP / Y` | Down |
| `L` | 1 | `PA / APL / Y` | Down |
| `I` | 2 | `PA / APL / YI` | Up |
| `S` | 1 | `PA / APLS / YI` | Up |
| `H` | 0 | `PAH / APLS / YI` | Down |
| `I` | 1 | `PAH / APLSI / YI` | Down |
| `R` | 2 | `PAH / APLSI / YIR` | Up |
| `I` | 1 | `PAH / APLSII / YIR` | Up |
| `N` | 0 | `PAHN / APLSII / YIR` | Down |
| `G` | 1 | `PAHN / APLSIIG / YIR` | Down |

The final row strings are:

```text
Row 0: PAHN
Row 1: APLSIIG
Row 2: YIR
```

Concatenate them:

```text
PAHN + APLSIIG + YIR = PAHNAPLSIIGYIR
```

**Output:** `"PAHNAPLSIIGYIR"`

## Complexity Analysis

Let `n` be the length of `s` and `r` be `numRows`.

- **Time complexity: `O(n)`** — each character is visited once, placed into a row once, and then included in the final answer. The total row content is `n` characters.
- **Auxiliary space complexity: `O(n + r)`** — the row strings collectively store `n` characters, and the vector contains `r` string objects. The returned answer also uses `O(n)` space.

Since `r <= n` in the non-early-return case, the auxiliary space is commonly simplified to **`O(n)`**.

## Common Mistakes

- **Using `row == numRows` as the bottom check:** invalid, because the last valid index is `numRows - 1`.
- **Changing direction before placing the character:** can make the character go into the wrong row. Place it first, then check the boundary.
- **Forgetting the top boundary:** without setting `down = true` at row `0`, the row index could become negative.
- **Returning rows in the wrong order:** append `rows[0]`, then `rows[1]`, and continue to the last row.

## Key Takeaway

This is a simulation problem. You do not need to build a 2D zigzag matrix: keep one string per row, track the direction, and concatenate the rows at the end.
