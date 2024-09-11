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
    // T.C.=O(m*n), S.C.=O(1)
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // m*n grid filled with -1's
        vector<vector<int>> grid(m, vector<int>(n, -1));
        // right, down, left, up
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // directional-index
        int i = 0; 
        // curr coordinates
        int currX = 0, currY = 0;

        ListNode* curr = head;
        while(curr != nullptr)
        {
            // fill the curr corrdinates with curr val of LL
            grid[currX][currY] = curr->val;
            curr = curr->next;
            
            // next possible coordinates
            int x = currX + dirs[i].first;
            int y = currY + dirs[i].second;
            
            // change the direction if the next coordinates 
            // reach out of bounds or is already filled
            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != -1)
                i = (i + 1) % 4;

            // update the curr coordinates
            currX += dirs[i].first;
            currY += dirs[i].second;
        }

        return grid;
    }
};