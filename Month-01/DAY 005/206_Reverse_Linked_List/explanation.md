# Explanation - Reverse Linked List

## Approach

We use three pointers:

```text
t1 = previous node
t2 = current node
t3 = next node
```

The main idea is to reverse the direction of every link.

Original list:

```text
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

After reverse:

```text
5 -> 4 -> 3 -> 2 -> 1 -> NULL
```

## Important Step

First, we make the first node point to `NULL` because after reversing, the first node becomes the last node.

```cpp
t1 -> next = NULL ;
```

## Code Logic

```cpp
while(t2 != NULL)
{
    t3 = t2 -> next ;
    t2 -> next = t1 ;
    t1 = t2 ;
    t2 = t3 ;
}
```

## Dry Run

Input:

```text
head = [1,2,3,4,5]
```

Start:

```text
t1 = 1
t2 = 2
t3 = 3
```

Make first node last:

```text
1 -> NULL
```

Step 1:

```text
t3 = 3
2 -> 1 -> NULL
t1 = 2
t2 = 3
```

Step 2:

```text
t3 = 4
3 -> 2 -> 1 -> NULL
t1 = 3
t2 = 4
```

Step 3:

```text
t3 = 5
4 -> 3 -> 2 -> 1 -> NULL
t1 = 4
t2 = 5
```

Step 4:

```text
t3 = NULL
5 -> 4 -> 3 -> 2 -> 1 -> NULL
t1 = 5
t2 = NULL
```

Now loop stops.

Final head:

```text
head = t1
head = 5
```

Output:

```text
[5,4,3,2,1]
```

## Time Complexity

```text
O(n)
```

Because we visit every node once.

## Space Complexity

```text
O(1)
```

Because we use only three pointers.

## Final Result

The linked list is reversed successfully.
