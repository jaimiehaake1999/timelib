/*
*Programm welches nach Eingabe des aktuellen Datums berechnet, der wievielte Tag in diesem Jahr es ist.
*Autor:Jaimie Haake
*Datum: 14.01.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"



int main(){
    int day,month,year;
    input_date(&day, &month, &year);
	printf("Es ist der %i Tag im Jahr %i",day_of_the_year(day,month,year),year);
    return 0;
}
