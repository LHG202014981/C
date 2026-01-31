#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    char author[50];
    int is_borrowed;
} Book;

void addBook(Book **lib, int *bookCount);
void printAllBooks(Book *lib, int bookCount);
void searchBook(Book *lib, int bookCount);
void saveToFile(Book *lib, int bookCount);

int main(){

/******************************************************불러오기**********************************************/
    FILE *fp;
    fp=fopen("book.txt","r");

    Book *library =NULL;
    int bookCount=0;

    if(fp!=NULL){

        Book temp;

    while(fscanf(fp,"%d %s %s %d\n",&temp.id,temp.title,temp.author,&temp.is_borrowed)==4){

        Book *next_library=realloc(library,sizeof(Book)*(bookCount+1));
        if(next_library==NULL) break;
        library=next_library;

        library[bookCount]=temp;

        bookCount++;
    }

    fclose(fp);
    printf("%d개의 도서를 불러왔습니다.\n",bookCount);
}

/******************************************************넣기**********************************************/
    fp=fopen("book.txt","a");

    while(1){
        Book *temp=realloc(library,sizeof(Book)*(bookCount+1));

        if(temp == NULL){
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        library=temp;

        library[bookCount].id=bookCount+1;
        printf("제목(q를 입력하면 종료) : \n");
        scanf("%s",library[bookCount].title);
        if(strcmp(library[bookCount].title, "q") == 0){break;}
        printf("저자 : \n");
        scanf("%s",library[bookCount].author);
         library[bookCount].is_borrowed=0;

        fprintf(fp, "%d %s %s %d\n",library[bookCount].id,library[bookCount].title,library[bookCount].author,library[bookCount].is_borrowed);
        

        bookCount++;
}
fclose(fp);

/******************************************************출력**********************************************/
    for(int i=0;i<bookCount;i++){
        printf("ID : %d\n", library[i].id);
        printf("제목 : %s\n", library[i].title);
        printf("저자 : %s\n", library[i].author);
        printf("대출내역 : %d\n", library[i].is_borrowed);
    }

    free(library);

    return 0;
}

void addBook(Book **lib, int *bookCount){}
void printAllBooks(Book *lib, int bookCount){}
void searchBook(Book *lib, int bookCount){}
void saveToFile(Book *lib, int bookCount){}