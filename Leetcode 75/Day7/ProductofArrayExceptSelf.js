/**
 * @param {number[]} nums
 * @return {number[]}
 */
/*
var productExceptSelf = function(nums) {
    let forwardArr = []
    let start1 = 1

    for (let i = 0;i<nums.length;i++){
        forwardArr.push(start1)
        start1 = start1*nums[i]
    }
    let resultArr = []
    let start2 = 1

    for (let i = nums.length-1;i>=0;i--){
        resultArr.unshift(start2*forwardArr[i])
        start2 = start2*nums[i]
    }
    return resultArr
};
*/
// correct solution : making it O(n) time complexity and O(1) space complexity
var productExceptSelf = function(nums) {
    let resultArr = []
    let start1 = 1
    let start2 = 1

    for (let i = 0;i<nums.length;i++){
        resultArr.push(start1)
        start1 = start1*nums[i]
    }

    for (let i = nums.length-1;i>=0;i--){
        resultArr[i] = start2*resultArr[i]
        start2 = start2*nums[i]
    }
    return resultArr
};