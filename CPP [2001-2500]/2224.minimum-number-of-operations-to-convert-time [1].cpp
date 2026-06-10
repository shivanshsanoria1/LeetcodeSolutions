class Solution {
public:
    int convertTime(string current, string correct) { // greedy
        int curr_hr = 10*(current[0]-'0') + (current[1]-'0');
        int curr_min = 10*(current[3]-'0') + (current[4]-'0');
        int curr_time = 60*curr_hr + curr_min;

        int correct_hr = 10*(correct[0]-'0') + (correct[1]-'0');
        int correct_min = 10*(correct[3]-'0') + (correct[4]-'0');
        int correct_time = 60*correct_hr + correct_min;
        
        int time_diff = correct_time - curr_time;
        
        int arr[4] = {60,15,5,1};
        int count = 0;
        for(int i=0; i<4; i++)
            while(time_diff - arr[i] >= 0)
            {
                time_diff -= arr[i];
                count++;
            }
        return count;
    }
};