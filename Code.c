#include<stdio.h>                                                                                                                           //Code created by Shourav Deb
#include<conio.h>
#include<time.h>
#include<windows.h>


void node (int n){


int i,j;

int **graph = (int **)malloc(n * sizeof(int *));     // Dynamic space allocation //
   for (i=0; i<n; i++)
        graph[i] = (int *)malloc(n * sizeof(int));


   for(i=0; i<n; i++ )
   for(j=i+1; j<n; j++)
      graph[i][j] = graph[j][i] = rand()%2;         // Random undirected graph initialize //


struct timespec start, end;
clock_gettime(CLOCK_REALTIME, &start);             // Start time for computation //

int total_edges = 0;
   for(i = 0 ; i < n ; i++)
   for(j = i + 1 ; j < n ; j++)
        if (graph[i][j] == 1)
            total_edges++;                        // Counting edges //


int total_degrees = 0;
  for(i = 0 ; i < n ; i++ )
  for(j = 0 ; j < n ; j++)
       if (graph[i][j] == 1)
           total_degrees++;                      // Computing degrees //

int flag;

   if(total_degrees == 2 * total_edges)         // Verifying Handshaking theorem //
   flag = 1;
   else
   flag = 0;

clock_gettime(CLOCK_REALTIME, &end);           // End time for computation //

/*                                                 // Remove comment to Represent the graph using adjacency matrix //
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
for(i=0; i<n; i++ )
{
for(j=i+1; j<n; j++)
{printf("\t|%d|",graph[i][j]);}
printf("\n");
}
*/

SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_BLUE |  FOREGROUND_INTENSITY);   // Printing all values //
printf("For %d vertice's we got :-\n",n);
printf("----------------------------\n\n");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
printf("\t\tNumber Edges = %d. \n",total_edges);
printf("\t\tSum of Degrees = %d. \n",total_degrees);
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_INTENSITY);
if(flag == 1)
printf("\t\tIt holds Handshaking theorem! \n");
else
printf("\t\tIt does not holds Handshaking theorem! \n");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
double nanos = (double)(end.tv_nsec - start.tv_nsec);
double ms = nanos/1000000;
printf("\t\tComputational time = %.2f ms.\n\n\n",ms);                               // Showing Computational Time  //

/*                                              // Remove comment to Get value 1 by 1 //
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_BLUE |  FOREGROUND_INTENSITY);
printf("Press enter to get the next graph results ...............\n\n");
getch();
*/

}


int main()
{
    node(1000);
    node(2000);
    node(3000);
    node(4000);
    node(5000);
}                                                                                                                            //Code created by Shourav Deb
