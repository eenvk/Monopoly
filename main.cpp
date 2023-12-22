#include <iostream>
#include "include/Casella.h"
#include "include/Giocatore.h"
using namespace std;

int main(){
    int array[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==0){
                cout<<array[i+j]<<"  ";
            }
            else if(i==7){
                cout<<array[21-j]<<" ";
            }
            else if(j==0 && (i!=0 && i!=7)){
                cout<<array[28-i];
            }
            else if(j==7 && (i!=0 && i!=7)){
                cout<<array[j+i];
            }
            else{
                cout<<" ";
            }
        }

        cout<<endl;
    }
    return 0;
}
