#include<iostream>
using namespace std;


void heapify(int Arr[],int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2; 

    
    if(left < n && Arr[left] > Arr[largest])
    {
        largest = left;
    }

    if(right < n && Arr[right] > Arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(Arr[i],Arr[largest]);
         heapify(Arr,n,largest);
        
    }

   
}

void Heap_Sort_Algorithm(int Arr[],int n)
{
    for(int i = n/2-1; i>=0; i--)
    {
        heapify(Arr,n,i);

    }

    for( int i = n-1; i>=0; i--)
    {
        swap(Arr[0],Arr[i]);
         heapify(Arr,i,0);
    }

     
}


void PrintArray(int Arr[],int n)
{ 
    for(int i = 0; i<n; i++)
    {
       cout<<Arr[i]<<"\n";
    }

}




int main()
{
    int Arr[] = {40,10,30,50,60,15};
    int isize = sizeof(Arr)/sizeof(Arr[0]);

    Heap_Sort_Algorithm(Arr,isize);

    PrintArray(Arr,isize);


   return 0;



}