/*
Petra Šporèiæ, R4
Zadaæa - UVOD U RAÈUNALNE MREŽE
29.01.2020.
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <bitset>
#include <cmath>
using namespace std;


string ipA = "10.0.0.0";
string subnet = "255.0.0.0";
string klasa;


int main() {
	int dalje;
	int brojUredjaja = 0;
	int izbor;
	do
	{
	do {
		cout << "APLIKACIJA ZA SUBNETIRANJE -Petra Sporcic, R4" << endl << endl; 
		cout << "1. Pomocu IP adrese i subnet maske izracunaj adresu mreze, prvu korisnu IP adresu, zadnju korisnu IP adresu i broadcast IP adresu." << endl << endl;
		cout << "2. Na temelju broja uredaja koji ce biti spojeni na mrezu odredi adresu mreze i subnet masku." << endl;


		cin >> izbor;

	} while (izbor != 1 && izbor != 2 );
	system("cls");
	if (izbor == 1) {
		// Ip adresa
		int ipPolje[4];
		int flag = 0;
		do
		{
			if (flag == 1) {
				cout << "Greska kod unosa IP adrese." << endl;
		}
		cout << "Unesite IP adresu: ";
		cin>> ipA;

		
		ipPolje[0] = 0;
		ipPolje[1] = 0;
		ipPolje[2] = 0;
		ipPolje[3] = 0;
		int redBroj = 0;
		
		for (int j = 0; j < ipA.length(); j++)
		{

			if (ipA[j] == '.') {
				redBroj += 1;
			}
			else {
				ipPolje[redBroj] = ipPolje[redBroj] * 10 + ipA[j] - '0';
			}

			if ((ipPolje[0] == 10 && ipPolje[1] >= 0 && ipPolje[1] <= 255 && ipPolje[2] >= 0 && ipPolje[2] <= 255 && ipPolje[3] >= 0 && ipPolje[3] <= 255) ||
				(ipPolje[0] == 172 && ipPolje[1] == 16 && ipPolje[2] >= 0 && ipPolje[2] <= 31 && ipPolje[3] >= 0 && ipPolje[3] <= 255) ||
				(ipPolje[0] == 192 && ipPolje[1] == 168 && ipPolje[2] >= 0 && ipPolje[2] <= 255 && ipPolje[3] >= 0 && ipPolje[3] <= 255)) {
				flag = 0;
			}
			else {
				flag = 1;
			}

		}
		} while (flag);

		//KLASE
		if (ipPolje[0] == 10 && ipPolje[1] >= 0 && ipPolje[1] <= 255 && ipPolje[2] >= 0 && ipPolje[2] <= 255 && ipPolje[3] >= 0 && ipPolje[3] <= 255)
		{
			klasa = "Klasa A";
		}
		if (ipPolje[0] == 172 && ipPolje[1] == 16 && ipPolje[2] >= 0 && ipPolje[2] <= 31 && ipPolje[3] >= 0 && ipPolje[3] <= 255)
		{
			klasa = "Klasa B";

		}
		if (ipPolje[0] == 192 && ipPolje[1] == 168 && ipPolje[2] >= 0 && ipPolje[2] <= 255 && ipPolje[3] >= 0 && ipPolje[3] <= 255)
		{
			klasa = "Klasa C";
		}

		
		// Subnet maska
		int subnetPolje[4];
		do
		{
		if (flag == 1) {
				cout << "Greska kod unosa subnet maske." << endl;
			}
		cout << "Unesite Subnet masku: ";
		cin >> subnet;
		

		subnetPolje[0] = 0;
		subnetPolje[1] = 0;
		subnetPolje[2] = 0;
		subnetPolje[3] = 0;
		int redBroj = 0;
		for (int j = 0; j < subnet.length(); j++)

		{
			if (subnet[j] == '.') {
				redBroj += 1;
			}
			else {
				subnetPolje[redBroj] = subnetPolje[redBroj] * 10 + subnet[j] - '0';
			}
		}

		if ((klasa=="Klasa A" && subnetPolje[0]==255 && subnetPolje[1]>=0 && subnetPolje[1]<=255 && subnetPolje[2] >= 0 && subnetPolje[2] <= 255 && subnetPolje[3] >= 0 && subnetPolje[3] <= 255) ||
			(klasa == "Klasa B" && subnetPolje[0] == 255 && subnetPolje[1] == 255 && subnetPolje[2] >= 0 && subnetPolje[2] <= 255 && subnetPolje[3] >= 0 && subnetPolje[3] <= 255) || 
			(klasa == "Klasa C" && subnetPolje[0] == 255 && subnetPolje[1] == 255 && subnetPolje[2] == 255 && subnetPolje[3] >= 0 && subnetPolje[3] <= 255)) {
			flag = 0;
		}
		else {
			flag = 1;
		}

		} while (flag);

	

		int  mrezniIP1 = ((ipPolje[0]) & (subnetPolje[0]));
		int  mrezniIP2 = ((ipPolje[1]) & (subnetPolje[1]));
		int  mrezniIP3 = ((ipPolje[2]) & (subnetPolje[2]));
		int  mrezniIP4 = ((ipPolje[3]) & (subnetPolje[3]));
		cout << endl;
		cout << "Subnet maska: ";
		for (int j = 0; j < 3; j++)
		{
			cout << subnetPolje[j] << ".";
		} cout << subnetPolje[3] << endl;


		cout << "IP adresa: ";
		for (int j = 0; j < 3; j++)
		{
			cout << ipPolje[j] << ".";
		} cout << ipPolje[3] << endl;


		cout << "Klasa: " << klasa << endl;
		cout << "Binarni zapis IP adrese: " << bitset<8>(ipPolje[0]) << "." << bitset<8>(ipPolje[1]) << "." << bitset<8>(ipPolje[2]) << "." << bitset<8>(ipPolje[3]) << endl;
		cout << "Binarni zapis subnet mreze: " << bitset<8>(subnetPolje[0]) <<"." << bitset<8>(subnetPolje[1]) << "."<< bitset<8>(subnetPolje[2]) <<"." << bitset<8>(subnetPolje[3]) <<endl;
		cout << "Mrezna adresa: " << mrezniIP1 << "." << mrezniIP2 << "." << mrezniIP3 << "." << mrezniIP4 <<endl;
		cout << "Prva korisna: " << mrezniIP1 << "." << mrezniIP2 << "." << mrezniIP3 << "." << mrezniIP4 + 1 << endl;
		cout << "Broadcast: " << mrezniIP1 + (255 - subnetPolje[0]) << "." << mrezniIP2 + (255 - subnetPolje[1]) << "." << mrezniIP3 + (255 - subnetPolje[2]) << "." << mrezniIP4 + (255 - subnetPolje[3]) << endl;
		cout << "Zadnja korisna: " << mrezniIP1 + (255 - subnetPolje[0]) << "." << mrezniIP2 + (255 - subnetPolje[1]) << "." << mrezniIP3 + (255 - subnetPolje[2]) << "." << mrezniIP4 + (255 - subnetPolje[3]) - 1 << endl;
		cout << "Host raspon od " << ipPolje[0] << "." << ipPolje[1] << "." << ipPolje[2] << "." << ipPolje[3] + 1 << " do " << mrezniIP1 + (255 - subnetPolje[0]) << "." << mrezniIP2 + (255 - subnetPolje[1]) << "." << mrezniIP3 + (255 - subnetPolje[2]) << "." << mrezniIP4 + (255 - subnetPolje[3]) - 1 << endl;
		cout << endl;
	}
	if (izbor==2)
	{
		
	//OPCIJA 4
	int ipPolje[4];
	int subnetPolje[4];
	do
	{
		cout << "Unesite broj uredjaja koje zelite spojiti na mrezu: ";
		cin >> brojUredjaja;

	} while (brojUredjaja<0 || brojUredjaja>=16777214);
	cout << endl;
	if (brojUredjaja>0 && brojUredjaja <254)
	{
		klasa = "Klasa C";
		ipPolje[0] = 192;
		ipPolje[1] = 168;
		ipPolje[2] = 0;
		ipPolje[3] = 0;		
	}
	
	if (brojUredjaja>=254 && brojUredjaja <65534)
	{
		klasa = "Klasa B";
		ipPolje[0] = 172;
		ipPolje[1] = 16;
		ipPolje[2] = 0;
		ipPolje[3] = 0;
	}
	if (brojUredjaja>=65534 && brojUredjaja <16777214)
	{
		klasa = "Klasa A";
		ipPolje[0] = 10;
		ipPolje[1] = 0;
		ipPolje[2] = 0;
		ipPolje[3] = 0;
	}

	int brojac = 0;
	for (int i = brojUredjaja +2; i > 0; i/=2)
	{
		brojac++;
	}
	
	unsigned int a= pow(2, 32) - 2;
	unsigned int b = pow(2, brojac) - 2;

	unsigned int jediniceUSubnetu = a ^ b;

	

	for (int i = 0; i < 4; i++)
	{
		subnetPolje[i] = jediniceUSubnetu % (int)pow(2, 8);
		jediniceUSubnetu /= (int)pow(2, 8);
	}
	

	//ISPIS
	cout << "Subnet maska: ";
	for (int i = 3; i >= 0; i--)
	{
		cout << subnetPolje[i] << ".";
	}
	cout << endl;

	//PRVA KORISNA

	cout << "Klasa: " << klasa << endl;
	cout << "Binarni zapis IP adrese: " << bitset<8>(ipPolje[0]) << "." << bitset<8>(ipPolje[1]) << "." << bitset<8>(ipPolje[2]) << "." << bitset<8>(ipPolje[3]) << endl;
	cout << "Binarni zapis subnet mreze: " << bitset<8>(subnetPolje[3]) <<"."<< bitset<8>(subnetPolje[2]) <<"."<< bitset<8>(subnetPolje[1]) << "."<< bitset<8>(subnetPolje[0]) << endl;
	cout << "Mrezna adresa: " << ipPolje[0] << "." << ipPolje[1] << "." << ipPolje[2] << "." << ipPolje[3] << endl;
	cout << "Prva korisna: " << ipPolje[0] << "." << ipPolje[1] << "." << ipPolje[2] << "." << ipPolje[3] + 1 << endl;
	cout << "Broadcast: " << ipPolje[0] + (255 - subnetPolje[3]) << "." << ipPolje[1] + (255 - subnetPolje[2]) << "." << ipPolje[2] + (255 - subnetPolje[1]) << "." << ipPolje[3] + (255 - subnetPolje[0]) << endl;
	cout << "Zadnja korisna: " << ipPolje[0] + (255 - subnetPolje[3]) << "." << ipPolje[1] + (255 - subnetPolje[2]) << "." << ipPolje[2] + (255 - subnetPolje[1]) << "." << ipPolje[3] + (255 - subnetPolje[0]) - 1 << endl;
	cout << "Host bitova: " << brojac << endl;
	cout << "CIDR: /" << 32 - brojac << endl;
	cout << "Ukupno rezervirano: " << b << endl;
	cout << "Host raspon od " << ipPolje[0] << "." << ipPolje[1] << "." << ipPolje[2] << "." << ipPolje[3] + 1 << " do " << ipPolje[0] + (255 - subnetPolje[3]) << "." << ipPolje[1] + (255 - subnetPolje[2]) << "." << ipPolje[2] + (255 - subnetPolje[1]) << "." << ipPolje[3] + (255 - subnetPolje[0]) - 1 << endl;
	cout << endl;
	}

	cout << "Zelite li ponoviti unos? " << endl << "1. Zelim nastaviti subnetirati." << endl << "2. Izlaz" <<endl;
	cin >> dalje;
	system("cls");
		} while (dalje==1);


	return 0;
}