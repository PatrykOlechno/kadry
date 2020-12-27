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

void wypisz_liste(pracownik_t *head);
void dodaj_pracownika(pracownik_t **head, char nazwisko[20], char imie[20], char pesel[12], char data_rozp[11], int pensja);
void usun_pracownika(pracownik_t *head, char pesel[12]);

int main(){
    int wybor = 0; // wybor z menu
    int program = 1; //gdy rowne 0, program sie konczy    char nazwisko[20];

    // dodwanie pracownika case2
    char nazwisko[20];
    char imie[20];
    char pesel[12]; // char zamiast int, bo pesel moze zaczynac sie od 0
    char data_rozp[11];  // format "DD/MM/RRRR"
    int pensja;

    //tworzenie glowy listy
    pracownik_t *head;
    head = (pracownik_t*)malloc(sizeof(pracownik_t));
    head = NULL;

    //testowi pracownicy
    dodaj_pracownika(&head, "", "Szyc", "75121968629", "31/01/1992", 4000);
    dodaj_pracownika(&head, "Olech", "Patryk", "75121967621", "12/21/2020", 30000);
    dodaj_pracownika(&head, "Cukier", "Marek", "75121968723", "04/05/1999", 5000);

    //wiadomosc powitalna
    printf("Witaj w programie Kadry!\n\n");

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
        usun_pracownika(head, pesel);
        break;
    case 4:
        printf("Funkcja %d niedostepna\n", wybor);
        break;
    case 5:
        printf("Funkcja %d niedostepna\n", wybor);
        break;
    case 6:
        printf("Funkcja %d niedostepna\n", wybor);
        break;
    case 7:
        printf("Funkcja %d niedostepna\n", wybor);
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
        for (int i = 0; i<100; i++){ printf("-");}
        printf("\n");
        while(ptr != NULL){
            printf("%20s | %20s | %12s | %11s | %d\n", ptr->nazwisko, ptr->imie, ptr->pesel, ptr->data_rozp, ptr->pensja);
            ptr= ptr->nastepny;
        }
        for (int i = 0; i<100; i++){ printf("-");}
        printf("\n");
    }
}
//dodaj pracownika
void dodaj_pracownika(pracownik_t **head, char nazwisko[20], char imie[20], char pesel[12], char data_rozp[11], int pensja){
  pracownik_t *nowy = (pracownik_t *)malloc(sizeof(pracownik_t));

  if(nowy == NULL){
    printf("Error. Pamiec nie zostala zaalokowana.\n");
  }else{
    printf("Pracownik dodany pomyslnie!\n\n");
  };
  //dane nowego pracownika
  strcpy(nowy->nazwisko, nazwisko);
  strcpy(nowy->imie , imie);
  strcpy(nowy->pesel , pesel);
  strcpy(nowy->data_rozp , data_rozp);
  nowy->pensja = pensja;

  //pracownik na pierwsze miejsce
    nowy->nastepny = (*head);
    (*head) = nowy;
}
//usun pracownika
void usun_pracownika(pracownik_t *head, char pesel[12]){
  pracownik_t *poprzedni = NULL;
  pracownik_t *aktualny = head;
  if (head == NULL) printf("Lista jest pusta! Nic stąd nie usuniesz!\n");

  while(aktualny->pesel != pesel){
    if(aktualny->nastepny == NULL){
      printf("Nie ma takiego pracownika!\n");
      break;
    }else{
      //idziemy przez petle az znajdziemy pesel
      poprzedni = aktualny;
      aktualny = aktualny->nastepny;
    }

    if (aktualny == head){
      //przeskakujemy pierwszy element
      head = head->nastepny;
      printf("Element zostal usuniety!\n");
    }else {
      //przeskakujemy srodkowy elemnt
      poprzedni->nastepny = aktualny->nastepny;
      printf("Element zostal usuniety!\n");
    }

  }
}