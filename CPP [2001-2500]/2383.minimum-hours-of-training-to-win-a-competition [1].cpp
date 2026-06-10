class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int requiredEnery = accumulate(energy.begin(), energy.end(), 0);
        int extraEnergy = initialEnergy > requiredEnery ? 0 : requiredEnery - initialEnergy + 1;

        int extraExperience = 0;
        int currExperience = initialExperience;
        for(int exp: experience)
        {
            if(currExperience <= exp)
            {
                extraExperience += exp - currExperience + 1;
                currExperience += exp - currExperience + 1;
            }
            currExperience += exp;
        }
        
        return extraEnergy + extraExperience;
    }
};