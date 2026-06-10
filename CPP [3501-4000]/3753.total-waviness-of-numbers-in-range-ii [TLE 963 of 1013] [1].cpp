class Solution {
public:
    // T.C.=O((num2 - num1) * log10(num2)), S.C.=O(log10(num2))
    long long totalWaviness(long long num1, long long num2) {
        long long int totalCount = 0;
        for(long long int num = num1; num <= num2; num++){
            string str = to_string(num);

            int count = 0;
            for(int i=1; i<str.length()-1; i++){
                // peak
                if(str[i-1] < str[i] && str[i] > str[i+1])
                    count++;
                // valley
                else if(str[i-1] > str[i] && str[i] < str[i+1])
                    count++;
            }

            totalCount += count;
        }

        return totalCount;
    }
};