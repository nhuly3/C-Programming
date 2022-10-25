//  C/C++ Progeamming
//  main.cpp
//  C++ElectricBill
//
//  Nhu Ly
//  2/20/22.

#include <iostream>
using namespace std;

const double tier1_ALLOWANCE = 350;
const double tier2_ALLOWANCE = 1450;
const double tier1_RATE = 0.23;
const double tier2_RATE = 0.29;
const double tier3_RATE = 0.45;
const double commissionTax = 0.20;

int main(int argc, const char * argv[]) {
    int kWh;
    double tier1Usage, tier2Usage, tier3Usage;
    double tier1Cost, tier2Cost, tier3Cost;
    double total;
    
    cout << "Enter kWh used: ";
    cin >> kWh;
    if (cin.fail()){
        cout << "Illegal non-numeric input.";
        return 1;
    }
    
    if(kWh <=tier1_ALLOWANCE){
        tier1Usage = kWh;
        tier2Usage = 0;
        tier3Usage = 0;
        tier1Cost = tier1Usage * tier1_RATE;
        tier2Cost = tier2Usage * tier2_RATE;
        tier3Cost = tier3Usage * tier3_RATE;
    }
    else if(kWh <=tier2_ALLOWANCE){
        tier1Usage = tier1_ALLOWANCE;
        tier2Usage = kWh - tier1_ALLOWANCE;
        tier3Usage = 0;
        tier1Cost = tier1Usage * tier1_RATE;
        tier2Cost = tier2Usage * tier2_RATE;
        tier3Cost = tier3Usage * tier3_RATE;
    }
    else{
        tier1Usage = tier1_ALLOWANCE;
        tier2Usage = tier2_ALLOWANCE - tier1_ALLOWANCE;
        tier3Usage = kWh - tier2_ALLOWANCE;
        tier2Cost = tier2Usage * tier2_RATE;
        tier1Cost = tier1Usage * tier1_RATE;
        tier3Cost = tier3Usage * tier3_RATE;
    }
    
    cout << "Tier 1 Usage " << tier1Usage << " kWh $" << tier1Cost << endl;
    cout << "Tier 2 Usage " << tier2Usage << " kWh $" << tier2Cost << endl;
    cout << "Tier 3 Usage " << tier3Usage << " kWh $" << tier3Cost << endl;
    cout << "Engergy Commission Tax " << commissionTax << endl;
    
    total = tier1Cost+ tier2Cost + tier3Cost + commissionTax;
    cout << "Total Electric Charges " << total << endl;
    
    return 0;
}
