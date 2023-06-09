#include <stdio.h>
int main(void){
	// The Interval Search Method starts
	
 	int number;  // Number for which we will find the root
    printf("Enter a number for the Interval Search Method: "); 
    scanf("%d", &number); // Use "scanf" to get the number
	// Define variables
	// variables for the intervals because this method will approach the root using intervals.
    float root1 = 0; // "0" because the first interval will be between "0" and the number we get from the user.
    float root2 = number; 
    float root1square ,root2square ; // to check if the guessed root is within the interval that includes the number
    float difference; // creates the intervals while guessing the root.
    int i; 

    do
    {
        difference = (root2 - root1) / 10; // Divide the interval into 10 parts
        for (i = 0; i < 10; i++) // "for" loop to perform operations in intervals.
        {
            root1 = root1 + (i * difference); 
            root2 = root1 + ((i + 1) * difference);
            root1square = root1 * root1;  
            root2square = root2 * root2;	
            if ((root1square <= number && number <=root2square) && (root2 - root1 < 0.0001 && root2 - root1 >=0.0))//Answer the questions "Is our number within this interval?" and "Do our root guesses give us the desired error rate?"
            {
                printf("%f\n", root2); // If the conditions are ok , print the root
            } 
            else if (root1square <= number && number <= root2square)  // Check the current interval 
            {
                i = 10; // If our number is not within the interval , the new operation begins
                break;
            }
        }
    } while (!(root2 - root1 < 0.0001 && root2 - root1 >= 0)); 

	//Ending Interval Search Method
	
	//Starting Newton-Raphson Method
	
	int number2; // Define the number we will get from the user
	printf("Enter a number for Newton-Raphson Method: ");
	scanf( "%d", &number2 ); // Get number
    
    
	float x = number2;  // Assign number to a "float" type variable.
	
    while (1) { // Start an infinite loop until we reach the desired error rate.
        float x1 = x;  // Assign the value of our "x" variable to our "x1" variable for each loop.
        x = x1 - (x1 * x1 - number2) / (2 * x1); // Apply the formula of the method to find the new value of "x".

        if (x - x1 < 0.0001 && x - x1 > -0.0001) { // If the conditions are ok , the operation finishes
            break;
        }
    }
	
    printf("%f\n", x); // Finally print the root
	
	// Ending Newton-Raphson Method
	
    return 0;
	  
    
}
