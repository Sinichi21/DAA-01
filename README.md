# Sorting Algorithm Analysis

Pada kesempatan kali ini kami akan menganalisis kompleksitas algoritma dari *4 jenis algoritma sorting*, yaitu:
- Redix Sort
- Bubble Sort
- Insertion Sort
- Selection Sort

## Radix Sort Algorithm
![Radix Sort](./radix.png)
Berikut merupakan analisis dari **Radix Sort Algorithm**
```bash
Deklarasi:
output[n]: integer;
count[10]: integer;
i: integer
exp: integer;
max: integer
Algoritma: 
max = arr[0];                                                            //1
i = 1;                                                                   //1
while(i < n) {                                                           //n
    if (arr[i] > max) {                                                  //n-1
        max = arr[i];                                                    //n-1
    }                                                                    
    i = i + 1;                                                           //2(n-1)
}
exp = 1                                                                  //1
while(max / exp > 0) {                                                   //m+1
    i = 0                                                                //m
    while(i < n) {                                                       //m(n+1)
        count[(arr[i] / exp) % 10] = count[(arr[i] / exp) % 10] + 1;     //m(6n)
        i = i + 1                                                        //m(2n)
    }
    i = 1                                                                //m
    while(i < 10) {                                                      //m(10)
        count[i] = count[i] + count[i - 1];                              //m(27)
        i = i + 1;                                                       //m(18)
    }
    i = n - 1;                                                           //2m                                                           
    while(i >= 0){                                                       //m(n+1)
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];                 //m(4n)
        count[(arr[i] / exp) % 10] = count[(arr[i] / exp) % 10] - 1;     //m(6n)
        i = i - 1;                                                       //m(2n)
    }
    i = 0;                                                               //m
    while(i < n) {                                                       //m(n+1)
        arr[i] = output[i];                                              //m(n)
        i = i + 1                                                        //m(2n)
    }
    exp = exp * 10                                                       //2m
}
```
Dari perhitunga tersebut didapatkan:
```bash
T(n)    = 1 + 1 + n + n-1 + n-1 +2(n-1) + 1 + m+1 + m + m(n+1) + m(6n) + m(2n) + m + m(10) + m(27) + m(18) + 2m + m(n+1) + m(4n) + m(6n) + m(2n) + m + m(n+1) + m(n) + m(2n) + 2m
        = 5n + 26mn + 66m
O(mn)
```
**Penjelasan untuk 'm'**

Pada Radix Sort Algorithm terdapat nilai max dimana digunakan untuk menghitung nilai terbesar. Nilai tersebut digunakan untuk melakukan perulangan sebanyak panjang bilangan. Sebagai contoh misalkan nilai terbesar dari suatu himpunan bilangan 1867, maka m = 4 dan akan melakukan perulangan sebanyak 4 kali pada baris 28 s/d 51. Jika nilai terbesar 75, maka akan melakukan perulangan sebanyak 2 kali.

## Bubble Sort Algorithm
![Bubble Sort](./bubble.png)
Berikut merupakan analisis dari **Bubble Sort Algorithm**
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

Pada perulangan kedua sudah pasti jumlah perulangan dimulai dengan n-1 kemudian n-2 kemudian n-3 sampai hanya 1 kali perulangan sehingga di dapat perulangan tersebut membentuk pola aritmatika dengan bilangan pertama didapatkan n-1 dan beda -1
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

## Insertion Sort
![Insertion Sort](./insertion.png)
Berikut merupakan analisis dari **Insertion Sort Algorithm**
```bash
Deklarasi:
i: integer
j: integer
key: integer
Algoritma:
i = 1;                                //1
while(i < n) {                        //n
    key = arr[i];                     //n-1
    j = i - 1;                        //2(n-1)
    while (j >= 0 && arr[j] > key){   //n(n+3)/2
        arr[j + 1] = arr[j];          //2(n(n+1)/2)
        j = j - 1;                    //2(n(n+1)/2)
    }
    arr[j + 1] = key;                 //n-1
    i = i + 1;                        //2(n-1)
}
```
Dari perhitunga tersebut didapatkan:
```bash
T(n)    = 1 + n + n-1 + 2(n-1) + n(n+3)/2 + 2(n(n+1)/2) + 2(n(n+1)/2) + n-1 + 2(n-1)
        = (5n^2 + 21n - 10)/2
O(n^2)
```
**Penjelasan untuk perulangan kedua**

Pada perulangan kedua sudah pasti jumlah perulangan dimulai dengan 1 kali perulangan kemudian 2 kali kemudian 3 kali sampai hanya n-1 kali perulangan sehingga di dapat perulangan tersebut membentuk pola aritmatika dengan bilangan pertama didapatkan 1 dan beda 1
```bash
a   = 1
b   = 1
Un  = a + (n-1)b
    = 1 + (n-1)1
    = n
Sn  = n/2(a + Un)
    = n/2(1 + n)
    = n(n+1)/2
```

## Selection Sort
![Selection Sort](./selection.png)
Berikut merupakan analisis dari Selection Sort Algorithm
```bash
Deklarasi:
i: integer
j: integer
minIndex: integer
temp: integer
Algoritma:
i = 0;                                    //1
while(i < n - 1) {                        //n
    minIndex = i;                         //n-1
    j = i + 1;                            //2(n-1)
    while(j < n) {                        //n(n)/2
        if (arr[j] < arr[minIndex]) {     //n(n-1)/2
            minIndex = j;                 //n(n-1)/2
        }
        j = j + 1;                        //2(n(n-1)/2)    
    }
    temp = arr[minIndex];                 //n-1
    arr[minIndex] = arr[i];               //n-1
    arr[i] = temp;                        //n-1
    i = i + 1;                            //2(n-1)
}
```
Dari perhitunga tersebut didapatkan:
```bash
T(n)    = 1 + n + n-1 + 2(n-1) + n(n)/2 + n(n-1)/2 + n(n-1)/2 + 2(n(n-1)/2) + n-1 + n-1 + n-1 + 2(n-1)
        = (5n^2 + 14n - 14)/2
O(n^2)
```
**Penjelasan untuk perulangan kedua**

Pada perulangan kedua sudah pasti jumlah perulangan dimulai dengan n-1 kemudian n-2 kemudian n-3 sampai hanya 1 kali perulangan sehingga di dapat perulangan tersebut membentuk pola aritmatika dengan bilangan pertama didapatkan n-1 dan beda -1
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
