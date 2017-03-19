#include <stdio.h>
#include <string.h>

void abertura() {
    printf("/*****************/\n");
    printf("/* Jogo de Forca */\n");
    printf("/*****************/\n\n");
}

void chuta(char chutes[], int tentativas) {
    char chute;
		
	printf("Qual letra?");
	scanf(" %c", &chute); // O espa�o " " antes do "%c" resolve o problema do enter.

	chutes[tentativas] = chute;
	tentativas++;
}

int main() {
	char palavrasecreta[20];
	
	sprintf(palavrasecreta, "MELANCIA"); // Ele escreve "MELANCIA\0", o "\0" informa que acabou a palavra.
	
	int acertou = 0;
	int enforcou = 0;
	
	char chutes[26];
	int tentativas = 0;
	
	abertura();
	
	do {
		int i, j;

		for (i = 0; i < strlen(palavrasecreta); i++) {
			int achou = 0;
			
			for (j = 0; j < tentativas; j++) {
				if (chutes[j] == palavrasecreta[i]) {
					achou = 1;
					break;
				}
			}
			
			if (achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");
		
		chuta(chutes, tentativas);
	} while (!acertou && !enforcou);
	
	system("pause");
}
