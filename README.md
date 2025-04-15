<div align="center">
  <h1>C++ Module 09</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>
</div>

<p align="center">
  Bu proje, STL (Standard Template Library) kullanarak C++ dilinde ileri seviye veri yapıları ve algoritma mantığını pekiştirmeyi hedefleyen 3 egzersizten oluşur. Her egzersiz, farklı bir STL konteyneri ile çalışmayı zorunlu kılarak öğrencinin kapsayıcı (container), algoritma, zaman hesaplama ve hata yönetimi konularını uygulamalı öğrenmesini sağlar.
</p>

---

### İçindekiler 📚
  - [Ex00 - Bitcoin Exchange](#ex00)
    - [Kapsayıcı Kullanımı](#kapsayici-kullanimi)
    - [Map Nedir?](#map-nedir)
    - [Hata Yönetimi](#hata-yonetimi)
    - [`std::istringstream` Nedir?](std::istringstream-nedir)
  - [Ex01 - Reverse Polish Notation](#ex02)
    - [Kapsayıcı Kullanımı](#ex01-kapsayici-kullanimi)
    - [Stack Nedir?](#stack-nedir)
    - [RPN Hesaplaması](#rpn-hesaplamasi)
  - [Ex02 - PmergeMe](#ex02)
    - [Kapsayıcı Kullanımı](#ex02-kapsayici-kullanimi)
    - [Ford-Johnson Algoritması](#ford-johnson-algoritmasi)
    - [Zaman Ölçümü ve Performans](#zaman-olcumu-ve-performans)

---

## <a name="ex00"></a>Ex00 - Bitcoin Exchange
Belirli bir tarih ve miktar için, Bitcoin fiyat veritabanına göre değer hesaplayan bir program yazılır. Kullanıcıdan alınan tarih ve değer bilgilerinin, bir CSV dosyasındaki fiyatlarla çarpımı gerçekleştirilir.

### <a name="kapsayici-kullanimi"></a>Kapsayıcı Kullanımı
- `std::map` kullanılarak tarih-fiyat çiftleri sıralı olarak tutulur.
- Tarih veritabanında yoksa `lower_bound()` ile en yakın önceki tarih bulunur.

### <a name="map-nedir"></a>Map Nedir?
`std::map`, C++ STL'de anahtar-değer çiftlerini sıralı tutmak için kullanılan bir konteynerdir. 
Tüm anahtarlar benzersizdir ve otomatik olarak küçükten büyüğe sıralanır. Arama, ekleme ve silme işlemleri logaritmik zamanda (`O(log n)`) gerçekleşir.

Özellikleri:
- Otomatik sıralama (default olarak `operator<` ile)
- Anahtara göre erişim: `map[key]`
- İteratör destekli: `begin()`, `end()`
- `lower_bound()` ile en küçük büyük/eşit anahtarı hızlıca bulabiliriz (bu proje için kritik).

Örnek:
```cpp
std::map<std::string, float> bitcoinRates;
bitcoinRates["2011-01-03"] = 0.3f;
```

---

## <a name="std::istringstream-nedir"></a> `std::istringstream` Nedir?

`std::istringstream`, C++ Standard Library'nin bir bileşeni olup, bir **giriş akışını** (input stream) simüle etmek için kullanılan bir sınıftır. Bu sınıf, bir `std::string` nesnesinden veri okumak için kullanılır. `std::istringstream` sınıfı, `std::istream` sınıfından türemektedir ve string üzerinde okuma işlemi yapmak için özel olarak tasarlanmıştır.

## Temel Kullanım

`std::istringstream`, `std::string`'ten veri okuma işlemlerini daha esnek ve kolay hale getirir. Bir metin dizesi (`std::string`) üzerinde tıpkı bir dosya veya `std::cin` gibi okuma işlemleri yapabilmenizi sağlar.

İlk olarak, `std::istringstream`'i kullanabilmek için `#include <sstream>` başlık dosyasını dahil etmeniz gerekir.

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Okunacak veri
    std::string data = "42 3.14 hello";

    // istringstream akışı oluşturuluyor
    std::istringstream stream(data);

    int intValue;
    double doubleValue;
    std::string stringValue;

    // Verileri string'den ayırarak okuyup uygun türlerdeki değişkenlere atıyoruz
    stream >> intValue >> doubleValue >> stringValue;

    // Sonuçları ekrana yazdırıyoruz
    std::cout << "Integer: " << intValue << std::endl;
    std::cout << "Double: " << doubleValue << std::endl;
    std::cout << "String: " << stringValue << std::endl;

    return 0;
}
```

---

çıktı:

```bash
Integer: 42
Double: 3.14
String: hello
```

**Özellikler ve Avantajlar**

- Veri okuma: Bir metin dizesindeki veriyi okuma işlemini kolaylaştırır. Dosya okuma yerine, bir string'den veri çıkartabilirsiniz.

- Dönüşüm ve ayrıştırma: String içerisindeki veriyi otomatik olarak uygun türlere dönüştürür (örneğin, sayılar, metin vb.).

---

### <a name="hata-yonetimi"></a>Hata Yönetimi
- Geçersiz tarih formatı
- Negatif veya 1000'den büyük değer
- Bozuk girdi satırı
Tüm bu hatalar terminale anlamlı mesajlarla yazdırılır.

---

## <a name="ex01"></a>Ex01 - Reverse Polish Notation

Matematiksel ifadeleri ters Lehçe gösterimi (RPN - Reverse Polish Notation) kullanarak çözen bir hesap makinesi uygulaması yapılır. Kullanıcıdan alınan string ifadedeki sayılar ve operatörler stack üzerinde işlenerek sonuç döndürülür.

### <a name="ex01-kapsayici-kullanimi"></a>Kapsayıcı Kullanımı
- `std::stack` kullanılır.
- Sayılar stack'e itilip operatörler geldiğinde stack'ten çekilerek işlem yapılır.

### <a name="stack-nedir"></a>Stack Nedir?
LIFO (Last-In First-Out) mantığıyla çalışan `std::stack` kullanılır. Sayılar yığına itilerek ve operatörle çekilerek hesaplama yapılır.

`std::stack`, kapalı bir veri yapısıdır; sadece son eleman erişilebilir (`top()`), eleman ekleme (`push()`), çıkarma (`pop()`), ve kontrol (`empty()`) gibi işlemler yapılabilir. 
Iterator desteği yoktur.

### <a name="rpn-hesaplamasi"></a>RPN Hesaplaması
Kullanıcıdan gelen ters Lehçe matematiksel ifade ayrıştırılır. 
Geçerli operatörler: `+`, `-`, `*`, `/`.

Yöntem:
- Sayılar stack'e itilerek biriktirilir.
- Operatör geldiğinde, son iki sayı alınır ve işlem yapılır, sonuç tekrar stack'e itilerek devam edilir.

Hatalı girdi için terminale `Error` mesajı basılır.

---

## <a name="ex02"></a>Ex02 - PmergeMe
Kullanıcıdan gelen bir dizi pozitif tamsayıyı Ford-Johnson (merge-insert) algoritmasıyla sıralayan bir program yazılır. Aynı algoritma iki farklı STL konteyneri (`vector` ve `deque`) üzerinde uygulanarak performans karşılaştırması yapılır.

### <a name="ex02-kapsayici-kullanimi"></a>Kapsayıcı Kullanımı
- `std::vector` ve `std::deque` konteynerleri zorunlu olarak kullanılır.
- Aynı algoritmanın her iki konteyner türü üzerinde ayrı ayrı uygulanması gerekir.

### <a name="ford-johnson-algoritmasi"></a>Ford-Johnson Algoritması
Bu alıştırmada, kullanıcıdan gelen tamsayılar Ford-Johnson (merge-insert) algoritmasıyla sıralanır. Bu algoritma verimli ve akademik olarak önemlidir.

Ford-Johnson algoritması, karşılaştırma sayısını minimize ederek "en hızlı teorik sıralama" olarak bilinir. Merge Sort ile Insertion Sort kombinasyonudur.


### <a name="zaman-olcumu-ve-performans"></a>Zaman Ölçümü ve Performans
- İki farklı konteyner (`std::vector`, `std::deque`) ile sıralama yapılır.
- Her biri için toplam geçen süre mikro saniye hassasiyetinde gösterilir.
- Çıktıda sıralama öncesi ve sonrası liste, zaman bilgileri yer alır.

`std::vector`: Dinamik dizi yapısı. Rastgele erişim hızlıdır (`O(1)`), ancak ortadan ekleme/silme pahalıdır.

`std::deque`: Çift uçlu kuyruk. Hem baştan hem sondan hızlı ekleme/silme yapılabilir (`O(1)`), ortadan erişim `O(n)`.

Her ikisiyle aynı algoritmanın uygulanması istenir, bu yüzden algoritmanın generic değil ayrı ayrı yazılması önerilir.

---

<p align="center">2025 This project was created by Derya ACAR.</p>



<p align="center">2025 This project was created by Derya ACAR.</p>

