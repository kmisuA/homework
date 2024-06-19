#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const float GRAVITY = -9.8f;
const float JUMP_FORCE = 5.0f;
const float TIME_STEP = 0.01f;
const float PLAYER_WIDTH = 0.1f;
const float PLAYER_HEIGHT = 0.1f;
const float GROUND_LEVEL = -0.3f;

class Player {
private:
    float xPos, yPos;
    float xVelocity, yVelocity;
    bool onGround;
    double jumpStartTime;
    bool isJumping;

public:
    Player(float x, float y) : xPos(x), yPos(y), xVelocity(0.0f), yVelocity(0.0f), onGround(false), jumpStartTime(0.0), isJumping(false) {}

    void update() {
        if (!onGround) {
            yVelocity += GRAVITY * TIME_STEP;
        }
        xPos += xVelocity * TIME_STEP;
        yPos += yVelocity * TIME_STEP;

        if (yPos <= GROUND_LEVEL) {
            yPos = GROUND_LEVEL;
            yVelocity = 0.0f;
            onGround = true;
        }
    }

    void render() const {
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(xPos - PLAYER_WIDTH / 2, yPos - PLAYER_HEIGHT / 2);
        glVertex2f(xPos + PLAYER_WIDTH / 2, yPos - PLAYER_HEIGHT / 2);
        glVertex2f(xPos + PLAYER_WIDTH / 2, yPos + PLAYER_HEIGHT / 2);
        glVertex2f(xPos - PLAYER_WIDTH / 2, yPos + PLAYER_HEIGHT / 2);
        glEnd();
    }

    void jump() {
        if (onGround) {
            isJumping = true;
            jumpStartTime = glfwGetTime();
            yVelocity = JUMP_FORCE;
            onGround = false;
        }
    }

    void keyCallback(int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
            jump();
        }
    }

    float getXPos() const { return xPos; }
    float getYPos() const { return yPos; }
    float getWidth() const { return PLAYER_WIDTH; }
    float getHeight() const { return PLAYER_HEIGHT; }
};

class Obstacle {
private:
    float xPos, yPos;
    float xVelocity;
    float width, height; // 장애물의 너비와 높이 추가

public:
    Obstacle(float x, float y) : xPos(x), yPos(y), xVelocity(-0.5f), width(PLAYER_WIDTH), height(PLAYER_HEIGHT) {}

    void update() {
        xPos += xVelocity * TIME_STEP;
    }

    void render() const {
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(xPos - width / 2, yPos - height / 1);
        glVertex2f(xPos + width / 2, yPos - height / 1);
        glVertex2f(xPos + width / 2, yPos + height / 1);
        glVertex2f(xPos - width / 2, yPos + height / 1);
        glEnd();
    }

    float getXPos() const { return xPos; }
    float getYPos() const { return yPos; }
    float getWidth() const { return width; } // 너비 반환 함수 수정
    float getHeight() const { return height; } // 높이 반환 함수 수정
};

// 정적 함수를 만들어서 람다 함수 대신 사용할 콜백 함수로 등록
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Player* player = static_cast<Player*>(glfwGetWindowUserPointer(window));
    if (player) {
        player->keyCallback(key, scancode, action, mods);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Dino Run", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    Player player(-0.5f, GROUND_LEVEL);
    std::vector<Obstacle> obstacles;
    bool gameOver = false;

    // 플레이어 객체를 윈도우 사용자 포인터로 설정
    glfwSetWindowUserPointer(window, &player);

    // 정적 함수를 콜백 함수로 등록
    glfwSetKeyCallback(window, keyCallback);

    // Game loop
    float obstacleSpawnTimer = 0.0f;  // 장애물 생성 타이머 초기화

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Update obstacle spawn timer
        obstacleSpawnTimer += TIME_STEP;

        // Generate new obstacles randomly
        if (obstacleSpawnTimer > 1.0f) {
            float obstacleY = GROUND_LEVEL + PLAYER_HEIGHT / 2;
            obstacles.emplace_back(1.0f, obstacleY);
            obstacleSpawnTimer = 0.0f;  // 타이머 리셋
        }

        // Update player
        player.update();

        // Update obstacles and check collisions
        for (size_t i = 0; i < obstacles.size(); ++i) {
            obstacles[i].update();

            // Check collision with player
            if (player.getXPos() + player.getWidth() / 2 >= obstacles[i].getXPos() - PLAYER_WIDTH / 2 &&
                player.getXPos() - player.getWidth() / 2 <= obstacles[i].getXPos() + PLAYER_WIDTH / 2 &&
                player.getYPos() + player.getHeight() / 2 >= obstacles[i].getYPos() - PLAYER_HEIGHT / 2 &&
                player.getYPos() - player.getHeight() / 2 <= obstacles[i].getYPos() + PLAYER_HEIGHT / 2) {
                gameOver = true;
                break;
            }

            // Remove obstacles that go off-screen
            if (obstacles[i].getXPos() < -1.0f - PLAYER_WIDTH / 2) {
                obstacles.erase(obstacles.begin() + i);
                --i;
            }
        }

        if (gameOver) {
            std::cout << "Game Over!" << std::endl;
            break;
        }

        // Draw ground
        glColor3f(1.0f, 0.7843f, 0.0588f);
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, GROUND_LEVEL - 0.05f);
        glVertex2f(1.0f, GROUND_LEVEL - 0.05f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
        glEnd();

        // Render player
        player.render();

        // Render obstacles
        for (const auto& obstacle : obstacles) {
            obstacle.render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
