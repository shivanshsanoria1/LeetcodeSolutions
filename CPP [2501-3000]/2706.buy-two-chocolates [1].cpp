class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int buyChoco(vector<int>& prices, int money) { 
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int num: prices)
        {
            if(num < min1) // new min1 found
            {
                min2 = min1; // old min1 is now min2
                min1 = num; // update min1
            }
            else if(num <= min2) // new min2 found
                min2 = num; // update min2
        }
        int moneyLeft = money - min1 - min2;
        return moneyLeft >= 0 ? moneyLeft : money;
    }
};