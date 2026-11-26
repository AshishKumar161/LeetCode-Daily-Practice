# LeetCode 3360: Stone Removal Game - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* Alice and Bob alternate turns removing a fixed, strictly decreasing number of stones from a pile of size $n$:
  * Turn 1 (**Alice**): removes $10$ stones
  * Turn 2 (**Bob**): removes $9$ stones
  * Turn 3 (**Alice**): removes $8$ stones
  * Turn 4 (**Bob**): removes $7$ stones
  * ...and so on, decreasing by $1$ each turn.
* Because neither player has any choice in how many stones to remove, the game is completely deterministic and can be solved by direct **simulation**.
* **Key Parity Insight (Tracking Whose Turn It Is):**
  * Instead of maintaining a separate boolean flag (like `isAliceTurn`), notice the exact parity of `remove`:
    * Whenever `remove` is **even** ($10, 8, 6, 4, 2$), it is always **Alice's turn**. If $n < \text{remove}$, Alice cannot make her move and loses $\rightarrow$ return `false`.
    * Whenever `remove` is **odd** ($9, 7, 5, 3, 1$), it is always **Bob's turn**. If $n < \text{remove}$, Bob cannot make his move and loses (meaning Alice wins) $\rightarrow$ return `true`.
* Note also that the total sum of all possible moves from $10$ down to $1$ is:
  $$10 + 9 + 8 + \dots + 1 = \frac{10 \times 11}{2} = 55$$
  Since the constraint guarantees $1 \le n \le 50$, the game is guaranteed to end before `remove` ever reaches $0$.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10 ;

        while (remove > 0)
        {
            if (remove % 2 == 0)
            {
                if(n >= remove)
                {
                    n = n - remove ;
                    remove-- ;
                    continue ;
                }
                else
                {
                    return false ;
                }
            }

            if (remove % 2 == 1)
            {
                if (n >= remove)
                {
                    n = n - remove ;
                    remove-- ;
                    continue ;
                }
                else
                {
                    return true ;
                }
            }
        }

        return false ;
    }
};
```

### Detailed Logic Breakdown:
1. **Initialization:**
   * `int remove = 10;` represents the required number of stones to be removed on the current turn (starting with Alice's first move).
2. **Alice's Turn (`if (remove % 2 == 0)`):**
   * Checks if enough stones remain (`n >= remove`).
   * If yes: subtracts `remove` from `n`, decrements `remove--`, and executes `continue;` to jump to the next loop iteration cleanly (preventing execution from immediately falling into the `remove % 2 == 1` block in the same iteration after `remove` becomes odd).
   * If no: Alice cannot make her required move, so she loses $\rightarrow$ immediately returns `false`.
3. **Bob's Turn (`if (remove % 2 == 1)`):**
   * Checks if enough stones remain (`n >= remove`).
   * If yes: subtracts `remove` from `n`, decrements `remove--`, and executes `continue;`.
   * If no: Bob cannot make his required move, so Bob loses and Alice wins $\rightarrow$ immediately returns `true`.
4. **Fallback Return (`return false;`):**
   * Reached only if `remove` drops to $0$ (if $n \ge 55$). Since $n \le 50$, the function always exits earlier inside the loop.

---

## 3. Comprehensive Dry Run

### Test Case 1: `n = 12`

| Turn | `remove` | Parity (`remove % 2`) | Player | Check `n >= remove` | Action / Updated `n` | Result |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | $10$ | $0$ (Even) | Alice | $12 \ge 10$ (**True**) | `n = 12 - 10 = 2`, `remove = 9`, `continue` | Game continues |
| **2** | $9$ | $1$ (Odd) | Bob | $2 \ge 9$ (**False**) | Enters `else` | **Return `true`** (Alice wins) |

* **Final Output:** `true`.

---

### Test Case 2: Multi-Turn Game (`n = 27`)

| Turn | `remove` | Parity (`remove % 2`) | Player | Check `n >= remove` | Action / Updated `n` | Result |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | $10$ | $0$ (Even) | Alice | $27 \ge 10$ (**True**) | `n = 27 - 10 = 17`, `remove = 9`, `continue` | Game continues |
| **2** | $9$ | $1$ (Odd) | Bob | $17 \ge 9$ (**True**) | `n = 17 - 9 = 8`, `remove = 8`, `continue` | Game continues |
| **3** | $8$ | $0$ (Even) | Alice | $8 \ge 8$ (**True**) | `n = 8 - 8 = 0`, `remove = 7`, `continue` | Game continues |
| **4** | $7$ | $1$ (Odd) | Bob | $0 \ge 7$ (**False**) | Enters `else` | **Return `true`** (Alice wins) |

* **Final Output:** `true`.

---

### Test Case 3: `n = 1`

| Turn | `remove` | Parity (`remove % 2`) | Player | Check `n >= remove` | Action | Result |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | $10$ | $0$ (Even) | Alice | $1 \ge 10$ (**False**) | Enters `else` | **Return `false`** (Alice loses) |

* **Final Output:** `false`.

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(1)$
  * Because `remove` starts at the constant value $10$ and strictly decreases by $1$ on every iteration, the `while` loop executes at most $10$ times regardless of the input value $n$.
* **Space Complexity:** $\mathcal{O}(1)$
  * Only a single integer variable (`remove`) is used alongside the input parameter `n`.

---

## 5. Edge Cases Handled

1. **Insufficient Stones on Turn 1 ($1 \le n \le 9$):**
   * On the very first iteration (`remove = 10`), `n >= 10` is false, immediately returning `false`.
2. **Exact Stones for a Player's Move (`n = 10` or `n = 19`):**
   * For `n = 10`: Alice removes $10$ leaving $n = 0$; Bob needs $9$ stones ($0 < 9$), returning `true`.
   * For `n = 19`: Alice removes $10$ ($n = 9$), Bob removes $9$ ($n = 0$); Alice needs $8$ stones ($0 < 8$), returning `false`.
3. **Maximum Constraint (`n = 50`):**
   * Moves proceed $10 \rightarrow 9 \rightarrow 8 \rightarrow 7 \rightarrow 6 \rightarrow 5$ (sum $= 45$, leaving $n = 5$ for Alice's turn requiring $4$ stones). Alice removes $4$ (leaving $n = 1$), and Bob cannot remove $3$ stones, returning `true`.