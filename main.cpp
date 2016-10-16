#include<stdio.h>
#include<string.h>
#include"sqstack.h"

#define MAXSIZE 30
#define TRUE 1

int priority(char ch)
{
	switch (ch)
	{
	case '(':
		return 1;
	case '[':
		return 2;
	case '{':
		return 3;
	default:
		return 0;
	}

}

int left_right(char ch)
{
	if (ch == '(' || ch == '{' || ch == '[')
		return -1;
	if (ch == ')' || ch == ']' || ch == '}')
		return 1;
}

int match(char p1, char p2)
{
	if (p1 == '(' && p2 == ')')
		return 1;
	else
		if (p1 == '[' && p2 == ']')
			return 1;
		else 
			if (p1 == '{' && p2 == '}')
				return 1;
			else
				return 0;
}

void bracket_match(char br[])
{
	SqStack s;
	char temp;
	int i = 0, j;
	s = InitStack(strlen(br) + 1);
	while (br[i] != '\0')
	{
		if (left_right(br[i]) == -1)
		{
			if (StackEmpty(s))
				Push(s, br[i]);
			else
			{
				j = GetTop(s, temp);
				if (priority(temp) >= priority(br[i]))
					Push(s, br[i]);
				else    //the priority is wrong
				{
					printf("ERROR:λ�� %d ���� %c ���ȼ�������ǰ�ߣ�\n", i + 1, br[i]);
					return;
				}
			} 
		}
		else 
			if (left_right(br[i]) == 1)
			{
				if (!Pop(s, temp))    //lack a left bracket
				{
					printf("ERROR:λ�� %d ���� %c ȱ�������Ӧ�������ţ�\n", i + 1, br[i]);
					return;
				}
				if (!match(temp, br[i]))    //no matching
				{
					printf("ERROR:λ�� %d ���� %c �������Ӧ�������Ų�ƥ�䣡\n", i + 1, br[i]);
					return;
				}
			}
		i++;
	}
	if (!StackEmpty(s))   //lack a right bracket
	{
		i = 0;
		while (s.top != s.data)
		{
			s.top--;
			i++;
		}
		j = GetTop(s, temp);
		printf("ERROR:λ�� %d �� %c ȱ�ٶ�Ӧ�������ţ�\n", i, temp);
		return;
	}
	else
		printf("������ȫƥ��!\n");
}

int main()
{
	int result;
	FILE *fp;
	char bracket[MAXSIZE];
	fp = fopen("test.txt", "r");
	for (int i = 0; fgets(bracket, 100, fp); i++)
	{
		printf("�� %d ��Ϊ��%s", i+1, bracket);
		bracket_match(bracket);
		printf("\n");
	}
	fclose(fp);
	return 0;
}