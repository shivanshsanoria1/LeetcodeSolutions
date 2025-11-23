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
    int findLengthOfLL(ListNode* head){
        ListNode* curr = head;
        int len = 0;

        while(curr != nullptr)
        {
            len++;
            curr = curr->next;
        }

        return len;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        
        visited[curr] = true;

        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = findLengthOfLL(head);

        vector<bool> isPresent(n, false);
        
        for(int num: nums)
            isPresent[num] = true;

        vector<vector<int>> graph(n);
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr)
        {
            if(prev != nullptr && isPresent[prev->val] && isPresent[curr->val])
            {
                graph[prev->val].push_back(curr->val);
                graph[curr->val].push_back(prev->val);
            }

            prev = curr;
            curr = curr->next;
        }

        vector<bool> visited(n, false);
        int comps = 0;

        for(int i=0; i<n; i++)
            if(isPresent[i] && !visited[i])
            {
                dfs(graph, visited, i);
                comps++;
            }

        return comps;
    }
};