// Heapify 
#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i){
    int index=i;
    int leftAns=2*i;
    int rightAns=2*i+1;
    int largest=index;
    if(leftAns<=n && a[largest]<a[leftAns]){
        largest=leftAns;
    }
    if(rightAns<=n && a[largest]<a[rightAns]){
        largest=rightAns;
    }
    if(largest!=index){
        swap(a[largest],a[index]);
        index=largest;
        heapify(a,n,index);
    }
}
void buildHeap(int a[],int n){
    for(int i=n/2;i>0;i--){
        heapify(a,n,i);
    }
}
void heapSort(int a[],int n){
    int index=n;
    while(n!=1){
        swap(a[1],a[n]);
    
        n--;
        heapify(a,n,1);
    }
}
int main(){
     int a[]={-1,12,15,13,11,14};
     int n=6;
    /*buildHeap(a,n);
     cout<<"Created Haeap"<<endl;
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
     }*/
     cout<<endl;
     heapSort(a,n);
     cout<<"Sorted Heap"<<endl;
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
     }
}