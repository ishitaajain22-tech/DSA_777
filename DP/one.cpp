#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k, p;
        cin >> n >> k >> p;
        
        if(abs(k) > n * p) {
            cout << -1 << endl;
            continue;
        }
        int ops = (abs(k) + p - 1) / p; 
        ops = min(ops, n); 
        
        cout << ops << endl;
    }
    
    return 0;
}