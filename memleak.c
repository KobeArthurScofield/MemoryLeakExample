
//MemLeaking example

/*------------------------------------------------------------------------------
Some memory-compression defence added.

WARNING!!
Be careful when the program is running. It will eat up all your free memory and
free disk space where the swap file exists.
^_^
------------------------------------------------------------------------------*/

#include <stdlib.h>

struct linklist
{
	struct linklist *next;
	struct linklist *prev;
};

typedef struct linklist mkbody;

int leakV1();
int leakV2();

int main()
{
	leakV2();
	return 0;
}

int leakV1()
{
	while (1)
		malloc(sizeof(char));
	return 0;
}

int leakV2()
{
	mkbody *curr, *up, *down;
	curr = malloc(sizeof(mkbody));
	curr->next = NULL;
	curr->prev = NULL;
	while (1)
	{
		if ((down = malloc(sizeof(mkbody))) != NULL)
		{
			curr->next = down;
			up = curr;
			curr = down;
			curr->prev = up;
			curr->next = NULL;
		}
		else malloc(sizeof(char));
	}
	return 0;
}