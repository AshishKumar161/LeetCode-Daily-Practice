# LeetCode 507: Perfect Number — Explanation

Your solution is **correct and accepted**.

## Your Core Idea

You use **divisor pairs** and only check up to the square root:

```cpp
for (int i = 2; i * i <= nums; i++)
```

If `i` divides `nums`, then `nums / i` is also a divisor.

For example, for `28`:

```text
1 × 28
2 × 14
4 × 7
```

Since the number itself must be excluded, you start with:

```cpp
ans.push_back(1);
```

---

## 1. Handle `nums <= 1`

```cpp
if (nums <= 1) {
    return false;
}
```

`1` is not a perfect number.

---

## 2. Add `1`

```cpp
vector<int> ans;
ans.push_back(1);
```

Every number greater than `1` has `1` as a proper divisor.

---

## 3. Check Only Up to `sqrt(nums)`

```cpp
for (int i = 2; i * i <= nums; i++)
```

You do not need to check every number.

Why?

Because divisors occur in pairs:

```text
i × (nums / i) = nums
```

For `28`:

```text
2 × 14 = 28
4 × 7 = 28
```

Once you reach the square root, all pairs have been found.

Therefore:

```text
Time = O(sqrt(nums))
```

instead of `O(nums)`.

---

## 4. Check Whether `i` Is a Divisor

```cpp
if (nums % i == 0)
```

The `%` operator gives the remainder.

For example:

```text
28 % 4 = 0
```

so `4` is a divisor.

But:

```text
28 % 3 = 1
```

so `3` is not a divisor.

---

## 5. Add the Divisor Pair

Your code:

```cpp
ans.push_back(i);

if (i != nums / i) {
    ans.push_back(nums / i);
}
```

Suppose:

```text
nums = 28
i = 4
```

Then:

```text
nums / i = 28 / 4 = 7
```

So you add:

```text
4 and 7
```

Together they form a divisor pair:

```text
4 × 7 = 28
```

---

## 6. Why `i != nums / i`?

This condition prevents adding the same divisor twice.

Consider:

```text
nums = 36
```

One divisor pair is:

```text
6 × 6 = 36
```

When:

```text
i = 6
```

we get:

```text
nums / i = 6
```

If you added both, you would have:

```text
6
6
```

twice.

Therefore:

```cpp
if (i != nums / i)
```

means:

> Add the paired divisor only when it is different from `i`.

This is especially important for **perfect squares**.

---

# Dry Run: `nums = 28`

Initially:

```text
ans = [1]
```

### `i = 2`

```text
28 % 2 == 0
```

Add:

```text
2
28 / 2 = 14
```

Now:

```text
ans = [1,2,14]
```

### `i = 3`

```text
28 % 3 != 0
```

Nothing happens.

### `i = 4`

```text
28 % 4 == 0
```

Add:

```text
4
28 / 4 = 7
```

Now:

```text
ans = [1,2,14,4,7]
```

### `i = 5`

```text
28 % 5 != 0
```

Nothing happens.

The loop ends when:

```text
i * i > 28
```

The proper divisors are therefore:

```text
1, 2, 4, 7, 14
```

---

# Calculate the Sum

Your code then does:

```cpp
int m = ans.size();
int sum = 0;

for (int i = 0; i < m; i++) {
    sum += ans[i];
}
```

For `28`:

```text
sum = 1 + 2 + 14 + 4 + 7
    = 28
```

Then:

```cpp
if (sum == nums)
    return true;
```

So the answer is:

```text
true
```

---

# Dry Run: `nums = 7`

Start:

```text
ans = [1]
```

Check possible divisors:

```text
7 % 2 != 0
```

The loop stops before `i = 3` because:

```text
3 * 3 > 7
```

So:

```text
sum = 1
```

Compare:

```text
1 == 7
```

False.

Therefore:

```text
return false
```

---

# Why Not Loop Until `nums`?

A basic solution could do:

```cpp
for (int i = 1; i < nums; i++)
```

but that is:

```text
O(nums)
```

For a number as large as:

```text
10^8
```

that could require a huge number of iterations.

Your divisor-pair approach only checks:

```text
2 ... sqrt(nums)
```

so it is:

```text
O(sqrt(nums))
```

which is much more efficient.

---

# Your Exact Complexity

You store all discovered divisors in:

```cpp
vector<int> ans;
```

Therefore:

```text
Time Complexity:  O(sqrt(n))
Space Complexity: O(sqrt(n))
```

The space can be reduced to `O(1)` by storing only the running sum.

For example:

```cpp
class Solution {
public:
    bool checkPerfectNumber(int nums) {

        if (nums <= 1)
            return false;

        int sum = 1;

        for (int i = 2; i * i <= nums; i++)
        {
            if (nums % i == 0)
            {
                sum += i;

                if (i != nums / i)
                {
                    sum += nums / i;
                }
            }
        }

        return sum == nums;
    }
};
```

This optimized version has:

```text
Time:  O(sqrt(n))
Space: O(1)
```

Your submitted code is still fully correct.

---

# Important Things to Remember

### Proper divisors

Do not include the number itself.

### Divisor pairs

```text
i × (n / i) = n
```

### Square-root optimization

```cpp
i * i <= n
```

### Check divisibility

```cpp
n % i == 0
```

### Avoid duplicate square-root divisor

```cpp
if (i != n / i)
```

### Final check

```cpp
sum == n
```

---

# Pattern to Remember

```text
Start with 1
     ↓
Check i up to sqrt(n)
     ↓
If i divides n
     ↓
Add i
     ↓
Add n/i
     ↓
Don't add twice when i == n/i
     ↓
Compare divisor sum with n
```

## Final Complexity

For **your exact code**:

```text
Time Complexity:  O(sqrt(n))
Space Complexity: O(sqrt(n))
```

For the running-sum version:

```text
Time Complexity:  O(sqrt(n))
Space Complexity: O(1)
```
