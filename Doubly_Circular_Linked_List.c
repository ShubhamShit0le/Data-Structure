#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,* PNODE,**PPNODE;


void Display(PNODE Head,PNODE Tail)
{
    printf("\n");
     
    if(Head == NULL && Tail == NULL)
    {
        return;
    } 

    do
    {
        printf("|%d|->",Head->data);
        Head = Head->next;
    }while(Head != Tail ->next );

    printf("\n");

}

int Count(PNODE Head,PNODE Tail)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        Head = Head->next;
    }while(Head != Tail->next);

    return iCnt;
}

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
   PNODE newn = NULL;
   newn=(PNODE)malloc(sizeof(NODE));
   newn->data = no;
   newn->next=NULL;
   newn->prev=NULL;

   if(*Head == NULL && *Tail==NULL)
   {
     *Head= newn;
     *Tail =newn;
   }
   else
   {
       newn->next = *Head;
       (*Head)->prev=newn;
        *Head=newn;
   }

   (*Tail)->next=*Head;
   (*Head)->prev=*Tail;

}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
     PNODE newn = NULL;

     newn= (PNODE)malloc(sizeof(int));
     newn->data=no;
     newn->next=NULL;
     newn->prev=NULL;

     if(*Head == NULL && *Tail==NULL)
     {
        *Head=newn;
        *Tail=newn;
     }
     else
     {
           (*Tail) -> next =newn;
           newn->prev =*Tail;
           *Tail=newn;

     }

     (*Tail)->next= *Head;
     (*Head) -> prev = *Tail;

}

 /// @brief 
/// @param Head 
/// @param Tail 
/// @param no 
/// @param iPos 
void InsertAtPos(PPNODE Head,PPNODE Tail,int no, int iPos)
{
   printf("Inside");
   
    PNODE temp = *Head;
    PNODE newn = NULL;
    int iSize = Count(*Head,*Tail);

    if((iPos < 1 )|| ( iPos > iSize+1))
    {
        printf("\nInvalide Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,Tail,no);
    }
    // else if(iPos == iSize+1)
    // {
    //     InsertLast(Head,Tail,no);
    // }
    // else
    // {
         
    //      newn=(PNODE)malloc(sizeof(NODE));
    //      newn->data = no;
    //      newn->next=NULL;
    //      newn->prev=NULL;
        
        
    //     for(int i = 1; i<iPos-1; i++)
    //     {
    //         temp=temp->next;
    //     }

    //     newn->next=temp->next;
    //     // temp->next->prev=newn;
    //     newn->next->prev=newn;
    //      temp->next = newn;
    //      newn->prev=temp;

    // }

         (*Tail) -> next =*Head;
         (*Head) -> prev = *Tail;
    
}






int main()
{
    PNODE first = NULL;
    PNODE last =  NULL;

    InsertFirst(&first,&last,20);
    InsertFirst(&first,&last,10);
    InsertLast(&first,&last,30);
    InsertLast(&first,&last,40);

    InsertAtPos(&first,&last,1,1);

    Display(first,last);
    printf("%d\n",Count(first,last));


    return 0;



}