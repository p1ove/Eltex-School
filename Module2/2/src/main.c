#include "main.h"


void clear(){
    printf ("\033[0d\033[2J");
}

void menu(int* option, contact* book, int* person_id ){
        clear();
        if(*option>4 || *option<0){
            printf("***\n");
            printf("Please choose right option\n");
            printf("***\n");
        }
        printf("Select an action\n");
        printf("1: Add contact\n");
        printf("2: Edit contact\n");
        printf("3: Delete contact\n");
        printf("4: Exit\n");

        scanf("%d",option);
        option_action(*option,book,person_id);
}

void option_action(int opt, contact* book, int* person_id){

switch (opt)
{
case 1:
    add(book,person_id);
    break;
case 2:
    edit(book,*person_id);
    break;
case 3:
    delete(book,*person_id);
    break;
case 4:
    break;
default:
    break;
}
}

void add(contact* book,int* pid){
    int choice = 0;
clear();
    printf("Write name\n");
    scanf("%s",book[*pid].name);
    printf("Do you want to continue?\n");
    printf("1-YES\n");
scanf("%d",&choice);
if(choice == 1){
    printf("Write work\n");
    scanf("%s",book[*pid].work);
    printf("Write phone numbers\n");
    scanf("%s",book[*pid].phone_numbers);
    printf("Write email\n");
    scanf("%s",book[*pid].email);
    printf("Write links\n");
    scanf("%s",book[*pid].links);
}
*pid++;
}

void edit(contact* book,int pid){
    char name[30];
    int err = 1;
    while(err){
clear();
    if(err==2){
        printf("Incorrect person name\n");
    }
    printf("Write person name\n");
    scanf("%s",name);
    for(int i = 0; i<=pid ;i++){
        if (strcmp(name, book[i].name)!=0){}
        else{
            err = 0;
            add(book,&i);
            break;
        }
        err = 2;
        }
    }
}

void delete(contact* book,int pid){
 char name[30];
    int err = 1;
    while(err){
clear();
    if(err==2){
        printf("Incorrect person name\n");
    }
    printf("Write person name\n");
    scanf("%s",name);
    for(int i = 0; i<=pid ;i++){
        if (strcmp(name, book[i].name)!=0){}
        else{
            err = 0;
            *book[i].name='\0';
            *book[i].email='\0';
            *book[i].links='\0';
            *book[i].phone_numbers='\0';
            *book[i].work='\0';
            break;
        }
        err = 2;
        }
    }
}

int main(){
    contact book[100]={0};
    int option = 0;
    int person_id = 0;
while(option!=4){
    menu(&option,book,&person_id);
}
    return 0;
}