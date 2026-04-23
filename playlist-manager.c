#include <stdio.h>
#include <stdlib.h>
struct node{
    char title[50];
    char artist[50];
    int duration;
    struct node* prev;
    struct node* next;
};
struct node* current = NULL;
struct node* addSong(struct node* head);
struct node* deleteSong(struct node*);
void display(struct node*);
struct node* playNext(struct node*);
struct node* playPrev(struct node* current);
int main()
{
    int choice;
    struct node* head = NULL;
    current = head;
    do {
        printf("\n1.Add 2.Delete 3.Display 4.Next 5.Prev 6.Search 7.Exit\n");
        scanf("%d", &choice);
        switch(choice) {

            case 1: head = addSong(head); break;
            case 2: head = deleteSong(head); break;
            case 3: display(head); break;
            case 4: current = playNext(current); break;
            case 5: current = playPrev(current); break;
            case 6: search(); break;
            case 7: exit(0);
            default: printf("\nInvalid choice\n");
        }
    } while(1); 
    return 0;
}


struct node* addSong(struct node* head){
    struct node* newSong = malloc(sizeof(struct node));
    if(!newSong){
        printf("Memory allocation failed.");
        return NULL;
    }
    printf("Enter song title: ");
    scanf(" %[^\n]", newSong-> title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newSong-> artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &newSong-> duration);
    newSong-> prev = NULL;
    newSong-> next = NULL;
    if(head == NULL){
        if(current == NULL) current = newSong;
        return newSong;
    }
    struct node* ptr = head;
    while(ptr-> next != NULL){
        ptr = ptr-> next;
    }
    ptr-> next = newSong;
    newSong-> prev = ptr;
    return head;
}

struct node* deleteSong(struct node* head){
    if(head == NULL){
        printf("Playlist is empty.");
        return NULL;
    }
    int n;
    printf("Enter the index of song you want to delete: ");
    scanf("%d", &n);
    struct node* ptr = head;
    if(n == 1){
        free(head);
        ptr = ptr-> next;
        ptr-> prev = NULL;
        if(ptr == current)
        current = ptr->next ? ptr->next : ptr->prev;
        return ptr;
    }
    for(int i = 1; i < n && ptr != NULL; i++){
        ptr = ptr-> next;
    }
    struct node* temp = ptr;
    if(ptr-> prev != NULL)
    ptr-> prev-> next = ptr-> next;
    if(ptr-> next != NULL)
    ptr-> next-> prev = ptr-> prev;
    free(temp);
    return head;
}

void display(struct node* head){
    struct node* ptr = head;
    int i = 1;
    printf("\n----- PLAYLIST -----\n");
    if(ptr == NULL){
        printf("Playlist is empty\n");
        return;
    }
    while(ptr != NULL){
        printf("%2d. %-20s | %-15s | %3d sec\n",i, ptr->title, ptr->artist, ptr->duration);
        ptr = ptr->next;
        i++;
    }
    printf("--------------------\n");
}


struct node* playNext(struct node* current){
    if(current == NULL){
        printf("PLaylist is empty.\n");
        return NULL;
    }
    if(current-> next == NULL){
        printf("End of playlist.\n");
        return current;
    }
    struct node* ptr = current-> next;
    printf("Now Playing: %s - %s (%d sec)\n", current->title, current->artist, current->duration);
    return current-> next;
    
}



struct node* playPrev(struct node* current){
    if(current == NULL){
        printf("Playlist is empty.\n");
        return NULL;
    }
    if(current-> prev == NULL){
        printf("No song before the current SONG.\n");
    }
    struct node* ptr = current-> prev;
    printf("Now Playing: %s - %s (%d sec)\n", current->title, current->artist, current->duration);
    return current-> prev;
    
}