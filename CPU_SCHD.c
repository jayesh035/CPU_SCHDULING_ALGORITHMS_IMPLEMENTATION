#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pair
{
   int first;
   int second;
};
 struct pa
{
   int first;
   int second;
   int third;
   

};
char ch[100];
int tat[1000];
int wt[1000];
int AT[1000];
int PT[1000];

int CT[1000];
int BT[1000];

void swap(int *a,int *b)
{
   int temp=*a;
   *a=*b;
   *b=temp;
}
int cpfunc (const void *a, const void *b)
{
   return (*(int*)a-*(int*)b);
}
//function for Longest Remaining Time First
int LRTF(int m)
{
int gannt[100];

  printf("%d ",m);

   int queue[1000];


   struct pa p[m];
for( int i=0;i<m;i++)
   {
      p[i].first=BT[i];
      p[i].second=i+1;
      p[i].third=0;

   }

   int t=0;
int y=0;
int front=0;
int end=-1;
int fq[100];

int r=-1;
int z=0;
int finish[m];

while (1>0)
{
   
   int f=0;

   int a=0;
      for(int i=0;i<m;i++)
      {
         if(p[i].first!=0)
         {
            a=1;
            break;
         }
      }
      if(a==0)
      {
         break;
      }

   
 
  
      for(int i=0;i<m;i++)
      {
         if(t>=AT[i] && p[i].first!=0 && p[i].third==0)
         {
          
           queue[y]=p[i].second;
           y++;
            p[i].third=1;
           z=1;
         }
         
      }
   
      
      if(z==0)
      {
         gannt[t]=0;
         t++;
      }
     if(z==1)
      {
         for(int i=0;i<y;i++)
         {
            if(p[queue[i]-1].first==0)
            {
                  queue[i]=0;
                  
            }
         }
         
if(y>1)
{
int k=0;
   int x=0;

int man=0;
   
   
   
   for(int i=0;i<y;i++)
      {
        // printf("%d",queue[i]);
        
         if(man<p[queue[i]-1].first && queue[i]!=0)
            {
               man=p[queue[i]-1].first;
               k=queue[i];
            }
         
           

      }
      for(int i=0;i<y;i++)
      {
         if(man==p[queue[i]-1].first)
         {
                k=queue[i];
                break;
         }
      }

gannt[t]=k;

      t++;
      p[k-1].first=p[k-1].first-1;
      if(p[k-1].first==0)
      {
         finish[k-1]=t;
      }
      

} 
       
else
{
   
gannt[t]=queue[0];

      t++;
      p[queue[0]-1].first=p[queue[0]-1].first-1;
       if(p[queue[0]-1].first==0)
      {
         finish[queue[0]-1]=t;
      }
}
}

   
      
}
printf("Gannt chart:");
for(int i=0;i<t;i++)
{
   if(gannt[i]!=0)
   {
printf("p%d-> ",gannt[i]);
   }
   else{
      printf("IDLE|->");
   }
   
}
printf("\n");
float TAT=0;
float WT=0;
for(int i=0;i<m;i++)
{
  TAT+=(finish[i]-AT[i]);
  WT+=(finish[i]-AT[i])-BT[i];
}
printf("\navarage turn around time:%f  \navarage turn around time:%f",TAT/m,WT/m);


}
//function for Priority Schduling
int Priority(int m)
{
  

   int queue[m];
int finish[m];

   struct pa p[m];
for(int i=0;i<m;i++)
   {
      p[i].first=BT[i];
      p[i].second=i+1;
      p[i].third=0;

   }

   for(int i=0;i<m;i++)
   {
      printf("%d %d %d\n",AT[i],BT[i],PT[i]);
   }
 
   

int gannt[100];
int t=0;
int y=0;
int front=0;
int end=-1;
int fq[100];

int r=-1;
int com=0;
int z=0;
while (com<m)
{

   
 
  
      for(int i=0;i<m;i++)
      {
         if(t>=AT[i] && p[i].first!=0 && p[i].third==0)
         {
          
           queue[y]=p[i].second;
           y++;
            p[i].third=1;
           z=1;
         }
         
      }
   
      
      if(z==0)
      {
         gannt[t]=0;
         t++;
      }
      

      if(z==1)
      {
         for(int i=0;i<y;i++)
         {
            if(p[queue[i]-1].first==0)
            {
                  queue[i]=0;
            }
         }
         
if(y>1)
{
int k=0;
   int x=0;

int min=0;
   
   
   
   for(int i=0;i<y;i++)
      {
        // printf("%d",queue[i]);
        
         if(min<=PT[queue[i]-1] && queue[i]!=0)
            {
               min=PT[queue[i]-1];
               k=queue[i];
            }
         
           

      }

gannt[t]=k;

      t++;
      p[k-1].first=p[k-1].first-1;

      if(p[k-1].first==0)
      {
         finish[k-1]=t;
         
com++;
      }
      
      
       

}
else
{
   
gannt[t]=queue[0];

      t++;
      p[queue[0]-1].first=p[queue[0]-1].first-1;

      if(p[queue[0]-1].first==0)
      {
         finish[queue[0]-1]=t;
         
com++;
      }
}
   
     
      }


      



}

printf("Gannt chart:");
for(int i=0;i<t;i++)
{
   if(gannt[i]!=0)
   {
printf("p%d-> ",gannt[i]);
   }
   if(gannt[i]==0){
      printf("IDLE|->");
   }
   
}
printf("\n");
float TAT=0;
float WT=0;
for(int i=0;i<m;i++)
{
  TAT+=(finish[i]-AT[i]);
  WT+=(finish[i]-AT[i])-BT[i];
}
printf("\navarage turn around time:%f  \navarage turn around time:%f",TAT/m,WT/m);



}
//function for Round Robin
int RR(int m,int tq)
{
   
  
   int queue[1000];

   int finish[m];

   int gannt[100];
   struct pa p[m];
   for(int i=0;i<m;i++)
   {
      p[i].first=BT[i];
      p[i].second=i+1;
      p[i].third=0;
      

   }
   //int at[1000];
int t=0;
int y=0;
int front=0;
int end=-1;
int fq[100];
int f=0;
int r=-1;
   while(1>0)
   {
         
      int a=0;
      for(int i=0;i<m;i++)
      {
         if(p[i].first!=0)
         {
            a=1;
            break;
         }
      }
      if(a==0)
      {
         break;
      }
      int z=0;
     
      int l=0;
      int pt=0;
      int i=0;
      for(int i=0;i<m;i++)
      {
         
         if(t>=AT[i] && p[i].first!=0 &&p[i].third==0)
         {
            int j=i;
            while(j<m)
            {
              
if(AT[j]==AT[i] && p[j].first!=0 &&p[j].third==0)
{
end++;
           queue[end]=p[j].second;
            
            p[j].third=1;
           z=1;
}
 j++;
            
            }

          
            
          
         }
      }
      while (f<=r)
       {
         end++;
           queue[end]=fq[f];
            
            f++;
           z=1;
       }
       
       
      
        if(z==0)
      {
         gannt[t]=0;
         t++;
         
      }

      if(z==1)
      {

      while(front<=end)
      {
         
         if(p[queue[front]-1].first>tq)
         {
            for(int j=0;j<tq;j++)
            {
             gannt[t]=queue[front];
             t++;
            }
            
           p[queue[front]-1].first=p[queue[front]-1].first-tq;
       
         }
         else
         {
            for(int i=0;i<p[queue[front]-1].first;i++)
            {
            gannt[t]=queue[front];
             t++;
            }
             p[queue[front]-1].first=0;
            
             
         }
         int s=0;
         p[queue[front]-1].third=1;
         if( p[queue[front]-1].first!=0)
         {
                 for(int i=0;i<m;i++)
      {
         
         if(t>=AT[i] && p[i].first!=0 &&p[i].third==0)
         {
            s=1;
            int j=i;
            while(j<m)
            {
              
if(AT[j]==AT[i] && p[j].first!=0 &&p[j].third==0)
{
end++;
           queue[end]=p[j].second;
            
            p[j].third=1;
           z=1;
}
 j++;
            
            }
end++;
           queue[end]=p[queue[front]-1].second;
            
            p[queue[front]-1].third=1;

break;
          
            
          
         }
        
      }
      if(s==0)
      {
         end++;
           queue[end]=p[queue[front]-1].second;
            
            p[queue[front]-1].third=1;
      }
         }
         else  if( p[queue[front]-1].first==0)
         {
              
           finish[queue[front]-1]=t;
         }
         
       front++;
         
      }
      
      }



         }
  printf("Gannt chart:");
for(int i=0;i<t;i++)
{
   if(gannt[i]!=0)
   {
printf("p%d-> ",gannt[i]);
   }
   else{
      printf("IDLE|->");
   }
   
}
printf("\n");
float TAT=0;
float WT=0;
for(int i=0;i<m;i++)
{
  TAT+=(finish[i]-AT[i]);
  WT+=(finish[i]-AT[i])-BT[i];
}
printf("\navarage turn around time:%f  \navarage turn around time:%f",TAT/m,WT/m);
         
}

//function for Shortest Remaining Time First
int SRTF(int m)
{
  int finish[m];
   int gannt[100];
   struct pa p[m];
   for(int i=0;i<m;i++)
   {
      p[i].first=BT[i];
      p[i].second=i+1;
      p[i].third=0;
   }


int t=0;

   while(1>0)
   {
      int a=0;
      for(int i=0;i<m;i++)
      {
         if(p[i].first!=0)
         {
            a=1;
            break;
         }
      }
      if(a==0)
      {
         break;
      }
      int z=0;
      int at[m];
      int l=0;
      for(int i=0;i<m;i++)
      {
         if(t>=AT[i] && p[i].first!=0)
         {
            at[l]=p[i].first;
            l++;
            
           z=1;
         }
      }
        if(z==0)
      {
         gannt[t]=0;
         t++;
         
      }
      if(z==1)
      {
   int min=__INT16_MAX__;
      for(int i=0;i<l;i++)
      {
         if(min>at[i])
         {
            min=at[i];

         }
      }
      for(int i=0;i<m;i++)
      {
         if(min==p[i].first && AT[i]<=t)
         {
            gannt[t]=p[i].second;
            t++;
            p[i].first-=1;

            if(p[i].first==0)
            {
               finish[i]=t;
            }
            break;
         }
      }
      }
         }

printf("Gannt chart:");
for(int i=0;i<t;i++)
{
   if(gannt[i]!=0)
   {
printf("p%d-> ",gannt[i]);
   }
   else{
      printf("IDLE|->");
   }
   
}
   printf("\n");
float TAT=0;
float WT=0;
for(int i=0;i<m;i++)
{
  TAT+=(finish[i]-AT[i]);
  WT+=(finish[i]-AT[i])-BT[i];
}
printf("\navarage turn around time:%f  \navarage turn around time:%f",TAT/m,WT/m);


}

//function for Shortest job first
int SJF(int m)
{
  int finish[m];
   int gannt[100];
   struct pa p[m];
   for(int i=0;i<m;i++)
   {
      p[i].first=BT[i];
      p[i].second=i+1;
      p[i].third=0;
   }


int t=0;

   while(1>0)
   {
      int a=0;
      for(int i=0;i<m;i++)
      {
         if(p[i].first!=0)
         {
            a=1;
            break;
         }
      }
      if(a==0)
      {
         break;
      }
      int z=0;
      int at[m];
      int l=0;
      for(int i=0;i<m;i++)
      {
         if(t>=AT[i] && p[i].first!=0)
         {
            at[l]=p[i].first;
            l++;
            
           z=1;
         }
      }
        if(z==0)
      {
         gannt[t]=0;
         t++;
         
      }
      if(z==1)
      {
   int min=__INT16_MAX__;
      for(int i=0;i<l;i++)
      {
         if(min>at[i])
         {
            min=at[i];

         }
      }
      for(int i=0;i<m;i++)
      {
         if(min==p[i].first && AT[i]<=t)
         {
           for(int j=0;j<p[i].first;j++)
           {
            gannt[t]=p[i].second;
            t++;
           }
           p[i].first=0;
           finish[i]=t;
            break;
         }
      }
      }
         }
printf("Gannt chart:");
for(int i=0;i<t;i++)
{
   if(gannt[i]!=0)
   {
printf("p%d-> ",gannt[i]);
   }
   else{
      printf("IDLE|->");
   }
   
}

printf("\n");
float TAT=0;
float WT=0;
for(int i=0;i<m;i++)
{
  TAT+=(finish[i]-AT[i]);
  WT+=(finish[i]-AT[i])-BT[i];
}
printf("\navarage turn around time:%f  \navarage turn around time:%f",TAT/m,WT/m);
}


// function for counting number of processes
int countraw()
{
   FILE* fp;
   char c;
   int count=0;
   fp=fopen("inp.txt","r");
   for (c = getc(fp); c != EOF; c = getc(fp))
   {


  if (c == '\n') // Increment count if this character is newline
  {
         count = count + 1;
  }



   }
      
      fclose(fp);

   return count;
 
}
// function to read input from file 
void init(int m,int x)
{


int l=0,z=0,y=0;

 FILE* ptr;
char c;
int count=0;
ptr=fopen("inp.txt","r");

int co=0;
int fl=0;
int n=4;
int a[3];

for(int i=0;i<m;i++)
{
   if(x==1)
   {
fscanf(ptr,"%d %d %d",&AT[i],&BT[i],&PT[i]);
   }

   else{
      fscanf(ptr,"%d %d",&AT[i],&BT[i]);
   }
   
}
}


//Function for First Come First Serve Algorithm
int FCFS(int m)
{
int gannt[1000];  // Array for gannt chart
int k=1;
int n=0;
int x=0;
int t=0;
int finish[m];    // Array to store finish time for each process
int completed=0;
struct pair p[m];
for(int i=0;i<m;i++)
{
   p[i].first=BT[i];
   p[i].second=i+1;
}
int f;
while (completed<m)
{f=0;
   for(int i=0;i<m;i++)
   {
      if(t>=AT[i]&& p[i].first>0)
      {
         for(int k=0;k<p[i].first;k++)
         {
               gannt[t]=p[i].second;
               t++;
         }
         finish[i]=t;
         p[i].second=0;
         f=1;
         completed++;
      }
   }
   if(f==0)
   {
      gannt[t]=0;
      t++;
   }
}
printf("Gannt chart:");
for(int i=0;i<t;i++)
{
   if(gannt[i]!=0)
   {
printf("p%d-> ",gannt[i]);
   }
   else{
      printf("IDLE|->");
   }
   
}

 printf("\n");
float TAT=0;
float WT=0;
for(int i=0;i<m;i++)
{
  TAT+=(finish[i]-AT[i]);
  WT+=(finish[i]-AT[i])-BT[i];
}
printf("\navarage turn around time:%f  \navarage turn around time:%f",TAT/m,WT/m);

}




int main()
{
printf("Enter your choice:");

printf("\na) First-Come First-Served-(non-preemptive)");
printf("\nb) Shortest Job First-(non-preemptive)");
printf("\nc) Round Robin Scheduling");
printf("\nd) Priority Scheduling");
printf("\ne) Shortest Remaining Time First");
printf("\nf) Longest remaining time first");

printf("\nEnter:  ");

char c;


scanf("%c",&c);


int m=countraw();
int x;

if(c=='a')
{
   x=0;
init(m,x);
FCFS(m);
}
else if(c=='b')
{
   x=0;
init(m,x);

SJF(m);
}
else if(c=='e')
{
   x=0;
init(m,x);
SRTF(m);
}
else if(c=='c')
{
   x=0;
init(m,x);
printf("Enter the time quantum: ");
int tq;
scanf("%d",&tq);
RR(m,tq);
}
else if(c=='d')
{
   x=1;
init(m,x);

Priority(m);
}
else if(c=='f')
{
   x=0;
init(m,x);
LRTF(m);
}






}

