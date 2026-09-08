# LeetCode 485: Max Consecutive Ones

## Approach

We use a **single traversal** with two variables:

```cpp
int ans = 0;
int one = 0;
```

* `one` → current consecutive count of `1`s.
* `ans` → maximum consecutive count found so far.

For every element:

```text
If it is 1 → increase one
If it is 0 → reset one to 0
```

Whenever we find a `1`, update:

```cpp
ans = max(ans, one);
```

The key pattern is:

```text
1 → increase current streak
0 → break current streak
ans → remember the largest streak
```

---

## Intuition

For:

```text
nums = [1,1,0,1,1,1]
```

we scan left to right.

```text
1 → one = 1
1 → one = 2
0 → one = 0
1 → one = 1
1 → one = 2
1 → one = 3
```

The largest value ever reached by `one` is `3`.

Therefore:

```text
answer = 3
```

---

## Algorithm

1. Initialize `ans = 0`.
2. Initialize `one = 0`.
3. Traverse the array.
4. If `nums[i] == 1`:
   ```cpp
   one++;
   ans = max(ans, one);
   ```
5. Otherwise:
   ```cpp
   one = 0;
   ```
6. Return `ans`.

---

## Dry Run

Input:

```text
nums = [1,1,0,1,1,1]
```

Initially:

```text
ans = 0
one = 0
```

### Index 0

```text
nums[0] = 1
```

```text
one = 1
ans = max(0,1) = 1
```

### Index 1

```text
nums[1] = 1
```

```text
one = 2
ans = max(1,2) = 2
```

### Index 2

```text
nums[2] = 0
```

The streak breaks:

```text
one = 0
ans = 2
```

Notice that `ans` is **not reset**.

### Index 3

```text
nums[3] = 1
```

```text
one = 1
ans = max(2,1) = 2
```

### Index 4

```text
nums[4] = 1
```

```text
one = 2
ans = max(2,2) = 2
```

### Index 5

```text
nums[5] = 1
```

```text
one = 3
ans = max(2,3) = 3
```

Final:

```text
return 3
```

---

## Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int one = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                one++;
                ans = max(ans, one);
            }
            else
            {
                one = 0;
            }
        }

        return ans;
    }
};
```

---

## Code Explanation

### `ans`

```cpp
int ans = 0;
```

`ans` stores the **largest streak found anywhere in the array**.

It never needs to be reset when a `0` appears.

---

### `one`

```cpp
int one = 0;
```

`one` stores the number of consecutive `1`s in the **current streak**.

Example:

```text
[1,1,1]
```

gives:

```text
one = 3
```

But after a `0`:

```text
[1,1,0]
```

the current streak becomes:

```text
one = 0
```

---

### Traverse the Array

```cpp
for(int i = 0; i < nums.size(); i++)
```

We process every element exactly once.

---

### When the Element is `1`

```cpp
if(nums[i] == 1)
{
    one++;
    ans = max(ans, one);
}
```

A `1` continues the current streak.

So:

```cpp
one++;
```

Then compare the current streak with the best streak:

```cpp
ans = max(ans, one);
```

---

### When the Element is `0`

```cpp
else
{
    one = 0;
}
```

A `0` breaks the consecutive sequence.

So the current count is reset.

But `ans` is preserved because an earlier sequence may still be the maximum.

---

## Difference Between `one` and `ans`

This is the most important concept.

### `one`

```text
Current consecutive 1s
```

### `ans`

```text
Maximum consecutive 1s found so far
```

Example:

```text
nums = [1,1,0,1]
```

After the `0`:

```text
one = 0
ans = 2
```

So:

```text
one → current streak
ans → overall best
```

---

## Why Does This Work?

A consecutive sequence continues only while the elements are `1`.

Therefore:

```text
1 → count++
0 → count = 0
```

Every time the current count increases, we compare it with the maximum.

At the end, `ans` contains the longest consecutive sequence of `1`s.

---

## Another Dry Run

Consider:

```text
nums = [1,0,1,1,0,1,1,1,1]
```

| Index | Value | `one` | `ans` |
|------:|------:|------:|------:|
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 |
| 2 | 1 | 1 | 1 |
| 3 | 1 | 2 | 2 |
| 4 | 0 | 0 | 2 |
| 5 | 1 | 1 | 2 |
| 6 | 1 | 2 | 2 |
| 7 | 1 | 3 | 3 |
| 8 | 1 | 4 | 4 |

Final answer:

```text
4
```

---

## Why Only One Loop?

We do not need to search for every group separately.

Each element gives us exactly the information we need:

```text
1 → continue streak
0 → reset streak
```

So one pass is enough.

---

## Edge Cases

### All Ones

```text
nums = [1,1,1,1]
```

Output:

```text
4
```

### All Zeros

```text
nums = [0,0,0]
```

Output:

```text
0
```

### Single One

```text
nums = [1]
```

Output:

```text
1
```

### Single Zero

```text
nums = [0]
```

Output:

```text
0
```

---

## Key Learning

This problem teaches the **current count + maximum count** pattern.

Whenever a problem asks for the maximum length of a consecutive sequence, consider maintaining:

```text
current count
maximum count
```

The pattern is:

```text
Condition true  → count++
Condition false → count = 0
Always track maximum
```

---

## Pattern to Remember

```cpp
int ans = 0;
int count = 0;

for(each element)
{
    if(condition)
    {
        count++;
        ans = max(ans, count);
    }
    else
    {
        count = 0;
    }
}

return ans;
```

For this problem, the condition is:

```cpp
nums[i] == 1
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

Every element is visited exactly once.

### Space Complexity

```text
O(1)
```

Only `ans` and `one` are used as extra variables.

---

## Final Complexity

| Metric | Complexity |
| ------ | ---------- |
| Time | `O(n)` |
| Extra Space | `O(1)` |

### Best Approach

```text
Single traversal + current count + maximum count
```

This gives:

```text
O(n) time
O(1) extra space
```
