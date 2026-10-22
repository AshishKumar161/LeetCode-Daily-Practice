# 237. Delete Node in a Linked List

**LeetCode:** [237. Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)  
**Difficulty:** Medium · **Topic:** Linked List

## Problem Statement

You are given a node in a singly linked list to delete. You are not given the head of the list, and the given node is guaranteed not to be the last node.

Delete the given node while preserving the order of all remaining values and reducing the list length by one.

## Examples

**Example 1**  
Input: `head = [4,5,1,9]`, `node = 5`  
Output: `[4,1,9]`

**Example 2**  
Input: `head = [4,5,1,9]`, `node = 1`  
Output: `[4,5,9]`

## Key Constraint

The given node is not the tail, so `node->next` is guaranteed to exist.

## Approach

Since the head and previous node are unavailable, we cannot unlink the given node in the usual way. Instead:

1. Copy the next node's value into the given node.
2. Save a pointer to the next node.
3. Make the given node point to the node after the next node.
4. Delete the bypassed node from memory.

See [`leetcode_237_explanation.md`](leetcode_237_explanation.md) for the C++ implementation, dry run, and complexity.
