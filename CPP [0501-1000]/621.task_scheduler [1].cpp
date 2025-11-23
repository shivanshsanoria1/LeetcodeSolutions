class Solution {
public:
    // T.C.=O(t), S.C.=O(26)
    // t: size of tasks[]
    int leastInterval(vector<char>& tasks, int n) { 
        vector<int> freq(26, 0);
        for(char task: tasks)
            freq[task - 'A']++;
        int maxFreq = 0;
        // number of elements with max freq
        int maxFreqCount = 0; 

        for(int i=0; i<26; i++)
        {
            // new max freq found
            if(freq[i] > maxFreq) 
            {
                // update max freq
                maxFreq = freq[i];
                // reset max freq count 
                maxFreqCount = 1;
            }
            // another max freq found
            else if(freq[i] == maxFreq) 
                // increment max freq count
                maxFreqCount++;
        }

        int time = maxFreq + n*(maxFreq - 1) + (maxFreqCount - 1);

        return max(time, (int)tasks.size());
    }
};
/*
# for optimal solution-
# element with maxFreq is seperated by a gap of size n
# number of gaps = maxFreq - 1
# so total length of sequence is 
  maxFreq + (maxFreq - 1) gaps of size n + 1 instance of possibly remaining chars with maxFreq
*/