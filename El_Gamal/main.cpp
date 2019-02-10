#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int modulo(double a, double b, int p);
void sending(int A, int P);
void receiving(int A, int P);

int main()
{
    int P,m,A,y;
    double x;
    cout << "Enter 0 for sending and 1 for receiving message:";
    cin >> m;
    cout << "Enter prime number P (>210): ";
    cin >> P;
    cout << "Enter number A (for P=211 it may be A=2): ";
    cin >> A;
    if (m == 0) sending(A,P);
    else receiving(A,P);
    system("pause");
}
int modulo (double a, double b, int p){
    int i,c=1;
        for (i=0;i<b;i++){
            c=(int)(c*a) % p;
   }
   return(c);
}

void sending(int A, int P){
    int r,e,s,l,i,y,k;
    std::string input;
    cout << "Enter number k (k and P-1 should be co-prime): ";
    cin >> k;
    cout << "Enter your message: ";
    cin.ignore();
    std::getline(std::cin,input);
    l=input.size();
    cout << "Enter B's public key: ";
    cin >> y;
    r=modulo(A,k,P);
    cout << "r= " << r << "\n";
    cout << "Your encrypted message: ";
    for (i=0;i<l;i++){
        s=(int)input[i]-31;
        e=(s*modulo(y,k,P)) % P;
        cout << e << " ";
    }
}

void receiving(int A, int P){
    int y,x,e;
    double r,b,d,s;
    string output;
    cout << "Enter your private key: ";
    cin >> x;
    y=modulo(A,x,P);
    cout << "Your public key is: ";
    cout << y << "\n";
    cout << "Enter r number: ";
    cin >> r;
    b=P-1-x;
    d=pow(r,b);
    cout << "Enter encrypted message from A: ";
    while (e!=0){
        cin >> e;
        if (e==0) break;
        else {
            s=fmod(e*d,P);
            output.push_back((char)(short int)(s+31));
        }
    }
    cout << "Decrypted message: " << output << "\n";
}
