#include <jni.h>
#include <stdio.h>

// Zayıf referans oluşturma ve silme işlemi
JNIEXPORT void JNICALL Java_trashdeleter_Main_createAndDeleteWeakReference(JNIEnv *env, jobject thisObj, jobject obj) {
    // Zayıf referans oluşturma
    jweak weakRef = (*env)->NewWeakGlobalRef(env, obj);
    if (weakRef == NULL) {
        printf("Zayif referans oluşturulamadi\n");
        return;
    } else {
        printf("Zayif referans oluşturuldu\n");
    }

    // Zayıf referansı kullanarak nesneyi kontrol edin
    jobject strongRef = (*env)->NewLocalRef(env, weakRef);
    if (strongRef != NULL) {
        printf("Nesne hala mevcut, islem yapilabilir\n");
    } else {
        printf("Nesne çöp toplama tarafindan serbest birakildi\n");
    }

    // Zayıf referansı silme
    (*env)->DeleteWeakGlobalRef(env, weakRef);
    printf("Zaiıf referans silindi\n");
}
