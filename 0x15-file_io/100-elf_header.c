#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_elf_header(const char *filename) {
int fd = open(filename, O_RDONLY);
if (fd == -1) {
perror("Error opening file");
exit(EXIT_FAILURE);
}

Elf64_Ehdr header;
if (read(fd, &header, sizeof(header)) != sizeof(header)) {
perror("Error reading file");
exit(EXIT_FAILURE);
}

if (header.e_ident[EI_MAG0] != ELFMAG0 || 
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3) {
fprintf(stderr, "Not an ELF file\n");
exit(EXIT_FAILURE);
}

printf("ELF Header:\n");
printf(" Magic:   ");
for (int i = 0; i < EI_NIDENT; ++i) {
printf("%02x ", header.e_ident[i]);
}
printf("\n");

printf(" Class:                             ");
switch (header.e_ident[EI_CLASS]) {
case ELFCLASS32: printf("ELF32\n"); break;
case ELFCLASS64: printf("ELF64\n"); break;
default: printf("<unknown>\n"); break;
}

printf(" Data:                              ");
switch (header.e_ident[EI_DATA]) {
case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
default: printf("<unknown>\n"); break;
}

printf(" Version:                           %d\n", header.e_ident[EI_VERSION]);

// You can add more sections to print other fields from the ELF header

close(fd);
}

int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(EXIT_FAILURE);
}

print_elf_header(argv[1]);

return EXIT_SUCCESS;
}

