# LeetCode 1838 — Explanation

## Your Approach

Your solution combines:

1. **Counting Sort** to put `nums` in sorted order.
2. **Sliding Window** to find the largest group that can be made equal.
3. A **cost formula** to calculate the required operations.

---

## 1. Why Sort?

After sorting:

```text
[1,2,4]
```

If we choose a window:

```text
[1,2,4]
```

the largest value is `4`.

Because operations can only **increase** numbers, the optimal target for this window is the largest element:

```text
target = nums[right]
```

So we try to turn every element in the window into `nums[right]`.

---

## 2. Your Counting Sort

You first find the maximum value:

```cpp
int max_val = 0;

for (int num : nums) {
    if (num > max_val)
        max_val = num;
}
```

Then create:

```cpp
vector<int> count(max_val + 1, 0);
```

and count every value.

Finally, you reconstruct `nums` in increasing order.

For example:

```text
[4,1,2,1]
```

becomes:

```text
[1,1,2,4]
```

This is Counting Sort.

---

# 3. Sliding Window

You then maintain:

```cpp
int left = 0;
long long current_sum = 0;
int max_freq = 0;
```

The current window is:

```text
[left ... right]
```

For every new `right`:

```cpp
current_sum += nums[right];
```

---

# 4. The Most Important Formula

Suppose:

```text
window = [1,2,4]
target = 4
```

Current sum:

```text
1 + 2 + 4 = 7
```

Desired array:

```text
[4,4,4]
```

Desired sum:

```text
4 + 4 + 4 = 12
```

Therefore operations required:

```text
12 - 7 = 5
```

Instead of calculating every difference individually, use:

```cpp
cost = window_size * target - current_sum;
```

So your code:

```cpp
(window_size * target) - current_sum
```

is the key idea.

---

# 5. Why the Formula Works

For:

```text
[a,b,c]
```

with target `c`:

```text
(c-a) + (c-b) + (c-c)
```

equals:

```text
3c - (a+b+c)
```

Therefore:

```text
cost = number_of_elements × target - sum
```

---

# 6. When the Window Is Invalid

You use:

```cpp
while ((window_size * target) - current_sum > k)
```

If:

```text
cost > k
```

we cannot make the entire window equal within the available operations.

So remove the leftmost element:

```cpp
current_sum -= nums[left];
left++;
```

This shrinks the window until it becomes valid.

---

# 7. Dry Run — `[1,2,4], k = 5`

### Window `[1]`

```text
target = 1
sum = 1
cost = 1 × 1 - 1 = 0
frequency = 1
```

Valid.

### Window `[1,2]`

```text
target = 2
sum = 3
cost = 2 × 2 - 3
     = 1
```

Valid because:

```text
1 <= 5
```

Frequency:

```text
2
```

### Window `[1,2,4]`

```text
target = 4
sum = 7
cost = 3 × 4 - 7
     = 5
```

Valid because:

```text
5 <= 5
```

Frequency:

```text
3
```

Answer:

```text
3
```

---

# 8. Example of Shrinking

For:

```text
nums = [1,4,8,13]
k = 5
```

Consider:

```text
[1,4,8]
```

Target:

```text
8
```

Cost:

```text
3 × 8 - (1+4+8)
= 24 - 13
= 11
```

But:

```text
11 > 5
```

So remove `1`.

Window becomes:

```text
[4,8]
```

Cost:

```text
2 × 8 - (4+8)
= 16 - 12
= 4
```

Now:

```text
4 <= 5
```

so the window is valid.

---

# 9. Why `long long`?

You correctly use:

```cpp
long long current_sum
```

and:

```cpp
long long window_size
long long target
```

because:

```cpp
window_size * target
```

can become large.

Using `long long` avoids integer-overflow problems.

---

# 10. Complexity of YOUR Exact Solution

Let:

```text
n = number of elements
M = maximum value in nums
```

Counting Sort:

```text
O(n + M)
```

Sliding Window:

```text
O(n)
```

Therefore:

```text
Time Complexity: O(n + M)
Space Complexity: O(M)
```

---

# 11. Standard LeetCode Version

The more common implementation uses:

```cpp
sort(nums.begin(), nums.end());
```

Then the same sliding window is applied.

That gives:

```text
Time: O(n log n)
Space: O(1) extra
```

Your counting-sort version can be faster when the value range `M` is reasonably small, but it uses extra memory proportional to `M`.

---

# 12. The Pattern to Memorize

This problem is mainly:

```text
SORT
  ↓
SLIDING WINDOW
  ↓
TARGET = nums[right]
  ↓
COST = target × window_size - window_sum
  ↓
cost > k ?
  ↓
YES → move left
NO  → update answer
```

The most important formula is:

```cpp
long long cost =
    1LL * (right - left + 1) * nums[right]
    - current_sum;
```

---

# Final Algorithm

```text
1. Sort the array.
2. Start left = 0.
3. Expand right.
4. Add nums[right] to the window sum.
5. Use nums[right] as the target.
6. Calculate the cost to make every value in the window equal to target.
7. If cost > k, move left until the window is valid.
8. Record the largest valid window.
9. Return it.

Time: O(n log n) with standard sorting
Space: O(1) extra
```

## Core DSA Insight

**Sorted array + sliding window + mathematical cost**

is the key pattern in LeetCode 1838.
