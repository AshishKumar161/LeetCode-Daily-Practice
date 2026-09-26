# LeetCode 2149 - Rearrange Array Elements by Sign

## Question

You are given a 0-indexed integer array `nums` of even length containing an equal number of positive and negative integers.

Return the array after rearranging it so that:

1. Every consecutive pair has opposite signs.
2. The relative order of integers with the same sign is preserved.
3. The array begins with a positive integer.

## Example 1

**Input:**
```text
nums = [3,1,-2,-5,2,-4]
```

**Output:**
```text
[3,-2,1,-5,2,-4]
```

The positive integers are `[3,1,2]` and the negative integers are `[-2,-5,-4]`. They are then placed alternately.

## Constraints

* `2 <= nums.length <= 2 * 10^5`
* `nums.length` is even.
* There are equal numbers of positive and negative integers.
* `nums[i] != 0`.

## Topics

* Array
* Two Pointers
* Simulation
