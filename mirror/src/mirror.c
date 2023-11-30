# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

int main (int argc, char *argv[]) {
  if (argc != 3) {
         printf("Usage: %s low high \n", argv[0]); 
         return 1;
  }
long long int  low = atoll(argv[1]);  /*μπορει να χριαστει να το αλλαξω σε atoi παλι*/
long long int  high = atoll(argv[2]);  /*μπορει να χριαστει να το αλλαξω σε atoi παλι*/

int palidromiki(int x);
int prvtoi( int x);

     
     if ( low > high  || low < 1 || high > 1000000000000000 ){
        return 1;
     }
      long long int  sum = 0  ;
      long long int  x ;
    for ( x=low ; x<=high ; x++) {  /*mexri edv */
  
        if  (palidromiki(x)){
              long long int  mirror_number ;
              long long int number = x ;
            while ( number>0 ) {
             mirror_number =  mirror_number * 10 + number % 10;
             number = number / 10;
          if ( prvtoi(mirror_number)){
             if(prvtoi(x)){
              sum=sum+x;
            } 
          }
            }
            
        }
        
    }
       printf("%lld\n",sum ) ;
       return 0 ;
}


int palidromiki (int x ){ /* ΑΥΤΗ Η ΣΥΝΑΡΤΗΣΗ ΒΡΗΣΚΕΙ ΠΟΤΕ Ο ΑΡΙΘΜΟΣ ΔΕΝ ΕΙΝΑΙ ΠΑΛΙΔΡΟΜΙΚΟΣ*/
    int n =x ;
    int len = 0;
    while (n != 0) {
        n = n / 10;
        ++ len ;  /* ΕΙΝΑΙ Ο ΑΡΙΘΜΟΣ ΤΩΝ ΣΤΟΙΧΕΙΩΝ ΕΝΩΣ ΑΡΙΘΜΟΥ  */
    }if (len==1){
      return 0 ;  
    }else if (len % 2 ==0) {
           int k = x ;
           int i ;
         for (i=1; i<=len/2 ; i++){       
           if (k/pow(10,len-i)!=k%(int)pow(10,i)){
              return 1 ;
             }else{
              k=k %(int)pow(10,len-1);
             }
          
        }
    }else{
         int k = x ;
         int i ;
        for (i=1; i<=(len-1)/2 ; i++){
        
          if (k/(int)pow(10,len-i)!=k%(int)pow(10,i)){ 
            return 1 ;
           }else{ 
            k=k%(int)pow(10,len-1);
            }
           } 
    } 
    return 0 ;  /*ΜΠΟΡΕΙ ΝΑ ΧΡΙΑΣΤΕΙ ΝΑ ΑΛΛΑΞΩ ΚΑΙ ΑΥΤΟ ΤΟ 0 ΣΕ 1 */ 
}

int prvtoi(int x ){
    double tetr_riza = sqrt(x);
     if (tetr_riza == (int)tetr_riza ) {
                    int n = (int)tetr_riza ;
                    int i ;                                      
                 for  ( i=2 ; i <= n/2 ; i++ ) {
                    if ( n % i == 0)  {                        
                        return 0 ;
                    }
                  } 
                  return 1;  
         }
         return 0 ;
}
