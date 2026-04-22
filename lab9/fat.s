.data

.text
.globl fat

fat:

    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    movl %r12d, -8(%rbp)

    cmpl $0, %edi
    je final

    movl %edi, %r12d
    subl $1,%edi
    call fat

    imul %eax, %r12d
    movl %r12d, %eax
    movl -8(%rbp), %r12d
    leave
    ret

    
final:
    movl $1, %eax
    movl -8(%rbp), %r12d
    leave
    ret

