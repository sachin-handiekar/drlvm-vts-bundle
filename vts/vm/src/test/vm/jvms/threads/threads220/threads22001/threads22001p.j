;    Copyright 2005-2006 The Apache Software Foundation or its licensors, as applicable
;
;    Licensed under the Apache License, Version 2.0 (the "License");
;    you may not use this file except in compliance with the License.
;    You may obtain a copy of the License at
;
;       http://www.apache.org/licenses/LICENSE-2.0
;
;    Unless required by applicable law or agreed to in writing, software
;    distributed under the License is distributed on an "AS IS" BASIS,
;    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;
;    See the License for the specific language governing permissions and
;    limitations under the License.

;
; Author: Maxim N. Kurzenev
; Version: $Revision: 1.1 $
;

.source threads22001p.j
.class public org/apache/harmony/vts/test/vm/jvms/threads/threads220/threads22001/threads22001p
.super java/lang/Object


.method public <init>()V
    .limit stack 1
    .limit locals 1

    aload_0
    invokespecial java/lang/Object/<init>()V
    return
.end method

.method public test([Ljava/lang/String;)I
    .limit stack 1
    .limit locals 2

    ; return test1(this.getClass());
    aload_0
    invokevirtual java/lang/Object/getClass()Ljava/lang/Class;
    invokestatic org/apache/harmony/vts/test/vm/jvms/threads/threads220/threads22001/threads22001p/test1(Ljava/lang/Class;)I
    ireturn
.end method

.method public static synchronized test1(Ljava/lang/Class;)I
    .limit stack 1
    .limit locals 1

    ; return Thread.holdsLock(c) ? 104 : 105;
    aload_0
    invokestatic java/lang/Thread/holdsLock(Ljava/lang/Object;)Z
    ifeq Failed
    bipush 104
    ireturn
Failed:
    bipush 105
    ireturn
.end method

.method public static main([Ljava/lang/String;)V
    .limit stack 2
    .limit locals 1

    new org/apache/harmony/vts/test/vm/jvms/threads/threads220/threads22001/threads22001p
    dup
    invokespecial org/apache/harmony/vts/test/vm/jvms/threads/threads220/threads22001/threads22001p/<init>()V
    aload_0
    invokevirtual org/apache/harmony/vts/test/vm/jvms/threads/threads220/threads22001/threads22001p/test([Ljava/lang/String;)I
    invokestatic java/lang/System/exit(I)V
    return

.end method
