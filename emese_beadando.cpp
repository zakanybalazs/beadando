#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct adat{
  int az;
  char nev [50];
  int kor;
};
int keres(adatok adatbazis [], int az)
  {
    for (int i = 0; i < 40; i++)
    {
      if (az == adatbazis[i].az)
      {
        return i;
      }
    }
    return 40;
  }
void kiir(adatok adatbazis [])
 {
  for (int i = 0; i < 40 ; i++)
    {
      if (adatbazis[i].az != 0)
      {
        printf("%d\t\t%s\t\t%d\n", adatbazis[i].az, adatbazis[i].nev, adatbazis[i].kolesz);
      }
  }


}
void ujadat (adatok adatbazis [])
  {
    for (int i = 0; i < 40; i++)
    {
      if (adatbazis[i].az == 0)
      {
        printf("Azonosito: %d\n", i+1);
        adatbazis[i].az = i+1;
        fflush(stdin);
        printf("Nev:");
        scanf("%[^\n]" , &adatbazis[i].nev);
        fflush(stdin);
        printf("Kolesz: ");
        scanf("%d", &adatbazis[i].kolesz);
        fflush(stdin);
        break;
      }
    }
  }
void kereses (adatok adatbazis [])
  {
    int keresd;
    // bekérem az azonosítót, ami alapján megkeresem, hogy hol van a tömbben
    printf ("Keresendo azonosito: ");
    scanf ("%d", &keresd);
    int i = keres(adatbazis, keresd);


    }
void torles(adatok adatbazis [])
  {
  printf("Torles azonosito alapjan.\n");
  printf("Azonosito megadasa:\n");
  int valasz;
  scanf("%d", &valasz);
  int i = keres(adatbazis,valasz);
    if (i != 40) {
      printf("%s torlese az adatbazisbol\n", adatbazis[i].nev);
      printf("Biztosan torolni szeretned? [I/N]\n");
      char val;
      scanf("%s", &val);

      if (val == 'i' || val == 'I')
      {
        printf("Torles\n");
        for (int z = i; z < 39; z++)
        {
          adatbazis[z].az = adatbazis[z+1].az;
          strcpy(adatbazis[z].nev, adatbazis[z+1].nev);
          adatbazis[z].kolesz = adatbazis[z+1].kolesz;
        }
        adatbazis[39].az = 0;
        strcpy(adatbazis[39].nev , "");
        adatbazis[39].kolesz = 0;
      }
      else
      {
        printf("Torles megszakitasa\n");
      }
      printf("A torles befejezodott\n");
    }
    else
    {
      printf("Nincs ilyen azonosito az adatbazisban!\n");
      system("pause");
      system("cls");
      torles(adatbazis);
    }
  }
void adatmodositas(adatok adatbazis [])
  {
    printf("Melyik adatot szeretned modositani? (azonosito)\n");
    int az;
    fflush(stdin);
    scanf("%d", &az);
    int i = keres(adatbazis, az);
    printf("Regi adatok:\n Nev: %s\n Kolesz: %d\n", adatbazis[i].nev,adatbazis[i].kolesz);
    printf("\nUj adatok megadasa:\n");
    fflush(stdin);
    printf("Nev:");
    scanf("%[^\n]" , &adatbazis[i].nev);
    fflush(stdin);
    printf("Kolesz: ");
    scanf("%d", &adatbazis[i].kolesz);
    fflush(stdin);
  }

int main()
{
  adatok adatbazis [40];

  for (int i = 0; i < 40; i++) {
    adatbazis[i].az = 0;
    strcpy(adatbazis[i].nev , "");
    adatbazis[i]. kolesz   = 0;
  }

  adatbazis[0].az   =1;
  strcpy(adatbazis[0].nev , "Anna");
  adatbazis[0]. kolesz   = 35;
  adatbazis[1].az   =2;
  strcpy(adatbazis[1].nev , "Bela");
  adatbazis[1]. kolesz   = 23;
  adatbazis[2].az   =3;
  strcpy(adatbazis[2].nev , "Mia");
  adatbazis[2]. kolesz   = 11;
  adatbazis[3].az   =4;
  strcpy(adatbazis[3].nev , "Zsolt");
  adatbazis[3]. kolesz   = 111;


int valasz;

do
{
  //menü

  printf ("1 Adatbazis megjelenitese\n");
  printf ("2 Kereses\n");
  printf ("3 Uj adat felvitele\n");
  printf ("4 Adatvaltoztatas\n");
  printf ("5 Torles\n");
  printf ("0 Kilepes\n");



  scanf("%d", &valasz);
  printf("\n" );
  system("cls");



switch (valasz) {
      case 1: kiir (adatbazis);
              break;
      case 2: kereses (adatbazis);
              break;
      case 3:ujadat (adatbazis);
              break;
      case 4:adatmodositas (adatbazis);
              break;
      case 5: torles (adatbazis);
              break;
      case 0:printf ("\nSzia!\n");
            break;
  }
} while(valasz != 0);

system("pause");
}
