#include<bits/stdc++.h>
#include <climits>
#include <ostream>
using namespace std;

int largest(vector<int> arr, int n){
  int largest=0;
  for(int i=0;i<n;i++){
    if(arr[i]>largest){
      largest=arr[i];
    }
  }
  return largest;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
      cin>>arr[i];
    }
    int largestEl = largest(arr, n);
    cout<<largestEl<<" is the largest element in the array"<<endl;
    return 0;
}