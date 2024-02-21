class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int up=0, down=m-1, left=0, right=n-1;
        int dir=0; // 0-right, 1-down, 2-left, 3-up
        vector<int> ans;
        while(left<=right && up<=down)
        {
            if(dir==0)
            {
                for(int j=left; j<=right; j++) // left to right
                    ans.push_back(matrix[up][j]);
                up++;
            }
            
            else if(dir==1)
            {
                for(int i=up; i<=down; i++) // up to down
                    ans.push_back(matrix[i][right]);
                right--;
            }
            
            else if(dir==2)
            {
                for(int j=right; j>=left; j--) // right to left
                    ans.push_back(matrix[down][j]);
                down--;
            }
            
            else if(dir==3)
            {
                for(int i=down; i>=up; i--) // down to up
                    ans.push_back(matrix[i][left]);
                left++;
            }
            
            dir = (dir+1)%4;
        }
        return ans;
    }
};