// System file
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <chrono>
#include <thread>

// Header file
#include "Admin/LogAdmin.h"               //Admin
#include "Error/ErrorSystem.h"            //Errore Sistema
#include "Error/ErrorUser.h"              //Errore Utente
#include "SinglePlayer/SinglePlayer.h"    //Messaggio benvenuto
#include "Delay.h"                        //Funzione Delay 
#include "Getch.h"                        //Funzione Getch


using namespace std;

// Costanti
const std::string NameA = "Admin";                 // Name Administrator
const std::string Password = "Itis01";             // Password System
const std::string Application = "Battle Ship";     // Application Name
const std::string VersionStable = "1.0.1";         // StableVersion

const char str[30]="Battleship";               //Visualizzato a schermo
const char str1[30]="By Sappia Fulvio";        //Visualizzato a schermo

// Giocatore
std::string Nome_Giocatore;

using std::cout;
using std::endl;

void funcSleep(){
    std::this_thread::sleep_for(std::chrono::seconds (3));
}

void NomeW(){
  cout << endl;
  cout<<"#############################################################################################\n";
    cout<<"                      *                                           *\n";
    cout<<"            *        * *                                         * *        *\n";
    cout<<"           * *        *          WELCOME TO BATTLESHIP          *        * *\n";
    cout<<"          *   *            *           PLAY NOW            *             *   *\n";
    cout<<"           * *            * *                              * *             * *\n";
    cout<<"            *              *                                *               *\n";
    cout<<"#############################################################################################\n";
  cout << endl << endl;

  cout << "Progetto: aggiornamento e manuntenzione costante.\n";
  cout << "Contattate: 'sappia.fulvio@polotecnologicoimperiese.it' per Consigli e Segnalazioni. \n" << endl;
  delay(100);

  cout << "Inserisci il tuo Nickname: \t";
  
}

int main() {
  //Inizio Conto in secondi
  auto start = std::chrono::high_resolution_clock::now();
    funcSleep();
  
    //A:Aircraft carrier
    //B:Battleship
    //D:Destroyer
    //C:Corvette

  //Inizio Programma
  NomeW();
  //Chiedo il nome del giocatore
  cin >> Nome_Giocatore;
  
  // Log Admin
  if (Nome_Giocatore == NameA) {
    AdminLog();
  }
  
  /*
  // Errore Log
  if (AdminLog() == 2) {
    SystemError();
    delay(100);
    cout << "Ridigita il nome del giocatore\n\n"; 
    delay(1000);
    cin >> Nome_Giocatore;   
  }
  */
  
  //SinglePlayer
  SinglePlayer();
  
  
  auto end = std::chrono::high_resolution_clock::now();

    auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "La durata della partita è di: " << int_s.count() << " secondi )" << 
    std::endl;
  
    return EXIT_SUCCESS;
}