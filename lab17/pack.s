.text

.globl pack

pack:

    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp
    movq $0, -8(%rbp)

    movsd -8(%rbp), %xmm2



loop:
    movsd %xmm2, -16(%rbp)
    movq %rdi, -32(%rbp)
    cmp $0, %rdi
    je final

    movsd 8(%rdi), %xmm0
    movl (%rdi), %edi
    call foo
    movsd -16(%rbp), %xmm2 
    movq -32(%rbp), %rdi
    movq 16(%rdi), %rdi

    addsd %xmm0, %xmm2 
    jmp loop


final:
    movsd %xmm2, %xmm0
    leave
    ret

     

     
