#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
string alphabet(string S, short int D[],short int k);
void decrypt();

char A[5][5]={{'r','f','e','v','g'},{'o','x','p','i','t'},{'k','q','b','y','w'},{'c','u','n','d','m'},{'j','l','s','a','h'}};
short int D[10]={0,1,2,3,4,5,6,7,8,9};
short int F[10]={0,1,2,3,4,5,6,7,8,9};
short int G[10]={0,1,2,3,4,5,6,7,8,9};

int main()
{
    string key, input, output, out;
    short int i,j,l,k,p=0,n;
    char B[5]={'A','D','F','G','X'};
    cout << "Enter your key: ";
    getline(std::cin, key);
    cout << "Enter your message: ";
    getline(std::cin, input);
    k=key.size();
    for (i=0;i<input.size();i++){
        if (input[i]==' ') input.erase(i,1);
    }
    l=input.size();
    while (l % k !=0){
        input.push_back(input[l-1]);
        l++;
    }
    for (i=0;i<5;i++){
        cout << "\n";
        for (j=0;j<5;j++){
            cout << A[i][j];
        }
    }
    for (p=0;p<l;p++){
        for (i=0;i<5;i++){
            for (j=0;j<5;j++){
                if (input[p]==A[i][j]){
                    out.push_back (B[i]);
                    out.push_back (B[j]);
                }
            }
        }
    }
    key=alphabet(key,D,k);
    j=0;
    for (i=0;i<2*l;i++){
        output.push_back (out[D[j]]);
        j++;
        if (j==k){
            for (j=0;j<k;j++){
                D[j]=D[j]+k;
            }
            j=0;
        }
    }
    p=0;
    cout << "\n" << "\n";
    for (i=0;i<k;i++){
        for (n=0;n<(2*l)/k;n++){
            cout << output[i+n*k];
        }
        cout << " ";
    }
    cout << "\n";
    decrypt();
    system("pause");
}

string alphabet(string S, short int D[],short int k){
    short int i,j,a;
    char c;
    for (i=0;i<k;i++){
        for (j=i+1;j<k;j++){
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

void decrypt(){
    char B[5]={'A','D','F','G','X'};
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
    key=alphabet(key,F,k);
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
