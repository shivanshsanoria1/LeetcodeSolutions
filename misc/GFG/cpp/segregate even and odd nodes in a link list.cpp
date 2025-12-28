class Solution{
public:
    Node* divide(int N, Node *head){ //S.C.=O(n)
        // code here
        vector<int> even, odd;
        Node* curr=head;
        while(curr!=NULL)
        {
            if(curr->data % 2 == 0)
                even.push_back(curr->data);
            else
                odd.push_back(curr->data);
            curr=curr->next;
        }
        curr=head;
        for(int i=0; i<even.size(); i++)
        {
            curr->data=even[i];
            curr=curr->next;
        }
        for(int i=0; i<odd.size(); i++)
        {
            curr->data=odd[i];
            curr=curr->next;
        }
        return head;
    }
};