class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { //T.C.=O(n) , S.C.=O(n) , using 1 stack
        int n=heights.size(), max_area=0;
        stack<int> st; //maintain the stack in increasing order, stack contains index (not elements)
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()]) //remove all the bars with height > curr bar height from stack
            {
                int popped= st.top();
                st.pop();
                int curr_area;
                if(st.empty())
                    curr_area= heights[popped] * i;
                else
                    curr_area= heights[popped] * (i-st.top()-1);
                max_area= max(max_area,curr_area);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int popped= st.top();
            st.pop();
            int curr_area;
            if(st.empty())
                curr_area= heights[popped] * n;
            else
                curr_area= heights[popped] * (n-st.top()-1);
            max_area= max(max_area,curr_area);
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) { //T.C.=O(m*n) , S.C.=O(n)
        int m=matrix.size(), n=matrix[0].size();
        vector<int> heights(n,0); //to store histogram for each row
        int max_area=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]=='1') //increment the histogram height
                    heights[j]++;
                else //reset the histogram height
                    heights[j]=0;
            }
            int curr_max_area= largestRectangleArea(heights);
            max_area= max(max_area,curr_max_area);
        }
        return max_area;
    }
};