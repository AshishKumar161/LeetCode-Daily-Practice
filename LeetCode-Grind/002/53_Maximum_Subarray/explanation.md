# Explanation - Maximum Subarray

## Approach

This problem is solved using Kadane's Algorithm.

We keep a running sum of the current subarray.

If the current sum becomes negative, we reset it to `0` because a negative sum will reduce the sum of the next subarray.

We also keep updating the maximum sum found so far.

## Logic

```cpp
sum = sum + val;
maxx = max(sum, maxx);

if (sum < 0) {
    sum = 0;
}