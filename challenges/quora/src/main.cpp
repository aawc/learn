#include <stdio.h>
#include "02_TypeAhead.cpp"

int main(int argc, char **argv)
{
	TypeAhead* typeAhead = new TypeAhead;
	delete typeAhead; typeAhead = NULL;
	return 0;
}