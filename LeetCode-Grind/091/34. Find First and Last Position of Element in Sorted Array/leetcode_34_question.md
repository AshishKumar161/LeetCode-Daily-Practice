# 34. Find First and Last Position of Element in Sorted Array

**Difficulty:** Medium  
**Topics:** Array, Binary Search  
**Companies:** Amazon, Meta, Microsoft, Google, Bloomberg, Apple, LinkedIn  

---

### Problem Statement

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with $\mathcal{O}(\log n)$ runtime complexity.

---

### Example 1:
```text
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

### Example 2:
```text
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

### Example 3:
```text
Input: nums = [], target = 0
Output: [-1,-1]
```

---

### Constraints:
- $0 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$
- `nums` is a non-decreasing array.
- $-10^9 \le \text{target} \le 10^9$