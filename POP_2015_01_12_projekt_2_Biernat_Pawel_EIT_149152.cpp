
						//POP 2015-01-12 projekt 2 Biernat Pawel EIT  149152      Dev-C++ 5.4.0
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

void deszyfrowanie(char tablica[], const int rozmiar)
{
	
	fstream plik;
	cout << "twoj tekst:" << endl;
	plik.open("tekst.txt");
											//wczytywanie tekstu z pliku do tablicy
	do
	{
		plik.getline(tablica, rozmiar);
		cout << tablica << endl;
	}
	while(!plik.eof());
	
	cout << endl;
	
	int x;													//podajemy klucz, aby odszyfrowac tekst
	cout << endl << "podaj klucz (przesuniecie) od 1 do 25: " << endl;
    cin >> x;
	
	if(plik.eof()) 			
    {
        plik.clear();		//skasowanie flagi konca pliku
        plik.seekg(0);		 // ustawienie wskaznika czytania na poczatek pliku
    }

 	do                                         
	{
	 	plik.getline(tablica, rozmiar);
        int dlugosc = strlen(tablica); //okreslamy ilosc znakow do zdeszyfrowania
        
		for(int i = 0 ; i < dlugosc ; i++)
        {
           if (tablica[i] >= 65 && tablica[i] <= 90)			//wielkie litery
			{
				if (tablica[i] - 65 - x < 0)
				tablica [i] = tablica[i] + (26 - x);
				else tablica[i] = (tablica[i] - 65 - x) % 26 + 65;
			}
			
		
			else if (tablica[i] >= 97 && tablica[i] <= 122)      //male litery
			{
				if (tablica[i] - 97 - x < 0)
				tablica [i] = tablica[i] + (26 - x);
				else tablica[i] = (tablica[i] - 97 - x) % 26 + 97;
			}
	
			else if (tablica[i]!=44 && tablica[i]!=32 && tablica[i]!=46 && tablica[i]!=63)    // zostawiamy znaki interpunkcyjne
			{
				tablica[i] = '!';          // polskie znaki i inne niepozadane
			}
				
            
        }
       
	    cout << tablica << endl;
    
	}while(!plik.eof());
}

//********************************************************************************************
void szyfrowanie(char tablica[], const int rozmiar)
{
	
	fstream plik;
	cout << "twoj tekst:" << endl;
	plik.open("tekst.txt");
													//wczytywanie tekstu z pliku do tablicy
	do
	{
		plik.getline(tablica, rozmiar);
		cout << tablica << endl;
	}
	while(!plik.eof());
	
	cout << endl;
	
	int x;																	//podajemy klucz jakim chcemy zaszyfrowac
	cout << endl << "podaj klucz (przesuniecie) od 1 do 25: " << endl;
    cin >> x;
	
	 if(plik.eof()) 
    {
        plik.clear();     //skasowanie flagi konca pliku
        plik.seekg(0); 	// ustawienie wskaznika czytania na poczatek pliku
    }

 	do
	{
		plik.getline(tablica, rozmiar);
        int dlugosc = strlen(tablica);               		//okreslamy ilosc znakow do zaszyfrowania
        for(int i = 0 ; i < dlugosc ; i++)
        {
           if(tablica[i]!= ' ')          // pomijamy spacje
            {
                if (tablica[i] >= 65 && tablica[i] <= 90)  // wielkie litery
                        tablica[i] = (tablica[i] - 65 + x) % 26 + 65;

                else if (tablica[i] >= 97 && tablica[i] <= 122)  //male litery
                        tablica[i] = (tablica[i] - 97 + x) % 26 + 97;

                else  if(tablica[i] != 44  && tablica[i] != 46 && tablica[i] != 63)       //interpunkcja
                        tablica [i] = '!';          //  znaki polskie i pozostale
            }
        }
        
		cout << tablica << endl;
    
	}while(!plik.eof());
	
	
}

//**********************************************************************************************
void nieznany_klucz(char tablica[], const int rozmiar)
{
	
	fstream plik;
	cout << "twoj tekst:" << endl;
	plik.open("tekst.txt");
											//wczytywanie
	do
	{
		plik.getline(tablica, rozmiar);
		cout << tablica << endl;
	}
	while(!plik.eof());
	
	cout << endl;
	
	int x = 1;                      //pierwsze przesuniecie
	int ost_przesuniecie = 26;
	while(x < ost_przesuniecie)
	{
	
		if(plik.eof()) 
    	{
        	plik.clear();	//skasowanie flagi konca pliku
        	plik.seekg(0); // ustawienie wskaznika czytania na poczatek pliku
    	}

 		do
		{
			plik.getline(tablica, rozmiar);
        	int dlugosc = strlen(tablica);                    //okreslenie ilosci znakow
        	for(int i = 0 ; i < dlugosc ; i++)
        	{
           		if (tablica[i] >= 65 && tablica[i] <= 90)
				{
					if (tablica[i] + x >= 65 && tablica[i] + x <= 90)
					tablica [i] += x;
					else tablica[i] = tablica[i] + x - 26;
				}
			 
		
				else if (tablica[i] >= 97 && tablica[i] <= 122)
				{
					if (tablica[i] + x >= 97 && tablica[i] + x <=122)
					tablica [i] += x;
					else tablica[i] = tablica[i] + x - 26;
				}
            
        	}
        
		  cout << tablica << endl;
    
		}while(!plik.eof());
		
		cout << endl;
    
		x++;        //zwiekszamy przesuniecie
	}
	
	cout << endl << "aby poznac klucz, policz od konca, az dojdziesz do pozycji prawidlowo rozszyfrowanego tekstu :)";
}

//***************************************************************************************
int main ()
{

const int rozmiar = 500;
char tablica[rozmiar];
int opcja;

cout << "szyfrowanie - wpisz 1, deszyfrowanie - 2, nieznany klucz - 3" << endl;
cin >> opcja;

if (opcja==1)
szyfrowanie(tablica, rozmiar);
else if(opcja==2)
deszyfrowanie(tablica, rozmiar); 
else if(opcja==3) 
nieznany_klucz(tablica, rozmiar);
else cout << "zla wartosc!";

return 0;
}
