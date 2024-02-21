class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> points;
        points.insert(to_string(x) + "#" + to_string(y));
        for(char ch: path)
        {
            if(ch == 'N')
                y++;
            else if(ch == 'S')
                y--;
            else if(ch == 'E')
                x++;
            else // ch == 'W'
                x--;
            string hash = to_string(x) + "#" + to_string(y);
            if(points.find(hash) != points.end())
                return true;
            points.insert(hash);
        }
        return false;
    }
};