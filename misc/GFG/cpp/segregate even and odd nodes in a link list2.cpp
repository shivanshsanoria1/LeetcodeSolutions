class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *dummy = new Node(-1); //dummy node
        dummy->next=head;
        
        Node *prev=dummy;
        Node *curr=head;
        Node *end=head;
        while(end->next!=NULL)
            end=end->next;
        Node *new_end=end;
        while(curr!=end)
        {
            if(curr->data % 2 != 0) //odd
            {
                prev->next=curr->next;
                new_end->next=curr;
                new_end=curr;
                new_end->next=NULL;
                curr=prev->next;
            }
            else //even
            {
                prev=curr;
                curr=curr->next;
            }
        }
        if(new_end!=end && end->data % 2 != 0) //last node in original LL is odd
        {
            prev->next=end->next;
            end->next=NULL;
            new_end->next=end;
        }
        return dummy->next;
    }
};