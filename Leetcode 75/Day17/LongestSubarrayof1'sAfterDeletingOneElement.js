/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let result = 0, k=1
    for (let i = 0,j=0;j<nums.length;j++){
        if (nums[j]== 0){
            k--
        }
        while(k<0){
            if (nums[i]==0){
            k++
            }
            i++
        }
        result = Math.max(result,j-i)
    }
    return result
};