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
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int len = 0;
    
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
    }
    
    ListNode* buildLL(vector<int>& nums){
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

ListNode* findStartOfCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
        {
            ListNode* slow1 = head;
            while(slow1 != slow)
            {
                slow1 = slow1->next;
                slow = slow->next;
            }

            return slow1;
        }
    }
    
    return nullptr;
}

// --------------- END --------------- //

int main() {
    LinkedList ll;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    
    ListNode* head = ll.buildLL(nums);
    
    // connect the node at last index to the node at index 2
    ll.addCycleToIndex(2);
    
    ll.printLL();
    
    ListNode* cycleStartNode = findStartOfCycle(head);
    
    if(cycleStartNode != nullptr)
        cout<<"Cycle Found at node value = "<<cycleStartNode->val<<endl;
    else
        cout<<"Cycle Not Found"<<endl;

    return 0;
}