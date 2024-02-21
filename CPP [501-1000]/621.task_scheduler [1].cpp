class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) { // T.C.=O(26), S.C.=O(26)
        vector<int> freq(26, 0);
        for(char task: tasks)
            freq[task - 'A']++;
        int maxFreq = 0; // max freq
        int maxFreqCount = 0; // number of elements with max freq
        for(int i=0; i<26; i++)
        {
            if(freq[i] > maxFreq) // new max freq found
            {
                maxFreq = freq[i]; // update max freq
                maxFreqCount = 1; // reset max freq count
            }
            else if(freq[i] == maxFreq) // another max freq found
                maxFreqCount++; // increment max freq count
        }
        int len = tasks.size();
        int time = maxFreq + n*(maxFreq - 1) + (maxFreqCount - 1);
        return max(time, len);
    }
};
/*
# for optimal solution-
# element with maxFreq is seperated by a gap of size n
# number of gaps = maxFreq - 1
# so total length of sequence is 
  maxFreq + (maxFreq - 1) gaps of size n + 1 instance of possibly remaining chars with maxFreq
*/