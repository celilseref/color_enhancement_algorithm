#include <iostream>
#include <opencv2/opencv.hpp>
// Bu algoritmay� �al��t�rmak i�in bilgisayar�n�za OpenCV k�t�panesini indirmeniz gerekir aksi takdirde derleyiciniz hata verir ve �al��maz.

using namespace std;
using namespace cv;

int main()
{
	setlocale(LC_ALL, "Turkish");
	cout << "Renk iyile�tirme algoirtmalas�\n" <<;
    cout << "G�r�nt� i�leme alan�nda kullan�lan ve g�r�nt�deki renklerin kontrastn�, parlakl��n� ve doygunlu�unu artt�rmak ve azaltmak i�in tasarlanm�� algoritmalard�r."<<;
    // input.jpg isimli bir jpg dosyas� y�kledik
    Mat img = imread("input.jpg");

    // G�r�nt� bo�sa, hata mesaj� ver ve ��k
    if (img.empty()) 
    {
        cerr << "G�r�nt� y�klenemedi." << endl;
        return -1;
    }

    // Renk d�zeltme yap
    Mat out;
    cvtColor(img, out, COLOR_BGR2HSV); // RGB renk uzay�ndan HSV renk uzay�na d�n��t�r
    vector<Mat> channels(3);
    split(out, channels);
    equalizeHist(channels[2], channels[2]); // V kanal�n� histogram e�itleme ile d�zelt
    merge(channels, out);
    cvtColor(out, out, COLOR_HSV2BGR); // HSV renk uzay�ndan RGB renk uzay�na d�n��t�r

    // G�r�nt�y� kaydet
    imwrite("output.jpg", out);

    // Ba�ar�l� oldu�unu bildir
    cout << "G�r�nt� ba�ar�yla i�lendi ve kaydedildi." << endl;

    return 0;
}

