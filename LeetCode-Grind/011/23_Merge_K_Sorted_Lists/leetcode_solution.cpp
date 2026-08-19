class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1 != NULL)
        {
            tail->next = list1;
        }
        if (list2 != NULL)
        {
            tail->next = list2;
        }

        return dummy->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
        {
            return NULL;
        }

        while (lists.size() > 1)
        {
            vector<ListNode *> mergedLists;
            for (int i = 0; i < lists.size(); i += 2)
            {
                ListNode *l1 = lists[i];
                ListNode *l2 = NULL;

                if (i + 1 < lists.size())
                {
                    l2 = lists[i + 1];
                }

                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};