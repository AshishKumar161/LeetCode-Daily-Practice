# LeetCode 512: Leaders in an Array

## Approach

Your solution scans the array from **left to right**.

For every current position `i`, it finds the maximum element in the suffix:

```text
nums[i ... n-1]
```

That maximum is guaranteed to be a leader because it is greater than every element to its right.

After finding it, the code jumps to the position immediately after it:

```cpp
i = store + 1;
```

The process is:

```text
Start at i
   ↓
Find maximum from i to n-1
   ↓
Maximum is a leader
   ↓
Add it to answer
   ↓
Move after its position
   ↓
Repeat
```

## Your Code

```cpp
class Solution {
public:
    vector<int> leaders(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> leader;

        int i = 0;

        while (i < n)
        {
            int store = i;

            for (int j = i; j < n; j++)
            {
                if (nums[store] < nums[j])
                {
                    store = j;
                }
            }

            leader.push_back(nums[store]);
            i = store + 1;
        }

        // reverse(leader.begin(), leader.end());

        return leader;
    }
};
```

---

# Step-by-Step Explanation

## 1. Find the Array Size

```cpp
int n = nums.size();
```

For:

```text
nums = [1,2,5,3,1,2]
```

we get:

```text
n = 6
```

---

## 2. Create the Answer Vector

```cpp
vector<int> leader;
```

Initially:

```text
leader = []
```

It will contain all the leaders.

---

## 3. Start From Index 0

```cpp
int i = 0;
```

`i` represents the beginning of the current suffix.

Initially:

```text
[1,2,5,3,1,2]
 ^
 i
```

---

## 4. Store the Current Maximum Index

```cpp
int store = i;
```

Initially:

```text
store = 0
```

So we temporarily assume:

```text
nums[0] = 1
```

is the maximum.

---

## 5. Find the Maximum in the Current Suffix

```cpp
for (int j = i; j < n; j++)
{
    if (nums[store] < nums[j])
    {
        store = j;
    }
}
```

For:

```text
[1,2,5,3,1,2]
```

the comparisons are:

```text
1 < 1 → false
1 < 2 → true  → store = 1
2 < 5 → true  → store = 2
5 < 3 → false
5 < 1 → false
5 < 2 → false
```

Therefore:

```text
store = 2
nums[store] = 5
```

`5` is a leader because:

```text
5 > 3
5 > 1
5 > 2
```

---

## 6. Add the Leader

```cpp
leader.push_back(nums[store]);
```

Now:

```text
leader = [5]
```

---

## 7. Move After the Leader

```cpp
i = store + 1;
```

Since:

```text
store = 2
```

we get:

```text
i = 3
```

Now the remaining suffix is:

```text
[3,1,2]
```

The elements before index `3` do not need to be checked again.

---

# Complete Dry Run

Input:

```text
nums = [1,2,5,3,1,2]
```

### Iteration 1

```text
i = 0
range = [1,2,5,3,1,2]
maximum = 5
store = 2
```

Add:

```text
leader = [5]
```

Move:

```text
i = 3
```

### Iteration 2

```text
i = 3
range = [3,1,2]
maximum = 3
store = 3
```

Add:

```text
leader = [5,3]
```

Move:

```text
i = 4
```

### Iteration 3

```text
i = 4
range = [1,2]
maximum = 2
store = 5
```

Add:

```text
leader = [5,3,2]
```

Move:

```text
i = 6
```

Since:

```text
i == n
```

the loop ends.

Final:

```text
[5,3,2]
```

---

# Dry Run Table

| Iteration | `i` | Current Range | Maximum | `store` | Leaders |
|---:|---:|---|---:|---:|---|
| 1 | 0 | `[1,2,5,3,1,2]` | 5 | 2 | `[5]` |
| 2 | 3 | `[3,1,2]` | 3 | 3 | `[5,3]` |
| 3 | 4 | `[1,2]` | 2 | 5 | `[5,3,2]` |

---

# Why Does Finding the Maximum Give a Leader?

Suppose the current suffix is:

```text
[3,1,2]
```

The maximum is:

```text
3
```

Because `3` is the largest element in that suffix:

```text
3 > 1
3 > 2
```

Therefore `3` is strictly greater than every element to its right.

So it must be a leader.

---

# Why `i = store + 1`?

Suppose:

```text
store = 2
```

Then:

```text
nums[2]
```

has already been identified as a leader.

All future leaders must be to its right.

Therefore:

```cpp
i = store + 1;
```

moves directly to the next possible position.

---

# Why Is the Rightmost Element Always a Leader?

The last element has no elements to its right.

Therefore it automatically satisfies the leader condition.

For:

```text
[4,2,3]
```

the final:

```text
3
```

is a leader.

Your algorithm naturally handles this because when only the last element remains, it becomes the maximum of the remaining suffix.

---

# Equal Values

The condition is:

```cpp
if (nums[store] < nums[j])
```

not:

```cpp
if (nums[store] <= nums[j])
```

This matches the word **strictly** in the problem.

For:

```text
nums = [5,5]
```

the first `5` is not a leader because it is not strictly greater than the `5` on its right.

The last `5` is a leader.

---

# Why `reverse()` Is Commented Out

Your code has:

```cpp
// reverse(leader.begin(), leader.end());
```

You do **not** need it.

Your algorithm discovers leaders from left to right:

```text
5 → 3 → 2
```

which is already the required order:

```text
[5,3,2]
```

`reverse()` is normally needed in the optimized right-to-left approach because that approach discovers:

```text
2 → 3 → 5
```

and then reverses the result.

---

# Example 2

Input:

```text
nums = [-3,4,5,1,-4,-5]
```

### First suffix

```text
[-3,4,5,1,-4,-5]
```

Maximum:

```text
5
```

Leader:

```text
[5]
```

Next:

```text
i = 3
```

### Second suffix

```text
[1,-4,-5]
```

Maximum:

```text
1
```

Leader:

```text
[5,1]
```

### Third suffix

```text
[-4,-5]
```

Maximum:

```text
-4
```

Leader:

```text
[5,1,-4]
```

### Final element

```text
[-5]
```

Leader:

```text
[5,1,-4,-5]
```

Final answer:

```text
[5,1,-4,-5]
```

---

# Complexity Analysis

Your solution contains:

```cpp
while (i < n)
```

and inside it:

```cpp
for (int j = i; j < n; j++)
```

In the worst case, the inner loop scans large portions of the array repeatedly.

Therefore:

```text
Time Complexity = O(n²)
```

The answer vector stores the leaders.

In the worst case, all elements can be leaders, so:

```text
Output Space = O(n)
```

Apart from the returned vector, only a few variables are used:

```text
i
j
store
```

Therefore:

```text
Auxiliary Space = O(1)
```

For your submitted solution:

```text
Time: O(n²) worst case
Auxiliary Space: O(1)
Output Space: O(n)
```

---

# Optimized Idea

There is an important optimization for this problem.

Instead of repeatedly finding the maximum of every suffix, scan from **right to left** while maintaining:

```text
maximum seen so far
```

For:

```text
[1,2,5,3,1,2]
```

scan from the right:

```text
2 → leader
1 < 2 → not leader
3 > 2 → leader
5 > 3 → leader
2 < 5 → not leader
1 < 5 → not leader
```

Discovered leaders:

```text
[2,3,5]
```

Then reverse:

```text
[5,3,2]
```

This optimized method is:

```text
Time: O(n)
Auxiliary Space: O(1)
Output Space: O(n)
```

---

# Key Learning

Your solution teaches the idea:

```text
Find maximum of current suffix
        ↓
That maximum is a leader
        ↓
Jump after it
        ↓
Repeat
```

It also gives the intuition for the optimized:

```text
Right-to-left + running maximum
```

solution.

---

# Pattern to Remember

Your approach:

```cpp
int i = 0;

while (i < n)
{
    int store = i;

    for (int j = i; j < n; j++)
    {
        if (nums[store] < nums[j])
        {
            store = j;
        }
    }

    leader.push_back(nums[store]);

    i = store + 1;
}
```

Think:

```text
Current suffix
      ↓
Find maximum
      ↓
Maximum is a leader
      ↓
Jump after it
      ↓
Repeat
```

---

# Final Complexity

| Approach | Time | Auxiliary Space | Output Space |
|---|---:|---:|---:|
| Your solution | `O(n²)` worst case | `O(1)` | `O(n)` |
| Right-to-left + running maximum | `O(n)` | `O(1)` | `O(n)` |

For **your submitted solution**:

```text
Time:  O(n²) worst case
Space: O(1) auxiliary
Output: O(n)
```
