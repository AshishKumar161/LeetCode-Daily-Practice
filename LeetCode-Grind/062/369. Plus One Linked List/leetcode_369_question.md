# 464. Plus One Linked List

**Practice:** [Plus One Linked List — takeUforward](https://takeuforward.org/plus/dsa/problems/plus-one-linked-list)  
**Difficulty:** Medium  
**Topics:** Linked List, Math, Recursion (alternative approaches)

## Problem Statement

A non-negative integer is represented by a singly linked list of digits. The most significant digit is at the head of the list. Add one to the represented number and return the head of the updated list.

Each node contains one digit, and the digits appear in the same order as the number.

## Examples

### Example 1

**Input:** `head = [1,2,3]`  
**Output:** `[1,2,4]`  
**Explanation:** The list represents `123`. Adding one gives `124`.

### Example 2

**Input:** `head = [0]`  
**Output:** `[1]`  
**Explanation:** The list represents `0`. Adding one gives `1`.

### Example 3

**Input:** `head = [1,5,9]`  
**Output:** `[1,6,0]`  
**Explanation:** The list represents `159`. Adding one gives `160`.

## Approach Used in This Solution

The submitted approach converts the linked-list digits into a numeric value, adds one, and builds a new linked list from the result.

1. Traverse the list and build `number` using `number = number * 10 + temp->val`.
2. Add one to `number`.
3. Extract digits from right to left using `% 10` and `/ 10`.
4. Insert each extracted digit at the front of a new list, restoring the original digit order.
5. Return the new list's head.

**Important limitation:** This approach can overflow `long long` when the list contains many digits. Linked-list problems can have far more digits than fit in a built-in integer. See the explanation file for this limitation and a more robust linked-list approach.
