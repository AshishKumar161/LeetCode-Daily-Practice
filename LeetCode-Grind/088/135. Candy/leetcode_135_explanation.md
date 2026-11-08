# LeetCode 135: Candy - Detailed Explanation

## 1. Problem Understanding & Core Rules

We need to distribute the minimum number of candies to $n$ children positioned in a row according to two mandatory rules:

1. Every child receives at least $1$ candy.
2. If child $i$ has a higher rating than their immediate neighbor (left neighbor $i-1$ or right neighbor $i+1$), child $i$ must receive strictly more candies than that neighbor.

**Important Note on Ties:**
If two adjacent children have the **same** rating (`nums[i] == nums[i-1]`), the rule does *not* require them to have equal candies, nor does it require one to have more than the other. An equal rating breaks the strictly increasing or decreasing dependency chain, allowing the child to be assigned $1$ candy if it minimizes the total sum.

---

## 2. Approach 1: Two-Pass Vectors ($\mathcal{O}(N)$ Space)

### Intuition:
A child has two neighbors: one on the left and one on the right. Satisfying both constraints simultaneously in a single forward scan is tricky because a child's candy count depends on both sides.

We can split the problem into two passes:
1. **Left-to-Right Pass:** Check `nums[i] > nums[i-1]`. If so, give `left[i-1] + 1` candies; otherwise, assign $1$.
2. **Right-to-Left Pass:** Check `nums[i] > nums[i+1]`. If so, give `right.back() + 1` candies; otherwise, assign $1$.
3. **Merging:** Reverse the `right` vector so indices line up with `left`, then take $\max(\text{left}[i], \text{right}[i])$ for each child to satisfy both constraints at the same time.

### Code Implementation Walkthrough:
```cpp
class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size() ;

        vector < int > left ;
        vector < int > right ;

        left.push_back(1) ;
        right.push_back(1) ;

        for (int i = 1 ; i < n ; i++)
        {
            if (nums[i] > nums[i-1])
            {
                left.push_back(left[i-1] + 1) ;
            }

            if (nums[i] <= nums[i-1])
            {
                left.push_back(1) ;
            } 
        }

        for (int i = n - 2 ; i >= 0 ; i--)
        {
            if (nums[i] > nums[i+1])
            {
                right.push_back(right.back() + 1) ;
            }

            else 
            {
                right.push_back(1) ;
            }
        }

        reverse(right.begin() , right.end()) ;
        
        int sum = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            sum += max(left[i] , right[i]) ;
        
        }

        return sum ;
    }
};
```

### Dry Run: `nums = [1, 0, 2]`
- $n = 3$
- **Left Pass:**
  - $i = 0$: `left[0] = 1`
  - $i = 1$: `nums[1] (0) <= nums[0] (1)` $\rightarrow$ `left.push_back(1)`
  - $i = 2$: `nums[2] (2) > nums[1] (0)` $\rightarrow$ `left.push_back(left[1] + 1) = 2`
  - `left = [1, 1, 2]`
- **Right Pass (built backwards):**
  - Start with `right = [1]` (representing index $2$)
  - $i = 1$: `nums[1] (0) <= nums[2] (2)` $\rightarrow$ `right.push_back(1)`
  - $i = 0$: `nums[0] (1) > nums[1] (0)` $\rightarrow$ `right.push_back(right.back() + 1) = 2`
  - `right = [1, 1, 2]`
  - After `reverse(right.begin(), right.end())`: `right = [2, 1, 1]`
- **Combining:**
  - $i = 0$: $\max(1, 2) = 2$
  - $i = 1$: $\max(1, 1) = 1$
  - $i = 2$: $\max(2, 1) = 2$
  - Total `sum = 2 + 1 + 2 = 5`

### Complexity Analysis:
- **Time Complexity:** $\mathcal{O}(N)$ — One pass left-to-right, one pass right-to-left, one reversal of size $N$, and one pass to sum up max values.
- **Space Complexity:** $\mathcal{O}(N)$ — Uses two auxiliary vectors `left` and `right` of size $N$.

---

## 3. Approach 2: One-Pass Slope / Peak-Valley Method ($\mathcal{O}(1)$ Space)

### Intuition:
Instead of allocating auxiliary arrays, visualize the ratings array as a sequence of **peaks** (increasing slopes), **valleys** (decreasing slopes), and **plateaus** (equal elements).

```text
       /\
      /  \
     /    \
    /      \
Peak        Valley
```

1. **Baseline Candies:** Each child receives at least $1$ candy, so start with `total_candy = n`.
2. **Ascending Slope (`curr_peak`):**
   - When ratings increase (`nums[i] > nums[i-1]`), each child needs $1, 2, 3, \dots$ additional candies above baseline.
   - Increment `curr_peak` and add it to `total_candy`.
3. **Descending Slope (`curr_valley`):**
   - When ratings decrease (`nums[i] < nums[i-1]`), children downhill also need $1, 2, 3, \dots$ additional candies.
   - Increment `curr_valley` and add it to `total_candy`.
4. **Peak Overlap Correction:**
   - The child at the peak was included in both the ascending slope and descending slope additions.
   - The peak should only take the height of the taller slope: $\max(\text{curr\_peak}, \text{curr\_valley})$.
   - Because both slopes added their values, the peak received both. To correct this, subtract the smaller of the two:
     $$\text{total\_candy} -= \min(\text{curr\_peak}, \text{curr\_valley})$$
5. **Flat Plateau:**
   - When `nums[i] == nums[i-1]`, adjacent equal ratings can reset to $1$ candy. Simply advance `i++` and `continue`.

### Code Implementation Walkthrough:
```cpp
class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size() ;
        int total_candy = n ;
        int i = 1 ;

        while ( i < n )
        {
            if (nums[i] == nums[i-1])
            {
                i++ ;
                continue ;
            }

            int curr_peak = 0 ;

            while ( i < n && nums[i] > nums[i-1])
            {
                curr_peak++ ;
                total_candy += curr_peak ;
                i++ ;
            }

            if (i == n )
            {
                return total_candy ;
            }

            int curr_valley = 0 ;

            while (i < n && nums[i] < nums[i-1])
            {
                curr_valley++ ;
                total_candy += curr_valley ;
                i++ ;
            }

            total_candy -= min(curr_peak , curr_valley) ;
        }

        return total_candy ; 

    }
};
```

---

## 4. Comprehensive Dry Run (Approach 2)

### Input: `nums = [1, 3, 5, 4, 3, 2, 1]`
- $n = 7$
- Initial: `total_candy = 7`, `i = 1`

#### Step 1: Upward Slope (Climbing Peak)
- `nums[1] (3) > nums[0] (1)` $\rightarrow$ `curr_peak = 1`, `total_candy = 7 + 1 = 8`, `i = 2`
- `nums[2] (5) > nums[1] (3)` $\rightarrow$ `curr_peak = 2`, `total_candy = 8 + 2 = 10`, `i = 3`
- Loop ends because `nums[3] (4) < nums[2] (5)`.
- Ascending slope summary: `curr_peak = 2`.

#### Step 2: Downward Slope (Falling to Valley)
- `nums[3] (4) < nums[2] (5)` $\rightarrow$ `curr_valley = 1`, `total_candy = 10 + 1 = 11`, `i = 4`
- `nums[4] (3) < nums[3] (4)` $\rightarrow$ `curr_valley = 2`, `total_candy = 11 + 2 = 13`, `i = 5`
- `nums[5] (2) < nums[4] (3)` $\rightarrow$ `curr_valley = 3`, `total_candy = 13 + 3 = 16`, `i = 6`
- `nums[6] (1) < nums[5] (2)` $\rightarrow$ `curr_valley = 4`, `total_candy = 16 + 4 = 20`, `i = 7`
- Loop ends because $i == n$.
- Descending slope summary: `curr_valley = 4`.

#### Step 3: Peak Correction
- Peak index $2$ (rating $5$) was given extra candies from both the ascent of length $2$ and descent of length $4$.
- Adjustment:
  $$\text{total\_candy} -= \min(\text{curr\_peak}, \text{curr\_valley}) \implies 20 - \min(2, 4) = 20 - 2 = 18$$

#### Final Output:
- Returns `18` (corresponds to distribution `[1, 2, 5, 4, 3, 2, 1]`).

---

## 5. Comparison of Both Approaches

| Metric | Approach 1: Two-Pass Vectors | Approach 2: One-Pass Slope (Peak-Valley) |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ |
| **Space Complexity** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ |
| **Core Concept** | Independent left/right prefix & suffix passes | Arithmetic slope accumulation with peak correction |
| **Memory Allocation** | Two `std::vector<int>` | Integer counters only |

---

## 6. Edge Cases Handled

1. **Strictly Increasing Sequence (`[1, 2, 3, 4]`):**
   - Handled inside the peak loop; returns immediately when $i == n$.
2. **Strictly Decreasing Sequence (`[4, 3, 2, 1]`):**
   - Peak loop does not execute (`curr_peak = 0`), valley loop runs (`curr_valley = 3`).
   - $\min(0, 3) = 0$, so no peak subtraction occurs; correct result is achieved.
3. **Identical Elements (`[1, 1, 1]`):**
   - Hits `nums[i] == nums[i-1]`, skipping with `i++` and `continue`.
   - Returns base `n = 3` candies.
4. **Single Element ($n = 1$):**
   - Condition `i < n` ($1 < 1$) is false; returns `total_candy = 1`.