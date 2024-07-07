//Approach - 1
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consume = 0;
        while(numBottles >= numExchange){
            consume += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }
        return consume + numBottles;
    }
};
//Approach - 2
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange){
            int extraFullBottles = emptyBottles / numExchange;
            int remain = emptyBottles % numExchange;
            consumed += extraFullBottles;
            emptyBottles = remain + extraFullBottles;
        }
        return consumed;
    }
};
//Approach - 3
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};