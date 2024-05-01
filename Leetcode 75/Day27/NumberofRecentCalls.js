var RecentCounter = function() {

    this.reqs=[]
};

/**
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function(t) {

    this.reqs.push(t)

    while(this.reqs[0]<t-3000){
        this.reqs.shift()
    }
    return this.reqs.length
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
// In C++ this solution is better.
// class RecentCounter {
//     public:
//         queue<int> myQ;
//         RecentCounter() {
//         }

//         int ping(int t) {
//             myQ.push(t);
//             while(myQ.front() < t-3000){
//                 myQ.pop();
//             }
//             return myQ.size();
//         }
//     };
//     /**
//      * Your RecentCounter object will be instantiated and called as such:
//      * RecentCounter* obj = new RecentCounter();
//      * int param_1 = obj->ping(t);
//      */