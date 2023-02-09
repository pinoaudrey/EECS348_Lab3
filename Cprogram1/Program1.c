/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Audrey Pino
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void monthName(int monthNum){
	char *months[] = {"January", "February", "March", "April", "May", "June",
	                      "July", "August", "September", "October", "November", "December"};
	printf("  %-12s", months[monthNum]);
}

void salesReport(float monthReport[], int length){
    printf("  Month       Sales\n");
    for(int i = 0; i < length; ++i){
        monthName(i);
        printf("$%.2f\n", monthReport[i]);
    }
}

void salesSummary(float monthReport[], int length){
    float minimum = monthReport[0];
    int minimumIndex = 0;
    float maximum = monthReport[0];
    int maximumIndex = 0;
    float total = 0;

    for(int i = 1; i < length; ++i){
        if(monthReport[i] < minimum){
            minimum = monthReport[i];
            minimumIndex = i;
        }
        if(monthReport[i] > maximum){
            maximum = monthReport[i];
            maximumIndex = i;
        }
        total += monthReport[i];
    }

    float average = total / length;

    printf("Minimum sale:  $%.2f (", minimum);
    monthName(minimumIndex);
    printf(")\n");
    printf("Maximum sale:  $%.2f (", maximum);
    monthName(maximumIndex);
    printf(")\n");
    printf("Average sale:  $%.2f\n", average);
}

void sixMonthMovingAverage(float monthReport[], int length){
    float sum = 0.0;
    printf("  Month       Sales\n");
    for(int i = 0; i < length; ++i){
        monthName(i);
        for(int j = i; j < i + 6 && j < length; ++j){
            sum += monthReport[j];
        }
        printf("$%.2f\n", sum/6);
        sum = 0.0;
    }
}
void salesReportHighToLow(float monthReport[], int length){
    float sortedSales[12];
    int monthNum[12];
    for(int i = 0; i < length; ++i){
        sortedSales[i] = monthReport[i];
        monthNum[i] = i;
    }
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(sortedSales[i] < sortedSales[j]){
                float temp = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = temp;
                int tempNum = monthNum[i];
                monthNum[i] = monthNum[j];
                monthNum[j] = tempNum;
            }
        }
    }
    printf("  Month       Sales\n");
    for(int i = 0; i < length; ++i){
        monthName(monthNum[i]);
        printf("$%.2f\n", sortedSales[i]);
    }
}

int main(){
    FILE* myFile;
    myFile = fopen("input.txt", "r");
    if (myFile == NULL){
        printf("Unable to open file\n");
        return 1;
    }

    float sales[12] = {0};

    for(int i = 0; i < 12; i++){
        fscanf(myFile, "%f", &sales[i]);
    }

    printf("\nMonthly sales report for 2022:\n\n");
    salesReport(sales, 12);
    printf("\nSales Summary:\n\n");
    salesSummary(sales, 12);
    printf("\nSix-Month Moving Average Report:\n\n");
    sixMonthMovingAverage(sales, 12);
    printf("\nSales Report (Highest to Lowest):\n\n");
    salesReportHighToLow(sales,12);
    fclose(myFile);
    return 0;
}


