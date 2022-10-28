#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    char data;
    struct stack *next;
};

void push(struct stack **top, char ch)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = ch;
    temp->next = NULL;
    if (*top == NULL)
    {
        *top = temp;
        return;
    }
    temp->next = *top;
    *top = temp;
}
char pop(struct stack **top)
{
    struct stack *t;
    char p;
    t = *top;
    if (t == NULL)
    {
        *top = NULL;
        return 0;
    }
    p = t->data;
    *top = t->next;
    return p;
}
int checkPrecedence(char ch)
{
    // printf("%c ", ch);
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else if (ch == '(' || ch == '{')
        return -1;
    else
        return -1;
}
void convert(char *ch)
{
    struct stack *top = NULL;
    int i = 0;
    while (ch[i] != '\0')
    {

        if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 0 && ch[i] <= 9))
        {
            printf("%c", ch[i]);
        }
        else if (ch[i] == '(' || ch[i] == '{')
            push(&top, ch[i]);
        else if (ch[i] == ')' || ch[i] == '}')
        {
            while (top->data != '(')
            {
                printf("%c", pop(&top));
            }
            pop(&top);
        }
        else
        {
            if (top == NULL)
                push(&top, ch[i]);
            else if (checkPrecedence(ch[i]) > checkPrecedence(top->data))
            {
                push(&top, ch[i]);
            }
            else
            {
                while (top != NULL && (checkPrecedence(ch[i]) <= checkPrecedence(top->data)))
                {
                    printf("%c", pop(&top));
                }
                push(&top, ch[i]);
            }
        }
        i++;
    }
    while (top != NULL)
        printf("%c", pop(&top));
}

int main()
{

    char Str[100] = "a*b(c-d/e)^l*m-n*p", RevStr[100];   //	pn*mled/c-b^*a*-
    int i, j, len;

    j = 0;
    len = strlen(Str);

    for (i = len - 1; i >= 0; i--)
    {
        if (Str[i] == '(' || Str[i] == '{')
            Str[i] = ')';
        else if (Str[i] == ')')
            Str[i] = '(';
        RevStr[j++] = Str[i];
    }
    RevStr[j] = '\0';

    // printf("\n String after Reversing = %s", RevStr);

    convert(RevStr);
    return 0;
}
