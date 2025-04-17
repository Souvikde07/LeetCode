#include<bits/stdc++.h>
#include <climits>
#include <ostream>
using namespace std;

int secLargest(vector<int>&arr,int n){
  int largest = arr[0];
  int slargest = -1;
  for(int i=1; i<n;i++){
    if(arr[i]>largest){
      slargest=largest;
      largest = arr[i];
    }
    else if(arr[i] < largest && arr[i]>slargest){
      slargest=arr[i];
    }
  }
  return slargest;
}
int secSmallest(vector<int>&arr,int n){
  int smallest=arr[0];
  int ssmallest=INT_MAX;
  for(int i=1;i<n;i++){
    if(arr[i]<smallest){
      ssmallest=smallest;
      smallest=arr[i];
    }
    else if (arr[i] != smallest && arr[i]<smallest) {
      ssmallest=arr[i];
    }
  }
  return ssmallest;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
      cin>>arr[i];
    }
    int slargest=secLargest(arr,n);
    int ssmallest=secSmallest(arr,n);
    cout<<slargest<<endl;
    cout<<ssmallest;
    return 0;
}