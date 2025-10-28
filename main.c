#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

char letter_arr1[SIZE] = {'z', 'S', 's', 'a'};
char number_arr1[SIZE] = {4, -1, 2, 9};


void swap(char *a, char *b);
//sorteringsfunktioner
bool numbers_in_ascending_order(char a, char b);
bool letters_in_order(char a, char b);
//aver bubblesort funktionen med en pointer til et array og en pointer til en funktion
void bubble_sort(char *arr, bool (*pair_is_in_order)(char a, char b));


int main() {

    printf("bogstaver før sortering: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", letter_arr1[i]);
    }
    printf("\n");
    
    //Kalder sortering af bogstaver
    bubble_sort(letter_arr1, letters_in_order);
    
    printf("bogstaver efter sortering:  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", letter_arr1[i]);
    }
    printf("\n");
    

    printf("tal før sortering: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", number_arr1[i]);
    }
    printf("\n");
    
    //kalder sortering af tal
    bubble_sort(number_arr1, numbers_in_ascending_order);
    
    printf("tal efter sortering:  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", number_arr1[i]);
    }
    printf("\n");
    
    return 0;
}

void bubble_sort(char *arr, bool (*pair_is_in_order)(char a, char b)) {
    bool swapping_occurred;
    int koert = 0;
    
    do {
        swapping_occurred = false;
        //i starter på 1, da man sammenligner tallet man er på og det tidligere tal
        for (int i = 1; i < SIZE-koert; i++) {
          //tjekker om værdierne i arrayet er i rigtig rækkefølge
            if (!pair_is_in_order(arr[i-1], arr[i])) {
              //bytter værdierne
                swap(&arr[i-1], &arr[i]);
                swapping_occurred = true;
            }
        }
        //hver gang funktionen har kørt ved jeg at det sidste tal der er kørt er på plads, og derfor kan jeg køre for-loopet en gang mindre
        koert++;
    } while (swapping_occurred);
}


void swap(char *a, char *b) {
  //bytter på værdierne på positionen pointersne peger på
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool letters_in_order(char a, char b) {
  //hvis bogstavet er stort trækker jeg et stort A fra bogstavet ellers trækker jeg lille a fra for at få talværdier til at sammenligne
  if(a>='A' && a<='Z'){
    a=a-'A';
  }else{
    a=a-'a';
  }
    if(b>='A' && b<='Z'){
    b=b-'A';
  }else{
    b=b-'a';
  }
  //returnerer bool om a er mindre end b
    return a <= b;
}

bool numbers_in_ascending_order(char a, char b) {
  //returnerer bool om a er mindre end b
  //kan bruge char til tal da det hele bare er binære værdier. virker dog kun op til 127 da eller er der overflow
    return a <= b;
}
