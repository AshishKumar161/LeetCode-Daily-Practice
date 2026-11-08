# 135. Candy

**Difficulty:** Hard  
**Topics:** Array, Greedy  
**Companies:** Amazon, Google, Microsoft, Apple, Bloomberg, Citadel  

---

### Problem Statement

There are $n$ children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:
1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.

Return the *minimum number of candies you need to have to distribute the candies to the children*.

---

### Example 1:
```text
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second, and third child with 2, 1, 2 candies respectively.
```

### Example 2:
```text
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second, and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
```

---

### Constraints:
- $n == \text{ratings.length}$
- $1 \le n \le 5 \times 10^4$
- $0 \le \text{ratings}[i] \le 5 \times 10^4$