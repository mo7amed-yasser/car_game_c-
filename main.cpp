#include <iostream>
#include <GL/freeglut.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distribution(50,350);
int X=0;
int x_=300;
int y_=200;
int gx=700;
int gy=100;

void draw(GLint x,GLint y){
    glBegin(GL_POINTS);
        glVertex2d(x,y);
    glEnd();
}
void Bresenham(GLint x0, GLint y0, GLint x1, GLint y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int p = 2 * dy - dx;

    if (abs(dy) >= abs(dx)) {
        int temp = x0;
        x0 = y0;
        y0 = temp;

        temp = x1;
        x1 = y1;
        y1 = temp;

        std::swap(dx, dy);
        std::swap(sx, sy);
    }

    while (true) {
        // Output point (x0, y0) here

        if (x0 == x1 && y0 == y1) {
            break;
        }

        if (p < 0) {
            p += 2 * dy;
            x0 += sx;
            draw(x0,y0);
        } else {
            p += 2 * dy - 2 * dx;
            x0 += sx;
            y0 += sy;
            draw(x0,y0);
        }
    }
}


void road(GLint x){
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x,247);
            glVertex2d(x,253);
            glVertex2d(x+40,253);
            glVertex2d(x+40,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x,147);
            glVertex2d(x,153);
            glVertex2d(x+40,153);
            glVertex2d(x+40,147);
        glEnd();
/*                        */
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x+100,247);
            glVertex2d(x+100,253);
            glVertex2d(x+40+100,253);
            glVertex2d(x+40+100,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x+100,147);
            glVertex2d(x+100,153);
            glVertex2d(x+40+100,153);
            glVertex2d(x+40+100,147);
        glEnd();

        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x+200,247);
            glVertex2d(x+200,253);
            glVertex2d(x+40+200,253);
            glVertex2d(x+40+200,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x+200,147);
            glVertex2d(x+200,153);
            glVertex2d(x+40+200,153);
            glVertex2d(x+40+200,147);
        glEnd();
        /*                        */
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x+300,247);
            glVertex2d(x+300,253);
            glVertex2d(x+40+300,253);
            glVertex2d(x+40+300,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x+300,147);
            glVertex2d(x+300,153);
            glVertex2d(x+40+300,153);
            glVertex2d(x+40+300,147);
        glEnd();
        /*                        */
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x+400,247);
            glVertex2d(x+400,253);
            glVertex2d(x+40+400,253);
            glVertex2d(x+40+400,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x+400,147);
            glVertex2d(x+400,153);
            glVertex2d(x+40+400,153);
            glVertex2d(x+40+400,147);
        glEnd();
        /*                        */
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x+500,247);
            glVertex2d(x+500,253);
            glVertex2d(x+40+500,253);
            glVertex2d(x+40+500,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x+500,147);
            glVertex2d(x+500,153);
            glVertex2d(x+40+500,153);
            glVertex2d(x+40+500,147);
        glEnd();
        /*                        */
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x+600,247);
            glVertex2d(x+600,253);
            glVertex2d(x+40+600,253);
            glVertex2d(x+40+600,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x+600,147);
            glVertex2d(x+600,153);
            glVertex2d(x+40+600,153);
            glVertex2d(x+40+600,147);
        glEnd();
/*                        */
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex2d(x+700,247);
            glVertex2d(x+700,253);
            glVertex2d(x+40+700,253);
            glVertex2d(x+40+700,247);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2d(x+700,147);
            glVertex2d(x+700,153);
            glVertex2d(x+40+700,153);
            glVertex2d(x+40+700,147);
        glEnd();



}
void drawCircle(int centerX, int centerY, int radius)
{
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}
void car (GLint x,GLint y){
    int X=x;
    int Y=y;
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2d(X,Y);
        glVertex2d(X+20,Y+7);
        glVertex2d(X+100,Y+7);
        glVertex2d(X+120,Y);

        glVertex2d(X+120,Y);
        glVertex2d(X+120,Y-40);
        glVertex2d(X+90,Y-40);
        glVertex2d(X+90,Y);

        glVertex2d(X+70,Y);
        glVertex2d(X+70,Y-40);
        glVertex2d(X+30,Y-40);
        glVertex2d(X+30,Y);

        glVertex2d(X+20,Y);
        glVertex2d(X+20,Y-40);
        glVertex2d(X,Y-40);
        glVertex2d(X,Y);

        glVertex2d(X+120,Y-40);
        glVertex2d(X+100,Y-47);
        glVertex2d(X+20,Y-47);
        glVertex2d(X,Y-40);
    glEnd();
    glColor3f(.6,0,0);
    glBegin(GL_QUADS);
        glVertex2d(X+70,Y);
        glVertex2d(X+70,Y-40);
        glVertex2d(X+30,Y-40);
        glVertex2d(X+30,Y);
    glEnd();

    glColor3f(.1,.1,.1);
    glBegin(GL_QUADS);
        glVertex2d(X+90,Y-40);
        glVertex2d(X+90,Y);
        glVertex2d(X+70,Y);
        glVertex2d(X+70,Y-40);
        glVertex2d(X+30,Y-40);
        glVertex2d(X+30,Y);
        glVertex2d(X+20,Y);
        glVertex2d(X+20,Y-40);
    glEnd();

    glColor3f(1,1,1);
    Bresenham(X,Y,X+120,Y);
    Bresenham(X,Y-40,X+120,Y-40);








}void Keyboard(unsigned char key, int x, int y){
    if (key == GLUT_KEY_RIGHT) {
        x_ += 5;
    } else if (key == GLUT_KEY_LEFT) {
        x_ -= 5;
    } else if (key == GLUT_KEY_DOWN) {
        y_ += 5;
    }else if (key ==GLUT_KEY_UP){
        y_ -=5;
        }
}
void border(){
    int x =0;
    int y=0;
    glColor3f(.2,.2,.2);
     glBegin(GL_QUADS);
            glVertex2i(x, y);
            glVertex2i(x, y + 50);
            glVertex2i(x + 800, y + 50);
            glVertex2i(x + 800, y);
    glEnd();

    glBegin(GL_QUADS);
            glVertex2d(0,350);
            glVertex2d(0,400);
            glVertex2d(800,400);
            glVertex2d(800,350);
    glEnd();
}

void displayback(void){
    glClearColor(.70,.80,.87,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1);
    border();
    for(int i=0;i<800;i+=5){
        road(X);
        }
    if (x_>0&&x_+120<800&&y_-40>50&&y_<350){
        car(x_,y_);
    }else{
    }
    glColor3f(.5,.5,0);
    glBegin(GL_TRIANGLES);
        glVertex2d(gx,gy);
        glVertex2d(gx+20,gy-10);
        glVertex2d(gx+20,gy+10);
    glEnd();
    if (gx<=x_+120&&(y_>gy&&y_-30<gy)){
        x_=50;
        y_=50;
        }
    if (gx<0){
        gx=800;
        if (gy>350){
            int ran = distribution(gen);
            gy += ran;
        }else{
            gy=distribution(gen);

        }

    }
    gx-=10;
    glFlush();
    glutSwapBuffers();

    if(X<-800)
    {
    X=800;
    }
    X-=2;
    }

void timer(int value ){
    glutPostRedisplay();

    glutTimerFunc(15,timer,0);

}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );

    glutInitWindowSize(800,400);
    glutInitWindowPosition(10,10);
    glMatrixMode(GL_PROJECTION);

    glutCreateWindow("sait");
    gluOrtho2D(0,800,0,400);

    glutTimerFunc(0,timer,0);


    glutDisplayFunc(displayback);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    return 0;
}
