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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* toBST(vector<int>& nums, int left, int right)
    {
        if(left <= right)
        {
            int mid = left+(right-left)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = toBST(nums,left,mid-1);
            root->right = toBST(nums,mid+1,right);
            return root;
        }
        return NULL; //leaf node is reached
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        return toBST(vec,0,vec.size()-1);
    }
};