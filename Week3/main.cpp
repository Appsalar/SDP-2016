#include <iostream>
#include "StackA.h"

int main()
{
	StackA<int> a;
	a.push(3);
	a.push(420);
	a.push(1337);
	a.pop();
	a.pop();
	a.pop();
	return 0;
}