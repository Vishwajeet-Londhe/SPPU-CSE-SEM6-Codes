#include <iostream>
#include <algorithm>
using namespace std;

struct Job{
    char jobId;
    int deadline;
    int profit;
};

int comparison(Job x, Job y){
    return(x.profit > y.profit);
}

void jobScheduling(Job arr[], int n){
    sort(arr, arr+n, comparison);

    int jobsSelected[3];
    bool slots[3];

    for(int i=0; i<3; i++){
        slots[i]=false;
    }

    for(int i=0; i<n; i++){
        for(int j=arr[i].deadline-1; j>=0; j--){
            if(slots[j]==false){
                jobsSelected[j]=i;            
                slots[j]=true;
                break;
            }
        }
    }
    
    int max_profit=0;
    for(int i=0; i<3; i++){
        
        max_profit+=arr[jobsSelected[i]].profit;
        char x = arr[jobsSelected[i]].jobId;
        cout<<x<<" "<<arr[jobsSelected[i]].profit<<"\n";
        
    }
    cout<<"Max Profit is "<<max_profit<<"\n";
}

int main(){
    Job arr[] = { { 'a', 2, 100 },        
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };

    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<n;

    jobScheduling(arr, n);
}