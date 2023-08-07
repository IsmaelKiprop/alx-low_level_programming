#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUF_SIZE 1024

void print_magic(unsigned char e_ident[EI_NIDENT]);
void print_class(unsigned char e_ident[EI_NIDENT]);
void print_data(unsigned char e_ident[EI_NIDENT]);
void print_version(unsigned char e_ident[EI_NIDENT]);
void print_osabi(unsigned char e_ident[EI_NIDENT]);
void print_abiversion(unsigned char e_ident[EI_NIDENT]);
void print_type(Elf64_Half e_type);
void print_entry(Elf64_Addr e_entry);

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", argv[1]);
        exit(98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
        close(fd);
        exit(98);
    }

    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abiversion(header.e_ident);
    print_type(header.e_type);
    print_entry(header.e_entry);

    close(fd);
    return 0;
}

void print_magic(unsigned char e_ident[EI_NIDENT])
{
    int i;
    printf("ELF Header:\n  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

void print_class(unsigned char e_ident[EI_NIDENT])
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char e_ident[EI_NIDENT])
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

void print_version(unsigned char e_ident[EI_NIDENT])
{
    printf("  Version:                           ");
    switch (e_ident[EI_VERSION])
    {
        case EV_NONE: printf("invalid\n"); break;
        case EV_CURRENT: printf("1 (current)\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_VERSION]);
    }
}

void print_osabi(unsigned char e_ident[EI_NIDENT])
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone (embedded)\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

void print_abiversion(unsigned char e_ident[EI_NIDENT])
{
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(Elf64_Half e_type)
{
    printf("  Type:                              ");
    switch (e_type)
    {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", e_type);
    }
}

void print_entry(Elf64_Addr e_entry)
{
    printf("  Entry point address:               0x%lx\n", (unsigned long)e_entry);
}
