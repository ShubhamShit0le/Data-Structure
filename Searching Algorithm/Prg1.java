import java.util.Scanner;




class Prg1
{
	public static void main(String[] args) 
	{
	   Scanner sobj = new Scanner(System.in);

	   System.out.print("\mEnter The Size Of Array :");
	   int iSize = sobj.nextInt();

	   int Arr[] = new int[iSize];

	   System.out.print("\nEnter the elements :\n");
	   for(int i = 0; i < Arr.length;i++)
	   {
	   	Arr[i] = sobj.nextInt(); 
	   }


	}
}
