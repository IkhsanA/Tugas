#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <math.h>
#include <windows.h>

//deklarasi fungsi
void Menu_Utama();
void baca_file();
void buka_file();
void tambahDTK();
void tampilDTK();
void cariDTK();
void hapusDTK();
void ubahDTK();
void tambahDAK();
void tampilDAK();
void cariDAK();
void hapusDAK();
void ubahDAK();
void tambah_DJK();
void tampil_DJK();
void cari_DJK();
void hapus_DJK();
void ubah_DJK();

//deklarasi struct
typedef struct
{
  char nama[20];
  char alamat[20];
  char jabatan;
  char NIK[6];
  char status;
  char hari[7];
  char jam;
}data_gaji;

//deklarasi variable struct
data_gaji penggajian; 


//deklarasi variabel
FILE *Pfk;
int menu;
char kmbli_menu, jawab;
int i, nomor;
char z[6];
int tdkketemu;
char c;
int no_record, hasil_baca;
long int ofset_byte;


char *jm (char jam)
{ switch (jam)
  { case '1' : return("07.00-11.00");
    case '2' : return("13.00-17.00");
    case '3' : return("19.00-23.00");
  }
  return("Tidak Ada");
}

char *jbtn (char jabatan)
{ switch (jabatan)
  { case '1' : return("Manager");
    case '2' : return("Sekretaris");
    case '3' : return("Bendahara");
    case '4' : return("Leader");
    case '5' : return("Operator");
  }
  return("Tidak Ada");
}

int main(int argc, char *argv[])
{
    Menu_Utama();

system("PAUSE");    
return 0;    
}

void buka_file()
{
  //buka file
  if((Pfk=fopen("DataKaryawan.txt","at"))==NULL) 
  {
    clrscr();  
    printf("Kesalahan File Tidak Dapat Dibuka!!\n");    
    exit(1);                             
  }
} 
   
   
   
void Menu_Utama()
{

void DataKaryawan();
void DataAbsensiKaryawan();
void DataGajiKaryawan();

  do
  {                   
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("   Program Penggajian   ");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Data Karyawan        ");
    gotoxy(28,7);printf("2. Data Absensi Karyawan");
    gotoxy(28,8);printf("3. Data Gaji Karyawan   ");
    gotoxy(28,9);printf("4. Keluar               ");
    gotoxy(28,11);printf("========================");
    gotoxy(28,12);printf("   Pilihan [1..4] = ");scanf("%i", &menu);     
   
    switch(menu)
   {       
      case 1:DataKaryawan();break;
      case 2:DataAbsensiKaryawan();break;
      case 3:DataGajiKaryawan();break;  
      case 4:exit(1);break;
   }
   gotoxy(24,15);textcolor(LIGHTRED);
   printf("Salah memasukkan pilihan! Ulangi!");
   gotoxy(26,16);textcolor(15);
   printf("Tekan Enter Untuk Melanjutkan");
   getch(); 
   }while((menu<=0)||(menu>4));        
}

void baca_file()
{
  //baca file
  if((Pfk=fopen("DataKaryawan.txt","rt"))==NULL)
  {
    clrscr();
    printf("Kesalahan File Tidak Dapat Dibuka!!\n");    
   exit(1);                                   
  }
}

void baca_file_ubah()
{
  if((Pfk=fopen("DataKaryawan.txt","rt+"))==NULL)
  {
    clrscr();
    printf("Kesalahan File Tidak Dapat Dibuka!!\n");    
   exit(1);                                   
  }      
}     
 
void tambahDTK()
{   
    int n;
    n=7;
   buka_file();
   do
   {
      clrscr();
      gotoxy(34,2);printf("Data  Karyawan");
      gotoxy(31,3);printf("Input Data Karyawan");
      gotoxy(28,4);printf("==========================\n\n");
      printf(" NIK          \t : ");fflush(stdin);gets(penggajian.NIK);
      printf(" Nama         \t : ");fflush(stdin);gets(penggajian.nama);
      for(i=0;i<n;i++)
      {
      printf(" Hari ke-%i Hadir [Y/T]\t : ",i+1);fflush(stdin);gets(penggajian.hari);
      }
      printf("\n ================\n");
      printf("Pilihan Jam\n");
      printf(" ================\n");
      printf(" 1. Pagi \n");
      printf(" 2. Siang \n");
      printf(" 3. Malam \n");
      printf(" ================\n");
      printf(" Silahkan masukkan pilihan Jam : ");penggajian.jam = getche();printf("\n");
      printf("\n ================\n");
      printf(" Pilihan Jabatan\n");
      printf(" ================\n");
      printf(" 1. Manager \n");
      printf(" 2. Sekretaris \n");
      printf(" 3. Bendahara \n");
      printf(" 4. Leader \n");
      printf(" 5. Operator \n");
      printf(" ================\n");
      printf(" Silahkan masukkan pilihan Jabatan : ");penggajian.jabatan = getche();printf("\n");
      printf("=================================\n");  
      
      //masukan data mahasiswa ke file
      fwrite(&penggajian,sizeof(penggajian),1,Pfk);
      printf("\nMau Memasukan Data Lagi (Y/T)? ");
      jawab=getche();
    }while((jawab=='Y')||(jawab=='y'));
      
      //tutup file
      fclose(Pfk);
}

    
void tampilDTK()
{   
   clrscr();
   baca_file();
   nomor=0;
   gotoxy(34,2);printf("Data  Karyawan\n");
   gotoxy(31,3);printf("Tampil Data Karyawan\n");
   gotoxy(28,4);printf("==========================\n\n");
   printf
   (" ==============================================================================\n");
   printf
   (" | No |  NIK  |        Nama         |    Alamat    |    Status    |  Jabatan  |\n");
   printf
   (" ==============================================================================\n");
   for(;;)
   {
    fread(&penggajian,sizeof(penggajian),1,Pfk);
    if(feof(Pfk))break;
    printf(" | %i%3c%-5s%3c%-21s%c%-10s%5c%-14s%c%-11s%c\n",++nomor,'|', penggajian.NIK,'|'
    , penggajian.nama,'|',penggajian.alamat,'|','|', jbtn(penggajian.jabatan),'|'); 
   }
   printf
   (" ==============================================================================\n");
   
   //tutup file
   fclose(Pfk);
}

     
void cariDTK()
{
  clrscr();
  baca_file();
  gotoxy(25,12);printf("Masukan Kode Karyawan: ");fflush(stdin);gets(z);  
  tdkketemu=1;  
  while(!feof(Pfk))
  {
    if(strcmp(penggajian.NIK,z)==0)
     {              
      tdkketemu=0;
      clrscr();
      gotoxy(34,2);printf("Data  Karyawan\n");
      gotoxy(26,3);printf("Tampil Data Pencarian Karyawan\n");
      gotoxy(26,4);printf("==============================\n\n");
      gotoxy(19,5);printf("---------------------------------------------\n");
      gotoxy(19,6);printf("   NIK Karyawan    \t= %s\n", z);
      gotoxy(19,7);printf("   Nama Karyawan   \t= %s\n", penggajian.nama);
      gotoxy(19,8);printf("   Alamat          \t= %s\n", penggajian.alamat);
      gotoxy(19,10);printf("   Jabatan         \t= %s\n", jbtn(penggajian.jabatan));
      gotoxy(19,11);printf("---------------------------------------------\n");
      break;
     }
      else
       fread(&penggajian,sizeof(penggajian),1,Pfk);    
  }
  if(tdkketemu==1)
  {
    gotoxy(30,16);printf("Data Tidak Ditemukan!!!");
  }
  
  //tutup file
  fclose(Pfk);
}

void ubahDTK()
{
    awal:
    tampilDTK();
    gotoxy(34,2);printf("Data  Karyawan\n");
    gotoxy(31,3);printf("Ubah Data Karyawan\n");
    gotoxy(28,4);printf("==========================\n\n");
    baca_file_ubah();
     
    do
    {
      
      gotoxy(28,20);printf("\n");
      printf(" Masukkan nomor record yang akan diubah [1..%i] : ",nomor);
             scanf("%d",&no_record);       
      /* atur penunjuk posisi file ke record yang di kehendaki */
      ofset_byte=(no_record-1)*sizeof(penggajian);
      fseek(Pfk,ofset_byte,SEEK_SET);
      /* baca record yang ditunjuk oleh penunjuk posisi file */
      hasil_baca=fread(&penggajian,sizeof(penggajian),1,Pfk);      
      if(hasil_baca==0)
        {
          printf(" Nomor record tak absah !\r\n");
        }
       else
        {
         printf("\n\n");
         printf(" ==============================================================\n");
         printf(" Edit Data Karyawan \n");
         printf(" ==============================================================\n\n");
         printf(" NIK Karyawan \t\t = %s\n",penggajian.NIK);
         printf("----------------------------------------------------\n");
         printf(" Data Sebelum Diubah\n");
         printf("----------------------------------------------------\n");
         printf("\n Nama Karyawan \t\t = %s\n", penggajian.nama);
         printf(" Alamat \t\t = %s\n", penggajian.alamat);
    
         printf(" Jabatan \t\t = %s\n", jbtn(penggajian.jabatan));

         printf("\n\n");
         printf("----------------------------------------------------\n");
         printf(" Data Yang Akan Diubah\n");
         printf("----------------------------------------------------\n");
         printf(" NIK          \t : ");fflush(stdin);gets(penggajian.NIK);
         printf(" Nama         \t : ");fflush(stdin);gets(penggajian.nama);
         printf(" Alamat       \t : ");fflush(stdin);gets(penggajian.alamat);
         printf("\n ================\n");
         printf(" Pilihan Status\n");
         printf(" ================\n");
         printf(" 1. Menikah \n");
         printf(" 2. Belum Menikah \n");
         printf(" Silahkan masukan kode Status : ");penggajian.status = getche();printf("\n");
         printf("\n =======\n");
         printf(" Pilihan Jabatan\n");
         printf(" =======\n");
         printf(" 1. Manager \n");
         printf(" 2. Sekretaris \n");
         printf(" 3. Bendahara \n");
         printf(" 4. Leader \n");
         printf(" 5. Operator \n");
         printf(" Silahkan masukan kode Jabatan : ");penggajian.jabatan = getche();printf("\n");
         printf("\n=================================\n");  

         /* atur penunjuk posisi file ke posisi sebelumnya*/
         fseek(Pfk,ofset_byte,SEEK_SET);

         /* rekam ulang */
         fwrite(&penggajian,sizeof(penggajian),1,Pfk);
       }//nelse
       cputs("\n\n Mau mengubah lagi (Y/T)?");
       jawab = getche();clrscr();goto awal;
    }while (jawab=='Y'||jawab=='y');
    /* tutup file */
   fclose(Pfk); 
}

void hapusDTK()
{  
  FILE *Pfhapusdtk;
  char *pstr1, *pstr2;
  int banding;
  char nik[16];
  
  do
  {
  clrscr();
  tampilDTK();
  gotoxy(34,2);printf("Data  Karyawan\n");
  gotoxy(31,3);printf("Ubah Data Karyawan\n");
  gotoxy(28,4);printf("==========================\n\n");  
  baca_file();  
  
  gotoxy(2,20);printf(" Masukkan NIK yang akan dihapus = ");fflush(stdin);gets(nik);
    
  
  for(;;){
    fread(&penggajian, sizeof(penggajian), 1, Pfk);
    if(feof(Pfk))break;

    //strcmp: membandingkan apa yg dicari dengan nik yang ada di dalam file
    //strlwr: string to lower, mengecilkan semua karakter
    pstr1 = nik;
    pstr2 = penggajian.NIK;
    banding = strcmp(strlwr(pstr1), strlwr(pstr2));

    if(banding != 0)
    {
     //open file
     if((Pfhapusdtk = fopen("bantu.txt", "at")) == NULL)
      {
       clrscr();
       printf("File tidak dapat dibaca !!\n");
       exit(1);
      }//nif
     //di fwrite ke file baru, selain yg dicari
     fwrite(&penggajian,sizeof(penggajian),1,Pfhapusdtk);
     fclose(Pfhapusdtk);
    }//nif

  }//nfor
  //tutup file
  fclose(Pfk);
  remove("DataKaryawan.txt");
  //rename file temp dengan current name
  rename("bantu.txt", "DataKaryawan.txt");

  cputs("\n\n Mau menghapus data lagi (Y/T)?");
  jawab = getche();
  }while (jawab=='Y'||jawab=='y');

  /* tutup file */
  fclose(Pfk);
}//nvoid 
        

void DataKaryawan()
{
  do
  {
   do
    {
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("     DATA  KARYAWAN     ");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Tambah Data          ");
    gotoxy(28,7);printf("2. Tampil Data          ");
    gotoxy(28,8);printf("3. Cari Data            ");
    gotoxy(28,9);printf("4. Ubah Data           ");
    gotoxy(28,10);printf("5. Hapus Data           ");
    gotoxy(28,11);printf("6. Kembali             ");
    gotoxy(28,13);printf("========================");
    gotoxy(28,14);printf("   Pilihan [1..6] = ");scanf("%i", &menu);
    switch(menu)
    {
      case 1:tambahDTK();break;        
      case 2:tampilDTK();break;
      case 3:cariDTK();break;
      case 4:ubahDTK();break;
      case 5:hapusDTK();break;
      case 6:Menu_Utama();break;
    }
    if((menu<=0)||(menu>6))
    {
     gotoxy(24,15);textcolor(LIGHTRED);
     printf("Salah memasukkan pilihan! Ulangi!");
     gotoxy(26,16);textcolor(15);
     printf("Tekan Enter Untuk Melanjutkan");
     getch(); 
    }
   }while((menu<=0)||(menu>6));           
   
   printf("\n\n\n"); printf("Tekan M untuk kembali ke menu utama = ");
   kmbli_menu=getche();
  }while((kmbli_menu=='M')||(kmbli_menu=='m'));
  printf("\n\n");  
} 

void tambahDAK()
{}
void tampilDAK()
{}
void cariDAK()
{}
void hapusDAK()
{}
void ubahDAK()
{}
void DataAbsensiKaryawan()
{
  do
  {
   do
    {                     
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("  DATA  JENIS KARYAWAN  ");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Tambah Data          ");
    gotoxy(28,7);printf("2. Tampil Data          ");
    gotoxy(28,8);printf("3. Cari Data            ");
    gotoxy(28,9);printf("4. Ubah Data           ");
    gotoxy(28,10);printf("5. Hapus Data           ");
    gotoxy(28,11);printf("6. Kembali             ");
    gotoxy(28,13);printf("========================");
    gotoxy(28,14);printf("   Pilihan [1..6] = ");scanf("%i", &menu);
    switch(menu)
    {
      case 1:tambahDAK();break;        
      case 2:tampilDAK();break;
      case 3:cariDAK();break;
      case 4:ubahDAK();break;
      case 5:hapusDAK();break;
      case 6:Menu_Utama();break;
   }
   if((menu<=0)||(menu>6))
    {
     gotoxy(24,15);textcolor(LIGHTRED);
     printf("Salah memasukkan pilihan! Ulangi!");
     gotoxy(26,16);textcolor(15);
     printf("Tekan Enter Untuk Melanjutkan");
     getch(); 
    }
   }while((menu<=0)||(menu>6));           
   
   printf("\n\n\n"); printf("Tekan M untuk kembali ke menu utama = ");
   kmbli_menu=getche();
  }while((kmbli_menu=='M')||(kmbli_menu=='m'));
  printf("\n\n");
}

void tambah_DJK()
{}
void tampil_DJK()
{}
void cari_DJK()
{}
void hapus_DJK()
{}
void ubah_DJK()
{}
void DataGajiKaryawan()
{
  do
  {
   do
    {                     
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("  DATA  JENIS KARYAWAN  ");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Tambah Data          ");
    gotoxy(28,7);printf("2. Tampil Data          ");
    gotoxy(28,8);printf("3. Cari Data            ");
    gotoxy(28,9);printf("4. Ubah Data           ");
    gotoxy(28,10);printf("5. Hapus Data           ");
    gotoxy(28,11);printf("6. Kembali             ");
    gotoxy(28,13);printf("========================");
    gotoxy(28,14);printf("   Pilihan [1..6] = ");scanf("%i", &menu);
    switch(menu)
    {
      case 1:tambah_DJK();break;        
      case 2:tampil_DJK();break;
      case 3:cari_DJK();break;
      case 4:ubah_DJK();break;
      case 5:hapus_DJK();break;
      case 6:Menu_Utama();break;
   }
   if((menu<=0)||(menu>6))
    {
     gotoxy(24,15);textcolor(LIGHTRED);
     printf("Salah memasukkan pilihan! Ulangi!");
     gotoxy(26,16);textcolor(15);
     printf("Tekan Enter Untuk Melanjutkan");
     getch(); 
    }
   }while((menu<=0)||(menu>6));           
   
   printf("\n\n\n"); printf("Tekan M untuk kembali ke menu utama = ");
   kmbli_menu=getche();
  }while((kmbli_menu=='M')||(kmbli_menu=='m'));
  printf("\n\n");
}
