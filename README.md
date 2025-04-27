<div align="center">
  <h1>C++ Module 09</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>
</div>

<p align="center">
Bu proje, **C++** dilinde **STL (Standard Template Library)** kullanarak ileri seviye veri yapıları ve algoritma mantığını pekiştirmeyi hedefleyen 3 egzersizten oluşur. Her egzersiz, farklı bir STL konteyneri kullanımını zorunlu kılar ve öğrencinin kapsayıcı (container) kullanımı, algoritmalar, zaman hesaplama ve hata yönetimi konularında pratik yapmasını sağlar.
</p>

---

## İçindekiler 📚
  - [Ex00 - Bitcoin Exchange](#ex00)
    - [Kapsayıcı Kullanımı](#kapsayici-kullanimi)
    - [Map Nedir?](#map-nedir)
    - [Hata Yönetimi](#hata-yonetimi)
    - [std::istringstream Nedir?](#istringstream-nedir)
  - [Ex01 - Reverse Polish Notation](#ex02)
    - [Kapsayıcı Kullanımı](#ex01-kapsayici-kullanimi)
    - [Stack Nedir?](#stack-nedir)
    - [RPN Hesaplaması](#rpn-hesaplamasi)
  - [Ex02 - PmergeMe](#ex02)
    - [Kapsayıcı Kullanımı](#ex02-kapsayici-kullanimi)
    - [Ford-Johnson Algoritması](#ford-johnson-algoritmasi)
    - [Ford-Johnson (Merge-Insertion Sort) Mantığı](#mantigi)
    - [Jacobsthal Sayıları](#jacobsthal-sayilari)
    - [Zaman Ölçümü ve Performans](#zaman-olcumu-ve-performans)

---

## <a name="ex00"></a>Ex00 - Bitcoin Exchange

Belirli bir tarih ve miktar için, Bitcoin fiyat veritabanına göre değer hesaplayan bir program.

Kullanıcıdan alınan tarih ve değer bilgilerinin bir CSV dosyasındaki fiyatlarla çarpılması sağlanır.

### <a name="kapsayici-kullanimi"></a>Kapsayıcı Kullanımı
- `std::map` kullanılır.
- Tarih-fiyat çiftleri sıralı olarak tutulur.
- Tarih bulunamazsa `lower_bound()` ile en yakın önceki tarih bulunur.

### <a name="map-nedir"></a>Map Nedir?

`std::map`, **C++ STL**'de anahtar-değer çiftlerini **sıralı** tutan bir konteynerdir.

**Özellikleri:**
- Anahtarlar benzersizdir.
- Otomatik küçükten büyüğe sıralama yapar.
- Arama, ekleme, silme gibi işlemler `O(log n)` zamanda gerçekleşir.
- `lower_bound()` fonksiyonuyla belirli bir anahtara en yakın büyük veya eşit anahtar bulunabilir.

**Örnek Kullanım:**

```cpp
std::map<std::string, float> bitcoinRates;
bitcoinRates["2011-01-03"] = 0.3f;
```

## <a name="istringstream-nedir"></a> std::istringstream Nedir?

`std::istringstream`, bir `std::string` üzerinden veri okumak için kullanılan bir giriş akışı (input stream) aracıdır.

- `#include <sstream>` kütüphanesi ile kullanılır.
- Dosya veya `cin` gibi davranarak string'den veri çeker.

**Örnek Kullanım:**

```cpp
#include <sstream>
#include <iostream>

int main() {
    std::string data = "42 3.14 hello";
    std::istringstream stream(data);

    int i;
    double d;
    std::string s;

    stream >> i >> d >> s;

    std::cout << i << " " << d << " " << s << std::endl;
    return 0;
}
```

**Çıktı:**
```bash
42 3.14 hello
```

**Avantajları:**
- String verileri kolayca parçalayabilir ve uygun türlere dönüştürebilirsiniz.

### <a name="hata-yonetimi"></a>Hata Yönetimi

- Geçersiz tarih formatları algılanır.
- Negatif değerler veya 1000'den büyük miktarlar hata olarak işlenip bildirimi yapılır.
- Bozuk satırlar için anlamlı hata mesajları basılır.

---

## <a name="ex01"></a>Ex01 - Reverse Polish Notation (RPN)

Ters Lehçe (RPN) formatında verilen matematiksel ifadeleri hesaplayan program.

### <a name="ex01-kapsayici-kullanimi"></a>Kapsayıcı Kullanımı
- `std::stack` kullanılır.
- Sayılar stack'e eklenir, operatör geldiğinde son iki eleman çekilerek işlem yapılır.

### <a name="stack-nedir"></a>Stack Nedir?

- **LIFO (Last-In-First-Out)** mantığı ile çalışır.
- Son eklenen eleman ilk çıkar.
- `push()`, `pop()`, `top()` fonksiyonları bulunur.
- Iterator desteği yoktur.

### <a name="rpn-hesaplamasi"></a>RPN Hesaplaması

**Yöntem:**
- Sayılar geldikçe stack'e eklenir.
- Operatör geldiğinde, son iki sayı çekilip işlem yapılır.
- Sonuç tekrar stack'e atılır.

**Geçerli operatörler:** `+`, `-`, `*`, `/`

**Hatalı girdi:**
- "Error" mesajı basılır.
- Stack'te yeterli eleman yoksa veya bilinmeyen operatör kullanıldıysa hata verilir.

**Örnek:**
Girdi:
```
5 1 2 + 4 * + 3 -
```
İşlem sırası:
- 1 + 2 = 3
- 3 * 4 = 12
- 5 + 12 = 17
- 17 - 3 = 14

Sonuç: **14**

---

## <a name="ex02"></a>Ex02 - PmergeMe

Pozitif tamsayılardan oluşan bir diziyi **Ford-Johnson (Merge-Insert)** algoritması ile sıralayan program.

Aynı algoritmanın hem `std::vector` hem `std::deque` konteynerlerinde uygulanması istenir.

### <a name="ex02-kapsayici-kullanimi"></a>Kapsayıcı Kullanımı

- `std::vector` ve `std::deque` kullanılır.
- Aynı algoritma ikisine de ayrı ayrı uygulanır.

### <a name="ford-johnson-algoritmasi"></a>Ford-Johnson Algoritması
Ford-Johnson algoritması, **en az sayıda karşılaştırma** yaparak sıralama amacıyla tasarlanmıştır.


### <a name="mantigi"></a>Ford-Johnson (Merge-Insertion Sort) Mantığı

Adımlar:
1. Veri çiftler haline getirilir.
2. Her çift kendi içinde sıralanır (küçük -> büyük).
3. Büyük elemanlar ana liste olarak alınır.
4. Ana liste sıralı hale getirilir.
5. Küçük elemanlar uygun yerlere binary search ile yerleştirilir.
6. Eğer tek kalan eleman varsa, doğru yere eklenir.

**Örnek:**
Veri:
```
[7, 2, 5, 3, 9]
```
Adımlar:
- Çiftler: (2,7), (3,5), (9)
- Büyükler: [7,5]
- Sıralı büyükler: [5,7]
- Küçük 2 -> 5'in önüne
- Küçük 3 -> 5 ile 7 arasına
- Tek kalan 9 -> sona

Sonuç:
```
[2, 3, 5, 7, 9]
```

**Avantajları:**
- Teorik olarak minimum karşılaştırma sayısını hedefler.
- Merge Sort ve Insertion Sort'un birleşimidir.

**Performansı:**
- `N * log2(N) - 1.44N` civarında karşılaştırma yapar.

### <a name="jacobsthal-sayilari"></a>Jacobsthal Sayıları

Ford-Johnson algoritması, küçük elemanların ana listeye yerleştirilme sırasını belirlemek için **Jacobsthal dizisi**ni kullanır.

**Jacobsthal dizisi tanımı:**
```
J(0) = 0
J(1) = 1
J(n) = J(n-1) + 2 * J(n-2)
```

İlk birkaç Jacobsthal sayısı:
```
0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...
```

**Ford-Johnson'da kullanımı:**
- Küçük elemanlar, Jacobsthal dizisine göre ana listeye eklenir.
- Bu strateji, ekleme sırasını optimize ederek karşılaştırma sayısını daha da azaltır.
- Özellikle büyük veri setlerinde sıralama verimliliğini artırır.

### <a name="zaman-olcumu-ve-performans"></a>Zaman Ölçümü ve Performans

- Her iki konteyner için sıralama zamanı mikro-saniye (µs) hassasiyetinde ölçülür.
- `std::clock()` fonksiyonu kullanılır.

**std::vector:**
- Dinamik dizi.
- Rastgele erişim `O(1)`.
- Ortadan ekleme/silme maliyetlidir.

**std::deque:**
- Çift uçlu kuyruk.
- Baştan/sondan hızlı ekleme/silme `O(1)`.
- Ortadan erişim `O(n)`.

---

<div align="center">
  <b>2025 | Created by Derya ACAR</b>
</div>

