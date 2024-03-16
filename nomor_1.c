#include <stdio.h>

// Fungsi untuk konversi kartu huruf menjadi angka
int konversiKartuAngka(char *kartu) {
  int kartuAngka;
  
  // Cek angka 1 jika kartu ini bernilai 1 dan setelahnya TIDAK bernilai 0
  if (kartu[0] == '1' && kartu[1] != '0') kartuAngka = 1;
  // Cek angka 10 jika kartu ini bernilai 1 dan setelahnya bernilai 0
  else if (kartu[0] == '1' && kartu[1] == '0') kartuAngka = 10;
  // Cek angka 11, 12, dan 13 berdasarkan huruf dari kartu ini
  else if (kartu[0] == 'J') kartuAngka = 11;
  else if (kartu[0] == 'Q') kartuAngka = 12;
  else if (kartu[0] == 'K') kartuAngka = 13;
  // Konversikan kartu ini menjadi integer
  else kartuAngka = kartu[0] - '0';

  return kartuAngka; 
}

// Fungsi untuk mencari jumlah minimal pertukaran agar kartu menjadi urut
void sortKartu(char *kartu, int *kartuAngka, int jumlah) {
  // Inisialisasi jumlah pertukaran
  int jumlahTukar = 0;

  // Gunakan algoritma selection sort karena hanya algoritma ini yang sesuai dengan contoh output
  for (int i = 0; i < jumlah; i++) {
    // Inisialisasi index dengan nilai terkecil untuk setiap iterasi
		int minIndex = i;
    
    // Cek apakah ada index lain dengan value lebih besar dari index awal
		for (int j = i; j < jumlah; j++) {
			if (kartuAngka[j] < kartuAngka[minIndex]) {
				minIndex = j;
			}
		}

    // Cek apakah index terkecil sama dengan index perulangan, jika sama maka akan dilewati agar output bisa efisien
    if (minIndex != i) {
      // Melakukan pertukaran array kartu bentuk angka
      int tempA = kartuAngka[i];
      kartuAngka[i] = kartuAngka[minIndex];
      kartuAngka[minIndex] = tempA;
      
      // Melakukan pertukaran kartu bentuk huruf
      int tempB = kartu[i];
      kartu[i] = kartu[minIndex];
      kartu[minIndex] = tempB;

      // Menampilkan hasil dari pertukaran untuk setiap iterasi
      // ++jumlahTukar untuk menambahkan jumlahTukar yang sekarang dengan 1, ++ di awal agar jumlahTukar ditambahkan
      // pada iterasi saat ini juga, kalau menggunakan ++ di akhir maka jumlahTukar ditambahkan di iterasi berikutnya
      printf("Pertukaran ke-%d: ", ++jumlahTukar);
      for (int i = 0; i < jumlah; i++) {
        // Cek apakah isi dari kartu tersebut adalah 10 karena diantara semua pilihan kartu hanya angka 10 yang 2 digit
        if (kartuAngka[i] == 10) {
          printf("%d ", kartuAngka[i]);
        } else {
          printf("%c ", kartu[i]);
        }
      }
      printf("\n");
    }
	}
  
  // Menampilkan jumlah pertukaran yang DIBUTUHKAN agar kartu bisa urut
  printf("%d", jumlahTukar);
}

int main(int argc, char const *argv[]) {
  // Inisialisasi jumlah kartu
  int jumlah;
  scanf("%d", &jumlah);

  // Array kartu
  char kartu[jumlah];
  // Array kartu yang dikonversi ke angka
  int kartuAngka[jumlah];

  // Lakukan input char sebanyak jumlah yang dimasukkan
  for (int i = 0; i < jumlah; i++) {
    scanf(" %s", &kartu[i]);
    // Masukkan kartu huruf yang diubah menjadi kartu angka agar bisa disorting
    kartuAngka[i] = konversiKartuAngka(&kartu[i]); 
  }

  // Jalankan fungsi sortKartu
  sortKartu(kartu, kartuAngka, jumlah);
  
  return 0;
}