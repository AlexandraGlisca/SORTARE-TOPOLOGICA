

 #define MAX 100
 #include "function.h"
 ///\var MAX reprezinta numarul maxim de elemente
int n;
///\var n reprezinta numarul de noduri din graf
int adj[MAX][MAX];

int queue[MAX], front = -1,back = -1;
///\var front reprezinta nodul urmator nodului curent
///\var back reprezinta nodul anterior nodului curent
int main()
///\fn int main()
///\brief Reprezinta functia principala
{
 int i,v,count,topo_order[MAX],indeg[MAX];

    create_graph();
	for(i=0;i<n;i++)
	{
		indeg[i] = indegree(i);
		if( indeg[i] == 0 )
			insert_queue(i);
	}

	count = 0;

	while(  !isEmpty_queue( ) && count < n )
	{
		v = delete_queue();
    	topo_order[++count] = v;

		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1)
			{
				adj[v][i] = 0;
				indeg[i] = indeg[i]-1;
				if(indeg[i] == 0)
					insert_queue(i);
			}
		}
	}

	if( count < n )
	{
		printf("\nNo topological ordering possible, graph contains cycle\n");
		exit(1);
	}
	printf("\nVertices in topological order are :\n");
	for(i=1; i<=count; i++)
    {
		printf( "%d ",topo_order[i] );
	    printf("\n");
    }
	return 0;
}

