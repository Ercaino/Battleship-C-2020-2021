#include <iostream>

void delay(clock_t a);
char getch(void);

extern const char str[30];               //Visualizzato a schermo
extern const char str1[30];        //Visualizzato a schermo

void SystemError();
void UserError();
void Lose();
void Win();

/*Funzione*/
void SinglePlayer();