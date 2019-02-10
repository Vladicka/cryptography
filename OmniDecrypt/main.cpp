#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale>
#include <windows.h>
#include <cmath>

using namespace std;

void caesar();
int shift(char a, int k); //Caesar;
void pairs();
void squares();
void matrix();
string alphabet(string S, short int D[]); //Matrix, ADFGX;
void adfgx();
void vigenere();
void elgamal();
double modulo(double a, long int b, long int p); //ElGamal, RSA;
void rsa();
int primeattack(int p,double n);//              }
int primecheck(double a);//                     } RSA;
double inverse (long int e, long int z);//      }

int main()
{
    short int a;
    cout << "1. Caesar" << "\n" << "2. Pairs" << "\n" << "3. 4 squares" << "\n" << "4. Matrix" << "\n";
    cout << "5. ADFGX" << "\n" << "6. Vigenere" << "\n" << "7. ElGamal" << "\n" << "8. RSA" << "\nEnter number: ";
    cin >> a;
    cout << "\n";
    cin.ignore();
    switch (a){
        case 1: { caesar(); break; }
        case 2: { pairs(); break; }
        case 3: { squares(); break; }
        case 4: { matrix(); break; }
        case 5: { adfgx(); break; }
        case 6: { vigenere(); break; }
        case 7: { elgamal(); break; }
        case 8: { rsa(); break; }
    }
    system("pause");
}

void caesar()
{
    string input;
    short int i,l,k=0;
    char q='n';
    cout << "Enter encrypted text: ";
    getline(cin,input);
    l=input.size();
    while(q=='n'){
        for (i=0;i<6;i++){
            cout << (char)shift(input[i],k);
        }
        cout << "\n" << "Can you read some word or part of the word?(y/n)";
        cin >> q;
        if (q=='y'){
            for (i=0;i<l;i++){
                cout << (char)shift(input[i],k);
            }
        }
        k++;
    }
}

int shift(char a, int k){
    int c;
    if (a==' ') return(32);
    c=(int)a-k;
    if (c+256<160) c=c+80;
    if (c+256>175 && c+256<224) c=c-48;
    return(c);
}

void pairs(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale( LC_ALL,"Russian" );
    string str1("æõìïêöèíëôîóñðéòç");
    string str2("åüøúäàþ¸÷áâùýÿãû-");
    string input;
    short int i,j,k,l;
    cout << "Enter encrypted message: ";
    getline(cin,input);
    l=input.size();
    for (i=0;i<l;i++){
        k=0;
        if (input[i]!=' '){
            for (j=0;j<17;j++){
                if (input[i]==str1[j]){
                    k=1;
                    if (str2[j]!='-'){
                        input[i]=str2[j];
                    }
                }
            }
            if (k==0){
                for (j=0;j<16;j++) {
                    if (input[i]==str2[j]){
                        input[i]=str1[j];
                        break;
                    }
                }
            }
        }
    }
    cout << input << "\n";
}

void squares(){
    char sq1[5][5]={{'n','d','s','k','v'},{'c','f','m','w','h'},{'i','a','g','r','l'},{'p','e','q','o','x'},{'b','j','t','u','y'}};
    char sq2[5][5]={{'u','t','w','p','n'},{'y','k','e','s','a'},{'c','h','l','r','g'},{'d','o','q','m','i'},{'b','j','x','f','v'}};
    char sq3[5][5]={{'v','y','a','p','n'},{'h','g','s','q','o'},{'x','k','b','i','m'},{'e','t','c','l','j'},{'r','f','d','u','w'}};
    char sq4[5][5]={{'d','s','q','o','y'},{'t','p','m','a','j'},{'r','w','x','i','e'},{'k','u','c','h','n'},{'v','l','f','g','b'}};
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

void matrix(){//no bugs with decryption now!
    short int i,j,k,l,h=0;
    std::string input,output,key1,key2;
    short int A[3]={0,1,2}, B[5]={0,1,2,3,4}, F[3]={0,1,2}, G[5]={0,1,2,3,4};
    cout << "Enter encrypted message: ";
    getline(cin,input);
    cout << "Enter keyword 1 (3 letters): ";
    getline(cin,key1);
    cout << "Enter keyword 2 (5 letters): ";
    getline(cin,key2);
    l=input.size();
    key1=alphabet(key1,A);
    key2=alphabet(key2,B);
    for (i=0;i<5;i++){
        if (i<3) F[A[i]]=i;
        G[B[i]]=i;
    }
    for (k=0;k<l;k=k+15){
        h=k;
        for (i=0;i<3;i++){
            for (j=0;j<5;j++){
                output.push_back(input[3*G[j]+F[i]+h]);
            }
        }
    }
    cout << output << "\n";
}

string alphabet(string S, short int D[]){
    short int i,j,l,a;
    char c;
    l=S.size();
    for (i=0;i<l;i++){
        for (j=i+1;j<l;j++){
            if (S[j]<S[i]){
                c=S[i];
                S[i]=S[j];
                S[j]=c;
                a=D[i];
                D[i]=D[j];
                D[j]=a;
            }
        }
    }
    return(S);
}

void adfgx(){
    char A[5][5]={{'r','f','e','v','g'},{'o','x','p','i','t'},{'k','q','b','y','w'},{'c','u','n','d','m'},{'j','l','s','a','h'}};
    char B[5]={'A','D','F','G','X'};
    short int F[10]={0,1,2,3,4,5,6,7,8,9};
    short int G[10]={0,1,2,3,4,5,6,7,8,9};
    string input,key,out,output;
    short int i,j=0,k,l,n,q;
    cout << "Enter encrypted message: ";
    getline(cin,input);
    for (i=0;i<input.size();i++){
        if (input[i]==' ') input.erase(i,1);
    }
    cout << "Enter your key: ";
    cin >> key;
    k=key.size();
    l=input.size();
    q=l/k;
    key=alphabet(key,F);
    for (i=0;i<k;i++){
        G[F[i]]=i;
    }
    for (i=0;i<q;i++){
        for (j=0;j<k;j++){
            output.push_back(input[q*G[j]+i]);
        }
    }
    i=0;
    j=0;
    for (n=0;n<l;n=n+2){
        for (k=0;k<5;k++){
            if (output[n]==B[k]) i=k;
            if (output[n+1]==B[k]) j=k;
        }
        cout << A[i][j];
    }
    cout << "\n";
}

void vigenere(){
    string input, key;
    short int i,j=0,k,l;
    cout << "Enter encrypted message: ";
    getline(cin, input);
    cout << "Enter your key: ";
    cin >> key;
    l=input.size();
    k=key.size();
    for (i=0;i<l;i++){
        input[i]=(unsigned int)((int)input[i]-(int)key[j]);
        if ((int)input[i]<0) input[i]=26-(int)input[i]*(-1);
        input[i]=((unsigned int)input[i] % 26)+97;
        j++;
        if (j==k) j=0;
    }
    cout << input << "\n";
}

void elgamal()
{
    int p=0,y=0;
    long int e=1;
    unsigned int s;
    double a=0,x,d,r,b=0;
    string output;
    cout << "Enter prime number P, number A and public key: ";
    cin >> p >> a >> y;
    for (x=2;x<p;x++){
        if (modulo(a,x,p)==y){
            cout << "Private key is " << x << "\n";
            break;
        }
    }
    b=p-1-x;
    cout << "Enter r number: ";
    cin >> r;
    d=pow(r,b);
    cin.ignore();
    cout << "Enter encrypted message: ";
    while (e!=0){
        cin >> e;
        if (e==0) break;
        else {
            s=fmod(e*d,p);
            output.push_back((char)(short int)(s+31));
        }
    }
    cout << "Decrypted message: " << output << "\n";
}

double modulo (double a, long int b, long int p){
    long int i=0;
    double c=1, f;
    f=fmod(a,p);
        for (i=0;i<b;i++){
            c=fmod(fmod(c,p)*f,p);
   }
   return(c);
}

void rsa()
{
    long int z,n,d;
    int i,p,q, e, w;
    double s;
    string output;
    cout << "Enter public key: ";
    cin >> e >> n;
    for (i=8; i<10000; i++)
    {
        if (primecheck(i)==1)
        {
            if (primeattack(i,n)==1) break;
        }
    }
    p=i;
    q=n/p;
    z=(p-1)*(q-1);
    d=inverse(e,z);
    cout << "\n" << "d=" << d << "\n";
    cout << "Enter encrypted message: ";
    while (1){
            cin >> s;
            if (s==0) break;
            w=(int)modulo(s,d,n);
            output.push_back((char)(w+31));
        }
        cout << "Decrypted message: " << output << "\n";
    system("pause");
}

int primeattack(int p, double n)
{
    double q;
    if (fmod(n,p)==0)
    {
        q=n/p;
        if (primecheck(q)==1){
            cout << "P=" << p << " Q=" << q;
            return(1);
        }
    }
}

int primecheck(double a)
{
    if (((fmod(a,2))!=0) && ((fmod(a,3))!=0) && ((fmod(a,5))!=0) && ((fmod(a,7))!=0)) return(1);
}

double inverse (long int e, long int z){
    double a=z ,c=0;
    z++;
    while (1){
        c=fmod(z,e);
        if (c==0) break;
        z=z+a;
    }
    return(z/e);
}
