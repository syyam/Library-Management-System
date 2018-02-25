
    /* This is a comuterized system of a library management system written in C language.
       It contains 7 menus, performs 7 different functionalities.
       It is created by using FILE HANDLING technique, pointers and structures.*/

       /* Project submiited by: Syyam noor
          Roll no. FA15-BCS-127-A
          Submitted to: Mr. Adeel Nawab & Mr.Shuja*/

#include<stdio.h>   //Defines standard Input/output functions
#include<string.h>  //Used for String handling
#include<stdlib.h>  //General utilities: memory management, program utilities, string conversions, random numbers
#include<ctype.h>   //Functions to determine the type contained in character data

void add_book();        //Add function declaration/prototype
void delete_book();     //Delete function declaration/prototype
void search_book();     //Search function declaration/prototype
void update_book();     //Update function declaration/prototype
void display_books();   //Display function declaration/prototype
void issue_book();      //Issue function declaration/prototype
void s_isbn();              //Search by ISBN function declatarion/prototype
void s_book();              //Search by Book name function declatarion/prototype
void s_author();            //Search by author name function declatarion/prototype
void u_book(int serial);    //Update book name function declatarion/prototype
void u_author(int serial);  //Update author name function declatarion/prototype
void u_isbn(int serial);    //Update ISBN function declatarion/prototype
void d_book(int serial);    //Delete by book name function declatarion/prototype
void d_author(int serial);  //Delete by author name function declatarion/prototype
void d_isbn(int serial);    //Delete by ISBN function declatarion/prototype
int check_book(int serial); //Check book function declatarion/prototype

    struct book     //Global Structure declaration
    {
        int serial;
        char isbn[15];
        char name[25];
        char edition[15];
        char author[25];
        char status[15];
    }b;
main()
{
    char choice,a;
    system("COLOR F2");
    char c=178,d=178,f=176;
    label:printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",c,c,c,c,c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d,d,d,d,d,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c LIBRARY MANAGEMENT %c%c%c%c%c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d,d,d,d,d);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",c,c,c,c,c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d,d,d,d,d,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    printf("\n\t\t\t\t\t1. Add book\n\n\t\t\t\t\t2. Delete book\n\n\t\t\t\t\t3. Search book\n\n\t\t\t\t\t4. Update book\n\n\t\t\t\t\t5. Display book\n\n\t\t\t\t\t6. Issue book\n\n\t\t\t\t\t7. Exit\n");
    printf("\n Select option (1 to 7): ");
    choice=getche();
    switch(choice)
    {
    case '1':
        add_book();     //Calling Add function
        system("cls");
        goto label; //Control of the program moves to label "label"
        break;
    case '2':
        delete_book();  //Calling Delete function
        system("cls");
        goto label; //Control of the program moves to label "label"
        break;
    case '3':
        search_book();  //Calling Search function
        printf("\nPress 7 exit or any key to continue\n\n");
        char ch=getch();
        if(ch=='7')
        {
            goto table; //Control of the program moves to label "tabel"
        }
        system("cls");
        goto label; //Control of the program moves to label "label"
        break;
    case '4':
        update_book();  //Calling Search function
        system("cls");
        goto label; //Control of the program moves to label "label"
        break;
    case '5':
        display_books();    //Calling display function
        printf("\nPress 7 to exit or any key to continue\n\n");
        ch=getch();
        if(ch=='7')
        {
            goto table; //Control of the program moves to label "tabel"
        }
        system("cls");
        goto label; //Control of the program moves to label "label"
        break;
    case '6':
        issue_book();   //Calling Issue function
        printf("\nProcess completed\n");
        printf("\nPress 7 to exit or any key to continue\n\n");
        ch=getch();
        if(ch=='7')
        {
            goto table; //Control of the program moves to label "tabel"
        }
        system("cls");
        goto label; //Control of the program moves to label "label"
        break;
    case '7':
        goto table;  //Execution will jump to the label 'table'
        break;
    default:
        system("cls");
        goto label; //Control of the program moves to label "label"
    }
    table:system("cls");
    printf("\n\n\t\t\t\t%c%c%c%c%c%c%c%c SEE YOU AGAIN %c%c%c%c%c%c%c%c\n\n",f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f);
}
void add_book() //This function is for adding books in library
{
    system("cls");
    char c=219,d=219;
    printf("\n\t\t\t\t**************************");
    printf("\n\t\t\t\t%c%c%c%c%c%c%c%c ADD BOOK %c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d);
    printf("\t\t\t\t**************************\n\n");
    char a;
    int i;
    struct book b;
    FILE *fp;
    fp=fopen("d:\\book.txt","a");   //Opening file in append mode
    while(1)    //infinite loop, this will add books untill the conditoin becomes false
    {
        printf("Enter book serial number in numeric: ");
        fflush(stdin);
        scanf("%d",&b.serial);
        printf("\nEnter isbn: ");
        fflush(stdin);
        scanf("%s",b.isbn);
         printf("\nEnter book name: ");
        fflush(stdin);
        scanf("%s",b.name);
         printf("\nEnter edition: ");
        fflush(stdin);
        scanf("%s",b.edition);
         printf("\nEnter author: ");
        fflush(stdin);
        scanf("%s",b.author);
        strcpy (b.status,"  NO");   //As the book is added, so initially its status is 'NO'
        fflush(stdin);
        fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b.serial,b.isbn,b.name,b.edition,b.author,b.status);
        printf("\n\nPress any key to add another book or \" N \" to cancel\n\n");
        char a=getch();
        if(a=='n'||a=='N')
        {
            break;
        }
    }
    fclose(fp);
}
void delete_book()  //This function is for deleting books from library
{
    start:system("cls");
    char c=219,d=219;
    printf("\n\t\t\t    *****************************");
    printf("\n\t\t\t    %c%c%c%c%c%c%c%c DELETE BOOK %c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d);
    printf("\t\t\t    *****************************\n\n");
    struct book b;
    int i=0,SERIAL;
    char Nname[25],NAME[25],ch;
    int size=0;
    int flag=0;
    FILE *fp;
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    if(fp==NULL)
    {
        puts("cannot open file");
        exit(0);
    }
    fclose(fp);
    printf("\n\t\t\tHow do you want to delete this book?\n\n");
    printf("\n\t\t\t\t   1. By ISBN no.\n\t\t\t\t   2. By Book name\n\t\t\t\t   3. By Author name\n\n");
    c=getch();
    switch(c)
    {   /*  if any of the books have same author name, book name or ISBN then program will delete all these books,
            to over come this error the program is taking serial no. from the user which is unique. */

    case '1':
        printf("Enter book serial no. to delete:");
        scanf("%d",&SERIAL);
        check_book(SERIAL); //Calling check book function by value, to check whether the book which is to be deleted exists or not
        if(check_book(SERIAL)==0)   //if the function returns 0, if statement will execute.
        {
            printf("\n\t\t\t\t  *** No such book ***");
            goto x; //Execution will jump towards label 'x'
        }
        else
            d_isbn(SERIAL); //Calling function by value
        break;
    case '2':
        printf("Enter book serial no. to delete:\n");
        scanf("%d",&SERIAL);
        check_book(SERIAL); //Calling check book function by value,
        if(check_book(SERIAL)==0)   //if the function returns 0, if statement will execute.
        {
            printf("\n\t\t\t\t  *** No such book ***");
            goto x; //Execution will jump towards label 'x'
        }
        else
            d_book(SERIAL);
        break;
    case '3':
        printf("Enter book serial no. to delete:\n");
        scanf("%d",&SERIAL);
        check_book(SERIAL); //Calling check book function by value,
        if(check_book(SERIAL)==0)   //if the function returns 0, if statement will execute.
        {
            printf("\n\t\t\t\t  *** No such book ***");
            goto x;  //Execution will jump towards label 'x'
        }
        else
            d_author(SERIAL);
        break;
    default:
        printf("\nWrong choice");
    }
    x:label:printf("\n\nDelete another record?(y/n)\n");
    ch=getch();
    if(ch=='n'||ch=='N')
        goto end;
    if(ch=='y'||ch=='Y')
        goto start;
    end:printf("\nUpdate successful");
}
void search_book()  //This function is for searching books in library
{
    system("cls");
    char j;
    char c=219,d=219;
    printf("\n\t\t\t    *****************************");
    printf("\n\t\t\t    %c%c%c%c%c%c%c%c SEARCH BOOK %c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d);
    printf("\t\t\t    *****************************\n\n");
    char b;
    printf("\n\t\t\t\t 1-Search by ISBN\n\t\t\t\t 2-Search by book name\n\t\t\t\t 3-Search by author name\n\n");
    start:printf("\t\t\t\t     Search by?\n\n");
    b=getch();
    switch(b)
    {
    case '1':
        s_isbn();   //calling function
        break;
    case '2':
        s_book();   //calling function
        break;
    case '3':
        s_author(); //calling function
        break;
    default:
        printf("wrong choice");
    }
    printf("\n\nSearch another record?(y/n)\n");
    char ch=getch();
    if(ch=='n'||ch=='N')
        goto end;
    if(ch=='y'||ch=='Y')
        goto start;
    end:printf("\nSearch successful\n");
}
void update_book()
{
    system("cls");
    char c=219,d=219;
    printf("\n\t\t\t    *****************************");
    printf("\n\t\t\t    %c%c%c%c%c%c%c%c UPDATE BOOK %c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d);
    printf("\t\t\t    *****************************\n\n");
    struct book b;
    int i=0,SERIAL;
    char Nname[25],NAME[25],ch;
    int size=0;
    int flag=0; //Initializing value of flag to '0'
    FILE *fp;
    start:printf("Enter book serial no. to update:\n");
    scanf("%d",&SERIAL);
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    if(fp==NULL)    //If the file is empty, if statement will execute
    {
        puts("cannot open file");
        goto end;    //Execution is jumping to the end of function
    }
    //Reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b.serial,b.isbn,b.name,b.edition,b.author,b.status)!=EOF) //Read until end of file
    {
        if(b.serial==SERIAL)    //if Serial number matches, If statement will execute
        {
            flag=1; //and assign the value of flag to '1'
            break;
        }
    }
    if(flag==0) //If serial number doesnt match, If statemetn wil execute
    {
        printf("No such book\n");
        goto label; //execution will jumpt towards label 'label'
    }i=0;
    fclose(fp); //Closing file
    printf("\nWhat do you want to modify in this book?\n\n");
    printf("1. ISBN no.\n2. Book name\n3. Author name\n\n");
    c=getch();
    switch(c)
    {   /*  if any of the books have same author name, book name or ISBN then program will update all these books,
            to over come this error the program is taking serial no. from the user which is unique. */
    case '1':
        u_isbn(SERIAL);     //calling function with value
        break;
    case '2':
        u_book(SERIAL);     //calling function with value
        break;
    case '3':
        u_author(SERIAL);   //calling function with value
        break;
    default:
        printf("\nWrong choice");
    }
    label:printf("\nUpdate another record?(y/n)\n");
    ch=getch();
    if(ch=='n'||ch=='N')
        goto end;
    if(ch=='y'||ch=='Y')
        goto start;
    end:printf("\nUpdate successful");
}
void display_books()    //This function is for dislaying books on screen
{
    system("cls");
    char c=219,d=219;
    printf("\n\t\t\t    ******************************");
    printf("\n\t\t\t    %c%c%c%c%c%c%c%c DISPLAY BOOK %c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d);
    printf("\t\t\t    ******************************\n\n");
    printf("\nSerial no.\tISBN no.\tBook Name\tEditioin\tAuthor\tStatus\n");
    printf("--------------------------------------------------------------------------------\n");
    char ch;
    FILE *fp;
    struct book b;
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    if (fp==NULL)
    {
        printf("Cannot open file");    //If the file is empty, if statement will execute
    }
    while((ch=fgetc(fp))!=EOF)  //Getting data, character by character from file unless EOF appears
      printf("%c",ch);
    fclose(fp); //closing file
}
void issue_book()   //This function is for reserving book
{
    system("cls");
    char c=219,d=219;
    printf("\n\t\t\t    ****************************");
    printf("\n\t\t\t    %c%c%c%c%c%c%c%c ISSUE BOOK %c%c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,d,d,d,d,d,d,d,d);
    printf("\t\t\t    ****************************\n\n");
    struct book b[100];
    int i=0;
    char name[25],ch;
    int size=0;
    int flag=0; //Initializing flag to 0
    FILE *fp;
    start:printf("Enter book name to reserve:");
    scanf("%s",name);
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    if(fp==NULL)    //If file is empty, IF statement will execute
    {
        puts("\ncannot open file");
        goto end;   //execution will jump to the end of function
    }
    //reading data from file and storing in array
    //This will check name of book which is to be issued, whether it is in the file or not (from line 354 to 366)
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        if(strcmp(b[i].name,name)==0)   //If the name matches, If statement will execute
        {
            flag=1; //and assign flag to '0'
            break;
        }
    }
    if(flag==0) //If the name doesn't match, If statement will execute
    {
        printf("\nNo such book\n\n");
        goto label; //execution will jump to the label 'label'
    }i=0;
    fclose(fp); //closing the file
    fp=fopen("d:\\book.txt","r");   //again opening the file in read mode
    //reading data from file and storing in array
    while(fscanf(fp,"%d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        i++;    //VAlue of 'i' will increment by 1 untill EOF
        size++; //VAlue of 'size' will increment by 1 untill EOF
    }
    fclose(fp); //closing file
    flag=0;
    fp=fopen("d:\\book.txt","w");   //Opening file in write mode
    for(i=0;i<size;i++) //loop will execute unless i=size
    {
        if(strcmp(b[i].name,name)!=0)   //if the book which is to me issued is not found, if statement will execute
        {
            //Overwrite all the data
            fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
        }
        else                             //if the book which is to me issued is found, else statement will execute
        {
            if(b[i].status=='  NO') //If status is 'NO', if statement will execute
            {
                //Writing the book data which is to be issued
                fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
            }
            else
            {
                strcpy(b[i].status,"  YES");   //'Yes' will overwrite 'NO'
                //Writing the book data
                fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
                flag=0; //assign flag to '0'
                break;
            }
        }
    }
    label:printf("\nIssue another book?(y/n)\n");
    ch=getch();
    if(ch=='n'||ch=='N')
        goto end;
    if(ch=='y'||ch=='Y')
        goto start;
    end:fclose(fp);
}
void s_isbn()   //This function will search book by ISBN no.
{
    FILE *fp;
    char aname[25];
    int flag=0,i,j;
    fp=fopen("d:\\book.txt","r");   //opening file in read mode
    if(fp==NULL)    //If the file is empty, if statement will execute
    {
        puts( "\ncannot open file");
        goto end;   //Execution will jump to the end of function
    }
    printf("Enter isbn to search: ");
    scanf("%s",aname);
    //Reading data from file and storing in array
    while(fscanf(fp,"%d\t%s\t%s\t%s\t%s\t%s\n",&b.serial,b.isbn,b.name,b.edition,b.author,b.status)!=EOF)
    {
        if(strcmp(aname,b.isbn)==0) //If the result matches, if stateent will execute
        {
            printf("\nSerial no.\tISBN no.\tBook Name\tEditioin\tAuthor\tStatus\n");
            printf("--------------------------------------------------------------------------------\n");
            printf(" %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b.serial,b.isbn,b.name,b.edition,b.author,b.status);
            flag=1; //assigning '1' to flag
            break;
        }
    }
    if(flag==0) //If file is empty, if statement will execute
    {
        printf("\nNo record found\n");
    }
    end:fclose(fp); //Closing file
}
void s_book()   //This function will search book by name
{
     FILE *fp;
    char aname[25];

    int flag=0,i;
    fp=fopen("d:\\book.txt","r");   //opening file in read mode
    if(fp==NULL)    //If the file is empty, if statement will execute
    {
        puts ( "\ncannot open file" ) ;
        goto end;
    }
    printf("Enter book name to search: ");
    scanf("%s",aname);
    //Reading data from file and storing in array
    while(fscanf(fp,"%d\t%s\t%s\t%s\t%s\t%s\n",&b.serial,b.isbn,b.name,b.edition,b.author,b.status)!=EOF)
    {
        if(strcmp(aname,b.name)==0) //If the result matches, if statement will execute
        {
            printf("\nSerial no.\tISBN no.\tBook Name\tEditioin\tAuthor\tStatus\n");
            printf("--------------------------------------------------------------------------------\n");
            printf(" %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b.serial,b.isbn,b.name,b.edition,b.author,b.status);
            flag=1;
            break;
        }
    }
    if(flag==0) //If file is empty, if statement will execute
    {
        printf("\nNo record found\n");
    }
    end:fclose(fp); //closing file
}
void s_author() //This function will search book by author name
{
    FILE *fp;
    char aname[25];
    int flag=0,i;
    fp=fopen("d:\\book.txt","r");   //opening file in read mode
    if(fp==NULL)    //If the file is empty, if statement will execute
    {
        puts ( "\ncannot open file" ) ;
        goto end;
    }
    printf("Enter author name to search: ");
    scanf("%s",aname);
    //Reading data from file and storing in array
    while(fscanf(fp,"%d\t%s\t%s\t%s\t%s\t%s\n",&b.serial,b.isbn,b.name,b.edition,b.author,b.status)!=EOF)
    {
        if(strcmp(aname,b.author)==0)   //If author name is present in the file, if statement will execute
        {
            printf("\nSerial no.\tISBN no.\tBook Name\tEditioin\tAuthor\tStatus\n");
            printf("--------------------------------------------------------------------------------\n");
            printf(" %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b.serial,b.isbn,b.name,b.edition,b.author,b.status);
            flag=1;
            break;
        }
    }
    if(flag==0) //If file is empty, if statement will execute
    {
        printf("no record found\n");
    }
    end:fclose(fp); //closin file
}
void u_book(int serial) //This function will update book's name
{
    int i=0,size=0;
    char name[25],Nname[25];
    struct book b[100];
    FILE *fp;
    printf("Enter existing Book name\n");
    scanf("%s",name);
    printf("Enter new Book name\n");
    scanf("%s",Nname);
    fp=fopen("d:\\book.txt","r");   //opening book in read mode
    //Reading data from file and storing in array
    while(fscanf(fp,"%d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        i++;    //VAlue of 'i' will increment by 1 untill EOF
        size++; //VAlue of 'size' will increment by 1 untill EOF
    }
    fclose(fp); //closing file
    fp=fopen("d:\\book.txt","w");   //Opening file in write mode
    for(i=0;i<size;i++) //Loop will run untill i<size
    {   //Book name can be same but serial no. cannot be same
        if((b[i].serial==serial)&&(strcmp(b[i].name,name)==0))  //If both serial no and book name matches, if statement will execute
        {
            strcpy(b[i].name,Nname);    //Swapping new name to old name
        }
        //Owerwritting record
        fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
    }
    fclose(fp); //Closing file
}
void u_author(int serial)   //This function will update book's author name
{
    int i=0,size=0;
    struct book b[100];
    FILE *fp;
    char author[25],Nauthor[25];
    printf("Enter existing Author name\n");
    scanf("%s",author);
    printf("Enter new Author name\n");
    scanf("%s",Nauthor);
    fp=fopen("d:\\book.txt","r");   //opening book in read mode
    //Reading data from file and storing in array
    while(fscanf(fp,"%d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        i++;    //VAlue of 'i' will increment by 1 untill EOF
        size++; //VAlue of 'size' will increment by 1 untill EOF
    }

    fclose(fp); //Closing file
    //opening book in write mode
    fp=fopen("d:\\book.txt","w");
    for(i=0;i<size;i++) //Loop will run untill i<size
    {   //Author name can be same but serial no. cannot be same
        if((b[i].serial==serial)&&(strcmp(b[i].author,author)==0))  //If both serial no and author name matches, if statement will execute
        {
            strcpy(b[i].author,Nauthor);    //Swapping new author name to old name
        }
        //Overwitting record
        fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
    }
    fclose(fp); //Closing file
}
void u_isbn(int serial) //This function will update book's ISBN no.
{

    int i=0,size=0;
    struct book b[100];
    FILE *fp;
    char isbn[25],Nisbn[25];
    printf("Enter existing ISBN no.\n");
    scanf("%s",isbn);
    printf("Enter new ISBN no.\n");
    scanf("%s",Nisbn);
    fp=fopen("d:\\book.txt","r");   //opening book in read mode
    //Reading data from file and storing in array
    while(fscanf(fp,"%d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        i++;    //VAlue of 'i' will increment by 1 untill EOF
        size++; //VAlue of 'size' will increment by 1 untill EOF
    }

    fclose(fp); //Closing file
    //opening book in write mode
    fp=fopen("d:\\book.txt","w");
    for(i=0;i<size;i++) //Loop will run untill i<size
    {   //ISBN can be same but serial no. cannot be same
        if((b[i].serial==serial)&&(strcmp(b[i].isbn,isbn)==0))   //If both serial no and ISBN matches, if statement will execute
        {
            strcpy(b[i].isbn,Nisbn);    //Swapping new ISBN with Old ISBN
        }
        //Overwritting record
        fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
    }
    fclose(fp); //Closing file
}
void d_book(int serial) //This function will delete book by its name
{
    struct book b[100];
    int i=0;
    int size=0;
    int flag=0;
    char name[20],ch;
    FILE *fp;
    printf("\nEnter book name to delete:\n");
    scanf("%s",name);
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    if(fp==NULL)    //If fle is empty, if statement will execute
    {
        puts("cannot open file");
        goto label; //Execution of the program jumping to the end of function
    }
    //reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        //Checking if Book exists or not
        if(strcmp(b[i].name,name)==0)   //If book matches, if statement will execute
        {
            flag=1; //Assigning '1' to flag
            break;
        }
    }
    if(flag==0) //If book doesnt match, If statement will execute
    {
        printf("\n\t\t\t\t  *** No such book ***");
        goto label; //Execution of the program jumping to the end of function
    }
    fclose(fp); //Closing file
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    //reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        i++;    //VAlue of 'i' will increment by 1 untill EOF
        size++; //VAlue of 'size' will increment by 1 untill EOF
    }
    fclose(fp); //closing file
    //Opening book in write mode
    fp=fopen("d:\\book.txt","w");
    //The below code will overwrite every record in the file except for one which we want to delete
    for(i=0;i<size;i++) //Loop will run untill i<size
    {
        if((strcmp(b[i].name,name)==0)&&(b[i].serial==serial))  //If both serial no and book name matches, if statement will execute
            continue;   //Skipping next statements in the loop
        else
            //Writting record to file
            fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
        printf("Book deleted successfully\n");
    }
    label:fclose(fp);   //Closing file
}
void d_isbn(int serial) //This function will delete book by ISBN
{
    struct book b[100];
    int i=0;
    int size=0;
    int flag=0;
    char isbn[20],ch;
    FILE *fp;
    printf("\nEnter ISBN name to delete:\n");
    scanf("%s",isbn);
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    if(fp==NULL)    //If fle is empty, if statement will execute
    {
        puts("cannot open file");
        goto label; //Execution of the program jumping to the end of function
    }
    //reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        //Checking if Book exists or not
        if(strcmp(b[i].isbn,isbn)==0)   //If book matches, if statement will execute
        {
            flag=1; //Assigning '1' to flag
            break;
        }
    }
    if(flag==0) //If book doesnt match, If statement will execute
    {
        printf("\n\t\t\t\t  *** No such book ***");
        goto label; //Execution of the program jumping to the end of function
    }
    fclose(fp); //closing file
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    //reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        i++;    //VAlue of 'i' will increment by 1 untill EOF
        size++; //VAlue of 'size' will increment by 1 untill EOF
    }
    fclose(fp); //closing file
    //Opening book in write mode
    fp=fopen("d:\\book.txt","w");
    //The below code will overwrite every record in the file except for one which we want to delete
    for(i=0;i<size;i++) //Loop will run untill i<size
    {
        if((strcmp(b[i].isbn,isbn)==0)&&(b[i].serial==serial))  //If both serial no and ISBN matches, if statement will execute
            continue;   //Skipping next statements in the loop
        else
            fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
        printf("Book deleted successfully\n");
    }
    label:fclose(fp);
}
void d_author(int serial)   //This function will delete book by its author name
{
    struct book b[100];
    int i=0;
    int size=0;
    int flag=0;
    char author[20],ch;
    FILE *fp;
    start:printf("\nEnter Author name to delete:\n");
    scanf("%s",author);
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    if(fp==NULL)    //If fle is empty, if statement will execute
    {
        puts("cannot open file");
        goto label; //Execution of the program jumping to the end of function
    }
    //reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        //Checking if Book exists or not
        if(strcmp(b[i].author,author)==0)
        {
            flag=1; //Assigning flag '0'
            break;
        }
    }
    if(flag==0) //If book doesnt match, If statement will execute
    {
        printf("\n\t\t\t\t  *** No such book ***");
        goto label; //Execution of program will jump to the end of function
    }
    fclose(fp); //Closing file
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode
    //reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status)!=EOF)
    {
        i++;    //VAlue of 'i' will increment by 1 untill EOF
        size++; //VAlue of 'size' will increment by 1 untill EOF
    }
    fclose(fp); //closing file
    //Opening book in write mode
    fp=fopen("d:\\book.txt","w");
    //The below code will overwrite every record in the file except for one which we want to delete
    for(i=0;i<size;i++) //Loop will run untill i<size
    {
        if((strcmp(b[i].author,author)==0)&&(b[i].serial==serial))  //If both serial no and author name matches, if statement will execute.
            continue;   //Skipping next statements in the loop
        else
            fprintf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",b[i].serial,b[i].isbn,b[i].name,b[i].edition,b[i].author,b[i].status);
    }
    label:fclose(fp);   //Closing file
}
int check_book(int serial)  //This function will check the book, whether it's in the library or not.
{
    struct book b;
    int flag=0; //Initializing flag to '0'
    FILE *fp;
    fp=fopen("d:\\book.txt","r");   //Opening file in read mode.
    //reading data from file and storing in array
    while(fscanf(fp," %d\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n\n",&b.serial,b.isbn,b.name,b.edition,b.author,b.status)!=EOF)
    {
        if(b.serial==serial)    //If result matches, if statement will execute
        {
            flag=1; //Assigning '1' to flag
            break;
        }
    }
    if(flag==0) //If result doesn't match, if statement will execute
    {
        fclose(fp); //closing file
        return 0;   //returning 0 to the function
    }
    if(flag==1) //If result matches this statement will execute
    {
        fclose(fp);//closing file
        return 1;   //returning 1 to the function
    }
}
