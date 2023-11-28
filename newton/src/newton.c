# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main (int argc, char *argv[]){
 if (argc != 8) {
         printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5> <arg6> <arg7>\n", argv[0]);
         return 1;  
     }
   double a_0=atof(argv[1]); 
   double a_1=atof(argv[2]);
   double a_2=atof(argv[3]);
   double a_3=atof(argv[4]);
   double a_4=atof(argv[5]);
   double a_5=atof(argv[6]);
   double x_0=atof(argv[7]);

   double x = x_0 ;
     int i = 0 ; /* ΤΟ ΒΗΜΑ */


  while ( i < 1000 ) {

      double f_x_ = polionimo( x, a_0, a_1, a_2, a_3, a_4, a_5);
      double par_f= paragogos( x,  a_1, a_2, a_3, a_4, a_5);

       if ( fabs(par_f) == 0 ) {
            printf("nan\n"); /*ΓΙΑ ΟΤΑΝ ΑΠΟΚΛΗΝΕΙ Ο ΑΛΓΟΡΙΘΜΟΣ */
            return 0.0;
    }
      
       double x_n = x ; /* EINAI TO X n */
       x = x - f_x_ / par_f ;/* O TYΠΟΣ NEWTON ΑΠΟ ΟΠΟΥ ΒΡΗΣΚΟΥΜΕ ΤΟ Χ n+1 ΟΠΟΥ ΕΙΝΑΙ ΤΟ Χ*/
        
         if ( fabs (x - x_n) < 1e-6 ) {
           printf("x = %.2lf\n", x);
         return x;
     }

     i++;

  }
  
  printf("incomplete\n"); /* Η ΠΕΡΙΠΤΩΣΗ ΟΠΟΥ ΔΕΝ ΤΕΡΜΑΤΙΖΕΙ ΜΕΤΑ ΑΠΟ 1000 ΕΠΑΝΑΛΗΨΕΙΣ */
    return 0.0;
   

  return 0;

 }

double polionimo(double x, double a_0, double a_1, double a_2, double a_3, double a_4, double a_5) {
 /*ΒΡΗΣΚΕΙ ΤΟ ΠΟΛΥΩΝΥΜΟ ΠΕΜΠΤΟΥ ΒΑΘΜΟΥ ΑΠΟ ΤΟΥΣ ΑΡΙΘΜΟΥΣ ΠΟΥ ΕΙΣΑΓΑΜΕ */
    return a_0 + a_1 * x + a_2 * x * x + a_3 * x * x * x + a_4 * x * x * x * x + a_5 * x * x * x * x * x;
}

double paragogos(double x, double a_1, double a_2, double a_3, double a_4, double a_5) {
  /*ΒΡΗΣΚΕΙ ΤΗΝ ΠΑΡΑΓΩΓΟ ΤΟΥ ΠΟΛΥΩΝΥΜΟΥ ΠΕΜΠΤΟΥ ΒΑΘΜΟΥ */
    return a_1 + 2 * a_2 * x + 3 * a_3 * x * x + 4 * a_4 * x * x * x + 5 * a_5 * x * x * x * x;
}


