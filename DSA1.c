#include<stdio.h>
#include<string.h>

char s[100];
int top = -1;



void push(char a)
{
		top = top+1;
		s[top] = a;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return s[top--];
}


int operand(char x)
{
	if(x == '*' || x== '/' || x== '+' || x=='-' || x =='(' || x==')')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


int precedence(char x)
{
	if(x== '*' || x== '/')
	{
		return(2);
	}
	else if(x=='+' || x== '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void infixtopostfix(char a[100] , char b[100])
{
    int i=0,j=0;
    strcpy(b,a);
    char x ;
    printf("Postfix Expression");
    for(i=0;i<strlen(b);i++)

    {
        if(operand(b[i])==0)
            {
                if(operand(b[i+1])==0)
                {
                    printf("%c",b[i]);
                }
                else
                {
                    printf("%c " , b[i]);
                }
            }

        else if(b[i] == '(')
            {
                push(b[i]);
                }
        else if(b[i] == ')')
        {
            while((x = pop()) != '(')
                {
                    printf("%c ", x);
                }
        }
        else
        {
            while(precedence(s[top]) >= precedence(b[i]))
            {
                x=pop();
                printf("%c ",x);
            }
            push(b[i]);
        }
        b[i]++;
    }

    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}

int main()
{
	char infix[100], postfix[100];
	int total;
	printf("Enter infix expression");
	gets(infix);
    infixtopostfix(infix,postfix);


}
