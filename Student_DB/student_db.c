#include "header.h"
#include "fun_definition.c"

int main()
{
    int try=1;
    char t_username[20],t_password[9];

    L:
    printf("Enter the username: ");
    scanf("%s",t_username);
    printf("\nEnter password: ");
    scanf(" %s",t_password);
    printf("\n");
    int login=readcredentials(t_username,t_password);
    LINE;
    if(login)
    {
        int n,i,op;
        printf("Enter the number of students\n");
        scanf("%d",&n);
        student *s;
            s=malloc(sizeof(student)*n);
        LINE;
        printf("Enter the student details\n");
        LINE;
        i=0;
        while(i<n)
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
            LINE;
            i++;
        }
        while(1)
        {
            printf("Select the option\n");
            printf("1. Add new student details\n2. Find student by roll number\n3. Find student by name\n4. Total Count\n5. Delete Student\n6. Update student details\n7. Change Credentials\n8. Exit\n");
            scanf("%d",&op);
            switch(op)
            {
                case 1: addstudent(s,&n);
                        break;
                case 2: findbyrollno(s,n);
                        break;
                case 3: findbyname(s,n);
                        break;
                case 4: totalno(s,n);
                        break;
                case 5: delete(s,&n);
                        break;
                case 6: update(s,n);
                        break;
                case 7: createnew();
                        break;
                case 8: return 0;
                default : printf("Invalid option\n");
            }
        }
    }
    else
    {
        printf("Invalid Username and Password\n");
        try++;
        if(try<=3)
        {
            goto L;
        }
        else
        {
            printf("You've been blocked. Please reset your passowrd and username\n");
            createnew();
            try=1;
            goto L;
        }
    }
    return 0;
}