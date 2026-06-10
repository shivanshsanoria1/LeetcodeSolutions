class Solution {
private:
    int getDays(string date){
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = 0;
        for(int i=0; i<month-1; i++)
            days += monthDays[i];
        return days + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = getDays(arriveAlice);
        int endA = getDays(leaveAlice);
        int startB = getDays(arriveBob);
        int endB = getDays(leaveBob);
        
        // startB lies in the range [startA, endA]
        if(startA <= startB && startB <= endA)
            return min(endA, endB) - startB + 1;
        // startA lies in the range [startB, endB]
        if(startB <= startA && startA <= endB)
            return min(endA, endB) - startA + 1;
        // [startA, endA] and [startB, endB] do not intersect
        return 0;
    }
};