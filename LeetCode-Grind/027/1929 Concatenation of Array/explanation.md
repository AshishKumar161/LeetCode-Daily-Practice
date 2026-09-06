# LeetCode 1929: Concatenation of Array

## Approach

We can solve this problem by creating an array of size `2 * n`.

The first `n` positions contain the original `nums` array.

The next `n` positions contain the same elements again.

We use:

* `n` → stores the size of `nums`.
* `arr` → stores the final concatenated array.
* `count` → keeps track of the next empty position in `arr`.

The basic idea is:

```text
nums = [1,2,1]

First part:
[1,2,1]

Second part:
[1,2,1]

Final:
[1,2,1,1,2,1]
```

---

## Intuition

The problem simply asks us to place the same array two times consecutively.

For:

```text
nums = [1,2,1]
```

we need:

```text
ans = [1,2,1,1,2,1]
```

So we can divide the work into two parts:

```text
First copy:
arr[0]     = nums[0]
arr[1]     = nums[1]
arr[2]     = nums[2]

Second copy:
arr[3]     = nums[0]
arr[4]     = nums[1]
arr[5]     = nums[2]
```

The variable `count` tells us where the next element should be inserted.

Initially:

```text
count = 0
```

After filling the first copy, `count` becomes `n`.

Then the second loop continues filling the remaining positions.

---

## Algorithm

1. Find the size of the array:

   ```cpp
   int n = nums.size();
   ```

2. Create an array of size `2 * n`:

   ```cpp
   int arr[2*n];
   ```

3. Initialize `count = 0`.

4. Use the first loop to copy all elements of `nums` into the first half of `arr`.

5. Use the second loop to copy all elements of `nums` into the second half of `arr`.

6. Convert `arr` into a `vector<int>`.

7. Return the resulting vector.

---

## Dry Run

Consider:

```text
nums = [1,2,1]
```

Initially:

```text
n = 3
count = 0
```

The required array size is:

```text
2 * n = 6
```

So:

```text
arr = [_,_,_,_,_,_]
```

---

### First Loop

The first loop copies `nums` into the first half.

#### Step 1

```text
i = 0
nums[i] = 1
```

Store:

```text
arr[0] = nums[0]
```

Array:

```text
[1,_,_,_,_,_]
```

Then:

```text
count = 1
```

---

#### Step 2

```text
i = 1
nums[i] = 2
```

Store:

```text
arr[1] = nums[1]
```

Array:

```text
[1,2,_,_,_,_]
```

Then:

```text
count = 2
```

---

#### Step 3

```text
i = 2
nums[i] = 1
```

Store:

```text
arr[2] = nums[2]
```

Array:

```text
[1,2,1,_,_,_]
```

Then:

```text
count = 3
```

---

### Second Loop

Now `count = 3`, so the second copy starts from index `3`.

#### Step 4

```text
i = 0
nums[i] = 1
```

Store:

```text
arr[3] = nums[0]
```

Array:

```text
[1,2,1,1,_,_]
```

Then:

```text
count = 4
```

---

#### Step 5

```text
i = 1
nums[i] = 2
```

Store:

```text
arr[4] = nums[1]
```

Array:

```text
[1,2,1,1,2,_]
```

Then:

```text
count = 5
```

---

#### Step 6

```text
i = 2
nums[i] = 1
```

Store:

```text
arr[5] = nums[2]
```

Array:

```text
[1,2,1,1,2,1]
```

Then:

```text
count = 6
```

Final result:

```text
[1,2,1,1,2,1]
```

---

## Why Does This Work?

The required result is simply:

```text
nums + nums
```

The first loop puts one complete copy of `nums` into `arr`.

After that, `count` points to the first position after the first copy.

The second loop puts another complete copy of `nums` immediately after the first copy.

Therefore:

```text
arr = [nums[0], nums[1], ..., nums[n-1],
       nums[0], nums[1], ..., nums[n-1]]
```

which is exactly the required concatenation.

---

## Code

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int arr[2*n];
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            arr[i] = nums[i];
            count++;
        }

        for (int i = 0; i < n; i++)
        {
            arr[count] = nums[i];
            count++;
        }

        vector<int> ans(arr, arr + 2 * n);
        return ans;
    }
};
```

---

## Code Explanation

### `int n = nums.size()`

```cpp
int n = nums.size();
```

This stores the number of elements present in `nums`.

For example:

```text
nums = [1,2,1]

n = 3
```

The final array must contain:

```text
2 * n = 6
```

elements.

---

### Create the array

```cpp
int arr[2*n];
```

We create an array large enough to store two copies of `nums`.

For:

```text
nums = [1,2,1]
```

the size becomes:

```text
2 * 3 = 6
```

---

### Initialize `count`

```cpp
int count = 0;
```

`count` represents the next position where an element should be placed in the second part of the array.

It starts at `0` because we first fill the beginning of `arr`.

---

### First loop

```cpp
for (int i = 0; i < n; i++)
{
    arr[i] = nums[i];
    count++;
}
```

This copies the original array into the first `n` positions.

For:

```text
nums = [1,2,1]
```

we get:

```text
arr = [1,2,1,_,_,_]
```

After the loop:

```text
count = 3
```

---

### Second loop

```cpp
for (int i = 0; i < n; i++)
{
    arr[count] = nums[i];
    count++;
}
```

Now we copy `nums` again.

Since `count` is already `n`, the second copy starts exactly after the first copy.

For example:

```text
arr[3] = nums[0]
arr[4] = nums[1]
arr[5] = nums[2]
```

So:

```text
arr = [1,2,1,1,2,1]
```

---

### Create the result vector

```cpp
vector<int> ans(arr, arr + 2 * n);
```

The LeetCode function must return a `vector<int>`.

This creates a vector containing all `2 * n` elements from `arr`.

So:

```text
arr = [1,2,1,1,2,1]
```

becomes:

```text
ans = [1,2,1,1,2,1]
```

---

### Return the answer

```cpp
return ans;
```

Finally, we return the concatenated array.

---

## One Loop Alternative

The same problem can also be solved using a single loop:

```cpp
vector<int> ans(2 * n);

for (int i = 0; i < n; i++)
{
    ans[i] = nums[i];
    ans[i + n] = nums[i];
}

return ans;
```

Here, each element is placed directly into both required positions:

```text
nums[i] → ans[i]
nums[i] → ans[i+n]
```

This is a cleaner approach because it does not require the extra `arr` array or the `count` variable.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We process every element of `nums` twice.

More precisely, there are `2n` assignments, and:

```text
2n → O(n)
```

Using one loop or two loops does not change the Big-O time complexity.

Both are:

```text
O(n)
```

---

### Space Complexity

For the given code:

```text
O(n)
```

The array `arr` stores `2n` elements, and the returned vector `ans` also stores `2n` elements.

The auxiliary storage is therefore proportional to `n`.

---

## Edge Cases

### 1. Single Element

```text
nums = [5]
```

Output:

```text
[5,5]
```

---

### 2. Two Elements

```text
nums = [1,2]
```

Output:

```text
[1,2,1,2]
```

---

### 3. Repeated Elements

```text
nums = [1,1,1]
```

Output:

```text
[1,1,1,1,1,1]
```

---

## Key Learning

This problem teaches a simple but important array pattern:

```text
One array → copy it twice
```

For every element:

```text
nums[i]
```

we need to place it at:

```text
ans[i]
ans[i+n]
```

The most important observation is:

```text
First copy  → index i
Second copy → index i + n
```

---

## Pattern to Remember

Whenever a problem asks to concatenate an array with itself:

```text
nums = [a,b,c]
```

think:

```text
ans = [a,b,c,a,b,c]
```

The direct indexing pattern is:

```cpp
ans[i] = nums[i];
ans[i + n] = nums[i];
```

---

## Final Complexity

| Metric | Complexity |
| ------ | ---------- |
| Time   | `O(n)`     |
| Space  | `O(n)`     |
