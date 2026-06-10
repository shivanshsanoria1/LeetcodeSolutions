class Solution {
public:
    string losingPlayer(int x, int y) {
        return min(x, y/4) % 2 == 0 ? "Bob" : "Alice";
    }
};
/*
# x: num of 75 value coins
# y: num of 10 value coins
# to make a sum of 115 we need 1x and 4y coins
# thus, for each successful turn of a player 
  1x and 4y coins are needed
# taking the min of x/1 and y/4 gives us 
  the num of successful turns in the game
# the player in the turn after that loses the game

# simulation:
0 successful turns ==> Alice loses ==> Bob wins 
1 successful turns ==> Bob loses ==> Alice wins 
2 successful turns ==> Alice loses ==> Bob wins 
3 successful turns ==> Bob loses ==> Alice wins 
4 successful turns ==> Alice loses ==> Bob wins 
5 successful turns ==> Bob loses ==> Alice wins 
.
.
.

# thus for even successful turns Bob wins
  ans for odd successful turns Alice wins
*/