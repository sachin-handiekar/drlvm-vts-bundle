/*
    Copyright 2005-2006 The Apache Software Foundation or its licensors, as applicable

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

    See the License for the specific language governing permissions and
    limitations under the License.
*/
  
#include <jni.h>

#define ARG1 ((jint)1000000)
#define RES1 ((jint)ARG1)
#define ARG22 ((jint)-150012)
#define RES2 ((jint)(ARG1 + ARG22))
#define ARG3_LENGTH 2
#define ARG31 ((jint)-327551212)
#define ARG32 ((jint)13211143)
#define RES3 ((jint)(ARG31 + ARG32))
#define ARG42_LENGTH 3
#define ARG421 ((jint)8814231)
#define ARG422 ((jint)-1)
#define ARG423 ((jint)327564324)
#define RES4 ((jint)((ARG31 + ARG32) + (ARG421 + ARG422 + ARG423)))
#define ARG5 ((jint)1002112321)
#define RES5 ((jint)ARG5)
#define ARG62 ((jint)480091)
#define RES6 ((jint)(ARG5 + ARG62))

static jint callNI(JNIEnv *env, jobject obj, jclass parentcl, jmethodID mid, ...)
{
    va_list args;
    jint result;

    va_start(args, mid);
    result = (*env)->CallNonvirtualIntMethodV(env, obj, parentcl, mid, args);
    va_end(args);
    return result;
}

/*
 * Method: org.apache.harmony.vts.test.vm.jni.object_methods.CallNonvirtualIntMethodVTest.nativeExecute(Lorg/apache/harmony/vts/test/vm/jni/object_methods/ChildTestClass;Ljava/lang/Class;Lorg/apache/harmony/vts/test/vm/jni/object_methods/ChildNativeTestClass;Ljava/lang/Class;)Z
 */
JNIEXPORT jboolean JNICALL
Java_org_apache_harmony_vts_test_vm_jni_object_1methods_CallNonvirtualIntMethodVTest_nativeExecute
    (JNIEnv *env, jobject this_object, jobject tc, jclass parenttc, jobject ntc, jclass parentntc)
{
    jclass ic;
    char *sig1 = "(I)I";
    char *sig2 = "(II)I";
    char *sig3 = "([I)I";
    char *sig4 = "([I[I)I";
    char *sig5 = "(Ljava/lang/Integer;)I";
    char *sig6 = "(Ljava/lang/Integer;Ljava/lang/Integer;)I";
    jobject io5, io62;
    jintArray ar3, ar42;
    jint *elements3, *elements42;
    jint result1, result2, result3, result4, result5, result6;
    jint nresult1, nresult2, nresult3, nresult4, nresult5, nresult6;

    jmethodID m1, m2, m3, m4, m5, m6;
    jmethodID nm1, nm2, nm3, nm4, nm5, nm6;
    jmethodID int_init;

    ar3 = (*env)->NewIntArray(env, ARG3_LENGTH);
    ar42 = (*env)->NewIntArray(env, ARG42_LENGTH);

    if (NULL == ar3 || NULL == ar42)
        return JNI_FALSE;

    elements3 = (*env)->GetIntArrayElements(env, ar3, NULL);
    elements42 = (*env)->GetIntArrayElements(env, ar42, NULL);

    if (NULL == elements3 || NULL == elements42)
        return JNI_FALSE;

    elements3[0] = ARG31;
    elements3[1] = ARG32;

    elements42[0] = ARG421;
    elements42[1] = ARG422;
    elements42[2] = ARG423;

    (*env)->ReleaseIntArrayElements(env, ar3, elements3, 0);
    (*env)->ReleaseIntArrayElements(env, ar42, elements42, 0);

    ic = (*env)->FindClass(env, "java/lang/Integer");
    if (NULL == ic)
        return JNI_FALSE;
    int_init = (*env)->GetMethodID(env, ic, "<init>", "(I)V");
    if (NULL == int_init)
        return JNI_FALSE;
    io5 = (*env)->NewObject(env, ic, int_init, ARG5);
    io62 = (*env)->NewObject(env, ic, int_init, ARG62);
    if (NULL == io5 || NULL == io62)
        return JNI_FALSE;

    m1 = (*env)->GetMethodID(env, parenttc, "method", sig1);
    m2 = (*env)->GetMethodID(env, parenttc, "method", sig2);
    m3 = (*env)->GetMethodID(env, parenttc, "method", sig3);
    m4 = (*env)->GetMethodID(env, parenttc, "method", sig4);
    m5 = (*env)->GetMethodID(env, parenttc, "method", sig5);
    m6 = (*env)->GetMethodID(env, parenttc, "method", sig6);

    if (NULL == m1 || NULL == m2 || NULL == m3 ||
        NULL == m4 || NULL == m5 || NULL == m6)
        return JNI_FALSE;

    nm1 = (*env)->GetMethodID(env, parentntc, "method", sig1);
    nm2 = (*env)->GetMethodID(env, parentntc, "method", sig2);
    nm3 = (*env)->GetMethodID(env, parentntc, "method", sig3);
    nm4 = (*env)->GetMethodID(env, parentntc, "method", sig4);
    nm5 = (*env)->GetMethodID(env, parentntc, "method", sig5);
    nm6 = (*env)->GetMethodID(env, parentntc, "method", sig6);

    if (NULL == nm1 || NULL == nm2 || NULL == nm3 ||
        NULL == nm4 || NULL == nm5 || NULL == nm6)
        return JNI_FALSE;

    result1 = callNI(env, tc, parenttc, m1, ARG1);
    result2 = callNI(env, tc, parenttc, m2, ARG1, ARG22);
    result3 = callNI(env, tc, parenttc, m3, ar3);
    result4 = callNI(env, tc, parenttc, m4, ar3, ar42);
    result5 = callNI(env, tc, parenttc, m5, io5);
    result6 = callNI(env, tc, parenttc, m6, io5, io62);

    nresult1 = callNI(env, ntc, parentntc, nm1, ARG1);
    nresult2 = callNI(env, ntc, parentntc, nm2, ARG1, ARG22);
    nresult3 = callNI(env, ntc, parentntc, nm3, ar3);
    nresult4 = callNI(env, ntc, parentntc, nm4, ar3, ar42);
    nresult5 = callNI(env, ntc, parentntc, nm5, io5);
    nresult6 = callNI(env, ntc, parentntc, nm6, io5, io62);

    if (result1 != RES1 || nresult1 != RES1 ||
        result2 != RES2 || nresult2 != RES2 ||
        result3 != RES3 || nresult3 != RES3 ||
        result4 != RES4 || nresult4 != RES4 ||
        result5 != RES5 || nresult5 != RES5 ||
        result6 != RES6 || nresult6 != RES6)
        return JNI_FALSE;
    else
        return JNI_TRUE;
}
