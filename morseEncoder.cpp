#include "morseEncoder.h"

const int led = 13;
const int buz = 8;
String code = "";
int len = 0;
char ch;
char new_char;
int unit_delay = 250;
void dot() {
    Serial.print(".");
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
    delay(unit_delay);
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    delay(unit_delay);
}
void dash() {
    Serial.print("-");
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
    delay(unit_delay * 3);
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
    delay(unit_delay);
}

void a() {
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void b() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void c() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void d() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void e() {
    dot();
    delay(unit_delay);
}
void f() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void g() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void h() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void i() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void j() {
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void k() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void l() {
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void m() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void n() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void o() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void p() {
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
}
void q() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void r() {
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void s() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void t() {
    dash();
    delay(unit_delay);
}
void u() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void v() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void w() {
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void x() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void y() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void z() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void _1() {
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void _2() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void _3() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void _4() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
void _5() {
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void _6() {
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void _7() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void _8() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void _9() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dot();
    delay(unit_delay);
}
void zero() {
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
    dash();
    delay(unit_delay);
}
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
