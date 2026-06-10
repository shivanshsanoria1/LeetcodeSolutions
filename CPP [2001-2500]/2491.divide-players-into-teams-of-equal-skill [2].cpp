class Solution {
public:
    // T.C.=O(n + m), S.C.=O(m)
    // m: max-val in skill[]
    // counting-sort + 2-pointer
    long long dividePlayers(vector<int>& skill) {
        int minVal = *min_element(skill.begin(), skill.end());
        int maxVal = *max_element(skill.begin(), skill.end());

        vector<int> freq(maxVal + 1, 0);
        for(int num: skill)
            freq[num]++;
        
        int left = minVal, right = maxVal;
        long long int sum = 0;

        while(left <= right)
        {
            if(freq[left] != freq[right])
                return -1;

            sum += (long long int)left * right * (left == right ? freq[left]/2 : freq[left]);

            left++;
            right--;
        }

        return sum;
    }
};