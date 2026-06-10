class Solution {
public:
    double angleClock(int hour, int minutes) {
        // angle made by minute hand in CW direction from 0 position
        int minuteAngle = minutes * 6;
        if(hour == 12) // 12th hour is treated as 0th hour
            hour = 0;
        // angle made by hour hand in CW direction from 0 position
        double hourAngle = hour * 30 + minutes * 0.5;
        double diff = abs(hourAngle - minuteAngle);
        // limit the angle in the rnage [0, 180] degree
        return diff > 180 ? 360 - diff : diff;
    }
};

/*
# speed of minute hand = 360/60 degree/min. = 6 degree/min.
# speed of hour hand = 360/12 degree/hour. = 30 degree/hour. 
  = 30/60 degree/min. = 0.5 degree/min.
*/