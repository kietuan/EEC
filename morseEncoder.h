#ifndef _MORSE_ENCODER
#define _MORSE_ENCODER

#include <Arduino.h>

#ifndef output_pin
#define output_pin 1
#endif

//String code = "";
//int len = 0;
//char ch;
//char new_char; 
extern int const unit_delay;

void dot();
void dash();

void a();
void b();
void _c();
void d();
void e();
void f();
void g();
void h();
void k();
void i();
void j();
void k();
void l();
void m();
void n();
void o();
void p();
void q();
void r();
void s();
void v();
void w();
void x();
void y();
void z();
void t();
void u();

void _0();
void _1();
void _2();
void _3();
void _4();
void _5();
void _6();
void _7();
void _8();
void _9();

void _space();


#endif