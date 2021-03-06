#include <string.h>
#include <stdio.h>
#include <stdlib.h>
	
#include "../header/assem_table.h"

Assembly_instruction_table assembly_instrs;

void assem_init(){
	assembly_instrs.number_instructions = 0;
}

void assem_add_instr_arg0(char *op){

	assembly_instrs.instructions[assembly_instrs.number_instructions].op = op;
	assembly_instrs.instructions[assembly_instrs.number_instructions].number_arg = 0;		
	assembly_instrs.number_instructions++;
}

void assem_add_instr_arg1(char *op, int arg1){

	assembly_instrs.instructions[assembly_instrs.number_instructions].op = op;
	assembly_instrs.instructions[assembly_instrs.number_instructions].number_arg = 1;	
	assembly_instrs.instructions[assembly_instrs.number_instructions].args[0] = arg1;	
	assembly_instrs.number_instructions++;
}

void assem_add_instr_arg2(char *op, int arg1, int arg2){

	assembly_instrs.instructions[assembly_instrs.number_instructions].op = op;
	assembly_instrs.instructions[assembly_instrs.number_instructions].number_arg = 2;	
	assembly_instrs.instructions[assembly_instrs.number_instructions].args[0] = arg1;	
	assembly_instrs.instructions[assembly_instrs.number_instructions].args[1] = arg2;
	assembly_instrs.number_instructions++;
}

void assem_add_instr_arg3(char *op, int arg1, int arg2, int arg3){

	assembly_instrs.instructions[assembly_instrs.number_instructions].op = op;
	assembly_instrs.instructions[assembly_instrs.number_instructions].number_arg = 3;	
	assembly_instrs.instructions[assembly_instrs.number_instructions].args[0] = arg1;	
	assembly_instrs.instructions[assembly_instrs.number_instructions].args[1] = arg2;
	assembly_instrs.instructions[assembly_instrs.number_instructions].args[2] = arg3;
	assembly_instrs.number_instructions++;
}

void assem_write_file_instrs(){
	
	int i, j;	
	FILE *file = fopen("./assembler/assembly.s","w+");

	for(i = 0; i < assembly_instrs.number_instructions; i++){															
		fprintf(file," %s ", assembly_instrs.instructions[i].op);
		for(j = 0; j < assembly_instrs.instructions[i].number_arg; j++){
			fprintf(file," %d ", assembly_instrs.instructions[i].args[j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}			

int assem_number_instr(){
	return assembly_instrs.number_instructions; 
}

void assem_modify_arg_instr(int index, int arg_position, int new_arg){

 	assembly_instrs.instructions[index].args[arg_position] = new_arg;
}

void assem_write_obj() {
	FILE * fic = (FILE*)fopen("./assembler/assembly.o", "w+");
	int i, j;

	for (i = 0; i < assembly_instrs.number_instructions; i++) {
		
		if (strcmp(assembly_instrs.instructions[i].op, "ADD") == 0) {
			fprintf(fic, "1");
		} else if (strcmp(assembly_instrs.instructions[i].op, "MUL") == 0) {
			fprintf(fic, "2");
		} else if (strcmp(assembly_instrs.instructions[i].op, "SUB") == 0) {
			fprintf(fic, "3");
		} else if (strcmp(assembly_instrs.instructions[i].op, "DIV") == 0) {
			fprintf(fic, "4");
		} else if (strcmp(assembly_instrs.instructions[i].op, "COP") == 0) {
			fprintf(fic, "5");
		} else if (strcmp(assembly_instrs.instructions[i].op, "AFC") == 0) {
			fprintf(fic, "6");
		} else if (strcmp(assembly_instrs.instructions[i].op, "JMP") == 0) {
			fprintf(fic, "7");
		} else if (strcmp(assembly_instrs.instructions[i].op, "JMF") == 0) {
			fprintf(fic, "8");
		} else if (strcmp(assembly_instrs.instructions[i].op,"INF") == 0) {
			fprintf(fic, "9");
		} else if (strcmp(assembly_instrs.instructions[i].op,"SUP") == 0) {
			fprintf(fic, "A");
		} else if (strcmp(assembly_instrs.instructions[i].op,"EQU") == 0) {
			fprintf(fic, "B");
		} 
		
		for (j = 0; j <assembly_instrs.instructions[i].number_arg; j++) {
			fprintf(fic, " %d", assembly_instrs.instructions[i].args[j]);
		}
		fprintf(fic, "\n");
	}
	fclose(fic);
}

void assem_display(){

	int i; 
	printf("#####################################################\n");
	for(i = 0; i < assembly_instrs.number_instructions ; i++){
		printf("Operation : %s", assembly_instrs.instructions[i].op);
		int j;
		for (j = 0; j < assembly_instrs.instructions[i].number_arg; j++){
			printf("\t%d", assembly_instrs.instructions[i].args[j]);
		}
		printf("\n");
	}
	printf("#####################################################\n");
}

