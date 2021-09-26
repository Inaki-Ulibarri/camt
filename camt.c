/* camt, a shitty cat copy made be Iñaki Ullibarri Utrilla*/

/* libraries*/
#include "camt.h"

/* Display how many options this things lacks*/
void print_help(){
     printf("camt [OPTIONS] [FILES] \n"
			"	-h Display this text\n"
			"	-v Display version  \n"
			"	-n Show line-numbers\n"
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

/* Prints the intered file to stdout*/
void display(FILE *file){
	int ch;
	while((ch = fgetc(file)) != EOF){
		printf("%c", ch);
	}
}

/* Same as display() but with line numbers*/
void display_ln(FILE *file){ 
	unsigned int count = 1;
	int ch;
	printf("%-6d ", count);
	while((ch = fgetc(file)) != EOF){
		printf("%c", ch);
		if(ch == '\n'){ //linenumbers
				count++;
				printf("%-6d ", count);
		}
	}
}

int main(int argc, char* argv[]){
	if(argc<2){
		puts("I need an argument dipshit.");
		print_help();
	}
    
	int opt = 0;
	int o_files = 1; //files to open
	while((opt = getopt(argc, argv,  "hvn")) != -1){
		switch(opt){
			case 'h':
				print_help();
                break;
			case 'v':
				print_version();
                break;
            case 'n':
				p_flags.line_numbers = true;
				o_files = 2; //don't read the  arguments
				break;
			default:
				break;
		}
	}
	int ch;
	FILE* foofile;
    do{
        if(!(strcmp(argv[o_files], "-"))){ //read stdin
            while((ch = fgetc(stdin)) != '\n'){
                printf("%c", ch);
            }
            printf("\n");
        }else{ //read file
            foofile = fopen(argv[o_files], "r");
            if(foofile == NULL){ //check if file was opened
				printf("Error opening the file '%s'\n", argv[o_files]);
				exit(1);
			}
			if(p_flags.line_numbers){
				display_ln(foofile);
			}else{	
				display(foofile);
			}
            fclose(foofile);
        }
        o_files++;
        printf("\n"); 
    }while(o_files < argc);
    return(EXIT_SUCCESS);
}
