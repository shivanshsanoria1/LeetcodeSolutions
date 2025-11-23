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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { //without taking extra LL, recursive
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val <= l2->val)
        {
            l1->next= mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next= mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    
    ListNode *mergeSort(vector<ListNode*>& lists, int start, int end){
        if(start > end)
            return NULL;
        if(start == end)
            return lists[start];
        int mid= (start+end)/2;
        ListNode *a= mergeSort(lists,start,mid);
        ListNode *b= mergeSort(lists,mid+1,end);
        return mergeTwoLists(a,b);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) { //T.C.=O(n*logk) , S.C.=O(1) , where n is the max length of LL
        return mergeSort(lists,0,lists.size()-1);
    }
};
// using the code from Leetvode-21 (merge_two_sorted_lists)
// approach very similar to merge sort