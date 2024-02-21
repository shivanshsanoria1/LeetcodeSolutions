class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int mul=0;
        while(candies>0)
        {
            for(int i=0; i<num_people; i++)
            {
                int required=(mul*num_people)+(i+1);
                if(candies >= required)
                {
                    ans[i]+=required;
                    candies-=required;
                }
                else
                {
                    ans[i]+=candies;
                    candies=0;
                    break;
                }
            }
            mul++;
        }
        return ans;
    }
};