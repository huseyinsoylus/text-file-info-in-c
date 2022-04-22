# \<ks> Programı Kullanım Klavuzu

### \<ks> Programı nedir?&#x20;

\<ks> Programı parametre olarak verilen .txt uzantılı dosya ya da dosyaların harf, kelime ve satır sayılarını geri döndüren işlem ve fonksiyonları içerir. Parametresiz kullanılması durumunda STDIN standart giriş dosyası üzerinden tüm işlemleri gerçekleştirir.

#### Genel Kullanım Şekli

Parametreli Kullanım

```
./ks -w -l -c deneme.txt
```

![Resim - 1](.gitbook/assets/parametreli\_genel\_kullanim.png)

Parametresiz Kullanım

```
cat c_dickens.txt|./ks
```

![Resim - 2](.gitbook/assets/parametresiz\_genel\_kullanim.png)

### Programın Aldığı Parametreler

\-->"-l" Parametresi

Verilen dosyanın satır sayısını ve toplamda harf, kelime ve satır sayısını ekrana döndürür.



![Resim - 3](.gitbook/assets/l\_parameter.png)

\-->"-w" Parametresi

Verilen dosyanın kelime sayısını ve toplamda harf, kelime ve satır sayısını ekrana döndürür.

![Resim - 4](.gitbook/assets/w\_parameter.png)

\-->"-c" Parameter

Verilen dosyanın harf sayısını ve toplamda harf, kelime ve satır sayısını ekrana döndürür.

![Resim - 5](.gitbook/assets/c\_parameter.png)

\-->"+" Parameter

Stdin standart girişinden okuma yapmak için kullanılır.

![Resim - 6](.gitbook/assets/+\_parameter.png) ![Resim - 7](.gitbook/assets/+\_genel.png)

