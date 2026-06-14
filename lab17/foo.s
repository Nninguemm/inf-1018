.text 

.globl foo 

foo: 
pushq %rbp 
movq %rsp, %rbp 
subq $16, %rsp 
imull $-1, %edi 
cvtsi2sd %edi,%xmm1 
mulsd %xmm1, %xmm0 
leave 
ret