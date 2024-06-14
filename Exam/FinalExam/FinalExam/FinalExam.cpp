#pragma comment(lib, "Opengl32.lib")
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>
#include "Object.h"

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    // 창 생성 및 OpenGL 컨텍스트 설정
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL 창", nullptr, nullptr);
    if (!window) {
        std::cerr << "GLFW 창 생성 실패" << std::endl;
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트를 현재 창에 연결
    glfwMakeContextCurrent(window);

    // 게임 객체 생성
    Player player;
    Floor floor;
    EnemyBlock enemy1, enemy2;
    Star star;

    // 렌더링 루프: 창이 닫힐 때까지 반복
    while (!glfwWindowShouldClose(window)) {
        // 버퍼를 지정된 색상으로 지우기
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 검은색 배경
        glClear(GL_COLOR_BUFFER_BIT); // 색상 버퍼 지우기

        // 플레이어 그리기
        player.Draw();

        // 지면 그리기
        floor.Draw();

        // 장애물 그리기 (낮은 장애물)
        enemy1.Draw(-0.75f, 0.33333f); // x 좌표, 높이 100cm

        // 장애물 그리기 (높은 장애물)
        enemy2.Draw(0.25f, 1.0f); // x 좌표, 높이 300cm

        // 별 그리기
        star.Draw();

        // 버퍼 교환
        glfwSwapBuffers(window);

        // 이벤트 처리
        glfwPollEvents();
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}
