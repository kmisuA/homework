#pragma once

#include <GLFW/glfw3.h>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        // 기본적으로 아무 동작도 하지 않음
    }
};

class Player : public Object {
public:
    void Draw() {
        // 플레이어의 색상 (빨강)
        glColor3f(1.0f, 0.0f, 0.0f); // 빨간색으로 설정

        // 플레이어의 위치 및 크기 (가로 50cm의 정사각형)
        float playerSize = 0.16f; // 50cm를 1로 normalize
        float playerX = -0.2f; // 가로의 절반
        float playerY = -0.5f; // 세로의 절반

        // 플레이어 정사각형 채우기
        glBegin(GL_QUADS);
        glVertex2f(playerX+0.02, playerY);
        glVertex2f(playerX + playerSize, playerY);
        glVertex2f(playerX + playerSize, playerY + playerSize);
        glVertex2f(playerX + 0.02, playerY + playerSize);
        glEnd();

        // 플레이어 정사각형의 테두리 그리기
        glColor3f(0.0f, 0.0f, 0.0f); // 검은색으로 설정
        glLineWidth(5.0f); // 테두리 두께 설정
        glBegin(GL_LINE_LOOP);
        glVertex2f(playerX + 0.02, playerY);
        glVertex2f(playerX -0.001+ playerSize, playerY);
        glVertex2f(playerX -0.001+ playerSize, playerY + playerSize);
        glVertex2f(playerX + 0.02, playerY + playerSize);
        glEnd();
    }
};

class Floor : public Object {
public:
    void Draw() {
        // 지면의 색상 (황색)
        glColor3f(1.0f, 0.78f, 0.06f);

        // 지면의 위치 및 크기 (높이 100cm)
        float groundHeight = 0.33333f; // 100cm를 1로 normalize

        // 지면 사각형 그리기
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f + groundHeight);
        glVertex2f(-1.0f, -1.0f + groundHeight);
        glEnd();
    }
};

class EnemyBlock : public Object {
public:
    void Draw(float x, float height) {
        // 장애물의 색상 (녹색)
        glColor3f(0.0f, 1.0f, 0.0f);

        // 장애물의 위치 및 크기 (가로 50cm)
        float obstacleWidth = 0.12f; // 50cm를 1로 normalize

        // 장애물 사각형 그리기
        glBegin(GL_QUADS);
        glVertex2f(x, -1.0f);
        glVertex2f(x + obstacleWidth, -1.0f);
        glVertex2f(x + obstacleWidth, -1.0f + height);
        glVertex2f(x, -1.0f + height);
        glEnd();
    }
};

class Star : public Object {
public:
    void Draw() {
        
    }
};
