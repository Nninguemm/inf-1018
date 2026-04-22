.data


.text

.globl foo

foo: 

    push %rbp
    movq %rsp, %rbp
    subq $32, %rsp
    movq $0, %r10 
    movl $0, %r11d 
    movq %rdi, %r9 
    movq $4, %r8
   

inicio_loop:

    cmpq %rsi, %r10
    jge  fim_loop 

    movq $4, %r8
    movq %r9, %rdi

    imul  %r10, %r8
    addq %r8, %rdi
    addl (%rdi), %r11d
   
    addq $1, %r10

    cmpl $0,(%rdi)
    jne inicio_loop

    movl %r11d, (%rdi)
    movl $0,%r11d
    jmp inicio_loop



fim_loop:
    movq %r9, %rdi
    leave
    ret