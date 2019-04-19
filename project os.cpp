#include<conio.h>
#include<stdio.h>
int main()
{
 int number_process, resources;  										 //for number of process and for number of resources available to system
 int i,j,k,up=0,down=0;
 int allocated[5][5],max[5][5],need[5][5]; 			//max 5 in need of resources and allocated resources
 int instance[10],p[20];										//available instances of resources 5, processes 5   Max

printf("\t\t\t\t\t\t\t\t********************************\n");

printf("\t\t\t\t\t\t\t\t*                              *\n");

printf("\t\t\t\t\t\t\t\t*        Welcome Dear User     *\n");

printf("\t\t\t\t\t\t\t\t*                              *\n");

printf("\t\t\t\t\t\t\t\t********************************");
 	printf("\n\n\n\t\t\tEnter the number of process :");
 		scanf("%d",&number_process);
 	printf("\n\t\t\tEnter the number of resources available  : ");
 		scanf("%d",&resources);
 printf("\n\n\t\t\tEnter the number of insatnces for each resources : \n");
 		for(i=0;i<resources;i++) 
		 {  
		    printf("\t\t\tR%d ",i+1);				// Particular resource
			scanf("%d",&instance[i]);             // instances of a resource (max 5)
 		 }

 printf("\n\n\t\t\tEnter number of resources needed by process  -\n");

		 for(i=0;i<number_process;i++)
		 {
				 printf("\t\t\tp%d\t=",i+1);           //asking for resources needed by a particular process
			 for(j=0;j<resources;j++)
			 {
  				scanf("%d",&max[i][j]);           //storing in matrix 
			 }
		 }

 printf("\n\n\t\t\tEnter already allocated resources:  \n");
 		for(i=0;i<number_process;i++)
 		{
 				printf("\t\t\tp%d\t=",i+1);         
 				p[i]=0;						// allocating resources to a particular process in array
 			for(j=0;j<resources;j++)
 			{
 				 scanf("%d",&allocated[i][j]);		//putting the allocated resources in matrix
 			}
		}
printf("\n\t\t\tResources needed by-");				//remaining resources to be allocated to a process to complete processing
 		for(i=0;i<number_process;i++)
		 {
				 printf("\n\t\t\tp%d\t",i+1) ;    
 			for(j=0;j<resources;j++)
			{
				need[i][j]=max[i][j]-allocated[i][j];  // calculating remaining needs process by process
 				printf("\t\t\t\t%d",need[i][j]);
  			}
		 }
// solving the resourse allocation		 
printf("\n\n");
 	while(k<15)
 		{
 			for(i=0;i<number_process;i++)
 			{  
			 	up=0;
 				for(j=0;j<resources;j++)
 				{
  					if(p[i]==1) 
					  break;
  					if(need[i][j]<=instance[j])              
  					{
  						up++;
  					}
  					if(up==resources)
  					{
  						printf("\n\t\t\tOrder of execution is-");
  						for(j=0;j<resources;j++)
  						{
  							instance[j]+=allocated[i][j];
  						}
  						
  						printf("\n\t\t\t\tp%d\t",i+1); 
						  p[i]=1;    
						  down++;
  					}
 				}					
 			} 
		k++;
 		}
 	if(down<number_process-1)
 	{
 		printf("\n deadlock ");       // in case ifr there is a cycle formation in the prosesses execution
 	}
    getch();
 }
