# Proje : JNI.h kullanımı

## Bu proje kullanılmadan önce yapılması gerekenler

1. %JAVA_HOME%/include kısmında veya %JAVA_HOME%/include/win32 kısmındaki jni.h ve jni_md.h dosyasını alın
2. ardından o iki dosyayı MinGW klasörünün içine atın
3. sonrasında Ana sınıf (Main) sınıfının nativini yazmak için konsola şunu yazın : `javac -h . {Your class name.java}`
4. Bunu yazdırktan sonra karşınıza Main.h adlı bir header file gelecektir
5. sonrasında bu ikisini C dosyasına şu şekilde ekleyin
6. `#include <jni.h>` ve `#include "Main.h"`
7. bundan sonra mesela bir toplama metodu yapacaksınız ve onu şu şekilde oluşturdunuz : `public static native int sum(int x, int y)`
8. bunu yaptıysanız c dosyasının içine JNIEXPORT (metodu al) jint (java native integer) JNICALL (Metodu çağır) metod isminede Java_{sınıf ismi}_sum(jint x, jint y) yazacaksınız yani kodu toparlarsak şu şekilde olacaktır
9. `JNIEXPORT jint JNICALL Java_Main_sum(jint x, jint y) {}`
10. en sonundada içine c ile toplama işlemini gerçekleştireceksiniz ardından cmd ile c dosyasını dll veya işletim sisteminize göre so dosyası yapacaksınız
11. `gcc -shared -o example.dll -I"Main.h'ın bulunduğu dizin" example.c`
12. bunu yaptıktan sonra tek yapmamız gerekn static kısmına dll dosyasını yüklemek olucak

