
# LeetCode 24 - Swap Nodes in Pairs

## Question

Given a linked list, swap every two adjacent nodes and return its head.

You must solve the problem without modifying the values inside the nodes.

Only nodes themselves may be changed.

---

## Example 1

Input:

```text
head = [1,2,3,4]
```

Output:

```text
[2,1,4,3]
```

---

## Example 2

Input:

```text
head = []
```

Output:

```text
[]
```

---

## Example 3

Input:

```text
head = [1]
```

Output:

```text
[1]
```

---

## Topics

- Linked List
- Recursion

# LeetCode 24 - Swap Nodes in Pairs

## Problem

Given a linked list, swap every two adjacent nodes and return its head.

You must swap the nodes themselves, not just their values.

---

# Approach Used

We use:

* A **dummy node**
* Three pointers:

  * `prev/temp`
  * `first/h1`
  * `second/h2`

This approach works in **O(n)** time and **O(1)** space.

---

# Why Dummy Node?

A dummy node helps handle swapping at the head easily.

Example:

Before:

```text
dummy -> 1 -> 2 -> 3 -> 4
```

After swapping first pair:

```text
dummy -> 2 -> 1 -> 3 -> 4
```

Finally we return:

```cpp
return dummy.next;
```

---

# Code 1

```cpp
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        // empty list or one node
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode *temp = &dummy;

        while (temp->next != NULL &&
               temp->next->next != NULL)
        {
            ListNode *h1 = temp->next;
            ListNode *h2 = h1->next;

            // swap links
            h1->next = h2->next;
            h2->next = h1;
            temp->next = h2;

            // move temp
            temp = h1;
        }

        return dummy.next;
    }
};
```

---

# Dry Run

Input:

```text
1 -> 2 -> 3 -> 4
```

Initial:

```text
dummy -> 1 -> 2 -> 3 -> 4
temp = dummy
```

---

## First Iteration

### Step 1

```cpp
h1 = temp->next;
```

```text
h1 = 1
```

### Step 2

```cpp
h2 = h1->next;
```

```text
h2 = 2
```

---

## Swap

### Line 1

```cpp
h1->next = h2->next;
```

```text
1 -> 3
```

List becomes:

```text
dummy -> 1 -> 3 -> 4
2 separated
```

---

### Line 2

```cpp
h2->next = h1;
```

```text
2 -> 1
```

Now:

```text
2 -> 1 -> 3 -> 4
```

---

### Line 3

```cpp
temp->next = h2;
```

Connect previous part with swapped nodes.

```text
dummy -> 2 -> 1 -> 3 -> 4
```

---

### Move temp

```cpp
temp = h1;
```

```text
temp = 1
```

---

## Second Iteration

Current list:

```text
dummy -> 2 -> 1 -> 3 -> 4
```

Now:

```text
h1 = 3
h2 = 4
```

After swapping:

```text
dummy -> 2 -> 1 -> 4 -> 3
```

---

# Final Output

```text
2 -> 1 -> 4 -> 3
```

---

# Understanding Important Lines

## 1. `h1->next = h2->next`

Remove connection between first and second node.

Before:

```text
1 -> 2 -> 3
```

After:

```text
1 -> 3
```

---

## 2. `h2->next = h1`

Reverse the pair.

Before:

```text
2 -> 3
```

After:

```text
2 -> 1
```

---

## 3. `temp->next = h2`

Attach swapped pair back to list.

Before:

```text
dummy -> 1
```

After:

```text
dummy -> 2
```

---

# Why `temp = h1` ?

After swapping:

```text
2 -> 1
```

`h1` becomes the second node of swapped pair.

So next swapping should start after `1`.

That is why:

```cpp
temp = h1;
```

---

# Code 2

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0) ;
        dummy.next= head ;

        ListNode* prev = &dummy ;

        while(prev -> next != NULL &&
              prev -> next -> next != NULL )
        {
            ListNode* first = prev -> next ;
            ListNode* second = first -> next ;

            first -> next = second -> next ;
            second -> next = first ;
            prev -> next = second ;

            prev = first ;
        }

        return dummy.next ;
    }
};
```

---

# Difference Between Both Codes

There is almost NO difference.

Only variable names changed.

| Code 1 | Code 2 |
| ------ | ------ |
| temp   | prev   |
| h1     | first  |
| h2     | second |

Logic is exactly the same.

---

# Time Complexity

```text
O(n)
```

We visit each node once.

---

# Space Complexity

```text
O(1)
```

No extra space used.

---

# Key Learning

This problem teaches:

* Dummy node usage
* Pointer manipulation
* Linked list swapping
* How to reconnect nodes after changing links
* Safe traversal in linked list problems
