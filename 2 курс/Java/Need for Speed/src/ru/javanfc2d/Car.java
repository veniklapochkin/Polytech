package ru.javanfc2d;

import java.awt.Image;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;

import javax.swing.ImageIcon;

public class Car {

	public static final int MAX_V = 50; // ���� �� ������
	public static final int MAX_TOP = 70;
	public static final int MAX_BOTTOM =600;
	Image png_c = new ImageIcon(getClass().getClassLoader().getResource("models/Car1.png")).getImage();
	Image png_l = new ImageIcon(getClass().getClassLoader().getResource("models/Car2.png")).getImage();
	Image png_r = new ImageIcon(getClass().getClassLoader().getResource("models/Car3.png")).getImage();
	Image png = png_c;
	int v = 0;
	int a = 0;
	int b = 0;
	int s = 0;
	int x = 100;
	int y = 300;
	int width=115;
	int height=30;
	int layer1 = 0;
	int layer2 = 1300; // 2-� ����
	public Rectangle getRect(){
		return new Rectangle(x,y,width,height);
	}
	public void move() {
		s += v;
		v += a;
		if (v<=0) v=0;
		if (x<=0) x=0;
		if (v>=MAX_V) v= MAX_V;
		y -= b;
		if (y<= MAX_TOP) y=MAX_TOP;
		if (y>= MAX_BOTTOM) y=MAX_BOTTOM;
		if (v >= MAX_V)
			v = MAX_V;
		if (layer2 - v <= 0) {
			layer1 = 0;
			layer2 = 1300;
		} else {

			layer1 -= v;
			layer2 -= v;
		}
	}

	public void keyPressed(KeyEvent e) {
		int key = e.getKeyCode();
		if (key == KeyEvent.VK_RIGHT) {
			a = 1;
			x++;

		}
		if (key == KeyEvent.VK_LEFT) {
			a = -1;
			x--;
		

		}

		if (key == KeyEvent.VK_UP) {
			b = 4;
			y++;

			png = png_l;
		}
		if (key == KeyEvent.VK_DOWN) {
			b = -4;
			y--;
			png = png_r;
		}

		if (key == KeyEvent.VK_SPACE){
			v=0;
		}
	
	}

	public void keyReleased(KeyEvent e) {
		int key = e.getKeyCode();
		if (key == KeyEvent.VK_LEFT || key == KeyEvent.VK_RIGHT) {
			a = 0;
		}

		if (key == KeyEvent.VK_UP || key == KeyEvent.VK_DOWN) {
			b = 0;
			png = png_c;
		}
	}

}
