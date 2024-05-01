/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let insertpos = 0

    for(let i=0; i<nums.length; i++){
        if(nums[i]!=0){
            nums[insertpos] = nums[i]
            insertpos++
        }
    }
    while(insertpos<nums.length){
        nums[insertpos++] = 0
    }
};