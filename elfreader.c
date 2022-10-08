#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void readingFile(const char* common) {
          Elf64_Ehdr thisisanobject;
          FILE* file = fopen(common, "rb");
            if(file) {  
              fread(&thisisanobject, sizeof(thisisanobject), 1, file);
              if (memcmp(thisisanobject.e_ident, ELFMAG, SELFMAG) == 0) 
              {
                printf("Yes it is an elf file \n");
              }
              else {
                printf("Nope not an elf file \n");
              }
                printf("\n Since e_type is : %i", thisisanobject.e_type);
              switch (thisisanobject.e_type)
                  {
                case 0:
                  printf("This is a ET_NONE file \n");
                  break;
                case 1:
                  printf("This is a relocatable file \n");
                  break;
                case 2:
                  printf("This is a executable file \n");
                  break;
                case 3 :
                  printf("\n This is a shared object file \n");
                  break;
                case 4:
                  printf("This is a core file \n");
                  break;
                default:
                  break;    }
                  printf("\n ELF HEADER INFORMATION \n");
                  printf("\n Machine is : %i", thisisanobject.e_machine);
                  printf("\n Version is : %i", thisisanobject.e_version);
                  printf("\n Entry point is : %li", thisisanobject.e_entry);
                  printf("\n Program header offset is : %li", thisisanobject.e_phoff);
                  printf("\n Section header offset is : %li", thisisanobject.e_shoff);
                  printf("\n Flags is : %i", thisisanobject.e_flags);
                  printf("\n Size of this header is : %i", thisisanobject.e_ehsize);
                  printf("\n Size of program header is : %i", thisisanobject.e_phentsize);
                  printf("\n Number of program header is : %i", thisisanobject.e_phnum);
                  printf("\n Size of section header is : %i", thisisanobject.e_shentsize);
                  printf("\n Number of section header is : %i", thisisanobject.e_shnum);
                  printf("\n Section header string table index is : %i", thisisanobject.e_shstrndx);
                    
                    }    

          Elf64_Phdr aprogramheader[thisisanobject.e_phnum];
          int i;
                  fseek( file, 64, SEEK_SET );
                  for(i = 0; i < thisisanobject.e_phnum; i++)
                  {
                      fread(&aprogramheader[i], thisisanobject.e_phentsize, 1, file);
                  }
                  for(i = 0; i < thisisanobject.e_phnum; i++)
                  {
                  printf("\n\nHere Is The Program Header Table %i", i);
                  printf("\n Type is : %i ", aprogramheader[i].p_type);
                  printf("\n Offset is : %li", aprogramheader[i].p_offset);
                  printf("\n Virtual address is : %li", aprogramheader[i].p_vaddr);
                  printf("\n Physical address is : %li", aprogramheader[i].p_paddr);
                  printf("\n File size is : %li", aprogramheader[i].p_filesz);
                  printf("\n Memory size is : %li", aprogramheader[i].p_memsz);
                  printf("\n Flags is : %i", aprogramheader[i].p_flags);
                  printf("\n Alignment is : %li", aprogramheader[i].p_align);
                        if(aprogramheader[i].p_type == PT_LOAD)
                        {
                        printf("\n\nThis is a PT_LOAD program header \n");
                        FILE *fpp;
                        fpp=fopen("ptload.bin","wb");
                        fwrite(&aprogramheader[i].p_type,1,sizeof(aprogramheader->p_type), fpp);
                        fwrite(&aprogramheader[i].p_flags,1,sizeof(aprogramheader->p_flags), fpp);
                        fwrite(&aprogramheader[i].p_offset,1,sizeof(aprogramheader->p_offset), fpp);
                        fwrite(&aprogramheader[i].p_vaddr,1,sizeof(aprogramheader->p_vaddr), fpp);
                        fwrite(&aprogramheader[i].p_paddr,1,sizeof(aprogramheader->p_paddr), fpp);
                        fwrite(&aprogramheader[i].p_filesz,1,sizeof(aprogramheader->p_filesz), fpp);
                        fwrite(&aprogramheader[i].p_memsz,1,sizeof(aprogramheader->p_memsz), fpp);
                        fwrite(&aprogramheader[i].p_align,1,sizeof(aprogramheader->p_align), fpp);
                        fclose(fpp);          
                        }
                  }
          Elf64_Shdr asectionheader[thisisanobject.e_shnum];
                  fseek(file, 14712,SEEK_SET);
                    for(i = 0; i < thisisanobject.e_shnum; i++)
                          {
                              fread(&asectionheader[i], thisisanobject.e_shentsize, 1, file);
                          }
                          for(i = 0; i < thisisanobject.e_shnum; i++)
                          {
                  printf("\n\nHere Is The Section Header Table %i", i);
                  printf("\n Name is : %i ", asectionheader[i].sh_name);
                  printf("\n Type is : %i ", asectionheader[i].sh_type);
                  printf("\n Flags is : %li", asectionheader[i].sh_flags);
                  printf("\n Address is : %li", asectionheader[i].sh_addr);
                  printf("\n Offset is : %li", asectionheader[i].sh_offset);
                  printf("\n Size is : %li", asectionheader[i].sh_size);
                  printf("\n Link is : %i", asectionheader[i].sh_link);
                  printf("\n Info is : %i", asectionheader[i].sh_info);
                  printf("\n Address alignment is : %li", asectionheader[i].sh_addralign);
                  printf("\n Entry size is : %li", asectionheader[i].sh_entsize);
                          }
        {printf("\n ALL THE VALUES ARE IN DECIMAL PLEASE CONVERT THEM TO HEXADECIMAL IF YOU PLAN ON VERIFYING THEM FROM EITHER THE BINARY OR THE elf -l <command>  COMMAND");
        printf("THE PT_LOAD PROGRAM HEADER IS IN THE ptload.bin FILE PLEASE USE THE binaryreader.c TO READ DATA FROM IT AS WELL");
        }


        fclose(file);
}


int main(){
readingFile("hello");
}
