
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Note { char data[56]; void (*action)(void); } Note;
Note *stale = NULL;

void safe_action(void){ puts("Note action: nothing unusual."); }
void win(void){
    puts("=== MAINTENANCE CONSOLE ===");
    puts("Access granted.");
    puts("CYBERWOLF{use_after_free_reclaimed}");
}
void create_note(void){
    Note *n=malloc(sizeof(Note)); if(!n) exit(1);
    n->action=safe_action;
    printf("Enter note: "); fflush(stdout);
    fgets(n->data,sizeof(n->data),stdin);
    n->data[strcspn(n->data,"\n")]=0;
    stale=n; puts("Note saved.");
}
void delete_note(void){
    if(!stale){puts("No note.");return;}
    free(stale); puts("Note deleted.");
    /* BUG: stale is intentionally not cleared. */
}
void edit_note(void){
    if(!stale){puts("No note.");return;}
    printf("Edit note: "); fflush(stdout);
    fgets(stale->data,sizeof(stale->data),stdin);
    stale->data[strcspn(stale->data,"\n")]=0;
    puts("Note updated.");
}
void view_note(void){
    if(!stale){puts("No note.");return;}
    printf("Note: %s\n",stale->data);
}
void run_action(void){
    if(!stale){puts("No note.");return;}
    stale->action();
}
int main(void){
    setvbuf(stdout,NULL,_IONBF,0);
    puts("=== CyberWolf Note Manager ===");
    puts("Commands: create, delete, edit, view, run, exit");
    char cmd[16];
    while(1){
        printf("> "); if(!fgets(cmd,sizeof(cmd),stdin))break;
        cmd[strcspn(cmd,"\n")]=0;
        if(!strcmp(cmd,"create"))create_note();
        else if(!strcmp(cmd,"delete"))delete_note();
        else if(!strcmp(cmd,"edit"))edit_note();
        else if(!strcmp(cmd,"view"))view_note();
        else if(!strcmp(cmd,"run"))run_action();
        else if(!strcmp(cmd,"exit"))break;
        else puts("Unknown command.");
    }
}
