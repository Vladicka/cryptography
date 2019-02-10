#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <locale>
#include <windows.h>
#include <stdio.h>
using namespace std;

void random(char A[5][5]);
void print(char A[5][5]);
char sq1[5][5]={{'þ','à','á','ö','ä'},{'å','ô','ã','õ','é'},{'ê','ë','ì','í','î'},{'ï','ÿ','ð','ñ','ò'},{'æ','â','ü','ù','ú'}};
char sq2[5][5]={{'þ','à','á','ù','ä'},{'å','ô','ã','õ','é'},{'ê','ø','ì','í','î'},{'ï','ÿ','ð','÷','ò'},{'ó','û','ü','ý','ú'}};
char sq3[5][5]={{'þ','à','á','ö','ä'},{'å','ý','ã','è','é'},{'ê','ë','ì','í','û'},{'ï','ÿ','ð','ñ','ò'},{'æ','â','ü','ç','ú'}};
char sq4[5][5]={{'þ','à','á','ö','ä'},{'å','ô','ã','õ','é'},{'ê','ë','ì','í','î'},{'ï','ÿ','ð','ñ','ò'},{'æ','â','ü','ù','ú'}};

int main()
{
    srand((time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale( LC_ALL,"Russian" );
    short int i,j,k,s,x1,x2,y1,y2;
    string input;
    random(sq1);
    random(sq2);
    random(sq3);
    random(sq4);
    print(sq1);
    print(sq2);
    print(sq3);
    print(sq4);
    getline(std::cin, input);
    s=input.size();
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
    cout << input << "\n";
    system("pause");
}

void random(char A[5][5])
{
    short int i,j,k,l,m;
    char c;
    for (k=0;k<101;k++){
        i=rand() % 5;
        j=rand() % 5;
        l=rand() % 5;
        m=rand() % 5;
        c=A[i][j];
        //cout << i << ","<< j << A[i][j] << "; " << l << "," << m << "; ";
        A[i][j]=A[l][m];
        A[l][m]=c;
    }
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
