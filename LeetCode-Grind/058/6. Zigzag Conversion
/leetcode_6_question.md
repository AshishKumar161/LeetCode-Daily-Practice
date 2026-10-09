# 6. Zigzag Conversion

**LeetCode:** [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)  
**Difficulty:** Medium  
**Topics:** String, Simulation

## Problem Statement

Given a string `s`, write its characters in a zigzag pattern across `numRows` rows, then read the rows from top to bottom to create the converted string.

For example, when `s = "PAYPALISHIRING"` and `numRows = 3`, the pattern is:

```text
P   A   H   N
A P L S I I G
Y   I   R
```

Reading each row from left to right gives:

```text
PAHNAPLSIIGYIR
```

Implement `string convert(string s, int numRows)`.

## Examples

### Example 1

**Input**
```text
s = "PAYPALISHIRING", numRows = 3
```

**Output**
```text
"PAHNAPLSIIGYIR"
```

### Example 2

**Input**
```text
s = "PAYPALISHIRING", numRows = 4
```

**Output**
```text
"PINALSIGYAHRPI"
```

The zigzag arrangement is:

```text
P     I    N
A   L S  I G
Y A   H R
P     I
```

### Example 3

**Input**
```text
s = "A", numRows = 1
```

**Output**
```text
"A"
```

## Constraints

- `1 <= s.length <= 1000`
- `s` consists of English letters (lowercase and uppercase), `,` and `.`.
- `1 <= numRows <= 1000`

## Approach

Simulate the zigzag movement using one string for each row.

1. If there is only one row, or the number of rows is at least the string length, no rearrangement is needed. Return `s`.
2. Create `numRows` empty strings in a vector named `rows`.
3. Start at row `0` and move downward (`down = true`).
4. For every character:
   - Append it to `rows[row]`.
   - If the current row is the last row, change direction to upward.
   - If the current row is the first row, change direction to downward.
   - Move one row in the current direction.
5. Concatenate the row strings from top to bottom and return the result.

## C++ Solution

See the accompanying [`solution.md`](solution.md) for the fully commented implementation, dry run, and complexity analysis.
