#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int no;
    char name[40];
    int midtermGrade;
    int finalGrade;
    struct student *next;
};
typedef struct student node;

node* head = NULL;

node* createStudent(int no ,char name[],int midtermGrade , int finalGrade)
{
    node* newStudent = (node*) malloc(sizeof(node));
    newStudent->no = no;
    strcpy(newStudent->name,name);
    newStudent->midtermGrade = midtermGrade;
    newStudent->finalGrade = finalGrade;
    newStudent->next = NULL;
    return newStudent;
}

void addStudent()
{
    //Girdileri al
    int no,midtermGrade,finalGrade;
    char name[40];

    printf("Yeni ogrencinin numarasini giriniz?"); scanf("%d" ,&no);
    printf("Yeni ogrencinin ismini giriniz?"); scanf("%s" ,name);
    printf("Yeni ogrencinin vize notunu giriniz?"); scanf("%d" ,&midtermGrade);
    printf("Yeni ogrencinin final notunu giriniz?"); scanf("%d" ,&finalGrade);

    //Yeni dugum olustur
    node* newStudent = createStudent(no ,name ,midtermGrade ,finalGrade);
    
    //Dugumun nereye eklenecegini goster
    //Basa ekler(uygunsa)
    if (head == NULL || head->no >= no)
    {
        newStudent->next = head;
        head = newStudent;
    }
    else
    {
        node* current = head;
        //Numaraya gore uygun sirayi bulur.
        while (current->next != NULL && current->next->no < no)
        {
            current = current->next;
        }
        newStudent->next = current->next;
        current->next = newStudent;
    }
    printf("\n");
}

void listAll()
{
    node* current = head;

    if (current == NULL)
    {
        printf("Liste bos!");
    }
    
    while (current)
    {
        int ortalama = ((current->midtermGrade * 0.4) + (current->finalGrade * 0.6));
        printf("Ogrenci bilgileri\n");
        printf("Isim: %s No: %d Vize: %d Final: %d Ortalama : %d\n" ,
                current->name ,current->no ,current->midtermGrade,current->finalGrade , ortalama);

        current = current->next;
    }
    printf("\n");
}

void mainMenu()
{
    int choice;

    do
    {
        printf("Ogrenci eklemek icin 1\n");
        printf("Listelemek icin 2\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            listAll();
            break;
        case 0:
            printf("Program sonlandirildi!");
        default:
            printf("Gecersiz secim!\n");
            break;
        }
    } while (choice != 0);
}

int main()
{
    mainMenu();

    return 0;
}