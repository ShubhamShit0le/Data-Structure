#include<iostream>
using namespace std;



class SortingAlgorithm
{
    public : 
         
           void Display(int Arr[],int iSize);
           void SelectionSort(int Arr[],int iSize);
           
      
};

void SortingAlgorithm :: Display(int Arr[],int iSize)
{
    int i = 0;
    cout<<"\nSelection Sorted Array Is :\n";
    for(i = 0; i<iSize; i++)
    {
        cout<<Arr[i]<<endl;
    }
}

void SortingAlgorithm :: SelectionSort(int Arr[],int iSize)
{
   int i = 0;
   int j = 0;
   int iSmall = 0;
   
   for(i = 0; i<iSize-1; i++)
   {
       iSmall = i;
    for(j = i+1; j<iSize; j++)
    {
        if(Arr[iSmall] > Arr[j])
        {
             iSmall = j;
        }
    }
    int temp = Arr[iSmall];
    Arr[iSmall] = Arr[i];
    Arr[i] = temp;
   
   }

     Display(Arr,iSize);
  
}

int main()
{
   int Arr[] = {7,8,3,1,2};

    int iSize = sizeof(Arr)/sizeof(Arr[0]);

   SortingAlgorithm *obj = new SortingAlgorithm();

   obj->SelectionSort(Arr,iSize);


   return 0;


}
