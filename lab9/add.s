.data


.text
.globl add

add:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    movl %r12d, -8(%rbp)
    movl %edi, %r12d
    addl %esi, %r12d
    addl %edx, %r12d

    movl %r12d, %eax

    movl -8(%rbp), %r12d

    leave
    ret

