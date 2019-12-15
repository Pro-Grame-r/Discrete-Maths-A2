#include<iostream> 
#include <string.h>      

#define len 100000



using namespace :: std;    


struct node
	{   
    	char puzz[10];   
    	char road[100];   
	};   
node Start,finalstate,open[368800];       
	bool closed[368800]={0}; 
  
 

 

class Puzzle {

	private:


	int head,tail;  
	long Counter;   
	public:
	
	Puzzle()
	{	
		
		Counter=1;
		head=0;
		tail=1;  
	}
	
 
 void count(int *r,int *c,node u) 
{   
    int i;   
    
	for(i=0;i<10;i++)   
        if(u.puzz[i]=='0')   
        {   
            *r=i/3;*c=i%3;   
            break;   
        }   
}
 
 node takeof()    
{   
    node t;   
    t=open[head++];   
    head=head%len;   
    return t;   
} 
 
 
 
 
int Possiblemoves(node *u,int r,int c,int i,int num)      
{   
    char s;   
    switch(i)   
    {   
    case 0: r--;    
            if(r>=0)   
            {   
                s=u->puzz[(r+1)*3+c];   
                u->puzz[(r+1)*3+c]=u->puzz[r*3+c];   
                u->puzz[r*3+c]=s;   
                u->road[num]=48+i;    
                return 1;   
            }   
            break;   
    case 1: c--;     
          if(c>=0)   
          {   
              s=u->puzz[3*r+c+1];   
              u->puzz[3*r+c+1]=u->puzz[3*r+c];   
              u->puzz[3*r+c]=s;   
              u->road[num]=48+i;     
              return 1;   
          }   
          break;   
    case 2: r++;    
            if(r<=2)   
            {   
                s=u->puzz[(r-1)*3+c];   
                u->puzz[(r-1)*3+c]=u->puzz[r*3+c];   
                u->puzz[r*3+c]=s;   
                u->road[num]=48+i;  
                return 1;   
            }   
            break;   
    case 3: c++;       
          if(c<=2)   
          {   
              s=u->puzz[3*r+c-1];   
              u->puzz[3*r+c-1]=u->puzz[3*r+c];   
              u->puzz[3*r+c]=s;   
              u->road[num]=48+i;     
              return 1;   
          }   
    }   
    return 0;   
}   





   
int empty(void)   
{   
    if(head==tail)   
    {   
    exit(0);   
    }   
        return 0;   
}   
  
void move(node *u,int r,int c,char ch)   
{   
    char s;   
    switch(ch)   
    {   
    case '0':  r--;    
            if(r>=0)   
            {   
                s=u->puzz[(r+1)*3+c];   
                u->puzz[(r+1)*3+c]=u->puzz[r*3+c];   
                u->puzz[r*3+c]=s;}   
                break;   
    case '1': c--;   
          if(c>=0)   
          {   
              s=u->puzz[3*r+c+1];   
              u->puzz[3*r+c+1]=u->puzz[3*r+c];   
              u->puzz[3*r+c]=s;}   
              break;   
             
    case '2': r++;     
            if(r<=2)   
            {   
                s=u->puzz[(r-1)*3+c];   
                u->puzz[(r-1)*3+c]=u->puzz[r*3+c];   
                u->puzz[r*3+c]=s;         
            }   
            break;   
    case '3': c++;   
          if(c<=2)   
          {   
              s=u->puzz[3*r+c-1];   
              u->puzz[3*r+c-1]=u->puzz[3*r+c];   
              u->puzz[3*r+c]=s;   
          }   
    }   
}   

int factor(int n)   
{   
    int i,sum=1;   
    for(i=1;i<=n;i++)   
        sum*=i;   
    return sum;   
}     
  
  
int sortit(char Start[],int a)  
{   
    int i,j,sum,total=0;   
    for(j=0;j<=a-2;j++)   
    {   
        sum=0;   
        for(i=j+1;i<=a-1;i++)   
        {   
            if(Start[j]>Start[i])   
                sum++;   
        }   
        sum=sum*factor(a-1-j);   
        total+=sum;   
    }   
    return total;   
}     
    

 


   
  
void Initialize()  
{   
    int i;   
    int tStartart[9]={0},tfinish[9]={0};   
    long u;  
	
	cin >> Start.puzz; 
	
	 
	  
    getchar();   
    for(i=0;i<=8;i++)   
    {   
        if(Start.puzz[i]>'8'||Start.puzz[i]<'0')   
        {   
            exit(0);   
        }   
        tStartart[Start.puzz[i]-'0']=1;   
    }   
   for(i=0;i<9;i++)   
    {   
        if(tStartart[i]==0)   
        {   
           
            exit(0);   
        }   
    }   

	cout << "Enter the finalstateinal State:	" ;    
	cin >> finalstate.puzz;   
       
    for(i=0;i<=8;i++)   
    {   
        if(finalstate.puzz[i]>'8'||finalstate.puzz[i]<'0')   
        {      
            exit(0);   
        }   
    }   
    for(i=0;i<9;i++)   
    {   
        if(tStartart[i]==0)   
        {   
            exit(0);   
        }   
    }   
    for(i=0;i<100;i++){   
    finalstate.road[i]='\0';   
    Start.road[i]='\0';   
    }   
    open[0]=Start;   
    u=sortit(Start.puzz,9);   
    closed[u]=1;     
} 


void pop(node m)       
{   
    Counter++;   
    closed[sortit(m.puzz,9)]=1;   
} 

 int isaim(node m)     
{   
    if(!strcmp(m.puzz,finalstate.puzz))   
        return 1;   
    return 0;   
}   
int used(node m)     
{   
    if(closed[sortit(m.puzz,9)]==1)      
         return 1;   
     return 0;   
} 
   
 
void push(node m)      
{   
    if((tail+1)%len==head)   
    {   
       
        exit(0);   
    }   
    open[tail++]=m;   
    tail%=len;   
}   
  


node seach(int *t)    
{   
    node m[4];   
    int r,c,i,num=0;   
    
	while(!empty())   
    {   
        m[0]=m[1]=m[2]=m[3]=takeof();  
        num=strlen(m[0].road); 
        *t=num+1;      
        count(&r,&c,m[0]);  
     for(i=0;i<4;i++)        
        {   
            if(Possiblemoves(&m[i],r,c,i,num))    
            {   
                if(isaim(m[i]))      
                    return m[i];   
                if(!used(m[i]))      
                {   push(m[i]);    
                    pop(m[i]);     
                }   
            }   
        }   
    }   
    return m[0];   
} 
 


void print(node m,int t)   
{   
    int i,j,c,r;   
    cout << "Move: " <<endl ; 
    for(i=1;i<=9;i++)   
    {   
        cout << Start.puzz[i-1]<<"	";   
        if(i%3==0) cout << endl; 
    }   
       cout << endl;
	      
    for(i=1;i<=t;i++)   
    {   
    	
           
        cout << "Move Number: " << i<< endl;
		
		count(&r,&c,Start);   
        move(&Start,r,c,m.road[i-1]);    
        for(j=1;j<=9;j++)   
        {   
        	
        	
          cout <<Start.puzz[j-1] << "	";  
                if(j%3==0) 
				cout <<endl;  
        }   
           	cout << endl;
		       
    }   
}   



	
	
};



int main()   
{   
    Puzzle temp;
	node move;   
    int test;   
    
    cout << "Enter the values like 123587640" <<endl <<
            "1  2   3\n"   
            "5  8   7\n"   
            "6  4   0\n";   
   
    temp.Initialize();   
       
    move=temp.seach(&test);  
    temp.print(move,test);  
	  
	cout << "Total Moves: " << test <<endl; 
	
}  

 

 
   
   



