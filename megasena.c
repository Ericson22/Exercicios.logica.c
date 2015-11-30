#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 30 //é a quantidade de jogos que serao gerados
#define COLUNA 6 //é a quantidade de numeros por jogo
#define APOSTA 3 // é a quantidade de apostas
#define APOSTADOR 3//é a quantidade de apostadores
#define MAIORES 15 // define a quantidade de linhas quando for verificar os numeros que mais sairam
#define NUMEROS 60// sao os possiveis numeros que se escolhe ou sao sorteados nos jogos(1-60 nesse caso)

main (){
	char apostador[APOSTADOR][1000];
	int mega[NUMEROS][4],quant [3][MAIORES],resultado [LINHA][COLUNA],aposta[APOSTA][COLUNA];
	int a,b,c,d,e,f,g,aleatoria;
		
	srand( time(NULL) );//numeros nao se repetem quando codigo é ezecutado de novo
   	for (a=0;a<MAIORES;a++){
     	    quant[0][a]=0;//coluna que guarda quantidade de dupla que maais sairam 
     	    quant[1][a]=0;//coluna que guarda o primeiro numero  da dupla
     	    quant[2][a]=0;//coluna que guarda o segundo numero  da dupla
	}
	for(a=0;a<NUMEROS;a++){
	   	mega[a][0] = 0;//tabela para verificar em qual sorteio numero saiu pela ultima vez
		mega[a][1] = 0;	//coluna para verificar se ja sai um numero na mesma rodada
		mega[a][2] = 0;//coluna para contar quantas vezes o numero apareceu nos jogos
		mega[a][3] = a+1;//coluna para numeros que podem ser sorteados
	}
	
	  
	for (a=0;a<LINHA;a++){//laço aninhados para gerar numeros aleatorios
		for (b=0;b<COLUNA;b++){
			aleatoria=rand()%NUMEROS;//gera numero aleatorio de 0 a 59
			while (mega[aleatoria][1]==1){//laço para sortear novamente caso numero ja tenha saido nesse jogo
			      aleatoria=rand()%NUMEROS;}
		    mega[aleatoria][1]=1;
		    mega[aleatoria][2]+=1;
		    mega[aleatoria][0]=a+1;
			resultado[a][b]=(aleatoria+1);//soma 1 ao numero gerado e guarda na matriz do resultado
		}   
		for (c=0;c<NUMEROS;c++)
			mega[c][1] = 0;  //zera a coluna que verifica se o numero saiu
    }
    
    
    for (a=0;a<LINHA;a++){//imprimi os jogos sorteados
	    printf ("Jogo  (%d) =\t",a+1);
	    for (b=0;b<COLUNA;b++)
	    	printf ("%.2d\t",resultado[a][b]);
	    printf ("\n");
   }
   
   
	for (a=0;a<LINHA;a++)//verifica se o numero repete na mesma linha  e informa onde se repete
        for (b=0;b<COLUNA;b++)
             for (c=b+1;c<COLUNA;c++) 
                if (resultado[a][c]==resultado[a][b])
                    printf ("O numero:%.2d, Na linha %.2d , se repete na coluna %.2d e na coluna %.2d.\n",resultado[a][b],a+1,b+1,c+1);

	system("pause>>null");
	
   for (a=0;a<NUMEROS;a++)//imprimi quantas vezes sairam cada numero
       printf("Numero %.2d = %.2d\n",a+1,mega[a][2]);
       

   for (c=1;c<NUMEROS;c++){//laços  de repetição para verificar quantas vezes saiu cada possivel dupla
       for(d=(c+1);d<=NUMEROS;d++){
           f=0;
           for (a=0;a<LINHA;a++){ 
             e=0;
             for (b=0;b<COLUNA;b++){
                if ((resultado[a][b])==c)// verifica se o primeiro numero da dupla saiu
                    e++;
		        else if ((resultado[a][b])==d)// verifica se o segundo numero da dupla saiu
                    e++;
			 }
             if (e==2)
                 f++;//caso a dupla tenha saido acrescenta 1
           }
           g=0;
           for (a=1;a<MAIORES;a++)//laço para verificar qual dupla saiu menos vezes para que seja substituida
               if(quant[0][g]>quant[0][a])
                  g=a;
           if(quant[0][g]<f){//verica se a menor dentre as maiores quantidade de vezes é menor que a nova quantidade
              quant[0][g]=f;//guarda a quantidade de vezes que a dupla em questao saiu
              quant[1][g]=c;//guarda o primeiro numero dessa dupla
              quant[2][g]=d;//guarda o segundo numero dessa dupla
            }              
        }
	}
	
	printf ("Interessante...\n");
	sleep(2);
	printf("Sera que consigo ver as %d duplas que mais aparecerao?\nAperte uma tecla e vamos descobrir!!!\n",MAIORES);
	system("pause>>null");
	
   for (a=0;a<MAIORES;a++)//imprimi as duplas com maior quantidade de vezes que sairam
       printf ("Numeros %.2d e %.2d = %.2d vezes\n",quant[1][a],quant[2][a],quant[0][a]);

	system("pause>>null");
	
   	for (a=0;a<MAIORES;a++){//zera matriz
     	    quant[0][a]=0;//coluna que guarda quantidade de dupla que maais sairam 
     	    quant[1][a]=0;//coluna que guarda o primeiro numero  da dupla
     	    quant[2][a]=0;//coluna que guarda o segundo numero  da dupla
	}
	
   for (c=1;c<=NUMEROS;c++){//laço para verifica os numeros que sairam mais vezes
           f=0;
           for (a=0;a<LINHA;a++){ 
             for (b=0;b<COLUNA;b++)
                if ((resultado[a][b])==c)//verifica se o numero saiu nessa posição
                	f++;
           }
           g=0;
           for (a=1;a<MAIORES;a++)
               if(quant[0][g]>quant[0][a])//verifica para que substitua o numero dentre os "MAIORES" que saiu menos vezs
                  g=a;
           if(quant[0][g]<f){//verica se a menor dentre as maiores quantidade de vezes é menor que a nova quantidade
              quant[0][g]=f;//guarda a quantidade vezes que o numero saiu
              quant[1][g]=c;//guarda o numero que saiu
            }              
    }
   for (a=0;a<MAIORES;a++){//laço para imprimir os numeros em ordem crescente
   		c=0;
   		for(b=1;b<MAIORES;b++){
    		if (quant[1][c]>quant[1][b])
    			c=b;
		}
       	printf ("Numeros %.2d = %.2d vezes\n",quant[1][c],quant[0][a]);
       	quant[1][c]=1000 ;
	}
	
  	system("pause>>null");
  
	for (a=0;a<NUMEROS;a++){
  		b=LINHA-mega[a][0];
		if(b>0)
			printf ("Numero %.2d = nao sai a %.2d sorteios seguidos.\n",a+1,b);
		else
			printf ("Numero %.2d = saiu no ultimo sorteio.\n",a+1);
	}
	
	system("pause>>null");
	
	for (a=0;a<APOSTADOR;a++){// laço que armazena os nomes e numeros escolhidos pelos apostadores
		printf("Apostador %d digite seu nome\n",a+1);
		scanf("%s",apostador[a]);
		printf("Digite sua aposta %s:\n",apostador[a]);
		for(b=0;b<COLUNA;b++)
			scanf("%d",&aposta[a][b]);
	}
	
	for(c=0;c<APOSTADOR;c++){//laço que calcula e imprime quantas vezes cada apostador acertou um numero em todos os resultados
		d=0;
		for(a=0;a<NUMEROS;a++){
			for (b=0;b<COLUNA;b++){
				if ((a+1)==aposta[c][b])//verifica e soma quantas vezes cada numero escolhigo pelo apostador saiu 
					d+=mega[a][2];//
			}
		}
		printf("Parabens %s, voce acertou %d numeros!\n",apostador[c],d);
	}
	
	system("pause>>null");
}