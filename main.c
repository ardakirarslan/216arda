#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float bakiyeislemleri(float bakiye)
{
	float miktar;
	printf("\nYuklemek istediginiz miktari giriniz: ");
    scanf("%f", &miktar);
    bakiye+=miktar;
    printf("Yeni Bakiyeniz: %.2f TL\n", bakiye);
    return bakiye;
}
float rezervasyon(int otel[5][1],float bakiye, int fiyatlar[5])
{
	int odasecim,kalacakgun=0,toplam=0;
	printf("\nKullanilabilir Odalarimiz:\n");
	printf("1 - Deluxe Suit    (%d TL)\n", fiyatlar[0]);
    printf("2 - Deluxe Oda     (%d TL)\n", fiyatlar[1]);
    printf("3 - Luxury Suit    (%d TL)\n", fiyatlar[2]);
    printf("4 - Elite Room     (%d TL)\n", fiyatlar[3]);
    printf("5 - Standart Room  (%d TL)\n", fiyatlar[4]);
    printf("Seciminiz (1-5): ");
    scanf("%d",&odasecim);
	
		if (odasecim<1 || odasecim>5)
		{
			printf("Hatali Secim Yaptiniz!\n");
			return bakiye;
		}
	printf("\nKac gun kalacaksiniz?");
	scanf("%d",&kalacakgun);
	toplam=fiyatlar[odasecim-1]*kalacakgun;
	printf("\nToplam Tutar: %d TL",toplam);
	
		if (bakiye<toplam)
		{
			printf("\nYetersiz Bakiye, Bakiye islemlerine gonderiliyorsunuz.");

			bakiye=bakiyeislemleri(bakiye);
			
		}
		else
		{
			bakiye-=toplam;
			printf("\nIslem Basarili! Yeni bakiyeniz: %.2f TL\n",bakiye);
		}
		return bakiye;
}

void odaara(float bakiye, int fiyatlar[5])
{
	int bulma=0;
	printf("\n========= BAKIYENIZE UYGUN ODALAR =========\n");
    printf("Mevcut Bakiyeniz: %.2f TL\n", bakiye);
    printf("Bu Odalarda en az 1 gece kalabilirsiniz:\n");
    printf("--------------------------------------------\n");
    
    if (bakiye>=fiyatlar[0])
    {
    	printf("- Deluxe Suit    (%d TL)\n", fiyatlar[0]);
    	bulma=1;
	}
	if (bakiye>=fiyatlar[1])
    {
    	printf("- Deluxe Oda    (%d TL)\n", fiyatlar[1]);
    	bulma=1;
	}
	if (bakiye>=fiyatlar[2])
    {
    	printf("- Luxury Suit    (%d TL)\n", fiyatlar[2]);
    	bulma=1;
	}
	if (bakiye>=fiyatlar[3])
    {
    	printf("- Elite Room   (%d TL)\n", fiyatlar[3]);
    	bulma=1;
	}
	if (bakiye>=fiyatlar[4])
    {
    	printf("- Standart Room    (%d TL)\n", fiyatlar[4]);
    	bulma=1;
	}
	if (bulma == 0) 
	{
        printf("Maalesef bakiyeniz herhangi bir oda tutmak icin yeterli degil.\n");
        printf("Isterseniz Bakiye Yukle menusunden ekleme yapabilirsiniz.\n");
    }
}
float promosyon(float bakiye)
{
	int kod;
	printf("\n--- PROMOSYON KODU GIRISI ---");
    printf("\nLutfen 4 haneli promosyon kodunuzu giriniz: ");
    printf("\n 1010 kodu 1000 TL, 2020 kodu 2500 TL ");
    printf("\n Ayriyeten Bakiyenizin %5'i kadar bonus para hesabiniza tanimlanacaktir.\n");
    scanf("%d", &kod);
    
    if (kod==1010)
    {
    	bakiye*=1.05;
    	bakiye+=1000;
    	printf("\n Tebrikler! Bakiyeniz hesabiniza Aktarildi.");
    	printf("Guncel Bakiyeniz: %2.f TL",bakiye);
	}
	else if (kod=2020)
	{
		bakiye*=1.05;
		bakiye+=2500;
		printf("\n Tebrikler! Bakiyeniz hesabiniza Aktarildi.");
		printf("Guncel Bakiyeniz: %2.f TL",bakiye);
		
	}
	else 
	{
		printf("\n Lütfen Gecerli Bir Promosyon kodu giriniz.");
	}
	return bakiye;
}
float ekhizmetler(float bakiye)
{
	int secimm1;
	printf("\n---------- ODA SERVISI VE EK HIZMETLER ----------\n");
    printf("1 - Acik Bufe Kahvalti    (250 TL)\n");
    printf("2 - Odaya Kahvalti Servis (400 TL)\n");
    printf("3 - Spa ve Masaj          (1200 TL)\n");
    printf("4 - VIP Havuz Kullanimi   (800 TL)\n");
    printf("0 - Ana Menuye Don\n");
    printf("-------------------------------------------------\n");
    printf("Seciminiz: ");
    scanf("%d", &secimm1);
    
    	if (secimm1==1)
    	{
    		if (bakiye>=250)
    		{
    			bakiye-=250;
    			printf("\nAfiyet olsun! 250 TL bakiyenizden dusuldu.\n");
			}
			else
			{
				printf("\nYetersiz bakiye!\n");
			}
		}
		else if (secimm1==2)
    	{
    		if (bakiye>=400)
    		{
    			bakiye-=400;
    			printf("\nAfiyet olsun! 400 TL bakiyenizden dusuldu.\n");
			}
			else
			{
				printf("\nYetersiz bakiye!\n");
			}
		}
		else if (secimm1==3)
    	{
    		if (bakiye>=1200)
    		{
    			bakiye-=1200;
    			printf("\nTebrikler, 1200 TL bakiyenizden dusuldu.\n");
			}
			else
			{
				printf("\nYetersiz bakiye!\n");
			}
		}
		else if (secimm1==4)
    	{
    		if (bakiye>=800)
    		{
    			bakiye-=800;
    			printf("\nTebrikler, 800 TL bakiyenizden dusuldu.\n");
			}
			else
			{
				printf("\nYetersiz bakiye!\n");
			}
		}
		else if	(secimm1==0)
    	{
    		printf("\nAna menuye donuluyor\n");
		}
		else 
		{
			printf("\nGecersiz Secim Yaptiniz.\n");
		}
		return bakiye;
}
void uyekaydi()
{
	int isim,yas,tc;
	printf("Lütfen Ýsminizi Girin");
	printf("Lütfen Yasinizi Girin");
	printf("Lütfen TC Kimlik Numaranizi Girin");
	printf("Üyelik Kaydiniz Basariyla Olusturuldu");
}

int main()
 {
 	float bakiye=0;
 	int secim=-1;
 	int otel[5][1] = {0};
 	int fiyatlar[5]={15000,12500,11000,8500,6000};
 	char isim[30];
	char soyisim[30];
	char tcNo[12];
 	
 	
 	
 	printf("---------- THE ROYAL SUITE UYE KAYIT SISTEMI ----------\n");
	printf("Adinizi Giriniz: ");
	scanf("%s", isim);
	printf("Soyadinizi Giriniz: ");
	scanf("%s", soyisim);
	printf("TC Kimlik Numaranizi Giriniz: ");
	scanf("%s", tcNo);
	printf("\nKayit Basarili! Hosgeldiniz Sayin %s %s.\n", isim, soyisim);
	printf("-------------------------------------------------------\n");
 		
 	while (1)
 	{
 	
 		printf("\n---------- The Royal Suite Oteline Hosgeldiniz ----------");
        printf("\n1 - Rezervasyon Yap");
        printf("\n2 - Bakiye Yukle");
        printf("\n3 - Butceye Uygun Oda Ara");
        printf("\n4 - Promosyon Kodu Kullan");
        printf("\n5 - Oda Servisi / Ek Hizmetler");
        printf("\n0 - Cikis Yap");
        printf("\n-------------------------------------------------");
        printf("\nMevcut Bakiyeniz: %.2f TL", bakiye);
        printf("\nSeciminiz: ");
        scanf("%d", &secim);
        
        if (secim==1) 
 		{
 			bakiye=rezervasyon(otel,bakiye,fiyatlar);
		}
 		else if (secim==2)
 		{
 			bakiye=bakiyeislemleri(bakiye);
		}
		else if (secim==3)
 		{
 			odaara(bakiye,fiyatlar);
		}
		else if (secim==4)
 		{
 			bakiye=promosyon(bakiye);
		}
		else if (secim==5)
 		{
 			bakiye=ekhizmetler(bakiye);
		}
		else if (secim==0)
 		{
 			break;
		}
 		else
 		{
 			printf("\nGecersiz Secim!\n");
		}
 		
	}
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
	return 0;
}
