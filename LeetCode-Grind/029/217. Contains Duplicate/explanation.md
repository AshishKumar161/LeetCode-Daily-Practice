# LeetCode 217: Contains Duplicate

## Approach

We solve this problem using a **Hash Table (`unordered_map`)**.

The idea is:

> While traversing the array, check whether the current element has already appeared.

For every `nums[i]`:

```text
If nums[i] already exists in hash:
    Duplicate found → return true

Otherwise:
    Store nums[i] in hash
```

If we finish the complete array without finding a duplicate, return `false`.

---

## Intuition

Consider:

```text
nums = [1,2,3,1]
```

Initially:

```text
hash = {}
```

We process the elements from left to right.

For `1`:

```text
1 is not present
```

Store:

```text
1 → 0
```

For `2`:

```text
2 is not present
```

Store:

```text
2 → 1
```

For `3`:

```text
3 is not present
```

Store:

```text
3 → 2
```

For the next `1`:

```text
1 is already present
```

Therefore, a duplicate exists.

```text
return true
```

The important pattern is:

```text
Check → Store
```

---

## Algorithm

1. Create an `unordered_map` named `hash`.
2. Traverse the array using `i`.
3. Check whether `nums[i]` already exists.
4. If it exists, return `true`.
5. Otherwise store `nums[i]` and its index.
6. Continue until the array ends.
7. If no duplicate is found, return `false`.

---

## Dry Run

Consider:

```text
nums = [1,2,3,1]
```

Initially:

```text
hash = {}
```

### Step 1

```text
i = 0
nums[i] = 1
```

Check:

```text
Is 1 present?
```

No.

Store:

```text
hash[1] = 0
```

Now:

```text
hash = {1:0}
```

---

### Step 2

```text
i = 1
nums[i] = 2
```

Check:

```text
Is 2 present?
```

No.

Store:

```text
hash[2] = 1
```

Now:

```text
hash = {1:0, 2:1}
```

---

### Step 3

```text
i = 2
nums[i] = 3
```

Check:

```text
Is 3 present?
```

No.

Store:

```text
hash[3] = 2
```

Now:

```text
hash = {1:0, 2:1, 3:2}
```

---

### Step 4

```text
i = 3
nums[i] = 1
```

Check:

```text
Is 1 present?
```

Yes.

The map already contains:

```text
1 → 0
```

Therefore:

```text
return true
```

Final result:

```text
true
```

---

## Why Does This Work?

The hash map stores every element that we have already visited.

For every new element:

```cpp
hash.find(nums[i])
```

answers:

> "Have I seen this value before?"

If the value exists, it appeared at an earlier index, so it is a duplicate.

If it does not exist, we store it so that future elements can detect it.

---

## Code

```cpp
class Solution {

public:

    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            if(hash.find(nums[i]) != hash.end())
            {
                return true;
            }

            hash[nums[i]] = i;
        }

        return false;
    }

};
```

---

## Code Explanation

### Create the Hash Map

```cpp
unordered_map<int, int> hash;
```

The map stores:

```text
number → index
```

For example:

```text
1 → 0
2 → 1
3 → 2
```

For this problem, we mainly use the map to check whether a number already exists.

---

### Traverse the Array

```cpp
for (int i = 0; i < nums.size(); i++)
```

`i` visits every element from left to right.

For:

```text
nums = [1,2,3,1]
```

the values visited are:

```text
i = 0 → 1
i = 1 → 2
i = 2 → 3
i = 3 → 1
```

---

### Check Whether the Element Exists

```cpp
if(hash.find(nums[i]) != hash.end())
```

This is the most important line.

`hash.find(nums[i])` searches for the current value.

If the value does not exist:

```text
hash.find(nums[i]) == hash.end()
```

If the value exists:

```text
hash.find(nums[i]) != hash.end()
```

Therefore, this condition means:

> "The current value has already appeared."

So we found a duplicate.

---

### Return `true`

```cpp
return true;
```

As soon as a duplicate is found, we do not need to check the remaining elements.

For:

```text
nums = [1,2,3,1]
```

the second `1` is found at index `3`.

So:

```text
return true
```

---

### Store the Element

```cpp
hash[nums[i]] = i;
```

If the element is not already present, store it with its index.

For example:

```text
nums[i] = 2
i = 1
```

we store:

```text
hash[2] = 1
```

---

### Return `false`

```cpp
return false;
```

If the entire array is processed without finding a duplicate, every element is distinct.

Example:

```text
nums = [1,2,3,4]
```

Therefore:

```text
false
```

---

## Why Check Before Storing?

The order is:

```cpp
if(hash.find(nums[i]) != hash.end())
{
    return true;
}

hash[nums[i]] = i;
```

First we check.

Then we store.

Consider:

```text
nums = [3,3]
```

### First `3`

```text
3 is not in hash
```

Store:

```text
3 → 0
```

### Second `3`

```text
3 is already in hash
```

Therefore:

```text
return true
```

This is the correct duplicate-detection pattern.

---

## Hash Map State

For:

```text
nums = [1,2,3,1]
```

the map changes like this:

```text
Start:
{}

After 1:
{1:0}

After 2:
{1:0, 2:1}

After 3:
{1:0, 2:1, 3:2}

Second 1:
1 already exists → Duplicate
```

So:

```text
return true
```

---

## Alternative: `unordered_set`

For this particular problem, we do not actually need the index.

We only need to know whether a value has appeared.

So `unordered_set` is more natural:

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> hash;

        for(int i = 0; i < nums.size(); i++)
        {
            if(hash.find(nums[i]) != hash.end())
            {
                return true;
            }

            hash.insert(nums[i]);
        }

        return false;
    }
};
```

The set stores only:

```text
{1,2,3}
```

while your map stores:

```text
{1:0, 2:1, 3:2}
```

Your `unordered_map` solution is completely valid and is useful for understanding hash-map lookup.

---

## Alternative: Sorting

We can also sort the array first.

Example:

```text
Before:
[4,1,3,2,1]

After sorting:
[1,1,2,3,4]
```

Duplicate values become adjacent.

Then we can check:

```cpp
if(nums[i] == nums[i-1])
```

However, sorting takes:

```text
O(n log n)
```

time.

The hash-table approach takes:

```text
O(n)
```

average time.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the array once.

`unordered_map` lookup and insertion take **O(1) average time**.

Therefore:

```text
n × O(1) = O(n)
```

---

### Space Complexity

```text
O(n)
```

In the worst case, all elements are distinct, so we store all `n` elements in the hash map.

---

## Edge Cases

### 1. All Elements Are Distinct

```text
nums = [1,2,3,4]
```

Output:

```text
false
```

---

### 2. Duplicate at the Beginning

```text
nums = [1,1,2,3]
```

Output:

```text
true
```

---

### 3. Duplicate at the End

```text
nums = [1,2,3,1]
```

Output:

```text
true
```

---

### 4. All Elements Are the Same

```text
nums = [5,5,5,5]
```

The second `5` is already present.

Output:

```text
true
```

---

### 5. Negative Numbers

```text
nums = [-1,-2,-3,-1]
```

`-1` appears twice.

Output:

```text
true
```

---

## Key Learning

This problem teaches a fundamental **Hash Table lookup pattern**.

Whenever the problem asks:

```text
Have I seen this element before?
```

think about using:

```text
Hash Set / Hash Map
```

The pattern is:

```text
Check → Store
```

For this problem:

```cpp
if(hash.find(nums[i]) != hash.end())
{
    return true;
}

hash[nums[i]] = i;
```

---

## Pattern to Remember

```cpp
for(each element)
{
    if(element already exists)
        return true;

    store(element);
}

return false;
```

In terms of a hash map:

```cpp
if(hash.find(nums[i]) != hash.end())
{
    return true;
}

hash[nums[i]] = i;
```

This pattern is useful for:

* Detecting duplicates
* Finding repeated values
* Tracking previously seen elements
* Frequency/counting problems
* First repeated element problems

---

## Hash Map vs Hash Set

| Data Structure | Stores | Suitable? |
| -------------- | ------ | --------- |
| `unordered_map<int,int>` | Value + Index | Yes |
| `unordered_set<int>` | Value only | More natural |

Your solution uses:

```cpp
unordered_map<int, int>
```

so the structure is:

```text
number → index
```

But the duplicate check itself only needs:

```text
Does the number exist?
```

---

## Final Complexity

| Approach | Time | Space |
| -------- | ---- | ----- |
| Brute Force | `O(n²)` | `O(1)` |
| Sorting | `O(n log n)` | Depends on sorting |
| Hash Map | `O(n)` average | `O(n)` |
| Hash Set | `O(n)` average | `O(n)` |

### Best Approach

```text
Hash Table
```

because we can detect a duplicate in **O(1) average lookup time** while traversing the array only once.
