
.text

.globl foo1

foo1:

    push %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    movq %xmm1,-8(%rbp)

    cvtss2sd %xmm0, %xmm0
    call sin
    movq -8(%rbp),%xmm1
    cvtss2sd %xmm1, %xmm1
    addsd %xmm1, %xmm0

    CVTSD2SS %xmm0,%xmm0

    leave
    ret



