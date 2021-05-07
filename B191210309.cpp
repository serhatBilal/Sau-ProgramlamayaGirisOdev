/****************************************************************************
**
**				ÖĞRENCİ ADI...........................:Serhat BİLAL
**				ÖĞRENCİ NUMARASI......................:B191210309
**				DERS GRUBU............................:1A
****************************************************************************/


#include <iostream>
#include <iomanip> 
#include <stdlib.h>

using namespace std;

void matrisOlustur(int matris[26][26], int matrisGirilenBoyut) //Matris oluşturma fonksiyonu
{
	cout << "  ";
	for (int i = 1; i <= matrisGirilenBoyut; i++) // Sutun sırası için 1'den girilen boyutun değerine kadar dönüp i değerini yazıyor.
	{
		cout << setw(3) << i ;
	}
	cout << endl;
	cout << "    ";

	for (int i = 1; i <=  matrisGirilenBoyut ; i++) //Tablo görünümü için 1'den girilen boyutun değerine kadar dönüp her değer için 3 tane "_"çizgi ekliyor. 
	{
		cout << "___";
	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < matrisGirilenBoyut; i++)//Matrisin sıralı satır numarası.
	{
		cout << setw(2) << i + 1 << "|" << setw(2);

		for (int j = 0; j < matrisGirilenBoyut; j++)
		{
			cout << setw(2) << matris[i][j] << " ";
		}
		cout << endl;
	}
	cout << "1.Sutun Satir Degistir" << endl;
	cout << "2.Tekleri Basa Al (Satir)" << endl;
	cout << "3.Ters Cevir (Sutun)" << endl;
	cout << "4.Toplamlari Yazdir" << endl;
}



int main() 
{

	srand(time(0));

	int matrisBoyut = 26;
	int ilkMatris[26][26];



	while (!((matrisBoyut <= 25) && (5 <= matrisBoyut))) //Matris boyutu 5 ile 25 arasında değil ise gireceği döngü
	{
		cout << "Matris boyutu:";
		cin >> matrisBoyut;
		cout << endl;

		if (!((matrisBoyut <= 25) && (5 <= matrisBoyut))) //Matris boyutu istenen değer aralığında olmadığında çıkacak uyarı.
		{
			cout << "Matris boyutu 5 ile 25 arasinda olmalidir." << endl;
		}
	}


	for (int i = 0; i < matrisBoyut; i++) 
	{

		for (int j = 0; j < matrisBoyut; j++) 
		{

			ilkMatris[i][j] = rand() % 9 + 1; //Matrisin içine rastgele 1-9 arası sayı atama.
		}
	}
	matrisOlustur(ilkMatris, matrisBoyut);



	int secim;

	while (5)
	{

		cin >> secim;
		switch (secim)
		{

		case 1: 
		{

			int satirDeger, sutunDeger;
			cout << endl;
			cout<< "Satir ve sutun degerlerini giriniz:";
			cin >> satirDeger;
			cin >> sutunDeger;
			cout << endl;
			int toplam = ilkMatris[satirDeger - 1][satirDeger - 1] + ilkMatris[sutunDeger - 1][sutunDeger - 1];


			if (satirDeger > matrisBoyut || sutunDeger > matrisBoyut) //Girilen satır ve sutun değerlerinin matris boyutundan büyük olması durumunda.
			{

				cout << endl << "Satir ve sutun matris boyutundan kucuk olmalidir." << endl;
				matrisOlustur(ilkMatris, matrisBoyut);
				break;
			}
			else // Girilen satır ve sutun değerlerinin matris boyutuna uygun olma durumu
			{

				int geciciMatris_1_Sutun[1][26], geciciMatris_1_Satir[1][26];

				for (int i = 0; i < matrisBoyut; i++) 
				{

					geciciMatris_1_Sutun[0][i] = ilkMatris[i][sutunDeger - 1];
				}


				for (int i = 0; i < matrisBoyut; i++) 
				{

					geciciMatris_1_Satir[0][i] = ilkMatris[satirDeger - 1][i];
				}


				for (int i = 0; i < matrisBoyut; i++)
				{

					ilkMatris[satirDeger - 1][i] = geciciMatris_1_Sutun[0][i];
				}


				for (int i = 0; i < matrisBoyut; i++)
				{

					ilkMatris[i][sutunDeger - 1] = geciciMatris_1_Satir[0][i];
				}

				ilkMatris[satirDeger - 1][sutunDeger - 1] = toplam;
				matrisOlustur(ilkMatris, matrisBoyut);
			}
			break;
		}


		case 2:
		{
			int satirNo;
			cout << endl << "Satir numarasi girin:";
			cin >> satirNo;
			cout << endl;

			if (satirNo > matrisBoyut) 
			{
				cout << endl << "Matris boyutundan buyuk girdiniz. Tekrar deneyin" << endl;
				cout << endl;
				matrisOlustur(ilkMatris, matrisBoyut);
				break;
			}
			else 
			{

				int geciciMatris_2[1][26];
				int hizala = 0; satirNo--;

				for (int i = 0; i < matrisBoyut; i++) 
				{

					if (ilkMatris[satirNo][i] % 2 == 1)
					{

						geciciMatris_2[0][hizala] = ilkMatris[satirNo][i];
						hizala++;
					}
				}

				for (int i = 0; i < matrisBoyut; i++) 
				{

					if (ilkMatris[satirNo][i] % 2 == 0)
					{

						geciciMatris_2[0][hizala] = ilkMatris[satirNo][i];
						hizala++;
					}
				}


				for (int i = 0; i < matrisBoyut; i++) 
				{

					ilkMatris[satirNo][i] = geciciMatris_2[0][i];
				}
				matrisOlustur(ilkMatris, matrisBoyut);
			}
			break;
		}


		case 3: 
		{

			int sutunNo;
			cout << endl << "Sutun numarasi girin:";
			cin >> sutunNo;
			cout << endl;

			if (sutunNo > matrisBoyut) 
			{

				cout << endl << "Matris boyutundan buyuk girdiniz. Tekrar deneyin" << endl;
				cout << endl;
				matrisOlustur(ilkMatris, matrisBoyut);
				break;
			}
			else {

				int geciciMatris_3[1][26];
				int hizala = 0;
				sutunNo--;

				for (int i = 0; i < matrisBoyut; i++) {

					geciciMatris_3[0][i] = ilkMatris[i][sutunNo];
				}

				for (int i = matrisBoyut - 1; i >= 0; i--) {

					ilkMatris[hizala][sutunNo] = geciciMatris_3[0][i];
					hizala++;
				}
				matrisOlustur(ilkMatris, matrisBoyut);;
			}
			break;
		}


		case 4: 
		{

			int toplamMatrisi[26][26];
			int toplam = 0;

			for (int i = 0; i < matrisBoyut; i++) {

				for (int j = 0; j < matrisBoyut; j++) {

					toplam += ilkMatris[i][j];
				}
			}
			toplamMatrisi[0][0] = toplam - ilkMatris[0][0];

			for (int i = 0; i < matrisBoyut; i++)
			{

				for (int j = 1; j < matrisBoyut; j++)
				{
					toplamMatrisi[i][j] = toplamMatrisi[i][j - 1] - ilkMatris[i][j];
				}
				toplamMatrisi[i + 1][0] = toplamMatrisi[i][matrisBoyut - 1] - ilkMatris[i + 1][0];
			}
			matrisOlustur(toplamMatrisi, matrisBoyut);
			break;
		}
		default:
			break;
		}
	}
	system("pause");
}

