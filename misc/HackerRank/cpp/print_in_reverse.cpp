/*
 * Complete the 'reversePrint' function below.
 *
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void reversePrint(SinglyLinkedListNode* llist) {
    vector<int> vec;
    SinglyLinkedListNode* curr=llist;
    while(curr!=NULL)
    {
        vec.push_back(curr->data);
        curr=curr->next;
    }
    for(int i=vec.size()-1; i>=0; i--)
        cout << vec[i] << endl;
}