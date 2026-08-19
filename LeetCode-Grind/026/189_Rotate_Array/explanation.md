
# LeetCode 189: Rotate Array

## Approach

We can rotate the array in-place using the **Three Reversal Technique**.

The main idea is to divide the array into two parts:

```text
[First Part] [Last k Elements]
```

For a right rotation by `k` positions, the last `k` elements need to move to the beginning.

For example:

```text
nums = [1,2,3,4,5,6,7]
k = 3
```

We want:

```text
[5,6,7,1,2,3,4]
```

We can achieve this using three reversals:

1. Reverse the entire array.
2. Reverse the first `k` elements.
3. Reverse the remaining `n-k` elements.

---

## Important Observation

Before performing the rotation, we first calculate:

```cpp
k = k % n;
```

This is necessary because rotating an array `n` times brings it back to its original state.

For example:

```text
n = 7
k = 10
```

Instead of rotating 10 times:

```text
k = 10 % 7
  = 3
```

So rotating by 10 positions is equivalent to rotating by 3 positions.

---

## Intuition

Consider:

```text
[1,2,3,4,5,6,7]
```

For:

```text
k = 3
```

We want the last three elements:

```text
[5,6,7]
```

to move to the front:

```text
[5,6,7,1,2,3,4]
```

The three-reversal technique makes this possible without using an additional array.

---

## Algorithm

1. Store the size of the array in `n`.
2. Reduce `k` using:

   ```text
   k = k % n
   ```
3. Reverse the entire array.
4. Reverse the first `k` elements.
5. Reverse the remaining `n-k` elements.
6. The array is now rotated to the right by `k` positions.

---

## Why Three Reversals Work

Consider:

```text
[1,2,3,4,5,6,7]
```

Split it into:

```text
A = [1,2,3,4]
B = [5,6,7]
```

We want:

```text
B + A
```

which is:

```text
[5,6,7,1,2,3,4]
```

The three reversals produce this arrangement.

---

## Dry Run

Consider:

```text
nums = [1,2,3,4,5,6,7]
k = 3
```

### Step 1 — Reverse the Entire Array

Original:

```text
[1,2,3,4,5,6,7]
```

Reverse it:

```text
[7,6,5,4,3,2,1]
```

---

### Step 2 — Reverse the First `k` Elements

Here:

```text
k = 3
```

Reverse:

```text
[7,6,5]
```

It becomes:

```text
[5,6,7]
```

So the complete array becomes:

```text
[5,6,7,4,3,2,1]
```

---

### Step 3 — Reverse the Remaining Elements

The remaining elements are:

```text
[4,3,2,1]
```

Reverse them:

```text
[1,2,3,4]
```

Final array:

```text
[5,6,7,1,2,3,4]
```

Therefore, the array has been rotated right by `3` positions.

---

## Code

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        // Reverse the entire array
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        // Reverse the first k elements
        for (int i = 0, j = k - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        // Reverse the remaining n-k elements
        for (int i = k, j = n - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        return;
    }
};
```

---

## Code Explanation

### 1. Find the array size

```cpp
int n = nums.size();
```

`n` stores the number of elements in the array.

---

### 2. Reduce `k`

```cpp
k = k % n;
```

If `k` is greater than `n`, rotating by complete cycles does not change the array.

For example:

```text
n = 7
k = 10
```

becomes:

```text
k = 3
```

---

### 3. Reverse the Entire Array

```cpp
for (int i = 0, j = n - 1; i < j; i++, j--)
{
    swap(nums[i], nums[j]);
}
```

This reverses:

```text
[1,2,3,4,5,6,7]
```

into:

```text
[7,6,5,4,3,2,1]
```

---

### 4. Reverse the First `k` Elements

```cpp
for (int i = 0, j = k - 1; i < j; i++, j--)
{
    swap(nums[i], nums[j]);
}
```

For `k = 3`, reverse:

```text
[7,6,5]
```

into:

```text
[5,6,7]
```

The array becomes:

```text
[5,6,7,4,3,2,1]
```

---

### 5. Reverse the Remaining Elements

```cpp
for (int i = k, j = n - 1; i < j; i++, j--)
{
    swap(nums[i], nums[j]);
}
```

Reverse:

```text
[4,3,2,1]
```

into:

```text
[1,2,3,4]
```

Final result:

```text
[5,6,7,1,2,3,4]
```

---

## Why Does This Work?

Suppose the original array is divided into:

```text
A B
```

where `B` contains the last `k` elements.

A right rotation requires:

```text
B A
```

The first reversal gives:

```text
reverse(A B)
= reverse(B) reverse(A)
```

Then we reverse each part individually:

```text
reverse(reverse(B)) reverse(reverse(A))
```

which gives:

```text
B A
```

Therefore, three reversals successfully rotate the array.

---

## Example 2 Dry Run

Consider:

```text
nums = [-1,-100,3,99]
k = 2
```

### Reverse Entire Array

```text
[-1,-100,3,99]
```

becomes:

```text
[99,3,-100,-1]
```

### Reverse First `k = 2` Elements

```text
[99,3]
```

becomes:

```text
[3,99]
```

Array:

```text
[3,99,-100,-1]
```

### Reverse Remaining Elements

```text
[-100,-1]
```

becomes:

```text
[-1,-100]
```

Final result:

```text
[3,99,-1,-100]
```

---

## Edge Cases

### 1. `k = 0`

```text
nums = [1,2,3]
k = 0
```

No rotation is required.

The array remains:

```text
[1,2,3]
```

---

### 2. `k = n`

```text
nums = [1,2,3,4]
k = 4
```

After:

```text
k = k % n
```

we get:

```text
k = 0
```

So the array remains unchanged.

---

### 3. `k > n`

```text
nums = [1,2,3,4,5]
k = 7
```

Calculate:

```text
7 % 5 = 2
```

So this is equivalent to rotating by `2` positions.

---

### 4. Single Element

```text
nums = [1]
k = 100
```

After:

```text
k = 100 % 1
```

we get:

```text
k = 0
```

The array remains:

```text
[1]
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We perform three reversals.

Each reversal takes `O(n)` time in the worst case.

Therefore:

```text
O(n) + O(n) + O(n) = O(n)
```

---

### Space Complexity

```text
O(1)
```

No additional array is created.

Only a few variables are used.

Therefore, the solution works **in-place**.

---

## Key Learning

This problem teaches the **Three Reversal Technique** for array rotation.

The pattern to remember is:

```text
Right Rotate by k

1. Reverse the entire array
2. Reverse first k elements
3. Reverse remaining n-k elements
```

For example:

```text
[1,2,3,4,5,6,7]
        ↓
Reverse all
        ↓
[7,6,5,4,3,2,1]
        ↓
Reverse first k
        ↓
[5,6,7,4,3,2,1]
        ↓
Reverse remaining
        ↓
[5,6,7,1,2,3,4]
```

This is an important **in-place array manipulation pattern** and is useful in technical interviews. The reversal approach is also commonly identified as the standard in-place technique for Rotate Array.

---

## Final Complexity

| Metric   | Complexity |
| -------- | ---------- |
| Time     | `O(n)`   |
| Space    | `O(1)`   |
| In-place | Yes        |
