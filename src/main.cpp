#include<bits/stdc++.h>
using namespace std;
int N, x[100], cot[100], d1[100], d2[100];

int soCaChXep = 0;

void Try(int i) {
    // duyet cac kha nang ma x[i]  co the nhan duoc 
    
    for (int j = 1; j <= N; j++) {
        //chuan bi gan x[i]=j

        if (cot[j] == 1 && d1[i - j + N] == 1 && d2[i + j - 1] == 1) {  
            x[i] = j; 
            cot[j] = d1[i - j + N] = d2[i + j - 1] = 0;  
            if (i == N) {
                soCaChXep ++;  
            } else {
                Try(i + 1);  
            }
                     cot[j] = d1[i - j + N] = d2[i + j - 1] = 1;
        }
    }
}

int main() {
    cout<<"Nhap vao N quan hau: ";
        cin >> N; 
        soCaChXep = 0; 
        for (int i = 1; i <= N; i++) {
            cot[i] = 1;
        }
        for (int i = 0; i <= 2 * N; i++) {
            d1[i] = 1;
            d2[i] = 1;
        }
        Try(1); 
        cout<<"So cach xep la: ";
        cout << soCaChXep<< endl; 
    return 0;
}
