# Armstrong Number — Explanation

## Your Code

```cpp
class Solution {
public:
    bool isArmstrong(int n) {
        int count = 1;
        int temp = n;

        while (temp >= 10) {
            temp = temp / 10;
            count++;
        }

        temp = n;
        int sum = 0;

        while (temp > 0) {
            int store = temp % 10;
            temp = temp / 10;

            sum = sum + pow(store, count);
        }

        return sum == n;
    }
};
```

Your approach is correct and uses the standard digit-extraction technique.

---

# 1. What Is an Armstrong Number?

For a number with `k` digits:

```text
Armstrong number = sum of every digit^k
```

For example:

```text
153
```

has `3` digits.

Therefore:

```text
1³ + 5³ + 3³
= 1 + 125 + 27
= 153
```

Since the sum equals the original number:

```text
153 == 153
```

it is an Armstrong number.

---

# 2. Step 1 — Count the Number of Digits

You start with:

```cpp
int count = 1;
int temp = n;
```

Why `count = 1`?

Because every positive integer has at least one digit.

For example:

```text
n = 153
```

Initially:

```text
count = 1
temp = 153
```

Then:

```cpp
while (temp >= 10)
```

continues while there is more than one digit.

### Dry run

```text
temp = 153
153 >= 10 → true
temp = 153 / 10 = 15
count = 2

temp = 15
15 >= 10 → true
temp = 15 / 10 = 1
count = 3

temp = 1
1 >= 10 → false
```

Therefore:

```text
count = 3
```

So `153` has 3 digits.

---

# 3. Why Do We Use `temp`?

You don't want to destroy the original value `n`.

So:

```cpp
int temp = n;
```

is used for counting digits.

After counting, you reset:

```cpp
temp = n;
```

because you need to process the digits again.

---

# 4. Step 2 — Extract Each Digit

Now:

```cpp
int sum = 0;
```

Then:

```cpp
while (temp > 0)
```

processes every digit.

The key operation is:

```cpp
int store = temp % 10;
```

`% 10` gives the last digit.

For:

```text
153
```

we get:

```text
153 % 10 = 3
```

Then:

```cpp
temp = temp / 10;
```

removes the last digit:

```text
153 / 10 = 15
```

So the process is:

```text
153 → digit 3
15  → digit 5
1   → digit 1
```

---

# 5. Calculate the Armstrong Sum

You use:

```cpp
sum = sum + pow(store, count);
```

For `153`:

### First digit

```text
store = 3

3³ = 27

sum = 27
```

### Second digit

```text
store = 5

5³ = 125

sum = 27 + 125
    = 152
```

### Third digit

```text
store = 1

1³ = 1

sum = 152 + 1
    = 153
```

Finally:

```text
sum = 153
n   = 153
```

---

# 6. Final Check

Your last line is:

```cpp
return sum == n;
```

This is a very clean way to return the answer.

If:

```text
sum == n
```

then:

```text
true
```

Otherwise:

```text
false
```

For `153`:

```text
153 == 153
→ true
```

For `12`:

```text
1² + 2²
= 5

5 == 12
→ false
```

---

# Complete Dry Run — `n = 153`

Initial:

```text
n = 153
```

## Count digits

```text
temp = 153
count = 1

153 / 10 = 15
count = 2

15 / 10 = 1
count = 3
```

Therefore:

```text
count = 3
```

## Calculate sum

```text
temp = 153
sum = 0
```

First iteration:

```text
store = 153 % 10 = 3
temp = 153 / 10 = 15

sum = 0 + 3³
    = 27
```

Second iteration:

```text
store = 15 % 10 = 5
temp = 15 / 10 = 1

sum = 27 + 5³
    = 27 + 125
    = 152
```

Third iteration:

```text
store = 1 % 10 = 1
temp = 1 / 10 = 0

sum = 152 + 1³
    = 153
```

Final:

```text
sum == n

153 == 153

true
```

---

# Important Pattern to Remember

This problem teaches an important **number-digit pattern**.

## Extract last digit

```cpp
digit = n % 10;
```

## Remove last digit

```cpp
n = n / 10;
```

This pattern is used in many problems:

- Reverse Integer
- Palindrome Number
- Armstrong Number
- Sum of Digits
- Count Digits
- Number of Digits
- Digit Frequency

Remember:

```text
% 10 → gives last digit
/ 10 → removes last digit
```

---

# Complexity

Let `d` be the number of digits in `n`.

You process the digits twice:

1. Once to count digits.
2. Once to calculate the Armstrong sum.

Therefore:

```text
Time Complexity: O(d)
Space Complexity: O(1)
```

Since `d` is the number of digits, this is effectively very efficient.

---

# One Small Improvement

Your code uses:

```cpp
pow(store, count)
```

`pow()` returns a floating-point value (`double`).

For typical LeetCode constraints this works here, but for integer exponentiation, an integer-power function can avoid floating-point arithmetic.

For example:

```cpp
int power = 1;

for (int i = 0; i < count; i++) {
    power *= store;
}

sum += power;
```

However, **your current solution is accepted and logically correct** for the problem shown.

---

# Final Algorithm

```text
1. Count the number of digits.
2. Reset temp = n.
3. Extract each digit using % 10.
4. Remove the digit using / 10.
5. Add digit^number_of_digits to sum.
6. Compare sum with n.
7. If equal → Armstrong number.
8. Otherwise → not Armstrong.
```

## Core Pattern

```cpp
digit = temp % 10;
temp = temp / 10;
```

This is the most important concept to remember from this problem.
