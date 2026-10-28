# 860. Lemonade Change

**LeetCode:** [860. Lemonade Change](https://leetcode.com/problems/lemonade-change/)  
**Difficulty:** Easy  
**Topics:** Array, Greedy

## Problem Statement

At a lemonade stand, each lemonade costs **$5**. Customers stand in a queue and buy one lemonade at a time, in the order given by the integer array `bills`.

Each customer pays with a `$5`, `$10`, or `$20` bill. You must provide the correct change to each customer so that the customer effectively pays exactly `$5`.

Initially, you have no money in your cash register.

Given `bills`, return `true` if you can provide the correct change to every customer; otherwise, return `false`.

## Example 1

**Input:** `bills = [5,5,5,10,20]`  
**Output:** `true`

**Explanation:**
- The first three customers pay with `$5` bills. Keep all three.
- The fourth customer pays `$10`; give back one `$5`.
- The fifth customer pays `$20`; give back one `$10` and one `$5`.
- Every customer receives the correct change.

## Example 2

**Input:** `bills = [5,5,10,10,20]`  
**Output:** `false`

**Explanation:**
- The first two customers pay with `$5` bills.
- The next two customers pay with `$10` bills; each needs `$5` change.
- The last customer pays with `$20` and needs `$15` change, but the register has only two `$10` bills and no `$5` bills. The correct change cannot be provided.

## Visual Representation

Example: `bills = [5,5,5,10,20]`

```text
Customer bill    Change given       Cash after transaction ($5s, $10s)
     5           No change                    (1, 0)
     5           No change                    (2, 0)
     5           No change                    (3, 0)
    10           One $5                       (2, 1)
    20           One $10 + one $5             (1, 0)

Result: true
```

## Constraints

- `1 <= bills.length <= 10^5`
- `bills[i]` is either `5`, `10`, or `20`.

## Function Signature

```cpp
bool lemonadeChange(vector<int>& bills);
```

See `leetcode_860_explanation.md` for the greedy strategy, dry runs, correctness reasoning, and complexity analysis.
