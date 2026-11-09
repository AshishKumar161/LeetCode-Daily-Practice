# 704. Binary Search

**Difficulty:** Easy  
**Topics:** Array, Binary Search  
**Companies:** Amazon, Microsoft, Apple, Google, Meta, Bloomberg  

---

### Problem Statement

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with $\mathcal{O}(\log n)$ runtime complexity.

---

### Example 1:
```text
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

### Example 2:
```text
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

---

### Constraints:
- $1 \le \text{nums.length} \le 10^4$
- $-10^4 < \text{nums}[i], \text{target} < 10^4$
- All the integers in `nums` are **unique**.
- `nums` is sorted in ascending order.