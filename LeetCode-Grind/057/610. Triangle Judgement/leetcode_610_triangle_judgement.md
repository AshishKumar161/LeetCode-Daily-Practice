# LeetCode 610 — Triangle Judgement

## Problem

Given a table `Triangle` with columns:

```text
x | y | z
```

Each row contains the lengths of three line segments.

For every row, determine whether the three segments can form a triangle.

## Triangle Condition

Three side lengths form a valid triangle only when all three conditions are true:

```text
x + y > z
x + z > y
y + z > x
```

## SQL Solution

```sql
SELECT
    x,
    y,
    z,
    CASE
        WHEN x + y > z
         AND y + z > x
         AND x + z > y
        THEN 'Yes'
        ELSE 'No'
    END AS triangle
FROM Triangle;
```

## Explanation

`CASE` works like an `if-else` statement in SQL.

```sql
CASE
    WHEN condition
    THEN 'Yes'
    ELSE 'No'
END
```

The query checks the three **triangle inequalities**.

### Example 1

```text
x = 13
y = 15
z = 30
```

Check:

```text
13 + 15 > 30
28 > 30
```

This is false, so the result is:

```text
No
```

### Example 2

```text
x = 10
y = 20
z = 15
```

Check:

```text
10 + 20 > 15  → TRUE
10 + 15 > 20  → TRUE
20 + 15 > 10  → TRUE
```

All three are true, so:

```text
Yes
```

## Important SQL Concepts

### `CASE`

Used for conditional output:

```sql
CASE
    WHEN condition
    THEN 'Yes'
    ELSE 'No'
END
```

### `AND`

All conditions connected with `AND` must be true:

```sql
condition1
AND condition2
AND condition3
```

If even one condition is false, the answer is `No`.

## Complexity

For each row, only a constant number of comparisons is performed.

```text
Time Complexity  : O(n)
Space Complexity : O(1) extra
```

where `n` is the number of rows.

## Key Takeaway

Remember the triangle inequality:

```text
a + b > c
a + c > b
b + c > a
```

SQL pattern:

```sql
CASE
    WHEN x + y > z
     AND y + z > x
     AND x + z > y
    THEN 'Yes'
    ELSE 'No'
END
```
