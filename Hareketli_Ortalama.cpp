/*
Ara�t�rma:Cansel �zkaya
Alogritma : Ahmet Y�lmaz
Kodlama: Kemal �zg�ren
Hata Ay�klama: Kemal �zg�ren
Kullan�c� Geri D�n���m�:Sibel Bilgin
*/
#include <iostream>
#include <clocale> 										//T�rk�e dil i�in k�t�phane
#include <fstream>										//girdi ve ��kt�lar� almak i�in k�t�phane
#include <vector>										//vector i�in k�t�phane
#include <windows.h>									//renklendirmek i�in gerekli
//#include <iomanip>									//setprescion kullanmak laz�m olur diye ekledim
using namespace std;									//std:: den kurtulal�m
int main(){
	setlocale(LC_ALL, "Turkish"); 						//Dili T�rk�e yapal�m
	system("Color 0A");									//renkler
													///Dosyadan veri �ekme ve dosyaya kaydetme
	ifstream veri("veriler.txt");						//verilerin al�naca�� dosya
	ofstream cikti("cikti.txt");						//kay�t olacak dosya
	if (!veri.is_open())								//! E�er veriler.txt dosyas� a��k de�ilse
	return (cout << "Dosya a��lamad�\n"), 1;
	vector<double> A;									//Ne kadar veri oldu�unu �nceden bilmedi�imiz i�in bir vekt�r kulland�m.
	for (double v ; veri >> v; A.push_back(v));			//Veriyi vekt�r�n arkas�na ekler.
													///Dosyadan veri �ekme bitti
	int aralik ; 										//Ka� b�lenli olaca��n� se�iyoruz
	double sum ;										//Toplam�
	do	{												//Do ile a�a��daki hatalardan birisi oldu�u zaman sorguya geri d�n�yor
			cout << "Ortalama aral���n� belirleyin: ";
			cin >> aralik;

			if(aralik<1)	{
				system("Color 04");
			cout << "1'den k���k de�er girilemez! L�tfen tekrar deneyiniz.\n\a";	
					}					
			if(aralik>A.size())	{
			cout << "Veri say�s�ndan fazla sorgu yapilamaz. Toplam Veri say�s� : " << A.size() << "\n\a";	
							}	
    		}
    			    	while(aralik>A.size() || aralik<1);
			system("Color 0A");
			cout<<"Gecerli Bir Sayi Girildi"<< "\n";						
	for (int i = 0; i < A.size(); ++i) {
		sum += A[i];
		if (i >= aralik) sum -= A[i - aralik];
		cout << "Sonu�[" << i << "]: " << sum / min( i + 1, aralik ) << '\n';
		cikti << "Sonu�[" << i << "]: "  <<sum / min(i + 1, aralik) << '\n';//Son olarak cikti.txt dosyam�za kaydediyoruz ve bitiriyoruz.
	}
	system("PAUSE");
}
