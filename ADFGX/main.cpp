#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;
void random(char A[5][5]);
string alphabet(string S, short int D[],short int k);

char A[5][5]={{'a','b','c','d','e'},{'f','g','h','i','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
short int D[10]={0,1,2,3,4,5,6,7,8,9};

int main()
{
    srand((time(NULL)));
    string key, input, output, out;
    short int i,j,l,k,p=0,n;
    char B[5]={'A','D','F','G','X'};
    cout << "Enter your key: ";
    getline(std::cin, key);
    cout << "Enter your message: ";
    getline(std::cin, input);
    k=key.size();
    //cout << k;
    l=input.size();
    //cout << l;
    for (i=0;i<l;i++){
        if (input[i]==' '){
            p++;
            //cout << p;
            for (j=i;j<l;j++){
                input[j]=input[j+1];
            }
        }
    }
    l=l-p;
    //cout << p;
    //cout << l;
    p=l-1;
    //cout << p;
    while (l % k !=0){
        input[l]=input[p];
        l++;
        if (l>input.size()) input.push_back (input[p]);
    }
    //cout << input;
    random(A);
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
                    //cout << B[i] << B[j];
                    out.push_back (B[i]);
                    out.push_back (B[j]);
                    //output[2*k]=B[i];
                    //output[2*k+1]=B[j];
                }
            }
        }
    }
    //for (i=0;i<2*l;i++){
    //cout << "\n" << output;
    //}
    key=alphabet(key,D,k);
    j=0;
    //cout << l;
    for (i=0;i<2*l;i++){
        output.push_back (out[D[j]]);
        //output[i]=out[B[j]];
        //cout << output[i];
        j++;
        if (j==k){
            for (j=0;j<k;j++){
                D[j]=D[j]+k;
            }
            j=0;
        }
    }
    //cout << output;
    //cout << key;
    //for (i=0;i<k;i++){
        //cout << D[i];
    //}
    p=0;
    cout << "\n" << "\n";
    //cout << l << "\n";
    for (i=0;i<k;i++){
        //p++;
        for (n=0;n<(2*l)/k;n++){
            //j=k*D[n]+i;
            //cout << A[k] << " " << i << " ";
            //cout << j << " ";
            cout << output[i+n*k];
            //<< "(" << i << ")";
        }
        cout << " ";
        //if (p==k){
            //i=i+2*k;
            //p=0;
        //}
    }
    system("pause");
}
void random(char A[5][5])
{
    int i,j,k,l,m;
    char c;
    for (k=0;k<101;k++){
        i=rand() % 5;
        j=rand() % 5;
        l=rand() % 5;
        m=rand() % 5;
        c=A[i][j];
        A[i][j]=A[l][m];
        A[l][m]=c;
    }
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
