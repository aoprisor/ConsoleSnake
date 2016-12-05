//contine bug-uri 


#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>

using namespace std;

////harta pe care se plimba snak-ul
char map[20][20]={"###################",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "#                 #",
                  "###################"};

int lungime=5;//lungime de start

 struct snake{
	 int linie;
	 int coloana;
};
struct snake v[10];//marime maxima
 
int vlinie[10];
int vcoloana[10];
int punctcoloana=14; //mancarea coordonata coloana 
int punctlinie=16;//mancare coordonata linie
int viteza=500;
bool game=true;


void afisare(char harta[20][20]); //functia carw afiseaza harta // poate fi optimizata(se poate afisa cu un singur for matricea daca se folosesc adresele elementelor)
void Display();//asa cum ii spune numele introduce in matrice corpul sarpelui si mancarea, inainte de asta curata harta complet de elementele ramase din ciclul anterior 
bool verifica();//se verifica daca sarpele a atins peretele sau daca a luat mancarea
void sus();//comenzi care misca sarpele in directia spusa de numele functiei
void jos();
void stanga();
void dreapta();

int main(){
	//initializare corp sarpe
int i=0;
char c;

	for(i=0; i<10; i++){
		vlinie[i]=1;//punctele de plecare ale sarpelui
		vcoloana[i]=3;
		v[i].linie=vlinie[i];
		v[i].coloana=vcoloana[i];
	}

   system("color 74");
   cout<<"\n\n\n\n\n\t\t\tApasa d ca sa inceapa jocul!";

	 while(game)  {
	 
	 char temp;
	 temp=getch();
	 if(temp=='a'||temp=='d'||temp=='s'||temp=='w') c=temp;
	 
	system("cls");
	
	  switch(c){
		case 'w':
		sus();
			break;
		case 's':
		jos();
			break;
       case 'a':
        stanga();
			break;
		case 'd':
		dreapta();
          break;
      }

	
 
}
    	afisare(map);
		Sleep(1000);
		system("cls");
		cout<<"\n\n\n\n\n\t\t\tAi pierdut!\n";
	 
	      system("PAUSE");
	      return 0;		
	}
	
void afisare(char harta[20][20]){
	for(int i=0;i<20;i++)
	          for(int j=0;j<20;j++){
	          cout<<map[i][j];if(j==19) cout<<endl;}}


void Display(){
	
for(int i=0;i<20;i++)
	          for(int j=0;j<20;j++){
	          	if(map[i][j]!='#') map[i][j]=' ';			  } //se curata harta de elementele din ciclul anterior
	          	
	for(int i=0;i<lungime; i++){
	map[v[i].linie][v[i].coloana]='*';}// se adauga pozitia sarpelui
	map[punctlinie][punctcoloana]='@';//se adauga mancarea


}

bool verifica(){
	   
	   for(int i=1; i<lungime; i++){
	   	if(v[0].linie==v[i].linie&&v[0].coloana==v[i].coloana) return false;
	   }
	   if(v[0].linie==punctlinie&&v[0].coloana==punctcoloana) {
	   
	   lungime++; viteza-=50;
	   
	   srand(time(NULL));
	   punctlinie=rand()%17+1;
	   punctcoloana=rand()%17+1;
}
	   
	   if(v[0].coloana==18||v[0].coloana==0||v[0].linie==18||v[0].linie==0){
       map[v[0].linie][v[0].coloana]='x';
return false;}
else return true;
}

void sus(){
		do{
			
			for(int i=1;i<lungime;i++){
				v[i].linie=vlinie[i-1];
				v[i].coloana=vcoloana[i-1];	
			}
         v[0].linie--;
            for(int i=0; i<lungime; i++){
            	vlinie[i]=v[i].linie;
            	vcoloana[i]=v[i].coloana;
		}
		Display();
		system("cls");
		game=verifica();
		if(game==false) break;
		afisare(map);
		Sleep(viteza);
		}while(kbhit()==0);
}

void jos(){
do{
				for(int i=1;i<lungime;i++){
				v[i].linie=vlinie[i-1];
				v[i].coloana=vcoloana[i-1];	
			}
        v[0].linie++;
            for(int i=0; i<lungime; i++){
            	vlinie[i]=v[i].linie;
            	vcoloana[i]=v[i].coloana;
			}
			Display();
			system("cls");
			game=verifica();
			if(game==false) break;
		    afisare(map);
		    Sleep(viteza);
			}while(kbhit()==0);	
}

void stanga(){
	do{
			for(int i=1;i<lungime;i++){
				v[i].linie=vlinie[i-1];
				v[i].coloana=vcoloana[i-1];	
			}
        v[0].coloana--;
            for(int i=0; i<lungime; i++){
            	vlinie[i]=v[i].linie;
            	vcoloana[i]=v[i].coloana;
			}
			Display();
			system("cls");
			game=verifica();
			if(game==false) break;
		    afisare(map);
		    Sleep(viteza);
			}while(kbhit()==0);
}

void dreapta(){
	do{
			for(int i=1;i<lungime;i++){
				v[i].linie=vlinie[i-1];
				v[i].coloana=vcoloana[i-1];	
			}
        v[0].coloana++;
            for(int i=0; i<lungime; i++){
            	vlinie[i]=v[i].linie;
            	vcoloana[i]=v[i].coloana;
			}
			Display();
			system("cls");
			game=verifica();
			if(game==false) break;
		    afisare(map);
		    Sleep(viteza);
			}while(kbhit()==0);
}
