#include "morseEncoder.h"

//String code = "";
//int len = 0;
//char ch;
//char new_char; 
extern int const unit_delay = 150; //ms
void dot() {
    //Serial.print(".");
    digitalWrite(output_pin, HIGH);
    delay(unit_delay);

    digitalWrite(output_pin, LOW);
    delay(unit_delay);
}
void dash() {
    //Serial.print("-");
    digitalWrite(output_pin, HIGH);
    delay(unit_delay * 3);

    digitalWrite(output_pin, LOW);
    delay(unit_delay);
}

void a() {
    dot();
    dash();

    delay(2 * unit_delay); //tổng cộng là 3 lần
}
void b() {
    dash();
    dot();
    dot();
    dot();
    delay(2 * unit_delay);
}
void _c() {
    dash();
    dot();
    dash();
    dot();
    delay( 2 * unit_delay);
}
void d() {
    dash();
    dot();
    dot();
    delay( 2 * unit_delay);
}
void e() {
    dot();
    delay(2 * unit_delay);
}
void f() {
    dot();
    dot();
    dash();
    dot();
    delay( 2 * unit_delay);
}
void g() {
    dash();
    dash();
    dot();
    delay(2*unit_delay);
}
void h() {
    dot();
    dot();
    dot();
    dot();
    delay(2 * unit_delay);
}
void i() {
    dot();
    dot();
    delay(2 * unit_delay);
}
void j() {
    dot();
    dash();
    dash();
    dash();
    delay(2*unit_delay);
}
void k() {
    dash();
    dot();
    dash();
    delay(2*unit_delay);
}
void l() {
    dot();
    dash();
    dot();
    dot();
    delay(2*unit_delay);
}
void m() {
    dash();
    dash();
    delay(2*unit_delay);
}
void n() {
    dash();
    dot();
    delay(2*unit_delay);
}
void o() {
    dash();
    dash();
    dash();
    delay(2*unit_delay);
}
void p() {
    dot();
    dash();
    dash();
    dot();
    delay(2*unit_delay);
}
void q() {
    dash();
    dash();
    dot();
    dash();
    delay(2*unit_delay);
}
void r() {
    dot();
    dash();
    dot();
    delay(2*unit_delay);
}
void s() {
    dot();
    dot();
    dot();
    delay(2*unit_delay);
}
void t() {
    dash();
    delay(2*unit_delay);
}
void u() {
    dot();
    dot();
    dash();
    delay(2*unit_delay);
}
void v() {
    dot();
    dot();
    dot();
    dash();
    delay(2*unit_delay);
}
void w() {
    dot();
    dash();
    dash();
    delay(2*unit_delay);
}
void x() {
    dash();
    dot();
    dot();
    dash();
    delay(unit_delay*2);
}
void y() {
    dash();
    dot();
    dash();
    dash();
    delay(unit_delay*2);
}
void z() {
    dash();
    dash();
    dot();
    dot();
    delay(unit_delay*2);
}
void _1() {
    dot();
    dash();
    dash();
    dash();
    dash();
    delay(unit_delay*2);
}
void _2() {
    dot();
    dot();
    dash();
    dash();
    dash();
    delay(unit_delay*2);
}
void _3() {
    dot();
    dot();
    dot();
    dash();
    dash();
    delay(unit_delay*2);
}
void _4() {
    dot();
    dot();
    dot();
    dot();
    dash();
    delay(unit_delay*2);
}
void _5() {
    dot();
    dot();
    dot();
    dot();
    dot();
    delay(unit_delay*2);
}
void _6() {
    dash();
    dot();
    dot();
    dot();
    dot();
    delay(unit_delay*2);
}
void _7() {
    dash();
    dash();
    dot();
    dot();
    dot();
    delay(unit_delay*2);
}
void _8() {
    dash();
    dash();
    dash();
    dot();
    dot();
    delay(unit_delay*2);
}
void _9() {
    dash();
    dash();
    dash();
    dash();
    dot();
    delay(unit_delay*2);
}
void _0() {
    dash();
    dash();
    dash();
    dash();
    dash();
    delay(unit_delay*2);
}

void _space()
{
    digitalWrite(output_pin, LOW);
    delay (4 * unit_delay); // cộng thêm 3 giây delay sau mỗi từ
}

/*
void morse() {
    if (ch == 'A' || ch == 'a') {
        A();
        Serial.print(" ");
    } else if (ch == 'B' || ch == 'b') {
        B();
        Serial.print(" ");
    } else if (ch == 'C' || ch == 'c') {
        C();
        Serial.print(" ");
    } else if (ch == 'D' || ch == 'd') {
        D();
        Serial.print(" ");
    } else if (ch == 'E' || ch == 'e') {
        E();
        Serial.print(" ");
    } else if (ch == 'f' || ch == 'f') {
        f();
        Serial.print(" ");
    } else if (ch == 'G' || ch == 'g') {
        G();
        Serial.print(" ");
    } else if (ch == 'H' || ch == 'h') {
        H();
        Serial.print(" ");
    } else if (ch == 'I' || ch == 'i') {
        I();
        Serial.print(" ");
    } else if (ch == 'J' || ch == 'j') {
        J();
        Serial.print(" ");
    } else if (ch == 'K' || ch == 'k') {
        K();
        Serial.print(" ");
    } else if (ch == 'L' || ch == 'l') {
        L();
        Serial.print(" ");
    } else if (ch == 'M' || ch == 'm') {
        M();
        Serial.print(" ");
    } else if (ch == 'N' || ch == 'n') {
        N();
        Serial.print(" ");
    } else if (ch == 'O' || ch == 'o') {
        O();
        Serial.print(" ");
    } else if (ch == 'P' || ch == 'p') {
        P();
        Serial.print(" ");
    } else if (ch == 'Q' || ch == 'q') {
        Q();
        Serial.print(" ");
    } else if (ch == 'R' || ch == 'r') {
        R();
        Serial.print(" ");
    } else if (ch == 'S' || ch == 's') {
        S();
        Serial.print(" ");
    } else if (ch == 'T' || ch == 't') {
        T();
        Serial.print(" ");
    } else if (ch == 'U' || ch == 'u') {
        U();
        Serial.print(" ");
    } else if (ch == 'V' || ch == 'v') {
        V();
        Serial.print(" ");
    } else if (ch == 'W' || ch == 'w') {
        W();
        Serial.print(" ");
    } else if (ch == 'X' || ch == 'x') {
        X();
        Serial.print(" ");
    } else if (ch == 'Y' || ch == 'y') {
        Y();
        Serial.print(" ");
    } else if (ch == 'Z' || ch == 'z') {
        Z();
        Serial.print(" ");
    } else if (ch == '0') {
        zero();
        Serial.print(" ");
    } else if (ch == '1') {
        one();
        Serial.print(" ");
    } else if (ch == '2') {
        two();
        Serial.print(" ");
    } else if (ch == '3') {
        three();
        Serial.print(" ");
    } else if (ch == '4') {
        four();
        Serial.print(" ");
    } else if (ch == '5') {
        five();
        Serial.print(" ");
    } else if (ch == '6') {
        six();
        Serial.print(" ");
    } else if (ch == '7') {
        seven();
        Serial.print(" ");
    } else if (ch == '8') {
        eight();
        Serial.print(" ");
    } else if (ch == '9') {
        nine();
        Serial.print(" ");
    } else if (ch == ' ') {
        delay(unit_delay * 7);
        Serial.print("/ ");
    } else
        Serial.println("Unknown symbol!");
}
void String2Morse() {
    len = code.length();
    for (int i = 0; i < len; i++) {
        ch = code.charAt(i);
        morse();
    }
}
void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(buz, OUTPUT);
    Serial.println("I am ready...");
}
void loop() {
    while (Serial.available()) {
        code = Serial.readString();
        Serial.print(code);
        Serial.print(" = ");
        String2Morse();
        Serial.println("");
    }
    delay(1000);
}
*/
