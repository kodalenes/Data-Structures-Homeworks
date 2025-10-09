#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node* head = NULL;

node* createNode(int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

node* addNode()
{
    node* temp = head;

    int newData;

    printf("Enter new data.\n");
    scanf("%d" , &newData);

    node* newNode = createNode(newData);

    return newNode;
}

void addAtTheBeginning()
{
    node* newNode = addNode();
    
    //Liste bossa basa ekle
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else//Liste doluysa basa ekle
    {
        node* temp = head;
        //listenin sonu.next u  yeni heade ata
        while (temp->next != head)
        {
            temp = temp->next;
        }
        //Sona gidiyoz ve sonuncu.next = newnode
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void addAtTheEnd()
{
    node* newNode = addNode();

    //Liste bossa ekle
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else//Liste bos degilse sona ekle
    {
        node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;//Liste sonuna gittik
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void traverseList()
{
    if (head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        node* temp = head;
        int nodeCount = 1;
 
        do
        {
            printf("%d. node , Data: %d\n" , nodeCount++ , temp->data);
            temp = temp->next;
        } while (temp != head);
        
    }
}

int main()
{
    int choice;

    do
    {
        printf("-----------\n");
        printf("1-Basa Ekle\n");
        printf("2-Sona Ekle\n");
        printf("3-Listele\n");
        printf("0-Cikis\n");
        printf("Seciminiz: ");
        scanf("%d" , &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            addAtTheBeginning();
            break;
        case 2:
            addAtTheEnd();
            break;
        case 3:
            traverseList();
            break;
        case 0:
            printf("Program sonlandiriliyor...");
            return 0;
        
        default:
            printf("Yanlis secim!\n");
            break;
        }

    } while (choice != 0);
    
}
