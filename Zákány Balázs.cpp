#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
  char szoveg[80];
  int hossz;
  int kisbetu;
};

int tomb_poz_hossz(char szoveg[]) {
  int i = 0;
  while (szoveg[i] != '\0') {
    i++;
  }
  return i;
}
int kisbetuk_szama(char szoveg[]) {
  int i = 0;
  int kisbetu = 0;
  while (szoveg[i] != '\0') {
    if (szoveg[i] >='a' && szoveg[i] <= 'z') {
      kisbetu++;
    }
    i++;
  }
  return kisbetu;
}
void leghosszabb_szoveg(Data db[], int hossz) {
  int leghosszabb = 0;
  int leghosszabb_index;
    for (int i = 0; i < hossz; i++) {
      int szoveg_hossz = tomb_poz_hossz(db[i].szoveg);
      if (leghosszabb < szoveg_hossz) {
        leghosszabb = szoveg_hossz;
        leghosszabb_index = i;
      }
    }
    printf("%s\n", db[leghosszabb_index].szoveg);
}
void legrovidebb_szoveg(Data db[], int hossz) {
  int legrovidebb = 80;
  int legrovidebb_index;
    for (int i = 0; i < hossz; i++) {
      int szoveg_hossz = tomb_poz_hossz(db[i].szoveg);
      if (legrovidebb > szoveg_hossz) {
        legrovidebb = szoveg_hossz;
        legrovidebb_index = i;
      }
    }
    printf("%s\n", db[legrovidebb_index].szoveg);
}
float atlag_szoveg(Data db[], int hossz) {
  float atlag;
  int szum = 0;
  int osszeg = 0;
    for (int i = 0; i < hossz; i++) {
      osszeg += db[i].hossz;
      atlag = osszeg / szum;
      szum++;
    }
    return atlag;
}


int main() {
  Data db[100];

  int poz = -1;
  char valasz;
  for (int i = 0; i < 100; i++) {
    for (size_t x = 0; x < 80; x++) {
      db[i].szoveg[x] = '\0';
    }
  }

  char v;
  poz++;
  printf("Adjon meg tetszoleges szoveget\n");
  fflush(stdin);

  scanf("%[^\n]", &db[poz].szoveg);
  fflush(stdin);

  db[poz].hossz = tomb_poz_hossz(db[poz].szoveg);
  db[poz].kisbetu = kisbetuk_szama(db[poz].szoveg);




printf("Leghosszabb szoveg:\n");
leghosszabb_szoveg(db, poz+1);
printf("legrovidebb szoveg:\n");
legrovidebb_szoveg(db, poz+1);

printf("atlag szoveg: %f\n",atlag_szoveg(db, poz+1));


system("pause");
}
