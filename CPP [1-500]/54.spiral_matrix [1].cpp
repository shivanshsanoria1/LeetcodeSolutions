class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int up = 0, down = m-1, left = 0, right = n-1;
        // dir = 0: right, 1: down, 2: left, 3: up
        int dir = 0; 

        vector<int> ans;
        while(left <= right && up <= down)
        {
            if(dir == 0) // right
            {
                // move from left to right cols
                for(int j=left; j<=right; j++)
                    ans.push_back(matrix[up][j]);
                // 'up' row is completed
                up++;
            }
            else if(dir == 1) // down
            {
                // move from up to down rows
                for(int i=up; i<=down; i++) 
                    ans.push_back(matrix[i][right]);
                // 'right' col is completed
                right--;
            }
            else if(dir == 2) // left
            {
                // move from right to left cols
                for(int j=right; j>=left; j--)
                    ans.push_back(matrix[down][j]);
                // 'down' row is completed
                down--;
            }
            else // dir == 3 // up
            {
                // move from down to up rows
                for(int i=down; i>=up; i--) 
                    ans.push_back(matrix[i][left]);
                // 'left' col is completed
                left++;
            }

            // change direction
            dir = (dir + 1) % 4;
        }
        
        return ans;
    }
};