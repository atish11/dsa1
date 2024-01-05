




#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct student
{
    int roll_no;
    char name [15];
    float sgpa;
   
};





void create(struct student s[15],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"\n Enter the roll number:";
        cin>>s[i].roll_no;
        cout<<"\n Enter the Name:";
        cin>>s[i].name;
        cout<<"\n Enter the SGPA:";
        cin>>s[i].sgpa;
    }
}
void display(struct student s[15],int n)
{
    int i;
    cout<<"\n"<< "\t"<< "Roll No"<< "\t"<<" Name" <<"\t"<< "SGPA";
    for(i=0;i<n;i++)
    {
        cout<<"\n";
        cout<<"\t "<< s[i].roll_no<<"\t "<<s[i].name<<"\t "<<s[i].sgpa;
    }
}
 
void bubble(struct student s[15],int n)
{
    int i,j;
   struct student  temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].roll_no>s[j+1].roll_no)
            {
                temp=s[j+1];
                s[j+1]=s[j];
                s[j]=temp;
            }
        }
    }
}

void insertion(struct student s[15],int n){

for (int i=1;i<=n-1 ;i++){

char current[50];
int j ;
strcpy(current,s[i].name);
     int temp=s[i].roll_no;
        float temp1=s[i].sgpa;


j=i-1;

while(j>=0  &&  (strcmp(s[j].name,current)>0)){
strcpy(s[j+1].name,s[j].name);
            s[j+1].roll_no=s[j].roll_no;
   s[j+1].sgpa=s[j].sgpa;


j--;
}
  strcpy(s[j+1].name,current);




         s[j+1].roll_no=temp;

     s[j+1].sgpa=temp1;
}
}
void swap(struct student s[15],int i, int j){

float temp = s[i].sgpa;
s[i].sgpa=s[j].sgpa;
s[j].sgpa=temp;

int temp1=s[i].roll_no;
s[i].roll_no=s[j].roll_no;
s[j].roll_no=temp1;

 char temp2[50];
strcpy(temp2,s[i].name);
strcpy(s[i].name,s[j].name);
strcpy(s[j].name,temp2);
}
int partition(struct student s[15],int low , int high){

float pivot=s[high].sgpa;
int i=low-1;
for(int j=low ; j<high;j++){

if(s[j].sgpa>=pivot){
i++;
swap(s,i,j);
}
}
swap(s,i+1,high);
return i+1;
}
void quicksort(struct student s[15], int low , int high ){
int i=low;
int j = high;

if(low <high ){
int pi= partition(s,low ,high);

quicksort(s,low , pi-1);
quicksort(s,pi+1,high);
}


}
void linearsearch(struct student s[15], int n ){

for (int i=0 ; i< n ; i++){
for (int j=i+1; j<n ; j++){
if(s[i].sgpa==s[j].sgpa){

cout<<"Students having same SGPA are:";
cout<<"The name of the student 1st is"<<s[i].name<<endl;
            cout<<"The Roll number of the student 1st is"<<s[i].roll_no<<endl;
            cout<<"The sgpa of the student 1st is"<<s[i].sgpa<<endl;
           
            cout<<"The name of the student 2nd is"<<s[j].name<<endl;
            cout<<"The Roll number of the student 2nd is"<<s[j].roll_no<<endl;
            cout<<"The sgpa of the student 2nd is"<<s[j].sgpa<<endl;
}
else{
cout<<"No students are having same SGPA";
}
}
}
 
}

int binarysearch(struct student s[], int n ,char key[50]){

int start=0;
int end=n-1;
   
while(start <= end){

int mid=(start+end) /2;
int result= strcmp(s[mid].name,key);
if(result==0 ){
return mid;
}
else if (result < 0){
start=mid+1;
}else {
end=mid-1;

}
}
       return -1;
}
int main()
{
 
    int ch,n,result,mid;
    char x[15],d;
  char key[50];
    struct student s[15];
 
  do{
        cout<<"\n 1) Create Student Database ";
        cout<<"\n 2) Display Student Records ";
        cout<<"\n 3) bubble Sort (roll no sort)";
        cout<<"\n 4) insertion Sort (Alphabetical)";
        cout<<"\n 5) Quicksort Sort (Find Toppers)";
        cout<<"\n 6) linear search ";
        cout<<"\n 7) binary search ";
        cout<<"\n Enter Your Choice:=";
        cin>>ch;
       
       
         switch(ch)
        {
            case 1:
            cout<<"\n Enter The Number Of Records:=";
            cin>>n;
create(s,n);
           
            break;
            case 2:
            display(s,n);
            break;
            case 3:
            bubble(s,n);
            display(s,n);
            break;
            case 4:
            insertion(s,n);
            display(s,n);
            break;
           
            case 5:
           
            quicksort(s,0,n-1);
            for(int i=0;i<n;i++){
cout<<"The name of the student is"<<s[i].name<<endl;
cout<<"The Roll number of the student is"<<s[i].roll_no<<endl;
cout<<"The sgpa of the student is"<<s[i].sgpa<<endl;
}
            case 6:
            linearsearch(s,n);
            break;
          case 7:
            cout<<" Enter the name of the student to search";
               cin>>key;
   
             mid = binarysearch(s,n,key);
            if(mid==-1){
            cout << "no student found";
}else{
cout<<"The name of the student is"<<s[mid].name<<endl;
            cout<<"The Roll number of the student is"<<s[mid].roll_no<<endl;
            cout<<"The sgpa of the student is"<<s[mid].sgpa<<endl;}
            break;
            default: cout<<"Invalid choice";
             break;    
          }

        cout<<"\tDo you want to continue(Y/N) ";
        cin>>d;

}while(d=='y'||d=='Y');
       
        return 0;
   }