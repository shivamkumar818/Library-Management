#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct book {
        int id;
        char name[30];
        char author[20];
        char avbl;
        char isname[100];
    } 
    bk[20]={0};

    int choice, searchid, n, m,y;

    printf("\n\t\tWELCOME!\n");
    
    do
    {                           
        printf("\n\tLibrary Management System\n");
        printf("\t=========================\n");
        printf("1. Add new book\n\n");
        printf("2. Search book\n\n");
        printf("3. Issue book\n\n");
        printf("4. Submit book\n\n");
        printf("5. List of books\n\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: \n");

        scanf("%d", &choice);

        switch(choice) 
        {

            case 1:
                for(int i=0; i<20; i++)
                {
                    if (bk[i].id==0)
                    {               
                        printf("Enter name of the book: ");
                        scanf("%s", bk[i].name);
                        printf("Enter name of the author: ");
                        scanf("%s", bk[i].author);
                        printf("Enter book ID: ");
                        scanf("%d", &bk[i].id);
                        bk[i].avbl='y';
                        m=bk[i].id;
                        i=20;
                        printf("Book added successfully.\n\n");
                    }
                }
            break;

            case 2:
                printf("Enter book ID: ");
                scanf("%d", &searchid);
                n=0;
                for(int i=0; i<20; i++)
                {
                    if (searchid == bk[i].id)
                    {
                    printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %c\t\n", bk[i].id, bk[i].name, bk[i].author, bk[i].avbl);
                    n++;
                    }
                }
                if(n==0)
                {
                    printf("Book not found.\n\n");
                }

                break;

            case 3:
                printf("Enter book ID: ");
                scanf("%d", &searchid);
                y=searchid-101;
                if(y<0 || searchid>m)
                {
                    printf("ID not available!");
                    break;
                }
                if(bk[y].avbl=='y'){
                printf("Enter Issuer Name: ");
                scanf("%s", bk[y].isname);
                printf("Book sucessfully issued!!");
                bk[y].avbl='n';
                }
                else{
                    printf("Sorry the Book is not available it is issued by %s",bk[y].isname);
                }
               break;
            
            case 4:
                printf("Enter book ID: ");
                scanf("%d", &searchid);
                y=searchid-101;
                if(y<0 || searchid>m)
                {
                    printf("ID not available!");
                    break;
                }
                if(bk[y].avbl=='n') 
                {
                    bk[y].avbl='y';
                    printf("Book is returned Thank You");
                    break;
                }
                else{
                    printf("ID invalid to submit the book!");
                    break;
                }

            case 5:
                n=0;
                printf("Input number of books to print\n");
                scanf("%d",&n);
                FILE *filePointer; 
                filePointer = fopen("library.txt", "w");
                fprintf(filePointer, "ID \tAvailable\tBook Name\n");
                for(int i=0; i<n; i++)
                {
                    fprintf(filePointer, "%d\t    %c    \t%s\n", bk[i].id, bk[i].avbl, bk[i].name); 
                }
                fclose(filePointer);
                break;

            case 6:
                printf("\n\t\tTHANK YOU!");
                exit(0);
                break;
        }

    }while(choice!=6);

    return 0;
}