class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> vec(51,false);
        for(int i=0; i<ranges.size(); i++)
        {
            int start=ranges[i][0], end=ranges[i][1];
            for(int j=start; j<=end; j++) //mark the num in range [start,end] as visited
                 vec[j]=true;
        }
        for(int i=left; i<=right; i++)
            if(vec[i] == false) //check if any num in range [left,right] is unvisited
                return false;
        return true;
    }
};