/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function(gain) {
    sum = 0
    max = 0
    for (let i = 0; i<gain.length;i++){
        sum += gain[i]
        max = Math.max(max,sum)
    }
    return max
};