
// Header file
#include "SinglePlayer.h"

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
#include <ctype.h>

using namespace std;

extern const char str[30];
extern const char str1[30];

void err(){
  cout<< "Non è possibile piazzare qua la nave, RIPROVA!";
}

void SinglePlayer(){
  int i,j,k=0,x,y,chk=0,win=0,uposa[5][2],uposb[4][2],uposd[3][2],uposc[2][2],a=0,b=0,c=0,d=0,probab,diff;
  char gridu[10][10],griduv[10][10],gridc[10][10],gridcv[10][10],orin[2],tempstr[10],ch;

  /* Navi Font */
  char naveA = 'A';
  char naveB = 'B';
  char naveC = 'C';
  char naveD = 'D';

  /* Attak Font */
  char colpito = '#';
  char mancato = '*';

  /* Matrice Font */
  char font = '.';
  
  for(int i=0;i<10;i++){
        printf("\n");
    }

    for(int i=0;i<30;i++){
        printf(" ");
    }

    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
        delay(60);
    }

    printf("\n");

    for(int i=0;i<30;i++){
        printf(" ");
    }

    for(int i=0;str1[i]!='\0';i++){
        printf("%c",str1[i]);
        delay(60);
    }

    delay(1500);
    cout << "\033[2J\033[0;0H";

    for(;;){
        cout << "\033[2J\033[0;0H";

        for(int i=0;i<10;i++)
            printf("\n");

        for(int i=0;i<30;i++)
            printf(" ");
        printf("1.Gioca a Battleship!\n");

        for(int i=0;i<30;i++)
            printf(" ");
        printf("2.Regole\n");
        ch=getch();

        if(ch==49)
            break;

        if(ch==50){
            cout << "\033[2J\033[0;0H";
            printf("\n\n\t\t╔uu══════════════════╗☆\n");
            printf("\t\t❝ <     RULES     > ❞ \n");
            printf("\t\t╚══════nn════════════╝ \n\n");
            printf("\t\t\t -ꦼ———▸Le regole si chiuderanno a tempo.\n\n");
            printf("\t\t.・゜゜・Pronto per la guerra?・゜゜・\n\n");

            printf("\t\t:: 1. Distruggi tutte le navi del tuo avversario prima che lo faccia lui.\n");
            printf("\t\t:: 2. Il tuo campo da battaglia sara un 10x10, disponi bene le tue navi.\n");
            printf("\t\t:: 3. Inserisci l'orientamento della nava (verticale o orizzontale). \n");
                  printf("\t\t\t\tPer l'orientamento orizzontale dovrai digitare 'h' e per quello verticale dovrai digitare 'v'.\n");
            printf("\t\t:: 4. Inserisci le coordinate x y (separate da uno spazio).\n");
                  printf("\t\t\t\tx è il numero di righa e y di colonna del campo.\n");
            printf("\t\t:: 5. Hai una flotta di 4 navi da battaglia pronte da poter mettere:\n");
                  printf("\n\t\t\t\tPortaerei (Unita Lunghezza = 5),\n" "\t\t\t\tCorazzata (Unita Lunghezza = 4),\n" "\t\t\t\tDistruttrice (Unita Lunghezza = 3),\n" "\t\t\t\tCorvetta (Unita Lunghezza = 2).\n\n");
            printf("\t\t:: 6. Dopo aver posizionato le tue navi, attacca l'area nemica e colpisci le navi nemiche per vincere.\n");
            printf("\t\t:: 7. Se l'attacco va a buon fine uscira 'h' e avrai un turno bonus.\n");
            printf("\t\t:: 8. Se non colpisci sara segnato con '*'.\n");
            fflush(stdin);
            puts(tempstr);
            delay(20000000);
            continue;
    }
  }

    cout << "\033[2J\033[0;0H"; //cls
  
    for(int i=0;i<10;i++)
    printf("\n");
    for(int i=0;i<30;i++)
    printf(" ");
    printf("Seleziona il livello di dificolta:\n");
    for(int i=0;i<30;i++)
    printf(" ");
    printf(":: 1. Dilettante\n");
    for(int i=0;i<30;i++)
    printf(" ");
    printf(":: 2. Professionale\n");
    for(int i=0;i<30;i++)
    printf(" ");
    printf(":: 3. Leggenda\n");
    ch=getch();
    if(ch==49)
        diff=9;
    if(ch==50)
        diff=8;
    if(ch==51)
        diff=6;
    cout << "\033[2J\033[0;0H"; //cls
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            gridc[i][j]=font;
            gridu[i][j]=font;
            gridcv[i][j]=font;
        }
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(int j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(int j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(int j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }

   /*Aircraft carrier*/

   for(;;)
    {
        printf("Portaerei (5):\n");
        printf("Orientamento (o/v): ");
        scanf("%s",&orin);
        printf("Coordinate x e y: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"o")==0)
        {
            if(y>5 || y<0 || x>9 || x<0)
            {
                UserError();
                err();
                continue;
            }
            else
            {
                for(i=y;i<y+5;i++)
                {
                    gridu[x][i]=naveA;
                    uposa[k][0]=x;
                    uposa[k][1]=i;
                    k++;
                }
                break;
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>5 || x<0 || y>9 || y<0)
            {
                UserError();
                err();
                continue;
            }
             else
            {
                for(i=x;i<x+5;i++)
                {
                    gridu[i][y]=naveA;
                    uposa[k][0]=i;
                    uposa[k][1]=y;
                    k++;
                }
                break;
            }
        }
    }
    k=0;
    cout << "\033[2J\033[0;0H"; //cls
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }

    /*B:Battleship*/

    for(;;)
    {
        chk=0;
        printf("Battleship (4):\n");
        printf("Orientamento(o/v): ");
        scanf("%s",&orin);
        printf("Coordinate x e y: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"o")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
            {
                UserError();
                err();
                continue;
            }
            else
            {

                for(i=y;i<y+4;i++)
                {
                    if(gridu[x][i]!=font)
                    {
                        UserError();
                        err();
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                    {
                        gridu[x][i]=naveB;
                        uposb[k][0]=x;
                        uposb[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                UserError();
                err();
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(gridu[i][y]!=font)
                    {
                        UserError();
                        err();
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                   for(i=x;i<x+4;i++)
                    {
                        gridu[i][y]=naveB;
                        uposb[k][0]=i;
                        uposb[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k=0;
    cout << "\033[2J\033[0;0H"; //cls
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }

    /*Destroyer*/
    for(;;)
    {
        chk=0;
        printf("Distruttrice (3):\n");
        printf("Orientamento(o/v): ");
        scanf("%s",&orin);
        printf("Coordinate x e y: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"o")==0)
        {
            if(y>7 || y<0 || x>9 || x<0)
            {
                UserError();
                err();
                continue;
            }
            else
            {
                for(i=y;i<y+3;i++)
                {
                    if(gridu[x][i]!=font)
                    {
                        UserError();
                        err();
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+3;i++)
                    {
                        gridu[x][i]=naveD;
                        uposd[k][0]=x;
                        uposd[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>7 || x<0 || y>9 || y<0)
            {
                UserError();
                err();
                continue;
            }
             else
            {
                 for(i=x;i<x+3;i++)
                {
                    if(gridu[i][y]!=font)
                    {
                        UserError();
                        err();
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+3;i++)
                    {
                        gridu[i][y]=naveD;
                        uposd[k][0]=i;
                        uposd[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k=0;
    cout << "\033[2J\033[0;0H"; //cls
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }

    /*Corvette*/

    for(;;)
    {
        chk=0;
        printf("Corvetta (2):\n");
        printf("Orientamento(o/v): ");
        scanf("%s",&orin);
        printf("Coordinate x e y: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"o")==0)
        {
            if(y>8 || y<0 || x>9 || x<0)
            {
                UserError();
                err();
                continue;
            }
            else
            {
                for(i=y;i<y+2;i++)
                {
                    if(gridu[x][i]!=font)
                    {
                        UserError();
                        err();
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+2;i++)
                    {
                        gridu[x][i]=naveC;
                        uposc[k][0]=x;
                        uposc[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>8 || x<0 || y>9 || y<0)
            {
                UserError();
                err();
                continue;
            }
             else
            {
                 for(i=x;i<x+2;i++)
                {
                    if(gridu[i][y]!=font)
                    {
                        UserError();
                        err();
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+2;i++)
                    {
                        gridu[i][y]=naveC;
                        uposc[k][0]=i;
                        uposc[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    cout << "\033[2J\033[0;0H"; //cls
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }
    printf("Premi ENTER per continuare!");
    fflush(stdin);
    puts(tempstr);
    srand(time(NULL));

    /*Aircraft carrier CPU*/

    for(;;)
    {
        if(rand()%2 == 1)
            strcpy(orin,"o");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"o")==0)
        {
            if(y>5 || y<0 || x>9 || x<0)
            {
                continue;
            }
            else
            {
                for(i=y;i<y+5;i++)
                    gridc[x][i]=naveA;
                break;
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>5 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                for(i=x;i<x+5;i++)
                    gridc[i][y]=naveA;
                break;
            }
        }
    }

    /*Battleship CPU*/

    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"o");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"o")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
                continue;
            else
            {
                for(i=y;i<y+4;i++)
                {
                    if(gridc[x][i]!=font)
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                        gridc[x][i]=naveB;
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(gridc[i][y]!=font)
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+4;i++)
                        gridc[i][y]=naveB;
                    break;
                }
            }
        }
    }

    /*Destroyer CPU*/

    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"o");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"o")==0)
        {
            if(y>7 || y<0 || x>9 || x<0)
            {
               continue;
            }
            else
            {
                for(i=y;i<y+3;i++)
                {
                    if(gridc[x][i]!=font)
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+3;i++)
                        gridc[x][i]=naveD;
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>7 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+3;i++)
                {
                    if(gridc[i][y]!=font)
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+3;i++)
                        gridc[i][y]=naveD;
                    break;
                }
            }
        }
    }

    /*Corvette CPU*/

    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"o");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"o")==0)
        {
            if(y>8 || y<0 || x>9 || x<0)
            {
                continue;
            }
            else
            {
                for(i=y;i<y+2;i++)
                {
                    if(gridc[x][i]!=font)
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+2;i++)
                        gridc[x][i]=naveC;
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>8 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+2;i++)
                {
                    if(gridc[i][y]!=font)
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+2;i++)
                        gridc[i][y]=naveC;
                    break;
                }
            }
        }
    }

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            griduv[i][j]=gridu[i][j];
    }
    for(;;)
    {
        cout << "\033[2J\033[0;0H"; //cls
        for(i=0;i<10;i++)
        {
            for(j=0;j<30;j++)
            printf(" ");
            if(i==0)
            {
                printf("  ");
                for(j=0;j<10;j++)
                printf("%d ",j);
                printf("\n");
                for(j=0;j<30;j++)
                printf(" ");
            }
            printf("%d ",i);
            for(j=0;j<10;j++)
                printf("%c ",gridcv[i][j]);
            printf("\n");
        }
        printf("\n");
        for(i=0;i<10;i++)
        {
            for(j=0;j<30;j++)
            printf(" ");
            if(i==0)
            {
                printf("  ");
                for(j=0;j<10;j++)
                printf("%d ",j);
                printf("\n");
                for(j=0;j<30;j++)
                printf(" ");
            }
            printf("%d ",i);
            for(j=0;j<10;j++)
                printf("%c ",griduv[i][j]);
            printf("\n");
        }

        for(;;)
        {
            printf("Attaca le navi:\n");
            printf("Inserire x and y: ");
            scanf("%d %d", &x,&y);
            if(x>9 || x<0 || y>9 || y<0 || gridcv[x][y]==colpito || gridcv[x][y]==mancato)
            {
                printf("Input invalido RIPROVA!!\n");
                continue;
            }
            else
            {
                if(gridc[x][y]==naveA || gridc[x][y]==naveB||gridc[x][y]==naveC||gridc[x][y]==naveD)
                {
                    if(gridcv[x][y]!=colpito)
                    {
                        gridcv[x][y]=colpito;
                        cout << "\033[2J\033[0;0H"; //cls
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",gridcv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",griduv[i][j]);
                            printf("\n");
                        }
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<10;j++)
                            {
                                if(gridcv[i][j]==colpito)
                                    win++;
                            }
                        }
                        if(win==14)
                        {
                            Win();
                            break;
                        }
                        win=0;
                        continue;
                    }
                    else
                    {
                        printf("Input invalido RIPROVA!!\n");
                        continue;
                    }
                }
                else
                {
                    gridcv[x][y]=mancato;
                    break;
                }
            }
        }

        for(;;)
        {
            probab=rand()%diff;
            if(probab==diff-3&& a<5)
            {
                x=uposa[a][0];
                y=uposa[a][1];
                a++;
            }
            else if(probab==diff-2 && b<4)
            {
                x=uposb[b][0];
                y=uposb[b][1];
                b++;
            }
            else if(probab==diff-5 && d<3)
            {
                x=uposd[d][0];
                y=uposd[d][1];
                d++;
            }
            else if(probab==diff-6 && c<2)
            {
                x=uposc[c][0];
                y=uposc[c][1];
                c++;
            }
            else
            {
                x=rand()%10;
                y=rand()%10;
            }
            if(x>9 || x<0 || y>9 || y<0 || griduv[x][y]==colpito || griduv[x][y]==mancato)
            {
                continue;
            }
            else
            {
                if(gridu[x][y]==naveA || gridu[x][y]==naveB||gridu[x][y]==naveC||gridu[x][y]==naveD)
                {
                    if(griduv[x][y]!=colpito)
                    {
                        griduv[x][y]=colpito;
                        cout << "\033[2J\033[0;0H"; //cls
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",gridcv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",griduv[i][j]);
                            printf("\n");
                        }
                        delay(1000);
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    griduv[x][y]=mancato;
                    break;
                }
            }

        }

        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(gridcv[i][j]==colpito)
                    win++;
            }
        }

        if(win==14)
        {
            Win();
            break;
        }
        win=0;

        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(griduv[i][j]==colpito)
                    win++;
            }
        }

        if(win==14)
        {
            Lose();
            break;
        }
        win=0;
    }
}