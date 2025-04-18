#include<bits/stdc++.h>
using namespace std;

void lrotate(int arr[], int n){  
  int temp = arr[0];
  //1,2,3,4,5
  //temp=1
  //2,3,4,5
  for(int i=0;i<n-1;i++){
    arr[i]=arr[i+1];
  }
  arr[n-1] = temp;
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}

int main() {
    int n=5;
  int arr[]= {1,2,3,4,5};
  lrotate(arr, n);
    return 0;
}
