# LeetCode 1299: Replace Elements with Greatest Element on Right Side

## Approach

We solve this problem using a **right-to-left traversal**.

The key observation is:

> While moving from right to left, we can keep track of the greatest element already seen.

The elements already visited are exactly the elements to the **right** of the current index.

We maintain:

```cpp
int max = -1;
```

For every index:

1. Save the original value in `temp`.
2. Replace `arr[i]` with the current `max`.
3. Update `max` using the original value.

---

## Intuition

For:

```text
arr = [17,18,5,4,6,1]
```

we process:

```text
1 → 6 → 4 → 5 → 18 → 17
```

Start:

```text
max = -1
```

When processing `6`, the greatest element to its right is already known:

```text
max = 1
```

So:

```text
6 → 1
```

Then `6` becomes the new maximum:

```text
max = 6
```

When processing `4`:

```text
4 → 6
```

When processing `5`:

```text
5 → 6
```

When processing `18`:

```text
18 → 6
```

Then `18` becomes the new maximum for everything further left.

---

## Why Traverse From Right to Left?

If we move left to right, the elements on the right have not been processed yet.

For example:

```text
[17,18,5,4,6,1]
 ↑
```

For `17`, we would need to search:

```text
[18,5,4,6,1]
```

This can lead to `O(n²)` time.

With right-to-left traversal, we already know the maximum of the right side.

The pattern is:

```text
Right → Left
Track maximum
Replace current
Update maximum
```

---

## Algorithm

1. Store the array size in `n`.
2. Initialize `max = -1`.
3. Traverse from `n - 1` to `0`.
4. Save the original value:
   ```cpp
   int temp = arr[i];
   ```
5. Replace:
   ```cpp
   arr[i] = max;
   ```
6. Update:
   ```cpp
   if(temp > max)
       max = temp;
   ```
7. Return `arr`.

---

## Dry Run

Input:

```text
arr = [17,18,5,4,6,1]
```

Initially:

```text
max = -1
```

### `i = 5`

```text
temp = 1
arr[5] = -1
```

Array:

```text
[17,18,5,4,6,-1]
```

Update:

```text
1 > -1
max = 1
```

---

### `i = 4`

```text
temp = 6
arr[4] = 1
```

Array:

```text
[17,18,5,4,1,-1]
```

Update:

```text
6 > 1
max = 6
```

---

### `i = 3`

```text
temp = 4
arr[3] = 6
```

Array:

```text
[17,18,5,6,1,-1]
```

`4 > 6` is false, so:

```text
max = 6
```

---

### `i = 2`

```text
temp = 5
arr[2] = 6
```

Array:

```text
[17,18,6,6,1,-1]
```

`5 > 6` is false.

---

### `i = 1`

```text
temp = 18
arr[1] = 6
```

Array:

```text
[17,6,6,6,1,-1]
```

Update:

```text
18 > 6
max = 18
```

---

### `i = 0`

```text
temp = 17
arr[0] = 18
```

Final:

```text
[18,6,6,6,1,-1]
```

`17 > 18` is false.

---

## Why Do We Need `temp`?

This is the most important part of the in-place solution.

We do:

```cpp
int temp = arr[i];
arr[i] = max;
```

After replacing `arr[i]`, the original value would be lost.

But we still need that original value to update `max`.

Example:

```text
arr[i] = 18
max = 6
```

We need to:

```text
arr[i] = 6
```

and also compare:

```text
18 > 6
```

Therefore we save:

```cpp
int temp = arr[i];
```

So:

```text
temp     = original value
arr[i]   = answer for current index
max      = maximum for future indices
```

---

## Code

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max = -1;

        for(int i = n - 1; i >= 0; i--)
        {
            int temp = arr[i];

            arr[i] = max;

            if(temp > max)
            {
                max = temp;
            }
        }

        return arr;
    }
};
```

---

## Code Explanation

### Get Size

```cpp
int n = arr.size();
```

For:

```text
arr = [17,18,5,4,6,1]
```

we have:

```text
n = 6
```

Last index:

```text
n - 1 = 5
```

---

### Initialize `max`

```cpp
int max = -1;
```

The last element has nothing on its right, so it becomes `-1`.

As we move left, `max` represents the greatest value seen on the right.

---

### Traverse Right to Left

```cpp
for(int i = n - 1; i >= 0; i--)
```

The traversal is:

```text
5 → 4 → 3 → 2 → 1 → 0
```

This makes the right-side maximum available before processing each element.

---

### Save Original Value

```cpp
int temp = arr[i];
```

We save the original value because `arr[i]` will be overwritten.

---

### Replace Current Value

```cpp
arr[i] = max;
```

At this point, `max` is the greatest element among all elements to the right.

So it is exactly the value required by the problem.

---

### Update Maximum

```cpp
if(temp > max)
{
    max = temp;
}
```

If the original current value is greater than the previous maximum, it becomes the new maximum for elements further left.

---

### Return

```cpp
return arr;
```

The input array was modified **in-place**, so we simply return it.

---

## Core Logic

The entire solution can be remembered as:

```cpp
int temp = arr[i];

arr[i] = max;

if(temp > max)
{
    max = temp;
}
```

Meaning:

```text
1. Save current value
2. Put right-side maximum here
3. Update maximum using saved value
```

---

## Why Is `max` Correct?

At index `i`, because we are moving right to left, every index greater than `i` has already been processed.

Therefore:

```text
max = greatest value among arr[i+1 ... n-1]
```

So:

```cpp
arr[i] = max;
```

places exactly the greatest element to the right.

Then the original `arr[i]` is considered for the next position to the left.

---

## Why Not Use Nested Loops?

A straightforward solution would search the entire right side for every index:

```cpp
for(int i = 0; i < n; i++)
{
    int max = -1;

    for(int j = i + 1; j < n; j++)
    {
        max = std::max(max, arr[j]);
    }

    arr[i] = max;
}
```

This takes:

```text
O(n²)
```

time.

The right-to-left running maximum approach takes:

```text
O(n)
```

time.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We visit every element exactly once.

Each iteration performs constant-time work.

---

### Space Complexity

```text
O(1)
```

The array is modified in-place.

Only a few variables are used:

```text
n
max
temp
i
```

---

## Edge Cases

### Single Element

```text
arr = [400]
```

Output:

```text
[-1]
```

### Increasing Array

```text
arr = [1,2,3,4]
```

Output:

```text
[4,4,4,-1]
```

### Decreasing Array

```text
arr = [4,3,2,1]
```

Output:

```text
[3,2,1,-1]
```

### All Elements Equal

```text
arr = [5,5,5]
```

Output:

```text
[5,5,-1]
```

---

## Key Learning

This problem teaches an important **right-to-left traversal pattern**.

Whenever a problem asks about:

```text
greatest / smallest element on the right
```

consider processing:

```text
Right → Left
```

while maintaining information about the elements already visited.

For a maximum:

```cpp
max = std::max(max, current);
```

The general pattern is:

```text
Right → Left
Track maximum
Replace current
Update maximum
```

---

## Pattern to Remember

### Suffix Maximum Pattern

```cpp
int max = -1;

for(int i = n - 1; i >= 0; i--)
{
    int temp = arr[i];

    arr[i] = max;

    if(temp > max)
    {
        max = temp;
    }
}
```

This pattern is useful for:

* Greatest element on the right
* Suffix maximum
* Array leader problems
* Right-side comparisons
* Next-greater-style problems

---

## In-Place Advantage

Before:

```text
[17,18,5,4,6,1]
```

After:

```text
[18,6,6,6,1,-1]
```

No second result array is required.

Therefore:

```text
Extra Space = O(1)
```

---

## Final Complexity

| Approach | Time | Extra Space |
| -------- | ---- | ----------- |
| Nested Loops | `O(n²)` | `O(1)` |
| Right-to-Left Maximum | `O(n)` | `O(1)` |

### Best Approach

```text
Right-to-Left traversal + running maximum
```

because it solves the problem in:

```text
O(n) time
O(1) extra space
```
