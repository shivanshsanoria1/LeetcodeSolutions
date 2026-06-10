class Solution {
public:
    int convertTime(string current, string correct) { // greedy
        int curr_hr = stoi(current.substr(0,2));
        int curr_min = stoi(current.substr(3));
        int curr_time = 60*curr_hr + curr_min;

        int correct_hr = stoi(correct.substr(0,2));
        int correct_min = stoi(correct.substr(3));
        int correct_time = 60*correct_hr + correct_min;
        
        int time_diff = correct_time - curr_time;
        
        int arr[4] = {60,15,5,1};
        int count = 0;
        for(int i=0; i<4; i++)
        {
            count += time_diff/arr[i];
            time_diff %= arr[i];
        }
        return count;
    }
};