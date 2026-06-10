class Solution {
public:
    int numberOfCuts(int n) {
        if(n == 1)
            return 0;
        return n % 2 == 0 ? n / 2 : n;
    }
};
/*
# if n == 1, no cuts are needed to divide the circle
# if n == 2, 1 cut (the diameter) is needed
# for n >= 3, a regular-polygon of n sides can be formed 
  whose center is the same as the center of the circle and
  whose sides are the chords of the cicle
# if n is odd, the polygon has n radii connecting each vertex with the center 
  so n cuts are needed
# if n is even, each pair of radii form a straight line (the diameter), 
  so n/2 cuts are needed
*/