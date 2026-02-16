//problem link: https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/0

class Solution {
  public:
    long long kThEle(long long A[],long long N,long long k){
        priority_queue<int>pq;
        for(long long i=0;i<N;i++){
            pq.push(A[i]);
            
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
    
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        long long first = kThEle(A,N,K1);
        long long second = kThEle(A,N,K2);
        long long sum = 0;
        for(int i=0;i<N;i++){
            if(A[i]>first && A[i]<second){
                sum+=A[i];
            }
        }
        return sum;
    }
};
