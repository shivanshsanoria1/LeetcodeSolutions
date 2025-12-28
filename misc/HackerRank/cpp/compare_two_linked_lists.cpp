// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *curr1=head1, *curr2=head2;
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data != curr2->data)
            return false;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    if(curr1!=NULL)
        return false;
    if(curr2!=NULL)
        return false;
    return true;
}