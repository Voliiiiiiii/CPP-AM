#include <iostream>
#include <string>
#include <vector>
#include "Settlment.h"
#include "SettlmentStatisticsImpl.h"

int main() {
    Settlement kezdi("kezdi","CV",20000);
    cout<<kezdi<<endl;

    SettelmentStatisticsImpl impl;
    cout<<impl.numSettlementsByCounty("VN")<<endl;
    return 0;
}