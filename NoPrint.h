#ifndef _NoPrintClass_h_
#define _NoPrintClass_h_


class NoPrintClass {
public:
  void println(void) {}
  void print  (const void* p1) {}
  void println(const void* p1) {}
  void print  (const int p1, ...) {}
  void println(const int p1, ...) {}
//  void fprint  (const void* p1) {}
//  void fprintln(const void* p1) {}
  void printf(const void* p1) {}
  void printf(const void* p1, ...) {}


};


extern class NoPrintClass NoPrint;
// #define DEBUGSERIAL NoPrint

//#undef fprint(x)
//#undef fprintln(x)
//#define fprint(x) print(x)
//#define fprintln(x) println(x)



#endif
