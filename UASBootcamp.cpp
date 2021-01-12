#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char word[255];
    Node *next;
    Node *prev;
}*head,*tail;

Node *createNode(const char *word){
    Node *temp = (Node*) malloc(sizeof(Node));
    strcpy(temp->word,word);
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void pushHead(const char *word){
    Node *temp = createNode(word);

    if(!head){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;    
    }
}

void pushTail(const char *word){
    Node *temp = createNode(word);
    if(!head){
        head = tail  = temp;
    }
    else{
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void popHead(){
    Node *temp = head->next;
    if(!head){
        return;
    }
    else{
        head->next = NULL;
        temp->prev = NULL;
        head = NULL;
        free(head);
        head = temp; 
    }

}

void popTail(){
    Node *temp = tail->prev;

    if(!head){
        return;
    }
    else{
        tail->prev = NULL;
        temp->next = NULL;
        tail = NULL;
        free(tail);
        tail = temp;
    }
}

void popMid(const char *word){
    if(!head){
        return;
    }
    else if(strcmp(word,head->word) == 0){
        popHead();
    }
    else if(strcmp(word,tail->word) == 0){
        popTail();
    }
    else{
        Node *curr = head;
        while(curr &&  strcmp(word,curr->word) != 0){
            curr = curr->next;
        }
        
        if(!curr){
            puts("Word Not Found");
            return;
        }

        curr->prev->next =curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        curr = NULL;
        free(curr);

    }
}

void printLL(){
    Node *curr = head;

    while(curr){
        printf("%s\n",curr->word);
        curr = curr->next;
    }
    
}

int main(){

    int choose;
    char kata[255];
    char hapus[255];
    do{
        puts("1. insert word");
        puts("2. delete word");
        puts("3. print the word");
        puts("4. exit");
        printf("Choose number : ");
        scanf("%d",&choose);

        if(choose == 1){
            printf("Enter word to insert :");
            scanf("%s",&kata);
            pushTail(kata);
        }
        else if(choose == 2){
            printf("Enter word to delete : ");
            scanf("%s",&hapus);
            popMid(hapus);
        }
        else if(choose == 3){
            printLL();
        }

    }while(choose != 4);


    return 0;
}