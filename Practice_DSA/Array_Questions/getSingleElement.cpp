//Brute Force Approach
TC - O(n^2) SC - O(1)
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr){
  int n = arr.size();

  for(int i = 0;i<n;i++){
    int count= 0;
    for(int j = 0;j<n;j++){
      if(arr[j]==arr[i]){
        count += 1; 
      }
    }
    if(count == 1){
      return arr[i];
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {4,1,2,1,2};
  int ans = getSingleElement(arr);
  cout<<"The Single Element is: " << ans << endl;
  return 0;
}

// Better Approach - Using Hash Map
// TC - O(n)+O(n)+O(n) SC - O(maxElement+1)
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr){
  int n = arr.size();
  //calculate max
  int maxi = arr[0];
  for(int i = 0;i<n;i++){
    maxi = max(maxi, arr[i]);
  }
  //store array elements into hash array
  vector<int> hasharr(maxi+1, 0);
  for(int i = 0;i<n;i++){
    hasharr[arr[i]]++;
  }
  //loop through hasharr to the get the el
  for(int i = 0;i<n;i++){
    if(hasharr[arr[i]] == 1){
      return arr[i];
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {4,1,2,1,2};
  int ans = getSingleElement(arr);
  cout<<"The Single Element is: " << ans << endl;
  return 0;
}

// Better Approach - Using Hash Map
// TC - O(nlogm) SC - O(m), where m=(n/2)+1, n = size of the array
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr){
  int n = arr.size();
  
  //store array elements into map
  map<int, int> mp;
  for(int i = 0;i<n;i++){
    mp[arr[i]]++;
  }
  //loop through hasharr to the get the el
  for(int i = 0;i<n;i++){
    if(mp[arr[i]] == 1){
      return arr[i];
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {4,1,2,1,2};
  int ans = getSingleElement(arr);
  cout<<"The Single Element is: " << ans << endl;
  return 0;
}

//Optimal Approach - Using XOR
// TC - O(n) SC - O(1)
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr){
  int n = arr.size();
  int xorr = 0;
  for(int i=0;i<n;i++){
    xorr = xorr ^ arr[i];
  }
  return xorr;
}

int main() {
  vector<int> arr = {4,1,2,1,2};
  int ans = getSingleElement(arr);
  cout<<"The Single Element is: " << ans << endl;
  return 0;
}
