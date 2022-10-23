//  C/C++ Programming
//  main.cpp
//  C++CountingChange
//
//  Nhu Ly
//  2/13/22.

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    double total;
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    
    cout << "How many quarters do you have? ";
    cin >> quarters;
    cout << "How many dimes do you have? ";
    cin >> dimes;
    cout << "How many nickels do you have? ";
    cin >> nickels;
    cout << "How many pennies do you have? ";
    cin >> pennies;
    
    total = quarters*0.25 + dimes*0.10 + nickels*0.05 + pennies*0.01;
    
    cout << endl;
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "Your total is: $" << setprecision(2) << total << endl;
    
    return 0;
}
