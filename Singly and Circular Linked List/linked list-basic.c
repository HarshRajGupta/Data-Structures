#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

int main(void)
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	struct node* fourth = NULL;
	struct node* end = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node));
	end = (struct node*)malloc(sizeof(struct node));

	printf("1st number : ");
	scanf("%d", &head->data);
	head->next = second;

	printf("2nd number : ");
	scanf("%d", &second->data);
	second->next = third;

	printf("3rd number : ");
	scanf("%d", &third->data);
	third->next = fourth;

	printf("4th number : ");
	scanf("%d", &fourth->data);
	fourth->next = end;

	printf("5th number : ");
	scanf("%d", &end->data);
	end->next = NULL;


	struct node* print = head;
	printf("\n====================================\n");
	while (print != NULL)
	{
		printf("%d ", print->data );
		print = print->next;
	}
	printf("\n====================================\n");

	return 0;
}