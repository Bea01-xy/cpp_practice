#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <csignal>

#define WIDTH 80u
#define HEIGHT 40u

float A = 0, B = 0;

void signal_handler(int signum)
{
    std::cout << "\x1b[?25h" << std::endl;
    std::cout << "shutting down" << std::endl;
    exit(signum);
}

void render_frame(void)
{
    char b[WIDTH * HEIGHT];
    float z_[WIDTH * HEIGHT];

    memset(b, ' ', WIDTH * HEIGHT);
    memset(z_, 0, WIDTH * HEIGHT * sizeof(float));

    const float R1 = 1;
    const float R2 = 2;
    const float K2 = 5;
    const float K1 = WIDTH * K2 * 3 / (8 * (R1 + R2));

    for (float theta = 0; theta < 6.28; theta += 0.07) {
        float cos_theta = cos(theta), sin_theta = sin(theta);

        for (float phi = 0; phi < 6.28; phi += 0.02) {
            float cos_phi = cos(phi), sin_phi = sin(phi);

            float x0 = R2 + R1 * cos_theta;
            float y0 = R1 * sin_theta;

            float cosA = cos(A), sinA = sin(A);
            float cosB = cos(B), sinB = sin(B);

            float x = x0 * (cosB * cos_phi + sinA * sinB * sin_phi) - y0 * cosA * sinB;
            float y = x0 * (sinB * cos_phi - sinA * cosB * sin_phi) + y0 * cosA * cosB;
            float z = K2 + cosA * x0 * sin_phi + y0 * sinA;
            float ooz = 1 / z;

            int xp = (int)(WIDTH / 2.0f + K1 * ooz * x);
            int yp = (int)(HEIGHT / 2.0f - K1 * ooz * y / 2);

            float L = cos_phi * cos_theta * sinB - cosA * cos_theta * sin_phi -
                      sinA * sin_theta + cosB * (cosA * sin_theta - cos_theta * sinA * sin_phi);

            if (L > 0) {
                int idx = xp + WIDTH * yp;
                if (xp >= 0 && xp < WIDTH && yp >= 0 && yp < HEIGHT) {
                    if (ooz > z_[idx]) {
                        z_[idx] = ooz;
                        int luminance_idx = L * 8;
                        b[idx] = ".,-~:;=!*#$@"[luminance_idx];
                    }
                }
            }
        }
    }
    std::cout << "\x1b[H";

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        putchar(i % WIDTH ? b[i] : '\n');
    }
}

int main() {
    signal(SIGINT, signal_handler);
    std::cout << "\x1b[?25l";
    
    while (true) {
        render_frame();
        A += 0.002;
        B += 0.002;
    }
    return 0;
}
