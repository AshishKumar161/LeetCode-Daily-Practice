# LeetCode 119 — Pascal's Triangle II

## Your Solution

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer;

        long long ans = 1;
        answer.push_back(ans);

        for (int i = 1; i < rowIndex + 1; i++)
        {
            ans = ans * ((rowIndex + 1) - i);
            ans = ans / i;
            answer.push_back(ans);
        }

        return answer;
    }
};
```

## Approach

Instead of generating the complete Pascal's Triangle, your solution directly generates **only the required row**.

For a `0-indexed` row `rowIndex`, the elements are:

```text
C(rowIndex, 0), C(rowIndex, 1), ..., C(rowIndex, rowIndex)
```

The first element is always:

```text
1
```

Then each next element is calculated from the previous element.

### Formula

```text
C(n,k) = C(n,k-1) × (n-k+1) / k
```

Here:

```text
n = rowIndex
```

so your code uses:

```cpp
ans = ans * ((rowIndex + 1) - i);
ans = ans / i;
```

which is equivalent to:

```text
ans = ans × (rowIndex - i + 1) / i
```

## Dry Run

For:

```text
rowIndex = 3
```

Start:

```text
answer = [1]
ans = 1
```

### i = 1

```text
1 × (4 - 1) / 1
= 3
```

```text
answer = [1, 3]
```

### i = 2

```text
3 × (4 - 2) / 2
= 3
```

```text
answer = [1, 3, 3]
```

### i = 3

```text
3 × (4 - 3) / 3
= 1
```

Final:

```text
[1, 3, 3, 1]
```

## Why This Is Better Than LeetCode 118

In LeetCode 118, you need the **whole triangle**.

Here, you only need **one row**, so there is no need to build previous rows.

This makes the solution much more space efficient.

## Complexity

Let:

```text
n = rowIndex
```

The loop runs `n` times.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(n)
```

because the returned row contains `n + 1` elements.

The extra working variable `ans` uses:

```text
O(1)
```

auxiliary space.

## Important DSA Pattern

This problem reinforces:

- Pascal's Triangle
- Binomial coefficients
- Mathematical recurrence
- Iterative formula calculation
- Space optimization

### Key Difference

```text
LeetCode 118 → O(n²) time, O(n²) output space
LeetCode 119 → O(n) time,  O(n) output space
```

The main optimization is that you generate **only the requested row** instead of generating the entire triangle.
