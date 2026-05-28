
.text

.globl foo3

foo3:

    push %rbp
    movq %rsp, %rbp
    subq $48, %rsp

    movq $0, -33(%rbp)
    movsd -8(%rbp), %xmm7

    movl $0, %r10d


loop:
    movq %rdi, -8(%rbp)
    movl %esi, -12(%rbp)
    movl %r10d, -16(%rbp)
    movsd %xmm7, -32(%rbp)
    cmpl %esi, %r10d
    jge fim
    movsd (%rdi), %xmm0
    call sin

    movq -8(%rbp), %rdi
    movl -12(%rbp), %esi
    movl -16(%rbp), %r10d
    movsd -32(%rbp), %xmm7

    addsd %xmm0, %xmm7
    addq $8, %rdi
    incl %r10d
    jmp loop

fim:
    movsd %xmm7, %xmm0
    leave
    ret



