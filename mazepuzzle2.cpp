#include <iostream>
using  namespace std;
int pos1=0,pos2=0,m,n,p1,p2;
struct node
{
  int rw,cl;
  node *next;
};
void push(struct node **head,int a,int b)
{
node *createnode=new node;
createnode->rw=a;
createnode->cl=b;
createnode->next=NULL;
if(*head==NULL)
{
(*head)=createnode;
}
else{
	struct node *list=(*head);
	while(list->next!=NULL)
	{
		list=list->next;
	}
  list->next=createnode;
}
}
void removeready(struct node **head)
{
  if((*head)==NULL)
  {
    cout<<"Empty list";
  }
  else
	{
 delete(*head);
  }
}
void printmat(char arr[100][100])
{
for(int i=0;i<m;i++)
{
  for(int j=0;j<n;j++)
  {
    cout<<arr[i][j]<<" ";
  }
  cout<<"\n";
}
}
void path(struct node *head,char arr[100][100])
{
  int flag=0;
  cout<<"enter the destination cord\n";
  cin>>p1>>p2;
	struct node *list2=NULL,*list=NULL;
while(head!=NULL)
{
list2=head;
	while(list2->next!=NULL)
	{
		list=list2;
   list2=list2->next;
	}
int r=list2->rw;
int c=list2->cl;
if(r==p1 && c==p2)
{ flag=1;
  arr[r][c]='*';
	break;
}
else
{
  if((arr[r][c+1]=='-' ||arr[r][c+1]=='&')&& (c+1)<n)
{
	arr[r][c+1]='&';
  push(&head,r,c+1);
}
if((arr[r+1][c]=='-' || arr[r+1][c]=='&') && (r+1)<m)
{
	arr[r+1][c]='&';
push(&head,r+1,c);
}
if((arr[r-1][c]=='-' || arr[r-1][c]=='&') && r-1>=0)
{
	arr[r-1][c]='&';
   push(&head,r-1,c);
}
if((arr[r][c-1]=='-' || arr[r][c-1]=='&') && c-1>=0)
{
	arr[r][c-1]='&';
  push(&head,r,c-1);
}
arr[r][c]='*';
if(list2==head)
{
	head=head->next;
}
else{
list->next=NULL;
}
removeready(&list2);
printmat(arr);
cout<<endl;
}
}
if(flag==0)
{
	cout<<"destination not reached\n";
}
printmat(arr);
}

void copymat(char car[100][100],char ar[100][100])
{
	int i=pos1,j=pos2,points=0;
car[i][j]='#';
while(1){
	char ch;
	if(i==p1 && j==p2)
	{
		cout<<"CONGRATULATIONS\n";
		break;
	}
	printmat(car);
	cout<<"Enter the operation--------l(left) ---r(right)---t(top)--d(down)\n ";
cin>>ch;
switch(ch)
{
	case 't':
	if(car[i-1][j]=='-' && i-1>=0)
	{
		i=i-1;
		car[i][j]='#';
		if(ar[i][j]=='*')
		{
			points=points+2;
		}
		else {
			points++;
		}
	}
	else
	{
		cout<<"invalid step\n";
	}
	break;
	case 'd':
	if(car[i+1][j]=='-' && i+1<m)
	{
		i=i+1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points=points+2;
		}
		else {
			points++;
		}
	}
	else
	{
		cout<<"Invalid step\n";
	}
	break;
	case 'l':
	if(car[i][j-1]=='-' && j-1>=0)
	{
		j=j-1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points=points+2;
		}
		else {
			points++;
		}
	}
	else
	{
		cout<<"Invalid step\n";
	}
	break;
	case 'r':
	if(car[i][j+1]=='-' && j+1<n)
	{
		j=j+1;
		car[i][j]='#';
			if(ar[i][j]=='*')
		{
			points=points+2;
		}
		else {
			points++;
		}
	}
	else
	{
		cout<<"Invalid step\n";
	}
	break;
	default:cout<<"wrong input\n";
}
}
}
int main()
{
  char ar[100][100],car[100][100];
  struct node *head=NULL;
  cout<<"enter the pos\n";
  cin>>pos1>>pos2;
  cout<<"matrix cordinates\n";
  cin>>m>>n;
  cout<<"enter the value\n";
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>ar[i][j];
		car[i][j]=ar[i][j];
    }
  }
  push(&head,pos1,pos2);
  path(head,ar);
	copymat(car,ar);
}
