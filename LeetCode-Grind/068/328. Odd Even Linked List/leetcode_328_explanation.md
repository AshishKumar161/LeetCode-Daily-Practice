# Odd Even Linked List — C++ Solution and Explanation

**LeetCode:** [328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)  
**Approach:** In-place pointer rearrangement

## C++ Code

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* oddptr = head;
        ListNode* evenptr = head->next;
        ListNode* even = evenptr;

        while (evenptr != nullptr && evenptr->next != nullptr) {
            oddptr->next = evenptr->next;
            oddptr = oddptr->next;

            evenptr->next = oddptr->next;
            evenptr = evenptr->next;
        }

        oddptr->next = even;
        return head;
    }
};
```

## 1. Understand the Goal

For `1 -> 2 -> 3 -> 4 -> 5`, odd-positioned nodes are `1, 3, 5`; even-positioned nodes are `2, 4`. The required order is:

```text
Odd chain:   1 -> 3 -> 5
Even chain:  2 -> 4
Final list:  1 -> 3 -> 5 -> 2 -> 4
```

The values themselves do not determine the groups; positions do.

## 2. Handle Short Lists

```cpp
if (head == nullptr || head->next == nullptr) {
    return head;
}
```

An empty list or a one-node list is already correctly ordered. This also prevents accessing `head->next` when `head` is null.

## 3. Initialize the Pointers

```cpp
ListNode* oddptr = head;
ListNode* evenptr = head->next;
ListNode* even = evenptr;
```

- `oddptr`: last node in the odd-position chain currently being built.
- `evenptr`: last node in the even-position chain currently being built.
- `even`: saves the first even-positioned node so that chain can be attached at the end.

For `[1,2,3,4,5]`, `oddptr` starts at `1`, while `evenptr` and `even` start at `2`.

## 4. Loop Condition

```cpp
while (evenptr != nullptr && evenptr->next != nullptr)
```

Both pointers must exist before rewiring. The `&&` operator ensures the right-hand check is only evaluated when `evenptr` is not null.

## 5. Link the Next Odd Node

```cpp
oddptr->next = evenptr->next;
oddptr = oddptr->next;
```

The node after the current even node is the next odd-positioned node. Link it after `oddptr`, then advance `oddptr`.

## 6. Link the Next Even Node

```cpp
evenptr->next = oddptr->next;
evenptr = evenptr->next;
```

After moving `oddptr`, its `next` points to the next even-positioned node, if there is one. Link that node after `evenptr` and advance `evenptr`.

## 7. Join the Chains

```cpp
oddptr->next = even;
```

When the loop ends, attach the saved even chain after the final odd node.

## Dry Run

Input: `[1,2,3,4,5]`

Initial pointers: `oddptr = 1`, `evenptr = 2`, `even = 2`.

| Iteration | Odd-chain operation | Even-chain operation | Chains after iteration |
|---|---|---|---|
| 1 | Link `1 -> 3`; move `oddptr` to `3` | Link `2 -> 4`; move `evenptr` to `4` | Odd: `1 -> 3`; Even: `2 -> 4` |
| 2 | Link `3 -> 5`; move `oddptr` to `5` | Set `4->next` to `nullptr`; `evenptr` becomes `nullptr` | Odd: `1 -> 3 -> 5`; Even: `2 -> 4` |

The loop stops. Then `oddptr->next = even` links `5 -> 2`.

**Output:** `[1,3,5,2,4]`

## Complexity Analysis

Let `n` be the number of nodes.

- **Time:** `O(n)` — each node is processed a constant number of times.
- **Auxiliary space:** `O(1)` — only a fixed number of pointers are used; no additional list or array is created.

## Common Mistakes

- Grouping nodes by their values instead of their positions.
- Not saving the original even-chain head in `even`.
- Using `||` instead of `&&` in the loop condition.
- Forgetting `oddptr->next = even` after the loop.
- Advancing pointers before updating the links that depend on them.

## Key Takeaway

Rearrange the odd and even chains in place, preserve the even-chain head, and connect the odd tail to the even head.
