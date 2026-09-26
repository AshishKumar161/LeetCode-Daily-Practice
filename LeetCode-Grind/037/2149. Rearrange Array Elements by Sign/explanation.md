# LeetCode 2149: Rearrange Array Elements by Sign

## Approach

Your solution uses two vectors:

```cpp
vector<int> positive;
vector<int> negative;
```

The idea is:

```text
Separate positive and negative numbers
        ↓
Preserve their original order
        ↓
Take one positive
        ↓
Take one negative
        ↓
Repeat
```

Because the problem guarantees an equal number of positive and negative values, we can safely use the same index in both vectors.

## Code

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                positive.push_back(nums[i]);
            }
            else
            {
                negative.push_back(nums[i]);
            }
        }

        vector<int> answer;

        for (int i = 0; i < positive.size(); i++)
        {
            answer.push_back(positive[i]);
            answer.push_back(negative[i]);
        }

        return answer;
    }
};
```

## Step 1: Separate the Numbers

```cpp
vector<int> positive;
vector<int> negative;
```

`positive` stores positive values and `negative` stores negative values.

For:

```text
nums = [3,1,-2,-5,2,-4]
```

we get:

```text
positive = [3,1,2]
negative = [-2,-5,-4]
```

## Step 2: Scan the Original Array

```cpp
for (int i = 0; i < nums.size(); i++)
{
    if (nums[i] > 0)
        positive.push_back(nums[i]);
    else
        negative.push_back(nums[i]);
}
```

The scan goes from left to right.

That is important because `push_back()` preserves the order in which same-sign elements appeared.

For example:

```text
Original positive order:
3 → 1 → 2

positive vector:
[3,1,2]
```

and:

```text
Original negative order:
-2 → -5 → -4

negative vector:
[-2,-5,-4]
```

## Step 3: Build the Answer

```cpp
for (int i = 0; i < positive.size(); i++)
{
    answer.push_back(positive[i]);
    answer.push_back(negative[i]);
}
```

For every index we add:

```text
positive[i]
negative[i]
```

So the pattern becomes:

```text
+ - + - + -
```

For the example:

```text
i = 0 → 3, -2
i = 1 → 1, -5
i = 2 → 2, -4
```

Final:

```text
[3,-2,1,-5,2,-4]
```

## Detailed Dry Run

Input:

```text
nums = [3,1,-2,-5,2,-4]
```

### Separation

Start:

```text
positive = []
negative = []
```

| Index | Value | Positive | Negative |
|------:|------:|----------|----------|
| 0 | 3 | `[3]` | `[]` |
| 1 | 1 | `[3,1]` | `[]` |
| 2 | -2 | `[3,1]` | `[-2]` |
| 3 | -5 | `[3,1]` | `[-2,-5]` |
| 4 | 2 | `[3,1,2]` | `[-2,-5]` |
| 5 | -4 | `[3,1,2]` | `[-2,-5,-4]` |

Now:

```text
positive = [3,1,2]
negative = [-2,-5,-4]
```

### Merge

| `i` | Positive | Negative | Answer |
|----:|---------:|---------:|--------|
| 0 | 3 | -2 | `[3,-2]` |
| 1 | 1 | -5 | `[3,-2,1,-5]` |
| 2 | 2 | -4 | `[3,-2,1,-5,2,-4]` |

Final answer:

```text
[3,-2,1,-5,2,-4]
```

## Why Does It Start With Positive?

The code always inserts:

```cpp
answer.push_back(positive[i]);
```

before:

```cpp
answer.push_back(negative[i]);
```

Therefore the first element is positive.

## Why Do Signs Alternate?

Each iteration inserts exactly:

```text
positive → negative
```

Therefore the resulting pattern is:

```text
+ - + - + -
```

So every consecutive pair has opposite signs.

## Why Is Relative Order Preserved?

The first loop scans `nums` from left to right.

For:

```text
nums = [3,1,-2,-5,2,-4]
```

the positive values are encountered as:

```text
3 → 1 → 2
```

and stored as:

```text
[3,1,2]
```

The negative values are encountered as:

```text
-2 → -5 → -4
```

and stored as:

```text
[-2,-5,-4]
```

Therefore the relative order within each sign is preserved.

## Why Can We Use `negative[i]`?

The problem guarantees an equal number of positive and negative integers.

So if:

```text
positive.size() = 3
```

then:

```text
negative.size() = 3
```

Therefore this is safe:

```cpp
negative[i]
```

for every `i` used by the loop.

## Another Example

```text
nums = [-1,2,-3,4,-5,6]
```

Separate:

```text
positive = [2,4,6]
negative = [-1,-3,-5]
```

Merge:

```text
[2,-1,4,-3,6,-5]
```

Positive order remains:

```text
2 → 4 → 6
```

Negative order remains:

```text
-1 → -3 → -5
```

## Common Mistake

Do not sort the array unnecessarily.

Sorting can change the relative order of same-sign elements, while the problem requires that order to be preserved.

The current solution avoids sorting and uses one left-to-right scan.

## Why This Is Better Than Sorting

Sorting would take approximately:

```text
O(n log n)
```

time.

Your approach only needs to:

```text
separate → merge
```

so it takes:

```text
O(n)
```

time.

## Complexity Analysis

### Time Complexity

The first loop visits every element once:

```text
O(n)
```

The second loop inserts every element into the answer:

```text
O(n)
```

Total:

```text
O(n)
```

### Space Complexity

The vectors:

```text
positive
negative
answer
```

together store the `n` elements.

Therefore:

```text
O(n)
```

extra space.

## Key Learning

This problem teaches the:

```text
Separate → Preserve Order → Alternate
```

pattern.

When a problem asks you to:

```text
separate elements into categories
+
preserve their original order
+
combine them in a required pattern
```

a useful strategy is:

```text
Create a container for each category
        ↓
Scan the original array
        ↓
Store elements in their category
        ↓
Merge categories in the required order
```

## Pattern to Remember

```cpp
vector<int> positive;
vector<int> negative;

for(int x : nums)
{
    if(x > 0)
        positive.push_back(x);
    else
        negative.push_back(x);
}

vector<int> answer;

for(int i = 0; i < positive.size(); i++)
{
    answer.push_back(positive[i]);
    answer.push_back(negative[i]);
}

return answer;
```

Think:

```text
Positive:  + + + +
Negative:  - - - -

Merge:

+ - + - + -
```

## Final Complexity

| Approach | Time | Extra Space |
| -------- | ---- | ----------- |
| Sorting-based | `O(n log n)` | Depends on implementation |
| Separate + Merge | `O(n)` | `O(n)` |

For **your submitted solution**:

```text
Time:  O(n)
Space: O(n)
```
