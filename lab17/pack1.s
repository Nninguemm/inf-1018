.text

.globl pack1

pack1:

    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp
    movq $0, -8(%rbp)

    movsd -8(%rbp), %xmm2

    movl $0, %r10d
    



loop:
    cmp %esi, %r10d
    jge final

    movsd %xmm2, -8(%rbp)
    movq %rdi, -16(%rbp)
    movl %esi, -20(%rbp)
    movl %r10d, -24(%rbp)



    imull $8, %r10d
    addq %r10, %rdi

    cvtss2sd 4(%rdi), %xmm0
    movl (%rdi), %edi
    call foo

    movsd -8(%rbp), %xmm2
    movq -16(%rbp), %rdi
    movl -20(%rbp), %esi
    
    addsd %xmm0, %xmm2


    movl -24(%rbp), %r10d

    incl %r10d
    jmp loop
    




final:
    movsd %xmm2, %xmm0
    leave
    ret

     

     
