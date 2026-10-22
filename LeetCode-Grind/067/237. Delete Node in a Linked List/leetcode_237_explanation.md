# Delete Node in a Linked List — C++ Explanation

**LeetCode:** [237. Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)  
**Approach:** Copy the next value, bypass the next node, and delete it

## C++ Code

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;

        ListNode* del = node->next;
        node->next = node->next->next;

        delete del;
    }
};
```

## 1. Why This Technique Is Needed

Normally, deleting a node from a singly linked list requires its previous node so that the previous node's `next` pointer can be changed. Here, only the node to delete is provided—not the head or the previous node.

Because the node is guaranteed not to be the tail, a next node exists.

## 2. Copy the Next Node's Value

```cpp
node->val = node->next->val;
```

For `4 -> 5 -> 1 -> 9`, when `node` points to `5`, this changes the values to `4 -> 1 -> 1 -> 9`.

## 3. Save the Next Node

```cpp
ListNode* del = node->next;
```

`del` stores the address of the next node, which will be removed. Save it before changing the links.

## 4. Bypass the Next Node

```cpp
node->next = node->next->next;
```

The given node now points directly to the node after the one being bypassed. The reachable list becomes `4 -> 1 -> 9`.

## 5. Release Its Memory

```cpp
delete del;
```

This frees the bypassed node. Changing the link alone would remove it from the chain but leave its dynamically allocated memory unreleased.

## Dry Run

Input: `head = [4,5,1,9]`, `node = 5`

| Step | Operation | List reachable from head |
|---|---|---|
| 1 | Initial list | `4 -> 5 -> 1 -> 9` |
| 2 | Copy next value into `node` | `4 -> 1 -> 1 -> 9` |
| 3 | Save `node->next` in `del` | Links unchanged |
| 4 | Point `node->next` to `node->next->next` | `4 -> 1 -> 9` |
| 5 | `delete del` | `4 -> 1 -> 9` |

**Final output:** `[4,1,9]`

## Complexity Analysis

- **Time:** `O(1)` — a constant number of operations.
- **Auxiliary space:** `O(1)` — one extra pointer.

## Common Mistakes

- Trying to traverse from the head, which is not provided to the function.
- Applying this method to the tail; the tail has no next node to copy from.
- Changing `node->next` before saving the address of the node to delete.
- Forgetting to free the bypassed node in C++.

## Key Takeaway

When given only a non-tail node, copy the next node's value into it, bypass the next node, and delete that bypassed node.
