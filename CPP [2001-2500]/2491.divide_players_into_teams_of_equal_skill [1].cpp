class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    // sorting + 2-pointer
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int left = 0, right = skill.size()-1;
        int pairVal = skill[left] + skill[right];
        long long int sum = 0;

        while(left < right)
        {
            if(skill[left] + skill[right] != pairVal)
                return -1;

            sum += skill[left] * skill[right];

            left++;
            right--;
        }

        return sum;
    }
};