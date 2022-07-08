#include <iostream>
#include <string>
using namespace std;

string str1;
string str2;

int main(){
    getline(cin, str1);
    getline(cin, str2);
    // cout<<str1<<endl;
    // cout<<str2<<endl;
    long long N = str1.length();
    long long idx = 0;
    long long shrimp = 0;
    while(idx < N-1){
        // cout<<idx<<endl;
        if(str1[idx] == '0' && str2[idx] == '0'){
            if((str1[idx+1] == '0' && str2[idx+1] == '0') || (str1[idx+1] == '1' && str2[idx+1] == '0')){
                str1[idx] = '1';
                str2[idx] = '1';
                str2[idx+1] = '1';
                shrimp++;
            }
            else if(str1[idx+1] == '0' && str2[idx+1] == '1'){
                str1[idx] = '1';
                str2[idx] = '1';
                str1[idx+1] = '1';
                shrimp++;
            }
            // idx++;
        }
        else if((str1[idx] == '0' && str2[idx] == '1') && (str1[idx+1] == '0' && str2[idx+1] == '0')){
            str1[idx] = '1';
            str1[idx+1] = '1';
            str2[idx+1] = '1';
            // idx++;
            shrimp++;
        }
        else if((str1[idx] == '1' && str2[idx] == '0') && (str1[idx+1] == '0' && str2[idx+1] == '0')){
            str2[idx] = '1';
            str2[idx+1] = '1';
            str1[idx+1] = '1';
            // idx++;
            shrimp++;
        }
        idx++;
    }
    cout<<shrimp<<endl;
    // cout<<str1<<endl;
    // cout<<str2<<endl;
    return 0;

}