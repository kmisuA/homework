#pragma once

#include <GLFW/glfw3.h>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        // �⺻������ �ƹ� ���۵� ���� ����
    }
};

class Player : public Object {
public:
    void Draw() {
        // �÷��̾��� ���� (����)
        glColor3f(1.0f, 0.0f, 0.0f); // ���������� ����

        // �÷��̾��� ��ġ �� ũ�� (���� 50cm�� ���簢��)
        float playerSize = 0.16f; // 50cm�� 1�� normalize
        float playerX = -0.2f; // ������ ����
        float playerY = -0.5f; // ������ ����

        // �÷��̾� ���簢�� ä���
        glBegin(GL_QUADS);
        glVertex2f(playerX+0.02, playerY);
        glVertex2f(playerX + playerSize, playerY);
        glVertex2f(playerX + playerSize, playerY + playerSize);
        glVertex2f(playerX + 0.02, playerY + playerSize);
        glEnd();

        // �÷��̾� ���簢���� �׵θ� �׸���
        glColor3f(0.0f, 0.0f, 0.0f); // ���������� ����
        glLineWidth(5.0f); // �׵θ� �β� ����
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
        // ������ ���� (Ȳ��)
        glColor3f(1.0f, 0.78f, 0.06f);

        // ������ ��ġ �� ũ�� (���� 100cm)
        float groundHeight = 0.33333f; // 100cm�� 1�� normalize

        // ���� �簢�� �׸���
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
        // ��ֹ��� ���� (���)
        glColor3f(0.0f, 1.0f, 0.0f);

        // ��ֹ��� ��ġ �� ũ�� (���� 50cm)
        float obstacleWidth = 0.12f; // 50cm�� 1�� normalize

        // ��ֹ� �簢�� �׸���
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
