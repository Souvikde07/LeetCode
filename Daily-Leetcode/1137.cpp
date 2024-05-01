/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function(n) {
    if(n == 0) return 0

    let t0 = 0
    let t1 = 1
    let t2 = 1

    for(let i = 3; i<=n; i++){
        [t0,t1,t2] = [t1,t2,t0+t1+t2] 
    }
    return t2;
};