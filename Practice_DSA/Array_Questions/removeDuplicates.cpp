#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

int remDup(vector<int> &arr, int n){  
  int j=0;
  for(int i=1;i<n; i++){
    if(arr[i]!= arr[j]){
      arr[j+1]=arr[i];
      j++;
    }
  }
  return j+1;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
      cin>>arr[i];
    }
    int Remove = remDup(arr, n);  
    cout<<Remove<<endl;
    return 0;
}
