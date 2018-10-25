package ru.java2d;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Location extends JPanel implements ActionListener {

	Timer mainTimer = new Timer(200, this);

	Image png = new ImageIcon("models/Place.png").getImage();
	Player p = new Player();
	Boss b = new Boss();
	
	public Location() {
		mainTimer.start();
		addKeyListener(new MyKeyAdapter());
		setFocusable(true);
	}

	private class MyKeyAdapter extends KeyAdapter {
		public void keyPressed(KeyEvent e) {
			p.keyPressed(e);
		}

		public void keyReleased(KeyEvent e) {
			p.keyReleased(e);
		}

	}

	public void paint(Graphics g) {
		g = (Graphics2D) g;
		g.drawImage(png, p.player1, 0, null);
		//g.drawImage(png, p.player2, 0, null); // второй слой
		g.drawImage(p.png, p.x, p.y, null);
		g.drawImage(b.png1,b.x,b.y,null);
	}

	public void actionPerformed(ActionEvent e) {
		p.move();
		repaint();
	}

}
