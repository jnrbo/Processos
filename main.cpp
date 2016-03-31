#include <iostream>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int criarProcesso();
int menu();

int main(){
	
	while(true){
		menu();
	}
}

int criarProcesso() {
PROCESS_INFORMATION pi; /*preenchido em CreateProcess */

STARTUPINFO si; 
GetStartupInfo(&si);

CreateProcess(NULL, /* Nome do módulo executável*/
"notepad.exe", /* String da linha de comando */
NULL, /* Atributos de segurança do processo */
NULL, /* Atributos de segurando do encadeamento*/
FALSE, /* Sinalizador indicativo de herança */
DETACHED_PROCESS, /* Sinalizadores de criação */
NULL, /* Ponteiro para o novo bloco de ambiente */
NULL, /* Ponteiro para o diretório atual */
&si, /* Ponteiro para STARTUPINFO */
&pi /* Ponteiro para PROCESS_INFORMATION */
);


return 0;
}

int menu(){
	
	int opt, ret;
	
	printf("*--------------------------------------*\n");
	printf("1 - Criar n processos\n");
	printf("2 - Iniciar/Parar impressao em tela\n");
	printf("3 - Iniciar/Parar gravacao em disco\n");
	printf("4 - Encerrar um processo\n");
	printf("*--------------------------------------*\n\n");
	
	printf("Selecione a opcao desejada: ");
	scanf("%d", &opt);
	
	switch (opt){
		
		int ret;
		
		case 1:
			printf("\nQuantos processos quer iniciar? ");
			scanf("%d", &ret);
			for(int i = 0; i<ret; i++){
				criarProcesso();
			}
			break;
			
		case 2:
			break;
			
		case 3:
			break;
			
		case 4:
			break;
			
		default:
			printf("\nOpcao invalida. Tente novamente\n\n");
			break;
	}
}
