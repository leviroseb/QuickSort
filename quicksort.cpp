#include<iostream>
#include<time.h>
using namespace std;


int particion(int *A, int p, int r){
    int x=A[r];
    int i=p-1;
    for (int j=p;j<r;j++){
        if(A[j]<=x){
            i+=1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(int *A, int p, int r){
    
    if (p<r){
        int q=particion(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

int main(){
    int n;
    srand(time(NULL));
    cout<<"Tamano del arreglo: ";
    cin>>n;
    int *A=new int[n];
    for (int i=0;i<n;i++){
        A[i]=rand()%100;
    }
    quicksort(A,0,n-1);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    delete [] A;
    return 0;
}