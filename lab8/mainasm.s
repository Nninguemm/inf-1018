  .data
  nums: .int 3, -5, 7, 8, -2
  s1:   .string "%d\n"

  .text
  .globl main
  main:
  /* prologo */
     pushq %rbp
     movq  %rsp, %rbp
     subq  $16, %rsp
     movq  %rbx, -8(%rbp)
     movq  %r12, -16(%rbp)

  /* coloque seu codigo aqui */
  movq $0, %rbx
  movq $nums, %r12
  loop:

     /* chamada do filtro */
     movl (%r12), %edi /* pega da memória o int do ponteiro, por isso 32 bits e o parenteses*/
     movq $1, %rsi
     call filtro

     movslq %eax, %rsi /* coloca valor retornado do filtro para registrador de segundo parametro */

     movq $s1, %rdi /* chamada do print */
     call printf

     /* chamada do printf */
     addq $4, %r12
     addq $1, %rbx
     cmp $5, %rbx
     jl loop

  /* finalizacao */
     movq -8(%rbp), %rbx
     movq -16(%rbp), %r12
     leave
     ret