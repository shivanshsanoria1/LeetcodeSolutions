class Solution {
private:
    typedef long long int lli;

    lli stringToLLI(string s){
        lli num = 0;
        for(char ch: s)
        {
            num *= 10;
            num += ch - '0';
        }

        return num;
    }

    bool isPrime(lli num){
        if(num <= 1)
            return false;

        if(num == 2)
            return true;
        
        if(num % 2 == 0)
            return false;

        for(lli i=3; i*i<=num; i+=2)
            if(num % i == 0)
                return false;
        
        return true;
    }

public:
    // T.C.=O(n^2 * sqrt(m)), S.C.=O(1)
    // m: max num made from substring in s
    long long sumOfLargestPrimes(string s) {
        int n = s.length();
        set<lli> st;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
            {
                lli num = stringToLLI(s.substr(i, j-i+1));

                if(isPrime(num))
                    st.insert(num);

                if(st.size() == 4)
                    st.erase(st.begin());
            }

        lli sum = 0;
        for(lli num: st)
            sum += num;

        return sum;
    }
};