#include<iostream>
#include<deque>

using namespace std;
void printMax(int arr[], int n, int k){
    std::deque<int> qi(k);
    int i;
    for(i=0; i<k; i++){
        while(!qi.empty() && arr[i]>=arr[qi.back()])
            qi.pop_back();
        qi.push_back(i);
    }
    for(; i<n; i++){
        cout<<arr[qi.front()]<<" ";
        while(!qi.empty() && qi.front()<=i-k)
            qi.pop_front();
        while(!qi.empty() && arr[i]>=arr[qi.back()]){
            qi.pop_back();
        }
        qi.push_back(i);
    }
    cout<<arr[qi.front()];
} 
int main(){
    int arr[] = {12, 1, 78, 90, 57, 89, 56}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k = 3; 
    printMax(arr, n, k);
  // cout<<n<<" "<<k; 
    return 0; 
}
