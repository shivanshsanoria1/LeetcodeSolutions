/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // S.C.=O(n1 + n2)
        stack<int> st1, st2;
        ListNode *curr = l1;
        while(curr != NULL) // push node values from LL1 into stack1
        {
            st1.push(curr->val);
            curr = curr->next;
        }
        curr = l2;
        while(curr != NULL) // push node values from LL2 into stack2
        {
            st2.push(curr->val);
            curr = curr->next;
        }
        int carry = 0;
        ListNode *head = NULL;
        // run until both stacks becomes empty
        while(!st1.empty() || !st2.empty())
        {
            int val1 = 0, val2 = 0;
            if(!st1.empty())
            {
                val1 = st1.top();
                st1.pop();
            }
            if(!st2.empty())
            {
                val2 = st2.top();
                st2.pop();
            }
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *newNode = new ListNode(sum); // create new node
            newNode->next = head; // connect new node with head 
            head = newNode; // move head in reverse
        }
        if(carry == 1) //carry generated from MSB
        {
            ListNode *newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};