class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size(), max_num=INT_MIN;
        vector<bool> ans(n);
        for(int i=0; i<n; i++) //find max candies
            max_num=max(max_num,candies[i]);
        for(int i=0; i<n; i++)
        {
            if(candies[i]+extraCandies >= max_num)
                ans[i]=true;
            else
                ans[i]=false;
        }
        return ans;
    }
};