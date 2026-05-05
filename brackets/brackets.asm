%include "stud_io.inc"
global _start

section .text
_start: mov     ecx, 0      ; opening parentheses counter
        mov     ebx, 0      ; closing parentheses counter

again:  GETCHAR
        cmp     al, 40      ; search for an opening parenthesis
        jne     close       ; if not found, check the closing
        inc     ecx         ; if found, increase the counter
        jmp     again       ; return to input

close:  cmp     al, 41      ; search for a closing parenthesis
        jne     feed        ; if not found, check for end of line
        inc     ebx         ; if found, increase the counter.
        jmp     again       ; return to input

feed:   cmp     al, 10      ; search for newline
        jne     quit        ; if not found, check at the end of the file.
        jmp     comp        ; if found, print the output
        
comp:   cmp     ecx, ebx    ; compare counter
        jne     printn      ; If not equal, print "NO"
        PRINT   "YES"       ; If equal, print "YES"
        PUTCHAR 10          
        sub     ebx, ebx    ; resetting counters
        sub     ecx, ecx    ;
        jmp     again       ; return to input

printn: PRINT   "NO"
        sub     ebx, ebx    ; resetting counters
        sub     ecx, ecx    ;
        PUTCHAR 10
        jmp     again

quit:   cmp     al, -1
        jne     again
        FINISH
