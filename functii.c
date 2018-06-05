
#define MAX 100
#include "function.h"

void insert_queue(int vertex)
///\fn void insert_queue(int vertex)
///\ brief Insereaza un nod in coada
///\param vertex este o variabila care reprezinta nodul din graf
{
    int queue[MAX], front = -1,back = -1;
	if (back == MAX-1)
		printf("\nQueue Overflow\n");
	else
	{
		if (front == -1)
			front = 0;
		back = back+1;
		queue[back] = vertex ;
	}
}

int isEmpty_queue()
///\fn isEmpty_queue()
///\brief Verifica daca coada nu contine niciun element
{ int queue[MAX], front = -1,back = -1;
	if(front == -1 || front > back )
		return 1;
	else
		return 0;
}

int delete_queue()
///\fn delete_queue()
///\brief Sterge un element din coada
{int queue[MAX], front = -1,back = -1;
	int del_item;
	if (front == -1 || front > back)
	{
		printf("\nQueue Underflow\n");
		exit(1);
	}
	else
	{
		del_item = queue[front];
		front = front+1;
		return del_item;
	}
}

int indegree(int v)
///\fn indegree(int v)
///\brief Calculeaza gradul de intrare pentru fiecare nod
///\param v este o variablia care reprezinta nodul din graf
{   int n,adj[MAX][MAX];
	int i,in_deg = 0;
	for(i=0; i<n; i++)
		if(adj[i][v] == 1)
			in_deg++;
	return in_deg;
}

void create_graph()
///\fn create_graph()
///\brief Functia prin care este creat graful
///\var origin reprezinta nodul de la care porneste arcul
///\var destin reprezinta cel de-al doilea nod care formeaza arcul
///\var max_edges reprezinta numarul maxim de arce din graf
{
	int i,n,max_edges,origin,destination,adj[MAX][MAX],count;

	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(count=1; count<=max_edges; count++)
	{
            printf("Enter Edge [%d] co-ordinates (-1 -1 to quit)\n", count);
            printf("Enter Origin Vertex:\t");
            scanf("%d", &origin);
            printf("Enter Destination Vertex:\t");
            scanf("%d", &destination);

		if((origin == -1) && (destination == -1))
			break;

		if( origin >= n || destination >= n || origin<0 || destination<0)
		{
			printf("\nInvalid edge!\n");
			i--;
		}
		else
			adj[origin][destination] = 1;
	}
}


