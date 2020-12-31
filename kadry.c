// Program do zarzadzania kadrami
// Patryk Olechno 2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tworzenie infrastruktury listy pracownikow

typedef struct pracownik{
    char nazwisko[20];
    char imie[20];
    char pesel[12]; // char zamiast int, bo pesel moze zaczynac sie od 0
    char data_rozp[11];  // format "DD/MM/RRRR"
    int pensja;
    struct pracownik *nastepny;
} pracownik_t;

//headery funkcji listy
void wypisz_liste(pracownik_t *head);
void dodaj_pracownika(pracownik_t **head, char nazwisko[20], char imie[20], char pesel[12], char data_rozp[11], int pensja);
void usun_pracownika(pracownik_t **head, char pesel[12]);
void edytuj_pracownika(pracownik_t *head, char nazwisko[20], char imie[20], char pesel[12], char data_rozp[11], int pensja, char nowy_pesel[12]);
void szukaj_pracownika(pracownik_t *head, char pesel[12]);
void eksportuj_od_danej_pensji(pracownik_t *head, int pensja);

int main(){
    int wybor = 0; // wybor z menu
    int program = 1; //gdy rowne 0, program sie konczy    char nazwisko[20];

    // dodwanie pracownika switchu
    char nazwisko[20];
    char imie[20];
    char pesel[12]; // char zamiast int, bo pesel moze zaczynac sie od 0
    char data_rozp[11];  // format "DD/MM/RRRR"
    int pensja;
    char nowy_pesel[12];

    //tworzenie glowy listy
    pracownik_t *head;
    head = (pracownik_t*)malloc(sizeof(pracownik_t));
    head = NULL;

    //testowi pracownicy
    dodaj_pracownika(&head, "cela", "jonhanson", "75121968634", "30/01/2000", 5000);
    dodaj_pracownika(&head, "blonie", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "asd", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "gdc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "mdc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "odc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "hdc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "zdc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "rdc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "gdc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "xdc", "szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "fdc", "szyc", "75121968629", "31/01/1992", 4000);


    //wiadomosc powitalna
    printf("Witaj w programie Kadry!\n\n");

    //glowna petla
    while(program){

    //wypisz menu
    printf("MENU\n");
    printf("Co chcesz zrobic? Kliknij (1-8)\n");
    printf("1.Wypisz baze pracownikow.\n");
    printf("2.Dodaj pracownika.\n");
    printf("3.Usun pracownika.\n");
    printf("4.Edytuj uzytkownika.\n");
    printf("5.Szukaj pracownika.\n");
    printf("6.Eksportuj dane pracownikow od danej daty.\n");
    printf("7.Eksportuj dane pracownikow zarabiajacych powyzej danej kwoty.\n");
    printf("8.Zakoncz.\n");
    scanf("%d", &wybor);

    //sprawdz wybor
    switch (wybor)
    {
    case 1:
        system("cls");     //wyczysc console
        wypisz_liste(head);
        break;
    case 2:
        system("cls");     //wyczysc console
        printf("Dodawnia pracownika:\n");
        printf("Podaj nazwisko, imie, pesel, date rozpoczenia (DD/MM/RRRR) oraz pensje\n");
        scanf("%s %s %s %s %d", &nazwisko, &imie, &pesel, &data_rozp, &pensja);
        dodaj_pracownika(&head, nazwisko, imie, pesel, data_rozp, pensja);
        break;
    case 3:
        system("cls");     //wyczysc console
        printf("Usuwanie pracownika:\n");
        printf("Podaj pesel pracownika ktorego chesz usunac: \n");
        scanf("%s", &pesel);
        usun_pracownika(&head, pesel);
        break;
    case 4:
        system("cls");     //wyczysc console
        printf("Edytowanie pracownika:\n");
        printf("Podaj pesel pracownika, ktorego chesz edytowac: \n");
        scanf("%s", &pesel);
        printf("Podaj nowe nazwisko, imie, pesel, date rozpoczenia (DD/MM/RRRR) oraz pensje:  \n");
        scanf("%s %s %s %s %d", &nazwisko, &imie, &nowy_pesel, &data_rozp, &pensja);
        edytuj_pracownika(head, nazwisko, imie, pesel , data_rozp, pensja, nowy_pesel);
        break;
    case 5:
        system("cls");     //wyczysc console
        printf("Szukanie pracownika:\n");
        printf("Podaj pesel pracownika, ktorego chcesz znalezc: \n");
        scanf("%s", &pesel);
        szukaj_pracownika(head, pesel);
        break;
    case 6:
        printf("Funkcja %d niedostepna\n", wybor);
        break;
    case 7:
        system("cls");     //wyczysc console
        printf("Podaj minimalna pensja od ktorej zaczac eksportowanie: ");
        scanf("%d", &pensja);
        eksportuj_od_danej_pensji(head, pensja);
        break;
    case 8:
        printf("Do zobaczenia!\n");
        program = 0;
        break;
    default:
        printf("Wybierz poprawna opcje (1-8)\n");
        break;
    }
    }
    return 0;
}
// wypisz liste
void wypisz_liste(pracownik_t *head){
    if(head == NULL){
        printf("\nLista pracownikow jest pusta.\n");
    }else{
        pracownik_t *ptr = head;
        //wyglad listy
        for (int i = 0; i<80; i++){ printf("*");}
        printf("\n");
        while(ptr != NULL){
            printf("%20s | %20s | %12s | %11s | %d\n", ptr->nazwisko, ptr->imie, ptr->pesel, ptr->data_rozp, ptr->pensja);
            ptr= ptr->nastepny;
        }
        for (int i = 0; i<80; i++){ printf("*");}
        printf("\n");
    }
}
//dodaje pracownika na jego miejsce
void dodaj_pracownika(pracownik_t **head, char nazwisko[20], char imie[20], char pesel[12], char data_rozp[11], int pensja){
    pracownik_t *nowy = (pracownik_t *)malloc(sizeof(pracownik_t));
    pracownik_t *aktualny = *head;
    pracownik_t *poprzedni = NULL;

    //blad rezerwacji pamieci
    if(nowy == NULL){
        printf("Nie udalo sie zarezerwowac pamieci. Quitting...\n");
        return;
    }else{
        //Dane nowego pracownika
        strcpy(nowy->nazwisko, nazwisko);
        strcpy(nowy->imie , imie);
        strcpy(nowy->pesel , pesel);
        strcpy(nowy->data_rozp , data_rozp);
        nowy->pensja = pensja;

        //Jesli lista jest pusta dodaj go na poczatek
        if(*head == NULL){
            nowy->nastepny = (*head);
            (*head) = nowy;
            printf("1");
        }
        else{
        //Inaczej idz do nastepnego miejsca dopoki roznica kolejncyh liter alfabetu bedzie (a-b = 10-11) ujemna
        if(strcmp(aktualny->nazwisko, nowy->nazwisko) > 0){
            //Pasuje na pierwsze miejsce
            nowy->nastepny = (*head);
            (*head) = nowy;
        }else if((strcmp(aktualny->nazwisko, nowy->nazwisko) < 0) && aktualny->nastepny == NULL){
            //gdy sa dwa elementy w liscie wskaznik na nastepny zbyt szybko wykracza poza zasieg
            nowy->nastepny = aktualny->nastepny;
            aktualny->nastepny = nowy;
        }else{
            //aktualizujemy wskazniki, bo przy pierwszym wywolaniu poprzedni wskazuje na NULL i bysmy wychodzili poza nasza pamiec
            poprzedni=aktualny;
            aktualny= aktualny->nastepny;

            //powtarzamy petle do konca listy lub jesli element pasuje wczesniej
            while(aktualny != NULL){
               if(strcmp(aktualny->nazwisko, nowy->nazwisko) > 0){
                   //Nastepnie dodaj go na to miejsce
                   nowy->nastepny = aktualny;
                   poprzedni->nastepny = nowy;
                   //wychodzimy z petli
                   break;}
               else{
                    //nic w petli tym razem, idziemy do nastepnej iteracji
                    poprzedni=aktualny;
                    aktualny = aktualny->nastepny;
                }
            }
            //jesli wyszlismy z petli, to doszlismy do konca bez rezultatu; dodajemy tam pracownika
            if(aktualny ==NULL){
                nowy->nastepny = aktualny;
                poprzedni->nastepny = nowy;
            }
        }
        }
    }
}
//usun pracownika
void usun_pracownika(pracownik_t **head, char pesel[12]){
  //pomocnicze wskazniki
  pracownik_t *poprzedni = NULL;
  pracownik_t *aktualny = *head;

  if (*head == NULL) printf("Lista jest pusta! Nic stąd nie usuniesz!\n");
  //czy taki pracownik istnieje?
  while(strcmp(aktualny->pesel, pesel)){
    if(aktualny->nastepny == NULL){
      printf("Nie ma takiego pracownika!\n");
      break;
    }else{
      poprzedni = aktualny;
      aktualny = aktualny->nastepny;
    }}

    if (aktualny == *head){
      //przeskakujemy pierwszy element
      *head = aktualny->nastepny;
      printf("Element zostal usuniety!\n");
      }else{
        //przeskakujemy srodkowy elemnt
        poprzedni->nastepny = aktualny->nastepny;
        printf("Element zostal usuniety!\n");
      }
      free(aktualny); //zwolnienie pamieci
    }

//edytuj pracownika
void edytuj_pracownika(pracownik_t *head, char nazwisko[20], char imie[20], char pesel[12], char data_rozp[11], int pensja, char nowy_pesel[12]){
  //pomocnicze wskazniki
  pracownik_t *poprzedni = NULL;
  pracownik_t *aktualny = head;

  //czy taki pracownik istnieje?
  while((strcmp(aktualny->pesel, pesel))){
    if(aktualny->nastepny == NULL){
      printf("Nie ma takiego pracownika!\n");
      break;
    }else{
      //idziemy przez petle az znajdziemy pesel
      poprzedni = aktualny;
      aktualny = aktualny->nastepny;
    }
  }
    //update info
    strcpy(aktualny->nazwisko, nazwisko);
    strcpy(aktualny->imie , imie);
    strcpy(aktualny->pesel , nowy_pesel);
    strcpy(aktualny->data_rozp , data_rozp);
    aktualny->pensja = pensja;
    if (strcmp(aktualny->pesel, pesel)) printf("Dane zmienione pomyslnie\n");
    free(aktualny); //zwolnienie pamieci
}
void szukaj_pracownika(pracownik_t *head, char pesel[12]){
  pracownik_t *poprzedni = NULL;
  pracownik_t *aktualny = head;

  //czy taki pracownik istnieje?
  while((strcmp(aktualny->pesel, pesel))){
    if(aktualny->nastepny == NULL){
      printf("Nie ma takiego pracownika!\n");
      break;
    }else{
      //idziemy przez petle az znajdziemy pesel
      poprzedni = aktualny;
      aktualny = aktualny->nastepny;
    }
  }
  printf("\nDane pracownika:\n");
  for (int i = 0; i<80; i++){ printf("-");}
  printf("\n");
  printf("%20s | %20s | %12s | %11s | %d\n", aktualny->nazwisko, aktualny->imie, aktualny->pesel, aktualny->data_rozp, aktualny->pensja);
  for (int i = 0; i<80; i++){ printf("-");}
  printf("\n\n");
}
void eksportuj_od_danej_pensji(pracownik_t *head, int pensja){
  pracownik_t *aktualny = head;
  FILE * file = fopen("output.txt", "w");
  if (file != NULL){
    while(aktualny != NULL){
      if(aktualny->pensja > pensja){
          fprintf(file, "%20s | %20s | %12s | %11s | %d\n", aktualny->nazwisko, aktualny->imie, aktualny->pesel, aktualny->data_rozp, aktualny->pensja);
      }
      aktualny = aktualny->nastepny;
    }
    printf("\nDodano od pliku o nazwie output.txt\n\n");
    fclose(file);
  }else{
    printf("Plik nie istnieje");
  }
}
