# Explanation - Sort Colors

## Approach 1: Basic / Counting Approach

In the basic approach, we count the number of `0`, `1`, and `2`.

After counting, we overwrite the array:

- First fill all `0`
- Then fill all `1`
- Then fill all `2`

## Basic Approach Logic

```cpp
if (arr[i] == 0) {
    zero++;
}
else if (arr[i] == 1) {
    one++;
}
else {
    two++;
}
```

After counting:

```cpp
for (int i = 0; i < zero; i++) {
    arr[index] = 0;
    index++;
}

for (int i = 0; i < one; i++) {
    arr[index] = 1;
    index++;
}

for (int i = 0; i < two; i++) {
    arr[index] = 2;
    index++;
}
```

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(1)
```

---

# Approach 2: Dutch National Flag Algorithm

This is the optimized LeetCode approach.

We use three pointers:

```text
low
mid
high
```

The array is divided into parts:

```text
0 to low - 1        -> all 0
low to mid - 1      -> all 1
mid to high         -> unknown
high + 1 to n - 1   -> all 2
```

## Rules

### Case 1: nums[mid] == 0

Swap `nums[low]` and `nums[mid]`.

Then move both:

```cpp
low++;
mid++;
```

### Case 2: nums[mid] == 1

`1` is already in the correct position.

Move only:

```cpp
mid++;
```

### Case 3: nums[mid] == 2

Swap `nums[mid]` and `nums[high]`.

Move only:

```cpp
high--;
```

We do not move `mid` here because the element coming from `high` is unknown.

## Dry Run

Input:

```text
nums = [2,0,2,1,1,0]
```

Start:

```text
low = 0
mid = 0
high = 5
```

Steps:

```text
nums[mid] = 2
swap nums[mid] and nums[high]
array = [0,0,2,1,1,2]
high--

nums[mid] = 0
swap nums[low] and nums[mid]
array = [0,0,2,1,1,2]
low++
mid++

nums[mid] = 0
swap nums[low] and nums[mid]
array = [0,0,2,1,1,2]
low++
mid++

nums[mid] = 2
swap nums[mid] and nums[high]
array = [0,0,1,1,2,2]
high--

nums[mid] = 1
mid++

nums[mid] = 1
mid++
```

Final Output:

```text
[0,0,1,1,2,2]
```

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(1)
```

## Best Approach

Dutch National Flag Algorithm is better because it sorts the array in one pass.