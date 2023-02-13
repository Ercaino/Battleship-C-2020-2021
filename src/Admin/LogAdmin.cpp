//System file
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

  const string NameA = "Fulvio"; //Name Administrator
  const string Password = "diobello"; //Password System
  const string Application = "Battle Ship"; //Application Name
  const string VersionStable = "1.0.1"; //Stable Version

int AdminLog(){
  //Costanti di info


  //Credenziali e sistema
  string Pass; //Control Variable
  string command;
  string verifica;
  string variabile1;
  int ip;

	cin>>variabile1;

  //If the variable is the administrator name, it asks for the password
  if(variabile1 == NameA){
    cout<<endl<<"Inserisci la password per accedere al sistema\n\n"<<" :: ";

    //Password check and request+
    for(int i=0; i<1; i++){
      cin>>Pass;
      //Password Check
      if(Pass!=Password){
  			break; //Esce dalla funzione
  		}
    }

    //Has the password been entered correctly?
        do{
          system("cls"); // Pulisci La Schermata
          cout<<"Accesso eseguito come Amministratore\n\n";

          //Info System
          cout<<"\nStarted Console\n\n"
              <<"________________________________\n"
              <<"\n\t Author: " << NameA
              <<"\n\t Application: " << Application
              <<"\n\t Version Stable: " << VersionStable
              <<"\n\t Status:" << "online\n"
              <<"________________________________\n";

          //Comandi
			
			cin>>ip;
        }while(false); //Close Do while
        cout<<"Uscita Amministratore";
    } //First if
    return(0);
} //Close void