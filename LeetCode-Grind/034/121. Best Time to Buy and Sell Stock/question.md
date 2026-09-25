# LeetCode 121 - Best Time to Buy and Sell Stock

## Question

You are given an array `prices` where `prices[i]` is the price of a stock on the `i`th day.

You want to maximize your profit by choosing a **single day to buy** one stock and choosing a **different day in the future to sell** that stock.

Return the **maximum profit** you can achieve from this transaction.

If you cannot achieve any profit, return `0`.

---

## Example 1

**Input:**
```text
prices = [7,1,5,3,6,4]
```

**Output:**
```text
5
```

**Explanation:**

Buy on day 2 at price `1` and sell on day 5 at price `6`.

```text
profit = 6 - 1 = 5
```

You must buy before you sell.

---

## Example 2

**Input:**
```text
prices = [7,6,4,3,1]
```

**Output:**
```text
0
```

**Explanation:**

The prices continuously decrease, so no profitable transaction is possible.

---

## Constraints

* `1 <= prices.length <= 10^5`
* `0 <= prices[i] <= 10^4`

---

## Topics

* Array
* Dynamic Programming
