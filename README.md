# Sorting Algorithm Analysis

Pada kesempatan kali ini kami akan menganalisis kompleksitas algoritma dari *4 jenis algoritma sorting*, yaitu:
- Redix Sort
- Bubble Sort
- Insertion Sort
- Selection Sort

## Radix Sort Algorithm
Berikut merupakan analisis dari Radix Sort Algorithm

## Bubble Sort Algorithm
Berikut merupakan analisis dari Bubble Sort Algorithm
```bash
Deklarasi:
temp: integer;
swapped: boolean;
Algoritma:
int i = 0                            //1
while(i < n - 1){                    //2n
    swapped = false;                 //n-1
    int j = 0                        //n-1
    while(j < n - i - 1){            //3(n(n)/2)
        if (arr[j] > arr[j + 1]) {   //2(n(n-1)/2)
            temp = arr[j];           //1(n(n-1)/2)
            arr[j] = arr[j + 1];     //2(n(n-1)/2)
            arr[j + 1] = temp;       //2(n(n-1)/2)
            swapped = true;          //n(n-1)/2
        }
        j = j + 1;                   //2(n(n-1)/2)
    }
    if (!swapped){                   //n-1
        break;                       //n-1
    }
    i = i + 1;                       //2(n-1)
}
```
Dari perhitunga tersebut didapatkan:
```bash
T(n)    = 1 + 2n + n-1 + n-1 + 3(n(n)/2) + 2(n(n-1)/2) + 1(n(n-1)/2) + 2(n(n-1)/2) + 2(n(n-1)/2) + n(n-1)/2 + 2(n(n-1)/2) + n-1 + n-1 + 2(n-1)
        = (13n^2 + 6n - 10)/2
O(n^2)
```
**Penjelasan untuk perulangan kedua**
Pada perulangan kedua sudah pasti dimulai dengan n-1 kemudian n-2 kemudian n-3 sampai hanya 1 kali perulangan sehingga di dapat perulangan tersebut membentuk pola aritmatika dengan bilangan pertama didapatkan n-1 dan beda -1
```bash
a   = n-1
b   = -1
Un  = a + (n-1)b
    = n-1 + (n-1)*(-1)
    = n-1 + (-n+1)
    = 0
Sn  = n/2(a + Un)
    = n/2(n-1 + 0)
    = n(n-1)/2
```
