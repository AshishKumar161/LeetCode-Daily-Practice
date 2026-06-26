
# Explanation - Linked List Cycle

# Approach 1: Brute Force

In the brute force approach, we store every visited node inside a hash set.

If we visit the same node again, it means a cycle exists.

## Logic

```cpp
unordered_set<Node*> visited ;
```

Traverse linked list:

```cpp
while(temp != NULL)
```

Check:

```cpp
if(visited.find(temp) != visited.end())
{
    return true ;
}
```

Otherwise insert node into set:

```cpp
visited.insert(temp) ;
```

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(n)
```

Because extra hash set is used.

---

# Approach 2: Floyd Cycle Detection Algorithm

This is the optimized LeetCode solution.

We use two pointers:

```text
slow
fast
```

- `slow` moves one step.
- `fast` moves two steps.

If a cycle exists, both pointers will eventually meet.

## Main Logic

```cpp
slow = slow -> next ;
fast = fast -> next -> next ;
```

Check:

```cpp
if(fast == slow)
{
    return true ;
}
```

If `fast` reaches `NULL`, then no cycle exists.

## Dry Run

Input:

```text
1 -> 2 -> 3 -> 4
     ^         |
     |_________|
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
fast = 2
```

Step 3:

```text
slow = 4
fast = 4
```

Now both pointers meet.

Cycle exists.

Output:

```text
true
```

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(1)
```

No extra space is used.

---

# Best Approach

Floyd Cycle Detection Algorithm is better because it detects the cycle using constant extra space.git add .
git commit -m "Day 007: Solve LeetCode 141 Linked List Cycle"
git push
