//singly linked-list

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

typedef struct SinglyLL {
    int data;
    struct SinglyLL *next;
} node;

void CreateLL(node *head);
void DisplayLL(node *head);
int countNode(node *head);
int search(node *head, int key);
void menu();
int subMenu(node **head);
node *mergeLL(node *head, node *head1);
node *insertFirst(node *head);
node *insertBetween(node *head);
node *insertLast(node *head);
node *deleteFirst(node *head);
node *deleteBetween(node *head);
node *deleteLast(node *head);
node *bubbleSort(node *head);

void main() {
    clrscr();
    menu();
    getch();
}

void menu() {
    int ch, cnt = 0, key;
    node *head = NULL, *head1 = NULL;
    clrscr();
    head = (node*)malloc(sizeof(node));
    head1 = (node*)malloc(sizeof(node));
    printf("\n---Main Menu---\n");
    do {
        printf("\n1..Create");
        printf("\n2..Display");
        printf("\n3..Count");
        printf("\n4..Search");
        printf("\n5..Insert/Delete");
        printf("\n6..Merge");
        printf("\n7..Bubble Sort");
        printf("\n0..Exit");

        printf("\n\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            clrscr();
			DisplayLL(head);
            CreateLL(head);
            clrscr();
            break;
        case 2:
            clrscr();
            DisplayLL(head);
            break;
        case 3:
            clrscr();
			DisplayLL(head);
            cnt = countNode(head);
            printf("Total No of node: %d", cnt);
            break;
        case 4:
            clrscr();
			DisplayLL(head);
            printf("\nEnter value to search: ");
            scanf("%d", &key);
            if (search(head, key) == 1) {
                printf("\n%d Found.", key);
            }
            else {
                printf("\n%d Not Found.", key);
            }
            break;
        case 5:
            clrscr();
			DisplayLL(head);
            subMenu(&head);
            break;
        case 6:
            clrscr();
			DisplayLL(head);
            CreateLL(head);
            DisplayLL(head);
            CreateLL(head1);
            DisplayLL(head1);
            head = mergeLL(head, head1);
            DisplayLL(head);
            break;
        case 7:
            clrscr();
			DisplayLL(head);
            bubbleSort(head);
            break;
        case 0:
            exit(0);
        default:
            clrscr();
            printf("Enter the right choice");
            break;
        }
    } while (ch != 0);
}

int subMenu(node **head) {
    int ch;
    node *tempHead = *head;
    clrscr();
    printf("\n---Sub Menu---\n");
    do {
        printf("\n1..Insert First");
        printf("\n2..Insert Between");
        printf("\n3..Insert Last");
        printf("\n4..Delete First");
        printf("\n5..Delete Between");
        printf("\n6..Delete Last");
        printf("\n0..Exit");

        printf("\n\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            clrscr();
			DisplayLL(head);
            *head = insertFirst(*head);
            break;
        case 2:
            clrscr();
			DisplayLL(head);
            *head = insertBetween(*head);
            break;
        case 3:
            clrscr();
			DisplayLL(head);
            *head = insertLast(*head);
            break;
        case 4:
            clrscr();
			DisplayLL(head);
            *head = deleteFirst(*head);
            break;
        case 5:
            clrscr();
			DisplayLL(head);
            *head = deleteBetween(*head);
            break;
        case 6:
            clrscr();
			DisplayLL(head);
            *head = deleteLast(*head);
            break;
        case 0:
            clrscr();
            printf("\n---Main Menu---\n");
            break;
        default:
            clrscr();
            printf("Enter the right choice");
            break;
        }
    } while (ch != 0);

    *head = tempHead;
    return 0;
}

node *insertFirst(node *head) {
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter the number: ");
    scanf("%d", &newnode->data);
    newnode->next = head->next;
    head->next = newnode;
    printf("\n%d Inserted Successfully", newnode->data);
    return head;
}

node *deleteFirst(node *head) {
    node *temp;
    if (head->next == NULL) {
        printf("\nLinked List Empty");
    }
    else {
        temp = head->next;
        head->next = temp->next;
        printf("\n%d deleted successfully", temp->data);
        free(temp);
    }
    return head;
}

node *insertBetween(node *head) {
    int val, flag;
    node *p, *newnode;
    DisplayLL(head);
    printf("\nEnter the value where to Insert: ");
    scanf("%d", &val);
    if (search(head, val) == 1) {
        p = head;
        while (p->data != val) {
            p = p->next;
        }
        newnode = (node*)malloc(sizeof(node));
        printf("\nEnter the value you want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = p->next;
        p->next = newnode;
        printf("Inserted Successfully", newnode->data);
    }
    else {
        printf("\n%d Value is not found", val);
    }
    return head;
}

node *deleteBetween(node *head) {
    int val, flag;
    node *temp, *p;
    p = head;
    printf("Enter the value you want to delete: ");
    scanf("%d", &val);
    flag = search(head, val);
    if (flag == 1) {
        while (p->next->data != val) {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        printf("\n%d deleted successfully", temp->data);
        free(temp);
    }
    else {
        printf("\nElement not found");
    }
    return head;
}

node *insertLast(node *head) {
    node *p = head->next;
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    DisplayLL(head);
    printf("\nEnter value to Insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (p->next == NULL) {
        printf("\nInsert Successfully");
        return newnode;
    }
    else {
        while (p->next != NULL) {
            p = p->next;
        }
        if (p->next == NULL) {
            p->next = newnode;
        }
        printf("\nInsert Successfully");
    }
    return head;
}

node *deleteLast(node *head) {
    node *p, *temp;
    p = head;
    if (p->next == NULL) {
        printf("\nLinked List Empty");
    }
    else {
        while (p->next->next != NULL) {
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        printf("\n%d deleted successfully", temp->data);
        free(temp);
    }
    return head;
}

node *bubbleSort(node *head) {
    node *i, *j;
    int temp;
    printf("Linked list has been sorted\n");
    for (i = head; i->next != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
    DisplayLL(head);
    return head;
}

void CreateLL(node *head) {
    node *l;
    int n, i;
    l = head;
    printf("\n\nEnter number of nodes to create: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        l->next = (node*)malloc(sizeof(node));
        l = l->next;
        printf("\n\nEnter the value: ");
        scanf("%d", &l->data);
    }
    l->next = NULL;
}

void DisplayLL(node *head) {
    node *P;
    P = head;
    do {
        P = P->next;
        printf("%d -->", P->data);
    } while (P->next != NULL);
}

int countNode(node *head) {
    int cnt = 0;
    node *p;
    p = head;
    while (p->next != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int search(node *head, int key) {
    int flag = 0;
    node *p;
    p = head;
    while (p->next != NULL) {
        if (p->data == key) {
            flag = 1;
            break;
        }
        p = p->next;
    }
    return flag;
}

node *mergeLL(node *head, node *head1) {
    node *p;
    p = head1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = head->next;
    return head1;
}
