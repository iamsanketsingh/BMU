#include<stdio.h>
#include<stdlib.h>
int process[100],priority_arr[100],burst_time_arr[100],n;
void insert();
void FCFS();
void priority_scheduling();
void sjf_scheduling();
void sjf(int,int);
void display1();
void priority(int,int,int);
void display();
void fcfs(int,int);
void display2();
int turn_around_time=0,	waiting_time=0;
int process_number,burst_time,priority1;
struct node{
	int data_priority;
	int data_sjf;
	int data_fcfs;
	int priority;
	int burst_time_priority;
	int burst_time_sjf;
	int burst_time_fcfs;
	int wait_time_priority;
	int wait_time_sjf;
	int wait_time_fcfs;
	struct node *next;
}*start_priority,*start_sjf,*start_fcfs,*q_priority,*q_sjf,*q_fcfs,*t_priority,*t_fcfs,*t_sjf,*rear,*front;
int main()
{

	int choice1,choice2,choice;
	do{    
	 printf("\t\t\t\t\t\tCPU SCHEDULING PROGRAM \n Which data structure you want to use for scheduling:- ");
	printf("\n 1. press 1 if you want to use linked list \n 2. press 2 if you want to use array \n 3. press -1 for exit ");
	scanf("%d",&choice);
	switch(choice){
		
	      
	        case 1:
	
	       do
	        {
	        
	          	    printf("enter your choice \n 1. press 1 to Enter the values \n 2. press 2 for FCFS Scheduling \n 3. press 3 for Priority Scheduling \n 4. press 4 for Shortest Job First Scheduling \n 5. press -1 to exit the loop \nEnter Your choice- ");
	                scanf("%d",&choice1);
	                printf("\n");
	                switch(choice1)
	             {
                   	case 1:printf("Enter the Process Number:- ");
							scanf("%d",&process_number);
							printf("Enter the Burst Time of Process:- ");
							scanf("%d",&burst_time);
							printf("Enter the Priority of Process:- ");
							scanf("%d",&priority1);
							printf("\n");
							
							fcfs(process_number,burst_time);
							 priority(process_number,burst_time,priority1);
							 sjf(process_number,burst_time);
                   	break;
                    case 2:
                              display2();
                   	break;
                    case 3:  
                             display();
                   	break;
                   	case 4:  
                              display1();
                   	break;
	                default: printf("'WRONG CHOICE' \n");
                 	break;
					}//end of switch
	             } while(choice1!=-1);
	             break;
	             
	        case 2: do                                     // using array
	 {
	 
	   printf("\nEnter your choice for scheduling ");
       printf("\n 1. Enter 1 to enter the values  \n 2. Enter 2 for FCFS scheduling \n 3. Enter 3 for Shortest Job First scheduling(SJF) \n  4. Enter 4 for Priority Scheduling\n Enter -1 to exit he program\n ");
	   scanf("%d",&choice2);
	   
	 switch(choice2)
	 {
	 	case 1:	insert();
	            break;
	    
		case 2:
        	if(n==0)
		{
		printf("\nplease enter the values first then try out the program\n");
		 break;
		} 
		else 
		{
		  FCFS();                  // FCFS scheduling using array
          break;
         }
	 	
	
	   case 3:
	
	    if(n==0)
		{
		printf("\nplease enter the values first then try out the program\n");
		 break;
		} 
		else 
		{
		  sjf_scheduling();                  // shortest job first scheduling using array
          break;
         }
        case 4: 
		 if(n==0)
		{
		 printf("\nplease enter the values first then try out the program\n");
		 break;
		}
		
		 else
	   {
         priority_scheduling();              // priority scheduling using array
         break;
	   } 	 
	 	default: printf("\nDear user you have entered the wrong choice\n");
	 	break;
	 }
    }while(choice2!=-1);
        break;

        default: printf("WRONG CHOICE");
        break;
    }
      }while(choice!=-1);
return 0;
}

void priority(int process_number,int burst_time,int priority1)
{ 
t_priority=(struct node*)malloc(sizeof(struct node));
t_priority->data_priority=process_number;
t_priority->burst_time_priority=burst_time;
t_priority->priority=priority1;
if(start_priority==NULL)
{
	t_priority->next=NULL;
	start_priority=t_priority;
	
}

else
{   q_priority=start_priority;
   if(q_priority->priority > t_priority->priority)          // if the priority of the new process is high then the process which is present in start
   {
   	t_priority->next=q_priority;
   	start_priority=t_priority;
   }
   
   else{
   q_priority=start_priority;
   while(q_priority->next!=NULL && (q_priority->next)->priority <= t_priority->priority)      
   {
   	q_priority=q_priority->next;
   }
   t_priority->next=q_priority->next;           // q->next value is assigned to the t->next and then q->next will point towards t
   q_priority->next=t_priority;
}
}
q_priority=start_priority;
waiting_time=0;
while(q_priority->next!=NULL){
waiting_time+=q_priority->burst_time_priority;
q_priority=q_priority->next;
q_priority->wait_time_priority=waiting_time;	
}

}
void display()
{    
		q_priority=start_priority;
	if(q_priority==NULL)
{
	printf("please first enter the values");
}
printf("\n\n\t\tPRIORITY TABLE");
	puts("\n+-----+------------+--------------+-----------------+");
     puts("| PID | Burst Time | Waiting Time | Priority        |");
     puts("+-----+------------+--------------+-----------------+");
while(q_priority!=NULL)
	{
		printf("| %2d  |     %2d     |      %2d      |        %2d       |\n",q_priority->data_priority,q_priority->burst_time_priority,q_priority->wait_time_priority,q_priority->priority);
		q_priority=q_priority->next;
		puts("+-----+------------+--------------+-----------------+");
	}
printf("\n");
}


void sjf(int process_number,int burst_time)
{ 
t_sjf=(struct node*)malloc(sizeof(struct node));
t_sjf->data_sjf=process_number;
t_sjf->burst_time_sjf=burst_time;


if(start_sjf==NULL)
{
	t_sjf->next=NULL;
	start_sjf=t_sjf;
	
}

else
{   q_sjf=start_sjf;
   if(q_sjf->burst_time_sjf > t_sjf->burst_time_sjf)          // if the burst time of the new process low then the process which is present in start
   {
   	t_sjf->next=q_sjf;
   	start_sjf=t_sjf;
   }
   
   else{
   q_sjf=start_sjf;
   while(q_sjf->next!=NULL && (q_sjf->next)->burst_time_sjf <= t_sjf->burst_time_sjf)      
   {
   	q_sjf=q_sjf->next;
   }
   t_sjf->next=q_sjf->next;           // q->next value is assigned to the t->next and then q->next will point towards t
   q_sjf->next=t_sjf;
 
}
}
q_sjf=start_sjf;
waiting_time=0;
while(q_sjf->next!=NULL){
waiting_time+=q_sjf->burst_time_sjf;	
q_sjf=q_sjf->next;
q_sjf->wait_time_sjf=waiting_time;
}

}

void display1()
{    
   
	q_sjf=start_sjf;
	if(q_sjf==NULL)
{
	printf("please first enter the values");
}
printf("\n\n    SHORTEST JOB FIRST TABLE");
	puts("\n+-----+------------+--------------+");
     puts("| PID | Burst Time | Waiting Time |");
     puts("+-----+------------+--------------+");
while(q_sjf!=NULL)
	{
		printf("| %2d  |     %2d     |      %2d      |\n",q_sjf->data_sjf,q_sjf->burst_time_sjf,q_sjf->wait_time_sjf);
		q_sjf=q_sjf->next;
		puts("+-----+------------+--------------+");
	}
printf("\n");
}
void fcfs(int process_number,int burst_time)
{
t_fcfs=(struct node*)malloc(sizeof(struct node));
t_fcfs->data_fcfs=process_number;
t_fcfs->burst_time_fcfs=burst_time;

if(front==NULL)
{
    front=rear=t_fcfs;   
   	front->next=rear->next=t_fcfs->next=NULL;	
}
else
{
	rear->next=t_fcfs;
	rear=t_fcfs;
	rear->next=NULL;
}
q_fcfs=front;
waiting_time=0;
while(q_fcfs->next!=NULL){
waiting_time+=q_fcfs->burst_time_fcfs;	
q_fcfs=q_fcfs->next;
}
q_fcfs->wait_time_fcfs=waiting_time;
}


void display2()
{
q_fcfs=front;
if(q_fcfs==NULL)
{
	printf("please first enter the values");
}
printf("\n\n    FIRST COME FIRST SERVE TABLE");
	puts("\n+-----+------------+--------------+");
     puts("| PID | Burst Time | Waiting Time |");
     puts("+-----+------------+--------------+");
while(q_fcfs!=NULL)
	{
		printf("| %2d  |     %2d     |      %2d      |\n",q_fcfs->data_fcfs,q_fcfs->burst_time_fcfs,q_fcfs->wait_time_fcfs);
		q_fcfs=q_fcfs->next;
		puts("+-----+------------+--------------+");
	}
printf("\n");
}





void priority_scheduling()
{
	int i,j,k,waiting_time[100],turn_around_time[100],temp,temp1,temp2,total_waitingtime,total_turnaroundtime;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
		if(priority[i]>priority[j])
			{
				temp=priority_arr[j];
				priority_arr[j]=priority_arr[i];
				priority_arr[i]=temp;

				temp1=burst_time_arr[j];
				burst_time_arr[j]=burst_time_arr[i];
				burst_time_arr[i]=temp1;

				temp2=process[j];
				process[j]=process[i];
				process[i]=temp2;
			}
		}
	}
	waiting_time[0]=0;
	for(i=0;i<n;i++)
    {
       waiting_time[i]=0;
        for(j=0;j<i;j++)
           {
            waiting_time[i]+=burst_time_arr[j];
       }
      total_waitingtime+=waiting_time[i];
    }
    for(i=0;i<n;i++)
    {
        turn_around_time[i]=burst_time_arr[i]+waiting_time[i];
        total_turnaroundtime+=turn_around_time[i];
    }
    int avg_waiting_time=total_waitingtime/n;
    int avg_turn_around_time=total_turnaroundtime/n;
    printf("\n\n\t\tPRIORITY TABLE");
     puts("\n+-----+------------+--------------+-----------------+");
    puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-----+------------+--------------+-----------------+");
     for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , priority_arr[i], burst_time_arr[i], waiting_time[i], turn_around_time[i] );
        puts("+-----+------------+--------------+-----------------+");
    }
    puts(""); 
    printf("Total Waiting Time      : %d\n", avg_waiting_time);
    printf("Total Turnaround Time   : %-2d\n", avg_turn_around_time);
}

void sjf_scheduling()
{
	int i,j,k,waiting_time[100],turn_around_time[100],temp,temp1,temp2,total_waitingtime,total_turnaroundtime;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
		if(burst_time_arr[i]>burst_time_arr[j])
			{
				temp1=burst_time_arr[j];
				burst_time_arr[j]=burst_time_arr[i];
				burst_time_arr[i]=temp1;

				temp2=process[j];
				process[j]=process[i];
				process[i]=temp2;
			}
		}
	}
	waiting_time[0]=0;
	for(i=0;i<n;i++)
    {
       waiting_time[i]=0;
        for(j=0;j<i;j++)
           {
            waiting_time[i]+=burst_time_arr[j];
       }
      total_waitingtime+=waiting_time[i];
    }
    for(i=0;i<n;i++)
    {
        turn_around_time[i]=burst_time_arr[i]+waiting_time[i];
        total_turnaroundtime+=turn_around_time[i];
    }
    int avg_waiting_time=total_waitingtime/n;
    int avg_turn_around_time=total_turnaroundtime/n;
    printf("\n\n\t\tSHORTEST JOB FIRST TABLE");
     puts("\n+-----+------------+--------------+-----------------+");
     puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
     puts("+-----+------------+--------------+-----------------+");
     for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               ,i+1, burst_time_arr[i], waiting_time[i], turn_around_time[i] );
        puts("+-----+------------+--------------+-----------------+");
    }
	puts(""); 
    printf("Total Waiting Time      : %d\n", avg_waiting_time);
    printf("Total Turnaround Time   : %-2d\n", avg_turn_around_time);
}

void FCFS()
{
	int i,j,k,waiting_time[100],turn_around_time[100],temp,temp1,temp2,total_waitingtime,total_turnaroundtime;
	waiting_time[0]=0;
	for(i=0;i<n;i++)
    {
       waiting_time[i]=0;
        for(j=0;j<i;j++)
           {
            waiting_time[i]+=burst_time_arr[j];
       }
      total_waitingtime+=waiting_time[i];
    }
    for(i=0;i<n;i++)
    {
        turn_around_time[i]=burst_time_arr[i]+waiting_time[i];
        total_turnaroundtime+=turn_around_time[i];
    }
    int avg_waiting_time=total_waitingtime/n;
    int avg_turn_around_time=total_turnaroundtime/n;
    printf("\n\n\t\tFIRST COME FIRST SERVE TABLE");
     puts("\n+-----+------------+--------------+-----------------+");
     puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
     puts("+-----+------------+--------------+-----------------+");
     for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               ,i+1, burst_time_arr[i], waiting_time[i], turn_around_time[i] );
        puts("+-----+------------+--------------+-----------------+");
    }
	puts(""); 
    printf("Total Waiting Time      : %d\n", avg_waiting_time);
    printf("Total Turnaround Time   : %-2d\n", avg_turn_around_time);
}


void insert()
{
        int i,j,k;
	 	printf("\nenter the number of processes you want to enter ");
	    scanf("%d",&n);
	    printf("\nenter the priority for processes ");
	    for(i=0;i<n;i++)
	    {
		printf("\nEnter priority for %dth process:-",i+1);
		scanf("%d",&priority_arr[i]);
	    }
	    printf("\nenter the burst time for processes ");
	    for(i=0;i<n;i++)
	    {
		printf("\nEnter burst time for %dth process:-",i+1);
		scanf("%d",&burst_time_arr[i]);
	    }	
}
