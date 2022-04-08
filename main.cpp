#include<windows.h>
#include<GL/glut.h>

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void drawLines()
{
    int i,j,k;
    float xx1=40.0, x1=90.0, y1=168.0;
    float xx2=40.0, x2=170.0, y2=66.0;
    float xx3=170.0, yy3=66.0, x3=90.0, y3=168.0;

    for(i=1; i<=7; i++)
    {
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(xx1, 50.0);
        glVertex2f(x1, y1);
        xx1 += 20.0;
        x1 -= 10.0;
        y1 -= 17.0;
    }

    for(j=1; j<=7; j++)
    {
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(xx2, 50.0);
        glVertex2f(x2, y2);
        xx2 += 20.0;
        x2 -= 10.0;
        y2 += 17.0;
    }

    for(k=1; k<=7; k++)
    {
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(xx3, yy3);
        glVertex2f(x3, y3);
        xx3 -= 10.0;
        yy3 += 17.0;
        x3 -= 10.0;
        y3 -= 17.0;
    }
}

void drawGraph()
{
    glVertex2f(20.0, 50.0);
    glVertex2f(180.0, 50.0);

    glVertex2f(20.0, 50.0);
    glVertex2f(100.0, 185.0);

    glVertex2f(180.0, 50.0);
    glVertex2f(100.0, 185.0);

    drawLines();
}

void display_line()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINES);
    drawGraph();
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(400, 60);
    glutCreateWindow("Lines");
    myInit();
    glutDisplayFunc(display_line);
    glutMainLoop();
    return 0;
}
