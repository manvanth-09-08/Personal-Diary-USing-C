#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct diary
{
    char date[10],det[1000];
}DIARY;
DIARY* read(DIARY *d,FILE *fp)
{
    DIARY *ptr;
    ptr=malloc(sizeof(struct diary));
    printf("enter the date\n");
    scanf("%s",ptr->date);
    printf("\n\n%s",ptr->date);
    printf("enter the details\n");
    scanf("%*s  ",ptr->det);
    fp=fopen("diary.txt","a");
    fprintf("%s\n%s\n",ptr->date,ptr->det);
    fclose(fp);
    return ptr;
}
void disp(DIARY *d,FILE *fp)
{
    fp=fopen("diary.txt","r");
    while(fp!=EOF)
    {
        fscanf(fp,"%*c %*c",d->date,d->det);
        printf("%s\n%s\n",d->date,d->det);
        d++;
    }
    fclose(fp);
}
void main()
{
    int ch;
    DIARY *d=NULL;
    FILE *fp=fopen("diary.txt","a");
    while(1)
    {
        printf("enter 1 or 2\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:d=read(d,fp);
            break;
            case 2:disp(d,fp);
            break;
        }
    }
    fclose(fp);
}
