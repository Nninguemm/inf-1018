.text
.globl cria_func

cria_func:
    pushq %rbp
    movq %rsp, %rbp

    movl $12, %edi

    movl $67, %esi

    movl $189, %edx
    
    movq $0x123456789abcdef0,%rdi

    movq $0x123456789abcdef0,%rsi

    movq $0x123456789abcdef0,%rdx


    
    movq $0x123456789abcdef0, %r10

    call *%r10
    call *%r12


    leave
    ret
