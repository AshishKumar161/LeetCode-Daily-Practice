# 142. Linked List Cycle II — Two Approaches Explained

**LeetCode:** [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)  
**Language:** C++  
**Goal:** Return the exact node where the cycle begins, or `nullptr` if there is no cycle.

## What Is a Cycle?

A cycle exists when following `next` pointers eventually brings us back to a node already visited.

```text
3 -> 2 -> 0 -> -4
     ^           |
     |___________|
```

The cycle begins at the node containing `2`. Return the node pointer, not just its value.

---

## Approach 1: Floyd's Cycle Detection (Slow and Fast Pointers)

This is the approach used in your active code. It finds the cycle entry using constant extra space.

### Code

```cpp
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect whether a cycle exists.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: Find the cycle entry.
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};
```

### Phase 1 — Detect the Cycle

- `slow` moves one node per iteration.
- `fast` moves two nodes per iteration.
- If there is no cycle, `fast` or `fast->next` eventually becomes `nullptr`.
- If a cycle exists, `fast` eventually meets `slow` inside the cycle.
- `slow == fast` compares node addresses, not values.

The condition checks `fast` and `fast->next` before moving `fast` two steps.

### Phase 2 — Find the Cycle Entry

After the pointers meet:

```cpp
slow = head;
while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}
return slow;
```

Reset `slow` to the head and keep `fast` at the meeting point. Move both one step at a time. They meet at the cycle's entry node.

**Why this works:** Let `L` be the distance from the head to the cycle entry, `C` the cycle length, and `x` the distance from the entry to the meeting point. At the first meeting, the fast pointer has travelled twice as far as the slow pointer. The distance difference is a whole number of cycle lengths. This makes the distance from the meeting point around the cycle back to the entry align with the head-to-entry distance modulo `C`. Moving both pointers one step at a time therefore makes them meet at the entry.

### Dry Run

Input: `head = [3,2,0,-4]`, with the tail connected to index `1`.

**Phase 1:**
1. Initially: `slow = 3`, `fast = 3`.
2. First iteration: `slow = 2`, `fast = 0`.
3. Second iteration: `slow = 0`, `fast = 2`.
4. Third iteration: `slow = -4`, `fast = -4`. They meet, so a cycle exists.

**Phase 2:**
1. Reset `slow` to the head (`3`); `fast` stays at `-4`.
2. Move both once: `slow = 2`, `fast = 2`.
3. They meet at node `2`, the cycle entry. Return that node.

### Complexity

- **Time:** `O(n)`.
- **Auxiliary space:** `O(1)`.

---

## Approach 2: Hash Set of Visited Node Addresses

This is the approach in your commented-out code. Store each visited node's address. The first address seen for a second time is the cycle entry.

### Code

```cpp
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> hash;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (hash.find(temp) != hash.end()) {
                return temp;
            }

            hash.insert(temp);
            temp = temp->next;
        }

        return nullptr;
    }
};
```

### Logic

1. Start at `head` with `temp`.
2. Check whether the current node address already exists in `hash`.
3. If it exists, we have reached a previously visited node. Return `temp`; this first repeated address is the cycle entry.
4. Otherwise, insert the address and move to the next node.
5. If `temp` becomes `nullptr`, no cycle exists, so return `nullptr`.

The set stores `ListNode*` addresses, not node values. Separate nodes may have equal values.

### Dry Run

For `3 -> 2 -> 0 -> -4 -> 2 ...`:

| Step | Current node value | Already visited? | Action |
|---|---:|---|---|
| 1 | 3 | No | Insert node `3` |
| 2 | 2 | No | Insert node `2` |
| 3 | 0 | No | Insert node `0` |
| 4 | -4 | No | Insert node `-4` |
| 5 | 2 | Yes | Return node `2` |

### Complexity

- **Time:** `O(n)` average.
- **Auxiliary space:** `O(n)` for the set of visited addresses.

---

## Comparison

| Feature | Floyd's algorithm | Hash set |
|---|---|---|
| Main idea | Slow and fast pointers | Remember visited addresses |
| Time | `O(n)` | `O(n)` average |
| Auxiliary space | `O(1)` | `O(n)` |
| Extra data structure | None | `unordered_set<ListNode*>` |

## Which Approach Should You Use?

- **Floyd's algorithm** is generally preferred because it uses constant extra space and does not allocate a set.
- **Hash set** is intuitive and easy to debug, but requires extra memory.

## Common Mistakes

- Comparing `slow->val == fast->val` instead of `slow == fast`.
- Moving `fast` two steps without checking `fast` and `fast->next`.
- Returning Floyd's first meeting point; it is not necessarily the cycle entry.
- Storing node values rather than addresses in the hash set.
- Forgetting to return `nullptr` when no cycle exists.

## Key Takeaway

Floyd's method detects the cycle, then resets one pointer to the head and advances both pointers one step at a time to find the entry. The hash-set method returns the first node address encountered twice.
