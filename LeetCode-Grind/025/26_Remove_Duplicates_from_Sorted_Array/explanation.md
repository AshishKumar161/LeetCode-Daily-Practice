
# LeetCode 26: Remove Duplicates from Sorted Array

## Approach

We can solve this problem using the **Two Pointer Technique**.

Because the array is already sorted, all duplicate values are next to each other.

We use two pointers:

* `i` → scans the array and finds new elements.
* `k` → points to the position where the next unique element should be placed.

Initially:

```text
k = 0
```

The first element is always unique, so we start checking from:

```text
i = 1
```

Whenever:

```text
nums[i] != nums[k]
```

we have found a new unique element.

We then:

1. Increment `k`.
2. Store `nums[i]` at `nums[k]`.

At the end, the number of unique elements is:

```text
k + 1
```

---

## Intuition

Consider:

```text
[0,0,1,1,1,2,2,3,3,4]
```

Because the array is sorted, duplicates appear consecutively:

```text
[0,0] [1,1,1] [2,2] [3,3] [4]
```

We only need to keep the first occurrence of each value:

```text
[0,1,2,3,4]
```

The pointer `i` searches for the next unique value.

The pointer `k` maintains the position where that value should be stored.

So the array gradually becomes:

```text
[0,1,2,3,4,...]
```

Only the first `k + 1` positions matter.

---

## Algorithm

1. Store the size of the array in `n`.
2. Initialize:

   ```text
   k = 0
   ```
3. Start traversing from index `1`.
4. If:

   ```text
   nums[i] != nums[k]
   ```

   then a new unique element has been found.
5. Increment `k`.
6. Store:

   ```text
   nums[k] = nums[i]
   ```
7. Continue until the entire array has been processed.
8. Return:

   ```text
   k + 1
   ```

---

## Dry Run

Consider:

```text
nums = [0,0,1,1,1,2,2,3,3,4]
```

Initially:

```text
k = 0
```

So:

```text
nums[k] = nums[0] = 0
```

---

### Step 1

```text
i = 1
nums[i] = 0
nums[k] = 0
```

Since:

```text
0 == 0
```

this is a duplicate.

Do nothing.

```text
k = 0
```

---

### Step 2

```text
i = 2
nums[i] = 1
nums[k] = 0
```

Since:

```text
1 != 0
```

we found a new unique element.

Increment `k`:

```text
k = 1
```

Store:

```text
nums[1] = 1
```

Array:

```text
[0,1,1,1,1,2,2,3,3,4]
```

---

### Step 3

```text
i = 3
nums[i] = 1
nums[k] = 1
```

Since:

```text
1 == 1
```

it is a duplicate.

Do nothing.

---

### Step 4

```text
i = 4
nums[i] = 1
nums[k] = 1
```

Duplicate again.

Do nothing.

---

### Step 5

```text
i = 5
nums[i] = 2
nums[k] = 1
```

Since:

```text
2 != 1
```

we found another unique element.

Increment:

```text
k = 2
```

Store:

```text
nums[2] = 2
```

Array:

```text
[0,1,2,1,1,2,2,3,3,4]
```

Only the first `k + 1` elements matter:

```text
[0,1,2]
```

---

### Continue

The same process continues for `3` and `4`.

Final useful portion:

```text
[0,1,2,3,4]
```

At the end:

```text
k = 4
```

Therefore:

```text
k + 1 = 5
```

Return:

```text
5
```

---

## Why Does This Work?

The array is sorted, so if:

```text
nums[i] == nums[k]
```

then `nums[i]` is a duplicate of the latest unique element.

We can safely ignore it.

When:

```text
nums[i] != nums[k]
```

we know that `nums[i]` is a new unique value.

We move `k` forward and place that value at the next available position.

Therefore, at every stage:

```text
nums[0 ... k]
```

contains only unique elements in sorted order.

At the end, all unique elements are stored in the first `k + 1` positions.

---

## Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int k = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[k])
            {
                k++;
                nums[k] = nums[i];
            }
        }

        return k + 1;
    }
};
```

---

## Code Explanation

### 1. Store the array size

```cpp
int n = nums.size();
```

`n` stores the number of elements in the array.

---

### 2. Initialize `k`

```cpp
int k = 0;
```

`k` points to the position of the latest unique element.

Initially, the first element is considered unique.

For example:

```text
[1,1,2,3]
 ↑
 k
```

---

### 3. Start `i` from 1

```cpp
for (int i = 1; i < n; i++)
```

We start from index `1` because the first element has already been considered unique.

---

### 4. Check for a new element

```cpp
if (nums[i] != nums[k])
```

If the current element is different from the latest unique element, it is a new unique value.

---

### 5. Move `k`

```cpp
k++;
```

Move `k` to the next position where the new unique element should be stored.

---

### 6. Store the unique element

```cpp
nums[k] = nums[i];
```

Copy the new unique value into the correct position.

---

### 7. Return the number of unique elements

```cpp
return k + 1;
```

`k` is an index, so the number of elements is:

```text
k + 1
```

---

## Example 2 Dry Run

Consider:

```text
nums = [1,1,2]
```

Initially:

```text
k = 0
```

### `i = 1`

```text
nums[i] = 1
nums[k] = 1
```

Duplicate:

```text
1 == 1
```

Do nothing.

---

### `i = 2`

```text
nums[i] = 2
nums[k] = 1
```

New element:

```text
2 != 1
```

Increment:

```text
k = 1
```

Store:

```text
nums[1] = 2
```

Array:

```text
[1,2,2]
```

Return:

```text
k + 1 = 2
```

Therefore:

```text
unique elements = [1,2]
```

---

## Edge Cases

### 1. One Element

```text
nums = [5]
```

There are no duplicates.

```text
k = 0
```

Return:

```text
1
```

---

### 2. All Elements Are Unique

```text
nums = [1,2,3,4,5]
```

Every element is different.

The array remains unchanged:

```text
[1,2,3,4,5]
```

Return:

```text
5
```

---

### 3. All Elements Are Equal

```text
nums = [2,2,2,2]
```

Only one unique element exists.

The first position contains:

```text
[2]
```

Return:

```text
1
```

---

### 4. Multiple Duplicate Groups

```text
nums = [0,0,1,1,2,2,3,3]
```

The unique portion becomes:

```text
[0,1,2,3]
```

Return:

```text
4
```

---

## Important Observation

The sorted property is the key to this solution.

If the array were not sorted:

```text
[2,1,2,3,1]
```

equal values would not necessarily be adjacent.

But because the input is sorted:

```text
[1,1,2,2,3,3]
```

all duplicates are grouped together.

Therefore, we can solve the problem with just two pointers and no extra data structure.

---

## Two Pointer Pattern

This problem demonstrates an important pattern:

```text
i → scans the array
k → stores the position of the next unique element
```

The general structure is:

```cpp
for (int i = 1; i < n; i++)
{
    if (nums[i] != nums[k])
    {
        k++;
        nums[k] = nums[i];
    }
}
```

This is a very common **in-place array filtering pattern**.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the array exactly once.

---

### Space Complexity

```text
O(1)
```

No additional array, set, or hash map is used.

The modification is performed directly inside the original array.

---

## Key Learning

The main concepts learned from this problem are:

* Two pointers
* In-place array modification
* Using sorted order to detect duplicates
* Maintaining a write pointer
* Returning the new logical length of an array

The most important pattern is:

```text
Read Pointer → finds useful elements
Write Pointer → stores useful elements
```

This same pattern appears in many array problems, including:

* Remove Element
* Move Zeroes
* Remove Duplicates
* Remove Duplicates II
* Partitioning problems

---

## Final Complexity

| Metric    | Complexity   |
| --------- | ------------ |
| Time      | `O(n)`     |
| Space     | `O(1)`     |
| In-place  | Yes          |
| Technique | Two Pointers |
