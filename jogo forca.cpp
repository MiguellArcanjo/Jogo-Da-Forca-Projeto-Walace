#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char palavra[50];
char tentativas[50];
int tentativasFeitas = 0;

//verifica se a letra pertence a palavra
int letraCorreta(char letra){
 for(int i = 0; i < strlen(palavra); i++) {
        if(letra == palavra[i]) {
            return 1;
        }
    }
		return 0;	
}

//adiciona um erro, caso a letra digitada não pertença a palavra
int tentativasErradas() {
    int erros = 0;

    for(int i = 0; i < tentativasFeitas; i++) {

        if(!letraCorreta(tentativas[i])) {
            erros++;
        }
    }

    	return erros;
}

// verifica se a letra está correta.
int chute(char letra) {
    int correto = 0;
    for(int i = 0; i < tentativasFeitas; i++) {
        if(tentativas[i] == letra) {
            correto = 1;
            break;
        }
    }

    return correto;
}


//limite de erros para a derrota
int derrota(){
	return tentativasErradas() >=5;
}

// verifica se todas as letras foram adivinhadas
int vitoria(){
    for(int i = 0; i < strlen(palavra); i++) {
        if(!chute(palavra[i])) {
            return 0;
		}
	}
	return 1;
}
// pede o input de uma tentativa e testa se acertou ou não
void adivinha() {
    char chute;
    printf("digite uma letra para completar a palavra: ");
    scanf(" %c", &chute);

    if(letraCorreta(chute)) {
        printf("Você acertou uma letra %c\n\n", chute);
    } else {
        printf("\nVocê errou a letra %c\n\n", chute);
    }

    tentativas[tentativasFeitas] = chute;
    tentativasFeitas++;
}
// desenha a palavra escondida e as vidas restantes. a palavra vai sendo revelada com as tentativas corretas
void desenha() {

    int erros = tentativasErradas();


    for(int i = 0; i < strlen(palavra); i++) {

        if(chute(palavra[i])) {
            printf("%c ", palavra[i]);
        
    	}else {
            printf("_ ");
        }

    }
    printf("\nerros %d/5\n", erros);

}
// faz um jogador escolher uma palavra para ser descobetra
void escolhePalavra(){
	printf("\nDigite a palavra (sem acentos, letra maiúscula e espaço):");
	scanf("%[^\n]s", palavra);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n########################################################################\n\n");
}


// imprime o inicio do jogo
void bemVindo(){
	printf("*****************\n");
	printf("* JOGO DA FORCA *\n");
	printf("*****************\n\n");
	printf("Escolha alguém para escolher uma palavra,\nessa será a palavra misteriosa.\n\n");
}

int main() {
	
	setlocale(0, "portuguese");
	
	char continua;

    bemVindo();
    //do{
	
	escolhePalavra();
	do {
	desenha();
	adivinha();
	
    } while (!vitoria() && !derrota());

    if(vitoria()) {
    	printf("\n*****************");
        printf("\nVocê Ganhou!!!\n\n");
		printf("*****************\n");
    } else {
    	printf("\n*****************\n");
        printf("Você Perdeu :(\n");
        printf("*****************\n");
        printf("A palavra era: %s\n\n", palavra);
    }
	
//	printf("deseja jogar novamente? S/N: ");
	//	scanf(" %c", &continua);
    
	//} while (continua == 'S' || continua == 's');           "jogar novamente" desabilitado pq apresentava bug.
	
	printf("jogo encerrado");
}

