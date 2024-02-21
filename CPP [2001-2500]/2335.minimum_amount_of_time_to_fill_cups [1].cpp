class Solution {
public:
    int fillCups(vector<int>& amount) {
        int t = 0; // time
        while(amount[0] > 0 || amount[1] > 0 || amount[2] > 0)
        {
            t++;
            sort(amount.begin(), amount.end());
            if(amount[2] > 0)
                amount[2]--;
            if(amount[1] > 0)
                amount[1]--;
        }
        return t;
    }
};