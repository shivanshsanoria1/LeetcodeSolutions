class Solution {
private:
    bool isPermutation(const int num, const int sum){
        string s1 = to_string(num);
        string s2 = to_string(sum);

        const int n1 = s1.length();
        const int n2 = s2.length();

        // 'sum' cannot be larger than 'num'
        if(n1 < n2)
            return false;
        // add leading zeros in 'sum' to make 
        // 'num' and 'sum' strings of equal length
        if(n1 > n2)
            s2.insert(0, n1 - n2, '0');
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }

public:
    // T.C.=O(m*log(m)), S.C.=O(m)
    // m: num of digits in n
    bool isDigitorialPermutation(int n) {
        // fact[i] = i!
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

        int num = n;
        int sum = 0;
        while(n > 0){
            sum += fact[n % 10];
            n /= 10;
        }

        return isPermutation(sum, num);
    }
};