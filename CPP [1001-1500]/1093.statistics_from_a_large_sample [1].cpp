class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minNum = 256;
        double maxNum = -1;
        double sum = 0;
        int totalNums = 0;
        int maxFreq = 0;
        double mode = -1;

        for(int i=0; i<=255; i++)
        {
            if(count[i] == 0)
                continue;

            if(minNum == 256)
                minNum = i;
            
            maxNum = i;

            sum += (long long int)i * count[i];
            totalNums += count[i];

            if(count[i] > maxFreq)
            {
                maxFreq = count[i];
                mode = i;
            }
        }

        double median = -1;
        int totalNums2 = totalNums % 2 == 1 ? (totalNums + 1)/2 : totalNums/2;
        int idx = -1;
        for(int i=0; i<=255; i++)
        {
            if(count[i] == 0)
                continue;
            
            if(count[i] >= totalNums2)
            {
                count[i] -= totalNums2;
                median = i;
                idx = i;
                break;
            }
            else
            {
                totalNums2 -= count[i];
                count[i] = 0;
            }
        }

        if(totalNums % 2 == 0)
            for(int i = idx; i<=255; i++)
                if(count[i] > 0)
                {
                    median = (median + i)/2;
                    break;
                }

        vector<double> ans(5);
        ans[0] = minNum;
        ans[1] = maxNum;
        ans[2] = sum / totalNums;
        ans[3] = median;
        ans[4] = mode;

        return ans;
    }
};