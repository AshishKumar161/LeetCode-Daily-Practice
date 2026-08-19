
# LeetCode 189: Rotate Array

## Problem

Given an integer array `nums`, rotate the array to the **right by `k` steps**, where `k` is non-negative.

A right rotation by one position moves the last element to the first position.

The operation must be performed **in-place**, meaning the original array should be modified without creating another array.

---

## Example 1

**Input:**

```text
nums = [1,2,3,4,5,6,7], k = 3
```

**Output:**

```text
[5,6,7,1,2,3,4]
```

**Explanation:**

Rotate 1 step to the right:

```text
[7,1,2,3,4,5,6]
```

Rotate 2 steps to the right:

```text
[6,7,1,2,3,4,5]
```

Rotate 3 steps to the right:

```text
[5,6,7,1,2,3,4]
```

---

## Example 2

**Input:**

```text
nums = [-1,-100,3,99], k = 2
```

**Output:**

```text
[3,99,-1,-100]
```

**Explanation:**

Rotate 1 step to the right:

```text
[99,-1,-100,3]
```

Rotate 2 steps to the right:

```text
[3,99,-1,-100]
```

---

## Constraints

* `1 <= nums.length <= 10^5`
* `-2^31 <= nums[i] <= 2^31 - 1`
* `0 <= k <= 10^5`

---

## Follow-Up

* Can you solve the problem using different approaches?
* Can you perform the rotation **in-place** using `O(1)` extra space?

---

## Topics

* Array
* Two Pointers
* In-Place Algorithm
* Array Rotation
