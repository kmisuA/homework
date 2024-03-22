#include <iostream>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

void drawBlock(int code) {
    if (code & 0b1)
    {
        std::cout << "\x1b[037m";
        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }

    }
    if (code & 0b10)
    {
        std::cout << "\x1b[031m";
        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }

    }
    if (code & 0b100)
    {
        std::cout << "\x1b[032m";
        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }

    }
    if (code & 1000)
    {
        std::cout << "\x1b[033m";
        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }

    }
    if (code & 0b10000)
    {
        std::cout << "\x1b[034m";
        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }

    }
    if (code & 0b100000)
    {
        std::cout << "\x1b[035m";
        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }

    }
}

int main() {

    int objectCode;
    std::cout << "학번:202127014  이름:";
    std::cout << "김민수" << std :: endl;
    while (true) {
        std::cout << "화면에 그릴 물체코드를 입력하세요: ";
        std::cin >> objectCode;
        

        
        if (objectCode == 64) {
            drawBlock(objectCode);
            break;
        }
        drawBlock(objectCode);
    }

    return 0;
}

