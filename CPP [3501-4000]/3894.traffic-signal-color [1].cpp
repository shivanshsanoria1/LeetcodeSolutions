class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    string trafficSignal(int timer) {
        if(timer == 0)
            return "Green";
        else if(timer == 30)
            return "Orange";
        else if(timer > 30 && timer <= 90)
            return "Red";
        
        return "Invalid";
    }
};