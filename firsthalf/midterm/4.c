
/**** IMPORTANT: Do NOT include any headers.    	   ****/
/**** OJ will automatically include <stdio.h> for you. ****/
/**** No function in <math.h> is allowed.	 		   ****/

int numOfFactors(int n);

/**** IMPORTANT: Do NOT scan or print anything.        ****/
/**** IMPORTANT: Do NOT write the main function.       ****/
/**** A main function will be automatically generated. ****/

int numOfFactors(int n) {

  // YOUR CODE GOES HERE
    int c = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            c++;
        }
    }
    return c;
}
