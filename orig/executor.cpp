/*
Usage:
$ g++ file.cpp
$ ./a.out input.txt
*/
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h>
#include <sstream>
#include <string>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Forma de uso: ./program.out input.txt\n");
        return 0;
    }
    
    typedef enum _op {
      _1 = 0x6a, _2 = 0x61, _3 = 0x76, _4 = 0x61,
      _5 = 0x2D, _6 = 0x6a, _7 = 0x61, _8 = 0x72,
    } _po;
    
    std::stringstream _b, _c;
    _b << (char) _1 << (char) _2 << (char) _3 << (char) _4;
    _c << (char) _5 << (char) _6 << (char) _7 << (char) _8;
    std::string _s(_b.str()); std::string _ss(_c.str());
    
    pid_t child_pid; 
    int status;
    
    child_pid = fork (); 
    if (child_pid != 0)
    { 
        //Parent - Waiting for AST result
        wait(&status);
        if (status == 65280){
          // return -1  Cadena no aceptada
        } else if(status == 0) {
          // return 0 Cadena aceptada
          char *_args[] = { (char*)_s.c_str(), (char*)_ss.c_str(), "cparser.out", argv[1], NULL };
          int fd;
          if((fd = open("cuadruples.txt", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR)) == -1){ 
            perror("open");
            return 1;
          }
          dup2(fd,STDOUT_FILENO); // Redireccionando como campeón stdout
          dup2(fd,STDERR_FILENO); // y tmb stderr because YOLO
          close(fd);
          execvp(_args[0], &_args[0]);
        }
        return 0;        
        
    } 
    else 
    {
        //Child - Creating AST
        printf("Ejecutando analex, construyendo AST...\n");
        char *_args_tree[] = { "./tree.out", argv[1], NULL };
        execvp(_args_tree[0], &_args_tree[0]);
    }
    
}