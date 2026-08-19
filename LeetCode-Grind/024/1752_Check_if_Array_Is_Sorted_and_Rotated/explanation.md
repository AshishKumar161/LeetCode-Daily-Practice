
# LeetCode 1752: Check if Array Is Sorted and Rotated

## Approach

The key idea is to find the point where the sorted order breaks.

For example:

```text
[3,4,5,1,2]
```

There is one point where:

```text
5 > 1
```

This is the **rotation point**.

If we can find this point, we can rotate the array back to its original sorted form and then check whether the resulting array is sorted.

In this solution, we use the **array reversal technique** to rotate the array back into sorted order.

---

## Intuition

Suppose:

```text
nums = [3,4,5,1,2]
```

The first decreasing pair is:

```text
5 > 1
```

So the array can be divided into two parts:

```text
[3,4,5] [1,2]
```

The correct sorted array should be:

```text
[1,2] [3,4,5]
```

Therefore, we need to rotate the array left by `3` positions.

Instead of using another array, we can perform this rotation **in-place using three reversals**.

---

## Finding the Rotation Point

We scan the array until we find:

```cpp
nums[i] > nums[i + 1]
```

This is where the increasing order breaks.

For:

```text
[3,4,5,1,2]
```

we find:

```text
5 > 1
```

So:

```text
store = 2
```

and:

```text
k = store + 1
  = 3
```

`k` represents the number of elements in the first part of the rotated array.

---

## Algorithm

1. Find the first position where:

   ```text
   nums[i] > nums[i + 1]
   ```
2. If no such position exists, the array is already sorted, so return `true`.
3. Store the rotation amount:

   ```text
   k = store + 1
   ```
4. Reverse the entire array.
5. Reverse the first `n - k` elements.
6. Reverse the remaining `k` elements.
7. The array is now rotated back.
8. Traverse the resulting array and check whether it is sorted.
9. If any adjacent pair violates:

   ```text
   nums[i] <= nums[i + 1]
   ```

   return `false`.
10. Otherwise, return `true`.

---

## Why Three Reversals Work

Consider:

```text
[3,4,5,1,2]
```

Split it at the rotation point:

```text
A = [3,4,5]
B = [1,2]
```

We want:

```text
B + A
```

which is:

```text
[1,2,3,4,5]
```

A left rotation can be performed using three reversals.

### Step 1: Reverse the entire array

```text
[3,4,5,1,2]
```

becomes:

```text
[2,1,5,4,3]
```

### Step 2: Reverse the first `n-k` elements

Here:

```text
n = 5
k = 3

n-k = 2
```

Reverse:

```text
[2,1]
```

Result:

```text
[1,2,5,4,3]
```

### Step 3: Reverse the remaining `k` elements

Reverse:

```text
[5,4,3]
```

Result:

```text
[1,2,3,4,5]
```

Now the array is sorted.

---

## Dry Run

Consider:

```text
nums = [3,4,5,1,2]
```

### Step 1 — Find the break

Compare adjacent elements:

```text
3 < 4
4 < 5
5 > 1
```

The first decreasing pair is:

```text
5 > 1
```

Therefore:

```text
store = 2
k = 3
```

---

### Step 2 — Reverse the entire array

Before:

```text
[3,4,5,1,2]
```

After:

```text
[2,1,5,4,3]
```

---

### Step 3 — Reverse the first `n-k` elements

```text
n - k = 5 - 3 = 2
```

Reverse:

```text
[2,1]
```

Result:

```text
[1,2,5,4,3]
```

---

### Step 4 — Reverse the remaining elements

Reverse:

```text
[5,4,3]
```

Result:

```text
[1,2,3,4,5]
```

---

### Step 5 — Check if sorted

Now compare:

```text
1 <= 2
2 <= 3
3 <= 4
4 <= 5
```

Everything is sorted.

Therefore:

```text
true
```

---

## Example of an Invalid Array

Consider:

```text
[2,1,3,4]
```

Find the first break:

```text
2 > 1
```

Therefore:

```text
k = 1
```

Rotate the array back:

```text
[1,3,4,2]
```

Now check the order:

```text
1 <= 3
3 <= 4
4 > 2
```

The array is still not sorted.

Therefore:

```text
false
```

---

## Code

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        int store = -1;

        // Find the first point where sorted order breaks
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                store = i;
                break;
            }
        }

        // Already sorted
        if (store == -1) {
            return true;
        }

        int k = store + 1;

        // Reverse the entire array
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }

        // Reverse the first n-k elements
        for (int i = 0, j = n - k - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }

        // Reverse the remaining k elements
        for (int i = n - k, j = n - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }

        // Check whether the array is sorted
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }

        return true;
    }
};
```

---

## Code Explanation

### 1. Get the array size

```cpp
int n = nums.size();
```

`n` stores the number of elements.

---

### 2. Find the rotation point

```cpp
int store = -1;
```

Initially, we assume there is no point where the order breaks.

Then:

```cpp
for (int i = 0; i < n - 1; i++) {
    if (nums[i] > nums[i + 1]) {
        store = i;
        break;
    }
}
```

We find the first position where:

```text
nums[i] > nums[i + 1]
```

For:

```text
[3,4,5,1,2]
```

this happens at:

```text
5 > 1
```

Therefore:

```text
store = 2
```

---

### 3. Already sorted case

```cpp
if (store == -1) {
    return true;
}
```

If no decreasing pair exists, the array is already sorted.

Since zero rotations are allowed, the answer is `true`.

---

### 4. Calculate rotation amount

```cpp
int k = store + 1;
```

The first part of the rotated array contains elements from index `0` through `store`.

For:

```text
[3,4,5,1,2]
```

we have:

```text
k = 3
```

---

### 5. Reverse the entire array

```cpp
for (int i = 0, j = n - 1; i < j; i++, j--) {
    swap(nums[i], nums[j]);
}
```

This is the first reversal used to perform the rotation in-place.

---

### 6. Reverse the first part

```cpp
for (int i = 0, j = n - k - 1; i < j; i++, j--) {
    swap(nums[i], nums[j]);
}
```

This reverses the first `n-k` elements.

---

### 7. Reverse the second part

```cpp
for (int i = n - k, j = n - 1; i < j; i++, j--) {
    swap(nums[i], nums[j]);
}
```

This reverses the remaining `k` elements.

After the three reversals, the rotated array is restored to its original sorted arrangement.

---

### 8. Verify the result

```cpp
for (int i = 0; i < n - 1; i++) {
    if (nums[i] > nums[i + 1]) {
        return false;
    }
}
```

If any adjacent pair is decreasing, the array cannot be sorted after the rotation.

Otherwise:

```cpp
return true;
```

---

## Why Does This Work?

A valid sorted-and-rotated array consists of two sorted portions:

```text
[larger elements] [smaller elements]
```

For example:

```text
[3,4,5] [1,2]
```

There is only one point where the normal increasing order breaks:

```text
5 > 1
```

That point identifies the rotation boundary.

We use the boundary to rotate the array back into its original order.

If the resulting array is sorted, the original array could have been produced by rotating a sorted array.

If it is not sorted, no valid rotation can produce the original array.

---

## Edge Cases

### 1. Already Sorted

```text
[1,2,3,4,5]
```

There is no decreasing pair.

```text
store = -1
```

Return:

```text
true
```

---

### 2. Single Element

```text
[1]
```

A single-element array is always sorted.

Return:

```text
true
```

---

### 3. Duplicate Elements

```text
[1,1,1]
```

There is no decreasing pair because:

```text
1 > 1
```

is false.

Return:

```text
true
```

---

### 4. Valid Rotation

```text
[2,3,4,1]
```

There is one break:

```text
4 > 1
```

Rotating it back gives:

```text
[1,2,3,4]
```

Therefore:

```text
true
```

---

### 5. Invalid Rotation

```text
[2,1,3,4]
```

After rotating around the detected break, the array cannot become sorted.

Therefore:

```text
false
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We perform a constant number of linear passes over the array.

The three reversal operations together take `O(n)` time, and the final sorted check takes `O(n)`.

Therefore, the overall complexity is:

```text
O(n)
```

### Space Complexity

```text
O(1)
```

We modify the array in-place and use only a few integer variables.

---

## Key Learning

This problem teaches an important property of a **sorted rotated array**:

> There can be at most one point where the increasing order breaks.

The important pattern is:

```text
Find the rotation point
        ↓
Determine the rotation amount
        ↓
Rotate back using reversals
        ↓
Check whether the result is sorted
```

It also reinforces the **array reversal technique** for performing rotations in-place.

---

## Important Observation

There is an even simpler `O(n)` / `O(1)` solution that does not modify the array.

A valid sorted-and-rotated array has at most one circular descent:

```text
nums[i] > nums[(i + 1) % n]
```

So we can simply count these breaks.

If the count is at most `1`, the array is valid. This is the standard single-pass characterization of the problem.

Your current solution is still **O(n) time and O(1) space**, but it performs extra work because it actually rotates the array and then checks it.

---

## Final Complexity

| Metric   | Complexity |
| -------- | ---------- |
| Time     | `O(n)`   |
| Space    | `O(1)`   |
| In-place | Yes        |
