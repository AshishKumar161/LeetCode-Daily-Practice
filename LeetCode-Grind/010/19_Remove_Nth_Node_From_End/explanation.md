
# Explanation - Remove Nth Node From End of List

# Approach

This is a brute force approach.

We first count the total number of nodes in the linked list.

Then we calculate the position of the node from the start.

Finally we delete that node.

---

# Step 1: Count Total Nodes

```cpp
while(temp != NULL)
{
    count++ ;
    temp = temp -> next ;
}
```

Example:

```text
1 -> 2 -> 3 -> 4 -> 5
```

Total nodes:

```text
count = 5
```

---

# Step 2: Special Case

If:

```cpp
count == n
```

It means head node must be deleted.

Example:

```text
1 -> 2 -> 3
n = 3
```

Delete head:

```cpp
head = head -> next ;
```

---

# Step 3: Find Previous Node

We move to the node before the target node.

Loop:

```cpp
for(int i = 1 ; i < count - n ; i++)
{
    temp = temp -> next ;
}
```

Example:

```text
count = 5
n = 2
```

Target node:

```text
4
```

Move to:

```text
3
```

Because node after `3` must be deleted.

---

# Step 4: Delete Node

Store node to delete:

```cpp
ListNode* deleteNode = temp -> next ;
```

Change links:

```cpp
temp -> next = deleteNode -> next ;
```

Delete memory:

```cpp
delete deleteNode ;
```

---

# Dry Run

Input:

```text
1 -> 2 -> 3 -> 4 -> 5
n = 2
```

Step 1:

```text
count = 5
```

Step 2:

```text
count - n = 3
```

Move temp to node `3`.

Step 3:

```text
deleteNode = 4
```

Update links:

```text
3 -> 5
```

Final Output:

```text
1 -> 2 -> 3 -> 5
```

---

# Time Complexity

```text
O(n)
```

Because linked list is traversed.

---

# Space Complexity

```text
O(1)
```

No extra space used.

---

# Important Note

This is a brute force approach because:

- First traversal for counting
- Second traversal for deletion

Optimized solution uses two pointers and removes node in one traversal.git add .
git commit -m "Day 010: Solve LeetCode 19 Remove Nth Node From End"
git push
