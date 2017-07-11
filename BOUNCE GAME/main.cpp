//#include <iostream>
//#include <conio.h>
//#include "GL/glut.h"
//#include "SOIL.h"
//using namespace std;
//GLuint myTexture;
//
//int g_Width = 400;		//define size of the window
//int g_Height = 400;
//
////global mouse position
//int mouse_X = 0;	//xcod
//int mouse_Y = 0;	//ycod
//
//GLuint _mainMenuTextureId;//The id of the background texture on main menu screen
//
//GLuint loadtexture(char *name)
//{
//	GLuint temp;
//
//	glGenTextures(1, &temp);
//
//	temp = SOIL_load_OGL_texture
//		(name, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_DDS_LOAD_DIRECT
//		);
//
//	return temp;
//}
//
//void background()
//{
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, _mainMenuTextureId);
//
//	//Bottom
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	glColor3f(1.0f, 1.0f, 1.0f);
//	//glPushMatrix();
//	glScalef(1, 1, 1);
//	glColor4ub(255, 255, 255, 255);
//
//	glBegin(GL_POLYGON);
//
//	glTexCoord2f(0.0, 0.0);
//	glVertex3f(0, 0, 0.0);//draw square for menu
//	glTexCoord2f(1.0, 0.0);
//	glVertex2f(1350, 0.0);//2nd
//	glTexCoord2f(1.0, 1.0);
//	glVertex2f(1350, 700);//3rd 
//	glTexCoord2f(0.0, 1.0);
//	glVertex2f(0.0, 700);//4th
//
//	glEnd();
//	//glPopMatrix();
//
//	glDisable(GL_TEXTURE_2D);
//
//
//}
//
//class Ball{
//protected:
//	float Xco;
//	float Yco;
//	float r, g, b;  //for color
//	float radius;  //for radius
//	float inertia;
//	float life;
//
//public:
//	Ball(){
//		radius = 15;   //will create the ball
//		r = 2; g = 0; b = 0;
//		Xco = 200;
//		Yco = 415;
//		inertia = 0;
//		life = 1;
//	}
//	void set(float x, float y);
//	float surfaceS();
//	float height();
//	void moveRight();
//	void moveLeft();
//	float Radius(){ return radius; }
//	void DrawCircle();
//	float Inertia();
//	void increaseInertia();
//	void decreaseInertia();
//	void Jump(float *add, float surface);
//	void fall();
//	void changeLoc(float X, float Y){ Xco = X + 50; Yco = Y + 30; }
//	void death();
//};
//
//void Ball::death(){
//	life = 0;
//}
//
//
//void Ball::set(float x, float y){
//	Xco = x;
//	Yco = y;
//}
//
//float Ball::surfaceS(){
//	return Xco;
//}
//
//float Ball::height(){
//	return Yco + radius;
//}
//
//void Ball::moveRight(){
//	try{
//		if (Xco > 1320)
//			throw Xco;
//		Xco += 3;
//	}
//	catch (float a){
//		Xco = 1319;
//	}
//	increaseInertia();
//}
//
//void Ball::moveLeft(){
//	try{
//		if (Xco < 15)
//			throw Xco;
//		Xco -= 3;
//	}
//	catch (float b){
//		Xco = 14;
//	}
//	decreaseInertia();
//}
//
//float Ball::Inertia(){
//	return inertia;
//}
//
//void Ball::increaseInertia(){
//	inertia = 1;
//}
//
//void Ball::decreaseInertia(){
//	inertia = -1;
//}
//
//
//int halt = 0;
//
//void Ball::Jump(float *add, float jumpPoint){
//
//	if (*add == 0 && halt == 0){
//		Yco -= 4;
//
//		if (height() < (jumpPoint - 50))
//			halt = 1;
//
//	}
//
//	if (*add == 0 && halt == 1){
//		Yco += 4;
//
//		if (height() > jumpPoint)
//			halt = 0;
//
//	}
//
//	if (*add == 1 && halt == 0){
//		Yco -= 6.2;
//
//		if (height() < (jumpPoint - 100)){
//			halt = 1;
//			*add = 0;
//		}
//	}
//
//	if (*add == 1 && halt == 1){
//		Yco += 6;
//
//		if (Yco > jumpPoint - 20){
//
//			halt = 0;
//		}
//	}
//}
//
//void Ball::fall(){
//	Yco += 5;
//}
//
//void Ball::DrawCircle(){
//	if (life == 1){
//		glColor3f(r, g, b);
//		glBegin(GL_POLYGON);
//
//		for (int ii = 0; ii < 50; ii++)
//		{
//			float theta = 2.0f * 3.1415926f * float(ii) / float(50);  //get the current angle 
//
//			float x = radius * cosf(theta);  //calculate the x component 
//			float y = radius * sinf(theta);  //calculate the y component 
//
//			glVertex2f(x + Xco, y + Yco);//output vertex 
//
//		}
//
//		glEnd();
//	}
//	if (life == 0){
//		glColor3f(0, 0, 0);
//		glBegin(GL_POLYGON);
//
//		for (int ii = 0; ii < 50; ii++)
//		{
//			float theta = 2.0f * 3.1415926f * float(ii) / float(50);  //get the current angle 
//
//			float x = radius * cosf(theta);  //calculate the x component 
//			float y = radius * sinf(theta);  //calculate the y component 
//
//			glVertex2f(x + Xco, y + Yco);//output vertex 
//
//		}
//
//		glEnd();
//	}
//}
//
//
//class Platform{
//protected:
//	float Xco;
//	float Yco;
//	float width;
//	float height;
//
//public:
//	Platform(float a, float b, float c, float d) :Xco(a), Yco(b), width(c), height(d){};
//	void set(float x, float y, float w, float h);
//	void DrawPlatform();
//	bool compareX(float X);
//	bool compareY(float Y);
//	float Surface();
//};
//
//void Platform::set(float x, float y, float w, float h){
//	Xco = x;
//	Yco = y;
//	width = w;
//	height = h;
//}
//
//void Platform::DrawPlatform(){
//
//	glColor3f(0, 0, 1);
//
//	glBegin(GL_POLYGON);
//
//	glVertex2f(Xco, Yco);
//	glVertex2f(Xco + width, Yco);
//	glVertex2f(Xco + width, Yco + height);
//	glVertex2f(Xco, Yco + height);
//
//	glEnd();
//
//}
//
//bool Platform::compareX(float X){
//
//	if ((X > Xco - 6) && X < (Xco + width + 6))
//		return true;
//	else return false;
//
//}
//
//bool Platform::compareY(float Y){
//
//	if ((Y < (Yco + height)))
//		return true;
//	else return false;
//
//}
//
//float Platform::Surface(){
//	return Yco;
//}
//
//class movingPlatform :public Platform{
//private:
//	float beginPoint;
//	float endPoint;
//	int c;
//public:
//	movingPlatform(float a, float b, float c, float d, float begin, float end) :Platform(a, b, c, d), beginPoint(begin), endPoint(end){}
//	void set(float x, float y, float begin, float end);
//	void Behaviour();
//};
//
//
//void movingPlatform::set(float x, float y, float begin, float end){
//	Xco = x;
//	Yco = y;
//	beginPoint = begin;
//	endPoint = end;
//}
//
//
//void movingPlatform::Behaviour(){
//	if (c == 0){
//		Xco += 3;
//
//		if ((Xco > endPoint - 4))
//			c = 1;
//	}
//
//	if (c == 1){
//		Xco -= 3;
//
//		if (Xco < (beginPoint + 4))
//			c = 0;
//	}
//}
//
//
//
//class Coin{
//protected:
//	int vanish;
//	static int score;
//	float Xco;
//	float Yco;
//	float rad;
//
//public:
//	Coin(float X, float Y, float r) :Xco(X), Yco(Y), rad(r){ score = 0; }
//	void set(float x, float y);
//	void drawRing(int segments);
//	void incScore();
//	void VanishCoin(){ vanish = 1; }
//	int Van(){ return vanish; }
//	bool Collision(Ball a);
//	float X(){ return Xco; }
//	float Y(){ return Yco; }
//	int retScore(){ return score; }
//};
//
//int Coin::score = 0;
//
//void Coin::set(float x, float y){
//	Xco = x;
//	Yco = y;
//}
//
//void Coin::drawRing(int segments){
//
//	glColor3f(1.0, 0.5, 0.0);
//
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(Xco, Yco);
//	for (int n = 0; n <= segments; ++n) {
//		float const t = 2 * 3.1415926*(float)n / (float)segments;
//		glVertex2f(Xco + sin(t)*rad, Yco + cos(t)*rad);
//	}
//	glEnd();
//
//}
//
//void Coin::incScore(){
//	score++;
//}
//
//bool Coin::Collision(Ball a){
//	if (((a.surfaceS() + a.Radius() > Xco)) && (a.surfaceS() + a.Radius() < (Xco + 2 * rad)) && (a.height() > (Yco - rad)) && (a.height() < (Yco + rad))){
//		return true;
//	}
//	else return false;
//}
//
//
//class Door{
//protected:
//	float Xco;
//	float Yco;
//	float height;
//	float width;
//
//public:
//	Door(float a, float b, float c, float d) :Xco(a), Yco(b), width(c), height(d){};
//	void drawDoor();
//	void set(float x, float y);
//	bool Collision(Ball);
//	float retX(){ return Xco; }
//	float retY(){ return Yco; }
//};
//
//void Door::set(float x, float y){
//	Xco = x;
//	Yco = y;
//}
//
//void Door::drawDoor(){
//	glColor3f(1, 0, 1);
//	glBegin(GL_POLYGON);
//	glVertex2f(Xco, Yco);
//	glVertex2f(Xco + width, Yco);
//	glVertex2f(Xco + width, Yco + height);
//	glVertex2f(Xco, Yco + height);
//	glEnd();
//}
//
//bool Door::Collision(Ball ball){
//	if (ball.surfaceS() > Xco && ball.surfaceS() < Xco + width && ball.height() > Yco && ball.height() < Yco + height)
//		return true;
//	else return false;
//}
//
//class NextLevelDoor : public Door{
//private:
//	int nextLevel;
//public:
//	NextLevelDoor(float a, float b, float c, float d) :Door(a, b, c, d){}
//	void drawDoor();
//};
//
//void NextLevelDoor::drawDoor(){
//	glColor3f(1, 1, 0);
//	glBegin(GL_POLYGON);
//	glVertex2f(Xco, Yco);
//	glVertex2f(Xco + width, Yco);
//	glVertex2f(Xco + width, Yco + height);
//	glVertex2f(Xco, Yco + height);
//	glEnd();
//}
//
//
//class superCoin :public Coin{
//private:
//	int power;
//public:
//	superCoin(int a, float X, float Y, float r) :power(a), Coin(X, Y, r){}
//	int getPower();
//	void setPower(int);
//	void drawRing(int segments);
//	void Collision(Ball &ball);
//};
//
//void superCoin::drawRing(int segments){
//
//	glBegin(GL_POLYGON);
//	glColor3f(2, 1, 0);
//	glVertex2f(Xco, Yco);
//	for (int n = 0; n <= segments; ++n) {
//		float const t = 2 * 3.1415926*(float)n / (float)segments;
//		glVertex2f(Xco + sin(t)*rad, Yco + cos(t)*rad);
//	}
//	glEnd();
//
//}
//
//int superCoin::getPower(){
//	return power;
//}
//
//void superCoin::setPower(int x){
//	power = x;
//}
//
//
//void superCoin::Collision(Ball &ball){
//
//	if (((Xco > ball.surfaceS()) && (Xco<(ball.surfaceS() + 2 * ball.Radius())) && (Yco>ball.height()) && (Yco < (ball.height() + 2 * ball.Radius())))){
//		vanish = 1;
//	}
//}
//
//
//
//class Enemy :public Ball{
//	float beginPoint;
//	float endPoint;
//	bool eatable;
//	int vanish;
//	int c;
//	static int count;
//public:
//	Enemy(float x, float y, float begin, float end);
//	void set(float x, float y, float begin, float end);
//	void Collision(Ball &ball);
//	void state();
//	int Count(){
//		return count;
//	}
//	void Draw();
//	int Van(){ return vanish; }
//	void Behaviour();
//};
//
//int Enemy::count = 0;
//
//Enemy::Enemy(float x, float y, float begin, float end){
//	Xco = x;
//	Yco = y;
//	c = 0;
//	beginPoint = begin;
//	endPoint = end;
//	r = 0;
//	g = 2;
//	b = 00;
//	radius = 10;
//	eatable = false;
//	vanish = 0;
//}
//
//void Enemy::Draw(){
//
//	if (vanish == 0){
//		glColor3f(r, g, b);
//		glBegin(GL_POLYGON);
//
//		for (int ii = 0; ii < 50; ii++)
//		{
//			float theta = 2.0f * 3.1415926f * float(ii) / float(50);  //get the current angle 
//			float x = radius * cosf(theta);  //calculate the x component 
//			float y = radius * sinf(theta);  //calculate the y component 
//
//			glVertex2f(x + Xco, y + Yco);//output vertex 
//
//		}
//
//		glEnd();
//	}
//}
//
//
//void Enemy::state(){
//	eatable = true;
//}
//
//
//void Enemy::Collision(Ball &ball){
//
//	if (!eatable){
//		if (((Xco>ball.surfaceS()) && (Xco<(ball.surfaceS() + 2 * ball.Radius())) && (Yco>ball.height()) && (Yco < (ball.height() + 2 * ball.Radius()))))
//			ball.death();
//	}
//
//	if (eatable){
//		r = 2;
//		g = 1;
//		b = 0;
//		if (((Xco>ball.surfaceS()) && (Xco<(ball.surfaceS() + 2 * ball.Radius())) && (Yco>ball.height()) && (Yco < (ball.height() + 2 * ball.Radius())))){
//			count++;
//			vanish = 1;
//		}
//
//	}
//
//}
//
//
//void Enemy::Behaviour(){
//	if (c == 0){
//		Xco += 3;
//
//		if ((Xco > endPoint - 4))
//			c = 1;
//	}
//
//	if (c == 1){
//		Xco -= 3;
//
//		if (Xco < (beginPoint + 4))
//			c = 0;
//	}
//}
//
//
//class Boss :public Ball{
//	bool eatable;
//	int halt;
//	int vanish;
//public:
//	Boss(float x, float y){
//		radius = 15;   //will create the boss
//		r = 0; g = 0; b = 0;
//		Xco = x;
//		Yco = y;
//		eatable = false;
//	}
//	void set(float x, float y);
//	void moveLeft();
//	void moveRight();
//	void Jump(float);
//	int Vanish(){
//		return vanish;
//	}
//	void Behavior(Ball a);
//	void Collision(Ball &);
//};
//
//void Boss::set(float x, float y){
//
//	Xco = x;
//	Yco = y;
//
//}
//
//void Boss::moveLeft(){
//
//	try{
//		if (Xco < 15)
//			throw Xco;
//		Xco -= 3;
//	}
//	catch (float a){
//		Xco = 14;
//	}
//
//
//}
//
//void Boss::moveRight(){
//
//	try{
//		if (Xco > 1320)
//			throw Xco;
//		Xco += 3;
//	}
//	catch (float a){
//		Xco = 1319;
//	}
//
//
//}
//
//void Boss::Behavior(Ball a){
//
//	if (a.surfaceS() > Xco){
//		moveRight();
//	}
//
//	if (a.surfaceS() < Xco){
//		moveLeft();
//	}
//
//}
//
//
//void Boss::Collision(Ball &ball){
//
//	if (!eatable){
//		if (((Xco>ball.surfaceS()) && (Xco<(ball.surfaceS() + 2 * ball.Radius())) && (Yco>ball.height()) && (Yco < (ball.height() + 2 * ball.Radius()))))
//			ball.death();
//	}
//
//	if (eatable){
//		r = 2;
//		g = 1;
//		b = 0;
//		if (((Xco>ball.surfaceS()) && (Xco<(ball.surfaceS() + 2 * ball.Radius())) && (Yco>ball.height()) && (Yco < (ball.height() + 2 * ball.Radius())))){
//			vanish = 1;
//		}
//
//	}
//
//}
//
//
//void Boss::Jump(float jumpPoint){
//
//	if (halt == 0){
//		Yco -= 4;
//
//		if (height() < (jumpPoint - 30))
//			halt = 1;
//
//	}
//
//	if (halt == 1){
//		Yco += 4;
//
//		if (height() > jumpPoint)
//			halt = 0;
//
//	}
//
//}
//
//
//
//
//float jump = 0;
//
//Ball mainB;
//
//Platform p1(50, 630, 400, 10);
//Platform p2(320, 590, 150, 10);
//Platform p3(500, 550, 400, 10);
//Platform p4(1024, 390, 200, 10);
//Platform p5(900, 470, 220, 10);
//Platform p6(700, 400, 200, 10);
//Platform p7(450, 370, 200, 10);
//Platform p8(550, 270, 220, 10);
//Platform p9(50, 100, 220, 10);
//
//Platform BossP(0, 690, 1350, 10);
//
//movingPlatform m1(400, 370, 220, 10, 350, 750);
//
//Coin coins(200, 600, 10);
//Coin coins1(200, 500, 10);
//Coin coins2(300, 600, 10);
//Coin coins3(150, 80, 10);
//
//superCoin s1(1, 1110, 370, 6.5);
//
//Door door1(650, 170, 50, 100);
//Door door2(60, 10, 50, 90);
//
//Enemy e1(500, 540, 500, 900);
//Enemy e2(450, 360, 450, 650);
//
//Boss Boss1(800, 680);
//
//class Game{
//	int menu;
//	int level;
//
//public:
//	Game() :menu(1), level(0){};
//	void playGame();
//	void select(int a){ level = a; }
//};
//
//void Game::playGame(){
//	if (menu == 1 && level == 0){
//		_mainMenuTextureId = loadtexture("Game Menu Main.png");
//		background();
//		if (mouse_X > 480 && mouse_X < 860 && mouse_Y > 235 && mouse_Y < 370){
//			level = 1;
//			menu = 0;
//			mouse_X = 0;
//			mouse_Y = 0;
//		}
//		if (mouse_X > 480 && mouse_X < 860 && mouse_Y > 400 && mouse_Y < 540){
//			level = 0;
//			menu = 2;
//			mouse_X = 0;
//			mouse_Y = 0;
//		}
//		if (mouse_X > 480 && mouse_X < 860 && mouse_Y > 575 && mouse_Y < 700){
//			exit(EXIT_SUCCESS);
//		}
//	}
//	if (menu == 2 && level == 0){
//		/*glColor3f(1, 0, 0);
//		glBegin(GL_POLYGON);
//		glVertex2f(50, 50);
//		glVertex2f(50, 100);
//		glVertex2f(100, 100);
//		glVertex2f(100, 50);
//		glEnd();*/
//		_mainMenuTextureId = loadtexture("Levels.png");
//		background();
//
//		if (mouse_X > 525 && mouse_X < 830 && mouse_Y > 115 && mouse_Y < 220){
//			level = 1;
//			menu = 0;
//			mouse_X = 0;
//			mouse_Y = 0;
//			
//		}
//		if (mouse_X > 525 && mouse_X < 830 && mouse_Y > 270 && mouse_Y < 370){
//			/////////////////////////////setters////////////////////////
//			p1.set(200, 600, 200, 10);
//			p2.set(650, 550, 200, 10);
//			p3.set(330, 515, 200, 10);
//			p4.set(850, 470, 200, 10);
//			p5.set(600, 420, 200, 10);
//			p6.set(870, 300, 200, 10);
//			p7.set(450, 170, 200, 10);
//			p8.set(680, 240, 200, 10);
//			p9.set(940, 95, 200, 10);
//
//			//coins.set();
//			//coins1.set();
//			//coins2.set();
//			coins3.set(1100, 50);
//
//			//s1.set();
//
//			door1.set(470, 70);
//			door2.set(980, 10);
//
//			//e1.set();
//			//e2.set();
//			////////////////////////////////////////////////////////////
//			level = 2;
//			menu = 0;
//			mouse_X = 0;
//			mouse_Y = 0;
//		}
//
//
//		if (mouse_X > 525 && mouse_X < 830 && mouse_Y > 420 && mouse_Y < 520){
//			level = 3;
//			menu = 0;
//			mouse_X = 0;
//			mouse_Y = 0;
//		}
//
//
//	}
//
//	if (menu == 3 && level == 0){
//		_mainMenuTextureId = loadtexture("Dead.png");
//		background();
//		if (mouse_X > 530 && mouse_X < 810 && mouse_Y > 400 && mouse_Y < 520){
//			level = 0;
//			menu = 1;
//			mouse_X = 0;
//			mouse_Y = 0;
//		}
//		
//	}
//
//	if (menu == 0 && level == 1){
//		_mainMenuTextureId = loadtexture("Volcano.png");
//		background();
//		door1.drawDoor();
//		door2.drawDoor();
//		if (coins.Van() == 1 && coins1.Van() == 1 && coins2.Van() == 1 && coins3.Van() == 1 && e1.Van() == 1 && e2.Van() == 1){
//			NextLevelDoor d1(55, 540, 50, 100);
//			d1.drawDoor();
//			if (d1.Collision(mainB))
//			{
//				level = 2;
//				menu = 0;
//
//				/////////////////////////////setters////////////////////////
//				p1.set(200, 600, 200, 10);
//				p2.set(650, 550, 200, 10);
//				p3.set(330, 515, 200, 10);
//				p4.set(850, 470, 200, 10);
//				p5.set(600, 420, 200, 10);
//				p6.set(870, 300, 200, 10);
//				p7.set(450, 170, 200, 10);
//				p8.set(680, 240, 200, 10);
//				p9.set(940, 95, 200, 10);
//
//				//coins.set();
//				//coins1.set();
//				//coins2.set();
//				coins3.set(1100, 50);
//
//				//s1.set();
//
//				door1.set(470, 70);
//				door2.set(980, 10);
//
//				//e1.set();
//				//e2.set();
//				////////////////////////////////////////////////////////////
//			}
//		}
//		mainB.DrawCircle();
//
//		p1.DrawPlatform();
//
//		p2.DrawPlatform();
//
//		p3.DrawPlatform();
//
//		p4.DrawPlatform();
//
//		p5.DrawPlatform();
//
//		p6.DrawPlatform();
//
//		p7.DrawPlatform();
//
//		p8.DrawPlatform();
//
//		p9.DrawPlatform();
//
//		e1.Draw();
//
//		e1.Behaviour();
//
//		e1.Collision(mainB);
//
//		e2.Draw();
//
//		e2.Behaviour();
//
//		e2.Collision(mainB);
//
//		if (coins.Van() == 0)
//			coins.drawRing(250);
//
//		if (coins1.Van() == 0)
//			coins1.drawRing(250);
//
//		if (coins2.Van() == 0)
//			coins2.drawRing(250);
//
//		if (coins3.Van() == 0)
//			coins3.drawRing(250);
//
//		s1.Collision(mainB);
//
//		if (s1.Van() == 0)
//			s1.drawRing(250);
//
//		if (s1.Van() == 1){
//			e1.state();
//			e2.state();
//		}
//
//
//		if (coins.Collision(mainB))
//
//		{
//			coins.incScore();
//			coins.VanishCoin();
//		}
//
//		if (coins1.Collision(mainB))
//
//		{
//			coins1.incScore();
//			coins1.VanishCoin();
//		}
//
//		if (coins2.Collision(mainB))
//		{
//			coins2.incScore();
//			coins2.VanishCoin();
//		}
//
//		if (coins3.Collision(mainB))
//		{
//			coins3.incScore();
//			coins3.VanishCoin();
//		}
//
//		if (door1.Collision(mainB))
//		{
//			mainB.changeLoc(door2.retX(), door2.retY());
//		}
//
//
//		if ((p9.compareX(mainB.surfaceS())) && (p9.compareY(mainB.height()))){
//			mainB.Jump(&jump, p9.Surface());
//		}
//
//		else if ((p8.compareX(mainB.surfaceS())) && (p8.compareY(mainB.height()))){
//			mainB.Jump(&jump, p8.Surface());
//		}
//
//		else if ((p7.compareX(mainB.surfaceS())) && (p7.compareY(mainB.height()))){
//			mainB.Jump(&jump, p7.Surface());
//		}
//
//		else if ((p6.compareX(mainB.surfaceS())) && (p6.compareY(mainB.height()))){
//			mainB.Jump(&jump, p6.Surface());
//		}
//
//		else if ((p4.compareX(mainB.surfaceS())) && (p4.compareY(mainB.height()))){
//			mainB.Jump(&jump, p4.Surface());
//		}
//		else if ((p5.compareX(mainB.surfaceS())) && (p5.compareY(mainB.height()))){
//			mainB.Jump(&jump, p5.Surface());
//		}
//
//		else if ((p3.compareX(mainB.surfaceS())) && (p3.compareY(mainB.height()))){
//			mainB.Jump(&jump, p3.Surface());
//		}
//
//
//		else if ((p2.compareX(mainB.surfaceS())) && (p2.compareY(mainB.height()))){
//			mainB.Jump(&jump, p2.Surface());
//		}
//
//		else if ((p1.compareX(mainB.surfaceS())) && (p1.compareY(mainB.height()))){
//			mainB.Jump(&jump, p1.Surface());
//		}
//
//
//		else mainB.fall();
//
//		if (mainB.Inertia() > 0){
//			mainB.moveRight();
//		}
//
//		if (mainB.Inertia() < 0){
//			mainB.moveLeft();
//		}
//
//
//	}
//
//	if (menu == 0 && level == 2){
//		_mainMenuTextureId = loadtexture("Level2.png");
//		background();
//		door1.drawDoor();
//		door2.drawDoor();
//		if (coins.Van() == 1 && coins1.Van() == 1 && coins2.Van() == 1 && coins3.Van() == 1 && e1.Van() == 1 && e2.Van() == 1){
//			NextLevelDoor d1(55, 540, 50, 100);
//			d1.drawDoor();
//			if (d1.Collision(mainB))
//			{
//				level = 2;
//				menu = 0;
//			}
//		}
//		mainB.DrawCircle();
//
//		p1.DrawPlatform();
//
//		p2.DrawPlatform();
//
//		p3.DrawPlatform();
//
//		p4.DrawPlatform();
//
//		p5.DrawPlatform();
//
//		p6.DrawPlatform();
//
//		p7.DrawPlatform();
//
//		p8.DrawPlatform();
//
//		p9.DrawPlatform();
//
//		m1.DrawPlatform();
//
//		m1.Behaviour();
//
//		BossP.DrawPlatform();
//
//		Boss1.DrawCircle();
//
//		Boss1.Behavior(mainB);
//
//		Boss1.Jump(BossP.Surface());
//
//		Boss1.Collision(mainB);
//
//		e1.Draw();
//
//		e1.Behaviour();
//
//		e1.Collision(mainB);
//
//		e2.Draw();
//
//		e2.Behaviour();
//
//		e2.Collision(mainB);
//
//		if (coins.Van() == 0)
//			coins.drawRing(250);
//
//		if (coins1.Van() == 0)
//			coins1.drawRing(250);
//
//		if (coins2.Van() == 0)
//			coins2.drawRing(250);
//
//		if (coins3.Van() == 0)
//			coins3.drawRing(250);
//
//		s1.Collision(mainB);
//
//		if (s1.Van() == 0)
//			s1.drawRing(250);
//
//		if (s1.Van() == 1){
//			e1.state();
//			e2.state();
//		}
//
//
//		if (coins.Collision(mainB))
//
//		{
//			coins.incScore();
//			coins.VanishCoin();
//		}
//
//		if (coins1.Collision(mainB))
//
//		{
//			coins1.incScore();
//			coins1.VanishCoin();
//		}
//
//		if (coins2.Collision(mainB))
//		{
//			coins2.incScore();
//			coins2.VanishCoin();
//		}
//
//		if (coins3.Collision(mainB))
//		{
//			coins3.incScore();
//			coins3.VanishCoin();
//		}
//
//		if (door1.Collision(mainB))
//		{
//			mainB.changeLoc(door2.retX(), door2.retY());
//		}
//
//
//		if ((p9.compareX(mainB.surfaceS())) && (p9.compareY(mainB.height()))){
//			mainB.Jump(&jump, p9.Surface());
//		}
//
//		else if ((p8.compareX(mainB.surfaceS())) && (p8.compareY(mainB.height()))){
//			mainB.Jump(&jump, p8.Surface());
//		}
//
//		else if ((p7.compareX(mainB.surfaceS())) && (p7.compareY(mainB.height()))){
//			mainB.Jump(&jump, p7.Surface());
//		}
//
//		else if ((p6.compareX(mainB.surfaceS())) && (p6.compareY(mainB.height()))){
//			mainB.Jump(&jump, p6.Surface());
//		}
//
//		else if ((m1.compareX(mainB.surfaceS())) && (m1.compareY(mainB.height()))){
//			mainB.Jump(&jump, m1.Surface());
//		}
//
//		else if ((p4.compareX(mainB.surfaceS())) && (p4.compareY(mainB.height()))){
//			mainB.Jump(&jump, p4.Surface());
//		}
//		else if ((p5.compareX(mainB.surfaceS())) && (p5.compareY(mainB.height()))){
//			mainB.Jump(&jump, p5.Surface());
//		}
//
//		else if ((p3.compareX(mainB.surfaceS())) && (p3.compareY(mainB.height()))){
//			mainB.Jump(&jump, p3.Surface());
//		}
//
//
//		else if ((p2.compareX(mainB.surfaceS())) && (p2.compareY(mainB.height()))){
//			mainB.Jump(&jump, p2.Surface());
//		}
//
//		else if ((p1.compareX(mainB.surfaceS())) && (p1.compareY(mainB.height()))){
//			mainB.Jump(&jump, p1.Surface());
//		}
//
//		else if ((BossP.compareX(mainB.surfaceS())) && (BossP.compareY(mainB.height()))){
//			mainB.Jump(&jump, BossP.Surface());
//		}
//
//
//		else mainB.fall();
//
//		if (mainB.Inertia() > 0){
//			mainB.moveRight();
//		}
//
//		if (mainB.Inertia() < 0){
//			mainB.moveLeft();
//		}
//
//	}
//	
//}
//
//
//void init();
//void myMouseFunction(int button, int state, int mouseX, int mouseY);
//void myKeyboardFunction(unsigned char key, int mouseX, int mouseY);
//void mySpecialKeysFunction(int key, int x, int y);
//void myReshapeFunction(int width, int height);
//void myTimerFunction(int val);
//void myDisplayFunction();
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);		//initilize the GLUT libraray
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);		//has four colour components red, green,blue, and alpha 
//	glutInitWindowSize(1350, 700);	//size of window
//	glutInitWindowPosition(0, 0);		//position of window
//	glutCreateWindow("Pounce! The Game!");
//
//	init();
//
//	glutMouseFunc(myMouseFunction);
//	glutKeyboardFunc(myKeyboardFunction);
//	glutSpecialFunc(mySpecialKeysFunction);
//
//	glutReshapeFunc(myReshapeFunction);
//	glutDisplayFunc(myDisplayFunction);
//	glutTimerFunc(33, myTimerFunction, 0);
//
//	//	glutFullScreen();	// make the screen fullscreen
//	glutSetCursor(GLUT_CURSOR_INFO);	//Displays the type of cursor u want
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);		//background color of openGl window
//	//			 ^red, green, blue, alpha(opaquenss) 
//	glMatrixMode(GL_PROJECTION);		//glMatrixMode — specify which matrix is the current matrix ????
//	glLoadIdentity();		//glLoadIdentity — replace the current matrix with the identity matrix	????
//
//	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);	//set (0,0) on left top
//}
//
//void myMouseFunction(int button, int state, int mouseX, int mouseY)
//{
//	mouse_X = mouseX;
//	mouse_Y = mouseY;
//
//	if (state == 0) //Click
//	{
//		cout << "mouse clicked \n";
//		cout << "\nmouseX:" << mouseX << "mouseY:" << mouseY << "State: " << state;
//	}
//
//
//}
//
//void myKeyboardFunction(unsigned char key, int mouseX, int mouseY){
//	switch (key)
//	{
//	case 27: // Escape key
//		exit(0);
//		break;
//	}
//}
//
//
//
//void mySpecialKeysFunction(int key, int x, int y){
//
//	switch (key){
//
//	case GLUT_KEY_UP:
//		if (jump == 0){
//			jump = 1;
//		}
//		break;
//
//	case GLUT_KEY_DOWN:
//		break;
//
//	case GLUT_KEY_LEFT:
//		mainB.moveLeft();
//		break;
//
//	case GLUT_KEY_RIGHT:
//		mainB.moveRight();
//		break;
//	case GLUT_KEY_HOME:
//		break;
//	case GLUT_KEY_END:
//		break;
//	case GLUT_KEY_PAGE_UP:
//		break;
//	case GLUT_KEY_PAGE_DOWN:
//		break;
//	}
//}
//
//void myReshapeFunction(int width, int height)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	g_Width = width;
//	g_Height = height;
//
//	glViewport(0, 0, g_Width, g_Height);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, g_Width, g_Height, 0.0, -1.0, 1.0);	//change the (0,0) to top left
//}
//
//void myTimerFunction(int val)
//{
//	glutTimerFunc(33, myTimerFunction, 0);
//	myDisplayFunction();
//}
//
//
//Game Pounce;
//
//void myDisplayFunction()
//{
//	glClear(GL_COLOR_BUFFER_BIT);		//clears the screen after display
//
//	glColor3f(1, 1, 1);
//	glBegin(GL_POLYGON);
//	glVertex2f(-10, -10);
//	glVertex2f(2000, -10);
//	glVertex2f(2000, 1000);
//	glVertex2f(-10, 1000);
//	glEnd();
//
//	Pounce.playGame();
//
//	glutSwapBuffers();		//brings the openGl window on the front
//	//printf("\n.");
//}