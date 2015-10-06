//producer-consumer problem with semaphore
// operating systems - process&thread

#define TRUE 1
#define FALSE O

typedef int semaphore;

semaphore mutex = 1;  // kritik bolge erisimini kontrol eder

int urun = 0;         // uretici her seferinde 1 arttirir, tuketici
                      // bu degeri yazar
          
void uretici(void){
     while(TRUE){
         down(&mutex);
             urun = urun + 1;
         up(&mutex);
     }
}


void tuketici(void){
     while(TRUE){
	 down(&mutex);
	     printf("%d\n,urun);
	 up(&mutex);
     }      	


}
