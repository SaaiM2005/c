#include<stdio.h>
struct student
{
	int no;
	char nm[15];
	int mrk;
};
int main()
{
	struct student p;
	struct student *q=&p;
	printf("\nRoll no:");
	scanf("%d",&q->no);
	printf("\n Name:");
	scanf("%c",q->nm);
	printf("\nMarks:");
	scanf("%d",&q->mrk);
	printf("\nStudent Data\nNo:%d\nName:%s\nMarks:%d",q->no,q->nm,q->mrk);
	return;
}
