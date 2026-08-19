
# Explanation - Rotate List

# Approach

We rotate the linked list toward the right by `k` positions.

Example:

```text
1 -> 2 -> 3 -> 4 -> 5
k = 2
```

After rotation:

```text
4 -> 5 -> 1 -> 2 -> 3
```

---

# Step 1: Find Length

We first calculate linked list length.

```cpp
while(tail -> next != NULL)
{
    tail = tail -> next ;
    len++ ;
}
```

Example:

```text
Length = 5
```

---

# Step 2: Reduce Extra Rotations

If:

```text
k > length
```

Then repeated rotations happen.

So:

```cpp
k = k % len ;
```

Example:

```text
k = 7
len = 5

7 % 5 = 2
```

Only 2 rotations needed.

---

# Step 3: Make Circular Linked List

Connect tail to head:

```cpp
tail -> next = head ;
```

Now:

```text
1 -> 2 -> 3 -> 4 -> 5
^                   |
|___________________|
```

---

# Step 4: Find New Tail

New tail position:

```cpp
step = len - k
```

Example:

```text
len = 5
k = 2

step = 3
```

Move temp:

```cpp
for(int i = 1 ; i < step ; i++)
{
    temp = temp -> next ;
}
```

Temp reaches node `3`.

---

# Step 5: Break the Circular List

New head:

```cpp
head = temp -> next ;
```

New head becomes:

```text
4
```

Break connection:

```cpp
temp -> next = NULL ;
```

Final list:

```text
4 -> 5 -> 1 -> 2 -> 3
```

---

# Dry Run

Input:

```text
1 -> 2 -> 3 -> 4 -> 5
k = 2
```

Length:

```text
len = 5
```

Reduce rotations:

```text
k = 2
```

Make circular:

```text
5 -> 1
```

Find new tail:

```text
step = 5 - 2 = 3
```

Temp stops at:

```text
3
```

New head:

```text
4
```

Break link:

```text
3 -> NULL
```

Final Output:

```text
4 -> 5 -> 1 -> 2 -> 3
```

---

# Time Complexity

```text
O(n)
```

Only one traversal used.

---

# Space Complexity

```text
O(1)
```

No extra space used.

---

# Best Part

This approach rotates the linked list without using extra arrays or vectors.