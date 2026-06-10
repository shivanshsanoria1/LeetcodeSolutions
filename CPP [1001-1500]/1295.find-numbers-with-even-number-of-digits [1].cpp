class Solution {
private:
    int numOfDigits(int num){
        int digs = 0;
        while(num > 0)
        {
            digs++;
            num /= 10;
        }

        return digs;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num: nums)
            if(numOfDigits(num) % 2 == 0)
                count++;

        return count;
    }
};