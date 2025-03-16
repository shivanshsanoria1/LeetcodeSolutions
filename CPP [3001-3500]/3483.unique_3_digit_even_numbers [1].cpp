class Solution {
private:
    bool canMakeNumberFromDigits(int num, vector<int> freq){
        while(num > 0)
        {
            int digit = num % 10;
            
            if(freq[digit] == 0)
                return false;

            freq[digit]--;
            num /= 10;
        }

        return true;
    }

public:
    // T.C.=O(n + 1000), S.C.=O(10)
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int digit: digits)
            freq[digit]++;
        
        int count = 0;
        for(int num = 100; num < 999; num += 2)
            if(canMakeNumberFromDigits(num, freq))
                count++;

        return count;
    }
};