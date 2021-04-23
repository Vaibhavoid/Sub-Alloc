#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<cstring>
#include<ctype.h>

using namespace std;

class details
{
char name[20];
int r,c,rollno;
public:
details()
{
rollno=0;
}
int timetable[5][10];
char classes[45][5];

void initialize()
{
 for(r=0;r<=4;r++)
 {
  for(c=0;c<=9;c++)
  {
  timetable[r][c]=0;
  }
 }
}




void inputdata()
{
 system("cls");
 cout<<"********************************************************************************";
 cout<<"\n\n\n\t\t\t  ...Inventory Updatation...\n";
 cout<<"\n\n\tEnter the name of the teacher		";
 cin>>name;
 cout<<"\n\tEnter the assigned employee code        ";
 cin>>rollno;
 cout<<"\n\n\tTo start entering the timetable of the teacher press any key.\n\t";
  for(r=0;r<=4;r++)
 {
system("cls");
 cout<<"********************************************************************************";
   if(r==0)
    {
    cout<<"\n\n\t\t\t     Enter for Monday\n";
    }
   else if(r==1)
    {
    cout<<"\n\n\t\t\t     Enter for Tuesday\n";
    }
   else if(r==2)
    {
    cout<<"\n\n\t\t\t     Enter for Wednesday\n";
    }
   else if(r==3)
    {
    cout<<"\n\n\t\t\t     Enter for Thursday\n";
    }
   else if(r==4)
    {
    cout<<"\n\n\t\t\t     Enter for Friday\n";
    }

  for(c=1;c<=9;c++)
  {
  cout<<"\n\t\t     Period Number: "<<c<<"\n\t\t     ";
   cin>>timetable[r][c];
   if(timetable[r][c]==2)
   {
   cout<<"\n\t\t     Enter class : ";
   cin>>classes[(9*r)+(c-1)];
   }
   else
   {
   strcpy(classes[(9*r)+(c-1)]," - ");
   }
  }
 }

}


void disp_array()
{
system("cls");
cout<<"********************************************************************************";
cout<<"\n\n\n\t\t\t     Time Table : "<<name<<endl;
for(r=0;r<=4;r++)
{
cout<<"\n\t  |-----|-----|-----|-----|-----|-----|-----|-----|-----|\n\t ";
for(c=1;c<=9;c++)
{
cout<<" | "<<classes[(9*r)+(c-1)];
if(c==9)
{
cout<<" |";
}//if
}//for c
}//for r
cout<<"\n\t  |-----|-----|-----|-----|-----|-----|-----|-----|-----|\n\t ";
getch();
}

void disp_data()
{
cout<<"\t\t     Name : "<<name<<endl;
cout<<"\t\t     Employee code : "<<rollno<<endl;
}
void takename()
{
cout<<name<<"  ";
}
int getvalue(int r,int c)
{
return timetable[r][c];
}
int getroll()
{
return rollno;
}

void getclass(int r,int c,char* str)
{
int i1=0;
for(i1=0;classes[(9*r)+(c-1)][i1]!='\0';i1++)
{
str[i1]=classes[(9*r)+(c-1)][i1];
}
str[i1]='\0';
}

void getname(char* str)
{
int i1=0;
for(i1=0;name[i1]!='\0';i1++)
{
str[i1]=name[i1];
}
str[i1]='\0';
}

};

void menu1(int *x);
void access_code(int *y);
void compile(int *c, int *i, int *b);
void nocode();
void getday(int *d);

int main()
{
 system("cls");
 fstream f,f1;
 details d,d1;
 int in=0,m=0,lol=0,num=0,z=0,checksub=1,acall[30],name1=1,barrier=0,checkp=0;
 char aname[30][20];
 d1.initialize();
 for(int l=0;l<30;l++)
 acall[l]=0;

do
{

 menu1(&in);

 barrier=0;
 while(in==2)
 {
 access_code(&checkp);

 while(checkp==1)
 {
  compile(&checkp, &in, &barrier);
 }//while
 if(checkp==0)
 {
 nocode();
 in++;
 }

 }
 z=0;
 while(in==1)
 {

  int day;
  getday(&day);
   cout<<"\n\n\t\t     THANKS! Lets get going\n\n";
    getch();
    system("cls");
    cout<<"********************************************************************************";
    cout<<"\n\n\t\t\t       SUBSTITUTION ALLOCATION";
    cout<<"\n\n\t\t     Enter the number of teachers absent today\n\t\t     ";
    cin>>num;
    char str[20],cls[15];
    char subtable[500][40];
    for(int k=0;k<500;k++)
    {
    strcpy(subtable[k],'\0');
    }
    cout<<"\n\n\t\t     Enter the name of the teachers(without spaces)\n";
    for(m=0;m<num;m++)
    {
    cout<<"\n\t\t     "<<m+1<<". ";
    cin>>aname[m];
    for(int p;aname[m][p];p++)
    aname[m][p]=tolower(aname[m][p]);
    }

    for(m=0;m<num;m++)
    {
    f.open("database.dat",ios::binary|ios::in);
    while(f.read((char*)&d,sizeof(d)))
    {
      d.getname(str);

    if(strcmp(str,aname[m])==0)
    {
    acall[z]=d.getroll();//temp roll no for checking absentees
    z++;
    }
    }f.close();
    }
    for(m=0;m<num;m++)//--------------------------------
    {
    f.open("database.dat",ios::binary|ios::in);
    while(f.read((char*)&d,sizeof(d)))
    {
      d.getname(str);
    if(strcmp(str,aname[m])==0)
    {
     strcpy(subtable[m*10],str);
     cout<<"________________________________________________________________________________";
     cout<<"\n\t\t     The details of the absent teacher are as follows\n";
     d.disp_data();
     cout<<"\n\t\t     For allocating substitutions period wise, press 1 \n\t\t      ";
     cin>>checksub;
     if(checksub==1)
     {
     system("cls");
     cout<<"********************************************************************************";
     cout<<"\n\n\t\t\t       SUBSTITUTION ALLOCATION\n";
     for(int k=1;k<=9;k++)
      {
     if(d.getvalue(day,k)==1)
     {
      strcpy(subtable[m*10+k],"-");//------------------------
     }
     if(d.getvalue(day,k)!=1)
     {
     d.getclass(day,k,cls);
      cout<<"\n\t\t     For period: "<<k<<" and class: "<<cls<<"\n\n\t\t     ";

      f1.open("database.dat",ios::binary|ios::in);
      while(f1.read((char*)&d1,sizeof(d1)))
      {
      int checkloop=0;
      for(int l=0;l<30;l++)
       {
	if(d1.getroll()==acall[l])
	{checkloop++;}//absent teacher not displayed
       }
      if(checkloop==0)
      {
      if(d1.getvalue(day,k)==1)
       {
	d1.takename();
	cout<<"->"<<d1.getroll()<<" ;";
      }
     }
     }f1.close();//while
     cout<<endl;
     cout<<"\n\t\t     Enter the given roll number of the assigned teacher\n\t\t    ";
     cin>>lol;
     f1.open("database.dat",ios::binary|ios::in);
     char str2[15];
     while(f1.read((char*)&d1,sizeof(d1)))
     {
     if(lol==d1.getroll())
     {
     d1.getname(str2);
     strcpy (subtable[(m*10)+k],str2);
	 int v=0;
     for(v=0;subtable[(m*10)+k][v]!='\0';v++)
     {}
     subtable[(m*10)+k][v]='=';
     v++;
     d.getclass(day,k,str2);//-------------------------
     for(int a=0;str2[a]!='\0';a++,v++)
     {
     subtable[(m*10)+k][v]=str2[a];
     }
     subtable[(m*10)+k][v]='\0';
     }//if
     }//while
     f1.close();
     }//if
     getch();
     }
     //for:k
     }//if:checksub
     }//if
    }f.close();//while
   }//for
   cout<<"\n********************************************************************************";
   cout<<endl<<"\n\n\t\t     To view the substitution chart press any key\n";
   cout<<"********************************************************************************";
   getch();
   system("cls");
   cout<<"********************************************************************************";
   cout<<"\n\t\t\t       Substitution Charts\n\n";
   for(int p=0;p<num;p++)
   { cout<<p+1<<": ";
    for(int t=0;t<=9;t++)
    {
     cout<<subtable[(p*10)+t]<<"  ";
    }cout<<endl;
   }
   getch();
  cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  cout<<"\n\t\t     To go back to the first menu : Press 2\n\t\t     For terminating the program : Press 3\n";
  cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t\t     ";
  cin>>name1;

 in++;
 }


 if(name1==2)
 {barrier=1;}
 else if(name1==3)
 {barrier=2;}


}
while(barrier==1);


getch();

return 0;
}



void menu1(int *x)
{
system("cls");
cout<<"********************************************************************************";
cout<<"\n\t\t\t  :: SUMMERFIELDS SCHOOL ::\n";
cout<<"\n\n\n\t     WELCOME TO THE DEPARTMENT OF SUBSTITUTIONS ALLOCATION\n";
cout<<"\n\n\n\t\t     1. For Substitution allotment\n";
cout<<"\n\t\t     2. For database modification";
cout<<"\n\t\t        (Requires Special compilation access)\n\n\t\t     ";
cin>>*x;
}


void access_code(int *y)
{
 system("cls");
 *y=0;
 char pass[10];
 cout<<"********************************************************************************";
 cout<<"\n\n\n\n\t\t\t  << WELCOME COMPILER >>\n";
 cout<<"\n\n\t\t     Enter the compilation access code\n";
 for(int i=0;i<3;i++)
 {
  cout<<"\n\t\t     "<<3-i;
  if(i==2)
  cout<<" attempt";
  else
  cout<<" attempts";
  cout<<" remaining)\n\t\t     ";
  cin>>pass;
  if(strcmp(pass,"B1e#")==0)
  {
   *y=1;
   system("cls");
   cout<<"\n\n\n\n\n\n\n********************************************************************************";
   cout<<"\n\n\t\t\t       Login Successful";
   cout<<"\n\n********************************************************************************";
   getch();
   system("cls");
   break;
  }
 }
}
void compile(int *c, int *i, int *b)
{
 fstream f;
 details d1;
 char str4[20];
 int check=0,l=0;
 *c=0;
  system("cls");
  cout<<"********************************************************************************";
  cout<<"\n\n\n\t\t\t   .:  TIME TABLE DATABASE  :.\n\n";
  cout<<"\n\t\t     1. For Compiling Instructions\n";
  cout<<"\n\t\t     2. To enter the details of the teachers\n";
  cout<<"\n\t\t     3. To view the timetable of a teacher\n  ";
  cout<<"\n\t\t     4. To go back to the previous menu\n";
  cout<<"\n\t\t     5. To terminate the program\n\t\t     ";
  cin>>check;
  system("cls");

  switch(check)
  {
   case 1:
    system("cls");
    cout<<"\n\n\n\n\n===============================================================================\n";
    cout<<"\t\t\t   : INSTRUCTIONS FOR COMPILATION :\n";
    cout<<"\n\n\t\t --> Enter 1 for free period\n";
    cout<<"\n\t\t --> Enter 2 for an allocated period\n";
    cout<<"\t\t --> if 2, then enter the allocated class\n";
    cout<<"===============================================================================\n";
    getch();
    system("cls");

    *c=1;
    break;
   case 2:
    d1.inputdata();
    f.open("database.dat",ios::binary|ios::app);
    f.write((char*)&d1,sizeof(d1));
    f.close();
    d1.disp_array();
    *c=1;
    break;
   case 3:
    system("cls");
    cout<<"********************************************************************************";
    cout<<"\n\n\n\t\t\t  ...Time-Table Searching...\n";
    cout<<"\n\n\tEnter the name of the teacher\t\t";
    cin>>str4;
    f.open("database.dat",ios::binary|ios::in);
    while(f.read((char*)&d1,sizeof(d1)))
    {
     char str[10];
     d1.getname(str);
     if(strcmp(str4,str)==0)
     {
     d1.disp_array();
     l=1;
     getch();
     }
    }
    f.close();
    *c=1;
    if(l!=1)
    {
    cout<<"No Match found\n";
    getch();
    }
    break;
   case 4:
    *b=1;
    *i=3;
    *c=2;
    break;
   case 5:
    *i=3;
    *c=2;
    break;
   default:
    cout<<"\n\n\n\n";
    cout<<"!@#$%^&*())(*&^%$#@!!@#$%^&*())(*&^%$#@!!@#$%^&*())(*&^%$#@!!@#$%^&*()_++_)(*&^%";
    cout<<"\n\n\t\t\tWrong choice entered terminating the program...\n\n";
    cout<<"!@#$%^&*())(*&^%$#@!!@#$%^&*())(*&^%$#@!!@#$%^&*())(*&^%$#@!!@#$%^&*()_++_)(*&^%";
    getch();
    *i=3;
    *c=2;
    break;
  }
}

void nocode()
{
system("cls");
  cout<<"\n\n\n\n\n\n\n********************************************************************************";
   cout<<"\n\n\n\t\t\t       Wrong Password Entered\n\t\t\t    ...Terminating the program...";
   cout<<"\n\n********************************************************************************";
   getch();
   system("cls");
}

void getday(int *d)
{
 system("cls");
 cout<<"********************************************************************************";
 cout<<"\n\n\n\t\t\t         SUBSTITUTION ALLOCATION\n";
  cout<<"\n\n\t\t     Select the day today.";
  cout<<"\n\n\t\t     Monday : 1\n";
  cout<<"\t\t     Tuesday : 2\n";
  cout<<"\t\t     Wednesday : 3\n";
  cout<<"\t\t     Thursday : 4\n";
  cout<<"\t\t     Friday : 5\n\t\t     ";
  cin>>*d;
  *d=*d-1;
}

