global  _start

section .bss
    txt     resb 256

section .data
    name    db "open.txt", 0
    err     db "Failed open", 10
    err_len equ $-err

section .text
_start:
    ; read 
    mov     eax, 3      ; вызов read
    mov     ebx, 0      ; param 1
    mov     ecx, txt    ; param 2
    mov     edx, 256    ; param 3
    int     80h
   
    mov     edi, eax    ; number of bytes read
    push    ecx         ; address of text 

    ; file
    mov     eax, 5
    mov     ebx, name
    mov     ecx, 242h
    mov     edx, 0666q
    int     80h
   
    push    eax         ; descriptor of open file

    ; write 
    mov     eax, 4
    pop     eax 
    mov     ebx, eax
    pop     ecx         ; read text
    mov     edx, edi
    int     80h

    push    eax         ; descriptor of open file

    ; close
    mov     eax, 6
    pop     eax
    mov     ebx, eax 
    int     80h
 
    ; end
    mov     eax, 1
    mov     ebx, 0
    int     80h
