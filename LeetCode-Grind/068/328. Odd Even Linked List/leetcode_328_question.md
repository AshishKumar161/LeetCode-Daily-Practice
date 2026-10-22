# 328. Odd Even Linked List

**LeetCode:** [328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)  
**Difficulty:** Medium · **Topic:** Linked List

## Problem Statement

Given the head of a singly linked list, group nodes at odd indices together, followed by nodes at even indices. Preserve the relative order within each group.

The first node has index `1` (odd), the second has index `2` (even), and so on. Odd/even refers to node position, not node value.

## Examples

**Example 1**  
Input: `head = [1,2,3,4,5]`  
Output: `[1,3,5,2,4]`

**Example 2**  
Input: `head = [2,1,3,5,6,4,7]`  
Output: `[2,3,6,7,1,5,4]`

## Constraints

- The number of nodes is in the range `[0, 10^4]`.
- `-10^6 <= Node.val <= 10^6`

## Required Complexity

- Time: `O(n)`
- Extra space: `O(1)`

## Approach

1. Return immediately if the list has zero or one node.
2. Use `oddptr` for the odd chain and `evenptr` for the even chain.
3. Save the start of the even chain in `even`.
4. Rewire pointers to connect the next odd node, then the next even node.
5. Attach the even chain after the final odd node.

See [`leetcode_328_explanation.md`](leetcode_328_explanation.md) for the code, pointer logic, dry run, and complexity.
