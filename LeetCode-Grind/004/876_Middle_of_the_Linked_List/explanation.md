# Explanation - Middle of the Linked List

## Approach 1: Basic Approach

In the basic approach, we first count the total number of nodes in the linked list.

After counting, we find the middle position.

```cpp
int mid = (count / 2) + 1;
```

This formula works for both odd and even length linked lists.

## Example 1

```text
head = [1,2,3,4,5]
```

Total nodes:

```text
count = 5
```

Middle position:

```text
mid = (5 / 2) + 1
mid = 2 + 1
mid = 3
```

So answer starts from node `3`.

Output:

```text
[3,4,5]
```

## Example 2

```text
head = [1,2,3,4,5,6]
```

Total nodes:

```text
count = 6
```

Middle position:

```text
mid = (6 / 2) + 1
mid = 3 + 1
mid = 4
```

So answer starts from node `4`.

Output:

```text
[4,5,6]
```

## Basic Approach Code Logic

First count nodes:

```cpp
while (temp != NULL) {
    count++;
    temp = temp->next;
}
```

Then go to middle node:

```cpp
for (int i = 1; i < mid; i++) {
    temp = temp->next;
}
```

Finally return middle node:

```cpp
return temp;
```

## Time Complexity

```text
O(n)
```

We traverse the linked list two times.

## Space Complexity

```text
O(1)
```

We use only variables.

---

# Approach 2: Slow and Fast Pointer

This is the optimized LeetCode approach.

We use two pointers:

```text
slow
fast
```

- `slow` moves one step at a time.
- `fast` moves two steps at a time.

When `fast` reaches the end, `slow` will be at the middle node.

## Code Logic

```cpp
while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
}
```

## Dry Run

Input:

```text
head = [1,2,3,4,5]
```

Start:

```text
slow = 1
fast = 1
```

Step 1:

```text
slow = 2
fast = 3
```

Step 2:

```text
slow = 3
fast = 5
```

Now `fast->next == NULL`, so loop stops.

Answer:

```text
slow = 3
```

Output:

```text
[3,4,5]
```

## Even Length Dry Run

Input:

```text
head = [1,2,3,4,5,6]
```

Start:

```text
slow = 1
fast = 1
```

Step 1:

```text
slow = 2
fast = 3
```

Step 2:

```text
slow = 3
fast = 5
```

Step 3:

```text
slow = 4
fast = NULL
```

Answer:

```text
slow = 4
```

Output:

```text
[4,5,6]
```

## Time Complexity

```text
O(n)
```

We traverse the linked list only once.

## Space Complexity

```text
O(1)
```

We use only two pointers.

## Best Approach

The slow and fast pointer approach is better because it finds the middle node in one traversal.
