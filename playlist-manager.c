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
void currentSong(struct node*);
struct node* playNext(struct node*);
struct node* playPrev(struct node* current);
void search(struct node*);
void save(struct node*);
struct node* load();




int main()
{
    int choice;
    struct node* head = load();
    current = head;
    if(current != NULL){
    printf("\n================================\n");
    printf("      WELCOME TO PLAYLIST \n");
    printf("=================================\n");
    printf("\nNow Playing:\n");
    printf("----------------------------------\n");
    printf("Title   : %s\n", current->title);
    printf("Artist  : %s\n", current->artist);
    printf("Duration: %d sec\n", current->duration);
    printf("----------------------------------\n");
    }
    do {
        printf("\n===== MUSIC PLAYLIST MANAGER =====\n");
        printf("==================================\n");
        printf("\n1.Add \n2.Delete \n3.Display \n4.Current \n5.Next \n6.Prev \n7.Search \n8.Exit\n");
        printf("Enter you choice : ");
        scanf("%d", &choice);
        switch(choice) {

            case 1: head = addSong(head); save(head); break;
            case 2: head = deleteSong(head); save(head); break;
            case 3: display(head); break;
            case 4: currentSong(head); break;
            case 5: current = playNext(current); break;
            case 6: current = playPrev(current); break;
            case 7: search(head); break;
            case 8: save(head); exit(0);
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
        printf("\n----------------------------------\n");
        printf("Playlist is empty.\n");
        printf("----------------------------------\n");
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
        printf("----------------------------------\n");
        printf("Song delete successfully\n");
        printf("----------------------------------\n");
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
    printf("----------------------------------\n");
    printf("Song delete successfully\n");
    printf("----------------------------------\n");
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



void currentSong(struct node* head){
    if(current == NULL){
        printf("No song is playing.\n");
        return;
    }
    printf("\nNow Playing:\n");
    printf("----------------------------------\n");
    printf("Title   : %s\n", current-> title);
    printf("Artist  : %s\n", current-> artist);
    printf("Duration: %d sec\n", current-> duration);
    printf("----------------------------------\n");
}


struct node* playNext(struct node* current){
    if(current == NULL){
        printf("PLaylist is empty.\n");
        return NULL;
    }
    if(current-> next == NULL){
        printf("\nNow Playing:\n");
        printf("----------------------------------\n");
        printf("End of playlist.\n");
        printf("----------------------------------\n");
        return current;
    }
    struct node* ptr = current-> next;
    printf("\nNow Playing:\n");
    printf("----------------------------------\n");
    printf("Title   : %s\n", ptr-> title);
    printf("Artist  : %s\n", ptr-> artist);
    printf("Duration: %d sec\n", ptr-> duration);
    printf("----------------------------------\n");
    return current-> next;
    
}






struct node* playPrev(struct node* current){
    if(current == NULL){
        printf("\n----------------------------------\n");
        printf("Playlist is empty.\n");
        printf("----------------------------------\n");
        return NULL;
    }
    if(current->prev == NULL){
        printf("\n----------------------------------\n");
        printf("No previous song.\n");
        printf("----------------------------------\n");
        return current; 
    }
    current = current->prev;
    printf("\nNow Playing:\n");
    printf("----------------------------------\n");
    printf("Title   : %s\n", current-> title);
    printf("Artist  : %s\n", current-> artist);
    printf("Duration: %d sec\n", current-> duration);
    printf("----------------------------------\n");
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





void save(struct node* head){
    FILE *fp = fopen("playlist.txt", "w");
    struct node* ptr = head;
    while(ptr != NULL){
        fprintf(fp, "%s,%s,%d\n", ptr->title, ptr->artist, ptr->duration);
        ptr = ptr->next;
    }
    fclose(fp);
}




struct node* load(){
    FILE *fp = fopen("playlist.txt", "r");
    if(fp == NULL){
        printf("No saved playlist found.\n");
        return NULL;
    }
    struct node *head = NULL, *ptr = NULL;
    char line[150];
    while(fgets(line, sizeof(line), fp)){
        struct node* newSong = malloc(sizeof(struct node));
        if(newSong == NULL){
            printf("Memory allocation failed.\n");
            break;
        }
        if(sscanf(line, "%[^,],%[^,],%d",
                  newSong->title,
                  newSong->artist,
                  &newSong->duration) != 3){
            free(newSong);
            continue;
        }
        newSong->next = NULL;
        newSong->prev = NULL;
        if(head == NULL){
            head = newSong;
            ptr = head;
        } else {
            ptr->next = newSong;
            newSong->prev = ptr;
            ptr = newSong;
        }
    }
    fclose(fp);
    return head;
}