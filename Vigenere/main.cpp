#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() //no "space" erasing;
{
    string input, key;
    short int i,j,l,p;
    cout << "Enter your message: ";
    getline(std::cin, input);
    cout << "Enter your key: ";
    getline(std::cin,key);
    l=input.size();
    /*for (i=0;i<l;i++){
        if (input[i]==' '){
            p++;
            for (j=i;j<l;j++){
                input[j]=input[j+1];
            }
        }
    }*/
    //l=l-p;
    j=0;
    p=key.size();
    for (i=0;i<l;i++){
        //cout << ((int)input[i]-97) << ":" << ((int)input[i]+(int)key[j]-194) << " ";
        if (input[i]!=' '){
            input[i]=(int)input[i]+(int)key[j]-194;
            input[i]=((int)input[i] % 26)+97;
            j++;
            if (j==p) j=0;
        }
        else continue;
    }
    cout << input << "\n";
    system("pause");
}
