
# LeetCode 1752: Check if Array Is Sorted and Rotated

## Problem

Given an array `nums`, return `true` if the array was originally sorted in **non-decreasing order**, then rotated some number of positions, including zero.

Otherwise, return `false`.

There may be **duplicates** in the original array.

A rotation by `x` positions means that the element at index `i` in the rotated array comes from index `(i + x) % nums.length` in the original array.

---

## Example 1

**Input:**

```text
nums = [3,4,5,1,2]
```

**Output:**

```text
true
```

**Explanation:**

The original sorted array is:

```text
[1,2,3,4,5]
```

It can be rotated to obtain:

```text
[3,4,5,1,2]
```

---

## Example 2

**Input:**

```text
nums = [2,1,3,4]
```

**Output:**

```text
false
```

**Explanation:**

There is no non-decreasing sorted array that can be rotated to obtain `nums`.

---

## Example 3

**Input:**

```text
nums = [1,2,3]
```

**Output:**

```text
true
```

**Explanation:**

The array is already sorted.

A rotation of `0` positions is allowed.

---

## Example 4

**Input:**

```text
nums = [1,1,1]
```

**Output:**

```text
true
```

**Explanation:**

The array is already sorted, and duplicates are allowed.

---

## Example 5

**Input:**

```text
nums = [2,1]
```

**Output:**

```text
true
```

**Explanation:**

The original sorted array is:

```text
[1,2]
```

Rotating it can produce:

```text
[2,1]
```

---

## Constraints

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Topics

* Array
* Rotation
* In-Place Algorithm
