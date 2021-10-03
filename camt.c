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

/* Prints the entered file to stdout*/
void display(FILE *file){
	int ch;
	while((ch = fgetc(file)) != EOF){
		printf("%c", ch);
	}
}

/* Same as display() but with line numbers*/
void display_ln(FILE *file){ 
	ln_count++; //weird thing to get linenumbers to follow on concatenate files
	int ch;
	printf("%6d ", ln_count);
	while((ch = fgetc(file)) != EOF){
		printf("%c", ch);
		if(ch == '\n'){ //linenumbers
			ln_count++;
			printf("%6d ", ln_count);
		}
		
	}
}

/* Special display functions for stdin, work pretty much the same*/
void display_stdi(){
	int ch;
	while((ch = fgetc(stdin)) != '\n'){
		printf("%c", ch);
	}
}

void display_ln_stdi(){
	ln_count++;
	char ch[1024];
	fgets(ch, 1023, stdin);
	printf("%6d %s", ln_count, ch);
}

int main(int argc, char* argv[]){
	if(argc<2){ //incorrect usage
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
				o_files = 2; //don't read '-n' as a file
				break;
			default:
				break;
		}
	}
	
	FILE* foofile; //the fun starts here
    do{
        if(!(strcmp(argv[o_files], "-"))){ //read stdin
			if(p_flags.line_numbers){ //yet to add the feature
	            display_ln_stdi();
	            
        	}else{
				display_stdi();
            	}
            	
            printf("\n"); //for a nice prompt
        }else{ //read file
            foofile = fopen(argv[o_files], "r"); //obligatory file error shenanigans
            if(foofile == NULL){ //check if file was opened
				printf("Error opening the file '%s'\n", argv[o_files]);
				exit(1);
			}

			if(p_flags.line_numbers){ //linenumbers?
				display_ln(foofile);
		        printf("\n"); //get a nice prompt

			}else{	
				display(foofile);
		        printf("\n"); 

			}
            fclose(foofile);
        }
        
        o_files++;
    }while(o_files < argc); //read until no more arguments can be read
    return(EXIT_SUCCESS);
}
