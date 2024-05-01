/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    let pivot = 0 
    let left = 0 
    let right = 0

    for(let i = pivot+1;i<nums.length; i++){
        right += nums[i]
    }
    for (let pivot=0;pivot<nums.length;pivot++){
        if (left==right) return pivot
        left+=nums[pivot]
        right -= nums[pivot+1] 
    }
    return -1
};