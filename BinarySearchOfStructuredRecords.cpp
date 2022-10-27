#include "stdafx.h" 
#include <string.h>
#include <fstream> 
using namespace std;

typedef struct S_CUSTOMER_LIST {
  char name[40];
  char number[10];
} Customer;

Customer CustomerList [MAX];

int main(int argc, char* argv[]) {
  ifstream f("phony.txt"); if(f == NULL){
    cout<<"Cannot open file";
    exit(1);
  }
  int length = 0;
  while(!f.eof()) {
    char temp[40] = "\0";
    f.getline(temp, 34);
    CustomerList[length].name;
    for(int i = 0; i < strlen(temp); i++) {
      CustomerList[length].name[i] = '\0';
      if(temp[i] == '.')
        break;
      else
        CustomerList[length].name[i] = temp[i];
    }
    f.clear();
    f.getline(CustomerList[length].number, 10, '\n');
    length++;
  }
  f.close();
  int option;
  do {
    cout<<"1. Search using customer phone number"<<endl;
    cout<<"2. Search using customer name"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>option;
    if(option == 1) {
      char phoneNumber[10];
      cout<<"Enter customer phone number: ";
      cin>>phoneNumber;
      
      int imin = 0; 
      int imax = length - 1;
      int imid;
      int tries=0;
      bool found = false;
      while ( imax >= imin && !found) {
        tries++;
        imid = (imin + imax) / 2;
        if (stricmp(phoneNumber, CustomerList[imid].number) == 0) 
          found = true;
        else if (stricmp(phoneNumber, CustomerList[imid].number) < 0)
          imax=imid-1;
        else
          imin=imid+1;
      }
      if (found)
        cout << CustomerList[imid].number << " in " << tries << " tries" << endl;
      else
        cout << "Not Found" << endl;
    }
    if(option == 2) {
      char name[40];
      cout<<"Enter customer name: ";
      cin.ignore();
      cin.getline(name, 40, '\n');
      
      int tries=0; 
      bool found = false;
      int i;
      for(i = 0; i < length; i++) {
        tries++;
        if (stricmp(name, CustomerList[i].name) == 0 ) {
          found = true;
          break;
        }
      }
      if (found)
        cout << CustomerList[i].name << " in " << tries << " tries" << endl;
      else
        cout << "Not Found" << endl;
    }
  }
  while(option != 3);
  return 0;
}
