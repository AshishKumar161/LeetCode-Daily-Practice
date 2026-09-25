# LeetCode 268 - Missing Number

## Question

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## Example 1

**Input:**
```text
nums = [3,0,1]
```

**Output:**
```text
2
```

**Explanation:**

There are `n = 3` numbers, so the complete range is:

```text
[0,1,2,3]
```

`2` does not appear in `nums`.

## Example 2

**Input:**
```text
nums = [0,1]
```

**Output:**
```text
2
```

Here `n = 2`, so the range is `[0,2]`, and `2` is missing.

## Example 3

**Input:**
```text
nums = [9,6,4,2,3,5,7,0,1]
```

**Output:**
```text
8
```

## Constraints

* `n == nums.length`
* `1 <= n <= 10^4`
* `0 <= nums[i] <= n`
* All numbers are unique.

## Topics

* Array
* Hash Table
* Math
* Sorting
* Bit Manipulation
