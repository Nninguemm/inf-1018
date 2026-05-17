//include padrão
#include <stdio.h>

//meus includes

//minhas constantes

//meus tipos
typedef int (*funcp) (int x);
typedef unsigned int uint32;

//minhas variaveis globais

unsigned char codigo [] = { 
   0x55,                      //push   %rbp
   0x48, 0x89, 0xe5,          //mov    %rsp,%rbp
   0x48, 0x83, 0xec, 0x10,    //sub    $0x10,%rsp
   0xff, 0xc7,                //inc    %edi
   0x89, 0xf8,                //mov    %edi,%eax
   0xc9,                      //leave
   0xc3,                      //ret
};

//minhas funcoes
int bar(int x)
{
    return x +1;
}

#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define PAGE_START(P) ((intptr_t)(P)&~(pagesize-1))
#define PAGE_END(P) (((intptr_t)(P)+pagesize-1)&~(pagesize-1))

/*
 * The execpage() function shall change the specified memory pages
 * permissions into executable.
 *
 * void *ptr  = pointer to start of memory buff
 * size_t len = memory buff size in bytes
 *
 * The function returns 0 if successful and -1 if any error is encountered.
 * errono may be used to diagnose the error.
 */
int execpage(void *ptr, size_t len) {
	int ret;

	const long pagesize = sysconf(_SC_PAGE_SIZE);
	if (pagesize == -1)
		return -1;

	ret = mprotect((void *)PAGE_START(ptr),
		 PAGE_END((intptr_t)ptr + len) - PAGE_START(ptr),
		 PROT_READ | PROT_WRITE | PROT_EXEC);
	if (ret == -1)
		return -1;

	return 0;
}

#undef PAGE_START
#undef PAGE_END

int main(void)
{
    int a;
    int b;
    funcp f;
    execpage(codigo,sizeof(codigo));

    a = 7;

    b = bar(a);
    printf("bar(%d) = %d \n", a,b);

    f = bar;
    b = f(a);
    printf("f(%d) = %d \n", a,b);

    f = (funcp) codigo; //esse funcp serve para fazer o cast de tipos corretamente mas em assembly não muda nada
    b = f(a); //erro pq nao pode se rodar dados (.data) em seguimento de texto (código)
    int i = (*f)(10);
    printf("f(i) = %d\n", i);



    printf("codigo: %d = %d \n", a,b);

    return 0;
}