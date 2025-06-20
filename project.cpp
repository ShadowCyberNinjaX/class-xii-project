#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// A stack to store operators 
struct Stack 
{ 
int top; 
int size; 
char *arr; 
}; 
// Create a stack 
struct Stack* createStack(int size) 
{ 
struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
stack->top = -1; 
stack->size = size; 
stack->arr = (char*)malloc(stack->size * sizeof(char)); 
return stack; 
} 
// Push an element to the stack 
void push(struct Stack* stack, char c) 
{ 
stack->arr[++stack->top] = c; 
} 
// Pop an element from the stack 
char pop(struct Stack* stack) 
{ 
return stack->arr[stack->top--]; 
} 
// Check if the stack is empty
int isEmpty(struct Stack* stack) 
{ 
return stack->top == -1; 
} 
// Check if the operator is higher precedence than the top of the stack 
int isHigherPrecedence(char c, char top) 
{ 
switch (c) 
{ 
case '+': 
case '-': 
return (top == '+' || top == '-'); 
case '*': 
case '/': 
return (top == '+' || top == '-' || top == '*' || top == '/'); 
case '^': 
return (top == '+' || top == '-' || top == '*' || top == '/' || top == '^'); 
default: 
return 0; 
} 
} 
// Convert infix to postfix 
void infixToPostfix(char *infix, char *postfix) 
{ 
struct Stack* stack = createStack(strlen(infix)); 
int i, j; 
i = j = 0; 
while (infix[i] != '\0') 
{ 
if (isalnum(infix[i]))
postfix[j++] = infix[i++]; 
} 
else if (infix[i] == '(') 
{ 
push(stack, infix[i++]); 
} 
else if (infix[i] == ')') 
{ 
while (!isEmpty(stack) && stack->arr[stack->top] != '(') 
{ 
postfix[j++] = pop(stack); 
} 
if (!isEmpty(stack)) 
{ 
pop(stack); // pop the '(' 
} 
i++; 
} 
else // operator 
{ 
while (!isEmpty(stack) && isHigherPrecedence(infix[i], stack->arr[stack->top])) 
{ 
postfix[j++] = pop(stack); 
} 
push(stack, infix[i++]); 
} 
} 
while (!isEmpty(stack)) 
{
postfix[j++] = pop(stack); 
} 
postfix[j] = '\0'; 
} 
// Convert infix to prefix 
void infixToPrefix(char *infix, char *prefix) 
{ 
// Reverse the infix expression 
int i, j; 
i = j = strlen(infix) - 1; 
char revInfix[strlen(infix)]; 
while (i >= 0) 
{ 
revInfix[j--] = infix[i--]; 
} 
// Convert the reversed infix to postfix 
infixToPostfix(revInfix, prefix); 
// Reverse the postfix expression to get the prefix expression 
i = j = 0; 
char revPrefix[strlen(prefix)]; 
while (prefix[i] != '\0') 
{ 
revPrefix[j++] = prefix[i++]; 
} 
revPrefix[j] = '\0'; 
// Copy the reversed prefix expression to the prefix variable 
strcpy(prefix, revPrefix); 
} 
// Print the postfix expression 
void printPostfix(char *postfix)
{ 

} 
// Print the prefix expression 
void printPrefix(char *prefix) 
{ 
printf("Prefix expression: %s\n", prefix); 
} 

void prefixtoinfix()
{
#include <string.h>
#include <ctype.h>
#include <conio.h>
char opnds[50][80],oprs[50];
int  topr=-1,topd=-1;
pushd(char *opnd)
{
    strcpy(opnds[++topd],opnd);
}
char *popd()
{
    return(opnds[topd--]);
}
 
pushr(char opr)
{
    oprs[++topr]=opr;
}
char popr()
{
    return(oprs[topr--]);
}
int empty(int t)
{
    if( t == 0) return(1);
    return(0);
}
 
void main()
{
    char prfx[50],ch,str[50],opnd1[50],opnd2[50],opr[2];
    int i=0,k=0,opndcnt=0;
    clrscr();
    printf("Give an Expression = ");
    gets(prfx);
    printf(" Given Prefix Expression : %s\n",prfx);
    while( (ch=prfx[i++]) != '\0')
    {
	if(isalnum(ch))
	{
	    str[0]=ch; str[1]='\0';
	    pushd(str); opndcnt++;
	    if(opndcnt >= 2)
	    {
		strcpy(opnd2,popd());
		strcpy(opnd1,popd());
		strcpy(str,"(");
		strcat(str,opnd1);
		ch=popr();
		opr[0]=ch;opr[1]='\0';
		strcat(str,opr);
		strcat(str,opnd2);
		strcat(str,")");
		pushd(str);
		opndcnt-=1;
	    }
	}
	else
	{
	    pushr(ch);
	    if(opndcnt==1)opndcnt=0;  /* operator followed by single operand*/
	}
    }
    if(!empty(topd))
    {
	strcpy(opnd2,popd());
	strcpy(opnd1,popd());
	strcpy(str,"(");
	strcat(str,opnd1);
	ch=popr();
	opr[0]=ch;opr[1]='\0';
	strcat(str,opr);
	strcat(str,opnd2);
	strcat(str,")");
	pushd(str);
    }
    printf(" Infix Expression: ");
    puts(opnds[topd]);
    getch();
}
}

void postfixtoinfix()
{
	#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Global Variable
char stack[50];
int top=-1;
//Function to Push Elements into Stack
void push(char ch)
{
    stack[++top]=ch;
}
//Function to Pop Element From The Stack
char pop()
{
    return stack[top--];
}
//function to convert from postfix to infix
void convert(char exp[])
{
    int l,i,j=0;
    char tmp[20];
    strrev(exp);
    l=strlen(exp);
    for(i=0;i<50;i++){
        stack[i]='\0';
    }
    printf("\nThe Infix Expression is : : ");
    for(i=0;i<l;i++){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
            push(exp[i]);
        else{
            tmp[j++]=exp[i];
            tmp[j++]=pop();
        }
    }
    tmp[j]=exp[top--];
    strrev(tmp);
    puts(tmp);
}
//Main Function
int main()
{
    char exp[50];
    //taking postfix expression
    printf("\nEnter the Postfix Expression : : ");
    gets(exp);
    //calling the function to convert the expression
    convert(exp);
    return 0;
}
}


int main()
{
 int choice;
 while(1)
 {
 	printf("\nEnter 1 to convert infix to postfix");
 	printf("\nEnter 2 to convert infix to prefix");
 	printf("\nEnter 3 to convert prefix to infix");
 	printf("\nEnter 4 to convert postfix to infix");
 	printf("\n\nEnter your choice::");
 	scanf("%d",&choice);
 	
 	switch(choice)
 	{
 	  	case 1:
 	  		{
				printf("\nEnter the infix expression:");
 	  			gets(infix);
 	  			infixToPostfix(char,char);
 	  			printf("Postfix expression: %s\n", postfix); 	
				break;
			}
		case 2:
			{
				printf("\nEnter the infix expression:");
 	  			gets(infix);
 	  			infixToPrefix(char,char)
 	  			printf("Prefix expression: %s\n", prefix);
 	  			break;
			}
		case 3:
			{
				prefixtoinfix();
				break;		
			}
		case 4:
			{
				postfixtoinfix();
				break;
			}
		default :
		printf("\nWrong entry!!!!!!");	
	}
  }
  return 0;
