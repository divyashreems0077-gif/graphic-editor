#include <stdio.h>

#define WIDTH 60
#define HEIGHT 30

// Global canvas initialized with underscores
char canvas[HEIGHT][WIDTH];

// Function to initialize the canvas
void initCanvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Function to display the canvas
void displayCanvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

// --- REFINED PERFECT-SHAPE CIRCLE FUNCTION ---
void drawPerfectCircle(int xc, int yc, int r) {
    // This factor squishes the horizontal axis to perfectly balance
    // the tall rectangular proportions of terminal text characters.
    double aspect_ratio = 1.9; 

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate distance from the center
            double dx = (x - xc) / aspect_ratio;
            double dy = y - yc;
            double distance_squared = (dx * dx) + (dy * dy);
            double r_squared = r * r;

            // Using a fine-tuned thickness tolerance ensures a completely 
            // smooth, continuous curve with no missing blocks or jagged corners.
            if (distance_squared >= r_squared - r && distance_squared <= r_squared + r) {
                canvas[y][x] = '*';
            }
        }
    }
}

int main() {
    // 1. Prepare the canvas
    initCanvas();

    // 2. Draw a small, perfectly proportioned circle right in the center
    drawPerfectCircle(30, 15, 7);

    // 3. Print the result
    displayCanvas();

    return 0;
}