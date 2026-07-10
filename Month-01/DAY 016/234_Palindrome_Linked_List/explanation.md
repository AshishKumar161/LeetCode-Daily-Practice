
# Explanation - Palindrome Linked List

# LeetCode 234

---

# Intuition

A palindrome is a sequence that reads the same from left to right and right to left.

For example,

```text
1 → 2 → 2 → 1
```

Reading from the front:

```text
1 2 2 1
```

Reading from the back:

```text
1 2 2 1
```

Both are identical, so it is a palindrome.

The difficulty is that a singly linked list can only be traversed in the forward direction.

To compare the first half with the second half, we first locate the middle of the list, reverse the second half, and then compare both halves node by node.

---

# Approach

Our solution consists of three major steps.

1. Find the middle of the linked list.
2. Reverse the second half.
3. Compare both halves.

If every corresponding node has the same value, the linked list is a palindrome.

---

# Step 1 : Find the Middle Node

We use the Slow and Fast Pointer technique.

```cpp
ListNode* slow = head;
ListNode* fast = head;
```

Move

```cpp
slow = slow->next;
fast = fast->next->next;
```

until

```cpp
fast == NULL
or
fast->next == NULL
```

---

## Why does this work?

Slow moves

```text
1 step
```

Fast moves

```text
2 steps
```

Therefore,

when Fast reaches the end,

Slow reaches the middle.

---

# Example (Even Length)

```text
1 → 2 → 2 → 1
```

Initially

```text
S
F

1 → 2 → 2 → 1
```

After first move

```text
      S
            F

1 → 2 → 2 → 1
```

After second move

```text
          S

1 → 2 → 2 → 1
```

Fast becomes NULL.

Middle is

```text
second 2
```

---

# Example (Odd Length)

```text
1 → 2 → 3 → 2 → 1
```

Initially

```text
S
F

1 → 2 → 3 → 2 → 1
```

Move 1

```text
      S
            F
```

Move 2

```text
            S
                  F
```

Fast is not NULL.

This means the list has an odd number of nodes.

The middle element

```text
3
```

does not need comparison.

So we skip it.

```cpp
if(fast != NULL)
{
    slow = slow->next;
}
```

Now

```text
slow
↓

2 → 1
```

---

# Step 2 : Reverse Second Half

We reverse the list beginning from Slow.

Function

```cpp
ListNode* recursion(ListNode* head)
```

actually performs an **iterative reversal**.

Variables

```cpp
prev
curr
next
```

---

Initially

```text
NULL

1 → 2 → 3
^

curr
```

---

Iteration 1

```text
next = 2

1 → NULL

prev = 1

curr = 2
```

---

Iteration 2

```text
2 → 1 → NULL

prev = 2

curr = 3
```

---

Iteration 3

```text
3 → 2 → 1 → NULL
```

Return

```text
prev
```

which becomes the new head.

---

# Step 3 : Compare Both Halves

Now

Original first half

```text
1 → 2
```

Reversed second half

```text
1 → 2
```

Compare

```cpp
while(rev != NULL)
```

If

```cpp
head->val != rev->val
```

return

```text
false
```

Otherwise move both pointers.

```cpp
head = head->next;
rev = rev->next;
```

If loop completes,

return

```text
true
```

---

# Dry Run

Input

```text
1 → 2 → 2 → 1
```

---

## Step 1

Find middle

```text
slow

↓

2 → 1
```

---

## Step 2

Reverse second half

Before

```text
2 → 1
```

After

```text
1 → 2
```

---

## Step 3

Compare

First comparison

```text
1 == 1
```

Move

Second comparison

```text
2 == 2
```

Move

Reached end.

Return

```text
true
```

---

# Dry Run 2

Input

```text
1 → 2
```

Middle

```text
2
```

Reverse

```text
2
```

Compare

```text
1 != 2
```

Return

```text
false
```

---

# Why Skip Middle Node?

Consider

```text
1 → 2 → 3 → 2 → 1
```

The middle element

```text
3
```

is always equal to itself.

Comparing it is unnecessary.

Therefore

```cpp
if(fast != NULL)
{
    slow = slow->next;
}
```

moves Slow one step ahead.

---

# Pointer Visualization

Initially

```text
head

↓

1 → 2 → 2 → 1

↑
slow

↑
fast
```

After finding middle

```text
1 → 2 → 2 → 1
        ↑
      slow
```

Reverse

```text
1 → 2

1 → 2
```

Compare

```text
head       rev

1 == 1

↓

2 == 2
```

Finished.

---

# Why This Approach Works

The linked list is divided into two equal halves.

The second half is reversed.

Both halves now have identical traversal direction.

Simple comparison determines whether the list is a palindrome.

---

# Time Complexity

Finding Middle

```text
O(n)
```

Reversing

```text
O(n/2)
```

Comparison

```text
O(n/2)
```

Overall

```text
O(n)
```

---

# Space Complexity

Only pointers are used.

No extra array or stack.

```text
O(1)
```

---

# Advantages

- Optimal solution
- O(n) time
- O(1) extra space
- Uses Slow/Fast Pointer
- Uses Linked List Reversal
- Suitable for interview questions

---

# Concepts Learned

- Slow & Fast Pointer Technique
- Finding Middle Node
- Reversing a Linked List
- Comparing Two Linked Lists
- Handling Odd and Even Length Lists
- Pointer Manipulation
- In-place Linked List Algorithms

---

# Common Interview Questions

### Why use Slow and Fast pointers?

To find the middle node in one traversal.

---

### Why reverse only the second half?

Because a singly linked list cannot be traversed backward.

---

### Why skip the middle node for odd-length lists?

The middle element has no matching pair and doesn't affect whether the list is a palindrome.

---

### Can this be solved using an array?

Yes.

Store all values in a vector and compare from both ends.

Time:

```text
O(n)
```

Space:

```text
O(n)
```

Our approach is better because it uses

```text
O(1)
```

extra space.
