#include <stdio.h>
#include <stdlib.h>

struct link{
    int data;
    struct link* next;
};

// 函数声明
struct link* AppendNode(struct link*, int); 
void DisplayNode(struct link*); 
void DeleteMemory(struct link*);
struct link* DeleteNode(struct link*, int);  
struct link* InsertNode(struct link*, int, int); 
void ShowMenu();

int main(){
    int position,data = 0;
    struct link* head = NULL;  // 先给链表赋值为空
    printf("Please type the data(data >= 0, input -1 to quit):\n");
    while(1){
        scanf("%d", &data);
        if(data == -1){
            break;
        }
        head = AppendNode(head, data);  // 逐一向链表尾部添加节点
    }
    // 遍历显示列表
    DisplayNode(head);

    system("pause");
    system("cls");
    
    int index ;
    while(1){
        ShowMenu();
        scanf("%d", &index);
        switch(index){
        case 1:  // 添加节点
            printf("Please type the data(data >= 0, input -1 to quit):\n");
            while(1){
                scanf("%d", &data);
                if(data == -1){
                    break;
                }
                head = AppendNode(head, data);  // 逐一向链表尾部添加节点
            }
            DisplayNode(head);  // 遍历显示列表
            system("pause");
            system("cls");
            break;
        case 2:  // 删除节点
            printf("please type the delete data:");
            scanf("%d", &data);
            head = DeleteNode(head, data);
            DisplayNode(head);  // 遍历显示列表
            system("pause");
            system("cls");
            break;
        case 3:  // 插入节点
            printf("Please type the insert data and its position(eg:3 4):");
            scanf("%d %d", &data, &position);
            head = InsertNode(head, data, position);
            DisplayNode(head);  // 遍历显示列表
            system("pause");
            system("cls");
            break;
        case 4:  // 遍历显示列表
            DisplayNode(head);  // 遍历显示列表
            system("pause");
            system("cls");
            break;
        case 5:  // 删除链表内存
            DeleteMemory(head);
            system("pause");
            system("cls");
            break;
        case 0:  // 退出
            system("pause");
            return 0;
        default:
            printf("Code type error! Please input the code again!\n");
            system("pause");
            system("cls");
        }
    }

    // 删除链表内存
    DeleteMemory(head);
    
    system("pause");
    return 0;
}

// 向链表尾部添加节点函数
struct link* AppendNode(struct link* head, int data){
    struct link* new_node = (struct link*)malloc(sizeof(struct link));  // 申请新结点

    if(new_node == NULL){
        printf("No Enough Memory.\n");
        exit(0);
    }   // 空间不足处理

    new_node->data = data;
    new_node->next = NULL;  // 向new_node赋值

    if(head == NULL){
        head = new_node;
    }  // 若链表为空，则new_node直接接在链表头部
    else{
        struct link* p = head;
        while(p->next != NULL){
            p = p->next;
        }  // 定义以及寻找链表尾部
        p->next = new_node;  // new_node接在链表尾部
    }

    return head;
}

// 遍历显示链表函数
void DisplayNode(struct link* head){
    struct link* p = head;

    if(p == NULL){
        printf("Link Is Null.\n");
    }  // 若链表为空，直接退出

    else{
        printf("%d", p->data);
        p = p->next; 
    }  // 打印第一个节点的值
    while(p!=NULL){
        printf("->%d",p->data);
        p = p->next;
    }  // 从第二个开始，逐个打印各节点的值
    printf("\n");
}

// 删除链表内存函数
void DeleteMemory(struct link* head){
    struct link* p;
    while(head != NULL){
        p = head;
        head = head->next;
        free(p);
    }  // 逐个释放各节点的值
}

// 删除节点函数
struct link* DeleteNode(struct link* head, int data){
    struct link* p = head, * temp = p->next;  // 定义临时存储要删除的节点的变量
    int num = 0;  // 统计删除的节点个数

    if(p == NULL){
        printf("Link Is Null.\n");
        return head;
    }  // 若链表为空，直接退出

    while(temp != NULL){
        if(temp->data == data){
            p->next = temp->next;
            free(temp);
            temp = NULL;  // 释放temp存储的值，删除节点
            num++;
            return head;
        }
        p = p->next;
        temp = temp->next;  // 移动至下一个节点
    }

    if(num == 0){
        printf("Node not exist.\n");
    }

    return head;
}

// 插入节点函数
struct link* InsertNode(struct link* head, int data, int position){
    struct link* p = head, * previous, * new_node;

    if(p == NULL){
        printf("Link Is Null.\n");
        return head;
    }  // 若链表为空，直接退出

    int i;
    for(i = 1; i < position && p->next != NULL; i++){
        previous = p;
        p = p->next;
    }  // 寻找要插入的位置

    if(p->next == NULL){
        printf("Position is larger than link's length\n");
        return head;
    }

    new_node = (struct link *)malloc(sizeof(struct link));  // 申请新节点

    if(new_node == NULL){
        printf("No Enough Memory.\n");
        exit(0);
    }   // 空间不足处理

    new_node->data = data;
    new_node->next = p;
    previous->next = new_node;  // 插入新节点

    return head;
}

// 菜单函数
void ShowMenu(){
    printf("1: Append data\n");
    printf("2: Delete data\n");
    printf("3: Insert data\n");
    printf("4: Display node\n");
    printf("5: Clear link\n");
    printf("0: Exit");
    printf("\nPlease type the code:");
}