class Solution {
public:
    int solve(int teams){
        if(teams == 1)
            return 0;
        int matches = teams/2;
        teams = teams % 2 == 0 ? teams/2 : teams/2 + 1;
        return matches + solve(teams);
    }
    
    int numberOfMatches(int n) { // recursive
        return solve(n);
    }
};