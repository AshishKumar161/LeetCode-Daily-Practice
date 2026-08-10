
# 82. Remove Duplicates from Sorted List II

## Problem Statement

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

---

## Example 1

### Input

```text
[1,2,3,3,4,4,5]
```

### Output

```text
[1,2,5]
```

### Explanation

The values `3` and `4` appear more than once, so all nodes containing
`3` and `4` are removed.

Only `1`, `2`, and `5` remain.

---

## Example 2

### Input

```text
[1,1,1,2,3]
```

### Output

```text
[2,3]
```

### Explanation

The value `1` appears three times, so all nodes containing `1`
are removed.

---

## Constraints

- The number of nodes is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is sorted in non-decreasing order.
