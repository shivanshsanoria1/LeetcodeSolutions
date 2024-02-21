class Solution {
public:
    int heightChecker(vector<int>& heights) { //T.C.=O(nlogn) , S.C.=O(n)
        vector<int> vec=heights;
        sort(vec.begin(),vec.end());
        int c=0;
        for(int i=0; i<heights.size(); i++)
            if(heights[i] != vec[i])
                c++;
        return c;
    }
};