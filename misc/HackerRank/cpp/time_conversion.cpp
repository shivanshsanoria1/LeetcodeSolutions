/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string res;
    if(s[8]=='A') // AM
    {
        if(s[0]=='1' && s[1]=='2') // 12AM
            res += "00" + s.substr(2,6);
        else
            res += s.substr(0,8);
    }
    else if(s[8]=='P')
    {
        if(s[0]=='1' && s[1]=='2')
            res += "12" + s.substr(2,6);
        else
            res += to_string( stoi(s.substr(0,2))+12 ) + s.substr(2,6);
    }
    return res;
}