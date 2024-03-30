#include<iostream>
#define size 11
using namespace std;

string LCS(string a, string b, int m, int n){
    int arr[m+1][n+1];

    for(int i=0; i<=m; i++){
        arr[i][0]=0;
    }
    for(int j=0; j<=n; j++){
        arr[0][j]=0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1] == b[j-1]){
                arr[i][j]=1+arr[i-1][j-1];
            }
            else{
                arr[i][j]=max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    cout<<"LCS table is: "<<endl;
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }

    string lcs;
    int i=m, j=n;
    while(i>0 && j>0){
        if (a[i-1] == b[j-1]){
            lcs=a[i-1]+lcs;
            i--;
            j--;
        }
        else if(arr[i-1][j] > arr[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
return lcs;
}

int main(){
    string a="combination", b="competition";
    int m=a.length(), n=b.length();
    string lcsLength = LCS(a, b, m, n);
    string lcs = LCS(a, b, m, n);
    cout<<"LCS between 'combination' and 'competition': "<<lcs<<endl;
    cout<<"Length of LCS: "<<lcsLength<<endl;

return 0;
}
