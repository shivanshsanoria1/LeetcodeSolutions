class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;

        for(int i=0; i<=20; i++)
        {
            int num1 = pow(x, i);

            if(num1 >= bound)
                break;

            for(int j=0; j<=20; j++)
            {
                int num2 = pow(y, j);

                if(num1 + num2 > bound)
                    break;
                    
                s.insert(num1 + num2);
            }
        }

        vector<int> ans;
        for(int num: s)
            ans.push_back(num);
        return ans;
    }
};
// 2^20 > 10^6