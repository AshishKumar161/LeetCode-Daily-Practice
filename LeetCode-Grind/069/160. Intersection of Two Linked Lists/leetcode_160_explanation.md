# Intersection of Two Linked Lists — All Approaches

**LeetCode:** [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)  
**Language:** C++

## What Does Intersection Mean?

Two lists intersect only when their pointers refer to the **same node address**. Two separate nodes with the same value do not count as an intersection.

Example:

```text
A: 1 -> 2 --+
            +-> 8 -> 9
B: 4 -> 5 --+
```

The first shared node is `8`.

---

## Approach 1: Hash Set

### Code

```cpp
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> st;

        ListNode* temp = headA;
        while (temp != nullptr) {
            st.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr) {
            if (st.find(temp) != st.end()) {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }
};
```

### Explanation

1. Traverse list A and store each node address in `st`.
2. Traverse list B.
3. `st.find(temp) != st.end()` means that exact node address was previously stored from A, so `temp` is the intersection.
4. If no address matches, return `nullptr`.

The set stores `ListNode*` addresses, not values.

**Complexity:** Average `O(m + n)` time and `O(m)` auxiliary space, where `m` and `n` are the list lengths.

---

## Approach 2: Length Difference (Your Active Code)

### Code

```cpp
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        ListNode* temp = headA;

        int countA = 0;
        while (temp != nullptr) {
            countA++;
            temp = temp->next;
        }

        temp = headB;
        int countB = 0;
        while (temp != nullptr) {
            countB++;
            temp = temp->next;
        }

        if (countA > countB) {
            int diff = countA - countB;
            for (int i = 0; i < diff; i++) {
                t1 = t1->next;
            }
        } else if (countB > countA) {
            int diff = countB - countA;
            for (int i = 0; i < diff; i++) {
                t2 = t2->next;
            }
        }

        while (t1 != nullptr && t2 != nullptr) {
            if (t1 == t2) {
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        return nullptr;
    }
};
```

### Explanation

**Step 1: Count list A**

The first loop visits every node in A and stores its length in `countA`.

**Step 2: Count list B**

The second loop counts B's nodes in `countB`.

**Step 3: Align the starting points**

If A is longer, advance `t1` by `countA - countB`. If B is longer, advance `t2` by `countB - countA`.

Why? After this adjustment, both pointers have the same number of nodes left to traverse. If an intersection exists, they can now reach it on the same step.

**Step 4: Move together**

```cpp
while (t1 != nullptr && t2 != nullptr) {
    if (t1 == t2) return t1;
    t1 = t1->next;
    t2 = t2->next;
}
```

Compare addresses with `t1 == t2`, not values with `t1->val == t2->val`. If no shared node exists, the pointers eventually reach `nullptr` and the function returns `nullptr`.

### Dry Run

```text
A: 1 -> 2 -> 3 -> 8 -> 9   (length 5)
B:           4 -> 8 -> 9   (length 3)
```

1. `countA = 5`, `countB = 3`; difference is `2`.
2. Advance `t1` two steps, from `1` to `3`.
3. `t2` stays at `4`.
4. Compare `3` and `4`: different. Advance both.
5. Compare `8` and `8`: same node address. Return node `8`.

**Complexity:** `O(m + n)` time and `O(1)` auxiliary space.

---

## Approach 3: Two-Pointer Switching

### Code

```cpp
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            if (a == nullptr) {
                a = headB;
            } else {
                a = a->next;
            }

            if (b == nullptr) {
                b = headA;
            } else {
                b = b->next;
            }
        }

        return a;
    }
};
```

### Explanation

- `a` starts at A and `b` starts at B.
- Each pointer advances one node at a time.
- When `a` reaches the end, redirect it to `headB`.
- When `b` reaches the end, redirect it to `headA`.
- Stop when `a == b`.

Pointer `a` traverses A then B; pointer `b` traverses B then A. They therefore travel the same total distance. If the lists intersect, they align at the shared node. If they do not intersect, both eventually become `nullptr`, and the loop stops.

### Dry Run

```text
A: 1 -> 2 -> 8 -> 9
B: 4 -> 5 -> 6 -> 8 -> 9
```

Pointer `a` traverses A, then switches to B. Pointer `b` traverses B, then switches to A. After switching, the unequal prefix lengths are compensated for, and both meet at the shared node `8`.

**Complexity:** `O(m + n)` time and `O(1)` auxiliary space.

---

## Comparison

| Approach | Time | Auxiliary space | Main idea |
|---|---|---|---|
| Hash set | `O(m + n)` average | `O(m)` | Remember addresses from A |
| Length difference | `O(m + n)` | `O(1)` | Align remaining lengths |
| Two-pointer switching | `O(m + n)` | `O(1)` | Traverse both lists in swapped order |

## Which Should You Use?

- **Hash set:** Straightforward to understand; uses extra memory.
- **Length difference:** Explicit and easy to dry-run; constant extra space.
- **Two-pointer switching:** Compact optimal solution with constant extra space and no separate length-counting loops.

## Common Mistakes

- Comparing node values rather than node addresses.
- Forgetting to return `nullptr` when no intersection exists.
- Advancing only one pointer in the aligned traversal.
- Advancing the shorter list in the length-difference method.
- Assuming equal values mean the lists intersect.

## Key Takeaway

All three methods locate the first shared node. The hash-set method stores addresses; the other two achieve `O(1)` auxiliary space by aligning traversal lengths.
