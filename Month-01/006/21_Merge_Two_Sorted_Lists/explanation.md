
# Explanation - Merge Two Sorted Lists

## Approach

We use a dummy node and a tail pointer.

```text
dummy
tail
temp1
temp2
```

- `temp1` traverses list1
- `temp2` traverses list2
- `tail` builds the merged linked list

We compare values from both linked lists and attach the smaller node.

## Important Idea

```cpp
if(temp1 -> val <= temp2 -> val)
```

If value in list1 is smaller, attach it.

Otherwise attach node from list2.

## Code Logic

```cpp
while(temp2 != NULL && temp1 != NULL)
```

Loop runs until one linked list becomes empty.

Inside loop:

```cpp
tail -> next = temp1 ;
temp1 = temp1 -> next ;
```

or

```cpp
tail -> next = temp2 ;
temp2 = temp2 -> next ;
```

Move tail forward:

```cpp
tail = tail -> next ;
```

## Remaining Nodes

After loop ends, one list may still contain nodes.

```cpp
if(temp1 != NULL)
{
    tail -> next = temp1 ;
}
else
{
    tail -> next = temp2 ;
}
```

## Dry Run

Input:

```text
list1 = [1,2,4]
list2 = [1,3,4]
```

Step 1:

```text
1 <= 1
Take node from list1
```

Merged:

```text
1
```

Step 2:

```text
2 > 1
Take node from list2
```

Merged:

```text
1 -> 1
```

Step 3:

```text
2 <= 3
Take node from list1
```

Merged:

```text
1 -> 1 -> 2
```

Step 4:

```text
4 > 3
Take node from list2
```

Merged:

```text
1 -> 1 -> 2 -> 3
```

Step 5:

```text
4 <= 4
Take node from list1
```

Merged:

```text
1 -> 1 -> 2 -> 3 -> 4
```

Remaining node:

```text
4
```

Final Output:

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4
```

## Time Complexity

```text
O(n + m)
```

Where:

- `n` = size of list1
- `m` = size of list2

## Space Complexity

```text
O(1)
```

No extra linked list is created.

## Best Part

This approach directly reuses existing nodes without creating new nodes.
