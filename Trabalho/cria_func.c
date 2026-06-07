//código da função para criar funções

#include <stdio.h>
#include "cria_func.h"


//Inicio do pushq e RA
void inicio(unsigned char codigo[], int *indice)
{
    codigo[(*indice)++] = 0x55;
    codigo[(*indice)++] = 0x48;
    codigo[(*indice)++] = 0x89;
    codigo[(*indice)++] = 0xe5;
}

//Fim do leave e ret
void fim(unsigned char codigo[], int *indice)
{
    codigo[(*indice)++] = 0xc9;
    codigo[(*indice)++] = 0xc3;
}

//Precisa passar os parametros de acordo com a função ORIGINAL
void PARAM_f(unsigned char codigo[], int *indice, DescParam params[], int i, int cont_param)
{
    if (cont_param == 0)
    {
        switch(i)
        {
            case 0:
                break;
            case 1:
                codigo[(*indice)++] = 0x48;
                codigo[(*indice)++] = 0x89;
                codigo[(*indice)++] = 0xfe;
                break;

            case 2:
                codigo[(*indice)++] = 0x48;
                codigo[(*indice)++] = 0x89;
                codigo[(*indice)++] = 0xfa;
                break;

        }
    }
    else if (cont_param == 1)
        switch(i)
        {
            case 0:
                break;
            case 1:
                break;

            case 2:
                codigo[(*indice)++] = 0x48;
                codigo[(*indice)++] = 0x89;
                codigo[(*indice)++] = 0xf2;
                break;

        }

}

//casos do fix
void FIX_f(unsigned char codigo[], int *indice, DescParam params[], int i)
{
    if (params[i].tipo_val == INT_PAR) //caso para int
    {
        int valor = params[i].valor.v_int;

        switch(i)
        {
            case 0:
                codigo[(*indice)++] = 0xbf;

                codigo[(*indice)++] = valor & 0xFF;
                codigo[(*indice)++] = (valor>>8) & 0xFF;
                codigo[(*indice)++] = (valor>>16) & 0xFF;
                codigo[(*indice)++] = (valor>>24) & 0xFF;
                
                break;

            case 1:
                codigo[(*indice)++] = 0xbe;

                codigo[(*indice)++] = valor & 0xFF;
                codigo[(*indice)++] = (valor>>8) & 0xFF;
                codigo[(*indice)++] = (valor>>16) & 0xFF;
                codigo[(*indice)++] = (valor>>24) & 0xFF;

                break;

            case 2:
                codigo[(*indice)++] = 0xba;

                codigo[(*indice)++] = valor & 0xFF;
                codigo[(*indice)++] = (valor>>8) & 0xFF;
                codigo[(*indice)++] = (valor>>16) & 0xFF;
                codigo[(*indice)++] = (valor>>24) & 0xFF;
                break;
        }
    }
    else if (params[i].tipo_val == PTR_PAR) //para caso de ponteiro
    {
        unsigned long int valor = (unsigned long int) params[i].valor.v_ptr; //cast para fazer o shift

        switch(i)
        {
            case 0:
                
                codigo[(*indice)++] = 0x48;
                codigo[(*indice)++] = 0xbf;
                codigo[(*indice)++] = valor & 0xFF;
                codigo[(*indice)++] = (valor>>8) & 0xFF;
                codigo[(*indice)++] = (valor>>16) & 0xFF;
                codigo[(*indice)++] = (valor>>24) & 0xFF;
                codigo[(*indice)++] = (valor>>32) & 0xFF;
                codigo[(*indice)++] = (valor>>40) & 0xFF;
                codigo[(*indice)++] = (valor>>48) & 0xFF;
                codigo[(*indice)++] = (valor>>56) & 0xFF;
                break;

            case 1:
                codigo[(*indice)++] = 0x48;
                codigo[(*indice)++] = 0xbe;
                codigo[(*indice)++] = valor & 0xFF;
                codigo[(*indice)++] = (valor>>8) & 0xFF;
                codigo[(*indice)++] = (valor>>16) & 0xFF;
                codigo[(*indice)++] = (valor>>24) & 0xFF;
                codigo[(*indice)++] = (valor>>32) & 0xFF;
                codigo[(*indice)++] = (valor>>40) & 0xFF;
                codigo[(*indice)++] = (valor>>48) & 0xFF;
                codigo[(*indice)++] = (valor>>56) & 0xFF;
                break;

            case 2:
                codigo[(*indice)++] = 0x48;
                codigo[(*indice)++] = 0xba;
                codigo[(*indice)++] = valor & 0xFF;
                codigo[(*indice)++] = (valor>>8) & 0xFF;
                codigo[(*indice)++] = (valor>>16) & 0xFF;
                codigo[(*indice)++] = (valor>>24) & 0xFF;
                codigo[(*indice)++] = (valor>>32) & 0xFF;
                codigo[(*indice)++] = (valor>>40) & 0xFF;
                codigo[(*indice)++] = (valor>>48) & 0xFF;
                codigo[(*indice)++] = (valor>>56) & 0xFF;
                break;
        }
    }
}

//casos do IND
void IND_f(unsigned char codigo[], int *indice, DescParam params[], int i)
{
    if (params[i].tipo_val == PTR_PAR) //caso para ponteiro
    {
        int* endereco = params[i].valor.v_ptr;
        unsigned long endereco_i = (unsigned long) endereco;
        codigo[(*indice)++] = 0x49;
        codigo[(*indice)++] = 0xbb;

        codigo[(*indice)++] = endereco_i & 0xFF;
        codigo[(*indice)++] = (endereco_i>>8) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>16) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>24) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>32) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>40) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>48) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>56) & 0xFF;
        switch(i)
        {
            case 0:
                codigo[(*indice)++] = 0x49;
                codigo[(*indice)++] = 0x8b;
                codigo[(*indice)++] = 0x3b;
                break;

            case 1:
                codigo[(*indice)++] = 0x49;
                codigo[(*indice)++] = 0x8b;
                codigo[(*indice)++] = 0x33;
                break;

            case 2:
                codigo[(*indice)++] = 0x49;
                codigo[(*indice)++] = 0x8b;
                codigo[(*indice)++] = 0x13;
                break;
        }

    }

    else if (params[i].tipo_val == INT_PAR) //para caso de int
    {
        void* endereco = params[i].valor.v_ptr;
        unsigned long endereco_i = (unsigned long) endereco;
        codigo[(*indice)++] = 0x49;
        codigo[(*indice)++] = 0xbb;

        codigo[(*indice)++] = endereco_i & 0xFF;
        codigo[(*indice)++] = (endereco_i>>8) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>16) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>24) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>32) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>40) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>48) & 0xFF;
        codigo[(*indice)++] = (endereco_i>>56) & 0xFF;

        switch(i)
        {
            case 0:
                codigo[(*indice)++] = 0x41;
                codigo[(*indice)++] = 0x8b;
                codigo[(*indice)++] = 0x3b;
                break;

            case 1:
                codigo[(*indice)++] = 0x41;
                codigo[(*indice)++] = 0x8b;
                codigo[(*indice)++] = 0x33;
                break;

            case 2:
                codigo[(*indice)++] = 0x41;
                codigo[(*indice)++] = 0x8b;
                codigo[(*indice)++] = 0x13;
                break;
        }
    }

}

//codigo para o call da func
void chamar_endereço_função(void* f, unsigned char codigo[], int *indice)
{
    unsigned long endereço_f = (unsigned long) f;
    codigo[(*indice)++] = 0x49;
    codigo[(*indice)++] = 0xba;

    codigo[(*indice)++] = endereço_f & 0xFF;
    codigo[(*indice)++] = (endereço_f>>8) & 0xFF;
    codigo[(*indice)++] = (endereço_f>>16) & 0xFF;
    codigo[(*indice)++] = (endereço_f>>24) & 0xFF;
    codigo[(*indice)++] = (endereço_f>>32) & 0xFF;
    codigo[(*indice)++] = (endereço_f>>40) & 0xFF;
    codigo[(*indice)++] = (endereço_f>>48) & 0xFF;
    codigo[(*indice)++] = (endereço_f>>56) & 0xFF;

    codigo[(*indice)++] = 0x41;
    codigo[(*indice)++] = 0xff;
    codigo[(*indice)++] = 0xd2;
}

void cria_func (void* f, DescParam params[], int n, unsigned char codigo[])
{
    if (n > 3 || n < 1)
    {
        printf("número de parametros invalido");
        return;
    }

    int indice = 0;
    int cont_param = 0;

    //calcula quantos params tem no total
    for (int i = 0; i < n; i++)
    {
       if (params[i].orig_val == PARAM) 
            cont_param++;
    }
 

    cont_param = cont_param - 1;
    inicio(codigo,&indice);

    //loop para reorganizar os registradores primeiros 
    //precisa percoorrer de trás para frente para não 
    //ocorrer casos de registradores sobreescrendo outros
    for (int i = n - 1; i >= 0; i--)
    {
        if (params[i].orig_val == PARAM)  //se o parametro for inteiro
        {
            
            PARAM_f(codigo, &indice, params, i, cont_param);
            cont_param--;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (params[i].orig_val == FIX)
        {
            FIX_f(codigo, &indice, params, i);

        }
        else if (params[i].orig_val == IND)
        {
            IND_f(codigo, &indice, params, i);

        }
    }

    chamar_endereço_função(f, codigo, &indice);
    fim(codigo,&indice);
}