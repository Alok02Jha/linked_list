// This program is to implement of linked_list in C
// Just add new data & see the list

#include<stdio.h>
#include<stdlib.h>

// prototype declaration
void show_list();
void add_element(int);
void del_element(int);
void del_all_element(int);

struct node{
	int data;
	struct node *link;
};

struct node *head;

void main(){

	int choice;
	int data;

	do{
		printf("\n\n\t***LINKED LIST APPLICATION***\n1.Show List\n2.Add element\n3.Delete 1st element\n4.Delete all element\n 0.Exit\n\nEnter choice : ");
		scanf("%d",&choice);

		switch(choice){

			case 1:
				system("clear");
				printf("The data in the list are as follow : \n");
				show_list();
				break;
			case 2:
				system("clear");
				printf("Enter data to add : ");
				scanf("%d",&data);
				add_element(data);
				break;
			case 3:
				system("clear");
				printf("Enter data to delete : ");
				scanf("%d",&data);
				del_element(data);
				break;
			case 4:
				system("clear");
				printf("Enter data to delete all presence : ");
				scanf("%d",&data);
				del_all_element(data);
				break;
			case 0:
				printf("\n...Good bye...\n");
				break;
			default:
				printf("Please enter a valid option...\n");

		}
	}while(choice != 0);
}


void show_list(){
	struct node *t;
	t = head;
	while(t){
		printf("%d\n",t->data);
		t = t->link;
	}
	printf("\n\n");
}

void add_element(int i){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = i;
	new->link = NULL;
	if(head){
		struct node *t;
		t = head;
		while(t->link){
			t = t->link;
		}
		t->link = new;
	}else{
		head = new;
	}
}

void del_element(int j){
	struct node *t;
	t = head;
	int status = 0;
	if(t->data == j){
		head = t->link;
		status = 1;
		free(t);
	}else{
		while(t){
			if(t->link->data == j){
				t->link = t->link->link;
				status = 1;
				break;
			}
			t = t->link;
		}
		if(status){
			printf("'%d' deleted\n",j);
		}else{
			printf("'%d' not present in the list\n",j);
		}
	}
}

void del_all_element(int j){
	struct node *t;
	t = head;
	int status = 0;

	if(t->data == j){
		head = t->link;
		status = 1;
	}
	while(t){
		if(t->link && t->link->link){
			if(t->link->data == j){
				t->link = t->link->link;
				status = 1;
			}
		}
		t = t->link;
	}
	if(status){
		printf("All '%d' deleted\n",j);
	}else{
		printf("'%d' not present in the list\n",j);
	}
	
}