
# Explanation - Add Two Numbers

# Approach

In this approach, we first convert both linked lists into strings.

Then we reverse the strings because linked lists store digits in reverse order.

After reversing:

```text
l1 = [2,4,3]
becomes
"342"

l2 = [5,6,4]
becomes
"465"
```

Now both strings represent the actual numbers.

---

# Step 1: Store Digits into Strings

Traverse both linked lists:

```cpp
while(l1 != NULL)
{
    a = a + to_string(l1 -> val) ;
    l1 = l1 -> next ;
}
```

Same for second linked list:

```cpp
while(l2 != NULL)
{
    b = b + to_string(l2 -> val) ;
    l2 = l2 -> next ;
}
```

---

# Step 2: Reverse Strings

```cpp
reverse(a.begin() , a.end()) ;
reverse(b.begin() , b.end()) ;
```

Example:

```text
a = "243" -> "342"
b = "564" -> "465"
```

---

# Step 3: Add Digits

We add digits from back using carry.

```cpp
while(i >= 0 || j >= 0 || carry)
```

At every step:

```cpp
sum = digit1 + digit2 + carry
```

Store digit:

```cpp
ans = ans + to_string(sum % 10)
```

Update carry:

```cpp
carry = sum / 10
```

---

# Step 4: Convert String into Linked List

Now answer string contains digits in reverse order.

Example:

```text
ans = "708"
```

Create linked list:

```text
7 -> 0 -> 8
```

Code:

```cpp
for(int k = 0 ; k < ans.length() ; k++)
{
    temp -> next = new ListNode(ans[k] - '0') ;
    temp = temp -> next ;
}
```

---

# Dry Run

Input:

```text
l1 = [2,4,3]
l2 = [5,6,4]
```

Step 1:

```text
a = "243"
b = "564"
```

Step 2:

```text
reverse(a) = "342"
reverse(b) = "465"
```

Step 3:

```text
2 + 5 = 7
4 + 6 = 10
0 carry 1
3 + 4 + 1 = 8
```

Answer string:

```text
ans = "708"
```

Step 4:

Create linked list:

```text
7 -> 0 -> 8
```

Final Output:

```text
[7,0,8]
```

---

# Time Complexity

```text
O(n + m)
```

Where:

- `n` = size of first linked list
- `m` = size of second linked list

---

# Space Complexity

```text
O(n + m)
```

Extra strings are used.

---

# Important Note

This solution works correctly but is not the most optimized approach.

Optimized solution directly adds linked list nodes without converting into strings.

However, this approach is good for understanding carry handling and linked list construction.
