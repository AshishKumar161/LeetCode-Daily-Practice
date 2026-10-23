# 160. Intersection of Two Linked Lists

**LeetCode:** [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)  
**Difficulty:** Easy  
**Topics:** Hash Table, Linked List, Two Pointers

## Problem Statement

Given the heads of two singly linked lists, `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists do not intersect, return `nullptr`.

The test cases are generated so that there are no cycles anywhere in the entire linked structure.

**Important:** The two lists must retain their original structure after the function returns.

An intersection is defined by reference, not by value. This means that the two lists intersect only if they share the exact same node in memory. Two different nodes containing the same value do not count as an intersection.

## Example 1

**Input:**
```text
intersectVal = 8
listA = [4,1,8,4,5]
listB = [5,6,1,8,4,5]
skipA = 2
skipB = 3
```

**Output:**
```text
Intersected at '8'
```

**Explanation:**

The intersected node's value is `8` (note that this must not be `0` if the lists intersect). From the heads of `A` and `B`, the respective nodes before the intersection are `[4,1]` and `[5,6,1]`. After the intersection, both lists share the nodes `[8,4,5]`.

## Example 2

**Input:**
```text
intersectVal = 2
listA = [1,9,1,2,4]
listB = [3,2,4]
skipA = 3
skipB = 1
```

**Output:**
```text
Intersected at '2'
```

**Explanation:**

The intersected node's value is `2`. From the heads of `A` and `B`, the respective nodes before the intersection are `[1,9,1]` and `[3]`. After the intersection, both lists share the nodes `[2,4]`.

## Example 3

**Input:**
```text
intersectVal = 0
listA = [2,6,4]
listB = [1,5]
skipA = 3
skipB = 2
```

**Output:**
```text
No intersection
```

**Explanation:**

The two lists do not share any node, so the return value is `nullptr`. Note that `intersectVal` is `0` when there is no intersection.

## Constraints

- The number of nodes in `listA` is in the range `[1, 3 * 10^4]`.
- The number of nodes in `listB` is in the range `[1, 3 * 10^4]`.
- `1 <= Node.val <= 10^5`.
- `0 <= skipA < listA.length`.
- `0 <= skipB < listB.length`.
- `intersectVal` is `0` if `listA` and `listB` do not intersect.
- If `listA` and `listB` intersect, `intersectVal == listA[skipA] == listB[skipB]`.

## Function Signature

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
```

## Approaches to Explore

1. **Hash Set:** Store the node addresses from list A and check whether list B contains one of those addresses.
2. **Length Difference:** Count both list lengths, align the pointers by advancing the longer list, then move both pointers together.
3. **Two-Pointer Switching:** Let each pointer traverse both lists by switching to the other list's head after reaching the end.

The detailed C++ implementations, dry runs, and time/space complexity analysis for all three approaches are documented in [`leetcode_160_explanation.md`](leetcode_160_explanation.md).
