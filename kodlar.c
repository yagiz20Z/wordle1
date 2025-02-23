#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define sari "\x1b[33m"
#define yesil "\x1b[32m"
#define siyah "\x1b[0m"

int tekrar = 0;

void kelimeKontrol (char kelime[],char tahmin[]);             // kelimeler alinacak ve kontrol edilecek 
void buyutme (char kelime[],char tahmin[]);
void kurallar (char kelime[],char tahmin[]);
void bitim(char kelime[],char tahmin[]);
char* gizlikelime();

int main (){
    char tahmin[6] ;
    char* kelime = gizlikelime();           // bunu kütüphaneden çekeceğiz
    printf(" \t\tKelime oyununa hosgeldin \n oyunda her seferinde 5 harf olmak uzere tahminler yapip gizli kelimeyi 5 tahmin hakki içerisinde tahmin etmen gerekmektedir\n\n ");
    printf("kurallar : \n");
    printf("yapacaginiz tahmin 5 harfli olmalidir . \n");
    printf("eger tahmin ettigin harf gizli kelimede bulunuyor ancak yeri dogru degilse "sari"sari"siyah", \n");
    printf("eger tahmin ettigin harf gizli kelimede bulunuyor ve yeri dogru de dogruysa "yesil"yesil"siyah" bir kutu icerisinde gosterilecektir. \n");
    printf("\n\nlutfen tahmininizi giriniz : ");
    kurallar(kelime,tahmin); 
    return 0;
}

void kurallar (char kelime[],char tahmin[]){
    if(tekrar == 6){
        printf("\n\nhakkiniz bitmistir ! \n\t\t KAYBETTINIZ \n\n ");
        bitim(kelime,tahmin);

    }
    else{
        tekrar++;
        // printf("\n");
        gets(tahmin);
        if(strlen(tahmin) == 5){
            buyutme(kelime,tahmin);
    }
        else{
            printf(" yaptiginiz tahmin hatali tekrarlayin\n");
            kurallar(kelime,tahmin);
    }}}

void kelimeKontrol (char kelime[],char tahmin[]){
    int COUNT = 0;

    for ( int i = 0 ; i < 5 ; i++){
        if (tahmin[i] == kelime[i]){
            printf(yesil"%c\t"siyah,tahmin[i]);
            COUNT++;
        }
        else if (strchr(kelime, tahmin[i])){                        // string.h kütüphanesinde bulunan bu fonksiyon ile tahmin[i], kelime dizisi içerisinde  
            printf(sari"%c\t"siyah,tahmin[i]);                      // bulunup bulunmadığı kontrol edilmiştir
        }                                                  
        else {
            printf("%c\t",tahmin[i]);
        }
        
        }

    if (COUNT == 5){
        printf("\ntebrikler basardiniz\n"); 
        bitim(kelime,tahmin);
    }
    else{
        kurallar(kelime,tahmin); 
    }}

void buyutme (char kelime[],char tahmin[]){

    for (int i = 0; i < 5; i++) {
        if ('a' <= tahmin[i] && tahmin[i] <= 'z') {
            tahmin[i] -= 32; // Küçük harfi büyüğe çevir
        }
    }
    kelimeKontrol(kelime,tahmin);
}

void bitim(char kelime[],char tahmin[]){
        int cevap;
        printf(" | | | | | | |\n | | | | | | |\n");
        printf(" oyuna devam etmek icin 1'e basiniz! \n");
        printf("cikmak ve cevabi gormek icin herhangi bir tusa basiniz! \n");
        scanf("%d",&cevap);
        if (cevap==1){
            tekrar = 0;
            kurallar(kelime,tahmin);
        }
        else{
            for (int i = 0 ; i < 5 ; i++){
                printf(yesil"%c\t"siyah,kelime[i]);
        }
            printf("\ncikiliyor ...");
        }
}


char* gizlikelime(){

    srand(time(NULL));
    int rastegelesayi,miktar;
    static char kelime [][6]= {"AFAKI","ABIYE","ABBAS","BALON","BAHRI","DILIM","DAIMI","DILEK","EZBER","EVLAT","ENFES","FOSİL","FELEK","GAYET","GIYIM","GAZOZ","HAMAK","HAMSI","INMEK","INKAR","KELAM","JOKEY","JARSE","KREDI","KABLO","LOTUS","MEVLA","MASAL","MELEZ","NALAN","NINNI","PILOT","POSTA","RAMPA"};
    miktar=sizeof(kelime)/sizeof(kelime[0]);
    rastegelesayi = rand() % miktar;
    
    return kelime[rastegelesayi];

}
