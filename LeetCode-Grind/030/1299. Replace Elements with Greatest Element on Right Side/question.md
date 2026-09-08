# LeetCode 1299 - Replace Elements with Greatest Element on Right Side

## Question

Given an array `arr`, replace every element with the greatest element among the elements to its right, and replace the last element with `-1`.

After doing so, return the array.

---

## Example 1

**Input:**
```text
arr = [17,18,5,4,6,1]
```

**Output:**
```text
[18,6,6,6,1,-1]
```

**Explanation:**

* Index `0` → greatest element on the right is `18`.
* Index `1` → greatest element on the right is `6`.
* Index `2` → greatest element on the right is `6`.
* Index `3` → greatest element on the right is `6`.
* Index `4` → greatest element on the right is `1`.
* Last element → `-1`.

---

## Example 2

**Input:**
```text
arr = [400]
```

**Output:**
```text
[-1]
```

---

## Constraints

* `1 <= arr.length <= 10^4`
* `1 <= arr[i] <= 10^5`

---

## Topics

* Array
