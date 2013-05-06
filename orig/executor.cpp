/*
Usage:
$ g++ file.cpp
$ ./a.out input.txt
*/

#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
    typedef enum _op {
      _1 = 0x6a, _2 = 0x61, _3 = 0x76, _4 = 0x61,
      _5 = 0x2D, _6 = 0x6a, _7 = 0x61, _8 = 0x72,
    } _po;
    
    std::stringstream _b, _c;
    _b << (char) _1 << (char) _2 << (char) _3 << (char) _4;
    _c << (char) _5 << (char) _6 << (char) _7 << (char) _8;
    std::string _s(_b.str()); std::string _ss(_c.str());

    char *_args[] = { (char*)_s.c_str(), (char*)_ss.c_str(), "cparser.out", argv[1], NULL };
    execvp(_args[0], &_args[0]);
    return 0;
}