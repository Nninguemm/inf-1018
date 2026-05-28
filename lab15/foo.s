
.text

.globl foo

foo:

    push %rbp
    movq %rsp, %rbp

    cvtss2sd %xmm1, %xmm1
    movsd %xmm1, %xmm2 
    addsd %xmm0, %xmm1
    subsd %xmm2, %xmm0
    mulsd %xmm1, %xmm0
    CVTSD2SS %xmm0,%xmm0

    leave
    ret



