# 1021. Remove Outermost Parentheses — Explanation

**LeetCode:** [1021. Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/)

## Problem Idea
Every primitive parentheses string has one outermost opening parenthesis and one matching outermost closing parenthesis. Skip those two characters and keep the inner parentheses.

## Approach 1 — Stack (your commented approach)

```cpp
string removeOuterParentheses(string s) {
    stack<char> st;
    string ans;

    for (char c : s) {
        if (c == '(') {
            if (!st.empty()) ans.push_back(c);
            st.push(c);
        } else {
            st.pop();
            if (!st.empty()) ans.push_back(c);
        }
    }
    return ans;
}
```

### Logic
- For `'('`, check the stack before pushing. If it is already non-empty, this opening parenthesis is inside the primitive, so append it. Then push it.
- For `')'`, pop first. If the stack remains non-empty, this closing parenthesis is inside the primitive, so append it.
- If the stack is empty before an opening or after a closing parenthesis, that character is outermost and is skipped.

### Dry run: `s = "(()())"`
| Character | Stack action | Append? | `ans` |
|---|---|---|---|
| `(` | Push | No | `""` |
| `(` | Push | Yes | `(` |
| `)` | Pop; stack remains non-empty | Yes | `()` |
| `(` | Push | Yes | `()(` |
| `)` | Pop; stack remains non-empty | Yes | `()()` |
| `)` | Pop; stack becomes empty | No | `()()` |

**Complexity:** Time `O(n)`. Auxiliary space `O(n)` for the stack, excluding output.

## Approach 2 — Counter (your active code)

```cpp
string removeOuterParentheses(string s) {
    int count = 0;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') count--;

        if (count > 0) ans.push_back(s[i]);

        if (s[i] == '(') count++;
    }
    return ans;
}
```

### What `count` means
`count` tracks the current nesting depth. The order matters:
1. For `')'`, decrement first. An outermost closing parenthesis makes `count == 0`, so it is skipped.
2. Append only when `count > 0`.
3. For `'('`, increment afterward. The outermost opening parenthesis is checked while `count == 0`, so it is skipped; inner opening parentheses are kept.

### Dry run: `s = "(()())(())"`
| Index | Character | Count when checked for append | Append? | `ans` |
|---:|:---:|---:|---|---|
| 0 | `(` | 0 | No | `""` |
| 1 | `(` | 1 | Yes | `(` |
| 2 | `)` | 1 | Yes | `()` |
| 3 | `(` | 1 | Yes | `()(` |
| 4 | `)` | 1 | Yes | `()()` |
| 5 | `)` | 0 | No | `()()` |
| 6 | `(` | 0 | No | `()()` |
| 7 | `(` | 1 | Yes | `()()(` |
| 8 | `)` | 1 | Yes | `()()()` |
| 9 | `)` | 0 | No | `()()()` |

Output: `()()()`.

**Complexity:** Time `O(n)`. Auxiliary space `O(1)` beyond the output string.

## Comparison
| Feature | Stack | Counter |
|---|---|---|
| Tracks nesting with | Stack | Integer |
| Time | `O(n)` | `O(n)` |
| Auxiliary space excluding output | `O(n)` | `O(1)` |
| Main advantage | Nesting is explicit | Less memory and simpler |

## Common mistakes
- Do not append the outermost `'('`.
- In the counter approach, decrement before checking `')'`.
- In the counter approach, increment after checking `'('`.
- The string is valid, so the nesting depth returns to zero at every primitive boundary.

## Key takeaway
Both approaches remove the outer pair from every primitive. The stack checks whether it is empty; the counter checks nesting depth. Both run in `O(n)` time, but the counter uses `O(1)` auxiliary space.
