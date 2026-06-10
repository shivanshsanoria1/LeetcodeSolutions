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
    // T.C.=O(n), S.C.=O(n)
    ListNode* doubleIt(ListNode* head) { 
        // push all digits of LL into a vector
        vector<int> digs;
        ListNode* curr = head;
        while(curr != nullptr)
        {
            digs.push_back(curr->val);
            curr = curr->next;
        }

        // multiply the num represented in the vector by 2
        int carry = 0;
        for(int i=digs.size()-1; i>=0; i--)
        {
            int newVal = digs[i] * 2 % 10 + carry;
            carry = digs[i] * 2 / 10;
            digs[i] = newVal;
        }

        // copy the digits from vector to LL
        curr = head;
        for(int dig: digs)
        {
            curr->val = dig;
            curr = curr->next;
        }

        // if final carry is generated, add a new node at the start of the LL
        if(carry == 1)
        {
            ListNode* newNode = new ListNode(1, head);
            head = newNode;
        }
        
        return head;
    }
};