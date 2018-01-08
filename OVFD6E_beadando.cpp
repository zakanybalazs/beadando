#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 50
#define MAXL 30
struct Data {
  int id;
  char name[MAXL];
  int number;
};

void init(Data db[]) {
  // felveszünk alapértelmezet értékeket
  for (int i = 0; i < SIZE; i++) {
    db[i].id = 0;
    strcpy(db[i].name, "");
    db[i].number = 0;
  }
}
void preLoadData(Data db[]) {
  db[0].id = 1;
  strcpy(db[0].name, "Tyler Jones");
  db[0].number = 9;
  db[1].id = 2;
  strcpy(db[1].name, "Chriss Brook");
  db[1].number = 8;
  db[2].id = 3;
  strcpy(db[2].name, "Lebron James");
  db[2].number = 23;
  db[3].id = 4;
  strcpy(db[3].name, "Kevin Durant");
  db[3].number = 5;
  db[4].id = 5;
  strcpy(db[4].name, "Joel Noahim");
  db[4].number = 13;
  db[5].id = 6;
  strcpy(db[5].name, "Steve Harris");
  db[5].number = 33;
}
int autoIncrement(Data db[]) {
  int p = 0;
  int id;
  int ex = 0;
  while (ex != 1) {
    id = db[p].id;
    if (id != 0) {
      p++;
    } else {
      ex = 1;
    }
  }
  if (db[p-1].id+1 > 4000) {
    return 1;
  } else {
    return db[p-1].id+1;
  }
}
int getLastPoz(Data db[]) {
  int p = 0;
  int id;
  int ex = 0;
  while (ex != 1) {
    id = db[p].id;
    if (id != 0) {
      p++;
    } else {
      ex = 1;
    }
  }
  return p;
}
int search(Data db[], int id) {
  int i = 0;
  int ai;
  ai = autoIncrement(db);
  while (db[i].id != id && i < SIZE) i++;
  if (i < ai) {
    return i;
  } else {
    return ai;
  }
}
void newRec(Data db[]) {
  printf("\n\tAdatbevitel: \n");
  int poz, ai;
  fflush(stdin);
  poz = getLastPoz(db);
  ai = autoIncrement(db);
  printf("ID: %d\n", ai);
  printf("Nev: ");
  fflush(stdin);
  scanf("%[^\n]s", &db[poz].name);
  printf("Mezszam: ");
  fflush(stdin);
  scanf("%d", &db[poz].number);
  db[poz].id = ai;
  printf("\n\t Sikeresen rogzitve \n\n");
}
void del(Data db[]){
  int id, poz, ai;
  char valasz;
  printf("\n\tMelyik rekordot szeretned torolni?\n");
  scanf("%d",&id);
  ai = autoIncrement(db);
  poz = search(db, id);
  fflush(stdin);
  if (id > 0 && id < ai && poz != ai) {
  printf("\nBiztosan torolni szeretned %s-t a rendszerbol? [Y/N]", db[poz].name);
  scanf("%s", &valasz);
  if (valasz == 'Y' || valasz == 'y') {
    while (db[poz].id != 0) {
      db[poz].id = db[poz+1].id;
      strcpy(db[poz].name, db[poz+1].name);
      db[poz].number = db[poz+1].number;
      poz++;
    }
    printf("A modositas megtortent\n");
  } else {
    system("cls");
  }
   } else {
     printf("Nincs ilyen ID.vel rendelkezo rekord\n");
    }
}
void edit(Data db[], int poz) {
  int id;
  if (poz != 0) {
    printf("ID: %d\t Nev: %s \t Mezszam: %d\n\n", db[poz].id, db[poz].name, db[poz].number);
    fflush(stdin);
    printf("Uj nev:\n");
    scanf("%[^\n]s", db[poz].name);
    fflush(stdin);
    printf("Uj Mezszam:\n");
    scanf("%d", &db[poz].number);
  } else {
    printf("Melyik rekordod modositjuk?\n");
    scanf("%d", &id);
    fflush(stdin);
    poz = search(db, id);
    printf("ID: %d\t Nev: %s \t Mezszam: %d\n\n", db[poz].id, db[poz].name, db[poz].number);
    printf("Uj nev:\n");
    scanf("%[^\n]s", db[poz].name);
    fflush(stdin);
    printf("Uj mezszam:\n");
    scanf("%d", &db[poz].number);
  }
}
void showAll(Data db[]) {
  printf("ID. \t Felhasznalo \t Mezszam\n\n");
  for (int i = 0; i < SIZE; i++) {
    if (db[i].id != 0) printf("%d \t %s\t\t %d \t\n", db[i].id,db[i].name, db[i].number);
  }
}
int keresesFelulet(Data db[]){
  /* ----- Keresési felület. ----- */
      printf("Kereses id alapjan:\n");
      int searchid;
      int found = SIZE + 1; // a kereséshez szükséges változók
    do {
      scanf("%d", &searchid); // bekérjük a keresett id-t
      // átadjuk a search függvénynek a keresett id-t és a db-t (ahol keressük)
      found = search(db,searchid); // ez visszaad egy számot, ami az keresett emberke indexe a db-ben
      if (db[found].number != SIZE + 1) {
        printf("Nev: %s, iranyitoszam: %d\n", db[found].name, db[found].number); // megmutatjuk a usernek az index nevét
      } else {
        printf("Nincs %d id-val rendelkezo rekord adj meg egy masikat\n", searchid);
        found = SIZE + 1;
      }
    } while(found == SIZE + 1);
    return found;
}


int main() {
  Data db[SIZE];
/* --- felveszünk adatokat előre --- */
    init(db);
    printf("\n\tCsapatmez nyilvantarto\n");
    printf("\n\t\tToltsek be elore adatokat? [Y/n]\n");
    char pre;
    scanf("%c", &pre);
    if (pre == 'y' || pre == 'Y') {
      preLoadData(db);
    }

/* --- Menü séma elkészítése --- */
int choice;
int keresID = 0;
do {
  fflush(stdin);
  printf("\n\n\t\t\t Adatbazis kezelo \n\n");
  // printf("\t Főmenü: 1 \n");
  printf("  <--------------------------------------------------------------->\n\n");
  printf("\t Adatbazis mutatasa: 1 \n");
  printf("\t Kereses az adatbazisban: 2 \n");
  printf("\t Adatmodositas azonosito megadasaval: 3 \n");
  printf("\t Adat torlese: 4 \n");
  printf("\t Uj adat bevitele: 5 \n");
  printf("\t Kilepes: 0 \n");
  scanf("%d", &choice);
  system("cls");
    switch (choice) {
      case 1:
        keresID = 0;
        showAll(db);
        break;
      case 2:
        keresID = 0;
        keresID = keresesFelulet(db);
        printf("\n ----- %s modositasa az adatbazisban: 3 ----\n", db[keresID].name);
        break;
      case 3:
        edit(db,keresID);
        break;
      case 4:
        keresID = 0;
        del(db);
        break;
      case 5:
        keresID = 0;
        newRec(db);
        break;
      case 0:
        break;
      default:
        printf("Nem megfelelo menu választás!\n");
    }
  } while(choice != 0);
  system("pause");
}
