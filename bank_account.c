//PROGRAM TO ADD NEW RECORD MODIFY EXISTING RECORD,DELETE EXISTING RECORD,DISPLAY ALL RECORDS FROM ACC.DAT BINARY FILE WHICH CONTAINS ACCOUNT TYPE DATA
//1.ACCOUNT NUMBER MUST BE UNIQUE
//2.BALANCE MUST BE ABOVE 500
#include<stdio.h>
typedef struct account
{
	int acno;
	int acnm[15];
	int opnbal;
	int state;//0-deleted 1-vaild
}ACC;
FILE *fa;
ACC ac;
//function to search ACC record 
//return-1 if not found otherwise return begin byte number of found record
int search(int no)
{
	int pos=0;
	rewind(fa);
	while(1)
	{
		fread(&ac,sizeof(ACC),1,fa);
		if(feof(fa))
		{
			pos=-1;
			break;
		}
		if(ac.acno==no)
			break;
		pos=ftell(fa);
	}
	return pos;
}
//function to add new ACC type record
void add()
{
	int no,pos;
	printf("\nACCOUNT NO:");
	scanf("%d",&no);
	if(no<=0)
	{
		printf("\n invalid number.");
		return;
	}
	pos=search(no);
	if(pos>=0)
	{
		printf("\nRecord EXISTS:");
		return;
	}
	ac.acno=no;
	printf("\nA/C Holder name:");
	scanf("%s",ac.acnm);
	do
	{
		printf("\nOpening Balance:");
		scanf("%d",&ac.opnbal);
	}while(ac.opnbal<500);
	ac.state=1;

	fwrite(&ac,sizeof(ACC),1,fa);
	printf("\nRecord Inserted");
	return;
}
//function to modify existing account record
void mod()
{
	int pos,no;
	printf("\n A/C No:");
	scanf("%d",&no);
	if(no<=0)
	{
		printf("\nInvalid Input");
		return;
	}
	pos=search(no);
	if(pos==-1)
	{
		printf("\nNo such record!!");
		return;
	}
	if(ac.state==0)
	{
		printf("\nDeleted Record.");
		return;
	}
	fseek(fa,pos,SEEK_SET);//shifts file ptr fa to byte pos from begin of file that is to begin of the found record
	ac.acno=no;
	printf("\nA/C Name:");
	scanf("%d",&ac.acnm);
	do
	{
		printf("\nOpening Balance:");
		scanf("%d",&ac.opnbal);
	}while(ac.opnbal<500);
	ac.state=1;
	fwrite(&ac,sizeof(ACC),1,fa);
	printf("\nRecord Modified");
	return;
	
}
void del()
{
	int pos,no;
	printf("\n A/C No:");
	scanf("%d",&no);
	if(no<=0)
	{
		printf("\nInvalid Input");
		return;
	}
	pos=search(no);
	if(pos==-1)
	{
		printf("\nNo such record!!");
		return;
	}
	if(ac.state==0)
	{
		printf("\nDeleted Record.");
		return;
	}
	fseek(fa,pos,SEEK_SET);//shifts file ptr fa to byte pos from begin of file that is to begin of the found record
	ac.state=0;
	fwrite(&ac,sizeof(ACC),1,fa);
	printf("\nRecord Deleted");
	return;
}
//function to display ALL ACCOUNT DATA
void display()
{
	rewind(fa);
	printf("\nA/C Data\n");
	while(1)
	{
		fread(&ac,sizeof(ACC),1,fa);
		if(feof(fa))
			break;
		printf("\n%5d%-15s%6d%d",ac.acno,ac.acnm,ac.opnbal,ac.state);
	}
	return;
}
int main()
{
	int opt;
	fa=fopen("ACC.DAT","r+b");
	if(fa=NULL)
	{
		fa=fopen("ACC.DAT","Wb");
		fclose(fa);
		fa=fopen("ACC.DAT","r+b");
	}
	while(1)
	{
		printf("\nMENU\n1.ADD\n2.MOD\n3.DEL\n4.DISPLAY\n5.EXIT\nOPTION:");
		scanf("%d",&opt);
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				add();break;
			case 2:
				mod();break;
			case 3:
				del();break;
			case 4:
				display();
		}
	}
	fclose(fa);
	return 0;
}
