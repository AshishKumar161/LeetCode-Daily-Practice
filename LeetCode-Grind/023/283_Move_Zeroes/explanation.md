
# LeetCode 283: Move Zeroes

## Approach

We can solve this problem using the **Two Pointer Technique**.

We use two pointers:

* `i` → traverses the entire array.
* `j` → points to the position where the next non-zero element should be placed.

Initially:

```text
j = 0
```

Whenever `nums[i]` is non-zero:

1. Swap `nums[i]` with `nums[j]`.
2. Increment `j`.

This places every non-zero element at the earliest available position while preserving the relative order of the non-zero elements.

---

## Intuition

Consider:

```text
[0, 1, 0, 3, 12]
```

We want:

```text
[1, 3, 12, 0, 0]
```

The important observation is that we do not need to explicitly move every zero toward the end.

Instead, we focus on the **non-zero elements**.

The pointer `j` tells us:

> "This is the next position where a non-zero element should go."

So when `i` finds a non-zero element, we swap it with the element at `j`.

---

## Algorithm

1. Initialize `j = 0`.
2. Traverse the array using `i` from `0` to `n - 1`.
3. If `nums[i] != 0`:

   * Swap `nums[i]` and `nums[j]`.
   * Increment `j`.
4. Continue until the entire array has been processed.
5. The non-zero elements will be at the beginning and all zeroes will automatically be pushed toward the end.

---

## Dry Run

Consider:

```text
nums = [0, 1, 0, 3, 12]
```

Initially:

```text
j = 0
```

### Step 1

```text
i = 0
nums[i] = 0
```

It is zero, so we do nothing.

```text
nums = [0, 1, 0, 3, 12]
j = 0
```

---

### Step 2

```text
i = 1
nums[i] = 1
```

`1` is non-zero.

Swap:

```text
nums[1] ↔ nums[0]
```

Array becomes:

```text
[1, 0, 0, 3, 12]
```

Then:

```text
j = 1
```

---

### Step 3

```text
i = 2
nums[i] = 0
```

It is zero, so we do nothing.

```text
[1, 0, 0, 3, 12]
j = 1
```

---

### Step 4

```text
i = 3
nums[i] = 3
```

`3` is non-zero.

Swap:

```text
nums[3] ↔ nums[1]
```

Array becomes:

```text
[1, 3, 0, 0, 12]
```

Then:

```text
j = 2
```

---

### Step 5

```text
i = 4
nums[i] = 12
```

`12` is non-zero.

Swap:

```text
nums[4] ↔ nums[2]
```

Array becomes:

```text
[1, 3, 12, 0, 0]
```

Then:

```text
j = 3
```

Final result:

```text
[1, 3, 12, 0, 0]
```

---

## Why Does This Work?

At any point during the traversal, `j` represents the first position where a non-zero element has not yet been placed.

Therefore:

```text
[0 ... j-1]
```

contains only non-zero elements in their original relative order.

When `i` finds another non-zero element, we place it at position `j`.

Because we process the array from left to right, the non-zero elements are inserted in the same order in which they originally appeared.

All positions after the non-zero elements are consequently occupied by zeroes.

---

## Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return;
    }
};
```

---

## Code Explanation

### `int j = 0`

```cpp
int j = 0;
```

`j` represents the position where the next non-zero element should be placed.

---

### Traverse the array

```cpp
for (int i = 0; i < n; i++)
```

`i` scans every element from left to right.

---

### Check for a non-zero element

```cpp
if (nums[i] != 0)
```

If the current element is zero, we ignore it.

If it is non-zero, it needs to be placed at position `j`.

---

### Swap

```cpp
swap(nums[i], nums[j]);
```

This moves the non-zero element to its correct position.

At the same time, the zero that was at position `j` is moved toward the current position of `i`.

---

### Move `j`

```cpp
j++;
```

We have successfully placed one non-zero element, so the next non-zero element should go to the next position.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the array only once.

Here `n` is the number of elements in `nums`.

### Space Complexity

```text
O(1)
```

No additional array or data structure is used.

The array is modified in-place.

---

## Edge Cases

### 1. Array contains only zeroes

```text
[0,0,0]
```

Output:

```text
[0,0,0]
```

No non-zero element is found.

---

### 2. Array contains no zeroes

```text
[1,2,3,4]
```

Output:

```text
[1,2,3,4]
```

The relative order remains unchanged.

---

### 3. Zeroes are at the beginning

```text
[0,0,1,2]
```

Output:

```text
[1,2,0,0]
```

---

### 4. Zeroes are already at the end

```text
[1,2,3,0,0]
```

Output:

```text
[1,2,3,0,0]
```

---

## Key Learning

This problem is a good example of the **Two Pointer Technique**.

The important pattern is:

```text
i → scans the array
j → tracks the next valid position
```

Whenever a valid/non-zero element is found:

```text
swap(nums[i], nums[j])
j++
```

This pattern is useful for many **in-place array rearrangement and partitioning problems**.

---

## Pattern to Remember

```text
for each element:
    if element satisfies the condition:
        swap(element, nums[j])
        j++
```

For this problem, the condition is:

```cpp
nums[i] != 0
```

So the general pattern becomes:

```cpp
if (nums[i] != 0)
{
    swap(nums[i], nums[j]);
    j++;
}
```

---

## Final Complexity

| Metric | Complexity |
| ------ | ---------- |
| Time   | `O(n)`   |
| Space  | `O(1)`   |
