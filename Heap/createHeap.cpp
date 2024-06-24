//Create Heap
#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int a[101];
    int size;
    Heap(){
        size=0;
    }
    void insert(int value){
        size=size+1;
        int index=size;
        a[index]=value;
        while(index>1){
            int parentIndex=index/2;
            if(a[index]>a[parentIndex]){
                swap(a[index],a[parentIndex]);
                index=parentIndex;
            }else{
                break;
            }
        }
    }
    int deletion(){
        int ans=a[1];
        a[1]=a[size];
        size--;
        int index=1;
        while(index<size){
            int left=2*index;
            int right=2*index+1;

            int largest=index;
            if(left<size && a[largest]<a[left]){
                largest=left;
            }
            if(right<size && a[largest]<a[right]){
                largest=right;
            }
            if(largest==index){
                break;
            }else{
                swap(a[largest],a[index]);
                index=largest;
            }
        }
        return ans;
    }
};
int main(){
    Heap h;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);
   
    for(int i=1;i<=h.size;i++){
        cout<<h.a[i]<<" ";
    }
    cout<<endl;
    cout<<h.deletion()<<endl;
}