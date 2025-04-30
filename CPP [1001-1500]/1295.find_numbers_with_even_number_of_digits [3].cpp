class Solution {
private:
    int isNumOfDigitsEven(int num){
        return (num >= 10 && num <= 99) || (num >= 1000 && num <= 9999) || num == 100000;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num: nums)
            if(isNumOfDigitsEven(num))
                count++;

        return count;
    }
};