# LeetCode 169 - Majority Element

## Question

Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than `⌊n / 2⌋` times**.

You may assume that the majority element always exists in the array.

---

## Example 1

**Input:**
```text
nums = [3,2,3]
```

**Output:**
```text
3
```

The number `3` appears 2 times, which is more than:

```text
⌊3 / 2⌋ = 1
```

---

## Example 2

**Input:**
```text
nums = [2,2,1,1,1,2,2]
```

**Output:**
```text
2
```

The number `2` appears 4 times, which is more than:

```text
⌊7 / 2⌋ = 3
```

---

## Constraints

* `n == nums.length`
* `1 <= n <= 5 * 10^4`
* `-10^9 <= nums[i] <= 10^9`
* The majority element always exists in the array.

---

## Topics

* Array
* Hash Table
* Divide and Conquer
* Sorting
* Counting
