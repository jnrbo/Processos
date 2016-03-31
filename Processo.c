#include <iostream>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int criarProcesso();
int menu();

bool flag = false;

int main(){
	
	while(true){
		menu();
	}
}

int criarProcesso(int opt) {
	
	std::string str;
	std::wstring temp(str.begin(), str.end());

	LPSTR s;
	
switch (opt){
	
	case 1:
		str = "c:\\Users\\Ramon\\Desktop\\Processos\\exec1.exe";
		
		s = const_cast<char *>(str.c_str());
		
		break;
		
	case 2:
		str = "c:\\Users\\Ramon\\Desktop\\Processos\\imprimirTela.exe";
		
		s = const_cast<char *>(str.c_str());
		
		if(flag == true){
			//KILL_PROC_BY_NAME("c:\\Users\\Ramon\\Desktop\\Processos\\imprimirTela.exe");
			//taskkill "c:\\Users\\Ramon\\Desktop\\Processos\\imprimirTela.exe";
			flag = false;
		}
		else{
			flag = true;
		}
		
		break;

	case 3:
		str = "c:\\Users\\Ramon\\Desktop\\Processos\\exec1.exe";
		
		s = const_cast<char *>(str.c_str());
		
		break;
}	

PROCESS_INFORMATION pi; /*preenchido em CreateProcess */

STARTUPINFO si; 
GetStartupInfo(&si);

CreateProcess(NULL, /* Nome do módulo executável*/
//(LPSTR) temp.c_str(), /* String da linha de comando */
//(LPSTR) "c:\\Users\\Ramon\\Desktop\\Processos\\exec1.exe",
//(LPSTR) "notepad.exe",
s,
NULL, /* Atributos de segurança do processo */
NULL, /* Atributos de segurando do encadeamento*/
FALSE, /* Sinalizador indicativo de herança */
0, /* Sinalizadores de criação */
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
				criarProcesso(1);
			}
			break;
			
		case 2:
			criarProcesso(2);
			break;
			
		case 3:
			criarProcesso(3);
			break;
			
		case 4:
			/*char szName[100] = "imprimirTela.exe";
			int iRes;
			iRes=KILL_PROC_BY_NAME(szName);*/
			break;
			
		default:
			printf("\nOpcao invalida. Tente novamente\n\n");
			break;
	}
}
