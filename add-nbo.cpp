#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t file_read(char *filename){
    FILE *file = fopen(filename, "rb");
    
    if(!file){
	fprintf(stderr, "Error: cannot open file %s\n", filename);
        exit(1);
    }

    uint32_t num;
    size_t size = fread(&num, sizeof(uint32_t), 1, file);

    if(size != 1){
	fprintf(stderr, "Error: reading file %s failed\n", filename);
        fclose(file);
        exit(1);
    }

    fclose(file);

    return ntohl(num);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "syntax : add-nbo <file1> <file2>\n");
        return -1;
    }

    uint32_t num1 = file_read(argv[1]);
    uint32_t num2 = file_read(argv[2]);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

