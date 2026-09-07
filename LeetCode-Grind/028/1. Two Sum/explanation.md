# LeetCode 1: Two Sum

## Approach

We solve this problem using a **Hash Table (`unordered_map`)**.

For every element, calculate the number required to reach the target:

``` text
need = target - nums[i]
```

Then check whether `need` has already been stored in the hash map.

The map stores:

``` text
number → index
```

If `need` exists, we have found the two required indices.

------------------------------------------------------------------------

## Intuition

Consider:

``` text
nums = [2,7,11,15]
target = 9
```

Initially:

``` text
hash = {}
```

For `2`:

``` text
need = 9 - 2 = 7
```

`7` is not present, so store:

``` text
2 → 0
```

For `7`:

``` text
need = 9 - 7 = 2
```

`2` is already present at index `0`.

Therefore:

``` text
2 + 7 = 9
```

Return:

``` text
[0,1]
```

The key idea is:

> Instead of searching for the second number, calculate exactly what
> number is required and look for it in the hash map.

------------------------------------------------------------------------

## Algorithm

1.  Create an `unordered_map` named `hash`.

2.  Traverse `nums` using index `i`.

3.  Calculate:

    ``` cpp
    int need = target - nums[i];
    ```

4.  Check whether `need` exists in the map.

5.  If it exists, return:

    ``` cpp
    return {hash[need], i};
    ```

6.  Otherwise store:

    ``` cpp
    hash[nums[i]] = i;
    ```

7.  Continue until the answer is found.

------------------------------------------------------------------------

## Dry Run

Consider:

``` text
nums = [2,7,11,15]
target = 9
```

### Step 1

``` text
i = 0
nums[i] = 2
```

Calculate:

``` text
need = 9 - 2 = 7
```

`7` is not in the map.

Store:

``` text
hash[2] = 0
```

Now:

``` text
hash = {2:0}
```

------------------------------------------------------------------------

### Step 2

``` text
i = 1
nums[i] = 7
```

Calculate:

``` text
need = 9 - 7 = 2
```

`2` exists in the map:

``` text
2 → 0
```

Therefore:

``` text
return {hash[2], 1}
```

Final answer:

``` text
[0,1]
```

Check:

``` text
nums[0] + nums[1]
= 2 + 7
= 9
```

------------------------------------------------------------------------

## Why Does This Work?

For every element:

``` text
need = target - nums[i]
```

If `need` has already appeared at index `j`, then:

``` text
nums[j] = need
```

Therefore:

``` text
nums[j] + nums[i]
= need + nums[i]
= target
```

The hash map lets us find `j` in **O(1) average time**.

------------------------------------------------------------------------

## Code

``` cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];

            if(hash.find(need) != hash.end())
            {
                return {hash[need], i};
            }

            hash[nums[i]] = i;
        }

        return {};
    }
};
```

------------------------------------------------------------------------

## Code Explanation

### Create the Hash Map

``` cpp
unordered_map<int, int> hash;
```

The map stores:

``` text
number → index
```

Example:

``` text
2 → 0
7 → 1
11 → 2
```

------------------------------------------------------------------------

### Traverse the Array

``` cpp
for(int i = 0; i < nums.size(); i++)
```

`i` visits every element from left to right.

------------------------------------------------------------------------

### Calculate `need`

``` cpp
int need = target - nums[i];
```

This tells us which number is required to make the current element reach
`target`.

For example:

``` text
target = 17
nums[i] = 5

need = 17 - 5 = 12
```

So we search for `12`.

------------------------------------------------------------------------

### Check the Hash Map

``` cpp
if(hash.find(need) != hash.end())
```

This checks whether `need` already exists.

If it exists, the required pair has been found.

------------------------------------------------------------------------

### Return the Indices

``` cpp
return {hash[need], i};
```

`hash[need]` gives the index of the previous element, while `i` is the
current index.

------------------------------------------------------------------------

### Store the Current Element

``` cpp
hash[nums[i]] = i;
```

If the pair is not found yet, store the current number and its index so
a future element can use it.

------------------------------------------------------------------------

### Why Check Before Insert?

The order is important:

``` cpp
if(hash.find(need) != hash.end())
{
    return {hash[need], i};
}

hash[nums[i]] = i;
```

We search first and insert afterward.

This prevents using the same element twice.

For:

``` text
nums = [3,3]
target = 6
```

At `i = 0`, `3` is stored.

At `i = 1`, the second `3` finds the first `3` and returns:

``` text
[0,1]
```

------------------------------------------------------------------------

## Why Not Brute Force?

Brute force checks every possible pair using two loops:

``` cpp
for(int i = 0; i < n; i++)
{
    for(int j = i + 1; j < n; j++)
    {
        if(nums[i] + nums[j] == target)
        {
            return {i, j};
        }
    }
}
```

Its time complexity is:

``` text
O(n²)
```

The hash-map approach reduces the average lookup to `O(1)`, so the
overall complexity becomes:

``` text
O(n)
```

------------------------------------------------------------------------

## Edge Cases

### 1. Pair at the Beginning

``` text
nums = [2,7,11,15]
target = 9
```

Output:

``` text
[0,1]
```

### 2. Pair at the End

``` text
nums = [1,2,3,7]
target = 10
```

Output:

``` text
[2,3]
```

### 3. Duplicate Values

``` text
nums = [3,3]
target = 6
```

Output:

``` text
[0,1]
```

### 4. Negative Numbers

``` text
nums = [-3,4,5,9]
target = 1
```

Output:

``` text
[0,1]
```

------------------------------------------------------------------------

## Key Learning

The important pattern is:

``` text
Current + Required = Target
```

Therefore:

``` text
Required = Target - Current
```

For every element:

``` text
Calculate → Search → Store
```

This is a very common **Hash Table pattern** in array problems.

------------------------------------------------------------------------

## Pattern to Remember

``` cpp
for each element:
{
    need = target - current;

    if(need exists)
        return answer;

    store current;
}
```

The most important line is:

``` cpp
int need = target - nums[i];
```

------------------------------------------------------------------------

## Complexity Analysis

  Approach      Time             Space
  ------------- ---------------- --------
  Brute Force   `O(n²)`          `O(1)`
  Hash Map      `O(n)` average   `O(n)`

### Best Approach

``` text
Hash Map
```

because it reduces the average time complexity from:

``` text
O(n²) → O(n)
```
