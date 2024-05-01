/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

//Sliding window Algorithm - k=4,[1,12,-5,-6,50,3]
var findMaxAverage = function(nums, k) {
    let sum = 0
    //find the sum of the elements of the first window
    for(let i=0;i<k;i++){
        sum += nums[i]
    }
    let maxSum = sum
    let startIndex = 0
    let endIndex = k
    while(endIndex<nums.length){
        sum -= nums[startIndex] //remove previous element
        startIndex++

        sum += nums[endIndex]//add new element
        endIndex++

        maxSum = Math.max(maxSum,sum) //Update maxSum
    }
    return maxSum/k //return the average of the MaxSum. 
};