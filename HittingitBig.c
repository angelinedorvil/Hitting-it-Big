#include <stdio.h>
#include <stdlib.h>

/* 
Student: [Angeline Dorvil] 
Date: [11/5/2023]
Features: [Creating loops and recursion for dice game]
Bugs: [N/A]
 */

int payoff (int R1, int R2, int R3);
void loopR1 (int minVal, int maxVal);
void loopR2(int minVal, int maxVal, int R1);
void loopR3(int minVal, int maxVal, int R2, int R1);
    
int main() {

    printf("Welcome to M3PA\n");
    printf("\n");

    int R1 = 0; //3 dices roll
    int R2 = 0;
    int R3 = 0;

    // No more user input, loops for each variable values
    //step 1 requirements
    printf("Step #1-Feature payoff distribution\n");
    printf("\n");
    
    for (R1 = 1; R1 <= 3; R1++){
    	for (R2 = 1; R2 <= 3; R2++) {
            for (R3 = 1; R3 <= 3; R3++) {
           	int totalPay = 0; // Initialize totalPay
    		if (R2 > R1 && R3 > R1) {
    			totalPay = R1;
    		} else {
    			totalPay = R1; // Initialize totalPay with R1
    			if (R2 < R1) {
        			totalPay += R2;
        			if (R3 < R2) {
            				totalPay += (2 * R3);
        			} else if (R3 < R1) {
            				totalPay += R3;
        			}
    			} else if (R3 < R1) {
        			totalPay += R3;
    			}
    		}
            	printf("%d %d %d payoff is %d\n", R1, R2, R3, totalPay);
            }
        }
    }
    
    printf("\n");
    
    //step 2 requirements
    printf("Step #2-Refactoring, F(R1, R2, R3)\n");    
    printf("\n");
    
    for (R1 = 1; R1 <= 3; R1++){
    	for (R2 = 1; R2 <= 3; R2++) {
            for (R3 = 1; R3 <= 3; R3++) {
           	int rollPay = payoff(R1, R2, R3);
            	printf("%d %d %d payoff is %d\n", R1, R2, R3, rollPay);
            }
        }
    }
    
    printf("\n");
    
    // step 3 requirements
    printf("Step #3-Refactoring, Recursive Functions vs. Loops\n");    
    printf("\n");
        
    loopR1(1,3);

    printf("\n");
    printf("All Done!\n");
    exit(EXIT_SUCCESS);
}


// Function to calculate the payoff for a given combination of R1, R2, and R3
    
int payoff (int R1, int R2, int R3){
    int totalPay = 0; // Initialize totalPay
    if (R2 > R1 && R3 > R1) {
    	totalPay = R1;
    	return totalPay;
    } else {
    	totalPay = R1; // Initialize totalPay with R1
    	if (R2 < R1) {
        	totalPay += R2;
        	if (R3 < R2) {
            		totalPay += (2 * R3);
            		return totalPay;
        	} else if (R3 < R1) {
            		totalPay += R3;
            		return totalPay;
        	}
    	} else if (R3 < R1) {
        	totalPay += R3;
            	return totalPay;
    	}
    }
}    

// Recursive function for looping over R values from R1 to R3
    
void loopR1 (int minVal, int maxVal){
    if (minVal > maxVal){
    	return;
    } else {
      	loopR2(1,3,minVal);
      	loopR3(1, 3, minVal, minVal);
    	loopR1(minVal+1, maxVal);
      }   
}


void loopR2(int minVal, int maxVal, int R1) {
    int R3 = 0;

    if (minVal > maxVal) {
        return;
    } else {
            for (R3 = 1; R3 <= 3; R3++) {
                int rollPay = payoff(R1, minVal, R3);
                printf("%d %d %d payoff is %d\n", R1, minVal, R3, rollPay);
            }
            loopR2(minVal + 1, maxVal, R1);
      }
}
 

void loopR3(int minVal, int maxVal, int R2, int R1) {
    if (minVal > maxVal) {
        return;
    } else {
      	int rollPay = payoff(R1, R2, minVal);
      	printf("%d %d %d payoff is %d\n", R1, R2, minVal, rollPay);  
        loopR3(minVal + 1, maxVal, R1, R2);
      }
}    
