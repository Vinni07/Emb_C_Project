#ifndef HEADER
#define HEADER
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINE printf("-----------------------------------------------------------------------------\n")

struct st_data 
{
    int rollno;
    char first_name[20];
    char last_name[20];
    float CGPA;
    char courseid[10];
};
typedef struct st_data student;

void addstudent(student *,int *);
void findbyrollno(student *, int);
void findbyname(student *,int);
void totalno(student *,int);
void update(student *,int);
void delete(student *,int *);
void print_detail(student *);
void createnew();
int readcredentials(const char*,const char*);
#endif