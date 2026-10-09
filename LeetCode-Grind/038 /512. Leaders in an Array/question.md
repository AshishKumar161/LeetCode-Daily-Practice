# LeetCode 512 - Leaders in an Array

## Question

Given an integer array `nums`, return a list of all the **leaders** in the array.

A leader is an element whose value is **strictly greater than all elements to its right**. The rightmost element is always a leader.

The leaders must appear in the same order as they appear in `nums`.

## Example 1

**Input**
```text
nums = [1,2,5,3,1,2]
```

**Output**
```text
[5,3,2]
```

**Explanation**

- `2` is the rightmost element, so it is a leader.
- `3` is greater than `[1,2]`.
- `5` is greater than `[3,1,2]`.

## Example 2

**Input**
```text
nums = [-3,4,5,1,-4,-5]
```

**Output**
```text
[5,1,-4,-5]
```

## Topics

- Array
- Traversal
- Searching
- Greedy
