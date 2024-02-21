class Solution {
public:
    string getMonthNum(string month){
        if(month == "Jan")
            return "01";
        if(month == "Feb")
            return "02";
        if(month == "Mar")
            return "03";
        if(month == "Apr")
            return "04";
        if(month == "May")
            return "05";
        if(month == "Jun")
            return "06";
        if(month == "Jul")
            return "07";
        if(month == "Aug")
            return "08";
        if(month == "Sep")
            return "09";
        if(month == "Oct")
            return "10";
        if(month == "Nov")
            return "11";
        return "12"; // "Dec"
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