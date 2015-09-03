#include<stdio.h>

struct stack
{
	int ex[100];
	int top;
}s;

void push(int item)
{
	s.top = s.top+1;
	s.ex[s.top] = item;
}

int pop()
{
	int temp;
	if(s.top == -1)
	{
	    
	}
	{temp = s.ex[s.top];
	s.top = s.top-1;
	return temp;}
}


int isOperator(char ch)
{
	if(ch == '+' || ch == '-' ||ch == '*' ||ch == '/')
	{
		return 1;
	}
	return 0;
}

int isOperand(char ch)
{
	if(ch>='0' && ch<='9')
	{
		return 1;
	}
	return 0;
}
int main()
{
    int a,b,i;
	char str[1000];
	s.top = -1;
	printf("Enter postfix expression :\n");
	scanf("%s",str);
	while(str[i]!='\0')
	{
		if(isOperand(str[i]))
		{
			push(str[i] - '0');
			
		}
	    else if(isOperator(str[i]))
		{
			a = pop();
			b = pop();
			 switch(str[i])
   			{
   				case '+':push(b+a);break;
   				case '-':push(b-a);break;
   				case '*':push(b*a);break;
   				case '/':push(b/a);break;
   			}

		}
		i++;
	}
	printf(" = %d \n",s.ex[s.top]);
	return 0;
}