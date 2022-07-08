#include <iostream>
using namespace std;

long long counter = 0;
long long even[300000];
long long odd[300000];
long long ans[300000];
long long cmp[300000];

void Merge(long long *inp, int left, int mid, int right){
    int idxl = left,idxr = mid+1;

    for(int i = 0; i <= right - left; ++i){
        if(idxl > mid){
            /* Left array run out */
            ans[i] = inp[idxr++];
            continue;
        }
        if(idxr > right){
            /* Right array run out */
            ans[i] = inp[idxl++];
            continue;
        }
        if(inp[idxl] <= inp[idxr]){
            /* Copy left array value */
            ans[i] = inp[idxl++];
        }
        else{
            /* Copy right array value */
            counter += (mid-idxl+1);
            // counter = counter % 1000000007;
            ans[i] = inp[idxr++];
        }
    }

    /* Copy to original array */
    for(int i = 0; i <= right - left; ++i){
        inp[left+i] = ans[i];
    }
}


void mergeSort(long long* inp,int left, int right){
    if(left < right){
        int mid = (left+right) / 2;
        /* Split left array */
        mergeSort(inp, left, mid);
        /* Split right array */
        mergeSort(inp, mid+1, right);
        /* Merge left and right array */
        Merge(inp, left, mid, right);
    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int check = 0;
    long long n = 0;
    long long tmp = 0;
    long long od = 0;
    long long ev = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        if(i % 2 == 0){
            odd[od] = tmp;
            od++;
        }
        else{
            even[ev] = tmp;
            ev++;
        }
    }
    // for(int i = 0; i < od; i++){
    //     cout<<odd[i]<<endl;
    // }
    // cout<<"-----"<<endl;
    // for(int i = 0; i < ev; i++){
    //     cout<<even[i]<<endl;
    // }

    mergeSort(odd, 0, od - 1);
    mergeSort(even, 0, ev - 1);
    // cout<<"-----"<<endl;
    // for(int i = 0; i < od; i++){
    //     cout<<odd[i]<<endl;
    // }
    // for(int i = 0; i < ev; i++){
    //     cout<<even[i]<<endl;
    // }
    od = 0;
    ev = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            cmp[i] = odd[od];
            od++;
        }
        else{
            cmp[i] = even[ev];
            ev++;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(cmp[i] > cmp[i+1]){
            check = 1;
        }
    }
    if(check == 1){
        cout<<"no"<<endl;
    }
    else{
        cout<<"yes"<<endl;
    }
    // cout<<"---"<<endl;
    // for(int i = 0; i < n; i++){
    //     cout<<cmp[i]<<endl;
    // }
    // cout<<"---"<<endl;
    cout<<counter<<endl;
    return 0;
}