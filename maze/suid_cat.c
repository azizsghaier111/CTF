#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// print errno and exit
#define PERROR_EXIT(str, bool) {          \
            perror((str " "));      \
            exit(EXIT_FAILURE);     \
        }

int main(int argc, char **argv) {
  FILE* fp;
  char* file_name;
  char c;

  if (argc == 1) {
    fprintf(stderr, "[X] filename not provided\n");
    return 2;
  }

  file_name = argv[1];
  printf("[-] calling access()\n");
  if(!access(file_name, R_OK)) {
    printf("[-] access granted\n");
    fp = fopen(file_name, "r");
    if (fp == NULL) {
      perror("[X] fopen() failed ");
      fprintf(stderr, "hum... the file may have disapeared");
      return 2;
    }
    printf("[-] file opened\n");
    while ((c = fgetc(fp)) != EOF)
      fputc(c, stdout);
    fclose(fp);
  } else {
    perror("[X] access() failed ");
    return 2;
  }

  return 0;
}