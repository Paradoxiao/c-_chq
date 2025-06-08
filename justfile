default:
  @g++ -std=c++11 -Wno-write-strings -g main.cpp -o out.exe
  @./out.exe
input:
  @g++ -std=c++11 -Wno-write-strings -g main.cpp -o out.exe
  @./out.exe < _input.txt
