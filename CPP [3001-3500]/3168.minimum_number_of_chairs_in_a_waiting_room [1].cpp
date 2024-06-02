class Solution {
public:
    int minimumChairs(string s) {
        int people = 0;
        int chairs = 0;

        for(char ch: s)
        {
            if(ch == 'E')
                people++;
            else // ch == 'L'
                people--;

            chairs = max(chairs, people);
        }

        return chairs;
    }
};