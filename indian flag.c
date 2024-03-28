#include <GL/glut.h>
#include <cmath>

// Animation variables
float waveAmplitude = 0.1;
float waveFrequency = 1.5;
float waveSpeed = 0.05;
float waveOffset = 0.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Calculate wave offset based on time
    waveOffset += waveSpeed;

    // Draw flag with wave effect
    glBegin(GL_POLYGON);
    glColor3f(0.86, 0.30, 0.17); // Deep saffron (kesari)

    for (float x = -2.5; x <= 3.0; x += 0.01)
    {
        float y = waveAmplitude * sin(waveFrequency * x + waveOffset);
        glVertex2f(x, 1.0 + y);
    }

    glVertex2f(3.0, -0.50);
    glVertex2f(-2.5, -0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0); // White
    for (float x = -2.5; x <= 3.0; x += 0.01)
    {
        float y = waveAmplitude * sin(waveFrequency * x + waveOffset);
        glVertex2f(x, 0.33 + y);
    }

    glVertex2f(3.0, -0.33);
    glVertex2f(-2.5, -0.33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.07, 0.29, 0.07); // Dark green
    for (float x = -2.5; x <= 3.0; x += 0.01)
    {
        float y = waveAmplitude * sin(waveFrequency * x + waveOffset);
        glVertex2f(x, -1.0 + y);
    }

    glVertex2f(3.0, -0.33);
    glVertex2f(-2.5, -0.33);
    glEnd();

    // Draw Ashoka Chakra (24-spoke wheel)
    int i;
    GLfloat x, y, radius = 0.16;
    GLfloat twicePi = 2.0f * 3.1416;
    GLfloat x_center = 0.25f, y_center = 0.0f;

    glColor3f(0.0, 0.19, 0.33); // Navy blue

    glPushMatrix();
    glTranslatef(x_center, y_center, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (i = 0; i <= 24; i++)
    {
        x = radius * cos(i * twicePi / 24);
        y = radius * sin(i * twicePi / 24);
        if (i % 2 == 0)
            glColor3f(0.0, 0.19, 0.33); // Navy blue
        else
            glColor3f(1.0, 1.0, 1.0); // White
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Draw flagpole
    glLineWidth(10.0);
    glColor3f(1.0, 1.0, 1.0); // White
    glBegin(GL_LINES);
    glVertex2f(-2.5, 1.0);
    glVertex2f(-2.5, -9.0);
    glEnd();

    // Draw rectangular base
    glColor3f(1.0, 1.0, 1.0); // White
    glBegin(GL_POLYGON);
    glVertex2f(-4.3, -9.0);
    glVertex2f(0.0, -9.0);
    glVertex2f(0.3, -9.5);
    glVertex2f(-4.7, -9.5);
    glEnd();

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -12.0, 2.0); // Updated viewpoint to (-5.0, 5.0, -12.0, 2.0)
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // 60 FPS (1000ms/60 ≈ 16ms)
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 800);
    glutCreateWindow("National Flag of India");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    return 0;
}
