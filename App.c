//Cadastrar um aluno por vez

#include <stdio.h>

 struct tpAluno{
    char nome[30];
    float nota[2];
    float frequencia;
    float media;
  
};

const int tamMaxVetor=10; // constante o tamanho máximo - quantos alunos posso no máximo cadastrar
int numAlunos=0;  // quantos alunos cadastrados


void insere(struct tpAluno aluno[tamMaxVetor]){
    
    if(numAlunos<10){
        printf("Entre com o nome do aluno: ");
        scanf("%s",aluno[numAlunos].nome);
        printf("Entre com a primeira nota do aluno: ");
        scanf("%f",&aluno[numAlunos].nota[0]);
        printf("Entre com a segunda nota do aluno: ");
        scanf("%f",&aluno[numAlunos].nota[1]);
        printf("Entre com a frequência do aluno: ");
        scanf("%f",&aluno[numAlunos].frequencia);
        aluno[numAlunos].media=(aluno[numAlunos].nota[0]+aluno[numAlunos].nota[1])/2;
        numAlunos++;
    }
    else{
        printf("Não é possivel cadastrar. Limite máximo de 10 alunos atingido!");
    }
}

void imprimir(struct tpAluno aluno[tamMaxVetor]){
    int i;
    if(numAlunos==0){
        printf("Não há alunos cadastrados! \n");
    }
    else{
        for (i=0;i<numAlunos;i++){
            printf("O aluno %s teve media %f e frequencia %f \n", aluno[i].nome,aluno[i].media,aluno[i].frequencia);
            //aprovado por nota e frequência
            if(aluno[i].media>=7&&aluno[i].frequencia>=75){
                printf("Aluno aprovado! O aluno  foi aprovado por nota e frequência! \n");
            }
            // aprovado por nota e reprovado por frequência
            else if(aluno[i].media>=7&&aluno[i].frequencia<75){
                printf("Aluno reprovado! O aluno  foi aprovado por nota e reprovado por frequência! \n");
            }
            // reprovado por nota e aprovado por frequência 
            else if(aluno[i].media<7&&aluno[i].frequencia>=75){
                printf("Aluno reprovado! O aluno  foi reprovado por nota e aprovado por frequência! \n");
            }
            else{
                printf("Aluno reprovado! O aluno  foi reprovado por nota e frequência! \n");
            }
        }
    }
   
    
}
    

void menu(struct tpAluno aluno[tamMaxVetor]){  // dclaração da função tipo de retorno nome (parametros - tipo nome)
    int opcao;
    
    do{    //faça  - loop
        printf("Escolha uma opção 1,2 ou 3 \n");
        printf("1 - Incluir aluno \n");
        printf("2 - Imprimir\n");
        printf("3 - Sair \n");
        scanf("%d",&opcao);
        if(opcao==1){
            printf("Cadastro de alunos \n");
            insere(aluno);
        }
        else if(opcao==2){
            printf("Imprimir alunos \n");
            imprimir(aluno);
        }
        
        
    } while (opcao!=3); //enquanto opcao é diferente de 3
        
}

int main()
{
   
    struct tpAluno aluno[tamMaxVetor];
    menu(aluno);  // chamada da função menu com parâmetro aluno

    return 0;
}

