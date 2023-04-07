#include <iostream>
#include <opencv2/opencv.hpp>
// Bu algoritmayý çalýþtýrmak için bilgisayarýnýza OpenCV kütüpanesini indirmeniz gerekir aksi takdirde derleyiciniz hata verir ve çalýþmaz.

using namespace std;
using namespace cv;

int main()
{
	setlocale(LC_ALL, "Turkish");
	cout << "Renk iyileþtirme algoirtmalasý\n" <<;
    cout << "Görüntü iþleme alanýnda kullanýlan ve görüntüdeki renklerin kontrastný, parlaklðýný ve doygunluðunu arttýrmak ve azaltmak için tasarlanmýþ algoritmalardýr."<<;
    // input.jpg isimli bir jpg dosyasý yükledik
    Mat img = imread("input.jpg");

    // Görüntü boþsa, hata mesajý ver ve çýk
    if (img.empty()) 
    {
        cerr << "Görüntü yüklenemedi." << endl;
        return -1;
    }

    // Renk düzeltme yap
    Mat out;
    cvtColor(img, out, COLOR_BGR2HSV); // RGB renk uzayýndan HSV renk uzayýna dönüþtür
    vector<Mat> channels(3);
    split(out, channels);
    equalizeHist(channels[2], channels[2]); // V kanalýný histogram eþitleme ile düzelt
    merge(channels, out);
    cvtColor(out, out, COLOR_HSV2BGR); // HSV renk uzayýndan RGB renk uzayýna dönüþtür

    // Görüntüyü kaydet
    imwrite("output.jpg", out);

    // Baþarýlý olduðunu bildir
    cout << "Görüntü baþarýyla iþlendi ve kaydedildi." << endl;

    return 0;
}

