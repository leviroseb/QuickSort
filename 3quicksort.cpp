#include<iostream>
#include<time.h>
using namespace std;


// PARA PODER REALIZAR LAS COMPARACIONES POR FAVOR DESMARCAR LOS FRAGMENTOS COMENTADOS 

/*int particion(int *A, int p, int r){
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

void quicksort2(int *A, int p, int r){
    
    if (p<r){
        int q=particion(A,p,r);
        quicksort2(A,p,q-1);
        quicksort2(A,q+1,r);
    }
}
*/


void ThreePartition(int *A,int m,int n,int &inicio, int &fin){
    int pivot=A[m];
    inicio=m, fin=n;
    for(int i=inicio+1;i<=fin;i++){
        if(A[i]<pivot){
            swap(A[i],A[inicio]);
            inicio++;
        }
        else if(A[i]>pivot){
            swap(A[i],A[fin]);
            fin--;
            i--;
        }
    }
}

void quicksort(int *A, int m, int n){
    if(m>=n){
        return;
    }
    int inicio, fin;
    ThreePartition(A,m,n,inicio,fin);
    quicksort(A,m,--inicio);
    quicksort(A,++fin,n);
}

void copia(int *A, int *B, int n){
    for(int i=0;i<n;i++){
        B[i]=A[i];
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
    
      
       
    /*int n,m;
    unsigned t0,t1,t2,t3;
    double tiempo1,tiempo2;
    cout<<"numero de arreglos: ";
    cin>>n;
    cout<<"tamano inicial de arreglo";
    cin>>m;
    srand(time(NULL));
    for (int i=0;i<n;i++){
        int *A=new int[m];
        int *B=new int[m];
        for (int i=0;i<m;i++){
            A[i]=rand()%1000;
        }
        
        copia(A,B,m);
        t0=clock();
        quicksort(A,0,m-1);
        t1=clock();
        tiempo1=(double(t1-t0)/CLOCKS_PER_SEC);
        cout<<tiempo1<<endl;
        t2=clock();
        quicksort2(B,0,m-1);
        t3=clock();
        tiempo2=(double(t3-t2)/CLOCKS_PER_SEC);
        cout<<tiempo2<<endl;
        cout<<endl;
        m=m+10000;
        delete [] A;
        delete [] B;
    }*/
}