#include <stdio.h>

// Fungsi untuk mencari kemungkinan perpindahan bidak kuda dalam pola L
void kemungkinanPindah(int baris, int kolom, int *papan) {
  // Inisialisasi algoritma perhitungan kemungkinan perpindahan
  int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
  int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

  // Algoritma untuk mencari cell yang kemungkinan bisa ditempati
  for (int i = 0; i < 8; i++) {
    // Logika dari operasi ini adalah menjumlahkan baris dan kolom yang dipilih dengan array x dan y sesuai dengan index iterasi
    // agar membentuk pola L yang bisa dilakukan oleh bidak kuda
    int kemungkinanX = baris + x[i];
    int kemungkinanY = kolom + y[i];

    // Cek apakah posisi kemungkinan bidak kuda yang baru masih berada di dalam papan 8x8, jika iya maka nilainya diubah menjadi 1
    if (kemungkinanX >= 0 && kemungkinanX < 8 && kemungkinanY >= 0 && kemungkinanY < 8) {
      // Parameter papan berisi alamat pertama dari array papan 8x8, disini kita membaca array papan 2 dimensi sebagai 1 dimensi
      // dengan rumus "(baris yang dicari * jumlah kolom) + kolom yang dicari" sehingga jika posisi kuda adalah baris 2 kolom 2,
      // maka kemungkinan pertamanya berada pada index "(4 * 8) + 3 = 35" yang dimana index 35 dalam array papan 8x8 adalah [4][3]
      // yang nilainya kemudian akan diubah menjadi angka 1
      papan[(kemungkinanX * 8) + kemungkinanY] = 1;
    }
  }
}

int main() {
  // Inisialisasi papan catur 8x8 dengan nilai awal 0 untuk setiap cellnya
  int papan[8][8] = { {0} };

  // Inisialisasi posisi awal bidak kuda yang akan dipindahkan
  int posisi[2];
  for (int i = 0; i < 2; i++) {  
    scanf(" %d", &posisi[i]);
  }

  // Jalankan fungsi kemungkinanPindah
  // Posisi[0] merupakan baris, posisi[1] merupakan kolom, dan &papan[0][0] merupakan alamat dari isi papan yang pertama
  kemungkinanPindah(posisi[0], posisi[1], &papan[0][0]);

  // Menampilkan papan 8x8 dengan kemungkinan posisi baru bidak kuda yang nilainya telah diganti dengan 1
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("%d ", papan[i][j]);
    }
    printf("\n");
  }

  return 0;
}
