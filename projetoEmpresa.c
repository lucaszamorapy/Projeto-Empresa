/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/* Lucas Nicola de Avellar Zamora.*/


#include <stdio.h>
#include <stdlib.h>

char Empresa[3][30];
char Telefone[3][12];
char Nome[30];
i=0;

dados(){
   FILE *dados;
   dados = fopen("Info","w");
   for(i=0; i<3; i++){
      printf("\n DIGITE O NOME DA EMPRESA: \n");
      scanf("%s", &Empresa[i]);
      fwrite(Empresa[i], sizeof(Empresa[i]), 1, dados);

      printf("TELEFONE: \n");
      scanf("%s", &Telefone[i]);
      fwrite(Telefone[i], sizeof(Telefone[i]), 1, dados);
   }

   fclose(dados);
}

Ver(){
   int cont;
   FILE *dados;
   dados=fopen("Info","r");
   for(cont=0; cont<3; cont++){
      fread(Empresa[cont], sizeof(Empresa[cont]), 1, dados);
      fread(Telefone[cont], sizeof(Telefone[cont]), 1, dados);
      printf("EMPRESA: %s, TELEFONE: %s. \n", Empresa[cont], Telefone[cont]);
   }
   fclose(dados);
}

int pesquisa1(){
   int cont,k;
   FILE *dados;
   dados=fopen("Info","r");
   printf("PESQUISE AQUI: \n");
   scanf("%s",&Nome[0]);
   for(cont=0; cont<3; cont++){
      for(k=0; Nome[k]!='\0'; k++){
         if(Empresa[cont][k]!=Nome[k]){
            break;
			 }
         }

      if(Empresa[cont][k]=='\0'&& Nome[k]=='\0'){
         printf("EMPRESA: %s, TELEFONE: %s. \n", Empresa[cont], Telefone[cont]);
         fclose(dados);
         return(cont);
      }
   }
   printf("ESSA EMPRESA NAO EXISTE!");
   fclose(dados);
   return(-1);

}

int pesquisa2(){
   char l;
   int i, a=0;
   printf("INFORME A PRIMEIRA LETRA DA EMPRESA: \n");
   scanf("%s", &l);
   for(i=0; i<3; i++){
      if(l==Empresa[i][0]){
         printf("EMPRESA: %s, TELEFONE: %s. \n", Empresa[i], Telefone[i]);
         a=1;
      }
   }
   return(a);
}

int Mudar(){
   int cont,k;
   FILE *dados;
   dados=fopen("Info","w");
   printf("DIGITE O NOME PARA SER ALTERADO: \n");
   scanf("%s",&Nome[0]);
   for(cont=0; cont<3; cont++){
      for(k=0; Nome[k]!='\0'; k++){
         if(Empresa[cont][k]!=Nome[k]){
            break;
			 }
         }

      if(Empresa[cont][k]=='\0'&& Nome[k]=='\0'){
        printf("DIGITE UM NOVO NOME PARA A EMPRESA: \n");
        scanf("%s", &Empresa[cont]);
        printf("DIGITE UM NOVO TELEFONE PARA A EMRPESA:  \n");
        scanf("%s",&Telefone[cont]);

        for(k=0;k<3;k++){
        fwrite(Empresa[k], sizeof(Empresa[k]), 1, dados);
        fwrite(Telefone[k], sizeof(Telefone[k]), 1, dados);
        }
        fclose(dados);
        return(cont);
      }
   }
   printf("NAO FOI POSSIVEL ENCONTRAR A SUA BUSCA.");
   fclose(dados);
   return(-1);
}

int Excluir(){
   int cont,k, x;
   char y;
   FILE *dados;
   dados=fopen("Info","w");
   printf("DIGITE O NOME DA EMPRESA PARA EXCLUIR: \n");
   scanf("%s",&Nome[0]);
   for(cont=0; cont<3; cont++){
      for(k=0; Nome[k]!='\0'; k++){
         if(Empresa[cont][k]!=Nome[k]){
            break;
			 }
         }

      if(Empresa[cont][k]=='\0'&& Nome[k]=='\0'){
        printf("\n TEM CERTEZA QUE DESEJA EXCLUIR ESSA EMPRESA? : SIM 'S' ou NÃO'N' ? ");
        printf("\n EMPRESA - %s / TELEFONE - %s ",Empresa[cont],Telefone[cont]);
        scanf("%s",&y);
        if (y=='s' || y=='S'){
        for (x=0;x<30;x++){
        Empresa[cont][x]=NULL;
        Telefone[cont][x]=NULL;

        fclose(dados);
        return(cont);

      }
   }
   printf("NAO FOI POSSIVEL ENCONTRAR SUA BUSCA.");
   fclose(dados);
   return(-1);

}
}
}

int Saida(){
   exit(0);
}

int main(){
   int Op, Red;
   char P;

   do{
      printf("\n Menu de Opcoes: \n");
      printf("1 - ENTRAR COM OS DADOS \n");
      printf("2 - VER TODOS OS DADOS LISTADOS \n");
      printf("3 - PESQUISAR UMA EMPRESA \n");
      printf("4 - PESQUISAR UMA EMPRESA PELA SUA PRIMEIRA LETRA \n");
      printf("5 - ALTERAR DADOS \n");
      printf("6 - EXCLUIR DADOS \n");
      printf("7 - FINALIZAR \n");
      printf("\n");
      scanf("%d", &Op);

      switch(Op){
         case 1:
         printf("\n------ENTRAR COM DADOS------ \n");
         if(i>2){
            printf("\nVOCE ATINGIU O LIMITE DE EMPRESAS! \n");
            break;
         }
         dados();
         printf("\nVOLTANDO AO MENU...\n");
         break;

         case 2:
         printf("\n------DADOS------ \n");
         Ver();
         printf("\nVOLTANDO AO MENU...\n");
         break;

         case 3:
         printf("\n------PESQUISAR EMPRESA------ \n");
         Red=pesquisa1();
         printf("\nVOLTANDO AO MENU...\n");
         break;

         case 4:
         printf("\n------PESQUISAR EMPRESA PELA PRIMEIRA LETRA------ \n");
         Red=pesquisa2();
         if(Red!=1){
            printf("NAO FOI POSSIVEL CONCLUIR A SUA BUSCA! \n");
		 }
         printf("\nVOLTANDO AO MENU...\n");
         break;

         case 5:
         printf("\n------ALTERAR DADOS------ \n");
         Red=Mudar();
         printf("\nVoce sera redirecionado para o Menu de opcoes!\n");
         break;

         case 6:
         printf("\nOpcao selecionada: Excluir dados de uma empresa! \n");
         Red=Excluir();
         printf("\nVoce sera redirecionado para o Menu de opcoes!\n");
         break;

         case 0:
         printf("\nOpcao selecionada: Finalizar o programa! \n");
         Saida();
         break;

         default:
         printf("\nNumero invalido!\nTente novamente!\n");
         printf("\nVoce sera redirecionado para o Menu de opcoes!\n");
         break;
     }

	   }while(Op!=0);
}



