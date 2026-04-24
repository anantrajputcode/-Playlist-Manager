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
void search(struct node*);
struct node* save(struct node*);



int main()
{
    int choice;
    struct node* head = NULL;
    current = head;
    do {
        printf("\n===== MUSIC PLAYLIST MANAGER =====\n");
        printf("==================================\n");
        printf("\n1.Add \n2.Delete \n3.Display \n4.Next \n5.Prev \n6.Search \n7.Exit\n");
        printf("Enter you choice : ");
        scanf("%d", &choice);
        switch(choice) {

            case 1: head = addSong(head); save(head); break;
            case 2: head = deleteSong(head); save(head); break;
            case 3: display(head); break;
            case 4: current = playNext(current); break;
            case 5: current = playPrev(current); break;
            case 6: search(head); break;
            case 7: save(head); exit(0);
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
        printf("Playlist is empty.\n");
        return NULL;
    }
    int n;
    printf("Enter the index of song you want to delete: ");
    scanf("%d", &n);
    struct node* ptr = head;
    if(n == 1){
        struct node* temp = head;

        if(head->next == NULL){
            current = NULL;
            free(temp);
            return NULL;
        }
        head = head->next;
        head->prev = NULL;
        if(current == temp)
            current = head;

        free(temp);
        return head;
    }

    for(int i = 1; i < n && ptr != NULL; i++){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Invalid position.\n");
        return head;
    }
    if(ptr == current){
        if(ptr->next != NULL)
            current = ptr->next;
        else
            current = ptr->prev;
    }
    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    free(ptr);
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
    printf("%-3s %-20s %-15s %-10s\n", "No", "Title", "Artist", "Duration");
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
    printf("Now Playing: %s - %s (%d sec)\n", ptr->title, ptr->artist, ptr->duration);
    return current-> next;
    
}



struct node* playPrev(struct node* current){
    if(current == NULL){
        printf("Playlist is empty.\n");
        return NULL;
    }
    if(current->prev == NULL){
        printf("No previous song.\n");
        return current;  // stay on same song
    }
    current = current->prev;
    printf("Now Playing: %s - %s (%d sec)\n",
           current->title, current->artist, current->duration);
    return current;
}

void search(struct node* head){
    int n;
    struct node* ptr = head;
    printf("Enter the seriel number of the song: ");
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        ptr = ptr-> next;
    }
    printf("\n----- PLAYLIST -----\n");
    printf("%-3s %-20s %-15s %-10s\n", "No", "Title", "Artist", "Duration");
    printf("%2d. %-20s | %-15s | %3d sec\n", n, ptr->title, ptr->artist, ptr->duration);
    printf("--------------------\n");
}


struct node* save(struct node* head){
    FILE *fp = fopen("playlist.txt", "w");
    struct node* ptr = head;
    while(ptr != NULL){
        fprintf(fp, "%s,%s,%d\n", ptr->title, ptr->artist, ptr->duration);
        ptr = ptr->next;
    }
    fclose(fp);
}