#include <jni.h>
#include <stdio.h>
#include "trashdeleter_Main.h"  // Otomatik olarak jni komutu ile oluşturulan başlık dosyası

JNIEXPORT void JNICALL Java_trashdeleter_Main_createAndDeleteWeakReference(JNIEnv *env, jobject thisObj, jobject obj) {
    // Zayıf referans oluşturma
    jweak weakRef = (*env)->NewWeakGlobalRef(env, obj);
    if (weakRef == NULL) {
        printf("Zayıf referans oluşturulamadı\n");
        return;
    } else {
        printf("Zayıf referans oluşturuldu\n");
    }

    // Zayıf referansı kullanarak nesneyi kontrol edin
    jobject strongRef = (*env)->NewLocalRef(env, weakRef);
    if (strongRef != NULL) {
        printf("Nesne hala mevcut, işlem yapılabilir\n");
        (*env)->DeleteLocalRef(env, strongRef);  // Yerel referansı serbest bırakıyoruz
    } else {
        printf("Nesne çöp toplama tarafından serbest bırakıldı\n");
    }

    // Zayıf referansı silme
    (*env)->DeleteWeakGlobalRef(env, weakRef);
    printf("Zayıf referans silindi\n");
}
