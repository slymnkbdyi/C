//mutual exclusion with busy waiting
// Peterson's Solutions


#define FALSE 0
#define TRUE 1
#define N 2

int sira;  //kimin sirasi
int ilgili[N]; // ilk degerler FALSE dir.

void kritik_bolgeye_gir(int surec){
      int diger_surec;
      diger_surec = 1 - surec;
      ilgili[surec] = TRUE;
      sira = surec;
      while(sira == surec && ilgili[diger_surec] == TRUE);

}

void kritik_bolgeden_cik(int surec){
      ilgili[surec] = FALSE;
      
}
