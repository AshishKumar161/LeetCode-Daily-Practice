# Plus One Linked List — Solution and Explanation

**Practice:** [Plus One Linked List — takeUforward](https://takeuforward.org/plus/dsa/problems/plus-one-linked-list)  
**Language:** C++  
**Submitted approach:** Convert to integer, add one, then rebuild the list

## Your C++ Code

```cpp
class Solution {
public:
    ListNode* addOne(ListNode* head) {
        ListNode* temp = head;
        long long number = 0;

        while (temp != nullptr) {
            number = number * 10 + temp->val;
            temp = temp->next;
        }

        number = number + 1;

        ListNode* newHead = nullptr;

        while (number > 0) {
            int rem = number % 10;

            ListNode* newNode = new ListNode(rem);
            newNode->next = newHead;
            newHead = newNode;

            number = number / 10;
        }

        return newHead;
    }
};
```

## Step-by-Step Explanation

### 1. Convert the list into a number

```cpp
ListNode* temp = head;
long long number = 0;

while (temp != nullptr) {
    number = number * 10 + temp->val;
    temp = temp->next;
}
```

If the list is `1 -> 2 -> 3`, the calculation is:

| Current digit | Calculation | `number` |
|---:|---|---:|
| 1 | `0 * 10 + 1` | 1 |
| 2 | `1 * 10 + 2` | 12 |
| 3 | `12 * 10 + 3` | 123 |

After the loop, `number` is `123`.

### 2. Add one

```cpp
number = number + 1;
```

For `123`, this changes the value to `124`.

### 3. Extract digits from right to left

```cpp
while (number > 0) {
    int rem = number % 10;
    // create a node and insert it at the front
    number = number / 10;
}
```

For `124`, the extracted digits are `4`, then `2`, then `1`. The modulo operator `% 10` gets the last digit, while integer division `/ 10` removes it.

### 4. Build the list in the correct order

```cpp
ListNode* newNode = new ListNode(rem);
newNode->next = newHead;
newHead = newNode;
```

Each new digit is inserted at the front, so extracting `4`, `2`, `1` builds `1 -> 2 -> 4`, not `4 -> 2 -> 1`.

## Dry Run

Input:

```text
head = [1,5,9]
```

### Convert and increment

```text
number = 0
Read 1: number = 0 * 10 + 1 = 1
Read 5: number = 1 * 10 + 5 = 15
Read 9: number = 15 * 10 + 9 = 159
Add one: number = 160
```

### Rebuild the linked list

| `number` before iteration | `rem = number % 10` | New list after front insertion | `number / 10` |
|---:|---:|---|---:|
| 160 | 0 | `0` | 16 |
| 16 | 6 | `6 -> 0` | 1 |
| 1 | 1 | `1 -> 6 -> 0` | 0 |

**Output:** `[1,6,0]`

## Complexity Analysis of Your Approach

Let `n` be the number of nodes.

- **Time complexity: `O(n)`** — one traversal converts the list into a number, and another loop creates at most `n + 1` digit nodes.
- **Auxiliary space:** `O(1)` for the numeric variable and pointers, excluding the newly allocated output list. The output list uses `O(n)` space.

## Important Limitation: Integer Overflow

A `long long` can only store values up to approximately `9.22 × 10^18`. A linked list may represent a number with many more digits, so this conversion can overflow and produce an incorrect answer. This approach is only safe when the input number is guaranteed to fit in `long long`.

## More Robust Approach: Add Carry Directly to the List

For an unrestricted-length digit list, avoid converting the entire list to an integer. One common method is to reverse the list, add one digit by digit while carrying, and reverse it back. Another method is to find the rightmost digit that is not `9`, increment it, and set all following digits to `0`.

Here is the rightmost-non-nine method:

```cpp
class Solution {
public:
    ListNode* addOne(ListNode* head) {
        if (head == nullptr) {
            return new ListNode(1);
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* lastNotNine = &dummy;

        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            if (cur->val != 9) {
                lastNotNine = cur;
            }
        }

        lastNotNine->val++;

        for (ListNode* cur = lastNotNine->next;
             cur != nullptr;
             cur = cur->next) {
            cur->val = 0;
        }

        if (dummy.val == 1) {
            return new ListNode(1, head);
        }

        return head;
    }
};
```

The key idea is that adding one only affects the suffix of `9` digits. Find the last digit that is not `9`, increment it, and turn all digits after it into zeroes. If every digit is `9`, a new leading `1` is required.

## Key Takeaway

Your integer-conversion approach is easy to understand, but it has an overflow limitation. For interview-ready linked-list code, prefer a digit-by-digit or rightmost-non-nine solution that works even when the number has thousands of digits.
