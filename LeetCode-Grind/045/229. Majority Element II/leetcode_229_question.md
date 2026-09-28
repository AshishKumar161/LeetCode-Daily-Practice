# LeetCode 229 - Majority Element II

## Question

Given an integer array `nums` of size `n`, find all elements that appear more than:

```text
⌊n / 3⌋
```

times.

The answer can contain at most two elements.

## Example 1

```text
Input: nums = [3,2,3]
Output: [3]
```

`3` appears 2 times and:

```text
⌊3 / 3⌋ = 1
```

so `3` qualifies.

## Example 2

```text
Input: nums = [1]
Output: [1]
```

## Example 3

```text
Input: nums = [1,2]
Output: [1,2]
```

Both elements appear more than:

```text
⌊2 / 3⌋ = 0
```

times.

## Topics

- Array
- Hash Table
- Counting
- Boyer-Moore Voting Algorithm
