#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //thirrrja e funksionit per ndryshimin e ngjyrave ne terminal

void menu(); //inicializimi i funksionit per shfaqjen e menuse kryesore

int main()
{
	int kodi = 1111; // Default password
	int kodiInput; // variabla per te mbajtur kodin qe vendos perdoruesi
	int veprimi; // variabla per te zgjedhur veprimet qe do kryhen 
	float futjaELekve, terheqjaELekve; // variablat per transaksionet
	float balanca = 0; // balanca qe mban shumen e parave qe ka perdoruesi ne llogarin e tij
	SetConsoleTextAttribute(h,75); // funksion per ndryshimin e ngjyres
	cout<<"A T M (Automated Teller Machine)\n\n";
	
	// cikel per te kontrolluar nqs kodi qe vendos perdoruesi eshte i sakte per te hyre ne aplikacion 
	SetConsoleTextAttribute(h,15); // funksion per ndryshimin e ngjyres
	do{
		SetConsoleTextAttribute(h,14);		
		cout<<"Ju lutem shkruani kodin per te hyre ne llogarine tuaj: (Default PW: 1111)\n";
		SetConsoleTextAttribute(h,15);
		cin >> kodiInput;
		if(kodi != kodiInput){
			SetConsoleTextAttribute(h,12);
			cout<<"Kodi qe vendoset nuk eshte i sakte!\n\n";
		}
	} while (kodi != kodiInput); 	
	SetConsoleTextAttribute(h,7);		
	
	// cikel per te rishfaqur menune kryesore sa here perfundon perdorimi i nje opsioni 	
	do{	
		menu(); // thirret menuja
		
		cout<<"Cfare veprimi do te kryeni?\n";
		cout<<"Shtypni 1,2,3,4 ose 5:\n";
		SetConsoleTextAttribute(h,15);
		cin >> veprimi; // merr nga perdoruesi nje numer per te zgjedhur opsionin qe do perdoret 
		
		system("cls"); // pstron komandat e meparshme ne terminal ne menyre qe gjithcka te jete e kuptueshme 
		
	// perdorim switch statement per te ditur se cilin opsion ka zgjedhur perdoruesi
	switch(veprimi){
	case 1: 
		do{ // cikel per te perseritur opsionin nqs shifra e vendosur nuk eshte te sakte
			SetConsoleTextAttribute(h,15);
			cout<<"Sa leke do te depozitoni? ";
			cin>>futjaELekve; // merr shifren qe vendos (depoziton) perdoruesi
			if(futjaELekve < 1){ // kontrollon nqs shifra e vendosur eshte e sakte 
				SetConsoleTextAttribute(h,12);
				cout<<"Shifra qe vendoset nuk eshte e sakte!"<<endl;
				cout<<"Per te kryer depozitimin e parave ju lutem vendosni nje shifer me te madhe se zero!\n";
			} else {
				SetConsoleTextAttribute(h,15); 
				balanca += futjaELekve; // shton ne balance shumen e futur nga perdoruesi
				cout<<"\nLlogaria juaj u be me "<< balanca << " lek\n";  // i shfaq perdoruesit se sa lek ka ne llogarine e tij
			}
		} while (futjaELekve < 0 || futjaELekve == 0);
		break;
	case 2: 
		do{ // cikel per te perseritur opsionin nqs shifra e vendosur nuk eshte te sakte
			SetConsoleTextAttribute(h,15);
			cout<<"Sa lek do te terhiqni? ";
			cin>>terheqjaELekve; // merr shifren qe deshiron te terheqe perdoruesi
			if(terheqjaELekve < 0 || terheqjaELekve == 0){ // kontrollon nqs shifra e vendosur eshte e sakte
			SetConsoleTextAttribute(h,12);
				cout<<"Shifra qe vendoset nuk eshte e sakte! Ju nuk mund te terhiqni me pak se 1 Lek!"<<endl;
			} else if (terheqjaELekve > balanca){
			SetConsoleTextAttribute(h,12);
				cout<<"\nJu nuk keni para mjaftueshem per te kryer kete veprim.\n"<<endl;
			} else {
				balanca -= terheqjaELekve; // heq nga balanca vleren e futur nga perdoruesi
				SetConsoleTextAttribute(h,15);
				cout<<"Llogaria juaj aktuale eshte: "<< balanca << " lek"<<endl;
			}
		} while (terheqjaELekve < 0 || terheqjaELekve == 0);
		break;
	case 3: 
	SetConsoleTextAttribute(h,10);
		cout<<"Llogaria juaj aktuale ka " << balanca << " lek.\n";
		break;
	case 4: 
	{
		SetConsoleTextAttribute(h,15);
		int *kodiptr, kodi2; // deklarimi i nje variabli dhe nje variabli tjt te tipit poiter
		cout<<"Vendos kodin e ri (perdorni numerat nga 1-9): ";
		cin>>kodi2; 
		int size = trunc(log10(kodi2)) + 1; // me kete funksion gjejme gjatesine e kodit
		while (size > 6){ // kontrollojme nqs kodi i ri perputhet me kerkesen tone qe te mos jete me shume se 6 karaktere
			SetConsoleTextAttribute(h,12);
			cout<<"Kodi nuk duhet te jete me me shume se 6 karaktere\n";
			SetConsoleTextAttribute(h,15);
			cout<<"Ju lutem shkruani kodin e ri perseri:\n";
			cin>>kodi2;
			int size = trunc(log10(kodi2)) + 1;	// kontrollojme perseri gjatesine e kodit te ri
			if(size < 7){
				break;
			}
		}

		// inicializojme variblin fillestar qe mban kodin me kodin e ri
		kodiptr = &kodi2;
		kodi = *kodiptr;
		
		do{ // i japim mundesi perdoruesit te shkruaj kodin e ri ne menyre qe te hyje te llogaria e tij 
		SetConsoleTextAttribute(h,15);
		cout<<"Ju lutem shkruani kodin per te hyre ne llogarine tuaj:\n";
			cin >> kodiInput;
			if(kodi != kodiInput){
				SetConsoleTextAttribute(h,12);
				cout<<"Kodi qe vendoset nuk eshte i sakte!\n\n";
			}
		} while (kodi != kodiInput); 
		
		system("cls");
		break;
	}
	SetConsoleTextAttribute(h,15); // funksion per ndryshimin e ngjyres
	case 5: 
		SetConsoleTextAttribute(h,13);
		cout<<"Faleminderit per perdorimin e aplikacionit";
		break;
	default: 
	SetConsoleTextAttribute(h,12);
		cout<<"Opsioni qe zgjodhet nuk ekziston!\n";
	}
	} while(veprimi != 5);
	
	return 0;
}

// funksioni per shfaqjen e menuse
void menu(){
	SetConsoleTextAttribute(h,11);
	cout<<"\n************** MENU **************"<<endl;
	cout<<"1. Depozitim\n";
	cout<<"2. Terheqje\n";
	cout<<"3. Verifikim bilanci\n";
	cout<<"4. Ndryshim i kodit\n";
	cout<<"5. Dil nga programi\n";
	cout<<"**********************************"<<endl;
}

