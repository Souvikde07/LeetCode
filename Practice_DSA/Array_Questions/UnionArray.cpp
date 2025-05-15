#include<bits/stdc++.h>
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;
        vector<int> unArr;
        
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                if(unArr.size()==0 || unArr.back() != nums1[i]){
                    unArr.push_back(nums1[i]);
                }
                i++;
            } else{
                if(unArr.size()==0 || unArr.back() != nums2[j]){
                    unArr.push_back(nums2[j]);
                }
                j++;
            }
        }
        while(j<n2){
            if(unArr.size()==0 || unArr.back() != nums2[j]){
                unArr.push_back(nums2[j]);
            }
            j++;
        }
        while(i<n1){
            if(unArr.size()==0 || unArr.back() != nums1[i]){
                unArr.push_back(nums1[i]);
            }
            i++;
        }
        return unArr;
    }
};