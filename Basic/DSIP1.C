#include <graphics.h>
//#include <conio.h>
#include<X11/Xlib.h>
#define origX 320
#define origY 240

void axis(int type, int x, int y, int length);
void impulse(int x, int val);
void unit_ramp(int steps);
void unit_step(int steps);

void wait_for_char()
{

    //Wait for a key press
    int in = 0;

    while (in == 0) {
        in = getchar();
    }
}

int main() {
    	XInitThreads();
	int gd = DETECT, gm;
	int opt;
	initgraph(&gd, &gm, NULL);
	// Drawing X-axis
	axis(0, origX, origY, 240);
	// Drawing Y-axis
	axis(1, origX, origY, 200);
	printf("1. Unit Impulse\n2. Unit Step\n3.Unit Ramp\nEnter your choice: ");
	scanf("%d", &opt);
	switch(opt) {
		case 1:
			impulse(0, 1);
			break;
		case 2:
			printf("Enter the number of steps: ");
			scanf("%d", &opt);
			unit_step(opt);
			break;
		case 3:
			printf("Enter the number of steps: ");
			scanf("%d", &opt);
			unit_ramp(opt);
			break;
		default:
			printf("Invalid Choice");
			break;
	}
	//getch();
	//delay(5000);
	//scanf("%d", &opt);
	wait_for_char();
	closegraph();
	return 0;
}

void axis(int type, int x, int y, int length) {
	int i;
	if (type == 0) {
		line(x - length, y, x + length, y);
		outtextxy(x + length, y + 10, "Time Steps");
	}
	else {
		line(x, y - length, x, y + length);
		outtextxy(x - 10, y - length, "X(n)");
	}
}

void impulse(int x, int val) {
	int new_x = origX + 30*x;
	int new_y = origY - 30*val;
	char x_label[2], y_label[2];
	y_label[0] = (char) (val + 48);
	y_label[1] = '\0';
	x_label[0] = (char)(x+48);
	x_label[1] = '\0';
	setcolor(RED);
	line(new_x, origY, new_x, new_y);
	outtextxy(new_x, new_y - 10, y_label);
	outtextxy(new_x, origY + 10, x_label);
	setcolor(WHITE);
}

void unit_ramp(int steps) {
	int i;
	for (i = 0; i < steps; i++)
		impulse(i, i);
}

void unit_step(int steps) {
	int i;
	for (i = 0; i < steps; i++)
		impulse(i, 1);
}
