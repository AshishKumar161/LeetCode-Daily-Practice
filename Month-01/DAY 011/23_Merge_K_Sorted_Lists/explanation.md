
# Explanation - Merge k Sorted Lists

# Approach 1: Brute Force

In brute force approach:

1. Store all linked list values into an array.
2. Sort the array.
3. Create a new sorted linked list.

---

# Step 1: Store Values

Traverse every linked list:

```cpp
while(temp != NULL)
{
    arr.push_back(temp -> data) ;
    temp = temp -> next ;
}
```

---

# Step 2: Sort Array

```cpp
sort(arr.begin() , arr.end()) ;
```

Example:

```text
Before Sort:
1 4 5 1 3 4 2 6

After Sort:
1 1 2 3 4 4 5 6
```

---

# Step 3: Create New Linked List

Insert sorted values into new linked list.

---

# Time Complexity

```text
O(N log N)
```

Where:

```text
N = total number of nodes
```

---

# Space Complexity

```text
O(N)
```

Extra array is used.

---

# Approach 2: Optimized Divide and Conquer

This is the optimized LeetCode solution.

We merge linked lists pair by pair.

---

# Main Idea

Suppose:

```text
lists = [L1, L2, L3, L4]
```

First merge:

```text
L1 + L2
L3 + L4
```

Now:

```text
mergedLists = [M1, M2]
```

Merge again:

```text
M1 + M2
```

Final merged list obtained.

---

# mergeTwoLists Function

This function merges two sorted linked lists.

We use:

```text
dummy node
tail pointer
```

Compare nodes:

```cpp
if(list1 -> val < list2 -> val)
```

Attach smaller node.

Move tail forward.

---

# Dry Run

Input:

```text
[1,4,5]
[1,3,4]
[2,6]
```

Step 1:

Merge first two lists:

```text
[1,1,3,4,4,5]
```

Step 2:

Merge with third list:

```text
[1,1,2,3,4,4,5,6]
```

Final Output:

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
```

---

# Time Complexity

```text
O(N log k)
```

Where:

- `N` = total nodes
- `k` = number of linked lists

---

# Space Complexity

```text
O(1)
```

Ignoring recursive/vector storage.

---

# Why This Approach Is Better

Instead of sorting all elements again:

- We merge already sorted lists.
- Faster than brute force.
- Efficient for large inputs.
