# 1352. Product of the Last K Numbers

**Difficulty:** Medium  
**Topics:** Array, Math, Design, Data Stream, Prefix Sum  
**Companies:** Google, Amazon, Meta, Apple, Microsoft  

---

### Problem Summary

Design a data structure that processes a continuous stream of integers and supports querying the product of the most recent $k$ integers added to the stream.

Implement the `ProductOfNumbers` class with the following methods:
- `ProductOfNumbers()`: Initializes the data structure with an empty integer stream.
- `void add(int num)`: Appends the integer `num` to the end of the stream.
- `int getProduct(int k)`: Returns the product of the last `k` integers in the stream. Every call guarantees that at least `k` numbers have already been added.

All test cases guarantee that the product of any contiguous subsequence of elements fits inside a 32-bit signed integer without overflowing.

---

### Example:
```text
Input:
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output:
[null,null,null,null,null,null,20,40,0,null,32]

Explanation:
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // stream: [3]
productOfNumbers.add(0);        // stream: [3, 0]
productOfNumbers.add(2);        // stream: [3, 0, 2]
productOfNumbers.add(5);        // stream: [3, 0, 2, 5]
productOfNumbers.add(4);        // stream: [3, 0, 2, 5, 4]
productOfNumbers.getProduct(2); // returns 20 (5 * 4)
productOfNumbers.getProduct(3); // returns 40 (2 * 5 * 4)
productOfNumbers.getProduct(4); // returns 0  (0 * 2 * 5 * 4)
productOfNumbers.add(8);        // stream: [3, 0, 2, 5, 4, 8]
productOfNumbers.getProduct(2); // returns 32 (4 * 8)
```

---

### Constraints:
- $0 \le \text{num} \le 100$
- $1 \le k \le 4 \times 10^4$
- At most $4 \times 10^4$ total calls will be made to `add` and `getProduct`.
- The product of any contiguous sequence of elements fits within a 32-bit signed integer.