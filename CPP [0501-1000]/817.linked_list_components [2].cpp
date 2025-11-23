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

class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n){
        parent.resize(n);
        // initially every node is a parent of itself
        for(int i=0; i<n; i++)
            parent[i] = i;
        
        size.resize(n, 1);
    }

    int findUltimateParent(int curr){
        if(parent[curr] == curr)
            return curr;
        
        parent[curr] = findUltimateParent(parent[curr]);

        return parent[curr];
    }

    bool unionBySize(int a, int b){
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

        // nodes 'a' and 'b' are already in the same component
        if(ultPar_a == ultPar_b)
            return false;
        
        if(size[ultPar_a] <= size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }

        return true;
    }

    // num of components is the same as 
    // num of distinct ultimate-parents
    // ultimate-parent must also be present in isPresent[]
    int componentCount(vector<bool>& isPresent){
        int n=parent.size();
        unordered_set<int> ultParents;

        for(int i=0; i<n; i++)
        {
            int ultPar = findUltimateParent(i);
            if(isPresent[ultPar])
                ultParents.insert(ultPar);
        }
        
        return ultParents.size();
    }
};

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

public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = findLengthOfLL(head);

        vector<bool> isPresent(n, false);
        for(int num: nums)
            isPresent[num] = true;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        DisjointSet ds(n);
        
        while(curr != nullptr)
        {
            if(prev != nullptr && isPresent[prev->val] && isPresent[curr->val])
                ds.unionBySize(prev->val, curr->val);

            prev = curr;
            curr = curr->next;
        }

        return ds.componentCount(isPresent);
    }
};