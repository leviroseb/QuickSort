#include<iostream>
#include<time.h>
using namespace std;

// PARA PODER REALIZAR LAS COMPARACIONES POR FAVOR DESMARCAR LOS FRAGMENTOS COMENTADOS 



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

//funcion para verificar si un arreglo esta ordenado
bool ordenado(int *A, int n){
    for (int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            return false;
            break;
        }
        
    }
    return true;
}

void quicksort(int *A, int p, int r){
    //si el arreglo ya está ordenado, nos salimos de la función y terminamos la recursión
    if (ordenado(A,r-p)==true){
        return;
    }
    if (p<r){
        int q=particion(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

/*void quicksort2(int *A, int p, int r){
    
    if (p<r){
        int q=particion(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}*/

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