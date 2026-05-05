%include "stud_io.inc"
global  _start

section .text
_start:
    mov     ecx, 0          ; counter iterations 
    mov     ebx, 0          ; counter letters in word
    mov     edx, 0          ; address print

read:
    GETCHAR                 ; get symbol
    push    eax             ; adding to the stack
    cmp     al, -1          ; end of file?
    je      print           ; go to print
    inc     ecx             ; inc iterations
    cmp     al, 10          ; newline?
    je      getnewl         ; push counter letter
    inc     ebx             ; inc counter letters
    jmp     read            ; jump in read

getnewl:
    push    ebx             ; push counter
    inc     ecx             ; also an iteration
    xor     ebx, ebx        ; nullity counter letters
    jmp     read            ; back in read  

getadd:                     ; get address of #10
    shl     ebx, 2          
    jmp     address

print:
    mov     edi, esp        ; save initial address
    mov     ebp, esp        ; save initial address for print
    shl     ecx, 2          ; mult for correct end of stack 
newiteration:
    mov     esp, edi        ; return initial address after print <--+
    mov     ebp, edi        ; --------------------------------------+
    cmp     ecx, 4          ; check on exit from program
    jbe     end             
lp: mov     eax, [esp+ecx]  ; search symbol #10
    cmp     eax, 10         
    je      getadd          ; if find, go to get address
    inc     ebx             
    sub     esp, 4          
    jmp     lp              

address:
    sub     ecx, ebx        ; address of #10          
    mov     edx, ecx        ; copy address in edx     
    sub     ecx, 4          ; address of counter      
    mov     esi, ecx        ; auxiliary reg           
    mov     ecx, [ebp+ecx]  ; full address of counter 
    add     edx, 4          ; address of end word       

lp2:mov     eax, [ebp+edx]  ; | | | | |
    PUTCHAR al              ; v v v v v
    add     ebp, 4          ; PRINT WORD
    loop    lp2             ; ^ ^ ^ ^ ^
    PUTCHAR 10              ; | | | | | 

    mov     ecx, esi        ; counter iterations  
    xor     ebx, ebx        ; nullify
    jmp     newiteration
end:
    FINISH
