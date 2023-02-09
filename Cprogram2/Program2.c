/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Audrey Pino
 */
#include <stdio.h>

void scoreCombo(int score){
// tdc = TD + 2pt
// tdfg = TD + FG
// td = TD
// fg = 3pt FG
// sa = Safety

int tdc, tdfg, td, fg, sa;
    for (tdc = 0; tdc <= score / 8; tdc++) {
        for (tdfg = 0; tdfg <= score / 7; tdfg++){
            for (td = 0; td <= score / 6; td++){
                for (fg = 0; fg <= score / 3; fg++){
                    for (sa = 0; sa <= score / 2; sa++){
                        if((tdc * 8) + (tdfg * 7) + (td * 6) + (fg * 3) + (sa *2) == score){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tdc, tdfg, td, fg, sa);
                        }
                    }
                }
            }
        }
    }
}

int main(void){
    int score;
    while(1){
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1){
            break;
        }
        scoreCombo(score);
    }
}

