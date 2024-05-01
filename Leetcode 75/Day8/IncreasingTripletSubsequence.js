/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
    let a = Infinity, b=Infinity, c=Infinity
    
    for(let i = 0; i<nums.length; i++){
        if(nums[i]<=a) a=nums[i]
        else if (nums[i]<=b) b=nums[i]
        else if (nums[i]<=c) c=nums[i]

        if (c<Infinity && c>b && b>a) return true
    }
    return false
};

/* --  less runtime Solution
var increasingTriplet = function(nums) {

    let firstNum = Infinity;
    let secoundNum = Infinity;
    
    for(let currentNum of nums){
    
        if(currentNum > secoundNum){
            return true;
        }
    
        if(currentNum > firstNum){
            secoundNum = currentNum;
        }else{
            firstNum = currentNum
        }
    }
    
    return false;
       
    };*/