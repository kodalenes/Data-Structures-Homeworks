#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node* head = NULL;

node* createNode(int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void addNode()
{
    node* temp = head;

    int newData;
    printf("Enter new data..");
    scanf("%d" , &newData);
    node* newNode = createNode(newData);

    //Liste bossa ekleme basa ekler
    if (head == NULL)
    {
        head = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    else//Liste nin sonuna ekleme
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        newNode->prev = temp;
    }
}

void traverseList()
{
    node* temp = head;
    int count = 1;

    while (temp != NULL)
    {
        printf("%d. %d\n" , count++ , temp->data);
        temp = temp->next;
    }   
}

void deleteNode()
{
    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }
    
    node* temp = head;
    
    int key;
    printf("Enter the data which will be delete");
    scanf("%d" , &key);

    //Silinecek listenin basindaysa
    if (head->data == key)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    else//Silinecek veri orta veya sondaysa
    {
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        
        temp->prev->next = temp->next;
        if (temp->next !=NULL)//silinecek node sonuncuysa eksrta kontrol
        {
            temp->next->prev = temp->prev;
        }
        
        free(temp);
    }
    
}

void destroyList()
{
    node* temp = head;

    while (head != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    printf("List destroyed\n");
}

int destroyListRecursive(node* current)
{
    if (current == NULL)
    {
        return 0;
    }else
    {
        int count = destroyListRecursive(current->next); 
        free(current);
        return count + 1;
    }
}

int main()
{
    int choice;
    
    do
    {
        
        printf("1 -Listeye ekle\n");
        printf("2 -Listeti yazdir\n");
        printf("3 -Listeden sil\n");
        printf("4 -Listeyi sil\n");
        printf("0 -Cikis\n");
        printf("Seciminiz : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1: addNode();
                break;
            case 2: traverseList();
                break;
            case 3: deleteNode();
                break;
            case 4: 
                {
                    int deletedCount = destroyListRecursive(head);
                    head = NULL;
                    printf("List destroyed recursively. %d node(s) deleted.\n" , deletedCount);
                }
                break;
            case 0:
                printf("Program sonlandirildi!\n");
                break;
            default: printf("Yanlis secim!");
                break;
        }
    } while (choice != 0);
    
    

    return 0;
}
