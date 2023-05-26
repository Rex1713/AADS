#include<bits/stdc++.h>
using namespace std;

void min_heapify(int *a,int i,int n)
{
    int j,temp;
    temp=a[i];
    j=2*i;

    while(j<=n) 
    {
        if(j<n && a[j+1]<a[j])
        {
            j=j+1;

        }
        if(temp < a[j])
        {
            break;
        }
        else if(temp>=a[j])
        {
            a[j/2]=a[j];
            j=2*j;
        }
    }
    a[j/2]=temp;
}

void max_heapify(int *a,int i,int n){
        int j,temp;
    temp=a[i];
    j=2*i;

    while(j<=n) 
    {
        if(j<n && a[j+1]>a[j])
        {
            j=j+1;

        }
        if(temp > a[j])
        {
            break;
        }
        else if(temp<=a[j])
        {
            a[j/2]=a[j];
            j=2*j;
        }
    }
    a[j/2]=temp;
}

void buildMinHeap(int *a,int n) {
    for(int i=n/2;i>=1;i--) {
        min_heapify(a,i,n);
    }
}

void buildMaxHeap(int *a,int n)
{
    for (int i=n/2;i>=1;i--) {
        max_heapify(a,i,n);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++) {
        cout<<"MArks"<<(i)<<endl;
        cin>>a[i];
    }
    cout<<"Min heap";
    buildMinHeap(a,n);
    for(int i=1;i<=n;i++) {
        cout<<a[i];
    }
    cout<<"minimum is"<<a[1];
    cout<<endl;
    buildMaxHeap(a,n);
    for(int i=1;i<=n;i++) {
        cout<<a[i];
    }
    cout<<"MAx is"<<a[1]<<endl;



}