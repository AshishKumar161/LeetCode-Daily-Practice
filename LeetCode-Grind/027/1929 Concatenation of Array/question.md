# LeetCode 1929 - Concatenation of Array

## Question

Given an integer array `nums` of length `n`, create an array `ans` of length `2n` where:

```text
ans[i] == nums[i]
ans[i + n] == nums[i]
```

for `0 <= i < n`.

In other words, `ans` is the concatenation of `nums` with itself.

---

## Example 1

**Input:**

```text
nums = [1,2,1]
```

**Output:**

```text
[1,2,1,1,2,1]
```

**Explanation:**

The array `ans` is formed as follows:

```text
ans = [nums[0], nums[1], nums[2], nums[0], nums[1], nums[2]]
ans = [1,2,1,1,2,1]
```

---

## Example 2

**Input:**

```text
nums = [1,3,2,1]
```

**Output:**

```text
[1,3,2,1,1,3,2,1]
```

**Explanation:**

The original array is copied twice:

```text
nums = [1,3,2,1]

ans = [1,3,2,1,1,3,2,1]
```

---

## Constraints

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`

---

## Topics

* Array
