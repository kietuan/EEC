CXX = arduino-cli
BOARD = arduino:avr:nano
PORT = 


upload: compile
	$(CXX) upload -p PORT --fqbn $(BOARD)  main.ino


compile:
	$(CXX) compile --fqbn $(BOARD) main.ino ps2Keyboard.cpp lcd.cpp
