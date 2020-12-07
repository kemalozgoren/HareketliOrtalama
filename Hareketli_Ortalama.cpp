/*
Araþtýrma:Cansel Özkaya
Alogritma : Ahmet Yýlmaz
Kodlama: Kemal Özgören
Hata Ayýklama: Kemal Özgören
Kullanýcý Geri Dönüþümü:Sibel Bilgin
*/
#include <iostream>
#include <clocale> 										//Türkçe dil için kütüphane
#include <fstream>										//girdi ve çýktýlarý almak için kütüphane
#include <vector>										//vector için kütüphane
#include <windows.h>									//renklendirmek için gerekli
//#include <iomanip>									//setprescion kullanmak lazým olur diye ekledim
using namespace std;									//std:: den kurtulalým
int main(){
	setlocale(LC_ALL, "Turkish"); 						//Dili Türkçe yapalým
	system("Color 0A");									//renkler
													///Dosyadan veri çekme ve dosyaya kaydetme
	ifstream veri("veriler.txt");						//verilerin alýnacaðý dosya
	ofstream cikti("cikti.txt");						//kayýt olacak dosya
	if (!veri.is_open())								//! Eðer veriler.txt dosyasý açýk deðilse
	return (cout << "Dosya açýlamadý\n"), 1;
	vector<double> A;									//Ne kadar veri olduðunu önceden bilmediðimiz için bir vektör kullandým.
	for (double v ; veri >> v; A.push_back(v));			//Veriyi vektörün arkasýna ekler.
													///Dosyadan veri çekme bitti
	int aralik ; 										//Kaç bölenli olacaðýný seçiyoruz
	double sum ;										//Toplamý
	do	{												//Do ile aþaðýdaki hatalardan birisi olduðu zaman sorguya geri dönüyor
			cout << "Ortalama aralýðýný belirleyin: ";
			cin >> aralik;

			if(aralik<1)	{
				system("Color 04");
			cout << "1'den küçük deðer girilemez! Lütfen tekrar deneyiniz.\n\a";	
					}					
			if(aralik>A.size())	{
			cout << "Veri sayýsýndan fazla sorgu yapilamaz. Toplam Veri sayýsý : " << A.size() << "\n\a";	
							}	
    		}
    			    	while(aralik>A.size() || aralik<1);
			system("Color 0A");
			cout<<"Gecerli Bir Sayi Girildi"<< "\n";						
	for (int i = 0; i < A.size(); ++i) {
		sum += A[i];
		if (i >= aralik) sum -= A[i - aralik];
		cout << "Sonuç[" << i << "]: " << sum / min( i + 1, aralik ) << '\n';
		cikti << "Sonuç[" << i << "]: "  <<sum / min(i + 1, aralik) << '\n';//Son olarak cikti.txt dosyamýza kaydediyoruz ve bitiriyoruz.
	}
	system("PAUSE");
}
