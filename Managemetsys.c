// Student result management system 

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

void gotoxy(int ,int );
void context();
void add();
void view();
void search();
void modify();
void sorting();
void deleterec();
struct student{
    char name[30];
    float CGPA;
    int rollno;
    char course[20];
    char branch[20];
};
int main(){
    gotoxy(15,8);
    printf("::::: Student Result Management System :::::");
    gotoxy(23,10);
    printf("Press any key to continue!");
    getch();
    context();
    return 0;
}
void context(){
    int todo;
    system("cls");
    gotoxy(10,3);
    printf("::: CONTEXT :::");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete.");
    gotoxy(10,12);
    printf("6 : Sorting data according to Roll no.");
    gotoxy(10,13);
    printf("7 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice: ");
    scanf("%d",&todo);
    switch(todo){
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        sorting();
        break;

    case 7:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add(){
    FILE *fp;
    struct student data;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","a+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("::: ADD RECORD :::");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name : ");
        gets(data.name);
        gotoxy(10,8);
        printf("Enter CGPA : ");
        scanf("%f",&data.CGPA);
        gotoxy(10,9);
        printf("Enter Roll No : ");
        scanf("%d",&data.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Course : ");
        gets(data.course);
        gotoxy(10,11);
        printf("Enter Branch : ");
        gets(data.branch);
        fwrite(&data,sizeof(data),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue!");
    getch();
    context();
}
void view(){
    FILE *fp;
    int i=1,j;
    struct student data;
    system("cls");
    gotoxy(10,3);
    printf("::: VIEW RECORD :::");
    gotoxy(10,5);
    printf("S.No\tName\tCGPA\tRoll No.   Course\tBranch");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------");
    fp = fopen("record.txt","r");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&data,sizeof(data),1,fp) == 1){
        gotoxy(10,j);
        printf("%d   \t%s\t%.1f\t%d\t   %s\t%s",i,data.name,data.CGPA,data.rollno,data.course,data.branch);  
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue!");
    getch();
    context();
}
void search()
{
    FILE *fp;
    struct student data;
    char stdname[20];
    system("cls");
    gotoxy(10,3);
    printf("::: SEARCH RECORD :::");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stdname);
    fp = fopen("record.txt","r+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&data,sizeof(data),1,fp ) == 1){
        if(strcmp(stdname,data.name) == 0){
            gotoxy(10,7);
            printf("Name : %s",data.name);
            gotoxy(10,8);
            printf("CGPA : %.1f",data.CGPA);
            gotoxy(10,9);
            printf("Roll No : %d",data.rollno);
            gotoxy(10,10);
            printf("Course : %s",data.course);
            gotoxy(10,11);
            printf("Branch : %s",data.branch);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue!");
    getch();
    context();
}
void modify(){
    char stdname[20];
    FILE *fp;
    struct student data;
    system("cls");
    gotoxy(10,3);
    printf("::: MODIFY RECORD :::");
    gotoxy(10,5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stdname);
    fp = fopen("record.txt","r+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(fread(&data,sizeof(data),1,fp) == 1)
    {
        if(strcmp(stdname,data.name) == 0){
            gotoxy(10,7);
            printf("Enter name: ");
            gets(data.name);
            gotoxy(10,8);
            printf("Enter CGPA : ");
            scanf("%f",&data.CGPA);
            gotoxy(10,9);
            printf("Enter roll no : ");
            scanf("%d",&data.rollno);
            gotoxy(10,10);
            printf("Enter Course : ");
            fflush(stdin);
            gets(data.course);
            gotoxy(10,11);
            printf("Enter Branch : ");
            fflush(stdin);
            gets(data.branch);
            fseek(fp ,-sizeof(data),SEEK_CUR);
            fwrite(&data,sizeof(data),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue!");
    getch();
    context();
}
void sorting(){
    FILE *fp;
    struct student std;
    int i=0,swap;
    int array[70];
    system("cls");
    gotoxy(10,3);
    printf("::: SORTED :::");
    fflush(stdin);
    fp = fopen("record.txt","r+");
    if(fp == NULL){ 
        gotoxy(10,4);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        array[i]=std.rollno;
        i++;
    }
    for(int k = 0 ; k < i - 1; k++){
        for(int j = 0 ; j < i-k-1; j++){
            if(array[j] > array[j+1]){
                swap=array[j];
                array[j]=array[j+1];
                array[j+1]=swap;
            }
        }
    }
    fclose(fp);
    fflush(stdin);
    int j=6;
    gotoxy(5,4);
    printf("S.No\tName\tCGPA\tRoll No.   Course\tBranch");
    gotoxy(5,5);
    printf("--------------------------------------------------------------------");
    for (int u = 0; u<70; u++){
        fp = fopen("record.txt","rb+");
        if(fp == NULL){
            gotoxy(10,4);
            printf("Error opening file");
            exit(1);
        }
        while(fread(&std,sizeof(std),1,fp ) == 1){
            if (array[u]==std.rollno){
                gotoxy(5,j);
                printf("%d   \t%s\t%.1f\t%d\t   %s\t%s",u+1,std.name,std.CGPA,std.rollno,std.course,std.branch);  
                j++;
            }
        }
        fclose(fp);
    }

    fclose(fp);
    printf("\n");
}  
void deleterec(){
    char stdname[20];
    FILE *fp,*ft;
    struct student data;
    system("cls");
    gotoxy(10,3);
    printf("::: DELETE RECORD :::");
    gotoxy(10,5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stdname);
    fp = fopen("record.txt","r+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","w+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&data,sizeof(data),1,fp) == 1){
        if(strcmp(stdname,data.name)!=0)
            fwrite(&data,sizeof(data),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    context();
}
void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
