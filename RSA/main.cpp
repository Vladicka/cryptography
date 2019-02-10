#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

void receiving();
void sending();
int Euclid(int e, long int z);
double inverse (long int e, long int z);
double modulo (double a, long int b, long p);
void coprime(long int z);


int main()
{
    short int m;
    cout << "Enter 0 for sending message and 1 for receiving one: ";
    cin >> m;
    if (m==0) sending();
    else receiving();
    system("pause");
}

void receiving(){
    short int m;
    int p=0,q=0,e,w;
    long int z=0,d,n;
    double s;
    char a='y', k='y';
    string output;
    while(a=='y') {
        if (k=='y'){
            cout << "Enter 2 prime numbers P and Q: ";
            cin >> p >> q;
            n=p*q;
            z=(p-1)*(q-1);
            //cout << "N=" << (n=p*q) << "\n";
            //cout << "Z=" << (z=(p-1)*(q-1)) << "\n";
            cout << "You need to define E number (it'll be your public key; E<" << z << "; E and "<< z << " should be co-prime)" << "\n";
            cout << "Enter E number or enter 0 to see list of valid values for E: ";
            cin >> e;
            if (e==0){
                coprime(z);
                cout << "Enter E: ";
                cin >> e;
            }
            while (Euclid(e,z)!=1){
                cout << "Warning! " << e << " and " << z << " are not co-prime! Enter e again: ";
                cin >> e;
            }
            cout << "Now you need to define your private key D." << "\n" << "It can be calculated for you (enter 0) or you can input it manually (enter 1): ";
            cin >> m;
            if (m==0) d=inverse(e,z);
            else{
                cout << "Enter D: ";
                cin >> d;
                while ((d*e)%z!=1){
                    cout << "Unfortunately your D value is not proper. Enter 0 to calculate D or 1 to try again: ";
                    cin >> m;
                    if (m==0){
                        d=inverse(e,z);
                        break;
                    }
                    else{
                        cout << "Enter D:";
                        cin >>d;
                    }
                }
            }
        }
        cout << "D: " << d << "\n";
        cout << "Your public key is " << e << " " << n << "\n" << "Input encrypted message: ";
        while (1){
            cin >> s;
            if (s==0) break;
            w=(int)modulo(s,d,n);
            output.push_back((char)(w+31));
            //cout << w << " ";
        }
        cout << "Encrypted message: " << output;
        output.erase();
        cout << "\n" << "Do you want to decrypt another message? (y/n)";
        cin >>a;
        if (a=='n') break;
        cout << "Do you need to change your keys? (y/n):";
        cin >> k;
    }
}


void sending(){
    int e,n,s,i;
    char a='y',k='y';
    string input;
    while (a=='y'){
        if (k=='y'){
            cout << "Enter public key from receiver: ";
            cin >> e >> n;
        }
        cout << "Enter your message: ";
        cin.ignore();
        getline(cin,input);
        cout << "Encrypted message: ";
        for (i=0;i<input.size();i++){
            s=(double)input[i]-31;
            //cout << s << " ";
            cout << (long int)modulo(s,e,n) << " ";
        }
        cout << "\n" << "Do you want to send another message? (y/n):";
        cin >> a;
        if (a=='n') break;
        cout << "Do you need to change public key? (y/n):";
        cin >> k;
    }
}

int Euclid(int e, long int z){
    int c;
    while (1){ // Yes, it's infinite loop actually, but don't worry it does have its end.
        c=z%e;
        if (c==0) break;
        z=e;
        e=c;
    }
    return(e);
}

double inverse (long int e, long int z){
    double a=z ,c=0;
    z++;
    while (1){
        c=fmod(z,e);
        //cout << "c:" << c << " ";
        if (c==0) break;
        z=z+a;
        //cout << "z:" << z;
    }
    return(z/e);
}

double modulo (double a, long int b, long int p){
    long int i=0;
    double c=1, f;
    //cout << i << " " << b;
    f=fmod(a,p);
        for (i=0;i<b;i++){
            c=fmod(fmod(c,p)*f,p);
            //cout << c << " ";
            //c=((c%p)*(a%p)) % p;
            //if (i>500 && i<510 || i>50000 && i<50010 || i>500000 && i<500010) cout << "c: " << c;
   }
   //cout << c << " ";
   return(c);
}

void coprime(long int z){
    long int i=2;
    short int j=0;
    char a='y';
    cout << "List of E values: ";
    while (a=='y'){
        if (Euclid(i,z)==1){
            cout << i << "; ";
            j++;
        }
        if (i==z-1){
            cout << "All valid E values have been found.";
            break;
        }
        i++;
        if (j==10){
            j=0;
            cout << "\n" << "Do you need more values? (y/n): ";
            cin >> a;
            if (a=='n') break;
        }
    }
}
