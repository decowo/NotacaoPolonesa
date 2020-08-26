#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <math.h>
//Joel Ribeiro Bonfim Junior 190304 - Facens - 4 Semestre
//Professor: Adriano Pila - Facens

//Programa para calcular a notação polonesa inversa através de pilhas

float calcula(char expressao[]);

typedef struct {
	float exp[100];
	int top;
} pilha;

void push(float e, pilha *s)
{
	s->top += 1;
	s->exp[s->top] = e;
}

float pop(pilha *s)
{
	float e;
	e = s->exp[s->top];
	s->top -= 1;
	return(e);
}

float stacktop(pilha *s)
{
	float e;
	e = s->exp[s->top];
	return(e);
}

float calcula(char expressao[])
{
	pilha s;
	s.top == -1;
	int tamanho,i;                                        
	char aux;
	float nd,st,res;
	tamanho = strlen(expressao);
	for(i=0;i<tamanho;i++)
	{
		aux = expressao[i]; //salva cada numero ou operador na auxiliar para comparar se deve empilhar ou desempilhar para fazer conta
		if(aux >= '0' && aux <= '9') 
			push((float)aux-'0',&s); //empilha            
		else
		{
			st = pop(&s);
	        nd = pop(&s);
	        switch (aux)
		    {
		    case '+':	res = nd+st;
		        break;
		        
		    case '-':	res = nd-st;
		        break;
		    case '/':	res = nd/st;
		        break;
		        
		    case '*':	res = nd*st;
		        break;
		        
		    case '^':	res = pow(nd,st);
		        break;
		        
	    	}
	        push(res,&s);
		}
	}
return (pop(&s));	
}

int main(int argc, char *argv[]) {
	float resultado;
	char expressao[100]; //digitar a expressão 72^28^-9+3-, 34*2/5+1+ para testes, funcional com qualquer outra expresão
	printf("Digite a expressao: ");
	scanf("%s",&expressao);
	//system("cls");
	resultado = calcula(expressao);
  	printf("Valor da expressao: %.2f \t ", resultado);
		return 0;
}



