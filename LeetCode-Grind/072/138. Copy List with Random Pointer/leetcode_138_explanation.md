# 138. Copy List with Random Pointer — Code Explanation

**LeetCode:** [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)  
**Language:** C++

## 1. What Is the Problem Asking?

Each node has a `next` pointer and a `random` pointer. The random pointer may point to any node in the list or to `nullptr`.

A **deep copy** means creating brand-new nodes with the same values and equivalent pointer relationships. The copied list must not point to any original node.

## 2. Approach 1 — Your Submitted Code: Copy, Then Search

### Code

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* newHead = new Node(head->val);
        Node* temp = head->next;
        Node* newTemp = newHead;

        // Pass 1: Copy the next chain.
        while (temp != nullptr) {
            newTemp->next = new Node(temp->val);
            newTemp = newTemp->next;
            temp = temp->next;
        }

        // Pass 2: Find each random target in the original list.
        temp = head;
        newTemp = newHead;

        while (temp != nullptr) {
            if (temp->random != nullptr) {
                Node* p1 = head;
                Node* p2 = newHead;

                while (p1 != temp->random) {
                    p1 = p1->next;
                    p2 = p2->next;
                }

                newTemp->random = p2;
            }

            temp = temp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
```

### Pass 1: Create the copied `next` chain

Original:
```text
7 -> 13 -> 11 -> 10 -> 1 -> nullptr
```

After the first loop, a separate chain exists:
```text
7 -> 13 -> 11 -> 10 -> 1 -> nullptr
```

The values look the same, but these are new node objects. `temp` traverses the original list and `newTemp` traverses the copied list. At this stage, the copied nodes' random pointers are not assigned yet.

### Pass 2: Connect the random pointers

For every original node:
- `temp->random` tells us the target original node.
- `p1` starts at the original head and searches for that exact node.
- `p2` moves alongside `p1` in the copied list.
- When `p1 == temp->random`, `p2` is the corresponding copied target.
- Assign `newTemp->random = p2`.

Pointer identity matters here. Two nodes may have the same value but still be different nodes.

### Dry Run

Input:
`[[7,null],[13,0],[11,4],[10,2],[1,0]]`

Random relationships:
- `7` → `nullptr`
- `13` → node `7`
- `11` → node `1`
- `10` → node `11`
- `1` → node `7`

After the first pass, all values and `next` links are copied. The second pass assigns:

```text
copy(7).random  = nullptr
copy(13).random = copy(7)
copy(11).random = copy(1)
copy(10).random = copy(11)
copy(1).random  = copy(7)
```

The original list remains unchanged.

### Complexity

For `n` nodes:
- **Time:** `O(n²)` worst case, because each random target may require scanning up to `n` nodes.
- **Auxiliary space:** `O(1)` excluding the `O(n)` new nodes required for the output.

## 3. Approach 2 — Hash Map

Store a mapping from each original node address to its copied node address. Then assign `next` and `random` pointers using the map.

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> copied;

        // Create all copied nodes.
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            copied[curr] = new Node(curr->val);
        }

        // Connect the copied pointers.
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            copied[curr]->next =
                curr->next ? copied[curr->next] : nullptr;
            copied[curr]->random =
                curr->random ? copied[curr->random] : nullptr;
        }

        return copied[head];
    }
};
```

### Why it works

If the map contains `copied[originalNode] = copiedNode`, then `copied[curr->random]` directly retrieves the copied version of the random target.

- **Time:** `O(n)` expected.
- **Auxiliary space:** `O(n)` for the map, excluding the copied output nodes.

## 4. Approach 3 — Interweaving Nodes

This common solution uses three passes and `O(1)` auxiliary space, excluding the new output nodes.

### Pass 1: Insert each copy after its original

```text
Original: A -> B -> C
After:    A -> A' -> B -> B' -> C -> C'
```

### Pass 2: Set copied random pointers

For each original node with a random target:

```cpp
original->next->random = original->random->next;
```

Why? `original->next` is the copied node, and `original->random->next` is the copied version of the random target.

### Pass 3: Separate both lists

Restore the original `next` chain and connect the copied nodes into their own list.

- **Time:** `O(n)`.
- **Auxiliary space:** `O(1)`, excluding the copied nodes.
- **Caution:** The original list is temporarily modified, so separation must restore it correctly.

## 5. Comparison

| Approach | Time | Auxiliary space excluding output | Main idea |
|---|---|---|---|
| Copy, then search (your code) | `O(n²)` worst case | `O(1)` | Search both lists in parallel for each random target |
| Hash map | `O(n)` expected | `O(n)` | Map each original node to its copy |
| Interweaving | `O(n)` | `O(1)` | Place copies beside originals, connect random pointers, then separate |

## 6. Important Details and Common Mistakes

- Return `nullptr` if `head` is `nullptr`.
- Do not copy only values; every node must be a distinct object.
- Use node pointers, not values, to identify random targets.
- A random pointer can point forward, backward, to the same node, or to `nullptr`.
- Do not leave copied pointers referencing original nodes.
- `random_index` is only the problem's input format; the function receives actual pointers.

## Key Takeaway

Your approach is straightforward and uses constant auxiliary space beyond the copied nodes, but can take `O(n²)` time. The hash-map solution is easier to make linear-time, while interweaving achieves linear time with constant auxiliary space.
