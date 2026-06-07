//código da função para criar funções

#include <stdio.h>
#include "cria_func.h"


void cria_func (void* f, DescParam params[], int n, unsigned char codigo[])
{
    if (n > 3 || n < 1)
    {
        printf("número de parametros invalido");
        return;
    }

    int indice = 0;
    inicio(codigo,&indice);

    //inicio dos parametros
    for (int i = 0; i < n; ++i)
    {
        if (params[i].orig_val == OrigemValor.PARAM)  //se o parametro for inteiro
        {
            continue;
        }
        else if (params[i].orig_val == OrigemValor.FIX)
        {
            FIX(codigo, &indice, params, i)

        }
        else if (params[i].orig_val == OrigemValor.IND)
        {
            if (params[i].tipo_val == INT_PAR)
                IND(codigo, &indice, params, i)
            else if (params[i].tipo_val == PTR_PAR)
                IND(codigo, &indice, params, i)

        }
    }



    fim(codigo,&indice);
}

void inicio(unsigned char codigo[], int *indice)
{
    codigo[(*indice)++] = 0x55;
    codigo[(*indice)++] = 0x48;
    codigo[(*indice)++] = 0x89;
    codigo[(*indice)++] = 0xe5;
}

void fim(unsigned char codigo[], int *indice)
{
    codigo[(*indice)++] = 0xc9;
    codigo[(*indice)++] = 0xc3;
}

void PARAM(unsigned char codigo[], int *indice, DescParam params[], int i)
{

}

void FIX(unsigned char codigo[], int *indice, DescParam params[], int i)
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
        void *valor = params[i].valor.v_ptr;

        switch(i)
        {
            case 0:
                
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
            
                break;

            case 2:
                /* gerar mov valor, %rdx */
                break;
        }
    }
}

void IND(unsigned char codigo[], int *indice, DescParam params[], int i)
{
    
}