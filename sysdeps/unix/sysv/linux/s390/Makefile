abi-variants := 32 64
abi-32-options := -U__s390x__
abi-32-condition := __WORDSIZE == 32
abi-64-options := -D__s390x__
abi-64-condition := __WORDSIZE == 64
abi-64-ld-soname := ld64.so.1

ifeq ($(subdir),rt)
librt-routines += rt-sysdep
endif

ifeq ($(subdir),stdlib)
gen-as-const-headers += ucontext_i.sym
endif

ifeq ($(subdir),elf)
sysdep_routines += dl-vdso
endif

ifeq ($(subdir),debug)
ifeq (yes,$(build-shared))
sysdep_routines += v1-longjmp_chk
endif
endif
