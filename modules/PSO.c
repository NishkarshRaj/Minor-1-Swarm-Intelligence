#include <stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<time.h>
#define INT_MAX 100000

int n; //Declaring the N value as global variable!!!!!!!!!!!!!!!

// Random function for cost in PSO
float random_generator()
{
	register int x = rand(); //Using register storage class for faster access
	//printf("%d",x); Yes every time new random integer is generated
	//How to convert any integer number into a float between 0 and 1
	//Divide the number by 10^(number of digits)
	int count=0,temp;
	temp=x; //temp holds x value because its going to change to 0 to count frequency of digits
	while(temp>0)
	{
	    count++;
	    temp=temp/10;
	}
	//printf("%d\n%d\n",x,count);
	temp = pow(10,count); //using same variable again to save memory
	float answer = (float)x/temp;
	//printf("%f\n",answer);
	return abs(answer);
}

//Function for Valid Edge -> Check if edge present in MST Set or not!!
int isValidEdge(int u, int v, int* inMST) 
{ 
   if (u == v) 
       return 0; 
   if (inMST[u] == 0 && inMST[v] == 0) 
        return 0; 
   else if (inMST[u] == 1 && inMST[v] == 1) 
        return 0; 
   return 1; 
}   

//PSO Function
void PSO(int cost[][50],int x) 
{   
    int inMST[n]; 
    int r,c; //iterate the cost matrix
    // Include first vertex in MST 
    inMST[0] = 1; 
    // Keep adding edges while number of included 
    // edges does not become V-1. 
    int edge_count = 0, mincost = 0; 
    while (edge_count < x - 1) { 
        // Find minimum weight valid edge.   
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < x; i++) { 
            for (int j = 0; j < x; j++) {                
            //For each iteration, first change the cost of each edge with different random parameters
            //formulae: edgecost = edgecost + edgecost*(random number between 0 and 1) //Cost can only increase and never decrease due to random parameters
            for(r=0;r<x;r++)
            {
            	for(c=0;c<x;c++)
            	{
            		cost[r][c] += cost[r][c]*random_generator();
				}
			}
                if (cost[i][j] < min) { 
                    if (isValidEdge(i, j, inMST)) { 
                        min = cost[i][j]; 
                        a = i; 
                        b = j; 
                    } 
                } 
            } 
        } 
        if (a != -1 && b != -1 ) { 
            printf("Edge %d:(%d, %d) cost: %d \n",  
                         edge_count++, a, b, min); 
            mincost = mincost + min; 
            inMST[b] = inMST[a] = 1; 
        } 
    } 
    printf("\n Minimum cost= %d \n", mincost); 
} 
int main() 
{ 
srand(time(0)); //Declare for Randomization irrespective of time
int i,j;
printf("Enter number of vertex: ");
scanf("%d",&n);
int cost[50][50];
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
}
}
    // Print the solution 
    PSO(cost,n); 
    return 0; 
} 
