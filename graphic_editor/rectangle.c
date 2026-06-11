#include <stdio.h>
#include <stdlib.h> // Required for abs()

#define WIDTH 60
#define HEIGHT 30

// Global canvas initialized with underscores
char canvas[HEIGHT][WIDTH];

// Function to initialize the canvas with underscores
void initCanvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Function to print the canvas to the screen
void displayCanvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

// Helper function to safely plot a pixel if it is within bounds
void drawPixel(int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = '*'; // Note: array is indexed as [row][col] -> [y][x]
    }
}

// Bresenham's Line Algorithm to connect any two coordinates
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        drawPixel(x1, y1);

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// --- RECTANGLE DRAWING FUNCTION ---
void drawRectangle(int x1, int y1, int x2, int y2) {
    // Top horizontal side
    drawLine(x1, y1, x2, y1);
    // Bottom horizontal side
    drawLine(x1, y2, x2, y2);
    // Left vertical side
    drawLine(x1, y1, x1, y2);
    // Right vertical side
    drawLine(x2, y1, x2, y2);
}

int main() {
    // 1. Clear and prepare the grid
    initCanvas();

    // 2. Draw a distinct rectangle
    // Top-left corner at (10, 10), Bottom-right corner at (50, 20)
    // Width = 40 units, Height = 10 units. 
    drawRectangle(10, 10, 50, 20);

    // 3. Output the result
    displayCanvas();

    return 0;
}