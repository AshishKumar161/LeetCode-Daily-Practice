# Delete the Middle Node of a Linked List — Explanation

**LeetCode:** [2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)  
**Language:** C++  
**Approach:** Count nodes, then remove the middle node

## C++ Code

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // An empty list or a one-node list becomes empty.
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // First traversal: count the nodes.
        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // The middle node's index (0-based).
        int mid = count / 2;

        // Move temp to the node immediately before the middle.
        temp = head;
        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }

        // Unlink and delete the middle node.
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};
```

## Step-by-Step Explanation

### 1. Handle the edge case

```cpp
if (head == nullptr || head->next == nullptr) {
    return nullptr;
}
```

If `head` is `nullptr`, the list is empty. If `head->next` is `nullptr`, the list has one node. In either case, the result after deleting the middle node is an empty list.

### 2. Count the nodes

```cpp
ListNode* temp = head;
int count = 0;

while (temp != nullptr) {
    count++;
    temp = temp->next;
}
```

`temp` visits each node and increments `count`. When `temp` becomes `nullptr`, the traversal is finished and `count` holds the list length.

For `[1,3,4,7,1,2,6]`, `count` becomes `7`.

### 3. Find the middle index

```cpp
int mid = count / 2;
```

The problem uses zero-based indexing. Integer division gives the correct index to delete, including for even-sized lists.

| Node count | `mid` | Middle index |
|---:|---:|---:|
| 2 | 1 | 1 |
| 3 | 1 | 1 |
| 4 | 2 | 2 |
| 7 | 3 | 3 |

### 4. Move to the previous node

```cpp
temp = head;
for (int i = 0; i < mid - 1; i++) {
    temp = temp->next;
}
```

To remove a node from a singly linked list, we need the node before it so we can update that node's `next` pointer.

For a 7-node list, `mid = 3`. The loop runs for `i = 0` and `i = 1`, so `temp` stops at index `2`, the node with value `4`. The middle node (`7`) is at index `3`.

### 5. Bypass and delete the middle node

```cpp
ListNode* del = temp->next;
temp->next = del->next;
delete del;
```

- `del` stores the address of the middle node.
- `temp->next = del->next` makes the previous node point to the node after the middle node.
- `delete del` releases the removed node's memory.

Before:
```text
4 -> 7 -> 1
```

After changing the pointer:
```text
4 ------> 1
```

The node containing `7` is then deleted.

### 6. Return the head

```cpp
return head;
```

For lists with at least two nodes, the head remains unchanged, so return it.

## Dry Run

Input:

```text
head = [1,3,4,7,1,2,6]
```

### First traversal: count nodes

| Visited value | `count` |
|---:|---:|
| 1 | 1 |
| 3 | 2 |
| 4 | 3 |
| 7 | 4 |
| 1 | 5 |
| 2 | 6 |
| 6 | 7 |

After the final node, `temp` becomes `nullptr`. Thus, `count = 7`.

### Calculate the middle index

```text
mid = count / 2 = 7 / 2 = 3
```

The node at index `3` contains `7`.

### Move `temp` to the previous node

- Start at index `0`, value `1`.
- `i = 0`: move to index `1`, value `3`.
- `i = 1`: move to index `2`, value `4`.

Now `temp` points to `4`, the node immediately before `7`.

### Delete the middle node

```cpp
del = temp->next;        // del points to 7
temp->next = del->next;  // 4 now points to 1
delete del;              // release node 7
```

Result:

```text
1 -> 3 -> 4 -> 1 -> 2 -> 6
```

**Output:** `[1,3,4,1,2,6]`

## Complexity Analysis

Let `n` be the number of nodes.

- **Time complexity: `O(n)`** — the first traversal counts nodes, and the second traversal moves to the node before the middle. Two linear traversals still take `O(n)` time.
- **Auxiliary space complexity: `O(1)`** — only a constant number of pointers and integer variables are used.

## Common Mistakes

- **Stopping at the middle node:** you need the previous node to update its `next` pointer.
- **Using the wrong middle index:** `count / 2` is correct for zero-based indexing and selects the second central node for even-sized lists.
- **Forgetting to save the node before unlinking it:** assign `temp->next` to `del` first.
- **Forgetting `delete del`:** the node should be released after being unlinked.
- **Ignoring the one-node case:** deleting its only node must return `nullptr`.

## Key Takeaway

In a singly linked list, removing a node requires changing the previous node's `next` pointer. Counting the nodes first makes it straightforward to find the correct position with a second traversal.
