// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code her
    int low = 0 , high = n-1;
    while(low < high){
        int mid = (low + high) >> 1;
        if(arr[mid] == 1 && (mid - 1 >= 0 && arr[mid - 1] == 0)) return mid;
        else if(arr[mid] == 1) high = mid;
        else low = mid + 1;
    }
    return arr[high] == 1 ? high : -1;
}