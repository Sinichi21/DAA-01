#include <stdio.h>

// Fungsi untuk melakukan pengurutan gelembung
void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Inisialisasi variabel swapped

        for (int j = 0; j < n - i - 1; j++) {
            // Membandingkan dua elemen berturut-turut
            if (arr[j] > arr[j + 1]) {
                // Jika elemen saat ini lebih besar dari elemen berikutnya, tukar
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set swapped menjadi 1 jika ada pertukaran
            }
        }

        // Jika tidak ada pertukaran dalam iterasi ini, daftar sudah terurut
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Daftar terurut dengan Bubble Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
