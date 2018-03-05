#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#define PI 3.1415926535
#define WIDTH 40
#define HEIGHT 480


void sort(int a[10],int y);
void init();
void shape();
void display();

int a[10];
static int radius=2;
int main(int argc,char** argv)
{
int n,i,d=0,m=0;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the number of elements in the array: ");
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutCreateWindow("Sorting and Searching");
glutInitWindowSize(500,500);
glutInitWindowPosition(50,50);
init();
for(i=0;i<n;i++){
glutShapeFunc(shape);
scanf("%d\t\t",&a[i]);
glutDisplayFunc(display);
glutMainLoop();
}
sort(a,n);

return 0;
}

void init(){
glEnable(GL_DEPTH_TEST);
glCullFace(GL_BACK);
glEnable(GL_CULL_FACE);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glPerspective(45.0f,(GLfloat)WIDTH /(GLfloat)HEIGHT,0.1f,1000000,1000000.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glClearColor(1.0,1.0,1.0,0.0);
}

void shape()
{
glViewport(0,0,(GLsizei)WIDTH,(GLsizei)HEIGHT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glPerspective(45.0f,(GLfloat)WIDTH /(GLfloat)HEIGHT,0.1f,1000000,1000000.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
glPushMatrix();
gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
glPushMatrix();
glColor3f(0.2,0.3,0.5);

//Draw a circle
glBegin(GL_POLYGON);
double i;
for(i=0;i<2 * PI;i+=PI / 6){
glVertex3f(cos(i) *radius,sin(i)*radius,0.0);
}
glEnd();
}

void sort(int a[10],int n){
int i,j,temp;
for(i=0;i<n;i++){
for(j=0;j<n-1;j++){
if(a[i]>a[j+1]){
temp=a[i];
a[i]=a[j+1];
a[j+1]=temp;
}
}
}


}
