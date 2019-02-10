#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
using namespace std;

void print(char A[5][5]);
void decrypt();
char sq1[5][5]={{'n','d','s','k','v'},{'c','f','m','w','h'},{'i','a','g','r','l'},{'p','e','q','o','x'},{'b','j','t','u','y'}};
char sq2[5][5]={{'u','t','w','p','n'},{'y','k','e','s','a'},{'c','h','l','r','g'},{'d','o','q','m','i'},{'b','j','x','f','v'}};
char sq3[5][5]={{'v','y','a','p','n'},{'h','g','s','q','o'},{'x','k','b','i','m'},{'e','t','c','l','j'},{'r','f','d','u','w'}};
char sq4[5][5]={{'d','s','q','o','y'},{'t','p','m','a','j'},{'r','w','x','i','e'},{'k','u','c','h','n'},{'v','l','f','g','b'}};

int main()
{
    srand((time(NULL)));
    bool f;
    short int i,j,k,s,x1,x2,y1,y2;
    string input;
    print(sq1);
    print(sq2);
    print(sq3);
    print(sq4);
    cout << "Enter your message: ";
    getline(std::cin, input);
    for (i=0;i<input.size();i++){
        if (input[i]== ' ') input.erase(i,1);
    }
    s=input.size();
    if (s%2!=0) f=true;
    for (k=0;k<s;k=k+2){
        for (i=0;i<5;i++){
            for (j=0;j<5;j++){
                if (input[k]==sq1[i][j]){
                    x1=j;
                    y2=i;
                }
                if (input[k+1]==sq4[i][j]){
                    x2=j;
                    y1=i;
                }
            }
        }
        input[k]=sq3[x1][y1];
        input[k+1]=sq2[x2][y2];
    }
    if (f) input.erase(s,1);
    cout << input << "\n";
    decrypt();
    system("pause");
}

void print(char A[5][5]){
    short int i,j;
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            cout << A[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void decrypt(){
    string input;
    short int i,j,k,l,x1,x2,y1,y2;
    cout << "Enter encrypted message: ";
    getline(cin,input);
    l=input.size();
    for (k=0;k<l;k=k+2){
        for (i=0;i<5;i++){
            for (j=0;j<5;j++){
                if (input[k]==sq3[i][j]){
                    x2=j;
                    y1=i;
                }
                if (input[k+1]==sq2[i][j]){
                    x1=j;
                    y2=i;
                }
            }
        }
        input[k]=sq1[x1][y1];
        input[k+1]=sq4[x2][y2];
    }
    cout << input << "\n";
}
