//Brute Force Approach: TC - O(2n), SC - O(n)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void moveZero(vector<int>&arr, int n){
  vector<int> temp;
  for(int i=0;i<n;i++){
    if(arr[i]!=0){
      temp.push_back(arr[i]);
    }
  }
  int nz=temp.size();
  for(int i=0;i<nz;i++){
    arr[i]=temp[i];
  }
  for(int i=nz;i<n;i++){
    arr[i]=0;
  }

}

// To execute C++, please define "int main()"
int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }
  moveZero(arr, n);
  for(int i = 0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}

//Optimized Approach: TC - O(n), SC - O(1)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> moveZero(vector<int>&arr, int n){
  int j=-1;
  for(int i=0;i<n;i++){
    if (arr[i]==0){
      j=i;
      break;
    }
  }
  if(j==-1) return arr;
  for(int i=j+1;i<n;i++){
    if(arr[i]!=0){
      swap(arr[i],arr[j]);
      j++;
    }
  }
  return arr;
}

// To execute C++, please define "int main()"
int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }
  moveZero(arr, n);
  for(int i = 0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}

