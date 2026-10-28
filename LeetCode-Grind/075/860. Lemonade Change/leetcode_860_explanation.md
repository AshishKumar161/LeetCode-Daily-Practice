# 860. Lemonade Change — Code Explanation

**LeetCode:** [860. Lemonade Change](https://leetcode.com/problems/lemonade-change/)  
**Language:** C++

## Solution Code

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int Five = 0;
        int Ten = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                Five++;
            }
            else if (bills[i] == 10) {
                if (Five) {
                    Five--;
                    Ten++;
                }
                else {
                    return false;
                }
            }
            else { // bills[i] == 20
                if (Five && Ten) {
                    Ten--;
                    Five--;
                }
                else if (Five >= 3) {
                    Five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
```

## 1. Main Idea: Greedy

A lemonade costs `$5`, so:
- A customer paying `$5` needs no change.
- A customer paying `$10` needs `$5` change.
- A customer paying `$20` needs `$15` change.

Track only the change bills that can be useful:
- `Five`: number of `$5` bills available.
- `Ten`: number of `$10` bills available.

We do not need to track `$20` bills because they cannot be used to give change to later customers.

## 2. Explain Each Branch

### Case A: Customer pays `$5`

```cpp
if (bills[i] == 5) {
    Five++;
}
```

No change is required. Keep the `$5` bill, so `Five` increases by one.

### Case B: Customer pays `$10`

```cpp
else if (bills[i] == 10) {
    if (Five) {
        Five--;
        Ten++;
    }
    else {
        return false;
    }
}
```

The customer needs `$5` change. If a `$5` bill is available, give it to the customer and keep the received `$10` bill. If no `$5` bill is available, return `false` immediately.

### Case C: Customer pays `$20`

The customer needs `$15` change. There are two possible combinations:

1. One `$10` bill plus one `$5` bill.
2. Three `$5` bills.

```cpp
if (Five && Ten) {
    Ten--;
    Five--;
}
else if (Five >= 3) {
    Five -= 3;
}
else {
    return false;
}
```

**Why prefer `$10 + $5`?** Preserve three `$5` bills when possible. A future `$10` customer must receive a `$5` bill, while a `$20` customer can be handled with a `$10` and a `$5`. Using the `$10 + $5` combination preserves more small bills for future transactions.

If neither combination is possible, the correct change cannot be given, so return `false`.

## 3. Dry Run — Example 1

Input: `bills = [5,5,5,10,20]`

`Five` and `Ten` both start at `0`.

| Customer | Bill received | Action | Five after | Ten after |
|---:|---:|---|---:|---:|
| 1 | `$5` | Keep the bill | 1 | 0 |
| 2 | `$5` | Keep the bill | 2 | 0 |
| 3 | `$5` | Keep the bill | 3 | 0 |
| 4 | `$10` | Give `$5`; keep `$10` | 2 | 1 |
| 5 | `$20` | Give `$10 + $5` | 1 | 0 |

All customers receive correct change, so the function returns `true`.

## 4. Dry Run — Example 2

Input: `bills = [5,5,10,10,20]`

| Customer | Bill received | Action | Five after | Ten after |
|---:|---:|---|---:|---:|
| 1 | `$5` | Keep the bill | 1 | 0 |
| 2 | `$5` | Keep the bill | 2 | 0 |
| 3 | `$10` | Give `$5`; keep `$10` | 1 | 1 |
| 4 | `$10` | Give `$5`; keep `$10` | 0 | 2 |
| 5 | `$20` | Cannot make `$15` change | 0 | 2 |

At the last customer, there is no `$5` bill and fewer than three `$5` bills. Two `$10` bills cannot make `$15` change. The function returns `false`.

## 5. Why the Greedy Choice Works

When a customer pays `$20`, use one `$10` and one `$5` whenever both are available. This uses a larger bill and preserves as many `$5` bills as possible. The `$5` bill is especially valuable because every `$10` customer requires one `$5` in change.

If a `$10` bill is unavailable, three `$5` bills are the only remaining way to make `$15`. If neither option is possible, no valid change combination exists with the bills in the register, so returning `false` is correct.

## 6. Complexity Analysis

Let `n = bills.size()`.

- **Time complexity:** `O(n)` — process each customer once.
- **Auxiliary space:** `O(1)` — only two counters are maintained.

## 7. Common Mistakes

- Do not start with any change in the register; both counters start at zero.
- For a `$10` bill, you must have a `$5` bill.
- For a `$20` bill, valid change is `$10 + $5` or `$5 + $5 + $5`.
- Prefer `$10 + $5` when possible to preserve `$5` bills.
- Return `false` immediately when the required change cannot be made.
- Return `true` only after processing every customer successfully.

## Summary

Track the number of `$5` and `$10` bills. Handle each customer in queue order and choose change greedily. The algorithm runs in `O(n)` time and `O(1)` auxiliary space.
