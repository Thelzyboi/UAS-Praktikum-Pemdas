#include "roti.h"

// void Update(char input[]) //masih testing berubah tidak, struct belum diimplementasikan
// {
//     char uChar[10];
//     char newData[10];
//     FILE *fp = fopen("pelanggan.txt","r+    ");
//     if (fp==NULL)
//     {
//         printf("File tidak bisa dibuka");
//     }

//     while (1)
//     {
//         fgets(uChar,10,fp);
//         if (strcmp(uChar,input)==0);
//         {
//             fseek(fp,10-1,SEEK_CUR); //angka yang tengah harusnya menghitung panjang variabel lalu di mulai dari belakang
//             printf("Masukan isi baru");
//             scanf("%s",&newData);
//             fputs(newData,fp);
//             fseek(fp,0,SEEK_CUR); //blum beres angka ditengah harusnya "sampai bertemu tab/enter"
//         }
//         if (uChar==EOF)
//         {
//             break;
//         }
//     }
//     fclose(fp);

// }

void CreateRoti(){
    int pil;
    FILE *output = fopen("roti.dat", "a+   "); // open the file to write
    pTRoti=(struct tokoroti *)malloc(sizeof(struct tokoroti));
    if (!output) {
        // return -1; // error
    }
    printf("Masukan pilihan MASUK ROTI: ");
    scanf("%d",&pil);
    switch (pil)
    {
    case 1:
        printf("Masukan Kode Roti: ");
        scanf("%9s",pTRoti->rt.kdRoti);
        printf("Masukan Nama Roti: ");
        scanf("%9s",pTRoti->rt.namaRoti);
        printf("Masukan Harga: ");
        scanf("%d",&pTRoti->rt.harga);
        printf("Masukan jenis roti: ");
        scanf("%s",pTRoti->rt.jenisRoti);
        printf("Masukan Stok: ");
        scanf("%d",&pTRoti->rt.stok);
        break;
    case 2:
        //pelanggan
        printf("Masukan Kode Pelanggan: ");
        scanf("%s",pTRoti->kry.kodeK);
        
        break;
    case 3:
        //karyawan
        break;
    case 4:
        //pembayaran
        break;
    default:
        break;
    }
    //for (int i = 0; i < 1; ++i) {
        // write a line - see fprintf documentation
        // printf("Masukan Kode Roti: ");
        // scanf("%9s",pRoti->kdRoti);
        // printf("Masukan Nama Roti: ");
        // scanf("%9s",pRoti->namaRoti);
        // printf("Masukan Harga: ");
        // scanf("%d",&pRoti->harga);
        // printf("1. Roti Tawar\n");
        // printf("2. Roti Gandum\n");
        // printf("3. Roti Manis\n");
        // printf("Masukan pilihan roti: ");
        // scanf("%d",&pil);
        // switch (pil)
        // {
        // case 1:
        //     strcpy(pRoti->jenisRoti,"Roti Tawar");
        //     break;
        // case 2:
        //     strcpy(pRoti->jenisRoti, "Roti Gandum");
        //     break;
        // case 3:
        //     strcpy(pRoti->jenisRoti, "Roti Manis");
        //     break;
        // default:
        //     printf("Pilihan tidak ditemukan");
        //     break;
        // }
        fwrite (pTRoti, sizeof(struct tokoroti), 1, output);

        // I'm missing some error checks here - you should not
    //}
    fclose(output); // close
    // return 0;
}

void userlogin(void){
    FILE *fp;
    char uName[10], pwd[10],name[10];int i;char c;

    pUser=(struct user *)malloc(sizeof(struct user));

    printf("1. Login Through An Existing Account\n2. Create New account\n");
    scanf("%d",& i);
    //system("cls");
    switch(i){
        case 1:
            if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            printf("Username: ");
            scanf("%9s",uName);
            printf("Password: ");
            scanf("%9s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
                    printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) {
                        printf ("Match password\n");
                        //accessUser();
                    }
                }
            }
            break;

        case 2:
            do
            {
                if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                printf("Kode Admin: ");
                scanf("%9s",pUser->kodeAdmin);
                printf("Name: ");
                scanf("%9s",pUser->name);
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp);
                printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
            }while(c=='Y'||c=='y');
            break;
    }
    free ( pUser);//free allocated memory
    fclose(fp);
}

void Read(){
    FILE *output;
    struct roti pRoti;
    output = fopen("roti.dat","r");

    printf("Lihat Data Roti\n");

    if(output==NULL){
        fprintf(stderr,"Can't open file");
    } else{
        printf("Ini Adalah Roti\n");
    } while(fread(&pRoti,sizeof(struct roti),1,output)){
        printf("Kode Roti: %s\n",pRoti.kdRoti);
        printf("Nama Roti: %s\n",pRoti.namaRoti);
        printf("Harga: %d\n",pRoti.harga);
        printf("Jenis Roti: %s",pRoti.jenisRoti);
    }
    fclose(output);
    getch();

}