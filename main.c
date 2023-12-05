# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <time.h>

struct {
	char user[50], pass[50], nama[50], alamat[50], info[50];
} data;

void login ( int* );
int user ();
int admin ();
void delay ( unsigned int );

//Fungsi Utama
void main () {
	int x, y, i;
	char a[50], b[50], temp[50], username[50];

	//Teks Selamat Datang
	char welcome[] = ("=== SELAMAT DATANG DI D'FREELANCE ===\n\n");
	for ( i = 0; welcome[i] != '\0'; i++ ) {
        printf("%c", welcome[i]);
        delay(40);
    }

    //Menu Utama
	menu:
	    fflush(stdin);
	    x = 100;
		printf("[1] Admin\n[2] User\n[0] Keluar\n\nPilih Menu: "); scanf("%d", &x); getchar();

    //Pemilihan Menu Utama
	switch ( x ) {
	    //Log In Admin, Username admin Password admin
		case 1: {
		    fflush(stdin);
		    system("cls");
			printf("Selamat Datang Admin, Silakan Log In\n\n");
            printf("Username: "); gets(a);
            printf("Password: "); gets(b);

            //Membaca Username & Password Admin
            if ( ( strcmp(a, "admin" ) == 0 ) && ( strcmp(b, "admin") == 0 ) ) {        //Jika Benar
                printf("\nLog In Berhasil!!!\n");
                system("pause");
                system("cls");
                admin ();           //Ke Fungsi Admin
                goto menu;          //Kembali Ke Menu Utama Setelah Log Out Dari Fungsi Admin
            }
            else {                                                                      //Jika Salah
                printf("\nMaaf, Username dan Password yang Anda masukan SALAH\n");
                system("pause");
                system("cls");
                printf("=== SELAMAT DATANG DI D'FREELANCE ===\n\n");
                goto menu;          //Kembali Ke Menu Utama
            }
			break;
		}
		//Menu Untuk User
		case 2: {
		    //Menu Log In & Registrasi Akun User
		    menu_user:
		        fflush(stdin);
                system("cls");
                y = 100;
                printf("Silakan pilih Log In jika sudah punya akun atau pilih Registrasi untuk membuat akun\n\n");
			    printf("[1] Log In\n[2] Registrasi\n[0] Kembali\n\nPilih Menu: "); scanf("%d", &y); getchar();

            //Pemilihan Menu Log In & Regitrasi Akun User
			switch ( y ) {
			    //Log In User
				case 1: {
				    fflush(stdin);
				    system("cls");

		            //Memberitahukan Berapa Lagi Sisa Percobaan
		            i = 3;
					while (i > 0) {
                        printf("----- LOG IN -----\n\n");
                        printf("Sisa Kesempatan Anda: %d kali\n", i);
        				login ( &i );           //Ke Fungsi Log In
						if (i > 1) {            //Jika Percobaan Salah
	    					printf("\nMaaf, Username dan Password yang Anda masukkan SALAH\n");
	    	                printf("Silakan coba lagi . . .\n");
	    	                system("pause");
	    	                system("cls");
						}
	    				if (i == 1) {           //Jika Percobaan Sudah Habis
	        				printf("\nMaaf, kesempatan Anda sudah HABIS\n");
	    	                system("pause");
	    	                system("cls");
	                        goto menu_user;     //Kembali Ke Menu Log In & Registrasi Akun User
						}
						i--;
                    }
					goto menu;          //Kembali Ke Menu Utama Setelah Log Out Dari Fungsi User
					break;
				}
				//Registrasi User
				case 2: {
                    //Menu Registrasi
                    menu_registrasi:
                        fflush(stdin);
                        system("cls");
                        printf("----- REGISTRASI -----\n\n");

                    FILE*registrasi;
                    registrasi = fopen("DATA_USER.dat", "ab+");

                    //Menginput Profil User
                    printf("Username    : "); gets(username);
                    while ( fread(&data, sizeof(data), 1, registrasi) == 1 ) {          //Membaca Username Yang Sudah Digunakan
                        if ( strcmp(data.user, username) == 0 ) {                       //Jika Username Sudah Digunakan
                            printf("\nMaaf username %s sudah digunakan\nSilakan gunakan username lain . . .\n", username);
                            system("pause");
                            system("cls");
                            fclose(registrasi);
                            goto menu_registrasi;           //Kembali Ke Menu Registrasi
                        }
                    }
                    strcpy(data.user, username);
                    printf("Password    : "); gets(data.pass);
                    printf("Nama        : "); gets(data.nama);
                    printf("Alamat      : "); gets(data.alamat);
                    printf("Info Kontak : "); gets(data.info);
                    fwrite(&data, sizeof(data), 1, registrasi);
                    fclose(registrasi);

                    printf("\nData Anda telah teregistrasi!!!\nTerima Kasih\n");
                    system("pause");
                    system("cls");
                    goto menu_user;         //Kembali Ke Menu Log In & Registrasi Akun User
					break;
				}
				//Kembali Ke Menu Utama
				case 0: {
				    system("cls");
                    printf("=== SELAMAT DATANG DI D'FREELANCE ===\n\n");
				    goto menu;          //Kembali Ke Menu Utama
				    break;
				}
				//Jika Pilihan Tidak Ada
				default: {
					printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
                    system("pause");
                    system("cls");
			        goto menu_user;         //Kembali Ke Menu Log In & Registrasi Akun User
					break;
				}
			}
		}
		//Keluar Program
		case 0: {
		    system("cls");
			char thanks[] = ("TERIMA KASIH TELAH MENGGUNAKAN D'FREELANCE\n");
			for (i = 0; thanks[i] != '\0'; i++) {
                printf("%c", thanks[i]);
                delay(40);
            }
            system("pause");
			exit(0);            //Keluar Program
			break;
		}
		//Jika Pilihan Tidak Ada
		default: {
			printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
			system("pause");
			system("cls");
			printf("=== SELAMAT DATANG DI D'FREELANCE ===\n\n");
			goto menu;          //Kembali Ke Menu Utama
			break;
	    }
    }
}

//Fungsi User
int user(){
	int n, i, x, y, a, b, c, count;
	char cari[50], name[50], title[50];
	strcpy(name, data.nama);

	//Menu Utama User
	menu_user:
	    fflush(stdin);
	    n = 100;
	    printf("=== MENU USER ===\n\n");
	    printf("Selamat Datang, %s\n", name);
        printf("[1] Jual Jasa\n[2] Beli Jasa\n[0] Log Out\n\nPilih Menu: "); scanf("%d", &n); getchar();

    //Pemilihan Menu Utama User
	switch ( n ) {
	    //Menu Jual Jasa
		case 1: {
		    //Menu Jual
			menu_jual:
			    fflush(stdin);
			    system("cls");
			    x = 100;
			    printf("=== MENU JUAL ===\n\n");
				printf("[1] Pendaftaran Jasa\n[2] Pengumuman Pembeli Jasa\n[0] Kembali\n\nPilih Menu: "); scanf("%d", &x); getchar();

            //Pemilihan Menu Jual
            switch ( x ) {
				//Mendaftarkan Jasa
				case 1: {
					//Menu Daftar
					menu_daftar:
					    fflush(stdin);
                        system("cls");
                        printf("----- PENDAFTARAN JASA -----\n\n");

                    struct {
                        char judul[50], kategori[50], infoj[50], infok[50];
                        int harga;
                    } data;

                    FILE*daftarjasa;
                    daftarjasa = fopen("DATA_JASA.dat", "ab+");

                    //Menginput Data Penyedia Jasa
                    printf("Judul               : "); gets(title);
                    while ( fread(&data, sizeof(data), 1, daftarjasa) == 1 ) {          //Membaca Judul Jasa Yang Sudah Digunakan
                        if ( strcmp(data.judul, title) == 0 ) {                         //Jika Judul Jasa Sudah Digunakan
                            printf("\nMaaf judul %s sudah digunakan\nSilakan gunakan judul lain . . .\n", title);
                            system("pause");
                            system("cls");
                            fclose(daftarjasa);
                            goto menu_daftar;           //Kembali Ke Menu Daftar
                        }
                    }
                    strcpy(data.judul, title);
                    printf("Kategori            : "); gets(data.kategori);
                    printf("Info Jasa           : "); gets(data.infoj);
                    printf("Info Kontak Penjual : "); gets(data.infok);
                    printf("Harga               : Rp."); scanf("%d", &data.harga); getchar();
                    fwrite(&data, sizeof(data), 1, daftarjasa);
                    fclose(daftarjasa);

                    printf("\nJasa Anda telah terdaftar!!!\nTerima Kasih\n");
                    system("pause");
                    system("cls");
                    goto menu_jual;         //Kembali Ke Menu Jual
					break;
				}
				//Menampilkan Pengumuman Pembeli Jasa
				case 2: {
				    fflush(stdin);
				    system("cls");
				    printf("=== DAFTAR PEMBELI JASA ===\n\n");

					struct{
        				char judul[50], nama[50], infoj[50], infok[50];
    				} data;

    				FILE*databeli;
					databeli = fopen("DATA_PEMBELI.dat","rb");

					//Mengoutput Data Pembeli Jasa
					i = 1;
					while ( fread(&data,sizeof(data), 1, databeli) == 1 ) {
                        printf("%d. Nama Jasa    : %s\n", i, data.judul);
                        printf("   Nama         : %s\n", data.nama);
                        printf("   Info Kontak  : %s\n", data.infok);
                        printf("   Keterangan   : %s\n", data.infoj);
                        printf("\n");
                        i++;
                	}
                	fclose(databeli);

                    system("pause");
                    system("cls");
                    goto menu_jual;         //Kembali Ke Menu Jual
					break;
				}
				//Kembali Ke Menu Utama User
				case 0: {
					system("cls");
					goto menu_user;         //Kembali Ke Menu Utama User
					break;
				}
				//Jika Pilihan Tidak Ada
				default: {
		        	printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
                    system("pause");
                    system("cls");
		        	goto menu_jual;         //Kembali Ke Menu Jual
		        	break;
	            }
            }
	        break;
        }
		//Menu Beli Jasa
		case 2: {
            //Menu Beli
		    menu_beli:
		        fflush(stdin);
                system("cls");
                y = 100;
			    printf("=== MENU BELI ===\n\n");
                printf("[1] Daftar Penjual Jasa\n[2] Cari Kategori Jasa\n[3] Pembelian Jasa\n[0] Kembali\n\nPilih Menu: "); scanf("%d", &y); getchar();

            //Pemilihan Menu Beli
			switch ( y ) {
				//Menampilkan Daftar Penjual Jasa
				case 1: {
				    system("cls");
				    printf("=== DAFTAR JASA ===\n\n");

				    FILE*daftarjasa;
                    daftarjasa = fopen("DATA_JASA.dat", "rb");

                    //Menghitung Jumlah Data Penjual Jasa
                    i = 0;
                    while ( fread(&data, sizeof(data), 1, daftarjasa) == 1 ) {
                        i++;
                    }
                    fclose(daftarjasa);

                    struct {
                        char judul[50], kategori[50], infoj[50], infok[50];
                        int harga;
                    } data, temp[i + 1], temp2;
                    temp[0].harga = -1;

                    daftarjasa = fopen("DATA_JASA.dat", "rb");

                    //Mengcopy Data Penjual Jasa Ke Array
                    a = 0, b = 0, c = 0;
                    rewind(daftarjasa);
                    while ( fread(&data, sizeof(data), 1, daftarjasa) != 0 ) {
                        strcpy(temp[a].judul, data.judul);
                        strcpy(temp[a].kategori, data.kategori);
                        strcpy(temp[a].infoj, data.infoj);
                        strcpy(temp[a].infok, data.infok);
                        temp[a].harga = data.harga;
                        a++;
                        c = a;
                    }
                    fclose(daftarjasa);

                    //Ascending Sort Data Penjual Jasa Berdasarkan Judul
                    for ( a = c - 1; a >= 1; a--) {
                        for ( b = 1; b <= a; b++) {
                            if ( strcmp(temp[b - 1].judul, temp[b].judul) > 0 ) {
                                temp2 = temp[b - 1];
                                temp[b - 1] = temp[b];
                                temp[b] = temp2;
                            }
                        }
                    }

                    //Mengoutput Daftar Penjual Jasa Berdasarkan Urutan Judul
                    if ( temp[0].harga != -1 ) {            //Jika Data Penjual Mempunyai Isi (Harga Tidak Minus)
                        for ( a = 0; a <= c - 1; a++) {
                            printf("%d. Judul               : %s\n", a + 1, temp[a].judul);
                            printf("   Kategori            : %s\n", temp[a].kategori);
                            printf("   Info Jasa           : %s\n", temp[a].infoj);
                            printf("   Info Kontak Penjual : %s\n", temp[a].infok);
                            printf("   Harga               : Rp.%d\n", temp[a].harga);
                            printf("\n");
                        }
                    }

                    system("pause");
                    system("cls");
                    goto menu_beli;         //Kembali Ke Menu Beli
					break;
				}
				//Mencari Jasa Berdasarkan Kategori
				case 2: {
				    fflush(stdin);
				    printf("\nKategori yang dicari: "); gets(cari);
                    system("cls");
                    printf("===== DAFTAR JASA =====\n\n");

                    struct {
                        char judul[50], kategori[50], infoj[50], infok[50];
                        int harga;
                    } data;

				    FILE*daftarjasa;
				    FILE*daftarjasa2;
				    daftarjasa = fopen("DATA_JASA.dat", "rb");
                    daftarjasa2 = fopen("DATA_KATEGORI.dat", "wb");

                    //Menampilkan Jasa Sesuai Kategori Yang Dicari
                    i = 1, count = 0;
                    while ( fread(&data, sizeof(data), 1, daftarjasa) == 1 ) {
                        if ( strcmp(data.kategori, cari) == 0) {                    //Jika Kategori Jasa Sesuai Yang Dicari
                            printf("%d. Judul               : %s\n", i, data.judul);
                            printf("   Kategori            : %s\n", data.kategori);
                            printf("   Info Jasa           : %s\n", data.infoj);
                            printf("   Info Kontak Penjual : %s\n", data.infok);
                            printf("   Harga               : Rp.%d\n", data.harga);
                            printf("\n");
                            i++;
                            count++;
                        }
                    }
                    fclose(daftarjasa);
                    fclose(daftarjasa2);

                    if ( count == 0 ) {         //Jika Kategori Jasa Tidak Ditemukan
                        printf("Maaf, Kategori %s TIDAK ADA\n", cari);
                    }
                    else {                      //Jika Kategori Jasa Ditemukan
                        printf("Kategori yang Anda cari: %s\n\n", cari);
                    }

                    system("pause");
                    system("cls");
					goto menu_beli;         //Kembali Ke Menu Beli
					break;
				}
				//Membeli Jasa
				case 3: {


					menu_pembeli:
					    fflush(stdin);
                        system("cls");
                        printf("----- PEMBELIAN JASA -----\n\n");

					struct {
        				char judul[50], nama[50], infoj[50], infok[50];
    				} data;

    				FILE*databeli;
                    databeli = fopen("DATA_PEMBELI.dat", "ab+");

                    //Menginput Data Pembeli Jasa
                    printf("Nama Jasa    : "); gets(title);
                    while ( fread(&data, sizeof(data), 1, databeli) == 1 ) {            //Membaca Nama Jasa Yang Sudah Ada Pembeli
                        if ( strcmp(data.judul, title) == 0 ) {                         //Jika Judul Jasa Sudah Ada Pembeli
                            printf("\nMaaf jasa %s sudah ada pembeli\nSilakan gunakan nama jasa lain . . .\n", title);
                            system("pause");
                            system("cls");
                            fclose(databeli);
                            goto menu_pembeli;
                        }
                    }
                    strcpy(data.judul, title);
                    printf("Nama Pembeli : "); gets(data.nama);
                    printf("Info Kontak  : "); gets(data.infok);
                    printf("Keterangan   : "); gets(data.infoj);
                    fwrite(&data, sizeof(data), 1, databeli);
                    fclose(databeli);

                    printf("\nAnda telah membeli jasa ini, tunggu info selanjutnya!!!\nTerima Kasih\n");
                    system("pause");
                    system("cls");
                    goto menu_beli;         //Kembali Ke Menu Beli
					break;
				}
				//Kembali Ke Menu Utama User
				case 0: {
					system("cls");
					goto menu_user;             //Kembali Ke Menu Utama User
					break;
				}
				//Jika Pilihan Tidak Ada
				default:{
		        	printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
		        	system("pause");
		        	system("cls");
		        	goto menu_beli;         //Kembali Ke Menu Beli
		        	break;
	            }
			}
            break;
        }
		//Log Out Akun User
		case 0: {
			printf("\nLog Out Berhasil!!!\n");
            system("pause");
            system("cls");
            printf("===SELAMAT DATANG DI D'FREELANCE===\n\n");
			break;
		}
		//Jika Pilihan Tidak Ada
		default: {
            printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
            system("pause");
            system("cls");
            goto menu_user;         //Kembali Ke Menu Utama User
            break;
	    }
	}
	return 0;
}

//Fungsi Admin
int admin(){
	int n, i, x, y, z, a, b, c, count;
	char hapus[50];

	//Menu Utama Admin
	menu_admin:
	    fflush(stdin);
	    n = 100;
	    printf("=== MENU ADMIN ===\n\n");
	    printf("[1] Data Penyedia Jasa\n[2] Profil User\n[3] Data Pembeli Jasa\n[0] Log Out\n\nPilih Menu: "); scanf("%d", &n); getchar();

    //Pemilihan Menu Utama Admin
	switch ( n ) {
		//Menampilkan Data Penyedia Jasa
		case 1: {
		    //Menu Data Penyedia Jasa
		    menu_data:
		        fflush(stdin);
                system("cls");
                y = 100;
                printf("=== DATA PENYEDIA JASA ===\n\n");

            FILE*daftarjasa;
			daftarjasa = fopen("DATA_JASA.dat", "rb");

            //Menghitung Jumlah Data Penjual Jasa
			i = 0;
            while ( fread(&data, sizeof(data), 1, daftarjasa) == 1 ) {
                i++;
            }
            fclose(daftarjasa);

			struct {
        		char judul[50], kategori[50], infoj[50], infok[50];
        		int harga;
    		} data, temp[i + 1], temp2;
    		temp[0].harga = -1;

    		daftarjasa = fopen("DATA_JASA.dat", "rb");

    		//Mengcopy Data Penjual Jasa Ke Array
			a = 0, b = 0, c = 0;
			rewind(daftarjasa);
			while ( fread(&data, sizeof(data), 1, daftarjasa) != 0 ) {
				strcpy(temp[a].judul, data.judul);
				strcpy(temp[a].kategori, data.kategori);
				strcpy(temp[a].infoj, data.infoj);
				strcpy(temp[a].infok, data.infok);
				temp[a].harga = data.harga;
				a++;
				c = a;
			}
			fclose(daftarjasa);

			//Ascending Sort Data Penjual Jasa Berdasarkan Judul
			for ( a = c - 1; a >= 1; a-- ) {
				for ( b = 1; b <= a; b++ ) {
					if ( strcmp(temp[b - 1].judul, temp[b].judul) > 0 ) {
						temp2 = temp[b - 1];
						temp[b - 1] = temp[b];
						temp[b] = temp2;
					}
				}
			}

			//Mengoutput Data Penjual Jasa Berdasarkan Urutan Judul
            if ( temp[0].harga != -1 ) {            //Jika Data Penjual Mempunyai Isi (Harga Tidak Minus)
                for ( a = 0; a <= c - 1; a++ ) {
                    printf("%d. Judul               : %s\n", a + 1, temp[a].judul);
                    printf("   Kategori            : %s\n", temp[a].kategori);
                    printf("   Info Jasa           : %s\n", temp[a].infoj);
                    printf("   Info Kontak Penjual : %s\n", temp[a].infok);
                    printf("   Harga               : Rp.%d\n", temp[a].harga);
                    printf("\n");
                }
            }

			printf("[1] Hapus Jasa\n[0] Kembali\n\nPilih Menu: "); scanf("%d",&y); getchar();

			//Pemilihan Menu Data Penyedia Jasa
            switch ( y ) {
                //Hapus Jasa
                case 1: {
                    fflush(stdin);
                    printf("\nJudul jasa yang akan dihapus: "); gets(hapus);

                    struct{
                        char judul[50], kategori[50], infoj[50], infok[50];
                        int harga;
                    } data;

                    FILE*daftarjasa;
                    FILE*daftarjasa2;
                    daftarjasa = fopen("DATA_JASA.dat", "rb");
                    daftarjasa2 = fopen("DATA_JASA2.dat", "wb");

                    //Menghapus Jasa Yang Dipilih
                    while ( fread(&data, sizeof(data), 1, daftarjasa) == 1 ) {
                        if ( strcmp(data.judul, hapus) != 0 ) {                 //Jika Judul Jasa Yang Mau Dihapus Ditemukan
                            fwrite(&data, sizeof(data), 1, daftarjasa2);
                        }
                    }
                    fclose(daftarjasa);
                    fclose(daftarjasa2);
                    remove("DATA_JASA.dat");
                    rename("DATA_JASA2.dat", "DATA_JASA.dat");

                    printf("\nJasa %s telah dihapus\n", hapus);
                    system("pause");
                    system("cls");
                    goto menu_data;         //Kembali Ke Menu Data Penyedia Jasa
                    break;
                }
                //Kembali Ke Manu Utama Admin
                case 0: {
                    system("cls");
                    goto menu_admin;            //Kembali Ke Menu Utama Admin
                    break;
                }
                //Jika Pilihan Tidak Ada
                default: {
                    printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
                    system("pause");
                    system("cls");
                    goto menu_data;         //Kembali Ke Menu Data Penyedia Jasa
                    break;
                }
            }
            break;
        }
		//Menampilkan Profil User
		case 2: {
		    //Menu Profil User
		    menu_profil:
		        fflush(stdin);
		        system("cls");
		        x = 100;
                printf("=== PROFIL USER ===\n\n");

			FILE*registrasi;
			registrasi = fopen("DATA_USER.dat", "rb");

			//Menghitung Jumlah Data Profil User
			i = 0;
            while ( fread(&data, sizeof(data), 1, registrasi) == 1 ) {
                i++;
            }
            fclose(registrasi);

            struct{
                char user[50], pass[50], nama[50], alamat[50], info[50];
            } data, temp[i + 1], temp2;
            strcpy(temp[0].nama, "\0");

    		registrasi = fopen("DATA_USER.dat", "rb");

    		//Mengcopy Data Profil User Ke Array
    		a = 0, b = 0, c = 0;
			rewind(registrasi);
			while ( fread(&data, sizeof(data), 1, registrasi) != 0 ) {
				strcpy(temp[a].user, data.user);
				strcpy(temp[a].pass, data.pass);
				strcpy(temp[a].nama, data.nama);
				strcpy(temp[a].alamat, data.alamat);
				strcpy(temp[a].info, data.info);
				a++;
				c = a;
			}
			fclose(registrasi);

			//Ascending Sort Data Profil User Berdasarkan Username
			for ( a = c - 1; a >= 1; a-- ) {
				for ( b = 1; b <= a; b++ ) {
					if ( strcmp(temp[b - 1].user, temp[b].user) > 0 ) {
						temp2 = temp[b - 1];
						temp[b - 1] = temp[b];
						temp[b] = temp2;
					}
				}
			}

			//Mengoutput Data Profil User Berdasarkan Urutan Username
			if ( strcmp(temp[0].nama, "\0") != 0 ) {            //Jika Data Profil User Mempunyai Isi (Nama Tidak Null)
                for ( a = 0; a <= c - 1; a++ ) {
                    printf("%d. Username    : %s\n", a + 1, temp[a].user);
                    printf("   Password    : %s\n", temp[a].pass);
                    printf("   Nama        : %s\n", temp[a].nama);
                    printf("   Alamat      : %s\n", temp[a].alamat);
                    printf("   Info Kontak : %s\n", temp[a].info);
                    printf("\n");
                }
			}

			printf("[1] Hapus User\n[0] Kembali\n\nPilih Menu: "); scanf("%d", &x); getchar();

			//Pemilihan Menu Profil User
            switch ( x ) {
            	//Hapus Profil User
            	case 1: {
            	    fflush(stdin);
            	    printf("\nUsername yang dihapus: "); gets(hapus);

	                FILE*registrasi;
	                FILE*registrasi2;
	                registrasi = fopen("DATA_USER.dat", "rb");
                	registrasi2 = fopen("DATA_USER2.dat", "wb");

                	//Menghapus Profil User Yang Dipilih
                    while ( fread(&data, sizeof(data), 1, registrasi) == 1 ) {
                        if ( strcmp(data.user, hapus) != 0 ) {                  //Jika Username Yang Mau Dihapus Ditemukan
                            fwrite(&data, sizeof(data), 1, registrasi2);
                        }
                    }
                    fclose(registrasi);
                    fclose(registrasi2);
                    remove("DATA_USER.dat");
                    rename("DATA_USER2.dat", "DATA_USER.dat");

					printf("\nUsername %s telah dihapus\n", hapus);
					system("pause");
                    system("cls");
					goto menu_profil;           //Kembali Ke Menu Profil User
					break;
				}
				//Kembali Ke Manu Utama Admin
				case 0: {
					system("cls");
					goto menu_admin;            //Kembali Ke Manu Utama Admin
					break;
				}
				//Jika Pilihan Tidak Ada
				default: {
					printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
					system("pause");
					system("cls");
					goto menu_profil;           //Kembali Ke Menu Profil User
					break;
				}
			}
        break;
        }
        //Menampilkan Data Pembeli Jasa
        case 3: {
            //Menu Data Pembeli Jasa
            menu_pembeli:
                fflush(stdin);
                system("cls");
                z = 100;
                printf("=== DATA PEMBELI JASA ===\n\n");

            FILE*databeli;
            databeli = fopen("DATA_PEMBELI.dat", "rb");

            struct{
                char judul[50], nama[50], infoj[50], infok[50];
            } data;

            //Mengoutput Data Pembeli Jasa
            i = 1;
            while ( fread(&data,sizeof(data), 1, databeli) == 1 ) {
                printf("%d. Nama Jasa    : %s\n", i, data.judul);
                printf("   Nama         : %s\n", data.nama);
                printf("   Info Kontak  : %s\n", data.infok);
                printf("   Keterangan   : %s\n", data.infoj);
                printf("\n");
                i++;
            }
            fclose(databeli);

            printf("[1] Hapus Pembeli Jasa\n[0] Kembali\n\nPilih Menu: "); scanf("%d", &z); getchar();

            //Pemilihan Menu Data Pembeli Jasa
            switch ( z ) {
            	//Hapus Pembeli Jasa
            	case 1: {
            	    fflush(stdin);
            	    printf("\nNama Jasa yang dihapus: "); gets(hapus);

	                FILE*databeli;
	                FILE*databeli2;
	                databeli = fopen("DATA_PEMBELI.dat", "rb");
                	databeli2 = fopen("DATA_PEMBELI2.dat", "wb");

                	//Menghapus Pembeli Jasa Yang Dipilih
                    while ( fread(&data, sizeof(data), 1, databeli) == 1 ) {
                        if ( strcmp(data.judul, hapus) != 0 ) {                 //Jika Nama Jasa Yang Mau Dihapus Ditemukan
                            fwrite(&data, sizeof(data), 1, databeli2);
                        }
                    }
                    fclose(databeli);
                    fclose(databeli2);
                    remove("DATA_PEMBELI.dat");
                    rename("DATA_PEMBELI2.dat", "DATA_PEMBELI.dat");

					printf("\nPembeli Jasa %s telah dihapus\n", hapus);
					system("pause");
                    system("cls");
					goto menu_pembeli;          //Kembali Ke Menu Pembeli Jasa
					break;
				}
				//Kembali Ke Manu Utama Admin
				case 0: {
					system("cls");
					goto menu_admin;            //Kembali Ke Manu Utama Admin
					break;
				}
				//Jika Pilihan Tidak Ada
				default: {
					printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
					system("pause");
					system("cls");
					goto menu_pembeli;          //Kembali Ke Menu Pembeli Jasa
					break;
				}
			}
        }
		//Log Out Admin
		case 0: {
			printf("\nLog Out Berhasil!!!\n");
            system("pause");
            system("cls");
            printf("=== SELAMAT DATANG DI D'FREELANCE ===\n\n");
			break;
		}
		//Jika Pilihan Tidak Ada
		default: {
		    printf("\nMaaf, Pilihan Anda TIDAK ADA\n");
		    system("pause");
		    system("cls");
		    goto menu_admin;            //Kembali Ke Menu Utama Admin
		    break;
	    }
    }
	return 0;
}

//Fungsi Log In User
void login ( int*i ) {
	FILE*registrasi;
	registrasi = fopen("DATA_USER.dat", "rb");

	char a[50], b[50];
	printf("Username: "); gets(a);
	printf("Password: "); gets(b);

	//Membaca Username & Password User
	while ( fread(&data, sizeof(data), 1, registrasi) == 1 ) {
	    if ( ( strcmp(a, data.user) == 0 ) && ( strcmp(b, data.pass) == 0 ) ) {         //Jika Username & Password Benar
	    	printf("\nLog In Berhasil!!!\n");
            system("pause");
            system("cls");
	    	*i = *i * 0;
	    	fclose(registrasi);
	    	user ();         //Ke Fungsi User
	    }
	    fclose(registrasi);
	}
}

//Fungsi Delay Print Teks
void delay ( unsigned int ms ) {
    clock_t start = clock();
    while((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);
}
