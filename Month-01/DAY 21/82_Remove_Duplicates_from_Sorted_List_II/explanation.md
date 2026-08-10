
# LeetCode 82 — Remove Duplicates from Sorted List II

## Problem

Given a **sorted linked list**, remove **all nodes** whose values appear more than once.

The important word is **all**.

For example:

```text
1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
```

We cannot keep one `3` or one `4`.

We must remove the complete duplicate groups:

```text
3 -> 3
4 -> 4
```

Result:

```text
1 -> 2 -> 5
```

---

# Important Difference Between LeetCode 83 and 82

This is extremely important.

## LeetCode 83

Remove duplicates but **keep one copy**.

```text
1 -> 2 -> 2 -> 3 -> 3
```

Result:

```text
1 -> 2 -> 3
```

---

## LeetCode 82

Remove duplicates completely.

```text
1 -> 2 -> 2 -> 3 -> 3
```

Result:

```text
1
```

Because both `2` and `3` are duplicates.

---

# Approach

We use three important concepts:

```text
dummy
prev
curr
```

The `dummy` node is especially useful because the duplicate group can start at the head.

---

# Why Do We Need a Dummy Node?

Consider:

```text
1 -> 1 -> 2 -> 3
```

The duplicate group starts at `head`.

If we did not have a dummy node, removing the first group would require special handling.

Instead we create:

```text
dummy -> 1 -> 1 -> 2 -> 3
```

Now:

```text
prev
 |
dummy

curr
 |
1 -> 1 -> 2 -> 3
```

`prev` always represents the last node that we know should remain.

---

# Pointer Meaning

## `prev`

```cpp
ListNode* prev = &dummy;
```

`prev` points to the last node that should remain in the final answer.

---

## `curr`

```cpp
ListNode* curr = head;
```

`curr` is used to scan through the linked list.

---

# Main Condition

```cpp
if(curr->next != NULL && curr->val == curr->next->val)
```

This checks whether `curr` belongs to a duplicate group.

For example:

```text
1 -> 2 -> 3 -> 3 -> 4
          ^
         curr
```

Here:

```cpp
curr->val == curr->next->val
```

because:

```text
3 == 3
```

Therefore `3` is duplicated.

---

# Step 1 — Save the Duplicate Value

```cpp
int copy = curr->val;
```

Suppose:

```text
curr -> 3
```

Then:

```text
copy = 3
```

We save this value because we need to remove **every node** having this value.

---

# Step 2 — Skip the Entire Duplicate Group

```cpp
while(curr != NULL && curr->val == copy)
{
    curr = curr->next;
}
```

Suppose the list is:

```text
1 -> 2 -> 3 -> 3 -> 3 -> 4 -> 5
```

Initially:

```text
curr
 |
3 -> 3 -> 3 -> 4 -> 5
```

`copy = 3`

### First iteration

```text
curr->val == 3
```

Move:

```cpp
curr = curr->next;
```

Now:

```text
3 -> 3 -> 4 -> 5
     ^
    curr
```

### Second iteration

Move again:

```text
3 -> 4 -> 5
     ^
    curr
```

### Third iteration

Move again:

```text
4 -> 5
^
curr
```

Now:

```cpp
curr->val != copy
```

So the duplicate group is completely skipped.

---

# Step 3 — Connect `prev` to `curr`

After skipping the duplicate group:

```cpp
prev->next = curr;
```

Suppose we had:

```text
1 -> 2 -> 3 -> 3 -> 4
```

After removing `3`:

```text
prev
 |
2

curr
 |
4
```

We connect:

```cpp
prev->next = curr;
```

Result:

```text
1 -> 2 -> 4
```

The `3` nodes are no longer part of the returned linked list.

---

# What Happens When There Is No Duplicate?

Suppose:

```text
1 -> 2 -> 3 -> 4
```

At:

```text
curr = 1
```

Check:

```text
1 == 2
```

False.

So we execute:

```cpp
prev = curr;
curr = curr->next;
```

Now:

```text
prev
 |
1 -> 2 -> 3 -> 4
     ^
    curr
```

We continue.

---

# Complete Dry Run

Consider:

```text
1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
```

Expected:

```text
1 -> 2 -> 5
```

Initially:

```text
dummy -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
 ^       ^
prev    curr
```

---

## Step 1

```text
curr = 1
```

Check:

```text
1 == 2
```

False.

Move:

```cpp
prev = curr;
curr = curr->next;
```

Now:

```text
dummy -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
          ^    ^
         prev curr
```

---

# Step 2

```text
curr = 2
```

Check:

```text
2 == 3
```

False.

Move:

```cpp
prev = curr;
curr = curr->next;
```

Now:

```text
dummy -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
               ^    ^
              prev curr
```

---

# Step 3 — Duplicate 3 Found

Now:

```text
curr = 3
```

Check:

```text
curr->val == curr->next->val
```

```text
3 == 3
```

True.

Save:

```cpp
copy = 3;
```

Now skip all `3`s.

```text
3 -> 3 -> 4
^
curr
```

Move once:

```text
3 -> 4
     ^
    curr
```

Move again:

```text
4
^
curr
```

Now `curr->val != 3`.

Connect:

```cpp
prev->next = curr;
```

The list becomes logically:

```text
1 -> 2 -> 4 -> 4 -> 5
```

---

# Step 4 — Duplicate 4 Found

Now:

```text
prev = 2
curr = 4
```

Check:

```text
4 == 4
```

True.

Save:

```cpp
copy = 4;
```

Skip:

```text
4 -> 4 -> 5
^
curr
```

After first movement:

```text
4 -> 5
     ^
    curr
```

After second movement:

```text
5
^
curr
```

Connect:

```cpp
prev->next = curr;
```

Now:

```text
1 -> 2 -> 5
```

---

# Step 5

Now:

```text
curr = 5
```

There is no next node:

```text
curr->next == NULL
```

So the duplicate condition is false.

Execute:

```cpp
prev = curr;
curr = curr->next;
```

Now:

```text
prev -> 5
curr -> NULL
```

Loop ends.

---

# Final Result

```text
dummy -> 1 -> 2 -> 5
```

Return:

```cpp
return dummy.next;
```

Therefore:

```text
1 -> 2 -> 5
```

---

# Complete Code

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        if(head == NULL)
        {
            return head;
        }

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(curr != NULL)
        {
            if(curr->next != NULL && curr->val == curr->next->val)
            {
                int copy = curr->val;

                while(curr != NULL && curr->val == copy)
                {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
```

---

# Why `prev` Does Not Move When a Duplicate Is Found

This is one of the most important parts of the algorithm.

Suppose:

```text
1 -> 2 -> 3 -> 3 -> 4
```

When `3` is detected as a duplicate:

```text
prev
 |
2

curr
 |
3 -> 3 -> 4
```

We skip both `3`s.

After skipping:

```text
prev
 |
2

curr
 |
4
```

Then:

```cpp
prev->next = curr;
```

Result:

```text
1 -> 2 -> 4
```

Notice:

```text
prev
 |
2
```

`prev` stayed at `2`.

If we moved `prev` while processing the duplicate, we could accidentally keep a duplicate node.

---

# Why the List Is Still Sorted

The original list is already sorted.

Therefore all duplicate values are adjacent.

For example:

```text
1 -> 2 -> 3 -> 3 -> 3 -> 5
```

All `3`s are together.

We don't need to search the entire list for another `3`.

Once we find:

```text
curr->val == curr->next->val
```

we know the complete duplicate group can be skipped consecutively.

---

# Edge Cases

## Empty List

```text
head = NULL
```

We return:

```cpp
NULL
```

---

## One Node

```text
1
```

No duplicate exists.

Result:

```text
1
```

---

## All Nodes Are Duplicates

```text
1 -> 1 -> 2 -> 2
```

First remove:

```text
1 -> 1
```

Then remove:

```text
2 -> 2
```

Result:

```text
NULL
```

---

## Duplicate at the Beginning

```text
1 -> 1 -> 2 -> 3
```

Using `dummy` makes this easy.

Result:

```text
2 -> 3
```

---

## Duplicate at the End

```text
1 -> 2 -> 3 -> 3
```

Skip the `3`s.

Result:

```text
1 -> 2
```

---

# Complexity Analysis

Let `n` be the number of nodes.

## Time Complexity

Every node is visited at most a constant number of times.

Therefore:

```text
O(n)
```

---

## Space Complexity

We only use:

```text
dummy
prev
curr
copy
```

No extra data structure is required.

Therefore:

```text
O(1)
```

---

# Final Complexity

```text
Time:  O(n)
Space: O(1)
```

---

# Key Concepts Learned

1. Dummy node
2. Linked-list pointer manipulation
3. Detecting consecutive duplicates
4. Removing an entire duplicate group
5. Maintaining a `prev` pointer
6. Skipping nodes using pointer reassignment
7. Handling duplicate groups at the head
8. O(n) linked-list traversal
9. O(1) extra space

---

# Important Difference

### LeetCode 83

```text
1 -> 2 -> 2 -> 3 -> 3
```

Output:

```text
1 -> 2 -> 3
```

Keep one copy.

### LeetCode 82

```text
1 -> 2 -> 2 -> 3 -> 3
```

Output:

```text
1
```

Remove every value that appears more than once.
