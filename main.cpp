#include <iostream>

using namespace std;

typedef struct dugumler{    /*her graf elemaninin verilerini tutacak bir struct yapisi kurdum.*/
string renk="yok";  /*her dugumun renk bilgisini tutacak degisken, baslangicta hepsi renksiz.*/
int dugum_bag_sayisi; /*dugumun graf yapisinda kac adet baglantisi oldugunu tutacak.*/
int numara; /*dugumun numara bilgisini tutacak.*/
struct dugumler *ileri; /*sonri liste elemanini gosteren pointer.*/
}LISTE;

struct dugumler d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15,d16,d17,d18,d19,d20; /*tum graf elemanlarimiz icin dugumleri bir struct yapisinda olusturdum, bunlardan bagli bir liste olusturacagiz*/
LISTE *ilk,*p,*v,*son=&d20,*u,*m,*q; /*graf elemanlarini bagli listeye aldigimda, bagli liste uzerinde gezmek icin pointerler tanimladim.*/

string renk_havuzu[20][1]= /* renklendirme icin kullanilacak renkleri bir matris seklinde tanimladim.*/
{
    {"kirmizi"},
    {"yesil"},
    {"mavi"},
    {"mor"},
    {"sari"},
    {"lacivert"},
    {"turuncu"},
    {"turkuaz"},
    {"pembe"},
    {"boz"},
    {"kirmizimsi"},
    {"yesilimsi"},
    {"mavimsi"},
    {"morumsu"},
    {"sarimsi"},
    {"lacivertimsi"},
    {"turuncumsu"},
    {"turkuazimsi"},
    {"pembemsi"},
    {"imsiimsi"},
};

void listeyi_bagla(){ /*Daha once olusturdugumuz dugumleri birbirlerine baglayarak cevrimsel bir bagli liste olusturdum.
     Renk atamasi yapilirken liste elemanlari arasinda defalarca gecilecegi icin cevrimsel*/
d1.ileri=&d2;
d2.ileri=&d3; d3.ileri=&d4;
d4.ileri=&d5; d5.ileri=&d6;
d6.ileri=&d7; d7.ileri=&d8;
d8.ileri=&d9; d9.ileri=&d10;
d10.ileri=&d11; d11.ileri=&d12;
d12.ileri=&d13; d13.ileri=&d14;
d14.ileri=&d15; d15.ileri=&d16;
d16.ileri=&d17; d17.ileri=&d18;
d18.ileri=&d19; d19.ileri=&d20;
d20.ileri=&d1;}; /*bu satirda cevrimsellik saglandi*/

int dugum_derecesi[20][1]; /*her bir dugumun bag sayisini yani drecesini tutacak bir matris tanimladim.*/

int komsuluk_matrisi[20][20]= /* Verilen grafimizin komsuluk matrisi*/
    {
        /*d1*/{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        /*d2*/{1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        /*d3*/{0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        /*d4*/{0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        /*d5*/{0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        /*d6*/{0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        /*d7*/{0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        /*d8*/{0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0},
        /*d9*/{0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
        /*d10*/{0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
        /*d11*/{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
        /*d12*/{0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
        /*d13*/{0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0},
        /*d14*/{0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},
        /*d15*/{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0},
        /*d16*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
        /*d17*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
        /*d18*/{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0},
        /*d19*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1},
        /*d20*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},

    };

    void derece_hesap()     {/*dugumlerin derecelerini hesaplamasi icin bir fonksiyon tanimladim.*/

        int komsuluk_satir,komsuluk_sutun; /*komsuluk matrisinin indexleri olarak kullanmak uzere tanimladim.*/
        int derece_satir=0; /*dereceleri tutan matrisinuzerinde gezmek icin tanimlanmis bir index verisi tutan degisken*/
            for(komsuluk_satir=0;komsuluk_satir<20;komsuluk_satir++)  { /*komsuluk matrisinin satirlarini gezecek for dongusu*/
                for(komsuluk_sutun=0;komsuluk_sutun<20;komsuluk_sutun++){ /*komsuluk matrisinin sutunlarini gezecegimiz for dongusu*/
                        if(komsuluk_matrisi[komsuluk_satir][komsuluk_sutun]!=0) /*komsuluk matrisi uzerinde 1 sayisi yani baglanti olan noktayi kontrol ediyorum*/
                            {(dugum_derecesi[derece_satir][0])=(dugum_derecesi[derece_satir][0])+1;}; /*komsuluk matrisinde gezerken dugume ait bir baglantiya
                            rastladiginda bunu dugum_derecesi matrisine yazip sayma islemi yapiyorum*/
                        };
                derece_satir=derece_satir+1;  /*satirlari gezen for dongusun her turunde bir sonraki dugumun derecesini hesaplayacagimiz icin dugum_derecesi matrisinde de satir atliyorum*/
    };

};
    void derece_yerlestir(){  /*Hesapladigimiz dugum derecelerini dugumlerin dugum_bag_sayisi degiskenine atamasini yapiyorum.*/
        int derece_satiri; /*dereceleri tutan matrisin indexini tutuyorum*/
        p=&d1; /*bagli listenin ilk elemanini gosteren bir gezici isaretci atiyorum*/
        for(derece_satiri=0;derece_satiri<20;derece_satiri++){ /*dereceleri tutan matrisin basindan son elemanina kadar giden bir dongu.*/
            p->dugum_bag_sayisi=dugum_derecesi[derece_satiri][0]; /*dereceleri tutan matristeki verileri sirayla liste elemanlarinin bag sayisini tutan degiskenine yaziyorum*/
            p=p->ileri; /*listede ilerlemeyi sagliyorum*/
        };
    };

    void numara_yerlestir(){    /*her bagli liste elemaninin graf uzerindeki numarasini ilgili degiskene atanmasini sagliyorum.*/
        m=&d1;  /*liste uzerinde ilerleme saglamak icin bir isaretciyi ilk liste elemanini gosterecek halde hazirliyorum.*/
        for(int n=1;n<21;n++){  /*zaten siraya gore islem yaptigim icin her b.liste elemanlarina 1 den baslayip 20 ye kadar numara veriyorum. Graftaki numaralarini bozmadan. */
        m->numara=n; /*siradaki elemana siradaki numara veriliyor*/
         m=m->ileri;};      /*isretci bir sonraki elemani gostererek ilerlemeye devam ediyor.*/
    };

int a[20][1];   /*derceleri tutan diziyi siraladiktan sonra bu dizide tutarak orjinal diziyi bozmadan siralisini kullanacam*/
int secmeli_sirala(int dizi[20][1])  /*dereceleri tutan matrisin siralamasini Secmeli Siralama yontemi ile yapacak fonksiyonu tanimliyorum. */
{/*her seferinde buyuk sayiyi degistirerek siralam yaptigimiz normal secmeli siralama adimlari*/
int N = 20;
int t;
    for (int k=0;k<N;k++){
        int byk = k;
        for(int l=k+1;l<N;l++){
            if(dizi[l][0] > dizi[byk][0]){byk= l;};
        };
         t = dizi[k][0];
         dizi[k][0] = dizi[byk][0];
         dizi[byk][0] = t;
    };/*her seferinde buyuk sayiyi degistirerek siralam yaptigimiz normal secmeli siralama adimlari*/

    for(int y=0; y<20;y++){ /*Bu for songusu ile sorali hale gelmis diziyi daha once tanimladigim diziye aktariyorum.*/
    a[y][0] = dizi[y][0];
    };
return 0;
};

int komsu_rengi(int a){ /*Elimizdeki dugum icin gerekti yerde komsularinda ayni renkten olup olmadigini sorgulayip sonuc donduren fonksiyon olusturdum.*/
        p=&d1;  /*yine bir gezici isaretci ilk liste elemanini gostererek basladi.*/
        for(int i=0;i<20;i++){  /*komsuluk matrisinde her bir satiri sonuna kadar gitmemisi saglayacak for dongusu*/
            if(komsuluk_matrisi[a-1][i]==1) /*fonksiyone gonderilmis eleman numarasinin oldugu satira gelip 1 rakami (yani baglanti) bulana kadar saga dogru giden kontrolcu*/
                {
                    if(p->numara==i+1)      /*ilk bulacagi baglanti kendisi olmasi durumunda atlamasi ve sonraki baglantiyi bulmasi gerekir birada onu sagliyorum*/
                    {p=p->ileri;}
                    else {
                            if( p->renk==u->renk)  /*eger buldugu baglantinin liste elemaninda renk sorgulattigimiz elemanin rengi ile eslesiyor ise ...*/
                            {return 99;} else{return 0;};  /*99 rakami dondurup fonksiyonun cagirildigi yerde uyari ousturuyor. ama renk cakismasi gorulmadiyse 0 yollayip sikinti olmadigini bildiriyor/*/
                        };
                    } else {};
                };

       return 0; };
    int renk_sayisi; /*kullanicin girecegi rengi tanimladim*/

    int renk_atayici(int f){ /*her dugumun alacagi rengi belirleyen fonksiyon.*/
            int j=0,k=0; u=&d1; /*renk havuzu, derece sirasin tutan matrislerin indexlerini tutan degiskenler ile bagli listede gezmemize yarayacak isaretci tanimlandi.*/
                    for(int i=0;i<20;i++){ /*cevrimsel bir listede oldugu icin islemi durduracak for dongusu*/
                        while (dugum_derecesi[j][0]!=u->dugum_bag_sayisi||u->renk!="yok") /*sirlalanmis dugum dercesi matrisindeki en buyuk dereceye dahip elemani bulmadiysam*/
                       /* ve uzerinde bulundugum bagli liste elemaninin bir rengi zaten varsa, isaretciyi ilerletiyorum.*/
                        {
                                u=u->ileri;
                        };
                        u->renk=renk_havuzu[k][0]; j=j+1;k=k+1; /*while dongusundeki sartlerin disinda isem renk havuzundaki ilk rengi aliyorum
                         ve derceye gore siralanmis liste ile buldgum bagli liste elemaninin rengine yaziyorum.
                         renk havuzun ve dercelerin siralandigi matrislerin indexlerin bir sonrakine ilerletiyorum*/
                        if(k==f){k=0;}; /*renk havuzu matrisinde kullanicinin versigi renk sayisini gecmemek icin, kullanincinin verdigi sayiya ulasince index i tutan degiskeni ilk elemana geri aliyorum.*/
                    };

                        return 0;
};

int cakisma_kontrol(){ /* kullanicinin girebilecegi her sayi icin cakisma degerlendirmesi yapip minimum renk sayisini donduren fonksiyon.*/
        u=&d1; /*yine bir gezici isaretci*/
        int x=0; /*ilk denenecek renk sayisi ve her turda artip dogru yerde fonksiyonun cagrildigi yere dondurulecek.*/
        for(int w=0;w<20;w++){ /*bagli listenin basindan sonuna kadar ilerlemek icin for dongusu.*/
                if(komsu_rengi(u->numara)==99){x=x+1;} /*her bir liste elemanini komsu rengi fonksiyonuna yollayip cakisma gerceklesti mi diye sorguluyoruz.
                eger fonksiyondan 1 tane bile 99 degeri donuyorsa renk sayisi yetersiz ve cakisma var dektir.*/
                else{};
                u=u->ileri; /*listein sonuna kadar gidiyoruz.*/
        };
return x; /* eger hic 99 sayisi gelmediyse minimum renk sayisi olan x'i geri donduruyoruz.*/
};

        int sayi_giriniz(int a){ /*kullanicidan sayi alarak sayiyi cagirildigi yere donduren foksiyon*/
            int f;
            cout<<"Kullanilacak renk sayisi giriniz...: ";
            cin>>f;
            a=f;
            return a;
                };

void yazdir(){ /*dugumlere yazilmis renklerin hepsini ekrana basan fonksiyon.*/
    u=&d1; /*bagli listede gezdirecegimiz isaretci ilk dugumu gosteriyor.*/
       do{
        cout<<"d"<<u->numara<<" dumarali dugumun rengi...: "<<u->renk<<endl;
        u=u->ileri;
        }
         while(u->ileri!=&d2);  /*cevrimsel bir liste oldugundan bir kez calistirip listenin basina geldiginde donguden cikan bir dongu ile yazdirma yapiyorum.*/

};

int main()
{
int t; /*sayi girdimizde surekli degisecek degiskeni atiyorum*/
derece_hesap(); /*her graf elemaninin dercesini komsuluk matrisi ile hesaplayan fonksiyonu cagiriyorum.*/
listeyi_bagla(); /*elimdeki dugum yapilarinin hepsini birbirine baglayan baglama fonksiyonunu cagiriyprum.*/
derece_yerlestir(); /*dereceleri hesaplatmistik yerlstirme fonksiyonu ile bu dreceleri bagli listeye sirasi ile yerlstoren fonksiyonu cagiriyorum.*/
numara_yerlestir(); /*bagli listenin her dugumune sirasiyla olmasi gereken numaralari atayan fonksiyonu cagiriyorum.*/
secmeli_sirala(dugum_derecesi); /*dugum derecelerini tutan matrisi secmeli siralama yapan fonksiyon ile siraliyorum.*/

t=sayi_giriniz(0); /*t degiskenine sayi girinizin dondurecegi degeri atiyorum.*/
while(t<4){cout<<"Yetersiz sayi girdiniz. Renklendirme icin "<<4-t<<" renk daha gerekli "<<endl; /*minimum renk sayisi hesaplayan fonksiyonun verdigi
degere ulasana kadar renk girilmesi gerektigini bildiriyorum.*/
t=sayi_giriniz(t);};
renk_atayici(t);/*minimum dgere ulasildinde bu girilen degeri renk atama fonksiyonuna yollayip renklerin atanmasini sagliyorum.*/
yazdir(); /*renkleri atanan dugumleru yazdir fonksiyonunu cagirarak yazdiriyorum.*/
system("pause");
 return 0;
 };

