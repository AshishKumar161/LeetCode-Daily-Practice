
# LeetCode 26: Remove Duplicates from Sorted Array

## Problem

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **in-place** such that each unique element appears only once.

The relative order of the elements should remain the same.

Return the number of unique elements in `nums`.

Let the number of unique elements be `k`.

After removing the duplicates:

* The first `k` elements of `nums` should contain all unique elements in sorted order.
* The elements beyond index `k - 1` can be ignored.

---

## Example 1

**Input:**

```text
nums = [1,1,2]
```

**Output:**

```text
2
```

**Explanation:**

The unique elements are:

```text
[1,2]
```

So the first `2` elements of `nums` should be:

```text
[1,2]
```

---

## Example 2

**Input:**

```text
nums = [0,0,1,1,1,2,2,3,3,4]
```

**Output:**

```text
5
```

**Explanation:**

The unique elements are:

```text
[0,1,2,3,4]
```

So the first `5` elements of `nums` should be:

```text
[0,1,2,3,4]
```

The remaining elements can be ignored.

---

## Constraints

* `1 <= nums.length <= 3 * 10^4`
* `-100 <= nums[i] <= 100`
* `nums` is sorted in **non-decreasing order**.

---

## Topics

* Array
* Two Pointers
* In-Place Algorithm
