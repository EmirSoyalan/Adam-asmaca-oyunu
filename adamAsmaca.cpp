#include <iostream>
#include <conio.h>
#include <vector>
#include <unistd.h> 

using namespace std;
void resim(int kalanHak);

int main(){
	setlocale(LC_ALL,"Turkish");
	string kelime;
	int kacTane;
	vector<bool> bilinenHarf;
	char harf;
	bool oyunDevamEdiyor = false;
	bool tekrarOyna = false;
	bool zafer = false;
	int secim;
	int kalanHak;
	
	
	do{
		kalanHak = 5;
		kacTane = 0;
		cout << "*** Adam Asmaca ***" << endl << endl;
		cout << "Kelimeyi giriniz: ";
		cin >> kelime;
		cout << endl;
		for(int i = 0; i < kelime.length(); i++){
			bilinenHarf.push_back(i);
			bilinenHarf[i] = false;
		}
		system("cls");
		do{
			resim(kalanHak);
			oyunDevamEdiyor = false;
			zafer = true;
			for(int i = 0; i < kelime.length(); i++){
				if(bilinenHarf[i])
					cout << kelime.at(i) << " ";	
				else
					cout << "_ ";
			}
			cout << "\n\nHarf giriniz: ";
				cin >> harf;
				kacTane = 0;
				for(int i = 0; i < kelime.length(); i++){
					if(harf == kelime.at(i)){
						if(bilinenHarf[i]){
							cout << "\nBu harf zaten denenmiþ.";
							break;
						}
						kacTane++;
						bilinenHarf[i] = true;
					}
				}
				
			if(kacTane == 0){
				kalanHak--;
				if(kalanHak==0){
					oyunDevamEdiyor=false;
					zafer = false;
					cout << "\nBütün haklarýnýz bitti!";
					sleep(1);
					system("cls");
					break;
				}
				cout << "\nYanlýþ harf! Kalan hak: " << kalanHak;
			}
			else{
				cout << "\nKelimede " << kacTane << " tane " << harf << " harfi var";
			}
			sleep(1);
			system("cls");
			for(int i = 0; i < kelime.length(); i++){
				if(!bilinenHarf[i]){
					oyunDevamEdiyor = true;
					zafer = false;
				}
			}
		}while(oyunDevamEdiyor);
		cout << "Kelime: " << kelime << endl << endl;
		string mesaj = zafer ? "Kazandýnýz!": "Kaybettiniz";
		cout << mesaj <<"\n1-Tekrar oyna\nn-Çýkýþ\n\nSeçim: ";
		cin >> secim;
		tekrarOyna = (secim==1) ? true : false;
		system("cls");
	}while(tekrarOyna);
	cout << "Goodbye...";
	sleep(1);
	return 0;
}



void resim(int kalanHak){
	cout << " ______" << endl;
			cout << " |     |" << endl;
			cout << " |     | "  << endl;
	switch(kalanHak){
		case 1:
			
			cout << " |     O " << endl;
			cout << " |     | "<< endl;
			cout << " |       " << endl;
			break;
		case 2:
			cout << " |     O " << endl;
			cout << " |     | "<< endl;
			cout << " |    /  " << endl;
			break;
		case 3:
			cout << " |     O   " << endl;
			cout << " |     |\\ "<< endl;
			cout << " |    /    " << endl;
			break;
		case 4:
			cout << " |     O   " << endl;
			cout << " |    /|\\ "<< endl;
			cout << " |    /    " << endl;
			break;
		case 5:
			cout << " |     O   " << endl;
			cout << " |    /|\\ "<< endl;
			cout << " |    / \\   " << endl;
			break;
	}
	cout << "/|\\ " << endl << endl;
}
