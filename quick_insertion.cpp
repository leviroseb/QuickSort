#include<iostream>
#include<time.h>
using namespace std;


// PARA PODER REALIZAR LAS COMPARACIONES POR FAVOR DESMARCAR LOS FRAGMENTOS COMENTADOS 

void insertion_sort(int *A, int n) 
{
	
	int i, key, j;
	for (i = 1; i < n; ++i) 
	{
		key = A[i]; 
		j = i - 1; 
		while (j >= 0 && A[j] > key) 
		{
			A[j + 1] = A[j]; 
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

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

void quicksort_insertionsort(int *A, int p, int r){
    while(p<r){
        if(r-p<10){
            insertion_sort(A,r-p);
            break;
        }
        else{
            int pivot=particion(A,p,r);
            if(pivot-p<r-pivot){
                quicksort_insertionsort(A,p,pivot-1);
                p=pivot+1;
            }
            else{
                quicksort_insertionsort(A,pivot+1,r);
                r=pivot-1;
            }
        }
    }
}

/*void quicksort(int *A, int p, int r){
    
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
    int A[]={2,5,3,8,12,56,2,89,2,56,987,14,46,3,7,23,49,52,155,56};
    quicksort_insertionsort(A,0,19);
    for (int i=0;i<20;i++){
        cout<<A[i]<<endl;
    }
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
            A[i]=rand()%1000000;
        }
        
        copia(A,B,m);
        t0=clock();
        quicksort_insertionsort(A,0,m-1);
        t1=clock();
        tiempo1=(double(t1-t0)/CLOCKS_PER_SEC);
        cout<<tiempo1<<endl;
        t2=clock();
        quicksort(B,0,m-1);
        t3=clock();
        tiempo2=(double(t3-t2)/CLOCKS_PER_SEC);
        cout<<tiempo2<<endl;
        cout<<endl;
        m=m*10;
        delete [] A;
        delete [] B;
    }*/
}