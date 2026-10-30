# 1834. Single-Threaded CPU — Detailed Explanation

**LeetCode:** [1834. Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/)  
**Language:** C++

This document explains both implementations provided.

## 1. Understand the CPU's Selection Rule

At any moment, the CPU can choose only from tasks whose enqueue time is less than or equal to the current time.

Among the available tasks, it chooses:
1. The task with the smallest processing time.
2. If processing times are equal, the task with the smallest original index.

A task that has not arrived yet must not be placed in the available-task heap.

Both solutions use the same simulation:
- Sort tasks by enqueue time.
- Add all tasks that have arrived to a min-heap.
- Execute the best available task.
- Advance the CPU clock.
- If no task is available, jump forward to the next enqueue time.

---

# 2. Approach 1 — Sorting + C++ Priority Queue

## Code

```cpp
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sortedTasks;

        for (int i = 0; i < n; i++) {
            int enqueueTime = tasks[i][0];
            int processingTime = tasks[i][1];
            int index = i;

            sortedTasks.push_back({enqueueTime, processingTime, index});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        vector<int> ans;
        long long curr_time = 0;
        int idx = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        while (idx < n || !pq.empty()) {
            if (pq.empty() && curr_time < sortedTasks[idx][0]) {
                curr_time = sortedTasks[idx][0];
            }

            while (idx < n && sortedTasks[idx][0] <= curr_time) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            auto task = pq.top();
            pq.pop();

            curr_time += task.first;
            ans.push_back(task.second);
        }

        return ans;
    }
};
```

## Step-by-Step Explanation

### Step 1: Store each task with its original index

```cpp
vector<vector<int>> sortedTasks;

for (int i = 0; i < n; i++) {
    int enqueueTime = tasks[i][0];
    int processingTime = tasks[i][1];
    int index = i;

    sortedTasks.push_back({enqueueTime, processingTime, index});
}
```

Each task is stored as:

```text
[enqueueTime, processingTime, originalIndex]
```

For example:

```text
Original tasks:
[[1,2], [2,4], [3,2], [4,1]]

Stored records:
[[1,2,0], [2,4,1], [3,2,2], [4,1,3]]
```

We save the original index because the answer must contain the original task labels, even after sorting.

### Step 2: Sort by enqueue time

```cpp
sort(sortedTasks.begin(), sortedTasks.end());
```

C++ compares vectors lexicographically: first enqueue time, then processing time, then index.

Therefore, tasks are primarily arranged in increasing enqueue-time order. If enqueue times are equal, the other fields break the tie. This is fine because the heap will later decide which available task should execute.

### Step 3: Initialize simulation variables

```cpp
vector<int> ans;
long long curr_time = 0;
int idx = 0;
```

- `ans` stores the execution order.
- `curr_time` stores the current CPU time.
- `idx` points to the next task in `sortedTasks` that has not yet been inserted into the heap.

We use `long long` for time because the sum of processing times can exceed the range of a 32-bit integer.

### Step 4: Create a min-heap

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

The heap stores:

```text
{processingTime, originalIndex}
```

`greater<pair<int,int>>` makes it a min-heap.

Pairs are compared lexicographically:
- Smaller processing time comes first.
- If processing times are equal, smaller original index comes first.

This exactly matches the CPU's selection rule.

### Step 5: Continue while work remains

```cpp
while (idx < n || !pq.empty())
```

Continue while either:
- There are tasks that have not yet been added to the heap, or
- There are tasks waiting in the heap.

### Step 6: Handle an idle CPU

```cpp
if (pq.empty() && curr_time < sortedTasks[idx][0]) {
    curr_time = sortedTasks[idx][0];
}
```

If the heap is empty, no task is available. The CPU must wait until the next task arrives.

Instead of increasing time one unit at a time, jump directly to the next enqueue time.

This access is safe: if the heap is empty while the loop is running, `idx < n` must be true. Otherwise, the loop would have ended.

### Step 7: Insert all tasks that have arrived

```cpp
while (idx < n && sortedTasks[idx][0] <= curr_time) {
    pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
    idx++;
}
```

Insert every task whose enqueue time is no greater than the current CPU time.

Only available tasks enter the priority queue. Incrementing `idx` ensures that each task is inserted exactly once.

### Step 8: Select and execute the best task

```cpp
auto task = pq.top();
pq.pop();

curr_time += task.first;
ans.push_back(task.second);
```

- `pq.top()` selects the task with the shortest processing time; ties are broken by original index.
- `pq.pop()` removes that task from the heap.
- `task.first` is its processing time, so add it to `curr_time`.
- `task.second` is its original index, so append it to `ans`.

The next iteration inserts tasks that arrived while this task was running.

### Step 9: Return the answer

```cpp
return ans;
```

## Dry Run — Example 1

Input:

```text
tasks = [[1,2], [2,4], [3,2], [4,1]]
```

Sorted records:

```text
[1,2,0]
[2,4,1]
[3,2,2]
[4,1,3]
```

| Current time | Available tasks | Selected task | Time after execution | Answer |
|---:|---|---|---:|---|
| 1 | 0 | 0 (processing time 2) | 3 | `[0]` |
| 3 | 1, 2 | 2 (processing time 2) | 5 | `[0,2]` |
| 5 | 1, 3 | 3 (processing time 1) | 6 | `[0,2,3]` |
| 6 | 1 | 1 (processing time 4) | 10 | `[0,2,3,1]` |

**Output:** `[0,2,3,1]`

## Complexity — Approach 1

Let `n` be the number of tasks.

- Building `sortedTasks`: `O(n)`.
- Sorting: `O(n log n)`.
- Each task is pushed into and popped from the priority queue once: `O(n log n)` total.
- **Time complexity:** `O(n log n)`.
- **Auxiliary space:** `O(n)` for the sorted records, heap, and answer.

---

# 3. Approach 2 — Sorting + Manually Implemented Min-Heap

This implementation performs the same simulation but does not use `priority_queue`.

It:
1. Packs enqueue time and original index into one `long long`.
2. Sorts the packed values.
3. Packs processing time and original index for each available task.
4. Maintains a min-heap manually using an array.

## Code

```cpp
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> result(n);
        if (n == 0) return result;

        vector<long long> order(n);
        for (int i = 0; i < n; i++)
            order[i] = ((long long)tasks[i][0] << 17) | (long long)i;
        sort(order.begin(), order.end());

        vector<long long> heap(n);
        int heapSize = 0;
        const long long IDX_MASK = (1LL << 17) - 1;

        auto push = [&](long long val) {
            int i = heapSize++;
            heap[i] = val;
            while (i > 0) {
                int parent = (i - 1) >> 1;
                if (heap[parent] <= heap[i]) break;
                swap(heap[parent], heap[i]);
                i = parent;
            }
        };

        auto pop = [&]() -> long long {
            long long top = heap[0];
            heap[0] = heap[--heapSize];
            int i = 0;
            while (true) {
                int l = 2*i + 1, r = 2*i + 2, sm = i;
                if (l < heapSize && heap[l] < heap[sm]) sm = l;
                if (r < heapSize && heap[r] < heap[sm]) sm = r;
                if (sm == i) break;
                swap(heap[i], heap[sm]);
                i = sm;
            }
            return top;
        };

        long long time = 0;
        int i = 0, ri = 0;

        while (i < n || heapSize > 0) {
            if (heapSize == 0) {
                long long et = order[i] >> 17;
                if (time < et) time = et;
            }

            while (i < n && (order[i] >> 17) <= time) {
                int idx = (int)(order[i] & IDX_MASK);
                push(((long long)tasks[idx][1] << 17) | (long long)idx);
                i++;
            }

            long long top = pop();
            time += top >> 17;
            result[ri++] = (int)(top & IDX_MASK);
        }

        return result;
    }
};
```

## Step-by-Step Explanation

### Step 1: Prepare the answer

```cpp
int n = tasks.size();
vector<int> result(n);
if (n == 0) return result;
```

`result` stores the original task indices in execution order. The empty-input check returns immediately if there are no tasks.

### Step 2: Pack enqueue time and index

```cpp
vector<long long> order(n);

for (int i = 0; i < n; i++)
    order[i] = ((long long)tasks[i][0] << 17) | (long long)i;
```

This uses bit packing.

The packed value represents:

```text
enqueueTime * 2^17 + originalIndex
```

A left shift by 17 bits is equivalent to multiplying by `2^17`.

Why 17 bits? The maximum number of tasks is `10^5`, and:

```text
2^17 = 131072
```

Every valid index (`0` through `99999`) fits in the lower 17 bits. The enqueue time is stored in the higher bits.

The cast to `long long` must happen before shifting. Enqueue times can be as large as `10^9`, so shifting a 32-bit `int` could overflow.

### Step 3: Sort packed enqueue records

```cpp
sort(order.begin(), order.end());
```

The higher bits contain enqueue time, so sorting the packed values sorts primarily by enqueue time. If enqueue times are equal, the lower bits put the smaller original index first.

### Step 4: Prepare the manual heap and index mask

```cpp
vector<long long> heap(n);
int heapSize = 0;
const long long IDX_MASK = (1LL << 17) - 1;
```

- `heap` is the array that stores the binary heap.
- `heapSize` is the number of values currently in the heap.
- `IDX_MASK` is a mask containing seventeen `1` bits.

The mask is used to extract the original index from a packed number.

### Step 5: Understand the heap's packed value

The heap stores:

```text
processingTime * 2^17 + originalIndex
```

Comparing these packed values is equivalent to comparing:

```text
(processingTime, originalIndex)
```

lexicographically:
- A smaller processing time produces a smaller packed value.
- If processing times are equal, a smaller index produces a smaller packed value.

Therefore, the smallest packed value is exactly the task the CPU should select.

### Step 6: Understand `push()`

```cpp
auto push = [&](long long val) {
    int i = heapSize++;
    heap[i] = val;

    while (i > 0) {
        int parent = (i - 1) >> 1;
        if (heap[parent] <= heap[i]) break;
        swap(heap[parent], heap[i]);
        i = parent;
    }
};
```

This inserts a value into a min-heap.

1. Put the new value at the next free position.
2. Calculate its parent index using `(i - 1) / 2`.
3. If the parent is already smaller than or equal to the child, the heap property is satisfied.
4. Otherwise, swap them.
5. Continue moving upward until the heap property is restored or the root is reached.

For a zero-indexed binary heap:

```text
Parent index = (i - 1) / 2
Left child   = 2*i + 1
Right child  = 2*i + 2
```

### Step 7: Understand `pop()`

```cpp
auto pop = [&]() -> long long {
    long long top = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;

    while (true) {
        int l = 2*i + 1, r = 2*i + 2, sm = i;

        if (l < heapSize && heap[l] < heap[sm]) sm = l;
        if (r < heapSize && heap[r] < heap[sm]) sm = r;

        if (sm == i) break;

        swap(heap[i], heap[sm]);
        i = sm;
    }

    return top;
};
```

This removes and returns the minimum value at the root.

1. Save the root in `top`.
2. Move the final heap element to the root and decrease `heapSize`.
3. Compare the root with its left and right children.
4. Find the smallest among them.
5. If a child is smaller, swap with that child.
6. Continue moving downward until the min-heap property is restored.

The function returns the original root value saved in `top`.

### Step 8: Initialize CPU time and pointers

```cpp
long long time = 0;
int i = 0, ri = 0;
```

- `time`: current CPU time.
- `i`: next task in the sorted packed array.
- `ri`: next position to fill in `result`.

### Step 9: Continue while work remains

```cpp
while (i < n || heapSize > 0)
```

Continue if there are undiscovered tasks or tasks waiting in the heap.

### Step 10: Move time forward if the CPU is idle

```cpp
if (heapSize == 0) {
    long long et = order[i] >> 17;
    if (time < et) time = et;
}
```

If the heap is empty, no task is available. Right-shifting by 17 extracts the next task's enqueue time.

Move `time` forward to that enqueue time if necessary.

### Step 11: Insert all tasks that have arrived

```cpp
while (i < n && (order[i] >> 17) <= time) {
    int idx = (int)(order[i] & IDX_MASK);
    push(((long long)tasks[idx][1] << 17) | (long long)idx);
    i++;
}
```

For every task whose enqueue time is no greater than the current time:

- `order[i] >> 17` extracts its enqueue time.
- `order[i] & IDX_MASK` extracts its original index.
- `tasks[idx][1]` gets its processing time.
- Pack processing time and original index, then insert that value into the heap.
- Increment `i` so the task is not inserted again.

### Step 12: Execute the minimum task

```cpp
long long top = pop();
time += top >> 17;
result[ri++] = (int)(top & IDX_MASK);
```

- `pop()` returns the available task with the shortest processing time and smallest index.
- `top >> 17` extracts its processing time and advances the CPU clock.
- `top & IDX_MASK` extracts the original task index.
- Store that index in the answer.

### Step 13: Return the result

```cpp
return result;
```

## Dry Run — Example 1

Input:

```text
tasks = [[1,2], [2,4], [3,2], [4,1]]
```

The packed enqueue records are sorted by enqueue time. The CPU simulation is identical to Approach 1:

| Current time | Available tasks | Selected task | Time after execution | Result |
|---:|---|---|---:|---|
| 1 | 0 | 0 (processing time 2) | 3 | `[0]` |
| 3 | 1, 2 | 2 (processing time 2) | 5 | `[0,2]` |
| 5 | 1, 3 | 3 (processing time 1) | 6 | `[0,2,3]` |
| 6 | 1 | 1 (processing time 4) | 10 | `[0,2,3,1]` |

**Output:** `[0,2,3,1]`

## Complexity — Approach 2

- Packing records: `O(n)`.
- Sorting: `O(n log n)`.
- Each task is pushed once and popped once; each heap operation costs `O(log n)`.
- **Time complexity:** `O(n log n)`.
- **Auxiliary space:** `O(n)` for `order`, `heap`, and `result`.

---

# 4. Important Bit-Manipulation Concepts

### Left shift (`<<`)

```cpp
value << 17
```

Moves the bits of `value` seventeen positions to the left. For non-negative values, this is equivalent to multiplying by `2^17`, provided the result fits in the type.

### Right shift (`>>`)

```cpp
packed >> 17
```

Removes the lower seventeen bits and retrieves the value stored in the upper bits.

### Bitwise AND (`&`)

```cpp
packed & IDX_MASK
```

Keeps only the lower seventeen bits, which contain the original index.

### Why the mask works

```cpp
const long long IDX_MASK = (1LL << 17) - 1;
```

This creates a mask of seventeen `1` bits. AND-ing the packed value with this mask extracts the index.

### Why packing preserves priority order

Every task index is less than `2^17`. Therefore, the index fits entirely in the lower seventeen bits and cannot overlap the processing-time field.

Comparing packed values first compares processing time and then original index. This reproduces the CPU's priority rule.

---

# 5. Difference Between Both Approaches

| Feature | Approach 1 | Approach 2 |
|---|---|---|
| Task representation | Three integers per task | One packed `long long` |
| Available-task structure | STL `priority_queue` | Manually implemented binary min-heap |
| Heap element | `pair<int,int>` | Packed `long long` |
| Tie-breaking | Pair comparison | Packed numeric comparison |
| Heap operations | Provided by STL | Implemented manually |
| Time complexity | `O(n log n)` | `O(n log n)` |
| Auxiliary space | `O(n)` | `O(n)` |
| Ease of understanding | Easier | More advanced |

## Which Approach Should You Prefer?

**Approach 1 is recommended for learning and interviews.** It is readable, directly expresses the task priority, and uses a well-tested STL data structure.

**Approach 2 is useful for learning advanced implementation details**, including binary heaps, bit packing, shifts, and masks. It has the same Big-O complexity; it is not asymptotically faster.

## Final Takeaway

Both implementations use the same greedy algorithm:

1. Sort tasks by enqueue time.
2. Add all arrived tasks to a min-heap.
3. Select the available task with the shortest processing time.
4. Break ties using the original index.
5. Advance CPU time by the selected task's processing time.
6. If no task is available, jump to the next enqueue time.

The key insight is that **sorting handles task arrival order, while the min-heap handles task selection order**.
