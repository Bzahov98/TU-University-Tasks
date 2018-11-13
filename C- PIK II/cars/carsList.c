#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char name[20];
	char model[20];
	double price;
} Accessories;

typedef struct ListAcces accList;
struct ListAcces{
	Accessories *accessories;
	ListAcces* next;
};

typedef struct {
	char mark[20];
	char model[20];
	double price;
	ListAcces *listAcces;
} Car;



/*struct ListCar{
	Car *Car;
	ListCar* next;
} ;
*/
Car* makeCar(char mark[20],char model[20],double price){

	Car *car = (Car*) malloc(sizeof(Car));
	if (car == NULL) {
		exit(1);
		//return *car;
	}
	strcpy( car->mark, mark);
	strcpy( car->model, model);
	car->price = price;
	return car;
}

Accessories* makeAccess(char name[20],char model[20],double price){

	Accessories *acc = (Accessories*) malloc(sizeof(Accessories));
	if (acc == NULL) {
		exit(1);
		//return *car;
	}
	strcpy( acc->name, name);
	strcpy( acc->model, model);
	acc->price = price;

	return acc;
}


/*Accessories makeAccess(){

	return
}*/
int main(){

	Accessories *acc= makeAccess("fff","4",1000.1);
	Car *car= makeCar("sda","4",1000.1);

	//Accessories acces = makeAccess();
	return 0;
}
