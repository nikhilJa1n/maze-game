#include<iostream>
using namespace std;

struct node{
	int row,col;
	struct node *next;
};

void createNode(struct node**front,struct node **rear,int a,int b)
{
	struct node *trav=(*rear),*n;
	n=new node;
	n->row=a;
	n->col=b;
	n->next=NULL;
	if((*rear)==NULL)
	{
	   (*front)=n;
	   (*rear)=n;
	   trav=n;
	}
	else
	{
		while(trav->next!=NULL)
		   trav=trav->next;
		trav->next=n;
		(*rear)=n;
	}
}
void dequeue(struct node** head)
{
	struct node* temp;
	if(*head==NULL)
	{
		cout<<"Queue Is Empty";
	}
	else
	{
		temp=(*head);
		*head=(*head)->next;
		delete(temp);
	}
}
void printThePath(char puzzle[100][100],int n,int m)
{
	struct node *front=NULL,*rear=NULL;
	int srow,scol,drow,dcol;
	int i,j;
	cout<<"Enter Source\n";
	cin>>srow>>scol;
	cout<<"Enter Destination\n";
	cin>>drow>>dcol;
	createNode(&front,&rear,srow,scol);
	while(front!=NULL)
	{
    int count=0;
		i=front->row;
		j=front->col;
		if(i==drow&&j==dcol)
		{
			cout<<"("<<i<<j<<") Found\n";
			break;
		}
		if(j!=0&&puzzle[i][j-1]=='a')
		{
			createNode(&front,&rear,i,j-1);
      cout<<"left"<<' ';
		}
		if(j!=m-1&&puzzle[i][j+1]=='a')
		{
			createNode(&front,&rear,i,j+1);
      cout<<"right"<<' ';
		}
		if(i!=n-1&&puzzle[i+1][j]=='a')
		{
			createNode(&front,&rear,i+1,j);
      cout<<"bottom"<<' ';
		}
		if(i!=0&&puzzle[i-1][j]=='a')
		{
			createNode(&front,&rear,i-1,j);
      cout<<"top"<<' ';
		}
		puzzle[i][j]='*';
		dequeue(&front);
	}
}
int main()
{
	char puzzle[100][100];
	int i,j,n,m;
	cout<<"Enter Rows And Columns Of Puzzlen";
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>puzzle[i][j];
		}
	}
	printThePath(puzzle,n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<puzzle[i][j]<<" ";
		}
		cout<<endl;
	}

}
