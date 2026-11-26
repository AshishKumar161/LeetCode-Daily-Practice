# 3411. Maximum Subarray With Equal Products

**Difficulty:** Easy  
**Topics:** Array, Math, Sliding Window, Enumeration, Number Theory  
**Companies:** Google, Amazon, Goldman Sachs  

---

### Problem Statement

You are given an array of **positive** integers `nums`.

An array `arr` is called **product equivalent** if $\text{prod}(\text{arr}) == \text{lcm}(\text{arr}) \times \text{gcd}(\text{arr})$, where:
- $\text{prod}(\text{arr})$ is the product of all elements of `arr`.
- $\text{gcd}(\text{arr})$ is the Greatest Common Divisor (GCD) of all elements of `arr`.
- $\text{lcm}(\text{arr})$ is the Least Common Multiple (LCM) of all elements of `arr`.

Return the length of the **longest** **product equivalent** subarray of `nums`.

---

### Example 1:
```text
Input: nums = [1,2,1,2,1,1,1]
Output: 5
Explanation:
The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
```

### Example 2:
```text
Input: nums = [2,3,4,5,6]
Output: 3
Explanation:
The longest product equivalent subarray is [3, 4, 5].
```

### Example 3:
```text
Input: nums = [1,2,3,1,4,5,1]
Output: 5
```

---

### Constraints:
- $2 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i] \le 10$