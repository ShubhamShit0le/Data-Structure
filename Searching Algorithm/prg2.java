
import java.util.Scanner;

abstract class ArrayX
{
    public int Arr[];

    public ArrayX(int Size)
    {
        Arr = new int[Size];
    }

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter the elements : ");
        for(int i = 0; i < Arr.length; i++)
        {
            Arr[i] = sobj.nextInt();
        }
    }

    public void Display()
    {
        System.out.println("Elements are : ");
        for(int i = 0; i < Arr.length; i++)
        {
            System.out.println(Arr[i]);
        }
    }
    public abstract boolean LinearSearch(int iValue);
}

class Searching extends ArrayX
{
    public Searching(int Size)
    {
        super(Size);
    }

    public boolean LinearSearch(int iValue)
    {
        int i = 0;
        for(i = 0; i < Arr.length; i++)
        {
            if(Arr[i] == iValue)
                break;
        }

        if(i == Arr.length)
            return false;
        else
            return true;
    }
}

class prg2
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.print("Enter the size of array : ");
        int Size =  sobj.nextInt();

        Searching obj = new Searching(Size);
        
        obj.Accept();
        // obj.Display();

        System.out.println("Enter the number to search : ");
        int iNo = sobj.nextInt();

        boolean bRet = obj.LinearSearch(iNo);
        if(bRet == true)
        {
            System.out.println("Number is there in array");
        }
        else
        {
            System.out.println("Number is not there in array");
        }

        System.out.print("\n");
    }
}
