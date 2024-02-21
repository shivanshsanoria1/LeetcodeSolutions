class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2);
        int min_diff=INT_MAX;
        int l=sqrt(area), w=sqrt(area);
        while(w>=1 && l<=area)
        {
            if(l*w < area)
                l++;
            else if(l*w > area)
                w--;
            else //l==w
            {
                min_diff=min(min_diff,l-w);
                if(min_diff==l-w) //the first time min_diff will be updated, l and w will have the smallest diff
                {                 //since in each iteration diff between l and w increases
                    ans[0]=l;
                    ans[1]=w;
                    break;
                }
                l++;
                w--;
            }
        }
        return ans;
    }
};