# LeetCode 121: Best Time to Buy and Sell Stock

## Approach

We solve this problem using a **single traversal** with two important values:

```cpp
int profit = 0;
int min_profit = arr[0];
```

Conceptually:

```text
min_profit → minimum stock price seen so far
profit     → maximum profit found so far
```

For every price:

1. Update the minimum price seen so far.
2. Calculate the profit if we sell at the current price.
3. Keep the maximum profit.

The core idea is:

```text
Cheapest buying price seen so far
            +
Current selling price
            =
Possible profit
```

---

## Important Observation

For every selling day, the best possible buying price is the **minimum price seen before that day**.

For:

```text
prices = [7,1,5,3,6,4]
```

when we reach price `6`, the cheapest price seen before it is:

```text
1
```

Therefore:

```text
profit = 6 - 1
       = 5
```

We do not need to test every possible buy/sell pair.

---

## Intuition

We scan from left to right.

```text
prices = [7,1,5,3,6,4]
```

Track:

```text
minimum price
maximum profit
```

The important changes are:

```text
7 → minimum = 7
1 → minimum = 1
5 → profit = 5 - 1 = 4
3 → profit = 3 - 1 = 2
6 → profit = 6 - 1 = 5
4 → profit = 4 - 1 = 3
```

The maximum profit is:

```text
5
```

---

## Algorithm

1. Initialize:
   ```cpp
   int profit = 0;
   int min_profit = arr[0];
   ```

2. Traverse the array from left to right.

3. Update the minimum price:
   ```cpp
   min_profit = min(arr[i], min_profit);
   ```

4. Calculate the profit if selling at the current price:
   ```cpp
   arr[i] - min_profit
   ```

5. Keep the largest profit:
   ```cpp
   profit = max(profit, arr[i] - min_profit);
   ```

6. Return `profit`.

---

## Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0;
        int min_profit = arr[0];

        for(int i = 0; i < arr.size(); i++)
        {
            min_profit = min(arr[i], min_profit);
            profit = max(profit, arr[i] - min_profit);
        }

        return profit;
    }
};
```

---

## Code Explanation

### Initialize `profit`

```cpp
int profit = 0;
```

`profit` stores the maximum profit found so far.

We start at `0` because if no profitable transaction exists, the required answer is `0`.

---

### Initialize the Minimum Price

```cpp
int min_profit = arr[0];
```

Despite the variable name `min_profit`, this variable actually stores the **minimum stock price seen so far**.

A clearer name would be:

```cpp
int min_price = arr[0];
```

The algorithm is the same.

For:

```text
prices = [7,1,5,3,6,4]
```

initially:

```text
min_profit = 7
```

Later it becomes:

```text
1
```

because `1` is the cheapest price encountered.

---

### Traverse the Array

```cpp
for(int i = 0; i < arr.size(); i++)
```

We process each price exactly once.

At every day, we ask:

```text
What is the cheapest price available before/by this point?
```

and:

```text
If I sell today, what profit would I get?
```

---

### Update the Minimum Price

```cpp
min_profit = min(arr[i], min_profit);
```

This keeps the smallest price seen so far.

Example:

```text
min_profit = 7
arr[i] = 1
```

Then:

```text
min(1,7) = 1
```

So:

```text
min_profit = 1
```

Later:

```text
arr[i] = 5
```

gives:

```text
min(5,1) = 1
```

The minimum remains `1`.

---

### Calculate Current Profit

```cpp
arr[i] - min_profit
```

If today's price is `6` and the minimum price is `1`:

```text
current profit = 6 - 1
               = 5
```

This represents buying at the cheapest price seen so far and selling today.

---

### Update Maximum Profit

```cpp
profit = max(profit, arr[i] - min_profit);
```

We compare:

```text
profit
```

with:

```text
current profit
```

and keep the larger value.

For example:

```text
profit = 4
current profit = 5
```

then:

```text
profit = 5
```

If:

```text
profit = 5
current profit = 2
```

then:

```text
profit = 5
```

---

# Dry Run

Consider:

```text
prices = [7,1,5,3,6,4]
```

Initially:

```text
profit = 0
min_profit = 7
```

### Index 0

```text
price = 7

minimum = min(7,7) = 7
current profit = 7 - 7 = 0
profit = max(0,0) = 0
```

State:

```text
min_profit = 7
profit = 0
```

### Index 1

```text
price = 1

minimum = min(1,7) = 1
current profit = 1 - 1 = 0
profit = max(0,0) = 0
```

State:

```text
min_profit = 1
profit = 0
```

### Index 2

```text
price = 5

minimum = min(5,1) = 1
current profit = 5 - 1 = 4
profit = max(0,4) = 4
```

State:

```text
min_profit = 1
profit = 4
```

### Index 3

```text
price = 3

minimum = min(3,1) = 1
current profit = 3 - 1 = 2
profit = max(4,2) = 4
```

### Index 4

```text
price = 6

minimum = min(6,1) = 1
current profit = 6 - 1 = 5
profit = max(4,5) = 5
```

### Index 5

```text
price = 4

minimum = min(4,1) = 1
current profit = 4 - 1 = 3
profit = max(5,3) = 5
```

Final:

```text
profit = 5
```

Therefore:

```text
return 5;
```

---

## Dry Run Table

For:

```text
prices = [7,1,5,3,6,4]
```

| Index | Price | Minimum Price | Current Profit | Maximum Profit |
|------:|------:|--------------:|---------------:|---------------:|
| 0 | 7 | 7 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 |
| 2 | 5 | 1 | 4 | 4 |
| 3 | 3 | 1 | 2 | 4 |
| 4 | 6 | 1 | 5 | 5 |
| 5 | 4 | 1 | 3 | 5 |

Final answer:

```text
5
```

---

# Why Does the Buy Day Come Before the Sell Day?

This is an important part of the problem.

We process the array from:

```text
left → right
```

When we calculate:

```cpp
arr[i] - min_profit
```

the minimum price comes from an earlier position or the current position.

Therefore, when a positive profit is found, the buying price occurred before the selling price.

For example:

```text
prices = [7,1,5]
```

At price `5`:

```text
minimum = 1
```

So:

```text
buy at 1
sell at 5
```

This is valid.

---

# Why One Minimum Is Enough

Suppose the prices before today are:

```text
[7,4,6,8]
```

and today's price is:

```text
10
```

The best buying price is simply:

```text
4
```

We do not need to remember all the other prices.

If we buy at `4` and sell at `10`:

```text
profit = 6
```

Buying at `7`, `6`, or `8` can never produce a better profit for this selling day.

Therefore, one value is enough:

```text
minimum price seen so far
```

---

# Decreasing Prices

Consider:

```text
prices = [7,6,4,3,1]
```

The minimum keeps decreasing:

```text
7 → 6 → 4 → 3 → 1
```

There is never a later price that produces a positive profit.

So:

```text
profit = 0
```

remains unchanged.

Final answer:

```text
0
```

---

# Another Example

Consider:

```text
prices = [2,4,1,7]
```

Process:

```text
2 → minimum = 2 → profit = 0
4 → minimum = 2 → profit = 2
1 → minimum = 1 → profit = 2
7 → minimum = 1 → profit = 6
```

Final:

```text
6
```

Optimal transaction:

```text
Buy at 1
Sell at 7
Profit = 6
```

---

# Running Minimum Pattern

This problem is a classic **running minimum** problem.

A running minimum means:

```text
At every position,
remember the smallest value seen so far.
```

The general pattern is:

```cpp
minimum = min(minimum, current);
```

Then use that minimum to calculate the current result.

Here:

```text
running minimum = cheapest buying price
```

---

# Greedy Idea

The solution can also be understood as a **greedy** approach.

For every day:

1. Keep the cheapest buying price available so far.
2. Consider selling today.
3. Calculate the resulting profit.
4. Keep the best profit found.

The cheapest earlier price is always the best candidate for a future sale.

---

# Why Not Use Brute Force?

A brute-force solution can try every possible pair:

```text
buy day
+
sell day
```

For `n` prices, there can be roughly:

```text
O(n²)
```

possible pairs.

Therefore:

```text
Time = O(n²)
```

The running-minimum solution only scans once:

```text
Time = O(n)
```

---

# Common Mistake

Do not simply calculate:

```cpp
max_price - min_price
```

without considering their positions.

Example:

```text
prices = [7,1,5]
```

The maximum is `7` and minimum is `1`, but:

```text
7 - 1 = 6
```

is not a valid profit because `7` occurs before `1`.

The correct transaction is:

```text
buy at 1
sell at 5
profit = 4
```

The left-to-right approach automatically preserves the required order.

---

# Core Logic

The entire solution can be reduced to:

```text
Keep minimum price
        ↓
For every current price
        ↓
Calculate current profit
        ↓
Keep maximum profit
```

In code:

```cpp
min_profit = min(arr[i], min_profit);
profit = max(profit, arr[i] - min_profit);
```

These two lines contain the main algorithm.

---

# Edge Cases

### Single Price

```text
prices = [5]
```

Output:

```text
0
```

There is no different future day to sell.

### Decreasing Prices

```text
prices = [7,6,5,4,3]
```

Output:

```text
0
```

### Increasing Prices

```text
prices = [1,2,3,4,5]
```

Buy at `1`, sell at `5`:

```text
profit = 4
```

### Same Prices

```text
prices = [5,5,5,5]
```

Output:

```text
0
```

### Minimum in the Middle

```text
prices = [8,6,4,2,10]
```

Buy at `2` and sell at `10`:

```text
profit = 8
```

---

# Key Learning

This problem teaches the:

```text
Running Minimum + Maximum Answer
```

pattern.

Whenever a problem involves:

```text
minimum before maximum
buy before sell
best future difference
```

consider maintaining the minimum value seen so far.

The pattern is:

```text
Update minimum
      ↓
Calculate current result
      ↓
Update answer
```

---

# Pattern to Remember

```cpp
int answer = 0;
int minimum = arr[0];

for(int i = 0; i < arr.size(); i++)
{
    minimum = min(minimum, arr[i]);

    answer = max(answer, arr[i] - minimum);
}

return answer;
```

For this problem:

```text
minimum → cheapest buying price
arr[i]  → today's selling price
answer  → maximum profit
```

---

# Complexity Analysis

## Time Complexity

```text
O(n)
```

The array is traversed exactly once.

## Space Complexity

```text
O(1)
```

Only a constant number of variables are used.

No extra array, map, set, or DP table is required.

---

# Final Complexity

| Approach | Time | Extra Space |
| -------- | ---- | ----------- |
| Brute Force | `O(n²)` | `O(1)` |
| Running Minimum | `O(n)` | `O(1)` |

### Best Approach

```text
Single traversal + running minimum
```

This gives:

```text
O(n) time
O(1) extra space
```
