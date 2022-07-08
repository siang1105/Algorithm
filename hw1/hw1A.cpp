#include <iostream>
using namespace std;

void recur(long long &a, long long &b, long long d){
    if(d == 1){
        return;
    }
    else if(d % 2 != 0){
        recur(a, b, (d-1));
        long long pre_a = a;
        long long pre_b = b;
        a = pre_a * 3 + pre_b * 1;
        b = pre_a * 1 + pre_b * 3;
        a = a % 1000000007;
        b = b % 1000000007;
        return;
    }
    else{
        recur(a, b, d/2);
        long long pre_a = a;
        long long pre_b = b;
        a = pre_a * pre_a + pre_b * pre_b;
        b = pre_a * pre_b + pre_b * pre_a;
        a = a % 1000000007;
        b = b % 1000000007;
        return;
    }
}

int main(){
    long long d = 0;
    long long a = 3;
    long long b = 1;
    cin>>d;
    if(d == 0){
        cout<<"1"<<endl;
    }
    else{
        recur(a, b, d);
        cout<<a<<endl;
    }
    return 0;
}