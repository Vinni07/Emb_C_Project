#include"header.h"
void addstudent(student *s,int *n)
{
    int num,i;
    printf("Enter the number of new students\n");
    scanf("%d",&num);
    *n+=num;
        s=realloc(s,sizeof(student)*(*n));
    for(i=*n-num; i<*n; i++)
    {
            printf("%d)---\n",i+1);
            printf("Enter rollnumber: ");
            scanf("%d",&s[i].rollno);
            printf("\nEnter first name: ");
            scanf("%s",s[i].first_name);
            printf("\nEnter last name: ");
            scanf("%s",s[i].last_name);
            printf("\nEnter CGPA: ");
            scanf("%f",&s[i].CGPA);
            printf("\nEnter courseID: ");
            scanf("%s",s[i].courseid);
    }

}
void print_detail(student *s)
{
    printf("Roll number: %d\n",s->rollno);
    printf("Name: %s %s\n",s->first_name,s->last_name);
    printf("CGPA: %f\n",s->CGPA);
    printf("Course ID : %s\n",s->courseid);
    LINE;
}

void findbyrollno(student *s,int n)
{
    int i,r;
    printf("Enter the student roll number\n");
    scanf("%d",&r);
    for(i=0; i<n; i++)
    {
        if(r==s[i].rollno)
        {
            print_detail(s+i);
            return;
        }
    }
    printf("No student found with %d roll number\n",r);
}

void findbyname(student *s, int n)
{
    int i;
    char temp[20],temp2[10];
    printf("Enter the first name and last name of student\n");
    scanf("%s%s",temp,temp2);
    for(i=0; i<n; i++)
    {
        if(strcmp(s[i].first_name,temp)==0)
        {
            if(strcmp(s[i].last_name,temp2)==0)
            {
                print_detail(s+i);
                return;
            }
            else
            {
                printf("Entered student last name does not exist!\n");
                return;
            }
        }
        else
            {
                printf("Entered student name does not exist!\n");
                return;
            }
    }
}

void totalno(student *s, int n)
{
    printf("Total number of students are : %d\n",n);
}

void update(student *s, int n)
{
    int r,i;
    char ch='N';
    printf("Enter the student roll number\n");
    scanf("%d",&r);
    for(i=0; s[i].rollno!=r; i++);
    while(ch=='N')
    {
        int op;
        printf("1. Update Name\n2. Update CGPA\n3. Update Course ID\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("Enter the new first name and last name\n");
                    scanf("%s%s",s[i].first_name,s[i].last_name);
                    break;
            case 2: printf("Enter the new CGPA\n");
                    scanf("%f",&s[i].CGPA);
                    break;
            case 3: printf("Enter new Course ID\n");
                    scanf("%s",s[i].courseid);
            default : printf("Invalid option\n");
        }
        printf("Is updation over : Y/N?\n");
        scanf(" %c",&ch);
    }
}

void delete(student *s, int *n)
{
    int i,r,p;
    p=*n;
    printf("Enter the roll number of the student\n");
    scanf("%d",&r);
    for(i=0; s[i].rollno!=r && i<*n; i++);
    if(s[i].rollno==r)
    {
        for(; i<p-1; i++)
        {
            s[i]=s[i+1];
        }
        *n=*n-1;
        s=realloc(s,sizeof(student)*(*n));
        printf("Student data of %d roll number had been deleted successfully\n",r);
    }
    else
    printf("Student with %d roll number does not exist\n",r);
}

void createnew()
{
    FILE *fp;
    fp=fopen("password.h","w");
    if(fp==0)
    printf("Failed to open password.h\n");
    char s[20],p[10];
    printf("Enter new password\n");
    scanf("%s",s);
    printf("Enter new password\n");
    scanf("%s",p);
    fputs(s,fp);
    fputc(' ',fp);
    fputs(p,fp);
    fclose(fp);
        printf("Username and Password has been reset successfully.\n");
}

int readcredentials(const char *s, const char *p)
{
    FILE *fp;
    fp=fopen("password.h","r");
    if(fp==NULL)
    {
        printf("Failed to open the file\n");
        return 0;
    }
    char s1[20],p1[10];
    fscanf(fp,"%s",s1);
    fscanf(fp,"%s",p1);
    fclose(fp);
    if((strcmp(s1,s)==0)&&((strcmp(p1,p)==0)))
        return 1;
    else
        return 0;
}