class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> alpha_upper(26,false), alpha_lower(26,false);
        for(int i=0; i<jewels.size(); i++)
        {
            if(jewels[i]>='A' && jewels[i]<='Z')
                alpha_upper[jewels[i]-'A']=true;
            else
                alpha_lower[jewels[i]-'a']=true;
        }
        int c=0;
        for(int i=0; i<stones.size(); i++)
        {
            if(stones[i]>='A' && stones[i]<='Z')
            {
                if(alpha_upper[stones[i]-'A']==true)
                    c++;
            } 
            else
            {
                if(alpha_lower[stones[i]-'a']==true)
                    c++;
            }
        }
        return c;
    }
};