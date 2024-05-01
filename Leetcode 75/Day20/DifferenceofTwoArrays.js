/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[][]}
 */
var findDifference = function(nums1, nums2) {
    //Creating sets for better Time complexity.
    let set1 = new Set(nums1)
    let set2 = new Set(nums2)

    for(num of nums1){
        if(set2.has(num)){
            set1.delete(num)
            set2.delete(num)
        }
    }
    return [[...set1], [...set2]]
};
//Time Complexity : O(n+m)
//Space Complexity : O(n+m)