#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define NULL 0
struct list//defining structure
{
	char data[50];
	char no[50];
	char mail[75];
	int date,month,year;
	char street[50],district[25],state[25],pin[10];
	struct list *next;
};
typedef struct list *node;
//function prototype declaration
void insertfirst(char a[50],char no[50],char mail[75],int da,int mo,int yr,char street[50],char district[25],char state[25],char pin[25]);
void insertlast(char a[50],char no[50],char mail[75],int da,int mo,int yr,char street[50],char district[25],char state[25],char pin[25]);
void view();
node getnode();
void readnode(char a[50],char no[50],char mail[75],int da,int mo,int yr,node temp,char street[50],char district[25],char state[25],char pin[25]);
void display(node *p1,node *p3,int *count);
void sort();
void insert();
void readnodeuser(node temp);
void delete_();
void edit();
void insertinitial();
void displaymenu();
void search();
int conflictname(char a[30]);
int conflictno(char a[30]);
int welcome();
void thanks();
void error();
node head=NULL;

void main()
{
     extern node head;
     int check=0;
     char choice;
     clrscr();
     check=welcome();
     if(check==1)
     {
	insertinitial();
	sort();
	clrscr();
	do
	{
	    clrscr();
	    displaymenu();
	    printf("\n\t");
	    textcolor(LIGHTMAGENTA);
	    cputs("   ENTER AN OPTION.....:  ");
	    textcolor(LIGHTGRAY);
	    fflush(stdin);
	    scanf("%c",&choice);
	    switch(choice)
	    {
	    case '1'://search contact by contact name
		clrscr();
		printf("\n       ++++++++++++++++++++++++++++++++++++++++++\n");
		printf("       +                                        +\n");
		printf("       +            SEARCH CONTACT              +\n");
		printf("       +                                        +\n");
		printf("       ++++++++++++++++++++++++++++++++++++++++++\n\n");
		sort();
		search();
		printf("\n Press any key to continue....");
		getch();
		fflush(stdin);
		break;
	    case '2'://add a new contact
		clrscr();
		printf("\n       ++++++++++++++++++++++++++++++++++++++++++\n");
		printf("       +                                        +\n");
		printf("       +            ADDING CONTACT              +\n");
		printf("       +                                        +\n");
		printf("       ++++++++++++++++++++++++++++++++++++++++++\n\n");
		insert();
		sort();
		printf("\n Press any key to continue....");
		getch();
		fflush(stdin);
		break;
	    case '3'://delete a contact
		clrscr();
		printf("\n       ++++++++++++++++++++++++++++++++++++++++++\n");
		printf("       +                                        +\n");
		printf("       +            DELETE CONTACT              +\n");
		printf("       +                                        +\n");
		printf("       ++++++++++++++++++++++++++++++++++++++++++\n\n");
		delete_();
		sort();
		printf("\n Press any key to continue....");
		getch();
		fflush(stdin);
		break;
	    case '4'://edit a contact
		clrscr();
		printf("\n       ++++++++++++++++++++++++++++++++++++++++++\n");
		printf("       +                                        +\n");
		printf("       +             EDIT  CONTACT              +\n");
		printf("       +                                        +\n");
		printf("       ++++++++++++++++++++++++++++++++++++++++++\n\n");
		edit();
		sort();
		printf("\n Press any key to continue....");
		getch();
		fflush(stdin);
		break;
	    case '5'://display all the contact present in the data file
		clrscr();
		printf("\n       ++++++++++++++++++++++++++++++++++++++++++\n");
		printf("       +                                        +\n");
		printf("       +          DISPLAYING CONTACT            +\n");
		printf("       +                                        +\n");
		printf("       ++++++++++++++++++++++++++++++++++++++++++\n\n");
		view();
		printf("\n Press any key to continue....");
		getch();
		fflush(stdin);
		break;
	    case '6'://dispaly menu
		clrscr();
		displaymenu();
		break;
	    case '7'://exit from the program
		sort();
		clrscr();
		thanks();
		getch();
		exit(1);
		fflush(stdin);
		break;
	    default ://invalid option
		printf("\n       ++++++++++++++++++++++++++++++++++++++++++\n");
		printf("       +                                        +\n");
		printf("       +               MESSAGE                  +\n");
		printf("       +             ------------               +\n");
		printf("       +   Sorry...Enter a Valid Option...!!!   +\n");
		printf("       +                                        +\n");
		printf("       ++++++++++++++++++++++++++++++++++++++++++\n\n");
		printf("\n\n         Press any key to continue.....");
		getch();
		fflush(stdin);
		displaymenu();
		break;
	       }
	 }while(choice != '7');
    }
    else
	error();
    getch();
}
void insertfirst(char a[50],char no[50],char mail[75],int date,int month,int year,char street[50],char district[25],char state[25],char pin[25])
{
	node temp;
	extern node head;
	temp=getnode();//create a node
	readnode(a,no,mail,date,month,year,temp,street,district,state,pin);//insert values to node
	if(head==NULL)//in case of first contact
	{
	       head=temp;
	}
	else//adding at beginning of the list
	{
	    temp->next=head;
	    head=temp;
	}
}
void insertlast(char a[50],char no[50],char mail[75],int date,int month,int year,char street[50],char district[25],char state[25],char pin[25])
{
	node temp,p;
	extern node head;
	temp=getnode();//create a node
	readnode(a,no,mail,date,month,year,temp,street,district,state,pin);//insert values to node
	if(head==NULL)//in case of first contact
	{
		head=temp;
	}
	else//adding at end of the list
	{
		p=head;
		while(p->next!=NULL)//traversing to the end
			p=p->next;
		p->next=temp;
	}
}
void view()
{
	extern node head;
	node list=head;
	char mo[10];
	if(list==NULL)//in case of empty list
	{
		printf("\n MESSAGE :: ..........Contact Book Is Empty.........\n\n");
		printf("\n-----------------------------------------------------\n");
	}
	else//display list of contacts in table form
	{
		textcolor(6);
		printf("\n\n\t\t");
		cputs("  TABLE OF CONTACTS\n");
		textcolor(LIGHTGRAY);
		printf("\n____________________________________________________________________________");
		printf("\n\n   NAME\t\t|  CONTACT NO\t| BIRTHDAY\t| MAIL ID");
		printf("\n____________________________________________________________________________\n");
		for(;list!=NULL;list=list->next)
		{
		    switch(list->month)//month conversion
	    {
				case 1:
				    strcpy(mo,",Jan,");
				    break;
				case 2:
				    strcpy(mo,",Feb,");
				    break;
				case 3:
				    strcpy(mo,",Mar,");
				    break;
				case 4:
				    strcpy(mo,",Apr,");
				    break;
				case 5:
				    strcpy(mo,",May,");
				    break;
				case 6:
				    strcpy(mo,",Jun,");
				    break;
				case 7:
				    strcpy(mo,",Jul,");
				    break;
				case 8:
				    strcpy(mo,",Aug,");
				    break;
				case 9:
				    strcpy(mo,",Sep,");
				    break;
				case 10:
				    strcpy(mo,",Oct,");
				    break;
				case 11:
				    strcpy(mo,",Nov,");
				    break;
				case 12:
				    strcpy(mo,",Dec,");
				    break;
		    }
		    printf("\n   %s    \t|  %s \t| %d%s%d \t| %s\n",list->data,list->no,list->date,mo,list->year,list->mail);
		}
		printf("\n____________________________________________________________________________\n");
	}
}
node getnode()
{
	node temp;
	temp=(node)malloc(sizeof(struct list));//dynamically allocating space for a node
	return(temp);
}
void readnode(char a[50],char no[50],char mail[75],int da,int mo,int yr,node temp,char street[25],char district[25],char state[25],char pin[25])
{                           //copy values to the node created
	strcpy(temp->data,a);
	strcpy(temp->no,no);
	strcpy(temp->mail,mail);
	temp->date=da;
	temp->month=mo;
	temp->year=yr;
	strcpy(temp->street,street);
	strcpy(temp->district,district);
	strcpy(temp->state,state);
	strcpy(temp->pin,pin);
	temp->next=NULL;
}
void search()
{
	node p,p1,p2,p3,temp;
	char c,ans,ans1;int count=0,total=0,tot=0;
	if(head==NULL)//in case of empty list
	{
		printf("\n MESSAGE :: .....Contact List Is Empty........\n");
		printf("\n-----------------------------------------------\n");
	}
     else
     {
	for(temp=head;temp!=NULL;temp=temp->next)//find total number of contacts in the list
		total++;
	fflush(stdin);
	printf("\n Enter 1st Letter of the Contact to be searched...: ");
	scanf("%c",&c);
	fflush(stdin);
	for(p=head;p!=NULL;p=p->next)//traversing through the list
	{
		if((p->data[count]==c)||(p->data[count]==c-32))//checks contacts with initial letter of the contact
		{
			p1=p;//stores temporarily the first encountered contact with the given intial letter
			break;
		}
		else
		{
			tot++;
			continue;
		}
	}
	if(tot==total)//in case of no match
	{
		printf("\n MESSAGE :: Sorry...No Matches Found....!\n\n");
		printf("\n----------------------------------------------\n");
		fflush(stdin);
		return;
	}
	//display the list of contacts with same initial letter
	printf("\n_____________________________________________________________________________");
	printf("\n\n   NAME\t\t|  CONTACT NO\t| BIRTHDAY\t| MAIL ID");
	printf("\n_____________________________________________________________________________\n");
	for(p2=p1;p2!=NULL;p2=p2->next)
	{
		if((p2->data[count]==c)||(p2->data[count]==c-32))//checks contact with same intial letter
		{
			p3=p2;//stores last encountered contact in a variable
			printf("\n   %s    \t|  %s \t| %d-%d-%d \t| %s\n",p2->data,p2->no,p2->date,p2->month,p2->year,p2->mail);
		}
	}
	printf("______________________________________________________________________________\n");
	count++;
	fflush(stdin);
	printf("\n Continue The Current Search...(y/n)?  ");
	scanf("%c",&ans);
	if(ans=='y' || ans=='Y')//in case of further search
	{
		do
		{
			display(&p1,&p3,&count);//function to display specific contact
			fflush(stdin);
			printf("\n Continue The Current Search....(y/n)?  ");
			scanf("%c",&ans1);
		}while(ans1=='y' || ans1=='Y');
	}
     }
}
void display(node *p1,node *p3,int *count)//specified search
{
       node new1=*p1,a;
       node new3=*p3,f;
       char mo[20];
       int count1=*count,total=0,tot=0,i=1;
       char c1;
       for(a=new1;a!=new3->next;a=a->next)//total contact with same initial letter
		total++;
       fflush(stdin);
       printf("\n Enter The Next Letter Of The Contact To Be Searched..: ");
       scanf("%c",&c1);
       for(a=new1;a!=new3->next;a=a->next)//traversinf through the list with same intial letter
       {
	    if((a->data[count1]==c1)||(a->data[count1]==c1+32))//search if next letter within the list obtained in the previous function is same
	    {
		*p1=a;//stores the first encountered contact in a temp variable
		break;
	    }
	    else
	    {
		tot++;
		continue;
	    }
       }
       if(tot==total)//in case of no match
       {
	    printf("\n MESSAGE  :: Sorry....No Matches Found...!\n");
	    printf("\n----------------------------------------------\n");
	    fflush(stdin);
	    return;
       }
       for(f=*p1;f!=new3->next;f=f->next)//month conversion
       {
	    switch(f->month)
	    {
		case 1:
		    strcpy(mo,",Jan,");
		    break;
		case 2:
		    strcpy(mo,",Feb,");
		    break;
		case 3:
		    strcpy(mo,",Mar,");
		    break;
		case 4:
		    strcpy(mo,",Apr,");
		    break;
		case 5:
		    strcpy(mo,",May,");
		    break;
		case 6:
		    strcpy(mo,",Jun,");
		    break;
		case 7:
		    strcpy(mo,",Jul,");
		    break;
		case 8:
		    strcpy(mo,",Aug,");
		    break;
		case 9:
		    strcpy(mo,",Sep,");
		    break;
		case 10:
		    strcpy(mo,",Oct,");
		    break;
		case 11:
		    strcpy(mo,",Nov,");
		    break;
		case 12:
		    strcpy(mo,",Dec,");
		    break;
	     }
	     if((f->data[count1]==c1)||(f->data[count1]==c1+32))//display specific contact
	     {
		 *p3=f;
		 printf("\nCONTACT %d :\n",i);i++;
		 printf("----------\n");
		 printf("\n NAME \t\t: %s    \n MOBILE NUMBER \t: %s    \n EMAIL ID \t: %s\n BIRTHDAY \t: %d%s%d\n ADDRESS\t: %s,\n\t\t  %s,\n\t\t  %s,\n\t\t  %s.\n\n",f->data,f->no,f->mail,f->date,mo,f->year,f->street,f->district,f->state,f->pin);
		 printf("--------------------------------------------------------------------------");
	     }
       }
       (*count)++;//shift to next character
}
void sort()//sorting based on contact name
{
	node s,s1;
	char b[15][30],c[15][30],d[15][30];
	char st[25],di[25],sta[25],pi[10];
	int da,m,y;
	extern node head;
	FILE *fp,*fp1,*f;
	int aa=1;
	f=fopen("Base.c","w");//opening base filw
	fp=fopen("Diary.c","w");//opening a new file to store data
	fp1=fopen("Table.c","w");//opening a new file to store data
	fprintf(fp,"\n       ******************************************\n");
	fprintf(fp,"       *                                        *\n");
	fprintf(fp,"       *              CONTACT BOOK              *\n");
	fprintf(fp,"       *                                        *\n");
	fprintf(fp,"       ******************************************\n\n");
	fprintf(fp1,"\n       ******************************************\n");
	fprintf(fp1,"       *                                        *\n");
	fprintf(fp1,"       *              CONTACT BASE              *\n");
	fprintf(fp1,"       *                                        *\n");
	fprintf(fp1,"       ******************************************\n\n");
	for(s=head;s!=NULL;s=s->next)//bubble sort
	{
		for(s1=s->next;s1!=NULL;s1=s1->next)
		{
			if(strcmp(s->data,s1->data)>0)//swapping
			{
				strcpy(b[0],s1->data);strcpy(s1->data,s->data);strcpy(s->data,b[0]);
				strcpy(c[0],s1->no);strcpy(s1->no,s->no);strcpy(s->no,c[0]);
				strcpy(d[0],s1->mail);strcpy(s1->mail,s->mail);strcpy(s->mail,d[0]);
				da=s1->date;s1->date=s->date;s->date=da;
				m=s1->month;s1->month=s->month;s->month=m;
				y=s1->year;s1->year=s->year;s->year=y;
				strcpy(st,s1->street);strcpy(s1->street,s->street);strcpy(s->street,st);
				strcpy(di,s1->district);strcpy(s1->district,s->district);strcpy(s->district,di);
				strcpy(sta,s1->state);strcpy(s1->state,s->state);strcpy(s->state,sta);
				strcpy(pi,s1->pin);strcpy(s1->pin,s->pin);strcpy(s->pin,pi);
			}
		}
	}
	fprintf(fp1,"\n____________________________________________________________________________");
	fprintf(fp1,"\n\n   NAME\t\t|  CONTACT NO\t| BIRTHDAY\t| MAIL ID");
	fprintf(fp1,"\n____________________________________________________________________________\n");
	for(s=head;s!=NULL;s=s->next)
	{
		char mo[10];
		switch(s->month)
		{
		    case 1:
		strcpy(mo,",Jan,");
		break;
		    case 2:
		strcpy(mo,",Feb,");
		break;
		    case 3:
		strcpy(mo,",Mar,");
		break;
		    case 4:
		strcpy(mo,",Apr,");
		break;
		    case 5:
		strcpy(mo,",May,");
		break;
		    case 6:
		strcpy(mo,",Jun,");
		break;
		    case 7:
		strcpy(mo,",Jul,");
		break;
		    case 8:
		strcpy(mo,",Aug,");
		break;
		    case 9:
		strcpy(mo,",Sep,");
		break;
		    case 10:
		strcpy(mo,",Oct,");
		break;
		    case 11:
		strcpy(mo,",Nov,");
		break;
		    case 12:
		strcpy(mo,",Dec,");
		break;
		}//storing in diary.c file
		fprintf(fp,"\t NAME\t\t: %s\n",s->data);
		fprintf(fp,"\t MOBILE NO\t: %s\n",s->no);
		fprintf(fp,"\t EMAIL ID\t: %s\n",s->mail);
		fprintf(fp,"\t BIRTHDAY\t: %d%s%d\n",s->date,mo,s->year);
		fprintf(fp,"\t Address\t: %s,\n",s->street);
		fprintf(fp,"\t \t\t  %s,\n",s->district);
		fprintf(fp," \t\t\t  %s.\n",s->state);
		fprintf(fp," \t\t\t  %s\n\n",s->pin);
		fprintf(fp1,"\n   %s    \t|  %s \t| %d%s%d \t| %s\n",s->data,s->no,s->date,mo,s->year,s->mail);//storing in table.c file
		fprintf(f,"%d %s %s %d %d %d %s %s %s %s %s ",aa,s->data,s->no,s->date,s->month,s->year,s->mail,s->street,s->district,s->state,s->pin);
		//storing in the base.c file
	}
    fprintf(fp1,"\n____________________________________________________________________________");
    fprintf(f,"%d",0);//intialising the end charater
    fclose(fp);
    fclose(fp1);
    fclose(f);//closing all file that are opened
}
void insert()
{
	node temp,p,p1,p2,prev;
	char newname[50];
	extern node head;
	int choice;
	temp=getnode();//creating a node
	readnodeuser(temp);//getting values from the user
	if(head==NULL)//in case of empty list
		head=temp;
	else
	{
	p1=head;
	while(p1!=NULL)//traversing through the list
	{
	    sos :
	    if(!strcmp(temp->data,p1->data))//checking if contact name already present
	    {
		printf("\n MESSAGGE :: .....Contact Name You Entered ALREADY EXISTS.....\n");
		printf("_________________________________________________________________\n\n");
		printf(" 1. REPLACE Contact \n\n 2. Enter a NEW NAME For the contact\n\n 3. RETURN to Menu \n\n");
		printf("\n Enter An Option..: ");
		fflush(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
		    case 1://replace contact
			insertlast(temp->data,temp->no,temp->mail,temp->date,temp->month,temp->year,temp->street,temp->district,temp->state,temp->pin);//inserting at the last of the list
			prev->next=p1->next;//repalcing the previously available contact
			free(p1);//freeing the memory
			printf("\n MESSAGE :: The Contact Name Has Been Added Succesfully\n");
			printf("\n--------------------------------------------------------\n");
			return;
		    case 2://enter new name
			printf("\n Enter the New Name for the Contact....: ");
			scanf("%s",&newname);
			if(newname[0]>95)//switching initial char. to uppercase
				newname[0]=newname[0]-32;
			strcpy(temp->data,newname);
			insertlast(temp->data,temp->no,temp->mail,temp->date,temp->month,temp->year,temp->street,temp->district,temp->state,temp->pin);//insert at the last of the list
			printf("\n MESSAGE :: The Contact Name Has Been Added Succesfully\n");
			printf("\n--------------------------------------------------------\n");
			return;
		    case 3:
			return;
		    default:
			printf("\n MESSAGE :: Sorry....Not A Valid Option...!\n");
			printf("\n----------------------------------------------\n");
			goto sos;

		  }
	    }
	    prev=p1;
	    p1=p1->next;
	}
	p2=head;
	while(p2!=NULL)//traversing the list
	{
	    if(!strcmp(temp->no,p2->no))//checking if the contact number is present
	    {
		printf("\n MESSAGE :: .....Contact Number Already Exists....");
		printf("\n--------------------------------------------------\n");
		printf("\t Want To Replace the contact...(y/n)??  ");
		fflush(stdin);
		scanf("%c",&choice);
		if(choice=='y' || choice=='Y')
		{
		    insertlast(temp->data,temp->no,temp->mail,temp->date,temp->month,temp->year,temp->street,temp->district,temp->state,temp->pin);
		    return;
		}
		else
		    return;
	    }
	    else
		p2=p2->next;
	}//in case of no matches found
	p=head;
	while(p->next!=NULL)
	     p=p->next;
	p->next=temp;//inserting at the end
	}
	printf("\n MESSAGE :: The Contact Name Has Been Added Succesfully\n");
	printf("\n--------------------------------------------------------\n");
}
void readnodeuser(node temp)//reading the values from the user
{
	int mo;
	int i;
	char addr[50];
	printf(" INSTRUCTION : Use '_' underscore for spaces \n");
	printf("\n_____________________________________________\n");
	printf("\n  Enter Contact Name....... :");scanf("%s",temp->data);
	if(temp->data[0]>95)//converting the initial character to uppercase
	   temp->data[0]=temp->data[0]-32;
	printf("\n  Enter Contact Number..... :");scanf("%s",temp->no);
	printf("\n  Enter Contact Mail ID.... :");scanf("%s",temp->mail);
	printf("\n  Enter The Date Of Birth.. :\n");
	printf("\n  Day   : ");scanf("%d",&temp->date);
	printf("\n  Month : ");scanf("%d",&temp->month);
	printf("\n  Year  : ");scanf("%d",&temp->year);
	printf("\n  Enter The Address........ : ");scanf("%s",temp->street);
	printf("\n  Enter The District Name.. : ");scanf("%s",temp->district);
	if(temp->district[0]>95)//converting the initial character to uppercase
	   temp->district[0]=temp->district[0]-32;
	printf("\n  Enter The State Name..... : ");scanf("%s",temp->state);
	if(temp->state[0]>95)//converting the initial character to uppercase
	   temp->state[0]=temp->state[0]-32;
	printf("\n Enter Pin Code............ : ");scanf("%s",temp->pin);
	temp->next=NULL;
}
void delete_()
{
	node p,prev,p1;
	char delcontact[30];
	extern node head;
	if(head==NULL)//in case the list is empty
	{
		printf("\n MESSAGE :: .....Contacts List Is Empty.....\n");
		printf("\n----------------------------------------------\n");
		return;
	}
	else
	{
		printf("\n Enter Name Of Contact to be Deleted...: ");
		scanf("%s",delcontact);
		if(delcontact[0]>95)//converting the initial character to uppercase
			delcontact[0]=delcontact[0]-32;
		if(!strcmp(head->data,delcontact))//check if the head node is the node to be deleted
		{
			p=head;
			head=head->next;
			free(p);//freeing the memory
			printf("\n MESSAGE :: The Contact Has Been Successfully Deleted \n");
			printf("\n------------------------------------------------------\n");
			return;
		}
		else
		{
			p=head;
			while(p!=NULL)//traversing the list
			{
				if(!strcmp(p->data,delcontact))//checking the contact name
				{
					p1=p;
					prev->next=p->next;
					free(p1);
					printf("\n MESSAGE :: The Contact Has Been Successfully Deleted \n");
					printf("\n------------------------------------------------------\n");
					return;
				}
				else
				{
					prev=p;
					p=p->next;
				}
			}
			printf("\n MESSAGE :: ........Contact not present........\n");
			printf("\n-----------------------------------------------\n");
		}
	}
}
void edit()
{
	node p;
	char editname[30],editno[30],newname[30],newno[30],newmail[50],newstreet[25],newdistrict[25],newstate[25],newpin[10];
	int d,m,y;
	extern node head;
	int option,returnval,returnno;
	p=head;
	if(p==NULL)//in case of empty list
	{
		printf("\n MESSAGE :: .......Contacts list empty.......");
		printf("\n----------------------------------------------\n");
		return;
	}
	printf("\n\n  1. Edit Contact Name Only\n");
	printf("\n  2. Edit Contact Number Only\n");
	printf("\n  3. Edit Contact Name And Number Only\n");
	printf("\n  4. Edit All Details\n");
	printf("\n  5. Return To Main Menu\n");
	printf("______________________________________________\n");
	printf("\n INSTRUCTION : Use '_' underscore for spaces \n");
	printf("\n_____________________________________________\n");
	printf("\n Enter an Option...:  ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1://edit contact name
		printf("\n Enter Contact Name Which Is To Be Modified..: ");
		scanf("%s",editname);
		if(editname[0]>95)
			editname[0]=editname[0]-32;
		while(p!=NULL)
		{
		    if(!strcmp(p->data,editname))
		    {
			printf("\n Enter The New Name For The Contact...: ");
			scanf("%s",newname);
			if(newname[0]>95)//converting the initial character to uppercase
			    newname[0]=newname[0]-32;
			returnval=conflictname(newname);//check if the contact name already present
			if(returnval==1 || returnval==2)//if not
			{
			    strcpy(p->data,newname);
			    printf("\n MESSAGE :: The Contact Has Been Successfully Edited \n");
			    printf("\n-----------------------------------------------------\n");
			    return;
			}
			else
			    return;

		    }
		    else
			p=p->next;
		}
		printf("\n MESSAGE ::  .....Contact Not Present.....!\n");
		printf("\n----------------------------------------------\n");
		break;
	    case 2://edit the contact number
		printf("\n Enter Contact Name Which Is To be Modified...: ");
		scanf("%s",editname);
		if(editname[0]>95)//converting the initial character to uppercase
			editname[0]=editname[0]-32;
		while(p!=NULL)
		{
		    if(!strcmp(p->data,editname))
		    {
			printf("\n Enter The New Number...: ");
			scanf("%s",newno);
			returnno=conflictno(newno);//checks if the number is already present
			if(returnno==1 || returnno==2)//if not
			{
			    strcpy(p->no,newno);
			    printf("\n MESSAGE :: The Contact Has Been Successfully Edited \n");
			    printf("\n-----------------------------------------------------\n");
			    return;
			}
			else
			    return;
		     }
		     else
			p=p->next;
		}
		printf("\n MESSAGE :: ......Contact Not Present......!\n");
		printf("\n----------------------------------------------\n");
		break;
	    case 3://new contact name and number
		printf("\n Enter Contact Name Which Is To Be Modified...: ");
		scanf("%s",editname);
		if(editname[0]>95)//converting the initial character to uppercase
			editname[0]=editname[0]-32;
		while(p!=NULL)//traversing the list
		{
		    if(!strcmp(p->data,editname))
		    {
			printf("\n Enter New Name..: ");
			scanf("%s",newname);
			if(newname[0]>95)//converting the initial character to uppercase
			    newname[0]=newname[0]-32;
			printf("\n Enter New Number..: ");
			scanf("%s",newno);
			returnval=conflictname(newname);//checks if it is already present
			returnno=conflictno(newno);
			if(returnval==1 || returnval==2)
			     strcpy(p->data,newname);
			if(returnno==1 || returnno==2)
			{
			     strcpy(p->no,newno);
			     printf("\n MESSAGE :: The Contact Has Been Successfully Edited \n");
			     printf("\n-----------------------------------------------------\n");
			     return;
			}
			else
				return;
		     }
		     else
			p=p->next;
		}
		printf("\n MESSAGE :: ....Contact Not Present....!\n");
		printf("\n----------------------------------------------\n");
		break;
	case 4://edit all details
	    printf("\n Enter Contact Name Which Is To Be Modified...: ");
	    scanf("%s",editname);
	    if(editname[0]>95)
		editname[0]=editname[0]-32;
	    while(p!=NULL)
	    {
		if(!strcmp(p->data,editname))
		{
		    printf("\n Enter new name....... : ");
		    scanf("%s",newname);
		    if(newname[0]>95)//converting the initial character to uppercase
			newname[0]=newname[0]-32;
		    printf("\n Enter new number..... : ");
		    scanf("%s",newno);
		    printf("\n Enter a new Mail ID.. : ");
		    scanf("%s",newmail);
		    printf("\n Enter The New Date Of Birth : ");
		    printf("\n\n Enter Day...: ");
		    scanf("%d",&d);
		    printf("\n Enter Month...: ");
		    scanf("%d",&m);
		    printf("\n Enter Year....: ");
		    scanf("%d",&y);
		    printf("\n Enter new Address.... : ");
		    scanf("%s",newstreet);
		    printf("\n Enter district name.. : ");
		    scanf("%s",newdistrict);
		    if(newdistrict[0]>95)//converting the initial character to uppercase
			   newdistrict[0]=newdistrict[0]-32;
		    printf("\n Enter a state name... : ");
		    scanf("%s",newstate);
		    if(newstate[0]>95)//converting the initial character to uppercase
			   newstate[0]=newstate[0]-32;
		    printf("\n Enter pin code....... : ");
		    scanf("%s",newpin);
		    strcpy(p->mail,newmail);
		    strcpy(p->street,newstreet);
		    strcpy(p->district,newdistrict);
		    strcpy(p->state,newstate);
		    strcpy(p->pin,newpin);
		    p->date=d;
		    p->month=m;
		    p->year=y;
		    returnval=conflictname(newname);
		    returnno=conflictno(newno);
		    if(returnval==1 || returnval==2)
			strcpy(p->data,newname);
		    if(returnno==1 || returnno==2)
		    {	strcpy(p->no,newno);
			printf("\n MESSAGE :: The Contact Has Been Successfully Edited \n");
			printf("\n-----------------------------------------------------\n");
			return;
		    }
		}

		else
		    p=p->next;
	    }
	    printf("\n MESSAGE :: .......Contact Not Prresent......!\n");
	    printf("\n----------------------------------------------\n");
	    break;
	case 5:
	    break;
	default:
	    printf("\n MESSAGE ::  Sorry..Not a Valid Option\n");
	    printf("\n----------------------------------------------\n");
	    return;
    }
}
void insertinitial()
{
	 extern node head;
	 FILE *p;
	 int a,b,c;
	 int f;
	 char d[10][50];
	 p=fopen("Base.c","r");//opening the base file
	 fscanf(p,"%d%s%s%d%d%d%s%s%s%s%s",&f,d[0],d[1],&a,&b,&c,d[2],d[3],d[4],d[5],d[6]);//scaning the contacts from the file
	 if(f==1)//checking if the file is empty
	 {
		 insertfirst(d[0],d[1],d[2],a,b,c,d[3],d[4],d[5],d[6]);//inserting to the list
		 fscanf(p,"%d%s%s%d%d%d%s%s%s%s%s",&f,d[0],d[1],&a,&b,&c,d[2],d[3],d[4],d[5],d[6]);//scaning the next contact from the file
		 while(f==1)//scaning till the end of the file
		 {
			 insertlast(d[0],d[1],d[2],a,b,c,d[3],d[4],d[5],d[6]);
			 fscanf(p,"%d%s%s%d%d%d%s%s%s%s%s",&f,d[0],d[1],&a,&b,&c,d[2],d[3],d[4],d[5],d[6]);
		 }
	 }
	 fclose(p);//closing the base of file
}
void displaymenu()//displaying the main menu
{
	textcolor(3);
    printf("\n");cputs("       ++++++++++++++++++++++++++++++++++++++++++");printf("\n");
    cputs("       +                                        +");printf("\n");
    cputs("       +");textcolor(WHITE);cputs("             MENU OPTIONS              ");textcolor(3);cputs(" +");printf("\n");
    cputs("       +                                        +");printf("\n");
    cputs("       ++++++++++++++++++++++++++++++++++++++++++\n\n");    textcolor(LIGHTGRAY);
    printf("\n       -----------------------------------------\n");
    printf("       #                                        #\n");
    printf("       #                                        #\n");
    printf("       #         1. SEARCH CONTACT              #\n");
    printf("       #         2. ADD CONTACT                 #\n");
    printf("       #         3. DELETE CONTACT              #\n");
    printf("       #         4. EDIT CONTACT                #\n");
    printf("       #         5. DISPLAY ALL CONTACTS        #\n");
    printf("       #         6. DISPLAY MENU                #\n");
    printf("       #         7. EXIT                        #\n");
    printf("       #                                        #\n");
    printf("       #                                        #\n");
    printf("       ------------------------------------------\n\n");
}
int conflictname(char a[30])
{
	node p1,prev;
	extern node head;
	char ch;
	p1=head;
	while(p1!=NULL)//traversing the list
	{
		if((!strcmp(p1->data,a)))//checks if the data matches
		{
			printf("\n MESSAGE :: ..........Contact Name Already Present..........\n");
			printf("\n------------------------------------------------------------\n");
			printf("\n Want To Replace..(y/n)??");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y' || ch=='Y')
			{
				prev->next=p1->next;//replacing the contact
				free(p1);
				return(1);
			}
			else
				return(-1);
		}
		else
		{
			prev=p1;
			p1=p1->next;
		}
	}
	return(2);
}
int conflictno(char a[30])
{
	node p1;extern node head;char ch;
	p1=head;
	while(p1!=NULL)//traversing the list
	{
		if(!strcmp(p1->no,a))//checking the match
		{
			printf("\n MESSAGE ::  .....Contact Number Already Present.......\n");
			printf("\n-------------------------------------------------------\n");
			printf("\n Want to Repalce...(y/n)?? ");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y' || ch=='Y')
				return(1);
			else
				return(-1);
		}
		else
			p1=p1->next;
	}
	return(2);
}
int welcome()//welcome screen
{
    int one;
    int i;
    textcolor(CYAN);
    printf("\n\n\n\n\n\n\n\n\t\t");
    cputs("COLLEGE OF ENGINEERING GUINDY, ANNAUNIVERSITY");
    printf("\n\n\t\t");
    cputs("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    printf("\n\n\n\t\t");
    cputs("    PROGRAMMING AND DATASTRUCTURES PROJECT");
    printf("\n");
    delay(5000);
    clrscr();
    printf("\n\n\n\n\n\n");
    textcolor(MAGENTA);
    gotoxy(12,5);
    printf("  ");
    for(i=0;i<28;i++)
	cputs(" *");
    printf("\n");
    gotoxy(12,6);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,7);
    cputs("   *               ");
    textcolor(12+BLINK);
    cputs("......WELCOME.......");
    textcolor(MAGENTA);
    cputs("                  *  ");
    printf("\n");
    gotoxy(12,8);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,9);
    cputs("   *                ");
    textcolor(12+BLINK);
    cputs("........TO........");
    textcolor(MAGENTA);
    cputs("                   *  ");
    printf("\n");
    gotoxy(12,10);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,11);
    cputs("   *         ");
    textcolor(12+BLINK);
    cputs("....THE PERSONAL CONTACT BOOK.....");
    textcolor(MAGENTA);
    cputs("          *  ");
    printf("\n");
    gotoxy(12,12);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,13);
    cputs("  ");
    for(i=0;i<28;i++)
	cputs(" *");
    printf("\n\n");
    textcolor(LIGHTMAGENTA);
    cputs("\n\n\n    PLEASE PRESS  1  TO CONTINUE.........");
    textcolor(WHITE);
    scanf("%d",&one);
    return one;
}
void thanks()//EXIT
{
    int i;
    printf("\n\n\n\n\n\n");
    textcolor(MAGENTA);
    gotoxy(12,5);
    printf("  ");
    for(i=0;i<28;i++)
	cputs(" *");
    printf("\n");
    gotoxy(12,6);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,7);
    cputs("   *               ");
    textcolor(12+BLINK);
    cputs("......THANK YOU.....");
    textcolor(MAGENTA);
    cputs("                  *  ");
    printf("\n");
    gotoxy(12,8);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,9);
    cputs("   *                ");
    textcolor(12+BLINK);
    cputs(".....FOR USING....");
    textcolor(MAGENTA);
    cputs("                   *  ");
    printf("\n");
    gotoxy(12,10);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,11);
    cputs("   *         ");
    textcolor(12+BLINK);
    cputs("....THE PERSONAL CONTACT BOOK.....");
    textcolor(MAGENTA);
    cputs("          *  ");
    printf("\n");
    gotoxy(12,12);
    cputs("   *                                                     *  ");
    printf("\n");
    gotoxy(12,13);
    cputs("  ");
    for(i=0;i<28;i++)
	cputs(" *");
    printf("\n\n");
    printf("                        ");
    textcolor(GREEN);
    for(i=0;i<10;i++)
	cputs("  ");
    sleep(1);
    printf("\n\n\n\t\t\t   Developed By:");
    sleep(1);
    textcolor(LIGHTMAGENTA);
    cputs("   Vignesh.N.T");sleep(1);
    printf("\n                                        ");
    cputs("   Sashank.S");sleep(1);
    printf("\n                                         ");
    cputs("  Praveen.S.K");sleep(1);
    printf("\n                                        ");
    cputs("   Shebin.R");

}
void error()//error message
{
    int i;
    printf("\n\n\n");
    textcolor(MAGENTA);
    printf("       ");
    for(i=0;i<28;i++)
	cputs(" *");
    printf("\n");
    cputs("        *                                                     *  ");
    printf("\n");
    cputs("        *               ");
    textcolor(12+BLINK);
    cputs("SORRY...............");
    textcolor(MAGENTA);
    cputs("                  *  ");
    printf("\n");
    cputs("        *                                                     *  ");
    printf("\n");
    cputs("        *               ");
    textcolor(12+BLINK);
    cputs("NOT VALID OPTION....");
    textcolor(MAGENTA);
    cputs("                  *  ");
    printf("\n");
    cputs("        *                                                     *  ");
    printf("\n");
    cputs("        *               ");
    textcolor(12+BLINK);
    cputs("THANK YOU....................");
    textcolor(MAGENTA);
    cputs("         *  ");
    printf("\n");
    cputs("        *                                                     *  ");
    printf("\n");
    cputs("       ");
    for(i=0;i<28;i++)
	cputs(" *");
    printf("\n");
}



