//Header Files and Macros
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include<math.h>
#include<cstdlib>
#define NODES 50
#define INT_MAX 100000

int n; //global variable for number of edges in the graph

//Loading Function
void loading()
{
int i;
char ch;
system("reset");
for(i=0;i<25000;i++)
{
printf("Loading Content: %d\n",i+1);
}
system("reset");
}

//Prims Helper Function
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
  
void primMST(int cost[][50],int x) 
{   
clock_t start = clock();
    int inMST[n]; 
  
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
    clock_t end = clock();
    printf("\nMinimum cost= %d \n", mincost); 
    double time = ((double) (end - start))/CLOCKS_PER_SEC;
    time=time*1000000;
    printf("Processing Time: %f MicroSeconds\n",time);
} 

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

//Random Number Generator
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

//Adjancy List
//N nodes -> 0 is V1, 1 is V2,,, k is Vk+1,,,, n-1 is Vn
//Adjancy List ignoring loop, if connected with rest, then added in ordered fashion
struct node
{
	int node_number;
	struct node *next; //for linked list of structures
	struct node *list[20]; //for Adjancy list
};

//PSO Function
void PSO(int c[][50],int x) 
{   
clock_t start = clock();
int i,j;
float cost[50][50];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cost[i][j]=c[i][j];
	}
}
    int inMST[n]; 
float k;
    // Include first vertex in MST 
    inMST[0] = 1; 
    // Keep adding edges while number of included 
    // edges does not become V-1. 
    int edge_count = 0;
float mincost = 0;
    while (edge_count < x - 1) { 
        // Find minimum weight valid edge.   
        float min = INT_MAX;
 int a = -1, b = -1; 
        for (i = 0; i < x; i++) { 
            for (j = 0; j < x; j++) {                
k=random_generator();
                if ((cost[i][j] + cost[i][j]*k) < min) { 
                    if (isValidEdge(i, j, inMST)) { 
                        min = (cost[i][j] + cost[i][j]*k); 
                        a = i; 
                        b = j; 
                    } 
                } 
            } 
        } 
        if (a != -1 && b != -1 ) { 
            printf("Edge %d:(%d, %d) cost: %f \n",  
                         edge_count++, a, b, min); 
            mincost = mincost + min; 
            inMST[b] = inMST[a] = 1; 
        } 
    } 
    printf("\nMinimum cost= %f \n", mincost); 
    clock_t end = clock();
    double time = ((double) (end - start))/CLOCKS_PER_SEC;
    time=time*1000000;
    printf("Processing Time: %f MicroSeconds\n",time);
}

//User creates graph as .csv file
void create_csv(char f1[100])
{
	//printf("Creation of .csv file by user\n");
	//Adjance Matrix is a square matrix n*n with n being the number of nodes in the network
	int i,j,count=0;
	printf("Enter the number of nodes in network: ");
	scanf("%d",&n);
	int ds[100];
	char temp[100];
	// Create a file pointer
	FILE *fp;
	// Create a .csv file
	fp = fopen(f1,"a+");  
	// to update: Ask user for name of csv file to be made and also create a text file to store details of all csv file made till now or 
	//create a code to search for all csv files in current path.
	// Storing number of nodes as first line in adjacency matrix
	sprintf(temp,"%d",n);	
        fputs(temp,fp);
	fputs("\n",fp);
        printf("Enter the Adjancy Matrix values row wise\n");
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
				printf("Enter the cost for %d %d Edge Relation: ",i,j);
				scanf("%d",&ds[count]);
				//temp=ds[count]; //string because fputs only takes string as input
				sprintf(temp,"%d",ds[count]);
				fputs(temp,fp);
				fputs(",",fp);
				count++;
			}
			fputs("\n",fp);
	}
	fclose(fp);
}

//method to find the .csv file in current folder
static int parse_ext(const struct dirent *dir)
   {
     if(!dir)
       return 0;

     if(dir->d_type == DT_REG) 
	 { /* only deal with regular file */
         const char *ext = strrchr(dir->d_name,'.');
         if((!ext) || (ext == dir->d_name))
           return 0;
         else {
           if(strcmp(ext, ".csv") == 0)
             return 1;
         }
     }
     return 0;
}

//Time calculator
void time()
{
//clock_t is capable of calculating processor time and clock funcion is capable of returning the clock time since the program is started
clock_t start = clock(); 
/*
write the program for which you need to calculate the time used by cpu
*/
clock_t end = clock();
clock_t time = ((double) (end - start)) / CLOCKS_PER_SEC;    //number of processor clock ticks per second is CLOCKS_PER_SEC
printf("%ld\n",time);
}

//Module 4
void readcsv(char f1[100])
{
int i,j,kk,count;
  // Declare the file pointer 
  FILE * filePointer;

  // Declare the variable for the data to be read from file 
  char dataToBeRead[50];
int k = 50;
  int array[k][k];
  // Open the existing file GfgTest.c using fopen() 
  // in read mode using "r" attribute 
  filePointer = fopen(f1, "r");

  // Check if this filePointer is null 
  // which maybe if the file does not exist 
  if (filePointer == NULL) {
  	system("reset");
    printf("Selected file failed to open\n Exiting the code\n\n");
    exit(1);
  } else {
  	system("reset");
    printf("The file is now opened.\n");
    count = 0;
    //int k = 50;
	//int i,j;
	j=0;
    //char arr[50][50];
    while (fgets(dataToBeRead, 50, filePointer) != NULL) {
      if (count == 0) {
        // First line of csv contains total number of nodes
        k = atoi(dataToBeRead);
      } else {
        int j = 0;
        int length = (int) strlen(dataToBeRead);
        int kk = 0;

        for (int i = 0; i < length - 1; i++) {
          if (dataToBeRead[i] != ',') {
            kk = kk * 10 + (dataToBeRead[i] - '0');

          } else {
            array[count - 1][j] = kk;
            printf("%d \n", kk);
            kk = 0;
            j++;

          }
        }
        array[count - 1][j] = kk;
        printf("%d \n", kk);
        printf("\n");

      }
      count++;
    }

    // Closing the file using fclose() 
    fclose(filePointer);

    printf("Data successfully read from specified file\n");
    printf("The file is now closed.\n");
    for ( i = 0; i < k; i++) {
      for ( j = 0; j < k; j++) {
        printf("%d ", array[i][j]);
      }
      printf("\n");
    }
    ////Adjancy Matrix to adjancy List
node *ptr,*head,*p;
	n=k;
k=0;
int matrix[50][50];
	node *list1[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matrix[i][j] = array[i][j];
		}
	}
/////////////////Algorithms
//////////////////////////////Till Now!! File Handling Completed!!! Also, Adjancy Matrix extracted and Its Adjancy List is created!!!!/////
  int flag41;
  	system("reset");
  	printf("1. Perform Kruskal's Algorithm\n");
  	printf("2. Perform Prim's Algorithm\n");
  	printf("3. Perform PSO Algorithm\n");
  	printf("Enter your choice: ");
  	scanf("%d",&flag41);
system("reset");
  	switch(flag41)
  	{
  		case 1:
		  printf("Kruskal's Algorithm Application\n");
		  kruskalMST(matrix,n); 
  			break;
  		case 2:
  			printf("Prim's Algorithm Application\n");
  			primMST(matrix,n);
  			break;
  		case 3:
  			printf("Particle Swarm Intelligence Algorithm Application\n");
  			PSO(matrix,n);
  			break;
  		default: printf("Wrong Choice: Retry\n");
	}
	////////////////////////////////////////////////
k=1;
	//Create Linked list for all the Nodes in Network
	for(i=0;i<n;i++)
	{
		ptr = (node*)malloc(sizeof(node));
		//printf("Enter the Unique number for Node: ");
		//scanf("%d",&(ptr->node_number));
		ptr->node_number=k;
		k++;
		//ptr->list=NULL;
		ptr->next=NULL;
		list1[i]=(node*)malloc(sizeof(node));
		for(j=0;j<20;j++)
		{
			list1[i]->list[j]=NULL;
		}
		if(i==0)
		{
			head=(node*)malloc(sizeof(node));
			head=ptr;	
		}
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=ptr;
		}
		list1[i]=ptr;
	}
	////////////////////////////////////////////////
	//Display the Linked List
	p=head;
	//printf("%d\n",head->node_number);
	while(p->next!=NULL)
	{
		//printf("%d\n",ptr->node_number);
		p=p->next;
	}
	//printf("%d",list1[0]->node_number);
	/////////////////////////////////////////////////
	//Create List
	p=head;
	while(p->next!=NULL)
	{
//printf("Check 1\t");
		j=0;
k=p->node_number;
k--;
		for(i=0;i<n;i++)
		{
//	printf("Check 2\t");
			if((matrix[k][i]!=0)&&(i!=k))
			{
//printf("Check 3\n");
				p->list[j++]=list1[i];	
			}
		}
p=p->next;
	}
//printf("Check4");
		j=0;
k=p->node_number;
k--;
		for(i=0;i<n;i++)
		{
//	printf("Check 2\t");
			if((matrix[k][i]!=0)&&(i!=k))
			{
//printf("Check 3\n");
				p->list[j++]=list1[i];	
			}
		}
	/////////////////////////////////////////////////
	//Display Adjancy List
	p=head;
	while(p->next!=NULL)
	{
//printf("%d: ",p->node_number);
		for(i=0;p->list[i]!=NULL;i++)
		{
//			printf("%d\t",p->list[i]->node_number);
		}
printf("\n");
p=p->next;
	}
//printf("%d: ",p->node_number);
		for(i=0;p->list[i]!=NULL;i++)
		{
//			printf("%d\t",p->list[i]->node_number);
		}
printf("\n");
  }
  //system("reset");
}

///////////////////////////////////////MAIN FUNCTION///////////////////////////
int main()
{
	srand(time(0)); //Random Number initialization irrespective of time
	loading();
int ch1,n,count;
char f1[100];
printf("An efficient approach to optimize Network routing using Particle Swarm Intelligence\n\n");
printf("Press 1) Create new graph\n");
printf("Press 2) Use existing graph\n");
printf("Enter your choice: ");
scanf("%d",&ch1);
system("reset");
switch(ch1)
{
case 1: 
printf("User Creation of Template Network Graph\n");
printf("Enter Unique Name of the graph: ");
scanf("%s",&f1);
	create_csv(f1);
break;
case 2:
	printf("Using the already present template files for Networking\n");
printf("Following are the existing .csv files in the current directory\n");
///////////// to get the .csv files in current directory
struct dirent **namelist;
count=1;
       n = scandir(".", &namelist, parse_ext, alphasort);
       if (n < 0) {
           perror("scandir");
           return 1;
       }
       else {
           while (n--) {
               printf("%d: %s\n",count, namelist[n]->d_name);
count++;
               free(namelist[n]);
           }
           free(namelist);
       }
///////////////////
printf("Enter name of the file you want to use: ");
scanf("%s",&f1);
break;
default: printf("Wrong Choice! Exiting Code\n"); exit(1);
}
//Running Module 4 Read CSV -> For Reading the .csv file and creating a 2D array
readcsv(f1); 
printf("\n\nThanks for using our code!\n\n");
return 0;
}
