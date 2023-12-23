#include <iostream>
#include "include/Casella.h"
#include "include/Giocatore.h"
using namespace std;

int main(){
    int array[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==0){
                cout<<array[14+j]<<" ";
            }
            else if(i==7){
                cout<<array[7-j]<<"  ";
            }
            else if(j==0 && (i!=0 && i!=7)){
                if(i==6){
                    cout<<array[14-i]<<"  ";
                }
                else {
                    cout << array[14 - i] << " ";
                }
            }
            else if(j==7 && (i!=0 && i!=7)){
                cout<<array[21+i];
            }
            else{
                cout << "   ";
            }
        }
        cout<<endl;
    }
    return 0;
}