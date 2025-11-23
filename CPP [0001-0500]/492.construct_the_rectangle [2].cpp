class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2);
        int l, w;
        for(w=sqrt(area); w>=1; w--)
        {
            if(area%w==0)
            {
                l=area/w;
                break;
            }
        }
        ans[0]=l;
        ans[1]=w;
        return ans;
    }
};