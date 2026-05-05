%include "stud_io.inc"
global  _start

section .text
_start:
    mov     ecx, 0
    mov     ebx, 10

read:
    GETCHAR
    cmp     eax, -1
    je      rest
    cmp     eax, 48
    jb      rest
    cmp     eax, 57
    ja      rest
    sub     eax, 48
    add     ecx, eax
    mov     eax, ecx
    mul     ebx
    mov     ecx, eax
    jmp     read

rest:
    mov     eax, ecx
    div     ebx
    mov     ecx, eax

print:
    test    ecx, ecx
    je      end
    PRINT   "*"
    dec     ecx
    jmp     print

end:
    PUTCHAR 10
    FINISH
