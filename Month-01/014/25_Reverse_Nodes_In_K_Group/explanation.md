
# Explanation - Reverse Nodes in k-Group

## LeetCode 25

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0) ;

        dummy.next = head ;

        ListNode* prev = &dummy ;

        while(true)
        {
            ListNode* t1 = prev ;

            for(int i = 0 ; i < k ; i++)
            {
                t1 = t1 -> next ;

                if(t1 == NULL)
                {
                    return dummy.next ;
                }
            }

            ListNode* t2 = prev -> next ;

            ListNode* t3 = t1 -> next ;

            ListNode* curr = t2 ;

            ListNode* prevNode = t3 ;

            while(curr != t3)
            {
                ListNode* temp = curr -> next ;

                curr -> next = prevNode ;

                prevNode = curr ;

                curr = temp ;
            }

            prev -> next = t1 ;

            prev = t2 ;
        }
    }
};
```

---

# Problem Statement

Reverse nodes of a linked list in groups of size `k`.

If remaining nodes are less than `k`, leave them unchanged.

---

# Example

Input:

```text
1 -> 2 -> 3 -> 4 -> 5
k = 2
```

Output:

```text
2 -> 1 -> 4 -> 3 -> 5
```

---

# Main Idea

We reverse the linked list group by group.

Suppose current group is:

```text
1 -> 2
```

After reversal:

```text
2 -> 1
```

Then move to next group.

---

# Why Dummy Node?

```cpp
ListNode dummy(0) ;
dummy.next = head ;
```

Dummy node helps handle head changes easily.

Without dummy node:

```text
1 -> 2 -> 3
```

After reversing:

```text
2 -> 1 -> 3
```

Head changes from `1` to `2`.

Dummy node simplifies this process.

Visualization:

```text
dummy -> 1 -> 2 -> 3
```

---

# Pointer Explanation

| Pointer      | Meaning                       |
| ------------ | ----------------------------- |
| `prev`     | Node before current group     |
| `t1`       | Last node of current group    |
| `t2`       | First node of current group   |
| `t3`       | Node after current group      |
| `curr`     | Current node during reversal  |
| `prevNode` | Previous node during reversal |

---

# Step 1: Move `t1` to kth Node

```cpp
ListNode* t1 = prev ;

for(int i = 0 ; i < k ; i++)
{
    t1 = t1 -> next ;

    if(t1 == NULL)
    {
        return dummy.next ;
    }
}
```

---

# Purpose

Check whether `k` nodes exist or not.

If fewer than `k` nodes remain:

```text
Stop reversing
```

---

# Example

Current list:

```text
dummy -> 1 -> 2 -> 3 -> 4 -> 5
```

For `k = 2`

Initially:

```text
t1 = dummy
```

Move 1 step:

```text
t1 = 1
```

Move 2 step:

```text
t1 = 2
```

Now:

```text
t1 = last node of current group
```

---

# Step 2: Store Important Nodes

```cpp
ListNode* t2 = prev -> next ;
ListNode* t3 = t1 -> next ;
```

---

# Meaning

`t2`:

```text
First node of current group
```

`t3`:

```text
Node after current group
```

---

# Visualization

```text
dummy -> 1 -> 2 -> 3 -> 4 -> 5
          ^    ^    ^
          t2   t1   t3
```

Where:

```text
t2 = 1
t1 = 2
t3 = 3
```

---

# Step 3: Prepare Reversal

```cpp
ListNode* curr = t2 ;
ListNode* prevNode = t3 ;
```

---

# Why `prevNode = t3`?

Normally linked list reversal starts with:

```text
prev = NULL
```

But here we want:

```text
1 -> 2 -> 3
```

After reversal:

```text
2 -> 1 -> 3
```

Notice:

```text
1 points to 3
```

That is why:

```cpp
prevNode = t3 ;
```

---

# Step 4: Reverse Nodes

```cpp
while(curr != t3)
{
    ListNode* temp = curr -> next ;

    curr -> next = prevNode ;

    prevNode = curr ;

    curr = temp ;
}
```

---

# First Iteration

Current:

```text
curr = 1
prevNode = 3
```

Store next node:

```text
temp = 2
```

Reverse:

```text
1 -> 3
```

Move pointers:

```text
prevNode = 1
curr = 2
```

---

# Second Iteration

Current:

```text
curr = 2
prevNode = 1
```

Store next:

```text
temp = 3
```

Reverse:

```text
2 -> 1
```

Move:

```text
prevNode = 2
curr = 3
```

Loop stops because:

```text
curr == t3
```

---

# Reversed Group

Now group becomes:

```text
2 -> 1 -> 3
```

---

# Step 5: Connect Reversed Group

```cpp
prev -> next = t1 ;
```

Remember:

```text
t1 is new head after reversal
```

List becomes:

```text
dummy -> 2 -> 1 -> 3
```

---

# Step 6: Move `prev`

```cpp
prev = t2 ;
```

Why?

Because after reversal:

```text
t2 becomes tail of reversed group
```

Move to next group.

---

# Complete Dry Run

Input:

```text
1 -> 2 -> 3 -> 4 -> 5
k = 2
```

---

# First Group

Current group:

```text
1 -> 2
```

Reverse:

```text
2 -> 1
```

List becomes:

```text
2 -> 1 -> 3 -> 4 -> 5
```

Move:

```text
prev = 1
```

---

# Second Group

Current group:

```text
3 -> 4
```

Reverse:

```text
4 -> 3
```

List becomes:

```text
2 -> 1 -> 4 -> 3 -> 5
```

---

# Third Group

Remaining node:

```text
5
```

Less than `k`.

Do not reverse.

---

# Final Output

```text
2 -> 1 -> 4 -> 3 -> 5
```

---

# Time Complexity

```text
O(n)
```

Each node visited once.

---

# Space Complexity

```text
O(1)
```

No extra space used.

---

# Important Learning

This problem teaches:

* Linked list reversal
* Pointer manipulation
* Group reversal
* Dummy node usage
* In-place linked list modification
* Advanced linked list handling

This is one of the most important linked list interview questions.