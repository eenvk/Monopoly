#include <iostream>
#include "include/Casella.h"
#include "include/Giocatore.h"
using namespace std;

int main(){
    Casella c1('S');
    Casella c2('L');


    Giocatore n1(1);
    n1.pushProprieta(c1);
    n1.pushProprieta(c2);

    cout << n1;

    return 0;
}