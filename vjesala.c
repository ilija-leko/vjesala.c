#include <stdio.h>
#include <string.h>
/* Created by: Ilija Leko */
void igra (char *unos, char *rijec);
void pocetak (char *unos, char *rijec);
int zapis (char *unos, char *rijec);

int main(void) {
  char unos[50];
  char rijec[50];
  /*Zadavanje riječi.*/
  printf("Unesite riječ: ");
  scanf("%s", unos);
  /*Pokretanje igre*/
  igra(unos, rijec);
  return 0;
}

void igra (char *unos, char *rijec){
  /*IGRA VJEŠALA, BROJ POKUŠAJA = 5*/
  int i,j;
  pocetak(unos, rijec);
  for(i=5;i>0;i--){
    printf("Rijec: %s\n",rijec);
    printf("Preostalo je %d pokusaja.\n", i);
    if(zapis(unos,rijec)==0) break;
    if(i==1){
      printf("Niste pogodili :(");
      break;
    }
  }
}

int zapis (char *unos, char *rijec){
  char unos2[50];
  int i,j;
  int k,n,c;
  k=n=c=0;
  /*Unos slova ili cijele riječi*/
  printf("Unesite slovo ili cijelu rijec: ");
  scanf("%s", unos2);
  /*PROVJERA: Je li unesena riječ riješenje?*/
  if (strcmp(unos2, unos)==0){
    printf("Pogodili ste!");
    return 0;
  }
  /*Zapis unešenog slova, ako se nalazi u zadanoj riječi.*/
  else if (strlen(unos2)==1) {
    for (i=0;i<strlen(unos);i++){
      if (unos[i]==unos2[0]){
        k=i*2;
        if (i==0){
          rijec[0]=unos2[0];
        }
        else{
          rijec[k]=unos2[0];
        }
      }
    }
  }

/*PROVJERA: Je li zadnja uneseno slovo točno?*/
  for (j=0;j<strlen(unos);j++){
     c=j*2;
      if(rijec[c]==unos[j]){
        n++;
      }
     if (n==strlen(unos)){
        printf("Pogodili ste!");
        return 0;
        break;
     }
   }
  return 1;
}
/*Stvaranje početnog stringa za pogađanje.*/
void pocetak (char *unos, char *rijec){
  int i,j;
  for (i=0;i<(2*strlen(unos));i++){
    if (i%2==0){
      rijec[i]='_';
    }
    else rijec[i]=' ';
  }
}
