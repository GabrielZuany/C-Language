#include <stdio.h>

typedef struct{
    int ID;
    int Party;
    char model[100];
    int Kilometers;
}tCar;

typedef struct{
    tCar cars[100];
}tDealership;

tCar ReadCar(void);
void PrintCar(tCar car);
int GetParty(tCar car);
int GetKilometers(tCar car);

tDealership ReadDealershipCars(void);
void ListDealershipCars(tDealership dealership, int party, int kilometers);



//----------MAIN---------------
int main(){ 
    tDealership dealership; 

    dealership = ReadDealershipCars();

    int party, kilometers, i = 0;
    while(scanf("%d,%d", &party, &kilometers) == 2){
        printf("Caso %d:\n", ++i);
        ListDealershipCars(dealership, party, kilometers);
    }

    return 0;  
}

//--------------FUNCTIONS-------------

tCar ReadCar(){
    tCar car;
    scanf("%d %d %s %d", &car.ID, &car.Party, car.model, &car.Kilometers);
    return car;
}

void PrintCar(tCar car){
    if(car.ID!=0 && car.Party!=0 && car.Kilometers!=0){
       printf("CARRO (%d): %s de %d passageiros e com %d km\n", car.ID, car.model, car.Party, car.Kilometers); 
    }
}

int GetParty(tCar car){
    return car.Party;
}

int GetKilometers(tCar car){
    return car.Kilometers;
}

tDealership ReadDealershipCars(){
    int Quantity, i = 0;
    scanf("%d", &Quantity);

    tDealership dealership;
    while(i < Quantity){
        dealership.cars[i] = ReadCar();
        i++;
    }
    return dealership;
}

void ListDealershipCars(tDealership dealership, int party, int kilometers){
    int i = 0;
    while(i<100){

        if(party==-1 && kilometers==-1){
            PrintCar(dealership.cars[i]);
            i++;
            continue;
        }

        if(party==-1){
            if(GetKilometers(dealership.cars[i])<=kilometers){
                PrintCar(dealership.cars[i]);
            }
        }else if(kilometers==-1){
            if(GetParty(dealership.cars[i])==party){
                PrintCar(dealership.cars[i]);
            }
        }else{
            if(GetParty(dealership.cars[i])==party && GetKilometers(dealership.cars[i])<=kilometers){
                PrintCar(dealership.cars[i]);
            }
        }  

        i++;
    }
    
}