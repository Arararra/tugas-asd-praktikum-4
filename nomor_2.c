#include <stdio.h>

// Fungsi untuk mencari kemungkinan perpindahan bidak kuda dari awal posisi
void kemungkinanPindah(int baris, int kolom) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == baris && j == kolom) {
        printf("1 ");
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  // Inisialisasi posisi dari bidak kuda
  int posisi[2];
  for (int i = 0; i < 2; i++) {
    scanf(" %d", &posisi[i]);
  }

  // Jalankan fungsi kemungkinanPindah
  kemungkinanPindah(posisi[0], posisi[1]);

  return 0;
}