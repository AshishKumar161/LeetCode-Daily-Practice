# LeetCode 118 — Pascal's Triangle

## Your Approach

Your solution generates Pascal's Triangle **row by row** using the combination formula.

```cpp
vector<int> RowGenerate(int n)
{
    long long ans = 1;
    vector<int> answer;
    answer.push_back(1);

    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        answer.push_back(ans);
    }

    return answer;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(RowGenerate(i));
        }

        return ans;
    }
};
```

## How the Formula Works

For row `n`, the elements are:

```text
C(n-1, 0), C(n-1, 1), ..., C(n-1, n-1)
```

Instead of calculating factorials, you calculate the next element from the previous one:

```cpp
ans = ans * (n - i);
ans = ans / i;
```

For `n = 5`:

```text
Start: 1

i = 1 → 1 × 4 / 1 = 4
i = 2 → 4 × 3 / 2 = 6
i = 3 → 6 × 2 / 3 = 4
i = 4 → 4 × 1 / 4 = 1
```

Result:

```text
[1,4,6,4,1]
```

## Why `long long`?

You use:

```cpp
long long ans = 1;
```

because the intermediate multiplication:

```cpp
ans * (n - i)
```

can be larger than an `int` during calculation.

## Overall Algorithm

For every row from `1` to `numRows`:

1. Start the row with `1`.
2. Generate the remaining values using the combination formula.
3. Add the row to the answer.

## Complexity

The first `n` rows contain:

```text
1 + 2 + ... + n
= n(n+1)/2
```

elements.

Therefore:

```text
Time Complexity:  O(n²)
Space Complexity: O(n²)
```

`O(n²)` space is required for the returned triangle.

Extra working space apart from the answer is `O(n)`.

## Important Pattern

This problem teaches:

- Mathematical combinations
- Row-by-row construction
- Avoiding factorial calculations
- Efficient iterative formula generation

### Key Formula

```text
C(n,k) = C(n,k-1) × (n-k+1) / k
```

Your implementation applies this formula using `n-1` as the combination base.

### Final Takeaway

```text
Generate each row
      ↓
Start with 1
      ↓
Calculate next value from previous value
      ↓
Store the row
```

**Time: O(n²)**  
**Space: O(n²)**
