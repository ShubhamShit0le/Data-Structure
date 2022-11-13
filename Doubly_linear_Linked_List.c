#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE,**PPNODE;


void InsertFirst(PPNODE Head,int no)
{
  PNODE newn = NULL;

  newn = (PNODE)malloc(sizeof(NODE));
  newn->data=no;
  newn->next=NULL;
  newn->prev=NULL;

  if(*Head == NULL)
  {
      *Head = newn;
  }
  else
  {
    newn->next=*Head;
    (*Head)->prev=newn;
    *Head=newn;
  }
  
}

void InsertLast(PPNODE Head,int no)
{
   PNODE newn = NULL;
   PNODE temp = *Head;

   newn =(PNODE)malloc(sizeof(NODE));
   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;


   if(*Head == NULL)
   {
      *Head = newn;
   }
   else
   {
    while (temp -> next != NULL)
    {
           temp = temp->next;
    }

      temp->next=newn;
      newn->prev=temp;
    
   }
}

void Display(PNODE Head)
{
    printf("NULL<=>");
   while (Head != NULL)
   {
     printf("|%d|<=>",Head->data);
     Head = Head->next;
   }
   printf("NULL\n");

}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head !=NULL)
    {
        iCnt++;
        Head = Head->next;
        
    }
   return iCnt;
}

void InsertAtPos(PPNODE Head,int no,int iPos)
{
   int iSize = Count(*Head);
   int i = 0;
   PNODE newn = NULL;
   PNODE temp = *Head;

   if(iPos < 1 || iPos > iSize+1)
   {
      printf("INVALIDE POSITION\n");
      return;
   }
   else if(iPos == 1)
   {
      InsertFirst(Head,no);
   }
   else if(iPos == iSize+1)
   {
     InsertLast(Head,no);
   }
   else
   {
       newn = (PNODE)malloc(sizeof(NODE));
       newn->data=no;
      newn->next=NULL;
      newn->prev=NULL;

      for(i = 1; i<iPos-1; i++)
      {
        temp=temp->next;
      }

       newn->next=temp->next;
       newn->next->prev=newn;
       temp->next=newn;
       newn->prev=temp;

   }


}

void DeleteFirst(PPNODE Head)
{

   if(*Head == NULL)
   {
      return;
   }
   else if((*Head )-> next == NULL)
   {
      free(*Head);
      *Head == NULL;
   }
   else
   {
      *Head = (*Head)->next;
      free((*Head)->prev);
      (*Head) -> prev =NULL;
   }
 
}

void DeleteLast(PPNODE Head)
{
   PNODE temp = *Head;

   if(*Head == NULL)
   {
      return;
   }
   else if((*Head) ->next ==NULL)
   {
      free(*Head);
      *Head == NULL;
   }
   else
   {   
       while (temp -> next != NULL)
       {
          temp = temp->next;
       }

       temp -> prev -> next = NULL;
       free(temp);

       

       
   }

}

void DeleteAtPos(PPNODE Head,int iPos)
{

 
    int isize = Count(*Head);
    int i = 0;
     PNODE temp = *Head;  
    if(iPos < 1 || iPos >isize)
    {
      printf("\nInvalide Position\n");
      return;
    }
   
    if(iPos == 1)
    {
      DeleteFirst(Head);
    }
    else if(iPos == isize)
    {
      DeleteLast(Head);
    }
    else
    {
      
      for(i =1; i<iPos-1; i++)
      {
          temp = temp -> next;
      }

       temp -> next = temp->next->next;
     free(temp->next-> prev);
     temp->next-> prev= temp;

    }




}



int main()
{
   PNODE first = NULL;

   InsertFirst(&first,30);
   InsertFirst(&first,20);

   InsertLast(&first,40);
   InsertLast(&first,50);

   InsertAtPos(&first,25,4);

   Display(first);

   printf("%d\n",Count(first));


   // DeleteFirst(&first);
   // DeleteLast(&first);
   DeleteAtPos(&first,0);
  Display(first);
   printf("%d\n",Count(first));
   

  return 0;

}