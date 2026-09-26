# LeetCode 54 - Spiral Matrix

## Question

Given an `m x n` matrix, return all elements of the matrix in **spiral order**.

The traversal follows:

```text
left → right
top → bottom
right → left
bottom → top
```

and then repeats for the remaining inner matrix.

## Example 1

**Input**
```text
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]
```

**Output**
```text
[1,2,3,6,9,8,7,4,5]
```

## Example 2

**Input**
```text
matrix = [[1,2,3,4],
          [5,6,7,8],
          [9,10,11,12]]
```

**Output**
```text
[1,2,3,4,8,12,11,10,9,5,6,7]
```

## Topics

- Array
- Matrix
- Simulation
