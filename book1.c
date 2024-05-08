#include"book.h"
int main()
{
	struct book b;
	input(&b); //call by refernce
	display(b);//call by value
	return;
}
