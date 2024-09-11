#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val = -1;
    ListNode* next = nullptr;

    ListNode(){
        this->val = -1;
        this->next = nullptr;
    }

    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
    
    ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};

class LinkedList{
public:
    vector<int> nums;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int len = 0;
    
    LinkedList(){
        this->nums.clear();

        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
    }
    
    LinkedList(vector<int>& nums){
        this->nums = nums;
        
        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
    }
    
    ListNode* buildLL(){
        for(int num: nums)
        {
            ListNode* newNode = new ListNode(num);
            len++;
            
            if(tail == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        
        return head;
    }
    
    // connect the node at last index to the node at index 'idx'
    void addCycleToIndex(int idx){
        if(idx < 0 || idx >= len)
        {
            cout<<"Invalid Index"<<endl;
            return;
        }
        
        ListNode* curr = head;
        while(idx--)
            curr = curr->next;
        
        tail->next = curr;
    }
    
    void printLL(){
        ListNode* curr = head;
        for(int i=0; i<len; i++)
        {
            cout<<curr->val<<" ";
            curr = curr->next;
        }
        
        // start of cycle (if present)
        if(curr != nullptr)
            cout<<"-> "<<curr->val<<" ";
            
        cout<<endl;
    }
};

// --------------- START --------------- //

bool hasCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            return true;
    }
    
    return false;
}

// --------------- END --------------- //

int main() {
    vector<int> nums = { 1, 2, 3, 4, 5 };
    LinkedList ll(nums);
    
    ListNode* head = ll.buildLL();
    
    // connect the node at last index to the node at index 2
    ll.addCycleToIndex(2);
    
    ll.printLL();
    
    if(hasCycle(head))
        cout<<"Cycle Found"<<endl;
    else
        cout<<"Cycle Not Found"<<endl;

    return 0;
}