#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "pbplots/pbPlots.h"
#include "pbplots/supportLib.h"

#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )

int histogram_ciz(int histogram[])
{
    
    double xs[257];
    double ys[257];
    //double xs2[2];
    //double ys2[2];

    for (int i = 0; i < 256; i++)
        xs[i] = (double)i;

    for (int i = 0; i < 254; i++)
        ys[i] = (double)histogram[i];

    ys[255] = histogram[255];

    //xs2[0] = xs[254];
    //xs2[1] = xs[255];
    //ys2[0] = histogram[254];
    //ys2[1] = histogram[255];

    _Bool success;
	StringReference *errorMessage;

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xs;
	series->xsLength = 256;
	series->ys = ys;
	series->ysLength = 256;
	//series->linearInterpolation = true;
	//series->lineType = L"dotted";
	//series->lineTypeLength = wcslen(series->lineType);
    series->pointType = L"dots";
	series->lineThickness = 1;
	series->color = GetGray(1);

    //ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();
	//series2->xs = xs2;
	//series2->xsLength = 2;
	//series2->ys = ys2;
	//series2->ysLength = 2;
	////series2->linearInterpolation = true;
	////series2->lineType = L"dotted";
	////series2->lineTypeLength = wcslen(series->lineType);
    //series2->pointType = L"dots";
	//series2->lineThickness = 1;
	//series2->color = GetGray(1);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1000;
	settings->height = 600;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = L"HISTOGRAM";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"Renk Tonu";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"Olusma sayisi";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 1;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	errorMessage = (StringReference *)malloc(sizeof(StringReference));
	success = DrawScatterPlotFromSettings(canvasReference, settings, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "histogram.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	return success ? 0 : 1;
}

int pmf_ciz(double pmf[])
{
    double xs[257];
    double ys[257];

    for (int i = 0; i < 255; i++)
        xs[i] = i;

    for (int i = 0; i < 254; i++)
        ys[i] = pmf[i];

    ys[255] = pmf[255];

    _Bool success;
	StringReference *errorMessage;

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xs;
	series->xsLength = 256;
	series->ys = ys;
	series->ysLength = 256;
	//series->linearInterpolation = true;
	//series->lineType = L"dotted";
	//series->lineTypeLength = wcslen(series->lineType);
	series->lineThickness = 1;
	series->color = GetGray(1);
    

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1000;
	settings->height = 600;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = L"PMF";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"Renk Tonu";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"olusma olasiligi";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 1;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	errorMessage = (StringReference *)malloc(sizeof(StringReference));
	success = DrawScatterPlotFromSettings(canvasReference, settings, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "pmf.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	return success ? 0 : 1;
}

int normalDagilim_ciz(double normalDagilim[])
{
    double xs[257];
    double ys[257];

    for (int i = 0; i < 255; i++)
        xs[i] = i;

    for (int i = 0; i < 254; i++)
        ys[i] = normalDagilim[i];

    ys[255] = normalDagilim[255];

    _Bool success;
	StringReference *errorMessage;

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xs;
	series->xsLength = 256;
	series->ys = ys;
	series->ysLength = 256;
	//series->linearInterpolation = true;
	//series->lineType = L"dotted";
	//series->lineTypeLength = wcslen(series->lineType);
	series->lineThickness = 1;
	series->color = GetGray(1);
    

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1000;
	settings->height = 600;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = L"Normal Dagilim";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"X";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"P(X)";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 1;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	errorMessage = (StringReference *)malloc(sizeof(StringReference));
	success = DrawScatterPlotFromSettings(canvasReference, settings, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "normal_dagilim.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	return success ? 0 : 1;
}

int ortalamaPmf_ciz(double ortalamalar[])
{
    double xs[256];

    for (int i = 0; i < 255; i++)
        xs[i] = i;

    _Bool success;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	StringReference *errorMessage = CreateStringReference(L"", 0);
	success = DrawScatterPlot(canvasReference, 1000, 600, xs, 256, ortalamalar, 256, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "MLT-PMF.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	return success ? 0 : 1;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    //komut satırından argüman alma işlemleri
    if (argc != 2)
    {
        printf("kullanim sekli: %s <dosyaadi.pgm>\n", argv[0]);
        return 1;
    }

    //dosya oku
    char *dosyaAdi = argv[1];
    FILE *fp = fopen(dosyaAdi, "rb");
    if (fp == NULL)
    {
        printf("dosya acilamadi: %s\n", dosyaAdi);
        return 1;
    }

    //PGM dosyasının başlığını oku
    int genislik, uzunluk, maksDeger;
    char baslik[3];
    fscanf(fp, "%s\n%d %d\n%d\n", baslik, &genislik, &uzunluk, &maksDeger);
    if (baslik[1] != '5' || baslik[0] != 'P')
    {
        printf("Dosya PGM formatinda degil!\n");
        return 1;
    }

    //Piksel verileri için bellek ayır
    unsigned char *pikseller = (unsigned char *)malloc(sizeof(unsigned char) * uzunluk * genislik);
    if (pikseller == NULL)
    {
        printf("Piksel verileri icin bellek ayrilamadi\n");
        return 1;
    }

    //Piksel verisini oku
    fread(pikseller, sizeof(unsigned char), genislik * uzunluk, fp);

    //dosyayı kapat
    fclose(fp);

    //Resmin histogramını hesapla
    int histogram[maksDeger + 1];
    for (int i = 0; i <= maksDeger; i++)
    {
        histogram[i] = 0;
    }
    for (int i = 0; i < genislik * uzunluk; i++)
    {
        histogram[pikseller[i]]++;
    }

    //histogramı konsola bas
    printf("-----HISTOGRAM-----\n");
    for (int i = 0; i <= maksDeger; i++)
    {
        if (histogram[i] == 0)
            continue;
        
        printf("%d: %d\n", i, histogram[i]);
    }

    printf("\n\n");

    printf("-----PMF-----\n");
    //PMF hesapla
    double pmf[256] = {0};
    for (int i = 0; i <= maksDeger; i++)
    {
        pmf[i] = (double)histogram[i] / (double)(genislik * uzunluk);
        if (pmf[i] == 0)
            continue;
        
        printf("%d: %f\n", i, pmf[i]);
    }

    printf("\n\n");

    //Ortalama yoğunluk değerini hesapla
    double ortalama = 0.0;
    for (int i = 0; i <= maksDeger; i++)
    {
        ortalama += (double)i * (double)histogram[i];
    }
    ortalama /= (double)(genislik * uzunluk);

    //varyans hesapla
    double varyans = 0.0;
    for (int i = 0; i <= maksDeger; i++)
    {
        varyans += pow((double)histogram[i] - ortalama, 2.0);
    }
    varyans /= (double)(genislik * uzunluk);

    //Standart sapma hesapla
    double standartSapma = sqrt(varyans);

    //Normal dağılım hesapla
    double normalDagilim[256];
    for (int i = 0; i < 256; i++) {
        normalDagilim[i] = (1.0 / (standartSapma * sqrt(2 * M_PI))) * exp(-pow((i - ortalama), 2) / (2 * pow(standartSapma, 2)));
    }

    //pmf grafiği ile normal dağılım grafiğini birbirine benzetme işlemi (tamamlayamadım!)
    /*
    double ortalamalar[256] = {0.0};
    double toplam;
    for (int i = 0; i < 255; i++)
    {
        toplam = 0.0;
        for (int j = 0; j < 9; j++)
        {
            toplam += pmf[(rand() % 255)];
        }
        toplam /= 9.0;
        ortalamalar[i] = toplam;
    }
    printf("\n");
    for (int i = 0; i <= maksDeger; i++)
    {
        printf("%ld: %ld\n", i, ortalamalar[i]);
    }
    */
    
    bool basariliMi;
    basariliMi = histogram_ciz(histogram);
    if (basariliMi == 1)
        printf("çizim başarısız!");

    basariliMi = pmf_ciz(pmf);
    if (basariliMi == 1)
        printf("çizim başarısız!");
    
    basariliMi = normalDagilim_ciz(normalDagilim);
    if (basariliMi == 1)
        printf("çizim başarısız!");
    /*
    basariliMi = ortalamaPmf_ciz(ortalamalar);
    if (basariliMi == 1)
        printf("çizim başarısız!");
    */
    //Sonuçları konsola bas
    printf("Ortalama Yogunluk Degeri: %f\n", ortalama);
    printf("Varyans: %f\n", varyans);
    printf("Standart Sapma: %f\n", standartSapma);

    //belleği boşalt
    free(pikseller);

    return 0;
}
