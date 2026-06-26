
# Explanation - Remove Linked List Elements

# Approach

We remove every node whose value equals `val`.

We use two pointers:

```text
prev
curr
```

- `curr` traverses the linked list.
- `prev` keeps track of the previous valid node.

---

# Important Case

The head itself may contain the target value.

Example:

```text
6 -> 6 -> 1 -> 2
```

So first we move head forward:

```cpp
while(head != NULL && head -> val == val)
{
    head = head -> next ;
}
```

Now head points to the first valid node.

---

# Main Logic

Traverse the linked list:

```cpp
while(curr != NULL)
```

If current node value equals target value:

```cpp
prev -> next = curr -> next ;
```

This removes the node.

Move current pointer:

```cpp
curr = curr -> next ;
```

Otherwise move both pointers:

```cpp
prev = curr ;
curr = curr -> next ;
```

---

# Dry Run

Input:

```text
1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
val = 6
```

Start:

```text
prev = 1
curr = 1
```

Step 1:

```text
curr = 1
Not equal to 6
Move both pointers
```

Step 2:

```text
curr = 2
Not equal to 6
Move both pointers
```

Step 3:

```text
curr = 6
Equal to target
Remove node
```

List becomes:

```text
1 -> 2 -> 3 -> 4 -> 5 -> 6
```

Continue traversal.

Final Output:

```text
1 -> 2 -> 3 -> 4 -> 5
```

---

# Time Complexity

```text
O(n)
```

We traverse the linked list once.

---

# Space Complexity

```text
O(1)
```

No extra space is used.

---

# Best Part

This approach removes nodes directly without creating a new linked list.
