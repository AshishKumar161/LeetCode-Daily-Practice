
# Explanation - Remove Duplicates from Sorted List

# LeetCode 83

---

# Main Idea

The linked list is already sorted.

That means:

```text
Duplicate values always come together
```

Example:

```text
1 -> 1 -> 2 -> 3 -> 3
```

Here:

- both `1` are together
- both `3` are together

So we only need to compare adjacent nodes.

---

# Goal

Convert:

```text
1 -> 1 -> 2 -> 3 -> 3
```

Into:

```text
1 -> 2 -> 3
```

---

# Pointers Used

| Pointer | Meaning       |
| ------- | ------------- |
| `t1`  | Previous node |
| `t2`  | Current node  |
| `t3`  | Next node     |

---

# Initial Setup

```cpp
ListNode* t1 = head ;
ListNode* t2 = head ;
ListNode* t3 = head -> next ;
```

---

# Visualization

Suppose list is:

```text
1 -> 1 -> 2 -> 3 -> 3
```

Initially:

```text
t1 = first 1
t2 = first 1
t3 = second 1
```

Visualization:

```text
1 -> 1 -> 2 -> 3 -> 3
^    ^
|    |
t1   t2

     ^
     |
     t3
```

---

# Why Three Pointers?

We need:

- previous node connection
- current node
- next node

Because deletion in linked list needs previous node.

---

# Main Condition

```cpp
if(t2 -> val == t3 -> val)
```

Meaning:

```text
Duplicate found
```

---

# Case 1 : Duplicate at Head

Code:

```cpp
if(t2 == head)
```

---

# Example

```text
1 -> 1 -> 2
```

Current:

```text
t2 = first 1
t3 = second 1
```

We want to remove first `1`.

---

# Step 1

Move head forward:

```cpp
head = t3 ;
```

Now:

```text
head = second 1
```

List still:

```text
1 -> 1 -> 2
```

But head changed.

---

# Step 2

Delete old node:

```cpp
delete t2 ;
```

Now:

```text
1 -> 2
```

---

# Step 3

Move pointers again:

```cpp
t2 = head ;
t3 = head -> next ;
```

Now:

```text
t2 = 1
t3 = 2
```

---

# Important Observation

After deletion:

```text
New head becomes valid node
```

---

# Case 2 : Duplicate in Middle

Example:

```text
1 -> 2 -> 2 -> 3
```

Current:

```text
t1 = 1
t2 = first 2
t3 = second 2
```

Visualization:

```text
1 -> 2 -> 2 -> 3
^    ^    ^
|    |    |
t1   t2   t3
```

---

# Step 1

Skip duplicate node:

```cpp
t1 -> next = t3 ;
```

Now:

```text
1 ------> 2 -> 3
```

First `2` disconnected.

---

# Step 2

Delete duplicate node:

```cpp
delete t2 ;
```

Now memory cleared.

---

# Step 3

Move pointers:

```cpp
t2 = t3 ;
t3 = t2 -> next ;
```

Now:

```text
t2 = second 2
t3 = 3
```

List becomes:

```text
1 -> 2 -> 3
```

---

# Else Condition

If values are different:

```cpp
else
{
    t1 = t2 ;

    t2 = t3 ;

    t3 = t2 -> next ;
}
```

---

# Why Move All Pointers?

Because current nodes are unique.

Move to next nodes for checking.

---

# Example

Current:

```text
1 -> 2 -> 3
```

Pointers:

```text
t1 = 1
t2 = 2
t3 = 3
```

Since:

```text
2 != 3
```

Move all forward.

---

# Complete Dry Run

Input:

```text
1 -> 1 -> 2 -> 3 -> 3
```

---

# Initial State

```text
t1 = 1
t2 = 1
t3 = 1
```

Duplicate found.

---

# First Deletion

Delete first `1`.

List:

```text
1 -> 2 -> 3 -> 3
```

Pointers:

```text
t2 = 1
t3 = 2
```

---

# Move Forward

Since:

```text
1 != 2
```

Move all pointers.

Now:

```text
t1 = 1
t2 = 2
t3 = 3
```

---

# Move Forward Again

Since:

```text
2 != 3
```

Move again.

Now:

```text
t1 = 2
t2 = 3
t3 = 3
```

---

# Second Deletion

Duplicate found.

Delete first `3`.

List:

```text
1 -> 2 -> 3
```

Now:

```text
t2 = 3
t3 = NULL
```

Loop ends.

---

# Final Output

```text
1 -> 2 -> 3
```

---

# Time Complexity

## Traversal

Each node visited once.

```text
O(n)
```

---

# Space Complexity

No extra data structure used.

```text
O(1)
```

---

# Important Learning

This problem teaches:

- Linked list traversal
- Safe node deletion
- Head deletion handling
- Previous node management
- Pointer movement
- Memory management
- Adjacent comparison in sorted list

---

# Most Important Concept

In linked list deletion:

```text
You always need previous node connection
```

That is why:

```text
t1 is very important
```

Without `t1`:

```text
Cannot reconnect linked list properly
```
