#include<iostream>
#include<algorithm>

using namespace std;


void Insert_Heap(int Arr[],int n, int iVal)
{
   
   n = n+1;
   Arr[n] = iVal;

   int i = n;   

   while(i> 1)
   {
    int Parent = i/2;
    int temp = 0;
    if(Arr[Parent] < Arr[i])
    {
         temp = Arr[i];
         Arr[i] = Arr[Parent];
         Arr[Parent] = temp;

         i  = Parent;

    }
    else
    {
        return;
    }
   }

     


}

void Delete_Heap(int Arr[],int n)
{
   Arr[1] = Arr[n];
   n=n-1;

  int   i = 1;

   while(i < n)
   {
      int left = Arr[2*i];
      int right = Arr[2*i+1];
      int Large = left>right ? 2*i : 2*i+1;

     int temp = 0;

      if(Arr[i] < Arr[Large])
      {
               temp = Arr[Large];
               Arr[Large] = Arr[i];
               Arr[i] = temp;

               i = Large;

      }
      else
      {
        return;
      }

   }


    
}

void Display(int Arr[],int n)
{
    int i = 0;
    for(i=0;i<n+4; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}




int main()
{
    int Arr[] = {50,30,40,10,5,20,30,60};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    int Val = 45;
     Insert_Heap(Arr,size,Val);
     Delete_Heap(Arr,size);
     Display(Arr,size);
     
     return 0;
}