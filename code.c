#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct book{
    char *name;
    char *author;
    int id;
    int pages;
    struct book* left;
    struct book* right;
};


struct student{
    char name[100];
    int roll_No;
    int book_id;
    struct student* left;
    struct student* right;
};


void greetings();

void display(struct book* root);

void display_student(struct student* root);

void insert(int id,struct book* root,char* bname,char* ath,int page);

void insert_student(int id,struct student* root,char* sname,int roll);

struct book* createBook(char* book_name,char* ath,int id,int page);

struct student* createStudentNode(char* name,int roll,int id);

void issue_book();

void return_book();

void delete_student();

struct student* minValueNode(struct student* node);

struct student* deleteNode(struct student* root, int roll);

void lib();

int i = 1;

int flag = 1;

struct student* start=NULL;

struct book* begin=NULL;

int a[100000];

int gt = 1;

int main(){
    int ch;
    lib();
    start = createStudentNode("Student Record",50,-1);
    while(1){
        if(gt){
            printf("\n\t\t\t*****************************************************\n");
            printf("\n\t\t\t\tWelcome to Library Management System               \t\t\t\n");
            printf("\n\t\t\t\tManaged by Nirma Students:                         \t\t\t\n");
            printf("\n\t\t\t\t  (1)21BCE090                                      \t\t\t\n");
            printf("\n\t\t\t\t  (2)21BCE091                                      \t\t\t\n");
            printf("\n\t\t\t\t  (2)21BCE092                                      \t\t\t\n");
            printf("\n\t\t\t*****************************************************\n");
            gt = 0;
        }
        printf("\n\t\t\t-----------------------------------------------------\n");
        printf("\n\t\t\t\t\t\tMain Menu\n\n");
        printf("\t\t\t(1)view all the books in the library\n\n");
        printf("\t\t\t(2)issue the book from library\n\n");
        printf("\t\t\t(3)return the book to the library\n\n");
        printf("\t\t\t(4)display all the students who have issued the book\n\n");
        printf("\t\t\t(5)Remove existing book from the library\n\n");
        printf("\t\t\t(6)Exit\n\n");
        printf("\t\t\t-----------------------------------------------------\n");
        printf("\n\t\t\tenter your choice: ");
        scanf("%d",&ch);
        fflush(stdin);
        if(ch==1){
            printf("\t\t\tAvailable Books\t\t\t\n");
            display(begin);
            i=1;
        }
        else if(ch==2){
            
            display(begin);
            i=1;
            issue_book();
        }
        else if(ch==3){
            return_book();
        }
        else if(ch==4){
            display_student(start);
        }
        else if(ch==5){
            display(begin);
            i=1;
            printf("enter the id of the book you want to remove from the record displayed above: ");
            int id;
            scanf("%d",&id);
            a[id]=1;
            struct book* tmp = begin;
            while(tmp!=NULL){
                if(tmp->id == id){
                    break;
                }
                else if(id < tmp->id){
                    tmp = tmp->left;
                }
                else {
                    tmp = tmp->right;
                }
            }
            printf("%s is removed from the library..\n",tmp->name);
            printf("if you want to see updated library then press 1");
            int p;
            scanf("%d",&p);
            if(p==1){
                display(begin);
            }
        }
        else if(ch==6){
            printf("Exiting library...");
            break;
        }
        else{
            printf("Please enter a Valid Choice...");
        }
    }

    return 0;
}



void insert(int id,struct book* root,char* bname,char* ath,int page){
    struct book* prev = NULL;
    struct book* new = createBook(bname,ath,id,page);
    struct book* tmp = root;
    while(tmp!=NULL){
        prev = tmp;
        if(id==tmp->id){
            return;
        }
        else if(id < tmp->id){
            tmp = tmp->left;
        }
        else{
            tmp = tmp->right;
        }
    }
    if(id<prev->id){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}


void insert_student(int id,struct student* root,char* sname,int roll){
    struct student* prev = NULL;
    struct student* new = createStudentNode(sname,roll,id);
    struct student* tmp = root;
    while(tmp!=NULL){
        prev = tmp;
        if(roll==tmp->roll_No){
            return;
        }
        else if(roll < tmp->roll_No){
            tmp = tmp->left;
        }
        else{
            tmp = tmp->right;
        }
    }
    if(roll < prev->roll_No){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}



struct book* createBook(char* book_name,char* ath,int id,int page){
    struct book* new = (struct book*)malloc(sizeof(struct book));
    new->name = (char*)malloc(100*sizeof(char));
    new->author = (char*)malloc(100*sizeof(char));
    strcpy(new->name,book_name);
    strcpy(new->author,ath);
    new->id = id;
    new->pages = page;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct student* createStudentNode(char* name,int roll,int id){
    struct student* new = (struct student*)malloc(sizeof(struct student));
    strcpy(new->name,name);
    new->roll_No = roll;
    new->book_id = id;
    // new->pages = page;
    new->left = NULL;
    new->right = NULL;
    return new;
}


void display(struct book* nd){
    if(nd==NULL)return;

    if(a[nd->id]==0){
        printf("\n\t(%d)Book name:  %s",i++,nd->name);
        printf("   Author name: %s",nd->author);
        printf("   Book id: %d\n",nd->id);
    }
    display(nd->left);
    display(nd->right);
}


void display_student(struct student* st){
    if(st==NULL)return;
    if(st->roll_No!=50){
        printf("\n(%d)Student name:  %s",i++,st->name);
        printf("   Roll Number: %d",st->roll_No);
        printf("   issued Book id: %d\n",st->book_id);        
    }
    display_student(st->left);
    display_student(st->right); 
}


void lib(){
    begin = createBook("Rich Dad Poor Dad","Robert Kiyosaki",50,300);
    insert(40,begin,"The Secret","Rhonda Byrne",300);
    insert(48,begin,"Eat that frog","Brian Tracy",300);
    insert(49,begin,"Made to stick","Dan Heath",300);
    insert(55,begin,"Essentialism","Greg McKeown",300);
    insert(56,begin,"The E-Myth Revisited","Michael E. Gerber",300);
    insert(60,begin,"Awaken the giant within","Anthony Robbins",300);
    insert(65,begin,"How to win friends","Dale Carnegie",300);
    insert(68,begin,"The power of now","Eckhart Tolle",300);
    insert(44,begin,"Atomic Habits","James Clear",300);
    insert(43,begin,"Beyond Mars and Venus","John gray",300);
    insert(39,begin,"Can't hurt me","David Goggins",300);
    insert(45,begin,"Get out of your own way","Dr. Mark Goulston",300);
    insert(58,begin,"The man in the mirror","Patrick M morly",300);
    insert(59,begin,"The power of Habit","Charles Duhigg",300);
    insert(62,begin,"The four Agreement","Don Miguel Ruiz",300);
    insert(70,begin,"The power of Imperfaction","Brene Brown",300);
    insert(69,begin,"Deep Work: Rules for Focused Success","Cal Newport",300);
    insert(66,begin,"Thinking, Fast and Slow","Daniel Kahneman",300);

}



void issue_book(){
    
    printf("\t\tenter the id of the book displayed below: ");
    lib();
    //display(begin);
    int x;
    scanf("%d",&x);
    if(a[x]==1){
        printf("Book with this id is not available currently..");
        printf("Please come again later...");
        return;
    }
    
    a[x]=1;
    printf("\n");
    // display(begin);
    int y;
    printf("\t\t\tenter your roll No: ");
    scanf("%d",&y);
    char s1[100],s2[100];
    printf("\t\t\tenter your name: ");
    scanf("%s %s",s1,s2);
    strcat(s1," ");
    strcat(s1,s2);
    insert_student(x,start,s1,y);
    printf("\n\n\t\t\tDetails of Issued book\n");
    struct book* tmp = begin;
    
    while(tmp!=NULL){
        if(tmp->id == x){
            break;
        }
        else if(tmp->id > x){
            tmp = tmp->left;
        }
        else{
            tmp = tmp->right;
        }
    }
    
    if(tmp==NULL){
        printf("\n\t\t\tBook with this id does not exist....\n");
        return;
    }
    
    printf("\t\t\tStudent's Name: %s\n\n",s1);
    printf("\t\t\tStudent's roll No: %d\n\n",y);
    printf("\t\t\tissued book : %s by %s\n\n",tmp->name,tmp->author);
    printf("\t\t\tbook %s is successfully issued to %s\n\n",tmp->name,s1);
    printf("\t\t\tPlease return the book as soon as possible\n\n");
}



void return_book(){
    int x;
    printf("enter your roll No: ");
    scanf("%d",&x);
    struct student* tmp = start;
    while(tmp!=NULL){
        if(tmp->roll_No==x){
            break;
        }
        else if(x<tmp->roll_No){
            tmp = tmp->left;
        }
        else{
            tmp = tmp->right;
        }
    }
    if(tmp==NULL){
        printf("\t\t\tThis Roll number does not exist in Record...");
        return;
    }
    struct book* temp = begin;
    while(temp!=NULL){
        if(temp->id == tmp->book_id){
            break;
        }
        else if(temp->id > tmp->book_id){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    a[tmp->book_id] = 0;
    printf("\n\t\t\t-----------------------------------------------------\n\n");
    printf("\t\t\tissued book details \n");
    printf("\t\t\tissued book: %s by %s\n\n",temp->name,temp->author);
    printf("\t\t\tissued to %s\n\n",tmp->name);
    printf("\t\t\tThe book has been successfully returned...\n\n");
    printf("\n\t\t\t-----------------------------------------------------\n\n");
    // display_student(start);
    deleteNode(start,x);
    display_student(start);
    i=1;
}



struct student* minValueNode(struct student* node){
    struct student* current = node;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

struct student* deleteNode(struct student* root, int roll){
    if(root==NULL){
        return root;
    }
    if(roll < root->roll_No){
        root->left = deleteNode(root->left,roll);
    }
    else if(roll > root->roll_No){
        root->right = deleteNode(root->right,roll);
    }
    else{
        if(root->left == NULL){
            struct student* tmp = root->right;
            return tmp;
        }
        else if(root->right == NULL){
            struct student* tmp = root->left;
            return tmp;
        }
        struct student* tmp = minValueNode(root->right);
        root->roll_No = tmp->roll_No;
        root->right = deleteNode(root->right,tmp->roll_No);
    }
    return root;
}






