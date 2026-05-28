
.text

.globl foo2

foo2:

    push %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    movss %xmm1,-4(%rbp)

    cvtss2sd %xmm0, %xmm0
    call sin
    movss -4(%rbp),%xmm1
    cvtss2sd %xmm1, %xmm1
    movq %xmm0,-8(%rbp) 
    movsd %xmm1, %xmm0
    call cos
    movq -8(%rbp), %xmm1
    addsd %xmm1, %xmm0

    leave
    ret



