# LeetCode 169: Majority Element

## Approach

Your solution uses an **`unordered_map`** to count how many times each number appears.

The main idea is:

```text
Count the frequency of every number
        ↓
Check each number's frequency
        ↓
If frequency > n/2
        ↓
That number is the majority element
```

The important condition is:

```cpp
x.second > n / 2
```

where:

```text
x.first  → the number
x.second → its frequency
```

---

## Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> hash;

        for(int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }

        for(auto x : hash)
        {
            if(x.second > n/2)
            {
                return x.first;
            }
        }
    }
};
```

---

# Step 1: Find `n`

```cpp
int n = nums.size();
```

`n` is the number of elements in the array.

For:

```text
nums = [3,2,3]
```

we have:

```text
n = 3
```

The majority element must appear more than:

```text
n / 2
```

times.

Since integer division is used:

```text
3 / 2 = 1
```

So the majority element must appear:

```text
more than 1 time
```

Therefore it must appear at least:

```text
2 times
```

---

# Step 2: Create the Hash Map

```cpp
unordered_map<int, int> hash;
```

The map stores:

```text
number → frequency
```

For example:

```text
nums = [3,2,3]
```

the final map will contain:

```text
3 → 2
2 → 1
```

Meaning:

```text
3 appears 2 times
2 appears 1 time
```

---

# Step 3: Count Frequencies

```cpp
for(int i = 0; i < n; i++)
{
    hash[nums[i]]++;
}
```

This is the main counting loop.

The expression:

```cpp
hash[nums[i]]++;
```

means:

```text
Find nums[i] in the map
+
increase its frequency by 1
```

If the key does not exist, `unordered_map` creates it with a default integer value of `0`, then `++` changes it to `1`.

---

## Example

For:

```text
nums = [3,2,3]
```

### First element

```text
nums[0] = 3
```

Initially:

```text
hash[3] = 0
```

After:

```cpp
hash[3]++;
```

we get:

```text
hash[3] = 1
```

---

### Second element

```text
nums[1] = 2
```

Now:

```text
hash[2] = 1
```

Map:

```text
3 → 1
2 → 1
```

---

### Third element

```text
nums[2] = 3
```

`3` already exists.

Increase its count:

```text
hash[3] = 2
```

Final map:

```text
3 → 2
2 → 1
```

---

# Step 4: Traverse the Hash Map

```cpp
for(auto x : hash)
```

This loops through every key-value pair in the map.

Each `x` contains:

```text
x.first
x.second
```

where:

```text
x.first  = number
x.second = frequency
```

For example:

```text
x.first = 3
x.second = 2
```

means:

```text
number 3 appears 2 times
```

---

# Step 5: Check the Majority Condition

```cpp
if(x.second > n/2)
```

This checks whether the current number appears more than half of the array.

For:

```text
n = 7
```

we have:

```text
n/2 = 3
```

The majority condition is:

```text
frequency > 3
```

Therefore a frequency of:

```text
4
```

is enough.

But:

```text
3
```

is not enough.

The problem specifically says:

```text
more than n/2
```

not:

```text
greater than or equal to n/2
```

---

# Step 6: Return the Majority Element

```cpp
return x.first;
```

Once a frequency greater than `n/2` is found, `x.first` is the majority element.

---

# Detailed Dry Run

Consider:

```text
nums = [2,2,1,1,1,2,2]
```

First:

```text
n = 7
```

Majority threshold:

```text
n / 2 = 3
```

So we need a frequency:

```text
> 3
```

---

## Build the Hash Map

Process each element:

```text
2 → count 1
2 → count 2
1 → count 1
1 → count 2
1 → count 3
2 → count 3
2 → count 4
```

Final frequencies:

```text
2 → 4
1 → 3
```

---

## Check Frequencies

For number `2`:

```text
frequency = 4
```

Check:

```text
4 > 7/2
4 > 3
```

True.

Therefore:

```cpp
return 2;
```

Final answer:

```text
2
```

---

# Dry Run Table

For:

```text
nums = [2,2,1,1,1,2,2]
```

| Index | Value | Count of 1 | Count of 2 |
|------:|------:|-----------:|-----------:|
| 0 | 2 | 0 | 1 |
| 1 | 2 | 0 | 2 |
| 2 | 1 | 1 | 2 |
| 3 | 1 | 2 | 2 |
| 4 | 1 | 3 | 2 |
| 5 | 2 | 3 | 3 |
| 6 | 2 | 3 | 4 |

Final:

```text
1 → 3
2 → 4
```

Since:

```text
4 > 7/2
```

the answer is:

```text
2
```

---

# Why Does `hash[nums[i]]++` Work?

This line:

```cpp
hash[nums[i]]++;
```

is a common C++ frequency-counting pattern.

Suppose:

```text
nums[i] = 5
```

If `5` is not in the map:

```cpp
hash[5]
```

creates the key with default integer value:

```text
0
```

Then:

```cpp
hash[5]++;
```

changes:

```text
0 → 1
```

If `5` already has frequency `3`:

```text
3 → 4
```

So this single line handles both:

```text
first occurrence
```

and:

```text
later occurrences
```

---

# Why Is the Answer Guaranteed to Exist?

The problem explicitly guarantees:

```text
The majority element always exists.
```

Therefore, there is guaranteed to be some value whose frequency satisfies:

```text
frequency > n/2
```

So the second loop will find one.

---

# Why Can There Be Only One Majority Element?

There cannot be two different elements that both appear more than half the time.

For example, if:

```text
n = 10
```

a majority element must appear:

```text
> 5
```

times.

Two different elements would therefore need more than:

```text
5 + 5 = 10
```

occurrences, which is impossible in an array containing only 10 elements.

Therefore the majority element is unique.

---

# Why Use a Hash Map?

Without a hash map, we would need another method to count occurrences.

The hash map gives us a direct relationship:

```text
number → frequency
```

This makes frequency counting straightforward.

This is a very common pattern in coding problems.

---

# Common Frequency Pattern

Whenever a problem asks:

```text
How many times does each value occur?
```

think:

```cpp
unordered_map<int,int> hash;

for(int x : nums)
{
    hash[x]++;
}
```

Then:

```cpp
for(auto x : hash)
{
    int value = x.first;
    int frequency = x.second;
}
```

This pattern is useful for:

* Frequency counting
* Duplicate detection
* Majority element
* Most frequent element
* Anagram problems
* Counting occurrences

---

# Why `x.first` and `x.second`?

For:

```cpp
for(auto x : hash)
```

`x` is a key-value pair.

Conceptually:

```text
x = {key, value}
```

Therefore:

```cpp
x.first
```

means:

```text
key
```

and:

```cpp
x.second
```

means:

```text
value
```

In this problem:

```text
x.first  → number
x.second → frequency
```

So:

```cpp
return x.first;
```

returns the number itself.

---

# Important Detail About `unordered_map`

The iteration order of:

```cpp
unordered_map
```

is not guaranteed.

But that does not matter here.

Why?

Because there is only one majority element.

We are not looking for a specific ordering.

We only need to find the one key whose frequency is greater than `n/2`.

---

# Brute Force Approach

A brute-force solution could count the occurrences of every element separately.

For every element:

```text
Count how many times it appears
```

This can take:

```text
O(n²)
```

time.

The hash-map solution counts everything in one pass:

```text
O(n)
```

average time.

---

# Complexity Analysis

## Time Complexity

First loop:

```text
O(n)
```

Second loop:

```text
O(k)
```

where `k` is the number of distinct values.

Since:

```text
k <= n
```

the overall average time is:

```text
O(n)
```

---

## Space Complexity

The hash map can store up to `n` distinct values.

Therefore:

```text
O(n)
```

extra space.

For the submitted approach:

```text
Time:  O(n) average
Space: O(n)
```

---

# Edge Cases

## 1. One Element

```text
nums = [5]
```

Here:

```text
n = 1
n/2 = 0
```

Frequency:

```text
5 → 1
```

Check:

```text
1 > 0
```

True.

Answer:

```text
5
```

---

## 2. All Elements Are the Same

```text
nums = [7,7,7,7]
```

Frequency:

```text
7 → 4
```

Since:

```text
4 > 4/2
```

the answer is:

```text
7
```

---

## 3. Majority Appears Exactly Half

This cannot happen as the majority condition is:

```text
> n/2
```

For example, with:

```text
n = 6
```

a frequency of:

```text
3
```

is not a majority.

It must appear at least:

```text
4
```

times.

The problem guarantees that such an element exists.

---

# Alternative Solutions

There are other common ways to solve this problem:

### Sorting

Sort the array.

Because the majority element appears more than half the time, the middle element must be the majority.

Complexity:

```text
Time: O(n log n)
Space: depends on sorting implementation
```

### Boyer-Moore Voting Algorithm

This is the classic optimal approach:

```text
Time: O(n)
Space: O(1)
```

It does not need a hash map.

However, your current solution is excellent for learning the **frequency-counting with hashing** pattern.

---

# Key Learning

This problem teaches:

```text
Frequency Counting + Hash Map
```

The pattern is:

```text
Create hash map
        ↓
Count every value
        ↓
Check frequency
        ↓
Return value satisfying the condition
```

For majority element:

```text
frequency > n/2
```

---

# Pattern to Remember

```cpp
unordered_map<int,int> hash;

for(int x : nums)
{
    hash[x]++;
}

for(auto x : hash)
{
    if(x.second > nums.size()/2)
    {
        return x.first;
    }
}
```

Think:

```text
x.first  → what number?
x.second → how many times?
```

Then:

```text
frequency > half
        ↓
majority element
```

---

# Core Logic

The whole solution can be reduced to:

```text
1. Count every number.
2. Find the number occurring more than n/2 times.
3. Return it.
```

For:

```text
nums = [2,2,1,1,1,2,2]
```

we get:

```text
2 → 4
1 → 3
```

Since:

```text
4 > 7/2
```

answer:

```text
2
```

---

# Final Complexity

| Approach | Time | Extra Space |
| -------- | ---- | ----------- |
| Brute Force | `O(n²)` | `O(1)` |
| Sorting | `O(n log n)` | Depends |
| Hash Map | `O(n)` average | `O(n)` |
| Boyer-Moore | `O(n)` | `O(1)` |

For **your submitted solution**:

```text
Time:  O(n) average
Space: O(n)
```
