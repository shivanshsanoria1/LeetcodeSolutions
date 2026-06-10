class Solution {
public:
    bool isLeapYear(int year){
        return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
    }

    int dayOfYear(string date) {
        int yyyy = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        int dd = stoi(date.substr(8));
        
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isLeapYear(yyyy))
            days[1]++;
            
        int ans = 0;
        for(int i=0; i<mm-1; i++)
            ans += days[i];
        return ans + dd;
    }
};