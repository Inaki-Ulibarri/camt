/* camt, a shitty cat copy made be Iñaki Ullibarri Utrilla*/

/* libraries*/
#include "camt.h"

/* Display how many options this things lacks*/
void print_help(){
     printf("camt [OPTIONS] [FILES] \n"
			"   -h Display this text\n"
			"   -v Display version  \n"
			);
	exit(0);
}

/* You guess*/
void print_version(){
    printf("camt: A shitty cat copy \n"
           "Version 1.0            \n"
           "Made by Iñaki Ulibarri Utrilla \n"
           "Unlicensed, because you'd have to be crazy to steal this bloody thing :D\n"
            );
    exit(0);
}

int main(int argc, char* argv[]){
	if(argc<2){
		puts("I need an argument dipshit.");
		print_help();
	}
    
	int opt = 0;
	while((opt = getopt(argc, argv,  "hv")) != -1){
		switch(opt){
			case 'h':
				print_help();
                break;
			case 'v':
				print_version();
                break;
			default:
				break;
		}
	}
	int ch;
	FILE* foofile;
	int o_files = 1;
    do{
        if(!(strcmp(argv[o_files], "-"))){ //read stdin
            while((ch = getc(stdin)) != '\n'){
                printf("%c", ch);
            }
            printf("\n");
        }else{ //read file
            foofile = fopen(argv[o_files], "r");
            while((ch = fgetc(foofile)) != EOF){
                printf("%c", ch);
            }
            fclose(foofile);
        }
        o_files++;
    }while(o_files < argc);
    
    return(EXIT_SUCCESS);
}
