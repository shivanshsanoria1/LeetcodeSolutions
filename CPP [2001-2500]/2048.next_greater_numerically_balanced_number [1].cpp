class Solution {
private:
    // returns true if for the number 'num' 
    // each of its digit 'd' has a freq of 'd'
    bool isBalanced(int num){
        vector<int> freq(10, 0);

        while(num > 0)
        {
            if(num % 10 == 0)
                return false;

            freq[num % 10]++;
            num /= 10;
        }

        for(int i=1; i<=9; i++)
            if(freq[i] > 0 && freq[i] != i)
                return false;
        
        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        n++;
        while(!isBalanced(n))
            n++;
        
        return n;
    }
};
// a numerically balanced number cannot have the digit 0
// since by its definition the digit 0 must be present 0 times