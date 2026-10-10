# 2095. Delete the Middle Node of a Linked List

**LeetCode:** [2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)  
**Difficulty:** Medium  
**Topics:** Linked List

## Problem Statement

You are given the `head` of a linked list. Delete the middle node and return the head of the modified list.

For a list with `n` nodes, the middle node is at index `n / 2` using **0-based indexing**. For an even number of nodes, this means deleting the second of the two central nodes.

## Examples

### Example 1
**Input:** `head = [1,3,4,7,1,2,6]`  
**Output:** `[1,3,4,1,2,6]`  
**Explanation:** There are 7 nodes. The middle node is at index `7 / 2 = 3`, with value `7`.

### Example 2
**Input:** `head = [1,2,3,4]`  
**Output:** `[1,2,4]`  
**Explanation:** There are 4 nodes. The middle node is at index `4 / 2 = 2`, with value `3`.

### Example 3
**Input:** `head = [2,1]`  
**Output:** `[2]`  
**Explanation:** The middle node is at index `2 / 2 = 1`, with value `1`.

## Constraints
- The number of nodes is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`.

## Approach
This solution uses two traversals:

1. Count all nodes in the linked list.
2. Calculate `mid = count / 2`.
3. Traverse again to reach the node immediately before the middle node.
4. Save the middle node, skip it by changing the previous node's `next` pointer, and delete it.
5. Return `head`.

If the list is empty or has only one node, return `nullptr`, because deleting its middle node leaves an empty list.

See [`leetcode_2095_explanation.md`](leetcode_2095_explanation.md) for the code and detailed explanation.
