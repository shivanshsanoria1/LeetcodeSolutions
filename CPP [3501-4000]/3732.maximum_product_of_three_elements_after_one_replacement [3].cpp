class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    long long maxProduct(vector<int>& nums) {
        // 2 largest absolute numbers, ie, without considering the signs
        int absMax1 = 0, absMax2 = 0;

        for(int num: nums){
            num = abs(num);
            
            if(num >= absMax1){
                absMax2 = absMax1;
                absMax1 = num;
            }else if(num > absMax2)
                absMax2 = num;
        }

        const long long int INF = pow(10, 5);
        return INF * absMax1 * absMax2;
    }
};