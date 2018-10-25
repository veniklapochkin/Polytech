package ru.javanfc2d;

import java.awt.Image;
import java.awt.Rectangle;

import javax.swing.ImageIcon;

public class Enemy{
	int x;
	int y;
	int v;
	int width= 120;
	int height = 70;
	Image png = new ImageIcon(getClass().getClassLoader().getResource("models/Car4.png")).getImage();
	Road road;
	
	public Rectangle getRect(){
		return new Rectangle(x,y,width,height);
	}
	
	
	public Enemy(int x,int y, int v, Road road){
		this.x =x;
		this.y =y;
		this.v = v;
		this.road = road;
		
	}
	public void move(){
		x=x-road.c.v-v;
	}

	
}