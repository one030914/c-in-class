
/**** IMPORTANT: Do NOT include any headers.    	   ****/
/**** OJ will automatically include <stdio.h> for you. ****/
/**** Note that <math.h> will NOT be included. 		   ****/

// Please complete the function declaration
float cRound(float src, unsigned int prcs);

/**** IMPORTANT: Do NOT scan or print anything. ****/
/**** IMPORTANT: Do NOT write main function. 	****/
/**** A main function will be automatically generated to test your `numOfFactors` function. ****/

// Please complete the function definition
float cRound(float src, unsigned int prcs) {
    int p = 1;
    for(int i = 0; i < prcs; i++){
        p *= 10;
    }
    if((float)(src * p) % 10 <= 4){
        return src;
    }else if((float)(src * p) % 10 >= 5){
        return src + 1;
    }
}
