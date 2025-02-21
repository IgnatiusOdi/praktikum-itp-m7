# praktikum-itp-m7

## Praktikum ITP M7

### No 1

Buatlah program bangun-bangun sederhana. berikut adalah tampilannya:

```
MENU
====
1. Add segitiga berisi
2. Add kotak berisi
3. Add kotak bolong
4. View bangun
5. Save
>>>
```

Program memiliki 5 menu utama yaitu:

1. Add segitiga berisi
   pada menu ini program akan meminta inputan ukuran segitiga berisi. Setelah itu segitiga akan masuk ke dalam daftar bangun.

```
>>> 1
ukuran segitiga: 3
```

2. Add kotak berisi
   pada menu ini program akan meminta inputan ukuran kotak berisi. Setelah itu kotak berisi akan masuk ke dalam daftar bangun.

```
>>> 2
ukuran segitiga: 4
```

3. Add kotak bolong
   pada menu ini program akan meminta inputan ukuran kotak bolong. Setelah itu kotak bolong akan masuk ke dalam daftar bangun.

```
>>> 3
ukuran segitiga: 5
```

4. View bangun
   pada menu ini program akan menampilkan data bangun beserta bangun yang sudah didaftarkan.

```
>>> 4
jumlah bangun: 3
segitiga: 1
kotak berisi: 1
kotak bolong: 1

*
**
***

****
****
****
****


****
*  *
*  *
****
```

5. Save
   pada menu ini program akan menyimpan semua data bangun yang dimasukan kedalam sebuah txt.

Jika sudah ada file txt, maka saat program di run, program akan meload semua mahasiswa dalam txt dan langsung masuk ke daftar mahasiswa.

### Tugas

Buatlah program pencatatan menu Restaurant sederhana yang akan memiliki 6 fitur (insert, update, delete, list all, sort dan exit). Jika fitur insert dipilih maka program akan meminta inputan berupa nama menu, harga menu sebelum pajak, dan harga menu setelah pajak. Jika menu update dipilih maka mintalah inputan nama menu yang ingin diubah harganya (program akan meminta inputan harga menu sebelum dan sesudah pajak). Jika menu delete dipilih maka mintalah inputan nama menu yang akan di hapus. (Semua yang meminta nama, jika nama tidak di temukan maka tampilkan pesan gagal mencari nama tersebut). Jika menu list all dipilih maka tampilkan semua data menu (nama, harga sebelum pajak dan harga sesudah pajak). Jika menu sort dipilih maka tampilkan list data menu urut dari harga sebelum pajak terkecil hingga terbesar. Jika Exit maka program akan berhenti.

MENU UTAMA

```
+++++ADMIN+++++
===============
MENU RESTAURANT
===============
1. Insert
2. Update
3. Delete
4. List all
5. Sort
6. Exit
```

INSERT

```
>> 1

INSERT
======
nama menu   : burger
harga       : 15000
harga+pajak : 16500
```

UPDATE

```
>> 2

UPDATE
======
nama menu   : burger
harga       : 20000
harga+pajak : 22000
harga telah di update
```

DELETE

```
>> 3

DELETE
=====
nama menu   : burger
nama menu telah di delete
```

LIST ALL

```
>> 4
1. ayam (35000) - 38500
2. burger (15000) - 16500
```

SORT

```
>> 5
1. burger (15000) - 16500
2. ayam (35000) - 38500
```

EXIT

```
>> 6
```
