#include<stdio.h>
struct book
{
    char title[50];
    char author[50];
    char isbn[70];
    char edition[30];
    int numcopy ;
};
struct st
{
    char name[100] ;
    char id[100] ;
    struct book books;
};

void addbook(struct book b)
{
    FILE *fptr = fopen("book.txt","a");
    getchar () ;
    printf ("enter title name:") ;
    gets (b.title) ;

    printf ("enter author name:");
    gets(b.author) ;

    printf ("enter isbn num:") ;
    gets(b.isbn);

    printf ("enter the edition:") ;
    gets(b.edition);

    printf ("enter the number_copy:");
    scanf ("%d",&b.numcopy) ;

    fprintf(fptr,"%s,",b.title);
    fprintf(fptr,"%s,",b.author);
    fprintf(fptr,"%s,",b.isbn);
    fprintf(fptr,"%s,",b.edition);
    fprintf(fptr,"%d\n",b.numcopy);
    fclose(fptr);

    ///we store a record seperating its all attributes using comma
    ///and seperate multiple record using newline.

}
void showbook(struct book b)
{
    FILE *fptr = fopen("book.txt","r");
    printf("Title\t\t\tAuthor\t\t\tISBN\t\tEdition\t\tNumber of copies\n");
    char ch;
    while(!feof(fptr))
    {
        ch=fgetc(fptr);
        if(ch==',')
        {
            printf("\t\t");
        }
        else
        {
            printf("%c",ch);
        }

    }
    fclose(fptr) ;

}

void searchbook()
{
    getchar();
    printf("Enter the name you want to search: ");
    char name[100];
    gets(name);

    FILE *fptr = fopen("book.txt","r");


    char book_info[1000][5][50];
    char ch;

    int i=0,j=0,k=0; ///storing all the information of multiple books to a 3D array
    while(!feof(fptr))
    {
        ch=fgetc(fptr);
        if(ch==',')
        {
            book_info[k][j][i]='\0';
            i=0;
            j++;
        }
        else if(ch=='\n')
        {
            book_info[k][j][i]='\0';
            k++;
            i=0;
            j=0;
        }
        else
        {
            book_info[k][j][i]=ch;
            i++;
        }

    }
    fclose(fptr);

    /*for(int a=0; a<k; a++)
    {
        for(int b=0; b<5; b++)
        {
            for(int c=0; book_info[a][b][c]!='\0'; c++)
            {
                printf("%c", book_info[a][b][c]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    */


    printf("----------------------------------------------BOOK INFROMATION----------------------------------------\n");
    int flag=0;
    int b=0;
    for(int a=0; a<k; a++)
    {
        flag=0;
        for(int c=0; name[c]!='\0'; c++)
        {

            if(book_info[a][b][c]!=name[c])
            {
                ///if does not match with  book name, iterate to another book record
                flag=1;
                break;

            }

        }
        if(flag==0) ///if matches with the book name
        {
            printf("\n\nTitle\t\t\tAuthor\t\t\tISBN\t\tEdition\t\tNumber of copies\n");

            for(int x=0; x<5; x++)
            {
                for(int y=0; book_info[a][x][y]!='\0'; y++)
                {

                    printf("%c", book_info[a][x][y]);
                }
                printf("\t\t");
            }
            printf("\n\n");
            break;

        }


    }

    if(flag==1)
    {
        printf("book not found!\n\n");
    }


}

void registr(struct st s)
{
    FILE *fptr=fopen("student.txt","a") ;
    getchar() ;
    printf("Enter student name:") ;
    gets(s.name) ;

    printf("Enter student id:") ;
    gets(s.id) ;
    fprintf(fptr,"%s,",s.name);
    fprintf(fptr,"%s\n",s.id);
    fclose(fptr) ;
}


void showIndividualStudent(char student_info[100][2][50], int a, int flag,int file)
{
        ///flag=0 means it has student info.
        ///file=0 measn we have to file student info

    if(flag==0)
    {
        printf("\n\nName\t\t\tID\n");
        for(int x=0; x<2; x++)
        {
            for(int y=0; student_info[a][x][y]!='\0'; y++)
            {

                printf("%c", student_info[a][x][y]);
            }
            printf("\t\t\t");
        }
        printf("\n\n");



    }
    else
    {
        printf("\t\t\tstudent not found!\n\n");


    }
    if(file==1)
    {
        FILE *fptr=fopen("borrowbooks.txt","a");

        for(int x=0; x<2; x++)
        {
            for(int y=0; student_info[a][x][y]!='\0'; y++)
            {

                fprintf(fptr,"%c", student_info[a][x][y]);
            }
            fprintf(fptr,",");
        }
        fclose(fptr);


    }



}

int searchStudent(int file)
{
    getchar();
    printf("Enter student name you want to search: ");
    char name[100];
    gets(name);

    FILE *fptr = fopen("student.txt","r");
    char student_info[1000][2][50];
    char ch;

    int i=0,j=0,k=0;
    while(!feof(fptr)) ///storing all student info to a 3D array.
    {
        ch=fgetc(fptr);
        if(ch==',')
        {
            student_info[k][j][i]='\0';
            i=0;
            j++;
        }
        else if(ch=='\n')
        {
            student_info[k][j][i]='\0';
            k++;
            i=0;
            j=0;
        }
        else
        {
            student_info[k][j][i]=ch;
            i++;
        }

    }
    fclose(fptr);


    printf("----------------------------------------------STUDENT INFROMATION----------------------------------------\n");
    int flag=0;
    int b=0;
    int a;
    for(a=0; a<k; a++)
    {
        flag=0;
        for(int c=0; name[c]!='\0'; c++)
        {
            //printf("%c",name[c]);
            if(student_info[a][b][c]!=name[c])
            {
                //printf("%c %c\n",book_info[a][b][c], name[c]);
                flag=1;
                break;

            }

        }
        if(flag==0)
        {
            /* printf("\n\nName\t\t\tID\n");

             for(int x=0; x<2; x++)
             {
                 for(int y=0; student_info[a][x][y]!='\0'; y++)
                 {

                     printf("%c", student_info[a][x][y]);
                 }
                 printf("\t\t\t");
             }
             printf("\n\n");
             break;

             */

            showIndividualStudent(student_info,a,flag,file);
            return 1;
            break;
        }



    }

    if(flag==1)
    {
        showIndividualStudent(student_info,a,flag,file);
        return 0;

    }






}


void borrowBook()
{
    char name[100];
    int file=1;///means filing is a must.
    int ans= searchStudent(file); ///doing it for student validation.
    // printf("ans: %d",ans);
    if(ans==1)
    {
        FILE *fptr = fopen("borrowbooks.txt","a");
        char book_name[100];
        printf("Enter book you want to borrow: ");
        gets(book_name);
        fprintf(fptr,"%s\n",book_name);
        fclose(fptr);

        ///Book validation is not applied here, but we have to do it eventually.
    }

}

void returnbook()
{
    getchar();
    printf("Enter book name you want to return: ");
    char book[50];
    gets(book);

    FILE *fptr = fopen("borrowbooks.txt","r");
    char borrow_info[1000][3][50];
    char ch;

    int i=0,j=0,k=0;
    while(!feof(fptr))
    {
        ch=fgetc(fptr);
        if(ch==',')
        {
            borrow_info[k][j][i]='\0';
            i=0;
            j++;
        }
        else if(ch=='\n')
        {
            borrow_info[k][j][i]='\0';
            k++;
            i=0;
            j=0;
        }
        else
        {
            borrow_info[k][j][i]=ch;
            i++;
        }

    }
    fclose(fptr);

    /* for(int i=0; i<k; i++)
     {
         for(int j=0; j<3; j++)
         {
             for(int l=0; borrow_info[i][j][l]!='\0'; l++)
             {
                 printf("%c",borrow_info[i][j][l]);
             }
             printf(",");
         }
         printf("\n");
     }
     */


    int flag=0;
    int b=2;
    for(int a=0; a<k; a++)
    {
        flag=0;
        for(int c=0; book[c]!='\0'; c++)
        {
            // printf("%c",book[c]);
            if(borrow_info[a][b][c]!=book[c])
            {
                //printf("%c %c\n",borrow_info[a][b][c], book[c]);
                flag=1;
                break;

            }

        }
        if(flag==0)
        {
            //printf("%d");

            ///replacing the current record with its next records and reducing the count of records by 1.
            int x, y;
            for(int shift_record=a; shift_record<k; shift_record++)
            {
                for( x=0; x<3; x++)
                {

                    for( y=0; borrow_info[shift_record][x][y]!='\0'; y++)
                    {


                        borrow_info[shift_record][x][y]=borrow_info[shift_record+1][x][y];


                    }
                    borrow_info[shift_record][x][y]='\0';
                }
            }
            k--; /// reducing the count of all records.

        }
    }
    if(flag==1)
    {
        printf("\t\t\t\t\tThe book name you have entered is not borrowed!")
    }
    else
    {
        fptr = fopen("borrowbooks.txt","w");

        int success=1;
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int l=0; borrow_info[i][j][l]!='\0'; l++)
                {
                    fprintf(fptr,"%c",borrow_info[i][j][l]);
                }
                fprintf(fptr,",");
            }

            fprintf(fptr,"\n");
            flag=0;
        }
        fclose(fptr);

        if(flag==0)
        {
            printf("\t\t\t\t\tBook returned successfully!");
        }

    }


}

int main()
{
    struct book b;
    struct st s;
    //int  index=0 ;
    int choice ;
    do
    {
        printf ("\n1.book registration\n") ;
        printf ("2.Show book \n") ;
        printf ("3.student registration\n");
        printf ("4.Search book infromation\n");
        printf("5.Search Student information\n");
        printf("6.Borrow Book\n");
        printf("7.Return book\n");
        printf ("-1.exit\n") ;
        scanf ("%d",&choice) ;
        if(choice==1)
        {
            addbook(b);
        }
        else if (choice==2)
        {
            showbook(b) ;
        }
        else if (choice==3)
        {
            registr(s) ;
        }
        else if (choice==4)
        {
            searchbook();
        }
        else if(choice==5)
        {
            int no_file=0; /// filing is prohibited
            searchStudent(no_file);
        }
        else if(choice==6)
        {
            borrowBook();

        }
        else if(choice==7)
        {
            returnbook();
        }
    }
    while(choice!=-1) ;


}
