<div align="center">
  <h1>C++ Module 09</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>
</div>

<p align="center">
  Bu proje, STL (Standard Template Library) kullanarak C++ dilinde ileri seviye veri yapıları ve algoritma mantığını pekiştirmeyi hedefleyen 3 egzersizten oluşur. Her egzersiz, farklı bir STL konteyneri ile çalışmayı zorunlu kılarak öğrencinin kapsayıcı (container), algoritma, zaman hesaplama ve hata yönetimi konularını uygulamalı öğrenmesini sağlar.
</p>

---

### İçindekiler 📚
  - [Ex00 - Bitcoin Exchange](#ex00---bitcoin-exchange)
    - [Amaç](#amaç)
    - [Kapsayıcı Kullanımı](#kapsayici-kullanimi)
    - [Map Nedir?](#map-nedir)
    - [Hata Yönetimi](#hata-yonetimi)
  - [Ex01 - Reverse Polish Notation](#ex01---reverse-polish-notation)
    - [Stack Nedir?](#stack-nedir)
    - [RPN Hesaplaması](#rpn-hesaplamasi)
  - [Ex02 - PmergeMe](#ex02---pmergeme)
    - [Ford-Johnson Algoritması](#ford-johnson-algoritmasi)
    - [Zaman Ölçümü ve Performans](#zaman-olcumu-ve-performans)

---

## Ex00 - Bitcoin Exchange

### Amaç
Belirli bir tarih ve miktar için, Bitcoin fiyat veritabanına göre değer hesaplayan bir program yazılır. Kullanıcıdan alınan tarih ve değer bilgilerinin, bir CSV dosyasındaki fiyatlarla çarpımı gerçekleştirilir.

### Kapsayıcı Kullanımı
- `std::map` kullanılarak tarih-fiyat çiftleri sıralı olarak tutulur.
- Tarih veritabanında yoksa `lower_bound()` ile en yakın önceki tarih bulunur.

### Map Nedir?
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

### Hata Yönetimi
- Geçersiz tarih formatı
- Negatif veya 1000'den büyük değer
- Bozuk girdi satırı
Tüm bu hatalar terminale anlamlı mesajlarla yazdırılır.

---

## Ex01 - Reverse Polish Notation

### Amaç
Matematiksel ifadeleri ters Lehçe gösterimi (RPN - Reverse Polish Notation) kullanarak çözen bir hesap makinesi uygulaması yapılır. Kullanıcıdan alınan string ifadedeki sayılar ve operatörler stack üzerinde işlenerek sonuç döndürülür.

### Kapsayıcı Kullanımı
- `std::stack` kullanılır.
- Sayılar stack'e itilip operatörler geldiğinde stack'ten çekilerek işlem yapılır.

### Stack Nedir?
LIFO (Last-In First-Out) mantığıyla çalışan `std::stack` kullanılır. Sayılar yığına itilerek ve operatörle çekilerek hesaplama yapılır.

`std::stack`, kapalı bir veri yapısıdır; sadece son eleman erişilebilir (`top()`), eleman ekleme (`push()`), çıkarma (`pop()`), ve kontrol (`empty()`) gibi işlemler yapılabilir. 
Iterator desteği yoktur.

### RPN Hesaplaması
Kullanıcıdan gelen ters Lehçe matematiksel ifade ayrıştırılır. 
Geçerli operatörler: `+`, `-`, `*`, `/`.

Yöntem:
- Sayılar stack'e itilerek biriktirilir.
- Operatör geldiğinde, son iki sayı alınır ve işlem yapılır, sonuç tekrar stack'e itilerek devam edilir.

Hatalı girdi için terminale `Error` mesajı basılır.

---

## Ex02 - PmergeMe

### Amaç
Kullanıcıdan gelen bir dizi pozitif tamsayıyı Ford-Johnson (merge-insert) algoritmasıyla sıralayan bir program yazılır. Aynı algoritma iki farklı STL konteyneri (`vector` ve `deque`) üzerinde uygulanarak performans karşılaştırması yapılır.

### Kapsayıcı Kullanımı
- `std::vector` ve `std::deque` konteynerleri zorunlu olarak kullanılır.
- Aynı algoritmanın her iki konteyner türü üzerinde ayrı ayrı uygulanması gerekir.

### Ford-Johnson Algoritması
Bu alıştırmada, kullanıcıdan gelen tamsayılar Ford-Johnson (merge-insert) algoritmasıyla sıralanır. Bu algoritma verimli ve akademik olarak önemlidir.

Ford-Johnson algoritması, karşılaştırma sayısını minimize ederek "en hızlı teorik sıralama" olarak bilinir. Merge Sort ile Insertion Sort kombinasyonudur.

### Zaman Ölçümü ve Performans
- İki farklı konteyner (`std::vector`, `std::deque`) ile sıralama yapılır.
- Her biri için toplam geçen süre mikro saniye hassasiyetinde gösterilir.
- Çıktıda sıralama öncesi ve sonrası liste, zaman bilgileri yer alır.

`std::vector`: Dinamik dizi yapısı. Rastgele erişim hızlıdır (`O(1)`), ancak ortadan ekleme/silme pahalıdır.

`std::deque`: Çift uçlu kuyruk. Hem baştan hem sondan hızlı ekleme/silme yapılabilir (`O(1)`), ortadan erişim `O(n)`.

Her ikisiyle aynı algoritmanın uygulanması istenir, bu yüzden algoritmanın generic değil ayrı ayrı yazılması önerilir.

---

<p align="center">2025 This project was created by Derya ACAR.</p>



<p align="center">2025 This project was created by Derya ACAR.</p>

