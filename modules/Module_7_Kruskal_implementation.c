#include <stdio.h> 
#include<time.h>
#define INT_MAX 10000  //Unreachable paths are identified using Infinity!!
int n;
int parent[INT_MAX];

//Kruskals Helper Function
// Find set of vertex i
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
 
//Kruskals Helper Function 
// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
 
// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][50],int x)
{
	clock_t start = clock();
    int mincost = 0; // Cost of min MST.
 
    // Initialize sets of disjoint sets.
    for (int i = 0; i < x; i++)
        parent[i] = i;
 
    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < x - 1) {
        int min = INT_MAX; int a = -1 ;int b = -1;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
 
        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
        mincost += min;
    }
    clock_t end = clock();
    printf("\nMinimum cost= %d \n", mincost);
    double time = ((double) (end - start))/CLOCKS_PER_SEC;
    time=time*1000000;
    printf("Processing Time: %f MicroSeconds\n",time);
}
 
// driver program to test above function
int main()
{
//int n;
int i,j;
printf("Enter the number of nodes: ");
scanf("%d",&n);
int cost[50][50]; //hardcoding 2d array size as needed for sending to new function
//Initialize by Int max as unreachable paths!!
//This is to be replaced by 2D matrix made in our main code
//Take user input!! for upper half triangle only
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
}
}  
    // Print the solution
    kruskalMST(cost,n);
 
    return 0;
} 
