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
private:
    int N = 0;
    ListNode* head = nullptr;

public:
    Solution(ListNode* head) {
        // save the head of LL
        this->head = head;

        // find the length of LL
        ListNode* curr = head;
        while(curr != nullptr)
        {
            this->N++;
            curr = curr->next;
        }

        // use the current time as seed for random generator 
        srand(time(0));
    }
    
    // T.C.=O(n), S.C.=O(1)
    int getRandom() {
        // get a random value in range [0, N-1] (both inclusive)
        int idx = rand() % N;

        // move curr 'idx' places forward
        ListNode* curr = this->head;
        while(idx--)
            curr = curr->next;
            
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */