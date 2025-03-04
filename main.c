#include <stdio.h>
#include "item.h"
#include <stdlib.h>
#include <string.h>


void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{

	item_list[index].price = price;
	item_list[index].sku = (char *)malloc(strlen(sku) +1);
	item_list[index].category = (char *)malloc(strlen(category) +1);
	item_list[index].name = (char *)malloc(strlen(name) +1);
	strcpy(item_list[index].sku, sku);
	strcpy(item_list[index].category, category);
	strcpy(item_list[index].name, name);

}

void free_items(Item *item_list, int size)
{
	for (int i = 0; i < size; i++) {
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);
}

double average_price(Item *item_list, int size)
{

	float total = 0;
	for(int i = 0; i < size; i++) {
		total += item_list[i].price;
	}
	return total/size;
}

void print_items(Item *item_list, int size){
	printf("###############\n");
	for(int i = 0; i < size; i++) {
		printf("item name = %s\n", item_list[i].name);
		printf("item sku = %s\n", item_list[i].sku);
		printf("item category = %s\n", item_list[i].category);
		printf("item price = %f\n", item_list[i].price);
		printf("###############\n");
	}
}



int main(int argc, char *argv[])
{
	int size = 5;
	Item *item_list = (Item *) malloc(sizeof(Item)*size);
	add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
	add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
	add_item(item_list, 1.00, "58492", "beverage", "water", 2);
	add_item(item_list, 3.00, "48933", "dairy", "yogurt", 3);
	add_item(item_list, 2.00, "84823", "snack", "cookie", 4);

	print_items(item_list, size);
	printf("average price of items = %f\n", average_price(item_list, 5)); 
	
	char *sku = argv[1];
	int ct = 0;
	while (ct < size && strcmp(item_list[ct].sku, sku) != 0) {
		ct++;
	}
	
	if (ct < size) 
	{
		printf("\n\nItem found:\n");
		printf("###############\n");
		printf("item name = %s\n", item_list[ct].name);
		printf("item sku = %s\n", item_list[ct].sku);
		printf("item category = %s\n", item_list[ct].category);
		printf("item price = %.6f\n", item_list[ct].price);
		printf("###############\n");
	}
	else {
		printf("Item not found.\n");
		}
	free_items(item_list, size);

	return 0;
}

