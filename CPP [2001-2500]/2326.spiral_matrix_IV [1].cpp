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
        // directional index
        int i = 0; 
        // curr coordinates
        int currX = 0, currY = 0;

        ListNode* curr = head;
        while(curr != nullptr)
        {
            // fill the cell with curr coordinates
            grid[currX][currY] = curr->val;
            // move the curr pointer forward
            curr = curr->next;
            
            // next possible coordinates
            int nextX = currX + dirs[i].first;
            int nextY = currY + dirs[i].second;
            
            // change the direction if the next coordinates reach out of bounds
            // or is already filled
            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || grid[nextX][nextY] != -1)
                i = (i + 1) % 4;

            // update the curr coordinates
            currX += dirs[i].first;
            currY += dirs[i].second;
        }

        return grid;
    }
};