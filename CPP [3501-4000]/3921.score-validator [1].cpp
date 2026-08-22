class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for(const string& event: events){
            if(event == "W")
                counter++;
            else if(event == "WD" || event == "NB")
                score++;
            else
                score += stoi(event);
            
            if(counter == 10)
                break;
        }

        return {score, counter};
    }
};