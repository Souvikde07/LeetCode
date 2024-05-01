/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

// Time : O(nlogn)
/*
var maxOperations = function(nums, k) {
    nums.sort((a,b)=> a-b)
    let count = 0
    let left = 0 , right = nums.length-1
    while(left<right){
        const tempSum = nums[left] + nums[right]
        if (tempSum === k){
            count++
            left++
            right--
        }else if(tempSum < k){
            left++
        }else{
            right--
        }
    }
    return count
};
*/
var maxOperations = function(nums, k) {
    const hashMap = new Map();
    let count = 0;

    for(let i = 0; i < nums.length; i++) {
        const diff = k - nums[i];

		// if the current difference is not found then set the value to map
        if(!hashMap.has(diff)) {
            hashMap.set(nums[i], (hashMap.get(nums[i]) || 0) + 1);
            continue;
        }
		// In previous condition we checked that the hash presents
		// reduce the occurrance by 1
        hashMap.set(diff, hashMap.get(diff)-1);
		// if the value is 0 of hash then delete it
		// 0 means the hash has no more occurrances
        if(!hashMap.get(diff)) hashMap.delete(diff);
		// increase the operation count
        count++;
    }
    return count;
};
