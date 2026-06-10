class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(totalSum % 3 != 0)
            return false;
        int sum = 0;
        int count = 0;
        for(int num: arr)
        {
            sum += num;
            if(sum == totalSum / 3)
            {
                sum = 0;
                count++;
            }
        }
        return count >= 3 ? true : false;
    }
};