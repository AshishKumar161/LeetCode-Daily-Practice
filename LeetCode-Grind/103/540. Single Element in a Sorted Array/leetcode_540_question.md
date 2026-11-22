# 540. Single Element in a Sorted Array

**Difficulty:** Medium  
**Topics:** Array, Binary Search  
**Companies:** Amazon, Google, Meta, Microsoft, Bloomberg, Apple  

---

### Problem Statement

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return *the single element that appears only once*.

Your solution must run in $\mathcal{O}(\log n)$ time and $\mathcal{O}(1)$ space.

---

### Example 1:
```text
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```

### Example 2:
```text
Input: nums = [3,3,7,7,10,11,11]
Output: 10
```

---

### Constraints:
- $1 \le \text{nums.length} \le 10^5$
- $0 \le \text{nums}[i] \le 10^5$