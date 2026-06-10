class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int finalMass = mass;
        multiset<long long int> s;
        for(int asteroid: asteroids)
        {
            finalMass += asteroid;
            s.insert(-1 * asteroid);
        }

        long long int currPlanetMass = mass;

        while(currPlanetMass < finalMass)
        {
            auto itr = s.lower_bound(-1 * currPlanetMass);
            // no asteroid with mass <= curr planet mass found
            if(itr == s.end())
                return false;
            
            currPlanetMass += abs(*itr);
            s.erase(itr);
        }

        return true;
    }
};
// lower_bound(val): returns an iterator to the first value >= val