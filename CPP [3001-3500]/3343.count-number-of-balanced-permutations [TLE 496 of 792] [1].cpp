class Solution {
private:
    #define MOD int(1e9 + 7)

    bool isBalanced(string& num){
        int sumEven = 0, sumOdd = 0;
        for(int i=0; i<num.length(); i++)
        {
            if(i % 2 == 0)
                sumEven += num[i] - '0';
            else
                sumOdd += num[i] - '0';
        }

        return sumEven == sumOdd;
    }

    int solve(string& num, int n, vector<int>& freq){
        if(num.length() == n && isBalanced(num))
            return 1;

        int res = 0;
        for(int i=0; i<=9; i++)
        {
            if(freq[i] == 0)
                continue;

            freq[i]--;
            num += to_string(i);

            res = (res + solve(num, n, freq)) % MOD;

            num.pop_back();
            freq[i]++;
        }

        return res;
    }

public:
    // T.C.=O(n!), S.C.=O(n)
    int countBalancedPermutations(string num) {
        int digitSum = 0;
        for(char dig: num)
            digitSum += dig - '0';
        
        // sum of digits must be even
        if(digitSum % 2 == 1)
            return 0;
        
        vector<int> freq(10, 0);
        for(char dig: num)
            freq[dig - '0']++;
        
        string str = "";
        return solve(str, num.length(), freq);
    }
};