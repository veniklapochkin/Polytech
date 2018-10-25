package ru.java2d;

import javax.swing.JFrame;

public class Game {

	public static void main(String[] args) {
		JFrame f = new JFrame("Shadow of the Colossus");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(1366, 768);
		f.add(new Location());
		f.setVisible(true);
	}
}
