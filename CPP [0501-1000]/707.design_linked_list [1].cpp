class LLNode{
public:
    int val;
    LLNode* next;

    LLNode(){
        this->val = -1;
        this->next = nullptr;
    }

    LLNode(int val){
        this->val = val;
        this->next = nullptr;
    }

    LLNode(int val, LLNode* next){
        this->val = val;
        this->next = next;
    }
};

class MyLinkedList {
private:
    int len;
    LLNode* head;
    LLNode* dummy;

    // only used for debugging
    void printLL(){
        LLNode* curr = dummy;

        while(curr != nullptr)
        {
            cout<<curr->val<<" ";
            curr = curr->next;
        }

        cout<<endl;
    }

public:
    MyLinkedList() {
        this->len = 0;
        this->head = nullptr;
        this->dummy = new LLNode(-1, this->head);
    }

    // T.C.=O(n)
    int get(int index) {
        if(index >= len)
            return -1;
        
        LLNode* curr = head;
        while(index--)
            curr = curr->next;
        
        //printLL();

        return curr->val;
    }
    
    // T.C.=O(1)
    void addAtHead(int val) {
        LLNode* newNode = new LLNode(val, head);
        dummy->next = newNode;

        head = dummy->next;
        len++;

        //printLL();
    }
    
    // T.C.=O(n)
    void addAtTail(int val) {
        LLNode* curr = dummy;
        while(curr->next != nullptr)
            curr = curr->next;

        LLNode* newNode = new LLNode(val);
        curr->next = newNode;

        head = dummy->next;
        len++;

        //printLL();
    }
    
    // T.C.=O(n)
    void addAtIndex(int index, int val) {
        if(index > len)
            return;

        LLNode* curr = dummy;
        while(index--)
            curr = curr->next;
        
        LLNode* newNode = new LLNode(val, curr->next);
        curr->next = newNode;

        head = dummy->next;
        len++;

        //printLL();
    }
    
    // T.C.=O(n)
    void deleteAtIndex(int index) {
        if(index >= len)
            return;

        LLNode* curr = dummy;
        while(index--)
            curr = curr->next;
        
        LLNode* del = curr->next;
        curr->next = curr->next->next;
        
        delete del;

        head = dummy->next;
        len--;
        
        //printLL();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */