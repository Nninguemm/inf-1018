.text
.globl cria_func

cria_func:

    pushq %rbp
    movq %rsp, %rbp

    movq $3669456912, %r11

    movq (%r11), %rdi
    movq (%r11), %rsi
    movq (%r11), %rdx

    movl (%r11), %edi
    movl (%r11), %esi
    movl (%r11), %edx

    movq %rsi, %rdi 
    movq %rdx, %rdi

    movq %rdx, %rsi

    leave
    ret