#include<iostream>
using namespace std;



class SortingAlgorithm
{
    public : 
         
           void Display(int Arr[],int iSize);
           void InsertionSort(int Arr[],int iSize);
           
      
};

void SortingAlgorithm :: Display(int Arr[],int iSize)
{
    int i = 0;
    cout<<"\nInsertion Sorted Array Is :\n";
    for(i = 0; i<iSize; i++)
    {
        cout<<Arr[i]<<endl;
    }
}

void SortingAlgorithm :: InsertionSort(int Arr[],int iSize)
{
   int i = 0;
   int j = 0;
   int key = 0;
   
   for(i = 0; i<iSize; i++)
   {
       key = Arr[i];
       j = i-1;
        
      while(j>=0 && key < Arr[j])
      {
          Arr[j+1] = Arr[j];
          j--;
      }  

      Arr[j+1] = key;


    }
   
     Display(Arr,iSize);
  
}

int main()
{
   int Arr[] = {7,8,3,1,2};

    int iSize = sizeof(Arr)/sizeof(Arr[0]);

   SortingAlgorithm *obj = new SortingAlgorithm();

   obj->InsertionSort(Arr,iSize);


   return 0;


}
