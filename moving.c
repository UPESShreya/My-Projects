#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

int maxx=600,maxy=600;
int i=0,u=0,c=0;
void display(){
//glClear(Gl_COLOR_BUFFER_BIT);
	if(u<=100 && c==0)
{
glClearColor(1,0.5,0.5,0);
glColor3f(1,1,0);
u++;
}
if(u>100 || c==1)
{
glClearColor(0.8,0.2,0.2,0.0);
glColor3f(0,1,1);
u--;
c=1;
}

if(u<=0){
c=0;
}

for(i=0;i<=u;i=i+3){
//delay(1);
glBegin(GL_LINE_LOOP);
  glVertex2f(200+u,200+u);
glVertex2f(400+u,200+u);
glVertex2f(400+u,400+u);
glVertex2f(200+u,400+u);
glEnd();

glBegin(GL_QUADS);
glVertex2f(0+u,0+u);
glVertex2f(200+u,0+u);
glVertex2f(200+u,200+u);
glVertex2f(0+u,200+u);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(280+i,400+u);
glVertex2f(400+u,280+i);
glVertex2f(400+u,400+u);
glEnd();

glColor3f(0,1,0);
glRecti(200-u,400+u,200+u,400-u);
glRecti(400+u,200-u,400-u,200+u);
glRecti(350+u,350+u,380+u,380+u);
glRecti(0+u,0+u,30+u,30+u);
glRecti(30+u,30+u,60+u,60+u);
glRecti(60+u,60+u,90+u,90+u);
glRecti(90+u,90+u,120+u,120+u);
glRecti(120+u,120+u,150+u,150+u);
glRecti(150+u,150+u,180+u,180+u);
glRecti(180+u,180+u,210+u,210+u);

glutSwapBuffers();
glutPostRedisplay();
}

}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(maxx,maxy);
glutInitWindowPosition(50,50);
glutCreateWindow("Draw");
glutDisplayFunc(display);
gluOrtho2D(0,maxx,0,maxy);
glClearColor(0.8,0.5,0.5,0);
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
glutMainLoop();
return 0;
}

