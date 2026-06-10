class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long int vol = (long long int)length * width * height;
        bool isBulky = length >= int(1e4) || width >= int(1e4) || height >= int(1e4) || vol >= int(1e9);
        bool isHeavy = mass >= 100;

        if(isBulky && isHeavy)
            return "Both";
        else if(isBulky)
            return "Bulky";
        else if(isHeavy)
            return "Heavy";
        return "Neither";
    }
};