class Solution {
public:
    string getMonthNum(string month){
        vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        string monthNum = "";
        for(int i=0; i<12; i++)
            if(month == months[i])
            {
                monthNum += to_string(i+1);
                break;
            }
            
        return monthNum.length() == 1 ? '0' + monthNum : monthNum;
    }

    string reformatDate(string date) {
        int len = date.length();

        string ddd = len == 12 ? '0' + date.substr(0, 1) : date.substr(0, 2);
        string mm = len == 12 ? getMonthNum(date.substr(4, 3)) : getMonthNum(date.substr(5, 3));
        string yyyy = len == 12 ? date.substr(8) : date.substr(9);

        return yyyy + "-" + mm + "-" + ddd;
    }
};
/*
# date.length() can be only 12 or 13
# 12 when the date is single-digit like "6th Jun 1933"
# 13 when the date is double-digit like "20th Oct 2052"
*/