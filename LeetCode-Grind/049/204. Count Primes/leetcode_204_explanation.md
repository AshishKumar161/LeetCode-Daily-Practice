# LeetCode 204: Count Primes — Explanation

## Your Code

```cpp
class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2) {
            return 0;
        }

        vector<bool> prime(n, true);

        prime[0] = false;
        prime[1] = false;

        for (int i = 4; i < n; i += 2) {
            prime[i] = false;
        }

        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    prime[j] = false;
                }
            }
        }

        int count = 1;

        for (int i = 3; i < n; i += 2) {
            if (prime[i]) {
                count++;
            }
        }

        return count;
    }
};
```

Your solution uses the **Sieve of Eratosthenes**, with an optimization that skips even numbers.

---

## 1. What Is a Prime Number?

A prime number is a number greater than `1` that has exactly two positive divisors:

```text
1 and itself
```

Examples:

```text
2, 3, 5, 7, 11, 13
```

Numbers such as `4`, `6`, `8`, and `9` are not prime.

---

## 2. What Does the Problem Ask?

The problem asks for the number of primes **strictly less than `n`**.

For:

```text
n = 10
```

we consider:

```text
0, 1, 2, 3, 4, 5, 6, 7, 8, 9
```

The primes are:

```text
2, 3, 5, 7
```

Therefore:

```text
answer = 4
```

---

## 3. Handle Small Values

```cpp
if (n <= 2) {
    return 0;
}
```

For `n = 0`, `1`, or `2`, there are no prime numbers strictly less than `n`.

---

## 4. Create the Prime Array

```cpp
vector<bool> prime(n, true);
```

Initially every position is considered prime.

Then:

```cpp
prime[0] = false;
prime[1] = false;
```

because `0` and `1` are not prime.

---

## 5. Remove Even Numbers

```cpp
for (int i = 4; i < n; i += 2) {
    prime[i] = false;
}
```

Every even number greater than `2` is composite.

For example:

```text
4, 6, 8, 10, 12...
```

The only even prime is:

```text
2
```

This optimization means the later loops only need to consider odd numbers.

---

## 6. Main Sieve Loop

```cpp
for (int i = 3; 1LL * i * i < n; i += 2)
```

We start from `3` because `2` has already been handled.

We increment by `2`:

```text
3 → 5 → 7 → 9 → 11...
```

so only odd numbers are processed.

### Why `i * i < n`?

We only need to find prime factors up to the square root of `n`.

If a composite number has a factor larger than its square root, it must have another factor smaller than the square root.

For example:

```text
45 = 5 × 9
```

and:

```text
5 < sqrt(45)
```

Therefore, checking factors up to `sqrt(n)` is enough.

### Why `1LL`?

```cpp
1LL * i * i
```

makes the multiplication use `long long`, reducing the risk of overflow when calculating `i * i`.

---

## 7. Check Whether `i` Is Prime

```cpp
if (prime[i])
```

If `prime[i]` is still `true`, then `i` has not been marked composite, so it is prime.

---

## 8. Mark Multiples

```cpp
for (int j = i * i; j < n; j += 2 * i) {
    prime[j] = false;
}
```

This is the main operation of the Sieve.

Suppose:

```text
i = 3
```

The multiples are:

```text
3, 6, 9, 12, 15, 18...
```

The even multiples have already been removed.

So we only need:

```text
9, 15, 21, 27...
```

That's why the increment is:

```cpp
j += 2 * i
```

For `i = 3`:

```text
9 → 15 → 21 → 27
```

---

## 9. Why Start From `i * i`?

You use:

```cpp
int j = i * i;
```

Earlier multiples have already been handled by smaller factors.

For example, for `i = 5`:

```text
10 = 2 × 5
15 = 3 × 5
20 = 4 × 5
```

These have already been dealt with.

The first new multiple is:

```text
5 × 5 = 25
```

Therefore we start at:

```cpp
i * i
```

---

# Dry Run: `n = 10`

Initially:

```text
prime = [T,T,T,T,T,T,T,T,T,T]
```

After removing `0` and `1`:

```text
F F T T T T T T T T
```

Remove even numbers greater than `2`:

```text
F F T T F T F T F T
```

Now `i = 3`.

Since:

```text
3 × 3 < 10
```

and `prime[3]` is true, mark:

```text
3 × 3 = 9
```

as false.

Now:

```text
F F T T F T F T F F
```

The remaining primes are:

```text
2, 3, 5, 7
```

---

## 10. Count the Primes

Your code:

```cpp
int count = 1;
```

counts `2`, which is known to be prime.

Then:

```cpp
for (int i = 3; i < n; i += 2)
```

checks only odd numbers.

For `n = 10`:

```text
2 → count = 1
3 → count = 2
5 → count = 3
7 → count = 4
```

So:

```text
return 4;
```

---

## 11. Why Skip Even Numbers During Counting?

You use:

```cpp
for (int i = 3; i < n; i += 2)
```

instead of checking every number.

All even numbers greater than `2` are already known to be composite.

Therefore:

```text
2
```

is counted separately and only odd numbers are checked afterward.

---

# Complete Algorithm

```text
If n <= 2:
    return 0

Create prime[n], initially true

Set:
    prime[0] = false
    prime[1] = false

Mark all even numbers > 2 as false

For every odd i up to sqrt(n):
    If i is prime:
        Mark its odd multiples as false

Start count at 1 for prime number 2

Check remaining odd numbers

Return count
```

---

# Complexity

The Sieve of Eratosthenes has:

```text
Time Complexity:  O(n log log n)
Space Complexity: O(n)
```

Your odd-number optimization reduces practical work, while the standard asymptotic time complexity remains `O(n log log n)`.

---

# Important Things to Remember

### Sieve idea

Instead of checking every number individually:

```text
Find a prime
    ↓
Mark its multiples as composite
```

### Start marking at `i * i`

```cpp
int j = i * i;
```

because smaller multiples were already handled.

### Process only odd numbers

```cpp
i += 2
```

### Skip even multiples

```cpp
j += 2 * i
```

### Only process factors up to square root

```cpp
1LL * i * i < n
```

---

# Final Pattern

```text
Create prime array
      ↓
0 and 1 = not prime
      ↓
Remove even numbers
      ↓
Find odd primes up to sqrt(n)
      ↓
Mark their odd multiples
      ↓
Count remaining primes
```

## Final Complexity

```text
Time:  O(n log log n)
Space: O(n)
```
