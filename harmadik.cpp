#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int legkisebb_karakter(char []);
int hany_kisbetu(char []);
char* ugyanaz_visszafele(char []);

int main ()
{
  char szoveg [100];
  for (int z = 0; z < 100; z++) {
    szoveg[z] = '~';
  }
  //feltolt (szoveg );
  printf("Tetszoleges szoveg:");
  scanf("%[^\n]" , &szoveg);

  printf("\nSzoveg tomb\n");

  for (int i = 0; i < 100; i++)
  {
    if (szoveg[i] != '~') {
    printf("%c", szoveg[i]);
  }
  }

  char legkisebb = legkisebb_karakter(szoveg);
  printf("A legkisebb karakter a(z) %c\n", legkisebb);

  int kisbetuk = hany_kisbetu(szoveg);
  printf("A kisbetuk szama  %d\n", kisbetuk);

  char valasz[4];
  char* memoria_hely;
  memoria_hely = ugyanaz_visszafele(szoveg);


   printf("Visszafele ugyan az? - %s\n",memoria_hely);

  system("pause");
}

int legkisebb_karakter(char szoveg[]) {
  int q = 0;
  while (szoveg [q] != '\0') {
    q++;
  }
  printf("\nSzoveg tomb hossza: %d\n", q);

    int min_index;
    char min = szoveg[0];
    for (int i = 0; i < 100; i++)
    {
      if (szoveg [i] == '\0')
      {
        break;
      }
      if (szoveg [i] < min && szoveg [i] != '~')
      {
        min = szoveg [i];
        min_index = i;
      }
    }
    return szoveg[min_index];
}
int hany_kisbetu(char szoveg[]) {
  // meghatarozzuk a hosszat
  int q = 0;
  while (szoveg [q] != '\0') {
    q++;
  }
  int kisbetuk_szama = 0;
  for (int i = 0; i < q; i++) {
    if (szoveg[i] >= 'a' && szoveg[i] <= 'z') {
      kisbetuk_szama++;
    }
  }
  return kisbetuk_szama;
}
char* ugyanaz_visszafele(char szoveg[]) {
  // meghatarozzuk a hosszat
  int q = 0;
  while (szoveg [q] != '\0') {
    q++;
  }
  int qp;
  qp = q / 2;

  char* nem = new char[3];
  nem[0] = 'n';
  nem[1] = 'e';
  nem[2] = 'm';

  char* igen = new char[4];
  nem[0] = 'i';
  nem[1] = 'g';
  nem[2] = 'e';
  nem[3] = 'n';


  for (int i = 0; i < qp; i++) {
    // printf("%c = %c\n", szoveg[i], szoveg[q-1-i]);
    if (szoveg[i] != szoveg[q-1-i]) {
      return nem;
    }
  }

    return igen;
}
