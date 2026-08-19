
# LeetCode 283: Move Zeroes

## Problem

Given an integer array `nums`, move all `0`s to the end of the array while maintaining the relative order of all non-zero elements.

The operation must be performed **in-place**, which means you should modify the existing array without creating a copy of it.

---

## Example 1

**Input:**

```text
nums = [0,1,0,3,12]
```

**Output:**

```text
[1,3,12,0,0]
```

**Explanation:**

All zeroes are moved to the end while the relative order of the non-zero elements remains unchanged:

```text
1 → 3 → 12
```

---

## Example 2

**Input:**

```text
nums = [0]
```

**Output:**

```text
[0]
```

---

## Constraints

* `1 <= nums.length <= 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`

---

## Follow-up

Can you minimize the total number of operations performed?

---

## Topics

* Array
* Two Pointers
* In-Place Algorithm
