#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
   char *question;
   struct node *no;
   struct node *yes;
} node;

int yes_no(char *question)
{
   char answer[3];
   printf("%s? (y/n)",question);
   fgets(answer,3,stdin);
   return answer[0] == 'y';
}
node* create(char *question)
{
   node *i = malloc(sizeof(node));
   i->question = strdup(question);
   i->no = NULL;
   i->yes = NULL;
   return i;
}

void release(node *n)
{
   if(n)
   {
      if(n->no)
         release(n->no);
      if(n->yes)
         release(n->yes);
      if(n->question)
         free(n->question);
      free(n);   
   }
}

int main()
{
   char question[80];
   char suspect[20];
   node *start_node = create("Does suspect have a moustache");
   start_node->no = create("Loretta Barnsworth");
   start_node->yes = create("Vinny the Spoon");

   node *current;
   do
   {
      current = start_node;
      while(1)
      {
          if (yes_no(current->question))
          {
             if(current->yes)
             {
                current = current->yes;
             }
             else
             {  
                printf("SUSPECT IDENTIFIED\n");
                break;
             }
          }
          else if (current->no)
          {
             current = current->no;
          }
          else
          { 
             /*Make a yes-no node for new suspect*/
             printf("Enter a suspect name? ");
             fgets(suspect,20,stdin);
             node *yes_node = create(suspect);
             current->yes = yes_node;

             /*Create no node for a copy of the question*/
             node *no_node = create(current->question);
             current->no = no_node;
             
             /*Question for this suspect*/
             printf("Give the question TRUE for %s not for %s",suspect,current->question);
             fgets(question,80,stdin);
             free(current->question);
             current->question = strdup(question);
             break;
          }
      }
   } while(yes_no("Run Again"));
   
   release(start_node);

   return 0;
}

