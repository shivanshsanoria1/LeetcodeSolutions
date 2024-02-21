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
    ListNode* doubleIt(ListNode* head) { // S.C.=O(n)
        // push all digits of LL into a vector
        ListNode *curr = head;
        vector<int> vec;
        while(curr != NULL)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        // multiply the num represented in the vector by 2
        int carry = 0;
        for(int i=vec.size()-1; i>=0; i--)
        {
            int newVal = vec[i] * 2 % 10 + carry;
            carry = vec[i] * 2 / 10;
            vec[i] = newVal;
        }
        // copy the digits from vector to LL
        curr = head;
        for(int i=0; i<vec.size(); i++)
        {
            curr->val = vec[i];
            curr = curr->next;
        }
        // if final carry is generated, add a new node at the start of the LL
        if(carry == 1)
        {
            ListNode *newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};